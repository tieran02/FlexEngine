#pragma once
#include "Core.h"
#include "IWindow.h"
#include "Flex/Events/IEvent.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Flex {
	class IApplication
	{
	public:
		FLEX_API IApplication();
		FLEX_API virtual ~IApplication();
		FLEX_API void Run();

		FLEX_API void OnEvent(Event& e);

		FLEX_API void PushLayer(ILayer* layer);
		FLEX_API void PushOverlay(ILayer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent e);

		std::unique_ptr<IWindow> m_window;
		bool m_running{ true };
		LayerStack m_layerStack;
	};

	//TO be defined in a client
	IApplication* CreateApplication();
}
