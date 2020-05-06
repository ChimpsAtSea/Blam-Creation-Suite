#pragma once

struct s_h5_tag_data_definition
{
	const char* definition_name_address;
	uint32_t flags;
	uint32_t alignment_bit;
	uint32_t maximum_size;
	const char* maximum_size_string_address;
	void* byteswap_procedure;
	void* copy_procedure;
};

class c_h5_tag_field_data_64 :
	public c_h5_tag_field
{
public:
	const s_h5_tag_data_definition* tag_data_definition;
	const char* definition_name;
	const char* maximum_size;

	c_h5_tag_field_data_64(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);
};