#pragma once

#include "Flex/IWindow.h"
#include "GLFW/glfw3.h"

namespace Flex 
{
	class MultiPlatformWindow : public IWindow
	{
	public:
		MultiPlatformWindow(const WindowProperites& props);
		~MultiPlatformWindow() override;

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_properties.Width; }
		inline unsigned int GetHeight() const override { return m_properties.Height; }

		// IWindow attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_properties.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

        std::vector<const char*> VulkanExtensions() override;

    private:
		virtual void Init(const WindowProperites& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;
	};
}
