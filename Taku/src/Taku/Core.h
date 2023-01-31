#pragma once

#ifdef TK_PLATFORM_WINDOWS
	#ifdef TK_BUILD_DLL
		#define TAKU_API __declspec(dllexport)
	#else
		#define TAKU_API __declspec(dllimport)
	#endif
#else
	#error Taku only supports Windows!
#endif

#define BIT(x) (1 << x)