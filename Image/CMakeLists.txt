cmake_minimum_required(VERSION 3.10)
project(Image VERSION 1.0)

include(function.cmake)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ImageLib)
add_subdirectory(gtest)
add_subdirectory(test)
option(BTEST "build test?" ON)

#if(BTEST)
#    add_subdirectory(gtest)
#    add_subdirectory(test)
#endif()

add_subdirectory(main)