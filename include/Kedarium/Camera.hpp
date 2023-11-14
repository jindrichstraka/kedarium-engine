#ifndef KDR_CAMERA_HPP
#define KDR_CAMERA_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Keys.hpp"

namespace kdr
{
  /**
   * Structure containing properties for a camera configuration.
   */
  struct CameraProps
  {
    float fov;
    float aspect;
    float near;
    float far;

    /**
     * Constructor for CameraProps.
     *
     * @param fov     Field of view for the camera.
     * @param aspect  Aspect ratio of the camera.
     * @param near    Near plane distance.
     * @param far     Far plane distance.
     */
    CameraProps(
      const float fov,
      const float aspect,
      const float near,
      const float far
    ) : fov(fov), aspect(aspect), near(near), far(far)
    {}
  };

  /**
   * Represents a camera in the Kedarium Engine.
   */
  class Camera
  {
    public:
      /**
       * Constructs a camera with provided camera properties.
       *
       * @param cameraProps Camera properties including fov, aspect, near, and far.
       */
      Camera(const CameraProps& cameraProps)
      : fov(cameraProps.fov), aspect(cameraProps.aspect), near(cameraProps.near), far(cameraProps.far)
      {}
      /**
       * Constructs a camera with specific parameters.
       *
       * @param fov     Field of view for the camera.
       * @param aspect  Aspect ratio of the camera.
       * @param near    Near plane distance.
       * @param far     Far plane distance.
       */
      Camera(const float fov, const float aspect, const float near, const float far)
      : fov(fov), aspect(aspect), near(near), far(far)
      {}

      /**
       * Sets the aspect ratio of the camera.
       *
       * @param aspect New aspect ratio for the camera.
       */
      void setAspect(const float aspect)
      { this->aspect = aspect; }

      /**
       * Updates the camera's movement based on input received from a GLFW window.
       *
       * @param window      The GLFW window context providing input for camera movement.
       * @param deltaTime   The time elapsed between the current frame and the previous frame.
       */
      void updateMovement(GLFWwindow* window, const float deltaTime);
      /**
       * Updates the camera's rotation based on input received from a GLFW window.
       *
       * @param window The GLFW window context providing input for camera rotation.
       */
      void updateRotation(GLFWwindow* window);
      /**
       * Updates the camera matrix for transformations.
       */
      void updateMatrix();
      /**
       * Applies the camera matrix to a specific shader for rendering.
       *
       * @param shaderID The ID of the shader to apply the camera matrix.
       */
      void applyMatrix(const GLuint shaderID);

    private:
      float fov    {60.f};
      float aspect {1.f};
      float near   {0.1f};
      float far    {100.f};

      float speed       {3.f};
      float sensitivity {20.f};

      float yaw   {-90.f};
      float pitch {0.f};

      glm::vec3 position {0.f, 0.f,  5.f};
      glm::vec3 front    {0.f, 0.f, -1.f};
      glm::vec3 up       {0.f, 1.f,  0.f};
      glm::mat4 matrix   {1.f};
  };
}

#endif // KDR_CAMERA_HPP
