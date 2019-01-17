#pragma once
#include "Core.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <string>

namespace Flex {

	struct WindowProperites
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		bool VSync;

		FLEX_API WindowProperites(const std::string& title = "Flex Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height), VSync(false){}

	};

	class Window
	{
	public:
		FLEX_API Window(const WindowProperites& properites);
		FLEX_API ~Window();

		FLEX_API static Window* Create(const WindowProperites& properites = WindowProperites());

		FLEX_API void Update();

		FLEX_API bool ShouldClose();
	private:
		GLFWwindow* m_glfwWindow;
		static bool m_glfwInit;

		void init();

		WindowProperites m_data;
	};

}
