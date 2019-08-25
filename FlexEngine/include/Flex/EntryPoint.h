#pragma once
#include "Application.h"

#ifdef FL_PLATFORM_WINDOWS

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

#ifdef FL_PLATFORM_LINUX

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