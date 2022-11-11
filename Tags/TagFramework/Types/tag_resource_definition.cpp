#include "tagframework-private-pch.h"

blofeld::s_tag_resource_definition::s_tag_resource_definition(
	const char* name,
	const char* symbol_name,
	const char* filename,
	int line,
	const s_tag_struct_definition& struct_definition) :
	name(name),
	symbol_name(symbol_name),
	filename(filename),
	line(line),
	struct_definition(struct_definition)
{
	symbol_manager_get_public_symbol_by_pointer(this, symbol);
}
