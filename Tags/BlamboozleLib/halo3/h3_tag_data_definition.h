#pragma once

struct s_h3_tag_data_definition
{
	ptr64 name_address;
	unsigned long flags;
	unsigned long alignment_bit;
	unsigned long maximum_size;
	ptr64 maximum_size_string_address;
	ptr64 unknown_procedure0;
	ptr64 unknown_procedure1;
	ptr64 unknown_procedure2;
	ptr64 unknown_procedure3;
	ptr64 unknown_procedure4;
	ptr64 unknown_procedure5;
};
constexpr size_t k_h3_tag_data_definition_size = sizeof(s_h3_tag_data_definition);
static_assert(k_h3_tag_data_definition_size == 80);

class c_h3_tag_data_definition
{
public:
	std::string name;
	std::string code_name;
	unsigned long flags;
	unsigned long alignment_bit;
	unsigned long maximum_size;
	std::string maximum_size_string;
	const s_h3_tag_data_definition& data_definition;

	c_h3_tag_data_definition(const char* guerilla_data, const s_h3_tag_data_definition& definition_header);

	static std::map<ptr64, c_h3_tag_data_definition*> tag_data_definitions;
	static c_h3_tag_data_definition* h3_get_tag_data_definition(const char* guerilla_data, ptr64 virtual_address);
};
