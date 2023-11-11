#ifndef KDR_GRAPHICS_HPP
#define KDR_GRAPHICS_HPP

#include <GL/glew.h>
#include <iostream>
#include <string>

#include "File.hpp"

namespace kdr
{
  namespace Graphics
  {
    /**
     * Represents an abstraction of an OpenGL shader program.
     */
    class Shader
    {
      public:
        /**
         * Constructor for Shader class.
         *
         * @param vertexSourcePath   The file path to the vertex shader source.
         * @param fragmentSourcePath The file path to the fragment shader source.
         */
        Shader(const char* vertexSourcePath, const char* fragmentSourcePath);

         /**
         * Retrieves the ID of the shader program.
         *
         * @return The ID of the shader program.
         */
        const GLuint getID() const
        { return this->ID; }

        /**
         * Activates the shader for use.
         */
        void Use()
        { glUseProgram(this->ID); }
        /**
         * Deletes the shader program.
         */
        void Delete()
        { glDeleteProgram(this->ID); }

      private:
        GLuint ID;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
