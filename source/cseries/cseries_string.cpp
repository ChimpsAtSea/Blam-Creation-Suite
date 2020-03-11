#include <cseries/cseries_asserts.h>
#include <cseries/cseries_string.h>

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* ---------- code */

bool ascii_islower(int c)
{
	return islower(c) != 0;
}

bool ascii_isupper(int c)
{
	return isupper(c) != 0;
}

bool ascii_isdigit(int c)
{
	return isdigit(c) != 0;
}

bool ascii_isalnum(int c)
{
	return isalnum(c) != 0;
}

bool ascii_isspace(int c)
{
	return isspace(c) != 0;
}

int ascii_tolower(int c)
{
	return tolower(c);
}

int ascii_toupper(int c)
{
	return toupper(c);
}

char *csstrchr(char *string, int c)
{
	assert(string);
	return strchr(string, c);
}

int csstrcmp(char const *s1, char const *s2)
{
	assert(s1 && s2);
	return strcmp(s1, s2);
}

int csstricmp(char *s1, char *s2)
{
	assert(s1 && s2);
	return _stricmp(s1, s2);
}

unsigned int csstrlen(char const *string)
{
	assert(string);
	return (unsigned int)strlen(string);
}

int csstrncmp(char const *s1, char const *s2, unsigned int max_length)
{
	assert(s1 && s2);
	return strncmp(s1, s2, max_length);
}

int csstrnicmp(char *s1, char *s2, unsigned int max_length)
{
	assert(s1 && s2);
	return _strnicmp(s1, s2, max_length);
}

unsigned int csstrnlen(char const *string, unsigned int max_length)
{
	assert(string);
	return (unsigned int)strnlen_s(string, max_length);
}

char *csstrnlwr(char *string, unsigned int max_length)
{
	assert(string);
	assert(max_length <= k_maximum_string_size);

	for (unsigned int remaining = max_length;
		(remaining > 0) && (string[remaining - 1] != '\0');
		remaining--)
	{
		string[remaining - 1] = static_cast<char>(ascii_tolower(string[remaining - 1]));
	}

	return string;
}

char *csstrnupr(char *string, unsigned int max_length)
{
	assert(string);
	assert(max_length <= k_maximum_string_size);

	for (unsigned int remaining = max_length;
		(remaining > 0) && (string[remaining - 1] != '\0');
		remaining--)
	{
		string[remaining - 1] = static_cast<char>(ascii_toupper(string[remaining - 1]));
	}

	return string;
}

char *csstrnzcat(char *s1, char *s2, unsigned int s1_size)
{
	assert(s1 && s2);
	assert(strncat_s(s1, s1_size, s2, strlen(s2)) == 0);
	return s1;
}

char *csstrnzcpy(char *s1, char const *s2, unsigned int s1_size)
{
	assert(s1 && s2);
	assert(strncpy_s(s1, s1_size, s2, strlen(s2)) == 0);
	return s1;
}

char *csstrnzncat(char *s1, char *s2, unsigned int s1_size, unsigned int count)
{
	assert(s1 && s2);
	assert(strncat_s(s1, s1_size, s2, count) == 0);
	return s1;
}

char *csstrpbrk(char *string, char const *control)
{
	assert(string && control);
	return strpbrk(string, control);
}

char *csstrrchr(char *string, int c)
{
	assert(string);
	return strrchr(string, c);
}

char *csstrstr(char *string, char const *substring)
{
	assert(string && substring);
	return strstr(string, substring);
}

char *csstrtok(char *string, char const *delimiter)
{
	assert(string || delimiter);
	return strtok(string, delimiter);
}

char *csnzprintf(
	char *buffer,
	unsigned int size,
	char const *format,
	...)
{
	va_list args;
	va_start(args, format);

	assert(cvsnzprintf(buffer, size, format, args) != 0);

	va_end(args);

	return buffer;
}

long cvsnzprintf(
	char *buffer,
	unsigned int size,
	char const *format,
	void *args)
{
	assert(buffer);
	assert(format);
	assert(size > 0 && size <= k_maximum_string_size);

	return vsnprintf_s(buffer, size, size - 1, format, (va_list)args);
}
