#pragma once

class c_h4_blamboozle;
class c_h4_tag_field;
struct s_h4_tag_field_definition;
struct s_h4_tag_struct_definition;

class c_h4_tag_struct
{
public:
	friend class c_h4_blamboozle;

	const char* name;
	const char* display_name;
	const char* filepath;
	const s_h4_tag_field_definition* fields;
	uint32_t size;
	const char* size_string;
	const char* byte_swap_definition_name;
	std::vector<c_h4_tag_field*> tag_fields;

protected:
	c_h4_tag_struct(const char* h4_data, const s_h4_tag_struct_definition* set_header);

};