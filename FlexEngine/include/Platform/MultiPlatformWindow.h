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

		inline unsigned int GetWidth() const override { return m_data.Width; }
		inline unsigned int GetHeight() const override { return m_data.Height; }

		// IWindow attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProperites& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_data;
	};
}
