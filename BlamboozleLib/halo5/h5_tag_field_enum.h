#pragma once

struct s_h5_tag_enum_definition
{
	uint32_t option_count;
	uint32_t options_address;
	uint32_t flags; //?
};

class c_h5_tag_field_enum :
	public c_h5_tag_field
{
public:
	const s_h5_tag_enum_definition* tag_enum_definition;
	std::vector<const char*> options;

	c_h5_tag_field_enum(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);

};
