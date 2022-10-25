#include "tagdefinitions-private-pch.h"

blofeld::s_tag_block_definition::s_tag_block_definition(
	const char* const pretty_name,
	const char* const name,
	const char* const symbol_name,
	const char* const filename,
	int32_t const line,
	t_max_count_func* max_count,
	const char* const max_count_string,
	const s_tag_struct_definition& struct_definition) :
	name(name),
	pretty_name(pretty_name),
	symbol_name(symbol_name),
	filename(filename),
	line(line),
	max_count(max_count),
	max_count_string(max_count_string),
	struct_definition(struct_definition),
	symbol()
{
	symbol_manager_get_public_symbol_by_pointer(this, symbol);
}
