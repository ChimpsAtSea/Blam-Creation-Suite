#pragma once

struct s_h5_tag_field_definition
{
	e_h5_field_type field_type;
	const char* name_address;
	void* definition_address;
	uint32_t group_tag;
	uint32_t : 32;
};

class c_h5_tag_field
{
public:
	const char* name;
	const char* definition;

	c_h5_tag_field(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);
	virtual ~c_h5_tag_field();
};
