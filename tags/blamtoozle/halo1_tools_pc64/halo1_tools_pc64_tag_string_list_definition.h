#pragma once

struct s_halo1_tools_pc64_string_list_definition
{
	uint32_t option_count;
	ptr32 options_address;	
};
constexpr size_t k_halo1_tools_pc64_string_list_definition_size = sizeof(s_halo1_tools_pc64_string_list_definition);
static_assert(k_halo1_tools_pc64_string_list_definition_size == 8);

struct s_halo1_tools_pc64_string_list_entry_definition
{
	ptr32 option_address;
};
constexpr size_t k_halo1_tools_pc64_string_list_entry_definition_size = sizeof(s_halo1_tools_pc64_string_list_entry_definition);
static_assert(k_halo1_tools_pc64_string_list_entry_definition_size == 4);

class c_halo1_tools_pc64_string_list_definition :
	public c_blamtoozle_string_list_definition
{
public:
	c_halo1_tools_pc64_string_list_definition(c_halo1_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo1_tools_pc64_string_list_definition(const c_halo1_tools_pc64_string_list_definition&) = delete;
	c_halo1_tools_pc64_string_list_definition(c_halo1_tools_pc64_string_list_definition&&) = delete;
	~c_halo1_tools_pc64_string_list_definition();

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;

	ptr32 definition_address;
	s_halo1_tools_pc64_string_list_definition string_list_definition;
	std::string name;
	std::string code_symbol_name;
};
