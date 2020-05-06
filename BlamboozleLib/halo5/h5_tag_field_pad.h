#pragma once

class c_h5_tag_field_pad :
	public c_h5_tag_field
{
public:
	uint32_t padding;

	c_h5_tag_field_pad(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);
};