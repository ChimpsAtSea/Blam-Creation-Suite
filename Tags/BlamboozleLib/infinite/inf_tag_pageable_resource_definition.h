#pragma once

class c_inf_tag_struct_definition;
class c_inf_tag_group_definition;

struct s_inf_tag_pageable_resource_definition
{
	ptr64 name_address;
	unsigned long unknown8;
	unsigned long unknownC;
	ptr64 structure_definition_address;
	ptr64 unknown18;
};
constexpr size_t k_inf_tag_pageable_resource_definition_size = sizeof(s_inf_tag_pageable_resource_definition);
static_assert(k_inf_tag_pageable_resource_definition_size == 32);

class c_inf_tag_pageable_resource_definition
{
public:
	std::string name;
	std::string code_name;
	const s_inf_tag_pageable_resource_definition& pageable_resource_definition;
	c_inf_tag_struct_definition& struct_definition;

	c_inf_tag_pageable_resource_definition(const char* data, const s_inf_tag_pageable_resource_definition& definition_header);

	static std::map<ptr64, c_inf_tag_pageable_resource_definition*> tag_pageable_resource_definitions;
	static c_inf_tag_pageable_resource_definition* inf_get_tag_pageable_resource_definition(const char* data, ptr64 virtual_address);
};

