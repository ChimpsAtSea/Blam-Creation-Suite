#include "definitiontweaker-private-pch.h"

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_block_definition(_runtime_tag_definitions),
	original_tag_block_definition(),
	pretty_name(),
	name(),
	symbol_name(),
	max_count(),
	max_count_string(),
	struct_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_block_definition const& source) :
	c_blamtoozle_tag_block_definition(_runtime_tag_definitions),
	original_tag_block_definition(source.original_tag_block_definition),
	pretty_name(source.pretty_name),
	name(source.name),
	symbol_name(source.symbol_name),
	max_count(source.max_count),
	max_count_string(source.max_count_string),
	struct_definition(source.struct_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_block_definition& tag_block_definition) :
	c_blamtoozle_tag_block_definition(_runtime_tag_definitions),
	original_tag_block_definition(&tag_block_definition),
	pretty_name(tag_block_definition.pretty_name),
	name(tag_block_definition.name),
	symbol_name(tag_block_definition.symbol_name),
	max_count(tag_block_definition.max_count(_runtime_tag_definitions.engine_platform_build)),
	max_count_string(tag_block_definition.max_count_string),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_block_definition.struct_definition)),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

const char* c_runtime_tag_block_definition::get_pretty_name()
{
	return pretty_name.c_str();
}

const char* c_runtime_tag_block_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_block_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

uint32_t c_runtime_tag_block_definition::get_max_count()
{
	return max_count;
}

const char* c_runtime_tag_block_definition::get_max_count_string()
{
	return max_count_string.c_str();
}

c_blamtoozle_tag_struct_definition& c_runtime_tag_block_definition::get_struct_definition()
{
	if (struct_definition == nullptr)
	{
		console_write_line("FATAL: Block '%s' has no struct definition", name.c_str());
		throw BCS_E_FATAL;
	}
	return *struct_definition;
}
