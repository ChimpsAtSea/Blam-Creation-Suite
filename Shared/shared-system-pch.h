#pragma once

#ifndef _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING //#TODO: Replace with WideCharToMultiByte and MultiByteToWideChar
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef WIN32_MEAN_AND_LEAN
#define WIN32_MEAN_AND_LEAN
#endif

#include "FatalError.h"

#define VectorEraseByValueHelper(vector, value) vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());

#define StaticClassSizeCheck(TYPE) static_assert(sizeof(TYPE) == 1, "Static classes shouldn't contain any data");

#define STRINGIFY(s) __STRINGIFY(s)
#define __STRINGIFY(s) #s

#define CHECK_STRUCTURE_SIZE(type, size) \
static constexpr size_t k##type = sizeof(type);\
static_assert(k##type == size, STRINGIFY(type) " is incorrect size");\

#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
using namespace tbb;

#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <tmmintrin.h>
#include <smmintrin.h>
#include <nmmintrin.h>
//#include <ammintrin.h>
//#include <wmmintrin.h>
//#include <immintrin.h>

#define __int128 __m128

#include <windows.h>
#include <hidusage.h>
#include <objidl.h>
#include <gdiplus.h>
#include <sqltypes.h>
#include <shlwapi.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <D3Dcompiler.h>
#include <dxgi.h>
#include <dxgi1_5.h>
#include <d3d11.h>
#include <d3d11_4.h>
#include <Xinput.h>
#include <DirectXMath.h>

#include <detours.h>

#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <intrin.h>
#include <immintrin.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <atomic>
#include <functional>
#include <algorithm>
#include <filesystem>
#include <psapi.h>
#include <map>
#include <locale>
#include <cwctype>
#include <codecvt>
#include <queue>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#else
#define UWP_PLATFORM
#endif

#include <imgui\imgui.h>
#include <imgui\imgui_impl_win32.h>
#include <imgui\imgui_impl_dx11.h>

#include "hexrays_defs.h" // #TODO: Integrate this into a global types definition list

#define COMBINE1(X,Y) X##Y
#define COMBINE(X,Y) COMBINE1(X,Y)
#define RUNONCE(...) do { \
static bool COMBINE(__runonceflag_, __LINE__) = false; \
if (COMBINE(__runonceflag_, __LINE__) == false) \
{ \
	__VA_ARGS__; \
	COMBINE(__runonceflag_, __LINE__) = true; \
} } while(0)

template<class T, std::size_t... N>
constexpr T bswap_impl(T i, std::index_sequence<N...>) { return ((((i >> (N * CHAR_BIT))& (T)(unsigned char)(-1)) << ((sizeof(T) - 1 - N) * CHAR_BIT)) | ...); };
template<class T, class U = typename std::make_unsigned<T>::type>
constexpr U bswap(T i) { return bswap_impl<U>(i, std::make_index_sequence<sizeof(T)>{}); }
#define bswap_auto_endian(littleEndian, i) (littleEndian ? i : bswap(i))

template<typename T>
constexpr decltype(auto) underlying_cast(T value)
{
	using ResultType = __underlying_type(T); // supported on most main compilers
	return static_cast<ResultType>(value);
}

#define underlying(type) __underlying_type(type)
#define unused(expression) do { (void)(expression); } while (false)
#define auto auto_is_banned

#ifdef assert
#undef assert
#define assert assert_is_banned_use_ASSERT_and_DEBUG_ASSERT
#endif

#ifdef _WIN64
#define static_assert_64 static_assert
#define static_assert_32(...)
#else
#define static_assert_64(...)
#define static_assert_32 static_assert
#endif

#include "!Resources/ResourcesManager.h"
