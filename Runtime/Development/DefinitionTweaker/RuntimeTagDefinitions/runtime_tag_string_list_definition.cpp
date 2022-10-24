#include "definitiontweaker-private-pch.h"

c_runtime_tag_string_list_definition::c_runtime_tag_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	strings(),
	original_string_list_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_string_list_definition::c_runtime_tag_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_string_list_definition const& source) :
	strings(source.strings),
	original_string_list_definition(source.original_string_list_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_string_list_definition::c_runtime_tag_string_list_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_string_list_definition& string_list_definition) :
	strings(),
	original_string_list_definition(&string_list_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	unsigned int string_count = string_list_definition.get_count(runtime_tag_definitions.engine_platform_build);
	for (unsigned int string_index = 0; string_index < string_count; string_index++)
	{
		const char* string = string_list_definition.get_string(runtime_tag_definitions.engine_platform_build, string_index);
		strings.push_back(string);
	}
}
