#include "runtimedefinitions-private-pch.h"

c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_array_definition(_runtime_tag_definitions),
	original_tag_array_definition(nullptr),
	original_tag_persist_array_definition(nullptr),
	pretty_name(),
	name(),
	symbol_name(),
	element_count(),
	element_count_string(),
	struct_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_array_definition const& source) :
	c_blamtoozle_tag_array_definition(_runtime_tag_definitions),
	original_tag_array_definition(source.original_tag_array_definition),
	original_tag_persist_array_definition(source.original_tag_persist_array_definition),
	pretty_name(source.pretty_name),
	name(source.name),
	symbol_name(source.symbol_name),
	element_count(source.element_count),
	element_count_string(source.element_count_string),
	struct_definition(source.struct_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, s_engine_platform_build engine_platform_build, const blofeld::s_tag_array_definition& tag_array_definition) :
	c_blamtoozle_tag_array_definition(_runtime_tag_definitions),
	original_tag_array_definition(&tag_array_definition),
	original_tag_persist_array_definition(nullptr),
	pretty_name(tag_array_definition.pretty_name),
	name(tag_array_definition.name),
	symbol_name(tag_array_definition.symbol_name),
	element_count(tag_array_definition.element_count(engine_platform_build)),
	element_count_string(tag_array_definition.element_count_string),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(engine_platform_build, tag_array_definition.struct_definition)),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}


c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_array_definition const& tag_persist_array_definition) :
	c_blamtoozle_tag_array_definition(_runtime_tag_definitions),
	original_tag_array_definition(nullptr),
	original_tag_persist_array_definition(nullptr),
	pretty_name(),
	name(),
	symbol_name(),
	element_count(),
	element_count_string(),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_file_reader, tag_file_reader.get_struct_definition_by_index(tag_persist_array_definition.structure_entry_index))),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	const char* array_name = tag_file_reader.get_string_by_string_character_index(tag_persist_array_definition.string_character_index);
	pretty_name = array_name;
	name = array_name;
	symbol_name = array_name;

	_runtime_tag_definitions.format_code_symbol_name(symbol_name);
}

c_runtime_tag_array_definition::~c_runtime_tag_array_definition()
{

}

const char* c_runtime_tag_array_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_array_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

uint32_t c_runtime_tag_array_definition::get_element_count()
{
	return element_count;
}

const char* c_runtime_tag_array_definition::get_element_count_string()
{
	return element_count_string.c_str();
}

c_blamtoozle_tag_struct_definition& c_runtime_tag_array_definition::get_struct_definition()
{
	if (struct_definition == nullptr)
	{
		console_write_line("FATAL: Array '%s' has no struct definition", name.c_str());
		throw BCS_E_FATAL;
	}
	return *struct_definition;
}
