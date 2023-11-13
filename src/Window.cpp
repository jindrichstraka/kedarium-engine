#include "Kedarium/Window.hpp"

kdr::Window::~Window()
{
  glfwDestroyWindow(glfwWindow);
}

void kdr::Window::loop()
{
  while (!glfwWindowShouldClose(glfwWindow))
  {
    _update();
    _render();
  }
}

void kdr::Window::close()
{
  glfwSetWindowShouldClose(glfwWindow, GLFW_TRUE);
}

void kdr::Window::_initializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void kdr::Window::_initializeGlew()
{
  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    std::cerr << "Failed to initialize GLEW!\n";
    std::cerr << "Error: " << glewGetErrorString(err)  << '\n';
    glfwTerminate();
  }
}

void kdr::Window::_initializeOpenGLSettings()
{
  glPointSize(5.f);
}

void kdr::Window::_initialize()
{
  _initializeGlfw();

  glfwWindow = glfwCreateWindow(
    width,
    height,
    title.c_str(),
    NULL,
    NULL
  );

  // Validating the Window
  if (glfwWindow == NULL)
  {
    std::cerr << "Failed to initialize a GLFW window!\n";
    glfwTerminate();
  }
  glfwMakeContextCurrent(glfwWindow);

  _initializeGlew();
  _initializeOpenGLSettings();
}

void kdr::Window::_setup()
{
  setup();
}

void kdr::Window::_updateCamera()
{
  if (boundCamera == NULL) return;

  boundCamera->updateMatrix();
  boundCamera->applyMatrix(usedShaderID);
}

void kdr::Window::_update()
{
  glfwPollEvents();
  update();
  _updateCamera();
}

void kdr::Window::_render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  render();
  glfwSwapBuffers(glfwWindow);
}
