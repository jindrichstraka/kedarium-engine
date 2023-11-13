#ifndef KDR_KEYS_HPP
#define KDR_KEYS_HPP

#include <GLFW/glfw3.h>

namespace kdr
{
  /**
   * Enumeration of custom keys mapping to GLFW key codes.
   */
  enum Key
  {
    A = GLFW_KEY_A,
    B = GLFW_KEY_B,
    C = GLFW_KEY_C,
    D = GLFW_KEY_D,
    S = GLFW_KEY_S,
    V = GLFW_KEY_V,
    W = GLFW_KEY_W,
    Space = GLFW_KEY_SPACE,
    LeftShift = GLFW_KEY_LEFT_SHIFT,
  };

  namespace Keys
  {
    /**
     * Checks if a specific key is currently pressed.
     *
     * @param window The GLFW window context.
     * @param key    The custom key to check.
     * @return True if the key is currently pressed, otherwise false.
     */
    const bool isPressed(GLFWwindow* window, const kdr::Key& key);
  }
}

#endif // KDR_KEYS_HPP
