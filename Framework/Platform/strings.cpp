#include "platform-private-pch.h"

BCS_RESULT string_compare(const char* string_a, const char* string_b, e_string_compare_flags flags)
{
	if (flags & _string_compare_allow_null)
	{
		if (string_a == nullptr)
		{
			string_a = "";
		}
		if (string_b == nullptr)
		{
			string_b = "";
		}
	}
	BCS_VALIDATE_ARGUMENT(string_a);
	BCS_VALIDATE_ARGUMENT(string_b);

	int strcmp_result = flags & _string_compare_case_insensitive ? _stricmp(string_a, string_b) : strcmp(string_a, string_b);
	if (strcmp_result != 0)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT string_compare(const wchar_t* string_a, const wchar_t* string_b, e_string_compare_flags flags)
{
	if (flags & _string_compare_allow_null)
	{
		if (string_a == nullptr)
		{
			string_a = L"";
		}
		if (string_b == nullptr)
		{
			string_b = L"";
		}
	}
	BCS_VALIDATE_ARGUMENT(string_a);
	BCS_VALIDATE_ARGUMENT(string_b);

	int strcmp_result = flags & _string_compare_case_insensitive ? _wcsicmp(string_a, string_b) : wcscmp(string_a, string_b);
	if (strcmp_result != 0)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT string_compare(const char* string_a, const wchar_t* string_b, e_string_compare_flags flags)
{
	BCS_CHAR_TO_WIDECHAR_STACK(string_a, string_a_wc);
	return string_compare(string_a_wc, string_b, flags);
}

BCS_RESULT string_compare(const wchar_t* string_a, const char* string_b, e_string_compare_flags flags)
{
	BCS_CHAR_TO_WIDECHAR_STACK(string_b, string_b_wc);
	return string_compare(string_a, string_b_wc, flags);
}
