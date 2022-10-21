#pragma once

class c_runtime_tag_definitions;
class c_runtime_tag_struct_definition;

class c_runtime_tag_block_definition
{
public:
	std::string display_name;
	std::string name;
	std::string symbol_name;
	unsigned int max_count;
	std::string max_count_string;
	c_runtime_tag_struct_definition* struct_definition;
	const blofeld::s_tag_block_definition* original_tag_block_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

	c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_block_definition& tag_block_definition);
};
