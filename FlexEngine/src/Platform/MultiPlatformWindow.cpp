#include "pchheader.h"
#include "Platform/MultiPlatformWindow.h"
#include "Flex/Events/ApplicationEvent.h"
#include "Flex/Events/MouseEvent.h"
#include "Flex/Events/KeyEvent.h"
#include <Platform/Vulkan/VulkanRenderer.h>

namespace Flex {

	static bool s_GLFWInitialized = false;

	IWindow* IWindow::Create(const WindowProperites& props)
	{
		return new MultiPlatformWindow(props);
	}

	static void GLFWErrorCallback(int error, const char* description)
	{
		FL_LOG_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	MultiPlatformWindow::MultiPlatformWindow(const WindowProperites& props) : IWindow(props), m_Window{nullptr}
	{
		Init(props);
	}

	MultiPlatformWindow::~MultiPlatformWindow()
	{
		Shutdown();
	}

	void MultiPlatformWindow::OnUpdate()
	{
		glfwPollEvents();
	}

	void MultiPlatformWindow::SetVSync(bool enabled)
	{
		m_properties.VSync = enabled;
	}

	bool MultiPlatformWindow::IsVSync() const
	{
		return m_properties.VSync;
	}

	void MultiPlatformWindow::Init(const WindowProperites& props)
	{
		FL_LOG_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			FL_CORE_ASSERT(success, "Could not intialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_properties.Title, nullptr, nullptr);
		glfwSetWindowUserPointer(m_Window, &m_properties);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowProperites& data = *(WindowProperites*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
            WindowProperites& data = *(WindowProperites*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
            WindowProperites& data = *(WindowProperites*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleaseEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			default:
			{
                break;
            }
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
            WindowProperites& data = *(WindowProperites*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
            default:
            {
                break;
            }
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
            WindowProperites& data = *(WindowProperites*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
            WindowProperites& data = *(WindowProperites*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});
	}

	void MultiPlatformWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

    std::vector<const char*> MultiPlatformWindow::VulkanExtensions()
    {
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions;
        extensions.reserve(glfwExtensionCount);
        for (int i = 0; i < glfwExtensionCount; ++i)
        {
            extensions.emplace_back(glfwExtensions[i]);
        }
        return extensions;
    }
}
