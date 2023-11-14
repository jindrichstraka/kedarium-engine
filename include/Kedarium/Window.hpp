#ifndef KDR_WINDOW_HPP
#define KDR_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Graphics.hpp"
#include "Camera.hpp"

namespace kdr
{
  /**
   * Structure containing properties for a window configuration.
   */
  struct WindowProps
  {
    unsigned int width;
    unsigned int height;
    std::string title;

    /**
     * Constructor for WindowProps.
     *
     * @param width  The width of the window.
     * @param height The height of the window.
     * @param title  The title of the window.
     */
    WindowProps(
      const unsigned int width,
      const unsigned int height,
      const std::string& title
    ) : width(width), height(height), title(title)
    {}
  };

  /**
   * Represents a window in the Kedarium Engine.
   */
  class Window
  {
    public:
      /**
       * Constructor for Window with window properties.
       *
       * @param windowProps Window properties containing width, height, and title.
       */
      Window(kdr::WindowProps windowProps)
      : width(windowProps.width), height(windowProps.height), title(windowProps.title)
      { this->_initialize(); }
      /**
       * Constructor for Window with only width and height.
       *
       * @param width  The width of the window.
       * @param height The height of the window.
       */
      Window(const unsigned int width, const unsigned int height)
      : width(width), height(height)
      { this->_initialize(); }
      /**
       * Constructor for Window with width, height, and title.
       *
       * @param width  The width of the window.
       * @param height The height of the window.
       * @param title  The title of the window.
       */
      Window(const unsigned int width, const unsigned int height, const std::string& title)
      : width(width), height(height), title(title)
      { this->_initialize(); }
      /**
       * Virtual destructor for the Window class.
       */
      virtual ~Window();

      /**
       * Sets the currently bound camera for the window.
       *
       * @param camera A pointer to the Camera object to be bound.
       */
      void setBoundCamera(kdr::Camera* camera)
      { this->boundCamera = camera; }

      /**
       * Retrieves the currently bound camera for the window.
       *
       * @return A pointer to the bound Camera object.
       */
      kdr::Camera* getBoundCamera()
      { return this->boundCamera; }
      /**
       * Retrieves the current time in seconds since the GLFW initialization.
       *
       * @return The current time in seconds.
       */
      const float getTime() const
      { return glfwGetTime(); }
      /**
       * Retrieves the time elapsed between the current frame and the previous frame.
       *
       * @return The time elapsed in seconds.
       */
      const float getDeltaTime() const
      { return this->deltaTime; }

      /**
       * Maximizes the window to fill the screen.
       */
      void maximize();
      /**
       * Restores the window from a maximized state.
       */
      void unmaximize();
      /**
       * Starts the main loop for the window.
       */
      void loop();
      /**
       * Closes the window.
       */
      void close();
      /**
       * Binds a shader for use in the window.
       *
       * @param shader The shader to be bound for rendering.
       */
      void bindShader(kdr::Graphics::Shader& shader)
      {
        shader.Use();
        this->usedShaderID = shader.getID();
      }

    protected:
      bool fullscreenOn       {false};
      bool pressingFullscreen {false};

      /**
       * Retrieves the GLFW window associated with the Window instance.
       *
       * @return A pointer to the GLFW window.
       */
      GLFWwindow* getGlfwWindow() const
      { return this->glfwWindow; }

      /**
       * To be implemented by derived classes. Sets up the window environment.
       */
      virtual void setup() = 0;
      /**
       * To be implemented by derived classes. Updates the window state.
       */
      virtual void update() = 0;
       /**
       * To be implemented by derived classes. Renders the window state.
       */
      virtual void render() = 0;

    private:
      unsigned int width  {800};
      unsigned int height {600};
      std::string  title  {"Kedarium Engine"};

      GLFWwindow* glfwWindow;

      kdr::Camera* boundCamera  {NULL};
      GLuint       usedShaderID {0};

      float deltaTime   {0.f};
      float lastTime    {0.f};

      /**
       * Initializes GLFW for the window.
       */
      void _initializeGlfw();
      /**
       * Initializes GLEW for the window.
       */
      void _initializeGlew();
      /**
       * Initializes OpenGL settings for the window.
       */
      void _initializeOpenGLSettings();
      /**
       * Initializes the window.
       */
      void _initialize();
      /**
       * Sets up the window environment.
       */
      void _setup();
      /**
       * Updates the time difference between the current and previous frames.
       */
      void _updateDeltaTime();
      /**
       * Updates the associated camera in the window.
       */
      void _updateCamera();
      /**
       * Updates the window state.
       */
      void _update();
      /**
       * Renders the window state.
       */
      void _render();
  };
}

#endif // KDR_WINDOW_HPP
