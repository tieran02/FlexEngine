cmake_minimum_required(VERSION 3.7)

if(UNIX AND NOT APPLE)
    message(STATUS ">>> Linux")
    add_compile_definitions(FL_PLATFORM_LINUX)
else()
    message(STATUS ">>> Windows")
    add_compile_definitions(FL_PLATFORM_WINDOWS)
endif()

add_compile_definitions(FL_ENABLE_ASSERTS)

add_subdirectory(FlexEngine)
add_subdirectory(Sandbox)