#include "Kedarium/Camera.hpp"

void kdr::Camera::updateMovement(GLFWwindow* window, const float deltaTime)
{
  if (kdr::Keys::isPressed(window, kdr::Key::W))
  {
    position += 3.f * deltaTime * front;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::S))
  {
    position -= 3.f * deltaTime * front;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::A))
  {
    position -= glm::normalize(glm::cross(front, up)) * 3.f * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::D))
  {
    position += glm::normalize(glm::cross(front, up)) * 3.f * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::Space))
  {
    position.y += 3.f * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::LeftShift))
  {
    position.y -= 3.f * deltaTime;
  }
}

void kdr::Camera::updateMatrix()
{
  glm::mat4 view {1.f};
  glm::mat4 proj {1.f};

  view = glm::lookAt(
    position,
    position + front,
    up
  );
  proj = glm::perspective(
    glm::radians(fov),
    aspect,
    0.1f,
    100.f
  );

  matrix = proj * view;
}

void kdr::Camera::applyMatrix(const GLuint shaderID)
{
  GLuint cameraMatrixLoc = glGetUniformLocation(shaderID, "cameraMatrix");
  glUniformMatrix4fv(cameraMatrixLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}
