#include "Kedarium/Graphics.hpp"

void kdr::Graphics::usePointMode()
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}

void kdr::Graphics::useLineMode()
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void kdr::Graphics::useFillMode()
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

kdr::Graphics::Shader::Shader(const char* vertexSourcePath, const char* fragmentSourcePath)
{
  // Shader Sources
  const std::string vertexShaderSource = kdr::File::getContents(vertexSourcePath);
  const std::string fragmentShaderSource = kdr::File::getContents(fragmentSourcePath);

  const char* vertexShaderSourceC = vertexShaderSource.c_str();
  const char* fragmentShaderSourceC = fragmentShaderSource.c_str();

  // Vertex and Fragment Shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSourceC, NULL);
  glShaderSource(fragmentShader, 1, &fragmentShaderSourceC, NULL);

  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  // Validating the Shaders
  int success {0};
  char infoLog[512];

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cerr << "Failed to compile the vertex shader!\n";
    std::cerr << "Error: " << infoLog << '\n';
  }

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cerr << "Failed to compile the fragment shader!\n";
    std::cerr << "Error: " << infoLog << '\n';
  }

  // Shader Program
  this->ID = glCreateProgram();
  glAttachShader(this->ID, vertexShader);
  glAttachShader(this->ID, fragmentShader);
  glLinkProgram(this->ID);

  // Validating the Program
  glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
    std::cerr << "Failed to link the shader program!\n";
    std::cerr << "Error: " << infoLog << '\n';
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}
