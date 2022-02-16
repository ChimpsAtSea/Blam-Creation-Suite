#pragma once

class c_reach_x360_tag_struct_definition;

struct s_reach_x360_tag_api_interop_persistent_identifier
{
	blong data[4];
};

struct s_reach_x360_tag_api_interop_definition
{
	s_reach_x360_tag_api_interop_persistent_identifier persistent_identifier;
	bptr32 structure_definition_address;
	bptr32 vtable_address;
	bptr32 name_address;
	bptr32 unknown;
};
constexpr size_t k_reach_x360_tag_api_interop_definition_size = sizeof(s_reach_x360_tag_api_interop_definition);
//static_assert(k_reach_x360_tag_api_interop_definition_size == 48);

class c_reach_x360_tag_api_interop_definition
{
public:
	std::string name;
	std::string code_name;
	c_reach_x360_tag_struct_definition& struct_definition;
	s_tag_persistent_identifier persistent_identifier;
	const s_reach_x360_tag_api_interop_definition& interop_definition;

	c_reach_x360_tag_api_interop_definition(const char* guerilla_data, const s_reach_x360_tag_api_interop_definition& definition_header);

	static std::map<ptr32, c_reach_x360_tag_api_interop_definition*> tag_api_interop_definitions;
	static c_reach_x360_tag_api_interop_definition* reach_x360_get_tag_api_interop_definition(const char* guerilla_data, ptr32 virtual_address);
};
