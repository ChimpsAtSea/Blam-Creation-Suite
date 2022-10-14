#pragma once

#ifdef _DEBUG
BCS_DEBUG_API extern void(*__bcs_assertfunc)(wchar_t const* message, wchar_t const* file, unsigned line);
BCS_DEBUG_API extern bool(*__bcs_is_debugger_present)();
BCS_DEBUG_API extern void(*__bcs_write_debug_string)(wchar_t const* message);
#else
#define __bcs_assertfunc(...)
#define __bcs_is_debugger_present(...) false
#define __bcs_write_debug_string(...) false
#endif

#define ASSERT(statement, ...) \
						do  \
						{  \
							if(!(statement)) \
							{ \
								if (__bcs_is_debugger_present()) \
								{ \
									__bcs_write_debug_string(L"" __FILE__ "(" STRINGIFY(__LINE__) "): assert " #statement "\n"); \
									__debugbreak(); \
								} \
								else \
								{ \
									__bcs_assertfunc(L"" __FILE__ "(" STRINGIFY(__LINE__) "): assert " #statement, _CRT_WIDE(__FILE__), __LINE__); \
								} \
							} \
						} while(false)

#define ASSERT_ONCE(statement, ...) \
						do  \
						{  \
							static bool __first_run = true; \
							if(__first_run && !(statement)) \
							{ \
								__first_run = false; \
								if (__bcs_is_debugger_present()) \
								{ \
									__bcs_write_debug_string(L"" __FILE__ "(" STRINGIFY(__LINE__) "): assert " #statement "\n"); \
									__debugbreak(); \
								} \
								else \
								{ \
									__bcs_assertfunc(L"" __FILE__ "(" STRINGIFY(__LINE__) "): assert " #statement, _CRT_WIDE(__FILE__), __LINE__); \
								} \
							} \
						} while(false)

#define FATAL_ERROR_NO_THROW(reason, ...) \
						do  \
						{  \
							if (__bcs_is_debugger_present()) \
							{ \
								__bcs_write_debug_string(L"" __FILE__ "(" STRINGIFY(__LINE__) "): fatal " reason "\n"); \
								__debugbreak(); \
							} \
							else \
							{ \
								__bcs_assertfunc(L"" __FILE__ "(" STRINGIFY(__LINE__) "): fatal " reason, _CRT_WIDE(__FILE__), __LINE__); \
							} \
						} while(false)

#define FATAL_ERROR(reason, ...) \
						do  \
						{  \
							if (__bcs_is_debugger_present()) \
							{ \
								__bcs_write_debug_string(L"" __FILE__ "(" STRINGIFY(__LINE__) "): fatal " reason "\n"); \
								__debugbreak(); \
							} \
							else \
							{ \
								__bcs_assertfunc(L"" __FILE__ "(" STRINGIFY(__LINE__) "): fatal " reason, _CRT_WIDE(__FILE__), __LINE__); \
							} \
							throw; \
						} while(false)

#define DEBUG_FATAL_ERROR(reason, ...) \
						do  \
						{  \
							if (__bcs_is_debugger_present()) \
							{ \
								__bcs_write_debug_string(L"" __FILE__ "(" STRINGIFY(__LINE__) "): fatal " reason "\n"); \
								__debugbreak(); \
							} \
						} while(false)

#define ASSERT_NO_THROW(expression, ...) do { if(!(bool)(expression)) { FATAL_ERROR_NO_THROW(_CRT_WIDE(STRINGIFY(expression)), ##__VA_ARGS__); } } while(false)

#ifdef _DEBUG
#define DEBUG_ASSERT ASSERT
#else
#define DEBUG_ASSERT(...) do {} while(false)
#endif

#define REFERENCE_ASSERT(reference) ASSERT((&reference) != nullptr)
