#include "shared-private-pch.h"

void strlower(const char* src, char* dst, size_t length)
{
	memmove(dst, src, length * sizeof(char));
	std::transform(dst, dst + length, dst, [](char c) { return static_cast<char>(std::tolower(c)); });
}

void wcslower(const wchar_t* src, wchar_t* dst, size_t length)
{
	memmove(dst, src, length * sizeof(wchar_t));
	std::transform(dst, dst + length, dst, [](wchar_t c) { return static_cast<char>(std::towlower(c)); });
}

int __cdecl strcmp_ic(char const* _Str1, char const* _Str2)
{
	if (strcmp(_Str1, _Str2) == 0) // skip converting characters
	{
		return 0;
	}

	std::string str1 = _Str1;
	std::string str2 = _Str2;

	strlower(str1.data(), str1.data(), str1.length());
	strlower(str2.data(), str2.data(), str2.length());
	
	int result = strcmp(str1.c_str(), str2.c_str());
	return result;
}

int __cdecl wcscmp_ic(wchar_t const* _Str1, wchar_t const* _Str2)
{
	if (wcscmp(_Str1, _Str2) == 0 && false) // skip converting characters
	{
		return 0;
	}

	std::wstring str1 = _Str1;
	std::wstring str2 = _Str2;

	wcslower(str1.data(), str1.data(), str1.length());
	wcslower(str2.data(), str2.data(), str2.length());

	int result = wcscmp(str1.c_str(), str2.c_str());
	return result;
}
