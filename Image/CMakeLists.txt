cmake_minimum_required(VERSION 3.10)
project(Image VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
add_executable(Image main.cpp)

target_link_libraries(Image PUBLIC lib)
target_include_directories(Image PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib"
        )