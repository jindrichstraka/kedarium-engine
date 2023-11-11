#include "Kedarium/File.hpp"

const std::string kdr::File::getContents(const char* path)
{
  std::ifstream file(path);
  if (!file.is_open())
  {
    std::cerr << "Failed to open a file (" << path << ")!\n";
    return "";
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  if (file.bad())
  {
    std::cerr << "Failed to read a file (" << path << ")!\n";
    file.close();
    return "";
  }

  file.close();
  return buffer.str();
}
