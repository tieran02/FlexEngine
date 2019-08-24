#pragma once
#include "IApplication.h"
#include "Log.h"

#ifdef FL_PLATFORM_WINDOWS

extern Flex::IApplication* Flex::CreateApplication();

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

extern Flex::IApplication* Flex::CreateApplication();

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