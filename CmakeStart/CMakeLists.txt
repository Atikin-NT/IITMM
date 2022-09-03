cmake_minimum_required(VERSION 3.10)
project(CmakeStart VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
add_executable(CmakeStart main.cpp)

target_link_libraries(CmakeStart PUBLIC lib)
target_include_directories(CmakeStart PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib"
        )