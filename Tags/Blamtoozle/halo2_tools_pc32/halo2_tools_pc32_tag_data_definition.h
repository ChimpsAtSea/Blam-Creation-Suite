#pragma once

struct s_halo2_tools_pc32_tag_data_definition
{
	ptr32 name_address;
	unsigned long flags;
	unsigned long alignment_bit;
	unsigned long maximum_element_count;
	ptr32 maximum_element_count_string_address;
	ptr32 unknown_procedure0;
	ptr32 unknown_procedure1;
	ptr32 unknown_procedure2;
	ptr32 unknown_procedure3;
	ptr32 unknown_procedure4;
	ptr32 unknown_procedure5;
};
constexpr size_t k_halo2_tools_pc32_tag_data_definition_size = sizeof(s_halo2_tools_pc32_tag_data_definition);
static_assert(k_halo2_tools_pc32_tag_data_definition_size == 44);

class c_halo2_tools_pc32_tag_data_definition :
	public c_blamtoozle_tag_data_definition
{
protected:
	c_halo2_tools_pc32_tag_data_definition(c_halo2_tools_pc32_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo2_tools_pc32_tag_data_definition(const c_halo2_tools_pc32_tag_data_definition&) = delete;
	c_halo2_tools_pc32_tag_data_definition(c_halo2_tools_pc32_tag_data_definition&&) = delete;
	~c_halo2_tools_pc32_tag_data_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo2_tools_pc32_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual unsigned long get_flags() override;
	virtual unsigned long get_alignment_bits() override;
	virtual unsigned long get_maximum_element_count() override;
	virtual const char* get_maximum_element_count_string() override;

protected:
	ptr32 definition_address;
	s_halo2_tools_pc32_tag_data_definition data_definition;
	const char* name;
	const char* maximum_element_count_string;
	std::string code_symbol_name;
};






