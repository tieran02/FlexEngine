project(FlexEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "clang++")

#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

include_directories(vendor/glad/include)
include_directories(vendor/glfw/include)
include_directories(vendor/glm/include)
include_directories(vendor/spdlog/include)
include_directories(include)


file(GLOB_RECURSE glad
        "vendor/glad/*.h"
        "vendor/glad/*.c")

file(GLOB_RECURSE flexFiles
        "include/*.h"
        "src/*.cpp"
        )

add_library(FlexEngine SHARED ${glad} ${flexFiles})
target_link_libraries(FlexEngine glfw)