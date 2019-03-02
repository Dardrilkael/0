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