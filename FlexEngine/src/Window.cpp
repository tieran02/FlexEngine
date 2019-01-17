#include "Window.h"
#include "Log.h"

namespace Flex
{
	bool Window::m_glfwInit = false;

	Window::Window(const WindowProperites& properites)
	{
		m_data = properites;
		init();
		FL_LOG_CORE_INFO("Window Created");

	}


	Window::~Window()
	{
	}

	void Window::init()
	{
		if (!m_glfwInit)
		{
			int success = glfwInit();
			FL_CORE_ASSERT(success, "Failed to init GLFW");
			m_glfwInit = true;
		}
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		m_glfwWindow = glfwCreateWindow(m_data.Width, m_data.Height, m_data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_glfwWindow);
	}

	void Window::Update()
	{
		glfwPollEvents();
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_glfwWindow);
	}

	Window* Window::Create(const WindowProperites& properites)
	{
		return new Window(properites);
	}
}
