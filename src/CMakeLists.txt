add_library(
  Kedarium
  Core.cpp
  File.cpp
  Graphics.cpp
  Window.cpp
)

# Include Directory
target_include_directories(Kedarium PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
