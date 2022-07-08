#pragma once

struct s_reach_x360_string_list_definition
{
	ptr32 name_address;
	unsigned long option_count;
	ptr32 options_address;
	unsigned long unknown0;
	unsigned long unknown1;
	ptr32 file_path;
	long line_number;
};
constexpr size_t k_reach_x360_string_list_definition_size = sizeof(s_reach_x360_string_list_definition);
static_assert(k_reach_x360_string_list_definition_size == 28);

struct s_reach_x360_string_list_entry_definition
{
	ptr32 option_address;
};
constexpr size_t k_reach_x360_string_list_entry_definition_size = sizeof(s_reach_x360_string_list_entry_definition);
static_assert(k_reach_x360_string_list_entry_definition_size == 4);

class c_reach_x360_string_list_definition :
	public c_blamtoozle_string_list_definition
{
public:
	c_reach_x360_string_list_definition(c_reach_x360_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_reach_x360_string_list_definition(const c_reach_x360_string_list_definition&) = delete;
	c_reach_x360_string_list_definition(c_reach_x360_string_list_definition&&) = delete;
	~c_reach_x360_string_list_definition();

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_file_path() override;
	virtual long get_line_number() override;

	ptr32 definition_address;
	s_reach_x360_string_list_definition string_list_definition;
	const char* name;
	std::string code_symbol_name;
	const char* file_path;
};
