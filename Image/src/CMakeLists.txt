set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})
#add_subdirectory(../lib)
add_library(${BINARY}_lib STATIC ${SOURCES} Formula.cpp Formula.h Image.cpp Image.h ImageTXT.cpp ImageTXT.h ImageBin.cpp ImageBin.h ImageTestCheck.cpp ImageTestCheck.h)
#target_include_directories(Image PUBLIC
#        "${PROJECT_BINARY_DIR}"
#        "${PROJECT_SOURCE_DIR}/lib/ImageLib"
#        )
#target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib ImageLib)
#add_library(../lib STATIC Image.cpp Image.h )