#pragma once

struct s_h5_tag_block_index_custom_search_definition
{
	void* get_block_procedure;
	void* is_valid_source_block_procedure;
};

class c_h5_tag_field_block_index_custom_search_definition :
	public c_h5_tag_field
{
public:
	const s_h5_tag_block_index_custom_search_definition* tag_block_index_custom_search_definition;

	c_h5_tag_field_block_index_custom_search_definition(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);

};
