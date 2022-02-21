#pragma once

#ifdef __RESHARPER__
#define __INTELLISENSE__
#endif

#ifdef __INTELLISENSE__
#ifndef HIDDEN_CODE
#define HIDDEN_CODE
#endif
#endif

#ifdef HIDDEN_CODE
#define HIDDEN(...)
#else
#define HIDDEN(...) __VA_ARGS__
#endif

#define COMBINE1(x,y) x##y
#define COMBINE(x,y) COMBINE1(x,y)
#define CONCAT(x, y) x##y
#define STRINGIFY(s) __STRINGIFY(s)
#define __STRINGIFY(s) #s

//#define static_assert(...) static_assert(__VA_ARGS__, STRINGIFY(__VA_ARGS__))

#ifdef _WIN64
#define static_assert_64 static_assert
#define static_assert_32(...)
#else
#define static_assert_64(...)
#define static_assert_32 static_assert
#endif

#define RUNONCE(...) do { \
static bool COMBINE(__runonceflag_, __LINE__) = false; \
if (COMBINE(__runonceflag_, __LINE__) == false) \
{ \
	__VA_ARGS__; \
	COMBINE(__runonceflag_, __LINE__) = true; \
} } while(0)

#ifdef _DEBUG
#define DEBUG_ONLY(...) __VA_ARGS__
#define NDEBUG_ONLY(...)
#else
#define NDEBUG_ONLY(...) __VA_ARGS__
#define DEBUG_ONLY(...)
#endif

#ifndef offsetof
#ifdef __cplusplus
#define offsetof(s,m) ((::size_t)&reinterpret_cast<char const volatile&>((((s*)0)->m)))
#else
#define offsetof(s,m) ((size_t)&(((s*)0)->m))
#endif
#endif

#define DEG2RAD 0.01745329251f
#define RAD2DEG 57.2957795131f
#define ALIGN(n, b) ( (b)==0 ? (n) : ( ((n)+(b)-1) - (((n)-1)%(b)) ) )

#define __clamp(value, min_value, max_value) (value > (max_value) ? (max_value) : (((value) < (min_value) ? (min_value) : (value))))
#ifndef _countof
#define _countof(arr) (sizeof(arr) / sizeof(arr[0]))
#endif

#define lambda(...) [](__VA_ARGS__)

#define underlying(type) __underlying_type(type)
template<typename T>
constexpr decltype(auto) underlying_cast(T value)
{
	using ResultType = __underlying_type(T); // supported on most main compilers
	return static_cast<ResultType>(value);
}

#define BCS_WIDECHAR_TO_CHAR_STACK(widechar_buffer_name, char_buffer_name) \
	char* char_buffer_name = nullptr; \
	if(widechar_buffer_name) \
	{ \
		size_t __buffer_length = wcslen(widechar_buffer_name) + 1; \
		char_buffer_name = static_cast<char*>(alloca(sizeof(char) * (__buffer_length))); \
		wcstombs(char_buffer_name, widechar_buffer_name, __buffer_length); \
	}

#define BCS_WIDECHAR_TO_CHAR_HEAP(widechar_buffer_name, char_buffer_name) \
	char* char_buffer_name = nullptr; \
	if(widechar_buffer_name) \
	{ \
		size_t __buffer_length = wcslen(widechar_buffer_name) + 1; \
		char_buffer_name = static_cast<char*>(tracked_malloc(platform_tracked_memory, sizeof(char) * (__buffer_length))); \
		wcstombs(char_buffer_name, widechar_buffer_name, __buffer_length); \
	}

#define BCS_CHAR_TO_WIDECHAR_STACK(char_buffer_name, widechar_buffer_name) \
	wchar_t* widechar_buffer_name = nullptr; \
	if(char_buffer_name) \
	{ \
		size_t __buffer_length = strlen(char_buffer_name) + 1; \
		widechar_buffer_name = static_cast<wchar_t*>(alloca(sizeof(wchar_t) * (__buffer_length))); \
		mbstowcs(widechar_buffer_name, char_buffer_name, __buffer_length); \
	}

#define BCS_CHAR_TO_WIDECHAR_HEAP(char_buffer_name, widechar_buffer_name) \
	wchar_t* widechar_buffer_name = nullptr; \
	if(char_buffer_name) \
	{ \
		size_t __buffer_length = strlen(char_buffer_name) + 1; \
		widechar_buffer_name = static_cast<wchar_t*>(tracked_malloc(platform_tracked_memory, sizeof(wchar_t) * (__buffer_length))); \
		mbstowcs(widechar_buffer_name, char_buffer_name, __buffer_length); \
	}

#ifdef assert
#undef assert
#endif
#define assert assert_is_banned_use_ASSERT_and_DEBUG_ASSERT
