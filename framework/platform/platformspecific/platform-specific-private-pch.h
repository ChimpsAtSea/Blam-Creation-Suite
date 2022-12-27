#pragma once

#include "platform-specific-define-platform.h"

#ifdef BCS_WIN32
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <fileapi.h>
#include <ShlObj.h>
#include <strsafe.h>
#include <psapi.h>
#include <dbghelp.h>

#if defined(_M_IX86) || defined(_M_X64)
#include <intrin.h>
#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <tmmintrin.h>
#include <smmintrin.h>
#include <nmmintrin.h>
//#include <ammintrin.h>
//#include <wmmintrin.h>
#include <immintrin.h>
#endif

#define __int128 __m128

#endif
