#pragma once
#include "Application.h"
#include "Log.h"
#ifdef FL_PLATFROM_WINDOWS

extern Flex::Application* Flex::CreateApplication();

int main()
{
	Flex::Log::Init();
	FL_LOG_CORE_INFO("Initilised Flex Engine");

	auto app = Flex::CreateApplication();

	app->Run();
	delete app;
	return 0;
}

#endif
