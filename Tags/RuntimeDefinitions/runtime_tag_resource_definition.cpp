#include "runtimedefinitions-private-pch.h"

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_resource_definition(_runtime_tag_definitions),
	original_tag_resource_definition(nullptr),
	original_tag_persist_resource_definition(nullptr),
	name(),
	symbol_name(),
	struct_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_resource_definition const& source) :
	c_blamtoozle_tag_resource_definition(_runtime_tag_definitions),
	original_tag_resource_definition(source.original_tag_resource_definition),
	original_tag_persist_resource_definition(nullptr),
	name(source.name),
	symbol_name(source.symbol_name),
	struct_definition(source.struct_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	s_engine_platform_build engine_platform_build,
	const blofeld::s_tag_resource_definition& tag_resource_definition) :
	c_blamtoozle_tag_resource_definition(_runtime_tag_definitions),
	original_tag_resource_definition(&tag_resource_definition),
	original_tag_persist_resource_definition(nullptr),
	name(tag_resource_definition.name),
	symbol_name(tag_resource_definition.symbol_name),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(engine_platform_build, tag_resource_definition.struct_definition)),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_resource_definition const& tag_persist_resource_definition) :
	c_blamtoozle_tag_resource_definition(_runtime_tag_definitions),
	original_tag_resource_definition(nullptr),
	original_tag_persist_resource_definition(&tag_persist_resource_definition),
	name(),
	symbol_name(),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_file_reader, tag_file_reader.get_struct_definition_by_index(tag_persist_resource_definition.structure_entry_index))),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	const char* resource_name = tag_file_reader.get_string_by_string_character_index(tag_persist_resource_definition.string_character_index);
	name = resource_name;
	symbol_name = resource_name;

	_runtime_tag_definitions.format_code_symbol_name(symbol_name);
}

c_runtime_tag_resource_definition::~c_runtime_tag_resource_definition()
{

}

const char* c_runtime_tag_resource_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_resource_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

c_blamtoozle_tag_struct_definition& c_runtime_tag_resource_definition::get_struct_definition()
{
	if (struct_definition == nullptr)
	{
		console_write_line("FATAL: Block '%s' has no struct definition", name.c_str());
		throw BCS_E_FATAL;
	}
	return *struct_definition;
}
