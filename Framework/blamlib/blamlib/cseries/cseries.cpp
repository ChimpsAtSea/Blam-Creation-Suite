#include <blamlib/cseries/cseries.h>
#include <stddef.h>

/* ---------- code */

char *tag_to_string(
	tag m_value,
	char *string)
{
	blamlib_assert(string);

	for (size_t i = 0; i < sizeof(tag); i++)
		string[3 - i] = static_cast<char>(m_value >> (i * 8));

	string[sizeof(tag)] = '\0';
	return string;
}

tag string_to_tag(
	char const *string)
{
	blamlib_assert(string);
	blamlib_assert(csstrnlen(string, sizeof(tag)) == sizeof(tag));

	tag result = 0;

	for (size_t i = 0; i < sizeof(tag); i++)
		result |= static_cast<tag>(string[3 - i]) << (i * 8);

	return result;
}
