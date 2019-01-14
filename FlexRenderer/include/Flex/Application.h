#pragma once
#include "Core.h"

namespace Flex {
	class FLEX_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//TO be defined in a client
	Application* CreateApplication();
}