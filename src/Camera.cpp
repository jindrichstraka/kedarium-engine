#include "Kedarium/Camera.hpp"

void kdr::Camera::updateMatrix()
{
  glm::mat4 view {1.f};
  glm::mat4 proj {1.f};

  view = glm::translate(
    view,
    {0.f, 0.f, -3.f}
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
