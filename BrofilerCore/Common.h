#pragma once

#include <MTConfig.h>

#if MT_PLATFORM_WINDOWS
#include <windows.h>
#endif

#include <MTTypes.h>
#include <MTPlatform.h>

#include <stdint.h>

#include "Brofiler.h"


// MEMORY //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define BRO_CACHE_LINE_SIZE 64
#define BRO_ALIGN(N) __declspec( align( N ) )
#define BRO_ALIGN_CACHE BRO_ALIGN(BRO_CACHE_LINE_SIZE)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if MT_PLATFORM_WINDOWS
#define IS_DEBUG_PRESENT ::IsDebuggerPresent() == TRUE
#endif

#define BRO_DEBUG_BREAK if (IS_DEBUG_PRESENT) { __debugbreak(); }

#ifdef _DEBUG
	#define BRO_ASSERT(arg, description) if (!(arg)) { BRO_DEBUG_BREAK; }
	#define BRO_VERIFY(arg, description, operation) if (!(arg)) { BRO_DEBUG_BREAK; operation; }
	#define BRO_FAILED(description) { BRO_DEBUG_BREAK; }
#else
	#define BRO_ASSERT(arg, description)
	#define BRO_VERIFY(arg, description, operation)
	#define BRO_FAILED(description)
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// OVERRIDE keyword warning fix ////////////////////////////////////////////////////////////////////////////////////////////////
#if _MSC_VER >= 1600 // >= VS 2010 (VC10)
	#pragma warning (disable: 4481) //http://msdn.microsoft.com/en-us/library/ms173703.aspx
#else
	#define override
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
