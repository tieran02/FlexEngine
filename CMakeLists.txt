cmake_minimum_required(VERSION 3.14)

if(UNIX AND NOT APPLE)
    message(STATUS ">>> Linux")
    add_compile_definitions(FL_PLATFORM_LINUX)
else()
    message(STATUS ">>> Windows")
    add_compile_definitions(FL_PLATFORM_WINDOWS)
endif()


add_subdirectory(FlexEngine)
add_subdirectory(Sandbox)