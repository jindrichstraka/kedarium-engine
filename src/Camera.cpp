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

void kdr::Camera::updateRotation(GLFWwindow* window)
{
  int windowWidth;
  int windowHeight;
  glfwGetWindowSize(window, &windowWidth, &windowHeight);

  double mouseX;
  double mouseY;
  glfwGetCursorPos(window, &mouseX, &mouseY);

  float deltaX = (float)(mouseX - (windowWidth / 2)) / windowWidth * sensitivity;
  float deltaY = (float)(mouseY - (windowHeight / 2)) / windowHeight * sensitivity;

  yaw += deltaX;
  pitch -= deltaY;

  if (pitch > 89.0f) pitch = 89.0f;
  if (pitch < -89.0f) pitch = -89.0f;

  yaw = std::remainderf(yaw, 360.f);

  glfwSetCursorPos(window, (double)windowWidth / 2, (double)windowHeight / 2);
}

void kdr::Camera::updateMatrix()
{
  glm::vec3 tempFront { 0.f, 0.f, 0.f };
  tempFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  tempFront.y = sin(glm::radians(pitch));
  tempFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  front = glm::normalize(tempFront);

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
