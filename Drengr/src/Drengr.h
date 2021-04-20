#pragma once

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
	// remove min/max define
	#if defined(min)
		#undef min
	#endif
	#if defined(max)
		#undef max
	#endif
	
#endif

#include <util/Assert.h>