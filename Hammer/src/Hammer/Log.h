#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hammer
{


class HM_API Log
{
public:
	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return s_CoreLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return s_ClientLogger; }

	static void Init();

	
private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

}

#ifndef HM_DIST
	#define HM_CORE_TRACE(...) Hammer::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define HM_CORE_DEBUG(...) Hammer::Log::GetCoreLogger()->debug(__VA_ARGS__)
	#define HM_CORE_INFO(...) Hammer::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define HM_CORE_WARN(...) Hammer::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define HM_CORE_CRITICAL Hammer::Log::GetCoreLogger()->critical(__VA_ARGS__)
	
	#define HM_TRACE(...) Hammer::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define HM_DEBUG(...) Hammer::Log::GetClientLogger()->debug(__VA_ARGS__)
	#define HM_INFO(...) Hammer::Log::GetClientLogger()->info(__VA_ARGS__)
	#define HM_WARN(...) Hammer::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define HM_CRITICAL(...) Hammer::Log::GetClientLoggerr()->critical(__VA_ARGS__)
#endif
