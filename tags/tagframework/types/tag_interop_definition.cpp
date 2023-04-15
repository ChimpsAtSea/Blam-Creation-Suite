#include "tagframework-private-pch.h"

blofeld::s_tag_interop_definition::s_tag_interop_definition(
	const char* name, 
	const char* symbol_name, 
	const char* filename,
	int line, 
	const s_tag_struct_definition& struct_definition,
			s_tag_persistent_identifier persistent_identifier) :
	name(name),
	symbol_name(symbol_name),
	filename(filename),
	line(line),
	struct_definition(struct_definition),
	persistent_identifier(persistent_identifier)
{

}
