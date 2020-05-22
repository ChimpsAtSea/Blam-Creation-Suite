#pragma once

// converts char* string to lowercase
void strlower(const char* src, char* dst, size_t length);
// converts wchar_t* string to lowercase
void wcslower(const wchar_t* src, wchar_t* dst, size_t length);

// strcmp with ignore case
int __cdecl strcmp_ic(char const* _Str1, char const* _Str2);
// wcscmp with ignore case
int __cdecl wcscmp_ic(wchar_t const* _Str1, wchar_t const* _Str2);