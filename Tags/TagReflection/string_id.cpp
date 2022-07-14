#include "tagreflection-private-pch.h"

h_string_id::h_string_id() :
	string()
{
}

h_string_id::h_string_id(const char* _string) :
	string()
{
	set_string(_string);
}

h_string_id::~h_string_id()
{
	clear();
}

const char* h_string_id::get_string() const
{
	return string != nullptr ? string : "";
}

void h_string_id::set_string(const char* _string)
{
	clear();

	if (_string)
	{
		string = strdup(_string);
	}
}

void h_string_id::set_string(const char* string_start, const char* string_end)
{
	ptrdiff_t string_length = string_end - string_start;
	ASSERT(string_length >= 0);
	ASSERT(string_length < 256); // use some kind of sensible limit here, may need to be increased

	char* terminated_string = trivial_alloca(char, string_length + 1);
	memcpy(terminated_string, string_start, static_cast<size_t>(string_length));
	terminated_string[string_length]= 0;

	set_string(terminated_string);
}

void h_string_id::clear()
{
	if (string != nullptr)
	{
		untracked_free(string);
		string = nullptr;
	}
}
