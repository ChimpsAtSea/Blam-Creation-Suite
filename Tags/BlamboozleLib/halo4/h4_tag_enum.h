#pragma once

struct s_h4_tag_enum_definition;

class c_h4_tag_enum
{
protected:
	const s_h4_tag_enum_definition* enum_definition;
public:
	const char* name;
	const char* filepath;
	uint32_t line_number;
	std::vector<const char*> options;

	c_h4_tag_enum(const char* h4_data, const s_h4_tag_enum_definition* enum_definition);
};

