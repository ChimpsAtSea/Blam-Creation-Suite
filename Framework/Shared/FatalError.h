#pragma once

#if !defined(_DEBUG) && defined(UWP_PLATFORM)
#define FATAL_ERROR(reason, ...) throw
#define DEBUG_FATAL_ERROR()
#else
void __FatalErrorInternal(const wchar_t* pReason, const wchar_t* pFile, unsigned int line, ...);
#define FATAL_ERROR_NO_THROW(reason, ...) __FatalErrorInternal(reason, _CRT_WIDE(__FILE__), (unsigned)(__LINE__), ##__VA_ARGS__)
#define FATAL_ERROR(reason, ...) (FATAL_ERROR_NO_THROW(reason, ##__VA_ARGS__), throw)
#define DEBUG_FATAL_ERROR(reason, ...) do { if (IsDebuggerPresent()) { __FatalErrorInternal(reason, _CRT_WIDE(__FILE__), (unsigned)(__LINE__), ##__VA_ARGS__); } } while(false); throw
#endif

#define ASSERT(expression, ...) do { if(!(bool)(expression)) { FATAL_ERROR(_CRT_WIDE(STRINGIFY(expression)), ##__VA_ARGS__); } } while(false)
#define ASSERT_NO_THROW(expression, ...) do { if(!(bool)(expression)) { FATAL_ERROR_NO_THROW(_CRT_WIDE(STRINGIFY(expression)), ##__VA_ARGS__); } } while(false)

#ifdef _DEBUG
#define DEBUG_ASSERT ASSERT
#else
#define DEBUG_ASSERT(...) do {} while(false)
#endif

#define REFERENCE_ASSERT(reference) ASSERT((&reference) != nullptr)

