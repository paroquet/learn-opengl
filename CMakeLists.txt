cmake_minimum_required(VERSION 3.20)
project(learn_opengl)
set(TARGET learn_opengl)
set(CMAKE_CXX_FLAGS "-std=c++17")

add_library(glfw INTERFACE)
target_include_directories(glfw INTERFACE ${CMAKE_SOURCE_DIR}/third_party/glfw/include)
target_link_libraries(glfw INTERFACE ${CMAKE_SOURCE_DIR}/third_party/glfw/lib-arm64/libglfw.3.dylib)

add_library(glad STATIC ${CMAKE_SOURCE_DIR}/third_party/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/third_party/glad/include)

add_library(stb STATIC ${CMAKE_SOURCE_DIR}/third_party/stb/src/stb_image.cpp)
target_include_directories(stb PUBLIC ${CMAKE_SOURCE_DIR}/third_party/stb/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/glm)

add_executable(${TARGET} main.cpp)
target_include_directories(${TARGET} PRIVATE include)
target_link_libraries(${TARGET} glfw glad stb glm)