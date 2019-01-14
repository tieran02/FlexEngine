#pragma once
#include "Application.h"
#ifdef FL_PLATFROM_WINDOWS

extern Flex::Application* Flex::CreateApplication();

int main()
{
	auto app = Flex::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
