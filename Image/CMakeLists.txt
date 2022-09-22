cmake_minimum_required(VERSION 3.10)
project(Image VERSION 1.0)

include(function.cmake)

set(CMAKE_CXX_STANDARD 17)
option(BTEST "build test?" ON)

add_subdirectory(ImageLib)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()
unset(BTEST CACHE)

add_subdirectory(main)