#pragma once

struct s_halo1_tools_pc64_tag_data_definition
{
	ptr32 name_address;
	unsigned long flags;
	unsigned long maximum_element_count;
	ptr32 unknown_procedure0;
};
constexpr size_t k_halo1_tools_pc64_tag_data_definition_size = sizeof(s_halo1_tools_pc64_tag_data_definition);
static_assert(k_halo1_tools_pc64_tag_data_definition_size == 16);

class c_halo1_tools_pc64_tag_data_definition :
	public c_blamtoozle_tag_data_definition
{
protected:
	c_halo1_tools_pc64_tag_data_definition(c_halo1_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo1_tools_pc64_tag_data_definition(const c_halo1_tools_pc64_tag_data_definition&) = delete;
	c_halo1_tools_pc64_tag_data_definition(c_halo1_tools_pc64_tag_data_definition&&) = delete;
	~c_halo1_tools_pc64_tag_data_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo1_tools_pc64_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual unsigned long get_flags() override;
	virtual unsigned long get_alignment_bits() override;
	virtual unsigned long get_maximum_element_count() override;
	virtual const char* get_maximum_element_count_string() override;

protected:
	ptr32 definition_address;
	s_halo1_tools_pc64_tag_data_definition data_definition;
	const char* name;
	char maximum_element_count_string[32];
	std::string code_symbol_name;
};






