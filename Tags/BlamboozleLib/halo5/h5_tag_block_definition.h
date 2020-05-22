#pragma once



class c_h5_tag_block_definition
{
public:
	const char* display_name;
	const char* name;
	std::vector<c_h5_tag_field_set*> tag_field_sets;

	c_h5_tag_block_definition(const char* halo5_forge_data, const s_h5_tag_block_definition* tag_block_definition_header, const s_h5_tag_layout_header* tag_layout_header = nullptr);

};