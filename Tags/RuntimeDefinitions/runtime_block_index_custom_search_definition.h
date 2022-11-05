#pragma once

class c_runtime_tag_block_index_custom_search_definition :
	public c_blamtoozle_tag_block_index_custom_search_definition
{
public:
	friend c_runtime_tag_definitions;

	std::string name;
	std::string symbol_name;
	const blofeld::s_block_index_custom_search_definition* original_block_index_custom_search_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_block_index_custom_search_definition() = delete;
	c_runtime_tag_block_index_custom_search_definition(c_runtime_tag_block_index_custom_search_definition const&) = delete;
	c_runtime_tag_block_index_custom_search_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_block_index_custom_search_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_block_index_custom_search_definition const& source);
	c_runtime_tag_block_index_custom_search_definition(
		c_runtime_tag_definitions& _runtime_tag_definitions,
		const blofeld::s_block_index_custom_search_definition& block_index_custom_search_definition);

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
};
