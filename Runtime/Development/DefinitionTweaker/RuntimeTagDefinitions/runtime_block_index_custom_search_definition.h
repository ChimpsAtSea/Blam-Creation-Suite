#pragma once

class c_runtime_block_index_custom_search_definition
{
public:
	std::string name;
	std::string symbol_name;
	const blofeld::s_block_index_custom_search_definition* original_block_index_custom_search_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

	c_runtime_block_index_custom_search_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_block_index_custom_search_definition(
		c_runtime_tag_definitions& _runtime_tag_definitions,
		const blofeld::s_block_index_custom_search_definition& block_index_custom_search_definition);
};
