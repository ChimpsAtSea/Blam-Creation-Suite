#pragma once



class c_h4_tag_block
{
public:
	const char* display_name;
	const char* name;
	c_h4_tag_struct* tag_struct;

	c_h4_tag_block(const char* h4_data, const s_h4_tag_block_definition* tag_block_definition_header, const s_h4_tag_group* tag_layout_header = nullptr);

};