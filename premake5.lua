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
IncludeDir["GLFW"] = "FlexEngine/vendor/GLFW/include"


include "FlexEngine/vendor/GLFW"

project "FlexEngine"
	location "FlexEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	buildoptions "/MT"

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/include/Flex",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FL_PLATFROM_WINDOWS",
			"FL_BUILD_DLL"
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
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	buildoptions "/MT"

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"FlexEngine/vendor/spdlog/include",
		"FlexEngine/include/",
		"FlexEngine/include/Flex",
		"%{prj.name}/include/"
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
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"