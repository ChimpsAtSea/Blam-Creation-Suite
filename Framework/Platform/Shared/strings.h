#pragma once

enum e_string_compare_flags
{
	_string_compare_default = 0,
	_string_compare_case_insensitive = 1 << 0,
	_string_compare_allow_null = 1 << 1
};

BCS_DEBUG_API BCS_RESULT string_compare(const char* string_a, const char* string_b, e_string_compare_flags flags = _string_compare_default);
BCS_DEBUG_API BCS_RESULT string_compare(const wchar_t* string_a, const wchar_t* string_b, e_string_compare_flags flags = _string_compare_default);
BCS_DEBUG_API BCS_RESULT string_compare(const char* string_a, const wchar_t* string_b, e_string_compare_flags flags = _string_compare_default);
BCS_DEBUG_API BCS_RESULT string_compare(const wchar_t* string_a, const char* string_b, e_string_compare_flags flags = _string_compare_default);
BCS_DEBUG_API void* memmem(const void* haystack, size_t haystack_length, const void* const needle, const size_t needle_length);
BCS_DEBUG_API char* ltrim(char* string);
BCS_DEBUG_API char* rtrim(char* string);
BCS_DEBUG_API char* trim(char* string);
