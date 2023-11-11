#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const std::string  WINDOW_TITLE  = "Kedarium Engine";

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
  GLclampf red   = 0.f;
  GLclampf green = 0.f;
  GLclampf blue  = 0.f;
  GLclampf alpha = 1.f;
  glClearColor(red, green, blue, alpha);

  // Main Loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
