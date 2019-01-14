#pragma once

#ifdef FL_PLATFROM_WINDOWS
	#ifdef FL_BUILD_DLL
		#define FLEX_API __declspec(dllexport)
	#else
		#define FLEX_API __declspec(dllimport)
	#endif
#else
	#error Flex only supports Windows!
#endif
