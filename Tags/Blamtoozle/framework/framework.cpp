#include "blamtoozle-private-pch.h"

#include <TagDefinitions/blamlib_byteswap.inl>

template<> void byteswap_inplace(blofeld::s_tag_persistent_identifier& value)
{
	byteswap_inplace(value.identifier_part_0);
	byteswap_inplace(value.identifier_part_1);
	byteswap_inplace(value.identifier_part_2);
	byteswap_inplace(value.identifier_part_3);
}

void nuke_trailing_extension(char* string, const char* extension)
{
	char* search = __max(string, string + (strlen(string) + 1) - (strlen(extension) + 1));
	if (strcmp(search, extension) == 0)
	{
		*search = 0;
	}
}

void replace_trailing_extension(char* string, const char* extension, const char* replacement)
{
	char* search = __max(string, string + (strlen(string) + 1) - (strlen(extension) + 1));
	if (strcmp(search, extension) == 0)
	{
		strcpy(search, replacement);
	}
}

void cleanup_code_symbol_name(char* buffer)
{
	replace_trailing_extension(buffer, "_struct_struct_definition", "_struct_definition");
	nuke_trailing_extension(buffer, "_struct_definition");

	if (strstr(buffer, "g_") == buffer)
	{
		memmove(buffer, buffer + 2, strlen(buffer + 2) + 1);
	}

	if (strstr(buffer, "s_") != buffer)
	{

		memmove(buffer + 2, buffer, strlen(buffer) + 1);
		strncpy(buffer, "s_", 2);

	}



	while (strstr(buffer + 1, "__") == buffer + 1)
	{

		memmove(buffer + 1, buffer + 2, strlen(buffer + 1) + 1);

	}
}
