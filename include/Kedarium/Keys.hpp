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
    C = GLFW_KEY_C,
    V = GLFW_KEY_V,
    B = GLFW_KEY_B,
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
