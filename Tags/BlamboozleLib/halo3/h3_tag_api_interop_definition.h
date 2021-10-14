#pragma once

class c_h3_tag_struct_definition;

struct s_h3_tag_api_interop_persistent_identifier
{
	unsigned long data[4];
};

struct s_h3_tag_api_interop_definition
{
	s_h3_tag_api_interop_persistent_identifier persistent_identifier;
	ptr64 structure_definition_address;
	ptr64 vtable_address;
	ptr64 name_address;
	ptr64 unknown;
};
constexpr size_t k_h3_tag_api_interop_definition_size = sizeof(s_h3_tag_api_interop_definition);
static_assert(k_h3_tag_api_interop_definition_size == 48);

class c_h3_tag_api_interop_definition
{
public:
	std::string name;
	std::string code_name;
	c_h3_tag_struct_definition& struct_definition;
	s_h3_tag_api_interop_persistent_identifier persistent_identifier;
	const s_h3_tag_api_interop_definition& interop_definition;

	c_h3_tag_api_interop_definition(const char* guerilla_data, const s_h3_tag_api_interop_definition& definition_header);

	static std::map<ptr64, c_h3_tag_api_interop_definition*> tag_api_interop_definitions;
	static c_h3_tag_api_interop_definition* h3_get_tag_api_interop_definition(const char* guerilla_data, ptr64 virtual_address);
};
