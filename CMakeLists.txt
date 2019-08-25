cmake_minimum_required(VERSION 3.7)

if(UNIX AND NOT APPLE)
    message(STATUS ">>> Linux")
    add_compile_definitions(FL_PLATFORM_LINUX)
else()
    message(STATUS ">>> Windows")
    add_compile_definitions(FL_PLATFORM_WINDOWS)
endif()

add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/cotire.cmake)

add_subdirectory(FlexEngine)
add_subdirectory(Sandbox)