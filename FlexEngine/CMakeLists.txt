project(FlexEngine)

#DEFINES
add_compile_definitions(FL_BUILD_DLL)

set(CMAKE_CXX_STANDARD 17)

#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

#VULKAN
find_package(Vulkan REQUIRED)

include_directories(vendor/glad/include)
include_directories(vendor/glfw/include)
include_directories(vendor/glm/include)
include_directories(vendor/spdlog/include)
include_directories(include)


file(GLOB_RECURSE flexFiles
        "include/*.h"
        "src/*.cpp"
        )
		
add_library(FlexEngine SHARED ${flexFiles})
set_target_properties(FlexEngine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "include/pchheader.h")
cotire(FlexEngine)

target_include_directories(FlexEngine PRIVATE Vulkan::Vulkan)
target_link_libraries(FlexEngine glfw Vulkan::Vulkan)