#pragma once

#ifdef FL_PLATFROM_WINDOWS
	#ifdef FL_BUILD_DLL
		#define FLEX_API __declspec(dllexport)
	#else
		#define FLEX_API __declspec(dllimport)
    #endif
#endif
#if FL_PLATFORM_LINUX
    #ifdef FL_BUILD_DLL
        #define FLEX_API __attribute__((visibility("default")))
    #endif
#endif


#ifdef FL_ENABLE_ASSERTS
	#define FL_ASSERT(x, ...) { if(!(x)) { FL_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FL_CORE_ASSERT(x, ...) { if(!(x)) { FL_LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FL_ASSERT(x, ...)
	#define FL_CORE_ASSERT(x, ...)
#endif