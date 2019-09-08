project(FlexEngine)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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

#visual studio filters
foreach(FILE ${flexFiles})
    # Get the directory of the source file
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)

    # Remove common directory prefix to make the group
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

    # Make sure we are using windows slashes
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    # Group into "Source Files" and "Header Files"
    if ("${FILE}" MATCHES ".*\\.cpp")
       set(GROUP "Source Files${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
       set(GROUP "Header Files${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
endforeach()