#pragma once
class c_h5_tag_field_explaination_definition :
	public c_h5_tag_field
{
public:
	const char* explaination;

	c_h5_tag_field_explaination_definition(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);

};