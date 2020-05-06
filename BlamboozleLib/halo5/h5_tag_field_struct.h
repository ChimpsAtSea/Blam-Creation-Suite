#pragma once

struct s_h5_tag_struct_definition
{
	const char* name_address;
	uint32_t group_tag;
	const char* display_name_address;
	uint32_t block_definition_address;
};

class c_h5_tag_field_struct :
	public c_h5_tag_field
{
public:
	const s_h5_tag_struct_definition* tag_struct_definition;

	c_h5_tag_field_struct(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);
};
