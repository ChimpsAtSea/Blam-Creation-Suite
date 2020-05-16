#pragma once



class c_h4_tag_block
{
public:
	const char* const display_name;
	const char* const name;
	uint32_t const maximum_element_count;
	const char* const maximum_element_count_string;
protected:
	const s_h4_tag_struct_definition* const struct_definition;
public:
	c_h4_tag_struct& tag_struct;

	c_h4_tag_block(const char* h4_data, const s_h4_tag_block_definition* tag_block_definition_header, const s_h4_tag_group* tag_layout_header = nullptr);

};	