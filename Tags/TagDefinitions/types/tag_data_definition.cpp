#include "tagdefinitions-private-pch.h"

using namespace blofeld;

s_tag_data_definition::s_tag_data_definition(
	const char* name,
	const char* pretty_name,
	unsigned long flags,
	unsigned long maximum_size,
	const char* maximum_size_string,
	const char* filename,
	long const line,
	unsigned long alignment_bits)
	: name(name)
	, pretty_name(pretty_name)
	, flags(flags)
	, alignment_bits(alignment_bits)
	, maximum_size(maximum_size)
	, maximum_size_string(maximum_size_string)
	, filename(filename)
	, line(line)
	, symbol()
{
	symbol_manager_get_public_symbol_by_pointer(this, symbol);
}
