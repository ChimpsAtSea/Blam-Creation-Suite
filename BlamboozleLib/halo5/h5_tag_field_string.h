#pragma once
class c_h5_tag_field_string :
	public c_h5_tag_field
{
public:
	c_h5_tag_field_string(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);
};