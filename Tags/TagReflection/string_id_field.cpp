#include "tagreflection-private-pch.h"

h_string_id_field::h_string_id_field() :
#if BCS_BUILD_HIGH_LEVEL_VERSION2
	h_field(_high_level_extended_type_string_id),
#else
	h_field(),
#endif
	string()
{
}

h_string_id_field::h_string_id_field(const char* _string) :
#if BCS_BUILD_HIGH_LEVEL_VERSION2
	h_field(_high_level_extended_type_string_id),
#else
	h_field(),
#endif
	string()
{
	set_string(_string);
}

h_string_id_field::h_string_id_field(h_string_id_field const& string_id) :
#if BCS_BUILD_HIGH_LEVEL_VERSION2
	h_field(_high_level_extended_type_string_id),
#else
	h_field(),
#endif
	string()
{
	set_string(string_id.string);
}

h_string_id_field::~h_string_id_field()
{
	clear();
}

const char* h_string_id_field::get_string() const
{
	return string != nullptr ? string : "";
}

void h_string_id_field::set_string(const char* _string)
{
	clear();

	if (_string)
	{
		string = strdup(_string);
	}
}

void h_string_id_field::set_string(const char* string_start, const char* string_end)
{
	ptrdiff_t string_length = string_end - string_start;
	ASSERT(string_length >= 0);
	ASSERT(string_length < 256); // use some kind of sensible limit here, may need to be increased

	char* terminated_string = trivial_alloca(char, string_length + 1);
	memcpy(terminated_string, string_start, static_cast<size_t>(string_length));
	terminated_string[string_length] = 0;

	set_string(terminated_string);
}

void h_string_id_field::clear()
{
	if (string != nullptr)
	{
		untracked_free(string);
		string = nullptr;
	}
}

h_string_id_field& h_string_id_field::operator=(h_string_id_field const& value)
{
	set_string(value.string);
	return *this;
}

h_string_id_field& h_string_id_field::operator=(const char* const& value)
{
	set_string(value);
	return *this;
}

bool h_string_id_field::operator==(h_string_id_field const& value) const
{
	if (string != nullptr && value.string != nullptr)
	{
		return strcmp(string, value.string) == 0;
	}
	return string == value.string;
}

bool h_string_id_field::operator==(const char* const& _value) const
{
	if (string != nullptr && _value != nullptr)
	{
		return strcmp(string, _value) == 0;
	}
	return string == _value;
}

bool h_string_id_field::operator!=(h_string_id_field const& value) const
{
	if (string != nullptr && value.string != nullptr)
	{
		return strcmp(string, value.string) != 0;
	}
	return string != value.string;
}

bool h_string_id_field::operator!=(const char* const& _value) const
{
	if (string != nullptr && _value != nullptr)
	{
		return strcmp(string, _value) != 0;
	}
	return string != _value;
}

#if !BCS_BUILD_HIGH_LEVEL_VERSION2

void const* h_string_id_field::get_data() const
{
	return &string;
}

void* h_string_id_field::get_data()
{
	return &string;
}

#endif
