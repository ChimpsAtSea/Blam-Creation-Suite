#pragma once

enum BCS_RESULT
{
	BCS_E_FATAL = -8,
	BCS_E_OUT_OF_RANGE = -7,
	BCS_E_NOT_FOUND = -6,
	BCS_E_UNSUPPORTED = -5,
	BCS_E_NOT_IMPLEMENTED = -4,
	BCS_E_UNEXPECTED = -3,
	BCS_E_INVALID_ARGUMENT = -2,
	BCS_E_FAIL = -1,
	BCS_S_OK = 0,
	BCS_S_GOOD_THING = 1,
};

#define BCS_VALIDATE_ARGUMENT_THROW(expression) \
	if(!(expression)) \
	{ \
		c_console::write_line("BCSAPI> %s '" #expression "'", __func__); \
		throw(BCS_E_INVALID_ARGUMENT); \
	}

#define BCS_VALIDATE_ARGUMENT(expression) \
	if(!(expression)) \
	{ \
		c_console::write_line("BCSAPI> %s '" #expression "'", __func__); \
		return BCS_E_INVALID_ARGUMENT; \
	}

#define IS_INVALID_BOOLEAN(value) (static_cast<unsigned __int8>(value) > 1ui8)
#define IS_VALID_BOOLEAN(value) (static_cast<unsigned __int8>(value) <= 1ui8)

#define BCS_CHAR_TO_WIDECHAR_STACK(char_buffer_name, widechar_buffer_name) \
	wchar_t* widechar_buffer_name; \
	{ \
		size_t __buffer_length = strlen(filepath); \
		widechar_buffer_name = new(alloca(sizeof(wchar_t) * (__buffer_length + 1))) wchar_t[__buffer_length]; \
		mbstowcs(widechar_buffer_name, filepath, __buffer_length + 1); \
	}

#define BCS_FAILED(result) ((result) < 0)
#define BCS_SUCCEEDED(result) ((result) >= 0)

#ifndef _DEBUG

#define ASSERT(expression, ...) do { if(!(bool)(expression)) { FATAL_ERROR(_CRT_WIDE( #expression ), ##__VA_ARGS__); } } while(false)

#if !defined(_DEBUG) && defined(UWP_PLATFORM)
#define FATAL_ERROR(reason, ...) throw
#define DEBUG_FATAL_ERROR()
#else
void BCSAPI __fatal_error_internal(const wchar_t* reason, const wchar_t* filepath, unsigned int line, ...);
#define FATAL_ERROR_NO_THROW(reason, ...) __fatal_error_internal(reason, _CRT_WIDE(__FILE__), (unsigned)(__LINE__), ##__VA_ARGS__)
#define FATAL_ERROR(reason, ...) (FATAL_ERROR_NO_THROW(reason, ##__VA_ARGS__), throw)
#define DEBUG_FATAL_ERROR(reason, ...) do { if (IsDebuggerPresent()) { __fatal_error_internal(reason, _CRT_WIDE(__FILE__), (unsigned)(__LINE__), ##__VA_ARGS__); } } while(false); throw
#endif

#else

_ACRTIMP void __cdecl _wassert(_In_z_ wchar_t const* _Message, _In_z_ wchar_t const* _File, _In_ unsigned _Line);

#define ASSERT(statement) \
						do  \
						{  \
							if(!(statement)) \
							{ \
								if (IsDebuggerPresent()) \
								{ \
									OutputDebugStringW(L"" __FILE__ "(" STRINGIFY(__LINE__) "): assert " #statement "\n"); \
									__debugbreak(); \
								} \
								else \
								{ \
									_wassert(L"" __FILE__ "(" STRINGIFY(__LINE__) "): assert " #statement, _CRT_WIDE(__FILE__), __LINE__); \
								} \
							} \
						} while(false)

#define FATAL_ERROR(reason, ...) \
						do  \
						{  \
							if (IsDebuggerPresent()) \
							{ \
								OutputDebugStringW(L"" __FILE__ "(" STRINGIFY(__LINE__) "): fatal " reason "\n"); \
								__debugbreak(); \
							} \
							else \
							{ \
								_wassert(L"" __FILE__ "(" STRINGIFY(__LINE__) "): fatal " reason, _CRT_WIDE(__FILE__), __LINE__); \
							} \
						} while(false)

#define FATAL_ERROR_NO_THROW FATAL_ERROR

#define DEBUG_FATAL_ERROR(reason, ...) \
						do  \
						{  \
							if (IsDebuggerPresent()) \
							{ \
								OutputDebugStringW(L"" __FILE__ "(" STRINGIFY(__LINE__) "): fatal " reason "\n"); \
								__debugbreak(); \
							} \
						} while(false)


//#define ASSERT(expression, ...) \
//do \
//{ \
//	if (!(bool)(expression)) \
//	{ \
//		const wchar_t* __fatal_error_string_wide = L"" #expression L" | " ##__VA_ARGS__; \
//		printf("%s(%i): error FATAL: %S", __FILE__, __LINE__, __fatal_error_string_wide); \
//		if (IsDebuggerPresent()) \
//		{ \
//			_wassert(__fatal_error_string_wide, _CRT_WIDE(__FILE__), __LINE__); \
//		} \
//		else \
//		{ \
//			int message_box_result = MessageBoxW(NULL, __fatal_error_string_wide, L"Fatal Error", MB_ABORTRETRYIGNORE | MB_ICONERROR); \
//			if (message_box_result != IDIGNORE) \
//			{ \
//				exit(1); \
//			} \
//		} \
//	} \
//} while (false)


#endif


#define ASSERT_NO_THROW(expression, ...) do { if(!(bool)(expression)) { FATAL_ERROR_NO_THROW(_CRT_WIDE(STRINGIFY(expression)), ##__VA_ARGS__); } } while(false)

#ifdef _DEBUG
#define DEBUG_ASSERT ASSERT
#else
#define DEBUG_ASSERT(...) do {} while(false)
#endif

#define REFERENCE_ASSERT(reference) ASSERT((&reference) != nullptr)
