#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace  Flex {
	class Log
	{
	public:
		FLEX_API static void Init();

		FLEX_API inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		FLEX_API inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Engine log macros
#define FL_LOG_CORE_TRACE(...) ::Flex::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FL_LOG_CORE_INFO(...) ::Flex::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FL_LOG_CORE_WARNING(...) ::Flex::Log::GetCoreLogger()->warning(__VA_ARGS__)
#define FL_LOG_CORE_ERROR(...) ::Flex::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FL_LOG_CORE_FATAL(...) ::Flex::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define FL_LOG_TRACE(...) ::Flex::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FL_LOG_INFO(...) ::Flex::Log::GetClientLogger()->info(__VA_ARGS__)
#define FL_LOG_WARNING(...) ::Flex::Log::GetClientLogger()->warning(__VA_ARGS__)
#define FL_LOG_ERROR(...) ::Flex::Log::GetClientLogger()->error(__VA_ARGS__)
#define FL_LOG_FATAL(...) ::Flex::Log::GetClientLogger()->critical(__VA_ARGS__)