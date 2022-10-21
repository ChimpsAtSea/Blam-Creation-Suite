#pragma once

class c_runtime_tag_array_definition
{
public:
	std::string name;
	std::string display_name;
	unsigned int count;
	std::string count_string;
	c_runtime_tag_struct_definition* struct_definition;
	const blofeld::s_tag_array_definition* original_tag_array_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

	c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_array_definition& tag_array_definition);
};
