#pragma once

struct s_h5_tag_field_set_header
{
	const char* display_name;
	const char* name;
	GUID _unknownguid;
	void* fields_address;
	uint64_t size;
	const char* size_string_address;
	uint64_t : 64;
	uint64_t _unknown0;
	uint64_t _unknown1;
	uint64_t _unknown2;
	uint64_t _unknown3;
	uint64_t _unknown4;
	uint64_t _unknown5;
	uint64_t _unknown6;
	void* procedures_table_address;
	uint64_t procedures_table_size;
	uint64_t _unknown[17];
};
//static_assert(sizeof(s_h5_tag_field_set_header) == 76, "s_h5_tag_field_set_header is incorrect size");

class c_h5_tag_field_set
{
public:
	const s_h5_tag_field_definition* fields;
	const char* size_string;
	const char* byte_swap_definition_name;
	std::vector<c_h5_tag_field*> tag_fields;

	c_h5_tag_field_set(const char* halo5_forge_data, const s_h5_tag_field_set_header* set_header);

};