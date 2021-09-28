#pragma once

#ifdef WORLDCLOCK_PLATFORM_WINDOWS
	#ifdef WORLDCLOCK_BUILD_DLL
		#define WORLDCLOCK_API __declspec(dllexport)
	#else
		#define WORLDCLOCK_API __declspec(dllimport)
	#endif
#else
	#error WorldClock is not supported by this system!
#endif