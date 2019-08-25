#pragma once

#ifdef FL_PLATFORM_WINDOWS
	#ifdef FL_BUILD_DLL
		#define FLEX_API __declspec(dllexport)
	#else
		#define FLEX_API __declspec(dllimport)
    #endif
#endif
#if FL_PLATFORM_LINUX
    #define FLEX_API
#endif


#ifdef DEBUG
	#define FL_ASSERT(x, ...) { if(!(x)) { FL_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
	#define FL_CORE_ASSERT(x, ...) { if(!(x)) { FL_LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); } }
#else
	#define FL_ASSERT(x, ...)
	#define FL_CORE_ASSERT(x, ...)
#endif