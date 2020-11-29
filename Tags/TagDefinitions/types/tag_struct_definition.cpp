#include "tagdefinitions-private-pch.h"

blofeld::s_tag_struct_definition::s_tag_struct_definition(
	const char* const name,
	const char* const display_name,
	const char* const variable_name,
	const char* const filename,
	int32_t const line,
	GUID const guid,
	const s_tag_field* const fields
) :
	name(name),
	display_name(display_name),
	variable_name(variable_name),
	filename(filename),
	line(line),
	guid(guid),
	fields(fields),
	symbol(c_runtime_symbols::runtime().get_public_symbol_by_virtual_address(this))
{

}