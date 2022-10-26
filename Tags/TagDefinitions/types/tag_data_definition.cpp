#include "tagdefinitions-private-pch.h"

using namespace blofeld;

s_tag_data_definition::s_tag_data_definition(
	const char* _name,
	const char* _pretty_name,
	const char* _symbol_name,
	uint32_t _flags,
	uint32_t _maximum_element_count,
	const char* _maximum_element_count_string,
	const char* _filename,
	int32_t const _line,
	uint32_t _alignment_bits) :
	name(_name),
	pretty_name(_pretty_name),
	symbol_name(_symbol_name),
	flags(_flags),
	alignment_bits(_alignment_bits),
	maximum_element_count(_maximum_element_count),
	maximum_element_count_string(_maximum_element_count_string),
	filename(_filename),
	line(_line),
	symbol()
{
	symbol_manager_get_public_symbol_by_pointer(this, symbol);
}
