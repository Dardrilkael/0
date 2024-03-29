#include "hmpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hammer {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::Init()
{
	
	spdlog::set_pattern("%^[%T] %n: %v%$");

	s_ClientLogger = spdlog::stdout_color_mt("SB_Aplication");
	s_CoreLogger = spdlog::stdout_color_mt("Hammer Api");

	s_ClientLogger->set_level(spdlog::level::trace);
	s_CoreLogger->set_level(spdlog::level::trace);

	s_CoreLogger->debug("Initializing Log");
	HM_CORE_TRACER
	
}



}