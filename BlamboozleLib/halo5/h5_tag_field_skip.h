#pragma once

class c_h5_tag_field_skip :
	public c_h5_tag_field
{
public:
	uint32_t lenght;

	c_h5_tag_field_skip(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);
};