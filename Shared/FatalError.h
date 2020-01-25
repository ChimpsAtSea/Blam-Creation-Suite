#pragma once

#if !defined(_DEBUG) && defined(UWP_PLATFORM)
#define FATAL_ERROR(reason, ...) throw
#define DEBUG_FATAL_ERROR()
#else
void __FatalErrorInternal(const wchar_t* pReason, const wchar_t* pFile, unsigned int line, ...);
#define FATAL_ERROR(reason, ...) __FatalErrorInternal(reason, _CRT_WIDE(__FILE__), (unsigned)(__LINE__), ##__VA_ARGS__)
#define DEBUG_FATAL_ERROR(reason, ...) do { if (IsDebuggerPresent()) { __FatalErrorInternal(reason, _CRT_WIDE(__FILE__), (unsigned)(__LINE__), ##__VA_ARGS__); } } while() 
#endif
