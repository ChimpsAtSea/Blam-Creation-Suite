/*
TAG.CPP
Monday, February 24, 2020 9:17:50 AM
*/

#include <assert.h>
#include <stddef.h>
#include <string.h>

#include <datatypes/tag.h>

/* ---------- code */

char *tag_to_string(tag value, char (&string)[4])
{
    for (size_t i = 0; i < sizeof(value); i++)
    {
        string[3 - i] = static_cast<char>(value >> (i * 8));
    }

    return string;
}

tag string_to_tag(
    const char *string)
{
    assert(string);
    assert(strlen(string) == sizeof(tag));

    tag result = 0;

    for (size_t i = 0; i < sizeof(tag); i++)
    {
        result |= static_cast<tag>(string[3 - i]) << (i * 8);
    }

    return result;
}
