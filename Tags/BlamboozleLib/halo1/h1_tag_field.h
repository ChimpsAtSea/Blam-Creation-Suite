#pragma once

struct s_h1_tag_field
{
	e_h1_field_type field_type;
	unsigned short _padding;
	ptr32 name_address;
	ptr32 definition_address;
};

class c_h1_tag_field
{
public:
	const char* name;
	const char* definition;
	const e_h1_field_type& field_type;
	const ptr32& name_address;
	const ptr32& definition_address;

	c_h1_tag_field(const char* guerilla_data, const s_h1_tag_field* field_definition);
};
