#pragma once

struct s_halo3_tools_pc64_string_list_definition
{
	ptr64 name_address;
	uint32_t option_count;
	ptr64 options_address;	
	//uint32_t unknown0;
	//uint32_t unknown1;
	//ptr64 file_path;
	//int32_t line_number;
};
constexpr size_t k_halo3_tools_pc64_string_list_definition_size = sizeof(s_halo3_tools_pc64_string_list_definition);
static_assert(k_halo3_tools_pc64_string_list_definition_size == 24);

struct s_halo3_tools_pc64_string_list_entry_definition
{
	ptr64 option_address;
};
constexpr size_t k_halo3_tools_pc64_string_list_entry_definition_size = sizeof(s_halo3_tools_pc64_string_list_entry_definition);
static_assert(k_halo3_tools_pc64_string_list_entry_definition_size == 8);

class c_halo3_tools_pc64_string_list_definition :
	public c_blamtoozle_string_list_definition
{
public:
	c_halo3_tools_pc64_string_list_definition(c_halo3_tools_pc64_tag_definition_manager& tag_definition_manager, ptr64 definition_address);
	c_halo3_tools_pc64_string_list_definition(const c_halo3_tools_pc64_string_list_definition&) = delete;
	c_halo3_tools_pc64_string_list_definition(c_halo3_tools_pc64_string_list_definition&&) = delete;
	~c_halo3_tools_pc64_string_list_definition();

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;

	ptr64 definition_address;
	s_halo3_tools_pc64_string_list_definition string_list_definition;
	const char* name;
	std::string code_symbol_name;
};
