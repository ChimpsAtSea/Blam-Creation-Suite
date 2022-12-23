#include "runtimedefinitions-private-pch.h"

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_block_definition(_runtime_tag_definitions),
	original_tag_block_definition(nullptr),
	original_tag_persist_block_definition(nullptr),
	pretty_name(),
	name(),
	symbol_name(),
	max_count(65536),
	max_count_string("65536"),
	struct_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_block_definition const& source) :
	c_blamtoozle_tag_block_definition(_runtime_tag_definitions),
	original_tag_block_definition(source.original_tag_block_definition),
	original_tag_persist_block_definition(source.original_tag_persist_block_definition),
	pretty_name(source.pretty_name),
	name(source.name),
	symbol_name(source.symbol_name),
	max_count(source.max_count),
	max_count_string(source.max_count_string),
	struct_definition(source.struct_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, s_engine_platform_build engine_platform_build, blofeld::s_tag_block_definition const& tag_block_definition) :
	c_blamtoozle_tag_block_definition(_runtime_tag_definitions),
	original_tag_block_definition(&tag_block_definition),
	original_tag_persist_block_definition(nullptr),
	pretty_name(tag_block_definition.pretty_name),
	name(tag_block_definition.name),
	symbol_name(tag_block_definition.symbol_name),
	max_count(tag_block_definition.max_count(engine_platform_build)),
	max_count_string(tag_block_definition.max_count_string),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(engine_platform_build, tag_block_definition.struct_definition)),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_definition::c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_block_definition const& persist_block_definition) :
	c_blamtoozle_tag_block_definition(_runtime_tag_definitions),
	original_tag_block_definition(nullptr),
	original_tag_persist_block_definition(&persist_block_definition),
	pretty_name(),
	name(),
	symbol_name(),
	max_count(persist_block_definition.max_count),
	max_count_string(std::to_string(persist_block_definition.max_count)),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_file_reader, tag_file_reader.get_struct_definition_by_index(persist_block_definition.structure_entry_index))),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	const char* block_name = tag_file_reader.get_string_by_string_character_index(persist_block_definition.string_character_index);
	pretty_name = block_name;
	name = block_name;
	symbol_name = block_name;

	_runtime_tag_definitions.format_code_symbol_name(symbol_name);
}

c_runtime_tag_block_definition::~c_runtime_tag_block_definition()
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
