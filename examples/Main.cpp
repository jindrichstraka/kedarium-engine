#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Kedarium/Core.hpp"
#include "Kedarium/File.hpp"
#include "Kedarium/Color.hpp"
#include "Kedarium/Graphics.hpp"

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const std::string  WINDOW_TITLE  = "Kedarium Engine";

// Vertices and Indices
const GLfloat vertices[] = {
  -0.5f, -0.5f, 0.f, 1.f, 1.f, 1.f,
   0.5f, -0.5f, 0.f, 1.f, 1.f, 1.f,
  -0.5f,  0.5f, 0.f, 1.f, 1.f, 1.f,
   0.5f,  0.5f, 0.f, 1.f, 1.f, 1.f,
};
const GLuint indices[] = {
  1, 0, 3,
  2, 3, 0,
};

int main()
{
  // Initializing GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Creating a GLFW Window
  GLFWwindow* window = glfwCreateWindow(
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE.c_str(),
    NULL,
    NULL
  );

  // Validating the Window
  if (window == NULL)
  {
    std::cerr << "Failed to initialize a GLFW window!\n";
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);

  // Initializing GLEW
  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    std::cerr << "Failed to initialize GLEW!\n";
    std::cerr << "Error: " << glewGetErrorString(err)  << '\n';
    glfwTerminate();
    return 1;
  }

  // Clear Color
  const kdr::Color::RGBA clearColor = kdr::Color::Black;
  glClearColor(
    clearColor.red,
    clearColor.green,
    clearColor.blue,
    clearColor.alpha
  );

  kdr::Core::printEngineInfo();
  std::cout << '\n';
  kdr::Core::printVersionInfo();

  // Shader Program
  kdr::Graphics::Shader defaultShader {
    "resources/Shaders/default.vert",
    "resources/Shaders/default.frag"
  };

  // VAO, VBO, and EBO
  kdr::Graphics::VAO VAO1;
  kdr::Graphics::VBO VBO1 {vertices, sizeof(vertices)};
  kdr::Graphics::EBO EBO1 {indices, sizeof(indices)};

  VAO1.Bind();
  VBO1.Bind();
  EBO1.Bind();

  VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
  VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

  VAO1.Unbind();
  VBO1.Unbind();
  EBO1.Unbind();

  glPointSize(3.f);

  // Main Loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
    {
      kdr::Graphics::usePointMode();
    }
    else if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
    {
      kdr::Graphics::useLineMode();
    }
    else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
      kdr::Graphics::useFillMode();
    }

    glClear(GL_COLOR_BUFFER_BIT);
    defaultShader.Use();
    VAO1.Bind();
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    glfwSwapBuffers(window);
  }

  VAO1.Delete();
  VBO1.Delete();
  EBO1.Delete();
  defaultShader.Delete();
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
