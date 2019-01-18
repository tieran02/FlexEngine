#pragma once
#include "flpch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Flex {

	struct WindowProperites
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		bool VSync;

		WindowProperites(const std::string& title = "Flex Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height), VSync(false){}

	};

	class FLEX_API Window
	{
	public:

		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProperites& properites = WindowProperites());

	};

}
