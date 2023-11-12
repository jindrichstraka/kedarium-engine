#ifndef KDR_CORE_HPP
#define KDR_CORE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

namespace kdr
{
  namespace Core
  {
    /**
     * Prints general engine information.
     */
    void printEngineInfo();
    /**
     * Prints version information of external libraries used by the engine.
     */
    void printVersionInfo();
  }
}

#endif // KDR_CORE_HPP
