#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>

#include "Kedarium/Core.hpp"
#include "Kedarium/Color.hpp"
#include "Kedarium/Graphics.hpp"
#include "Kedarium/Window.hpp"

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

class MainWindow : public kdr::Window::Window
{
  public:
    using kdr::Window::Window;

    ~MainWindow()
    {
      defaultShader.Delete();

      VAO1.Delete();
      VBO1.Delete();
      EBO1.Delete();
    }
    
    void setup()
    {
      VAO1.Bind();
      VBO1.Bind();
      EBO1.Bind();

      VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
      VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

      VAO1.Unbind();
      VBO1.Unbind();
      EBO1.Unbind();
    }

  kdr::Graphics::Shader defaultShader {
    "resources/Shaders/default.vert",
    "resources/Shaders/default.frag"
  };

  kdr::Graphics::VAO VAO1;
  kdr::Graphics::VBO VBO1 {vertices, sizeof(vertices)};
  kdr::Graphics::EBO EBO1 {indices, sizeof(indices)};

  void update()
  {
    if (glfwGetKey(this->getGlfwWindow(), GLFW_KEY_C) == GLFW_PRESS)
    {
      kdr::Graphics::usePointMode();
    }
    else if (glfwGetKey(this->getGlfwWindow(), GLFW_KEY_V) == GLFW_PRESS)
    {
      kdr::Graphics::useLineMode();
    }
    else if (glfwGetKey(this->getGlfwWindow(), GLFW_KEY_B) == GLFW_PRESS)
    {
      kdr::Graphics::useFillMode();
    }
  }

  void render()
  {
    defaultShader.Use();
    VAO1.Bind();

    GLuint modelLoc = glGetUniformLocation(defaultShader.getID(), "model");
    GLuint viewLoc = glGetUniformLocation(defaultShader.getID(), "view");
    GLuint projLoc = glGetUniformLocation(defaultShader.getID(), "proj");

    glm::mat4 model {1.f};
    glm::mat4 view {1.f};
    glm::mat4 proj {1.f};

    view = glm::translate(
      view,
      {0.f, 0.f, -3.f}
    );
    proj = glm::perspective(
      glm::radians(60.f),
      (float)WINDOW_WIDTH / WINDOW_HEIGHT,
      0.1f,
      100.f
    );

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  }
};

int main()
{
  // Window
  MainWindow mainWindow {
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE
  };

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

  // Main Loop
  mainWindow.setup();
  mainWindow.loop();
  mainWindow.close();

  glfwTerminate();
  return 0;
}
