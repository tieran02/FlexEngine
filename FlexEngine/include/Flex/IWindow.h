#pragma once

#include "pchheader.h"
#include "Core.h"
#include "Flex/Events/IEvent.h"

namespace Flex {

    using EventCallbackFn = std::function<void(Event&)>;

    struct FLEX_API WindowProperites
	{
		const char* Title;
		unsigned int Width;
		unsigned int Height;
		bool VSync;

        EventCallbackFn EventCallback;

		WindowProperites(const char* title = "Flex Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height), VSync(false){}

	};

	class FLEX_API IWindow
	{
	public:
	    IWindow(const WindowProperites& properites = WindowProperites()) : m_properties(properites){}
		virtual ~IWindow() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// IWindow attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

        //Get vulkan extensions that are needed for the window
        virtual std::vector<const char*> VulkanExtensions() = 0;

		static IWindow* Create(const WindowProperites& properites = WindowProperites());

    protected:
        WindowProperites m_properties;
	};

}
