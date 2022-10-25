#include "tagdefinitions-private-pch.h"

using namespace blofeld;

s_tag_data_definition::s_tag_data_definition(
	const char* name,
	const char* pretty_name,
	const char* symbol_name,
	uint32_t flags,
	uint32_t maximum_size,
	const char* maximum_size_string,
	const char* filename,
	int32_t const line,
	uint32_t alignment_bits) :
	name(name),
	pretty_name(pretty_name),
	symbol_name(symbol_name),
	flags(flags),
	alignment_bits(alignment_bits),
	maximum_size(maximum_size),
	maximum_size_string(maximum_size_string),
	filename(filename),
	line(line),
	symbol()
{
	symbol_manager_get_public_symbol_by_pointer(this, symbol);
}
