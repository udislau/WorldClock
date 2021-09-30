#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace WorldClock {

	class WORLDCLOCK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define WORLDCLOCK_CORE_TRACE(...)    ::WorldClock::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WORLDCLOCK_CORE_INFO(...)     ::WorldClock::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WORLDCLOCK_CORE_WARN(...)     ::WorldClock::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WORLDCLOCK_CORE_ERROR(...)    ::WorldClock::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WORLDCLOCK_CORE_FATAL(...)    ::WorldClock::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define WORLDCLOCK_TRACE(...)	      ::WorldClock::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WORLDCLOCK_INFO(...)	      ::WorldClock::Log::GetClientLogger()->info(__VA_ARGS__)
#define WORLDCLOCK_WARN(...)	      ::WorldClock::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WORLDCLOCK_ERROR(...)	      ::WorldClock::Log::GetClientLogger()->error(__VA_ARGS__)
#define WORLDCLOCK_FATAL(...)	      ::WorldClock::Log::GetClientLogger()->fatal(__VA_ARGS__) 