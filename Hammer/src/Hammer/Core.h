#pragma once
#ifdef HM_PLATFORM_WINDOWS
	#ifdef HM_BUILD_DLL
		#define HM_API __declspec(dllexport)
	#else 
		#define HM_API __declspec(dllimport)
	#endif
#else
	#error HM_API only supports Windows!
#endif

#define ASSERT(x)if(!x)__debugbreak();

#define BIT(x) (1<<x)
#define HM_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
