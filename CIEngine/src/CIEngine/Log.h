#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"


namespace CIEngine {

	class CIENGINE_API Log
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

// Core Log Macros

#define CIE_CORE_TRACE(...)::CIEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CIE_CORE_DEBUG(...)::CIEngine::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define CIE_CORE_INFO(...)::CIEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CIE_CORE_WARN(...)::CIEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CIE_CORE_ERROR(...)::CIEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CIE_CORE_CRITICAL(...)::CIEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros

#define CIE_TRACE(...)::CIEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CIE_DEBUG(...)::CIEngine::Log::GetClientLogger()->debug(__VA_ARGS__)
#define CIE_INFO(...)::CIEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CIE_WARN(...)::CIEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CIE_ERROR(...)::CIEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CIE_CRITICAL(...)::CIEngine::Log::GetClientLogger()->critical(__VA_ARGS__)