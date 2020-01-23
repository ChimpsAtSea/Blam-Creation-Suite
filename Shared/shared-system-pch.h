#pragma once

#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING //#TODO: Replace with WideCharToMultiByte and MultiByteToWideChar
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_MEAN_AND_LEAN

#if !defined(_DEBUG) && defined(UWP_PLATFORM)
#define FATAL_ERROR(reason, ...) throw
#else
#define FATAL_ERROR(reason, ...) _wassert(_CRT_WIDE(reason), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)); throw
#endif

#define WriteLineVerbose(str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
printf(str, ##__VA_ARGS__); \
printf("\n")

#define WriteVerbose(str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
printf(str, ##__VA_ARGS__)

#define WriteColoredLineVerbose(color, str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  \
printf(str, ##__VA_ARGS__); printf("\n"); \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)

#define WriteColoredVerbose(color, str, ...)  \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  \
printf(str, ##__VA_ARGS__); \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)

#define WriteColoredPrefixVerbose(color, prefix, str, ...) \
WriteColoredVerbose(color, "%s ", prefix); \
WriteLineVerbose(str, ##__VA_ARGS__)

#define vector_erase_by_value_helper(vector, value) vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());

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

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#else
#define UWP_PLATFORM
#endif

#include <imgui\imgui.h>
#include <imgui\imgui_impl_win32.h>
#include <imgui\imgui_impl_dx11.h>

#if !defined(_DEBUG) && defined(UWP_PLATFORM)
#define FATAL_ERROR(reason, ...) throw
#else
#define FATAL_ERROR(reason, ...) _wassert(_CRT_WIDE(reason), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)); throw
#endif

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

#define auto auto_is_banned


