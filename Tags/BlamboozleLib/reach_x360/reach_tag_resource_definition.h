#pragma once

class c_reach_x360_tag_struct_definition;
class c_reach_x360_tag_group_definition;

struct s_reach_x360_tag_resource_definition
{
	bptr32 name_address;
	bulong unknown8;
	bptr32 structure_definition_address;
	bptr32 tag_resource_vtable;
	bptr32 unknown20;
	bptr32 filepath;
	blong line_number;
	bptr32 unknown30;
};
constexpr size_t k_reach_x360_tag_resource_definition_size = sizeof(s_reach_x360_tag_resource_definition);
//static_assert(k_reach_x360_tag_resource_definition_size == 64);

class c_reach_x360_tag_resource_definition
{
public:
	std::string name;
	std::string code_name;
	const s_reach_x360_tag_resource_definition& pageable_resource_definition;
	c_reach_x360_tag_struct_definition& struct_definition;

	c_reach_x360_tag_resource_definition(const char* data, const s_reach_x360_tag_resource_definition& definition_header);

	static std::map<ptr32, c_reach_x360_tag_resource_definition*> tag_resource_definitions;
	static c_reach_x360_tag_resource_definition* reach_x360_get_tag_resource_definition(const char* data, ptr32 virtual_address);
};

