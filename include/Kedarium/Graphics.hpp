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
     * Sets the rendering mode to display polygons as points.
     */
    void usePointMode();
    /**
     * Sets the rendering mode to display polygons as lines.
     */
    void useLineMode();
    /**
     * Sets the rendering mode to display polygons filled with color.
     */
    void useFillMode();

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

    /**
     * Represents a Vertex Buffer Object (VBO) to manage vertex data in OpenGL.
     */
    class VBO
    {
      public:
        /**
         * Constructs a Vertex Buffer Object.
         *
         * @param vertices An array of GLfloat representing vertex data.
         * @param size     The size in bytes of the provided vertex data.
         */
        VBO(const GLfloat vertices[], GLsizeiptr size);

        /**
         * Retrieves the ID of the Vertex Buffer Object.
         *
         * @return The ID of the VBO.
         */
        const GLuint getID() const
        { return this->ID; }

        /**
         * Binds the VBO for use.
         */
        void Bind()
        { glBindBuffer(GL_ARRAY_BUFFER, this->ID); }
        /**
         * Unbinds the VBO.
         */
        void Unbind()
        { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        /**
         * Deletes the VBO from memory.
         */
        void Delete()
        { glDeleteBuffers(1, &this->ID); }

      private:
        GLuint ID;
    };

    /**
     * Represents an Element Buffer Object (EBO) in OpenGL used to manage element indices.
     */
    class EBO
    {
      public:
        /**
         * Constructs an Element Buffer Object.
         *
         * @param indices An array of GLuint representing element indices.
         * @param size    The size in bytes of the provided element indices.
         */
        EBO(const GLuint indices[], GLsizeiptr size);

        /**
         * Retrieves the ID of the Element Buffer Object.
         *
         * @return The ID of the EBO.
         */
        const GLuint getID() const
        { return this->ID; }

        /**
         * Binds the EBO for use.
         */
        void Bind()
        { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID); }
        /**
         * Unbinds the EBO.
         */
        void Unbind()
        { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
        /**
         * Deletes the EBO from memory.
         */
        void Delete()
        { glDeleteBuffers(1, &this->ID); }

      private:
        GLuint ID;
    };

    /**
     * Represents a Vertex Array Object (VAO) used to encapsulate the vertex attribute configuration in OpenGL.
     */
    class VAO
    {
      public:
        /**
         * Constructs a Vertex Array Object.
         */
        VAO()
        { glGenVertexArrays(1, &this->ID); }

        /**
         * Retrieves the ID of the Vertex Array Object.
         *
         * @return The ID of the VAO.
         */
        const GLuint getID() const
        { return this->ID; }

        /**
         * Links a VBO (Vertex Buffer Object) to the VAO, specifying attribute details.
         *
         * @param VBO     The VBO to link.
         * @param layout  The attribute layout location.
         * @param size    The number of components per attribute.
         * @param type    The data type of each component.
         * @param stride  The byte offset between consecutive vertex attributes.
         * @param offset  The offset of the first component in the VBO.
         */
        void LinkAttrib(kdr::Graphics::VBO& VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset);
        /**
         * Binds the VAO for use in rendering.
         */
        void Bind()
        { glBindVertexArray(this->ID); }
        /**
         * Unbinds the VAO.
         */
        void Unbind()
        { glBindVertexArray(0); }
        /**
         * Deletes the VAO from memory.
         */
        void Delete()
        { glDeleteVertexArrays(1, &this->ID); }
  
      private:
        GLuint ID;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
