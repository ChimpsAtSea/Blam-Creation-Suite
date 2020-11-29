#include "tagdefinitions-private-pch.h"

blofeld::s_tag_block_definition::s_tag_block_definition(
	const char* const name,
	const char* const display_name,
	const char* const filename,
	int32_t const line,
	t_max_count_func* max_count,
	const char* const max_count_string,
	const s_tag_struct_definition& struct_definition
) :
	name(name),
	display_name(display_name),
	filename(filename),
	line(line),
	max_count(max_count),
	max_count_string(max_count_string),
	struct_definition(struct_definition),
	symbol(c_runtime_symbols::runtime().get_public_symbol_by_virtual_address(this))
{

}
