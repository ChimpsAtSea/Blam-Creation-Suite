#pragma once

struct s_halo3_tools_pc64_tag_data_definition
{
	ptr64 name_address;
	uint32_t flags;
	uint32_t alignment_bit;
	uint32_t maximum_element_count;
	ptr64 maximum_element_count_string_address;
	ptr64 unknown_procedure0;
	ptr64 unknown_procedure1;
	ptr64 unknown_procedure2;
	ptr64 unknown_procedure3;
	ptr64 unknown_procedure4;
	ptr64 unknown_procedure5;
};
constexpr size_t k_halo3_tools_pc64_tag_data_definition_size = sizeof(s_halo3_tools_pc64_tag_data_definition);
static_assert(k_halo3_tools_pc64_tag_data_definition_size == 80);

class c_halo3_tools_pc64_tag_data_definition :
	public c_blamtoozle_tag_data_definition
{
protected:
	c_halo3_tools_pc64_tag_data_definition(c_halo3_tools_pc64_tag_definition_manager& tag_definition_manager, ptr64 definition_address);
	c_halo3_tools_pc64_tag_data_definition(const c_halo3_tools_pc64_tag_data_definition&) = delete;
	c_halo3_tools_pc64_tag_data_definition(c_halo3_tools_pc64_tag_data_definition&&) = delete;
	~c_halo3_tools_pc64_tag_data_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo3_tools_pc64_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual uint32_t get_flags() override;
	virtual uint32_t get_alignment_bits() override;
	virtual uint32_t get_maximum_element_count() override;
	virtual const char* get_maximum_element_count_string() override;

protected:
	ptr64 definition_address;
	s_halo3_tools_pc64_tag_data_definition data_definition;
	const char* name;
	const char* maximum_element_count_string;
	std::string code_symbol_name;
};






