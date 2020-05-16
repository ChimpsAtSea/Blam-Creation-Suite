#pragma once

struct s_h4_tag_enum_definition;

class c_h4_tag_enum
{
public:
	const char* name;
	const char* filename;
	const s_h4_tag_enum_definition* enum_definition;
	std::vector<const char*> options;

	c_h4_tag_enum(const char* h4_data, const s_h4_tag_enum_definition* enum_definition);
};

