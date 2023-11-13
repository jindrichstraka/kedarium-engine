#include "Kedarium/Keys.hpp"

const bool kdr::Keys::isPressed(GLFWwindow* window, const kdr::Key& key)
{
  return glfwGetKey(window, key) == GLFW_PRESS;
}
