cmake_minimum_required(VERSION 3.21)
project(billiards2D)

set(CMAKE_CXX_STANDARD 23)

add_executable(billiards2D main.cpp)
file(GLOB source_files CONFIGURE_DEPENDS "Shot.wav")
target_link_libraries(billiards2D -lOpenGL32 -lfreeGLUT -lGLU32 winMM.Lib)
