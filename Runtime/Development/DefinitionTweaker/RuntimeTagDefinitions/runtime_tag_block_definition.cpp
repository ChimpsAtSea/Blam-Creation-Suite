#include "definitiontweaker-private-pch.h"

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	display_name(),
	name(),
	symbol_name(),
	max_count(),
	max_count_string(),
	struct_definition(),
	original_tag_block_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_block_definition const& source) :
	display_name(source.display_name),
	name(source.name),
	symbol_name(source.symbol_name),
	max_count(source.max_count),
	max_count_string(source.max_count_string),
	struct_definition(source.struct_definition),
	original_tag_block_definition(source.original_tag_block_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_block_definition& tag_block_definition) :
	display_name(tag_block_definition.display_name),
	name(tag_block_definition.name),
	symbol_name(tag_block_definition.symbol_name),
	max_count(tag_block_definition.max_count(_runtime_tag_definitions.engine_platform_build)),
	max_count_string(tag_block_definition.max_count_string),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_block_definition.struct_definition)),
	original_tag_block_definition(&tag_block_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}
