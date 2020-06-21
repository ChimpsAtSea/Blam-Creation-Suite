#pragma once

class c_h4_blamboozle;
class c_h4_tag_field;
struct s_h4_tag_field_definition;
struct s_h4_tag_struct_definition;

class c_h4_tag_struct
{
public:
	friend class c_h4_blamboozle;

	const char* const name;
	const char* const display_name;
	const char* const filepath;
	uint32_t const line_number;
	const s_h4_tag_field_definition* const fields;
	const s_h4_tag_struct_definition* const struct_header;
	uint32_t const size;
	const char* const size_string;
	std::vector<c_h4_tag_field*> tag_fields;
	uint32_t offset;

protected:
	c_h4_tag_struct(const char* h4_data, const s_h4_tag_struct_definition* struct_header, uint32_t offset);

};