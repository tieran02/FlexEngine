project(Sandbox)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)

include_directories(../FlexEngine/vendor/glm/include)
include_directories(../FlexEngine/vendor/spdlog/include)
include_directories(../FlexEngine/include)
include_directories(include)

file(GLOB_RECURSE sandboxFiles
        "include/*.h"
        "src/*.cpp"
        )

add_executable(Sandbox ${sandboxFiles})
target_link_libraries(Sandbox FlexEngine)
