#pragma once

struct s_h5_tag_reference_definition
{
	uint32_t flags;
	uint32_t group_tag2;
	uint32_t group_tags_address;
};

class c_h5_tag_field_tag_reference_64 :
	public c_h5_tag_field
{
public:
	const s_h5_tag_reference_definition* tag_reference_definition;

	c_h5_tag_field_tag_reference_64(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);
};
