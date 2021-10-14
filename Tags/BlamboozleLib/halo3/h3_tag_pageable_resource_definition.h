#pragma once

class c_h3_tag_struct_definition;
class c_h3_tag_group_definition;

struct s_h3_tag_pageable_resource_definition
{
	ptr64 name_address;
	unsigned long unknown8;
	unsigned long unknownC;
	ptr64 structure_definition_address;
	ptr64 unknown18;
	ptr64 unknown20;
	ptr64 filepath;
	long line_number;
	ptr64 unknown30;
};
constexpr size_t k_h3_tag_pageable_resource_definition_size = sizeof(s_h3_tag_pageable_resource_definition);
static_assert(k_h3_tag_pageable_resource_definition_size == 64);

class c_h3_tag_pageable_resource_definition
{
public:
	std::string name;
	std::string code_name;
	const s_h3_tag_pageable_resource_definition& pageable_resource_definition;
	c_h3_tag_struct_definition& struct_definition;

	c_h3_tag_pageable_resource_definition(const char* data, const s_h3_tag_pageable_resource_definition& definition_header);

	static std::map<ptr64, c_h3_tag_pageable_resource_definition*> tag_pageable_resource_definitions;
	static c_h3_tag_pageable_resource_definition* h3_get_tag_pageable_resource_definition(const char* data, ptr64 virtual_address);
};

