#include "runtimedefinitions-private-pch.h"

c_runtime_string_list_definition::c_runtime_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_string_list_definition(_runtime_tag_definitions),
	original_string_list_definition(nullptr),
	original_tag_persist_string_list(nullptr),
	name(),
	symbol_name(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_string_list_definition::c_runtime_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_string_list_definition const& source) :
	c_blamtoozle_string_list_definition(_runtime_tag_definitions),
	original_string_list_definition(source.original_string_list_definition),
	original_tag_persist_string_list(source.original_tag_persist_string_list),
	name(source.name),
	symbol_name(source.symbol_name),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	for (std::string const& option : source.options)
	{
		options.emplace_back(option);
	}
}

c_runtime_string_list_definition::c_runtime_string_list_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions, 
	s_engine_platform_build engine_platform_build,
	const blofeld::s_string_list_definition& string_list_definition) :
	c_blamtoozle_string_list_definition(_runtime_tag_definitions),
	original_string_list_definition(&string_list_definition),
	original_tag_persist_string_list(nullptr),
	name(string_list_definition.name),
	symbol_name(string_list_definition.symbol_name),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	unsigned int string_count = string_list_definition.get_count(engine_platform_build);
	for (unsigned int string_index = 0; string_index < string_count; string_index++)
	{
		const char* string = string_list_definition.get_string(engine_platform_build, string_index);
		options.emplace_back(string);
	}
}

c_runtime_string_list_definition::c_runtime_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_string_list const& tag_persist_string_list) :
	c_blamtoozle_string_list_definition(_runtime_tag_definitions),
	original_string_list_definition(nullptr),
	original_tag_persist_string_list(&tag_persist_string_list),
	name(),
	symbol_name(),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	const char* struct_name = tag_file_reader.get_string_by_string_character_index(tag_persist_string_list.string_character_index);
	name = struct_name;
	symbol_name = struct_name;

	_runtime_tag_definitions.format_code_symbol_name(symbol_name);

	unsigned int string_list_count = tag_persist_string_list.string_offset_count;
	for (unsigned int string_list_index = 0; string_list_index < string_list_count; string_list_index++)
	{
		unsigned int string_list_offset = tag_persist_string_list.string_offset_start_index + string_list_index;
		const char* string = tag_file_reader.get_string_by_string_offset_index(string_list_offset);
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

