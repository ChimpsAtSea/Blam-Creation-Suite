#include "definitiontweaker-private-pch.h"

c_runtime_string_list_definition::c_runtime_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_string_list_definition(_runtime_tag_definitions),
	name(),
	symbol_name(),
	original_string_list_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_string_list_definition::c_runtime_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_string_list_definition const& source) :
	c_blamtoozle_string_list_definition(_runtime_tag_definitions),
	name(source.name),
	symbol_name(source.symbol_name),
	original_string_list_definition(source.original_string_list_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	for (std::string const& option : source.options)
	{
		options.emplace_back(option);
	}
}

c_runtime_string_list_definition::c_runtime_string_list_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_string_list_definition& string_list_definition) :
	c_blamtoozle_string_list_definition(_runtime_tag_definitions),
	name(string_list_definition.name),
	symbol_name(string_list_definition.symbol_name),
	original_string_list_definition(&string_list_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	unsigned int string_count = string_list_definition.get_count(runtime_tag_definitions.engine_platform_build);
	for (unsigned int string_index = 0; string_index < string_count; string_index++)
	{
		const char* string = string_list_definition.get_string(runtime_tag_definitions.engine_platform_build, string_index);
		options.emplace_back(string);
	}
}

c_runtime_string_list_definition::~c_runtime_string_list_definition()
{

}

const char* c_runtime_string_list_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_string_list_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

const char* c_runtime_string_list_definition::get_file_path()
{
	if (original_string_list_definition)
	{
		return original_string_list_definition->filename;
	}
	return c_blamtoozle_string_list_definition::get_file_path();
}

int32_t c_runtime_string_list_definition::get_line_number()
{
	if (original_string_list_definition)
	{
		return original_string_list_definition->line;
	}
	return c_blamtoozle_string_list_definition::get_line_number();
}

