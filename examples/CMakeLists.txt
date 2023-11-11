# Executable
add_executable(
  example
  Main.cpp
)

# Libraries
target_link_libraries(example PRIVATE GL GLEW glfw)
