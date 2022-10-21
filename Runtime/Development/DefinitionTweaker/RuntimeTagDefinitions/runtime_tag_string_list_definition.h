#pragma once

class c_runtime_tag_definitions;

class c_runtime_tag_string_list_definition
{
public:
	std::vector<std::string> strings;
	const blofeld::s_string_list_definition* original_string_list_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

	c_runtime_tag_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_string_list_definition(
		c_runtime_tag_definitions& _runtime_tag_definitions,
		const blofeld::s_string_list_definition& string_list_definition);
};
