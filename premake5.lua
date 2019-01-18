workspace "Flex"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "FlexEngine/vendor/glfw/include"

VULKAN = "F:/VulkanSDK/1.1.82.1"


include "FlexEngine/vendor/glfw"

project "FlexEngine"
	location "FlexEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "flpch.h"
	pchsource "FlexEngine/src/flpch.cpp"

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/include",
		"%{prj.name}/vendor/spdlog/include",
		"".. VULKAN .."/Include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"".. VULKAN .."/Lib/vulkan-1.lib",
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FL_PLATFROM_WINDOWS",
			"FL_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"GLFW_INCLUDE_VULKAN"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines
		{
			"FL_DEBUG",
			"FL_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		buildoptions "/MD"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"FlexEngine/vendor/spdlog/include",
		"FlexEngine/include/",
	}

	links
	{
		"FlexEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FL_PLATFROM_WINDOWS"
		}

	filter "configurations:Debug"
		defines
		{
			"FL_DEBUG",
			"FL_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		buildoptions "/MD"
		optimize "On"