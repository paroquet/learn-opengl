cmake_minimum_required(VERSION 3.20)
project(learn_opengl)
set(CMAKE_CXX_FLAGS "-std=c++17")

add_library(glfw INTERFACE)
target_include_directories(glfw INTERFACE ${CMAKE_SOURCE_DIR}/third_party/glfw/include)
target_link_libraries(glfw INTERFACE ${CMAKE_SOURCE_DIR}/third_party/glfw/lib-arm64/libglfw.3.dylib)

add_library(glad STATIC ${CMAKE_SOURCE_DIR}/third_party/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/third_party/glad/include)

add_library(stb STATIC ${CMAKE_SOURCE_DIR}/third_party/stb/src/stb_image.cpp)
target_include_directories(stb PUBLIC ${CMAKE_SOURCE_DIR}/third_party/stb/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/glm)

# add_library(freetype INTERFACE)
# target_link_libraries(freetype INTERFACE ${CMAKE_SOURCE_DIR}/third_party/freetype/libs/libfreetype.a)
# target_include_directories(freetype INTERFACE ${CMAKE_SOURCE_DIR}/third_party/freetype/include)

find_package(assimp REQUIRED)

list(APPEND LIBS glfw glad stb glm assimp::assimp)

add_executable(test_start test_start.cpp)
target_include_directories(test_start PRIVATE include)
target_link_libraries(test_start ${LIBS})

add_executable(test_light test_light.cpp)
target_include_directories(test_light PRIVATE include)
target_link_libraries(test_light ${LIBS})

file(GLOB SRC src/*.cpp src/**/*.cpp include/*.h)
add_executable(test_model test_model.cpp ${SRC})
target_include_directories(test_model PRIVATE include)
target_link_libraries(test_model ${LIBS})
