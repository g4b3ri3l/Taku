#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Taku {
	class TAKU_API Log
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
#define TK_CORE_TRACE(...)		::Taku::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TK_CORE_INFO(...)		::Taku::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TK_CORE_WARN(...)		::Taku::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TK_CORE_ERROR(...)		::Taku::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TK_CORE_FATAL(...)		::Taku::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TK_TRACE(...)		::Taku::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TK_INFO(...)		::Taku::Log::GetClientLogger()->info(__VA_ARGS__)
#define TK_WARN(...)		::Taku::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TK_ERROR(...)		::Taku::Log::GetClientLogger()->error(__VA_ARGS__)
#define TK_FATAL(...)		::Taku::Log::GetClientLogger()->fatal(__VA_ARGS__)




