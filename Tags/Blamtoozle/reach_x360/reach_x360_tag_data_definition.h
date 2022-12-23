#pragma once

struct s_reach_x360_tag_data_definition
{
	ptr32 name_address;
	uint32_t flags;
	uint32_t alignment_bit;
	uint32_t maximum_element_count;
	ptr32 maximum_element_count_string_address;
	ptr32 unknown_procedure0;
	ptr32 unknown_procedure1;
	ptr32 unknown_procedure2;
	ptr32 unknown_procedure3;
	ptr32 unknown_procedure4;
	ptr32 unknown_procedure5;
};
constexpr size_t k_reach_x360_tag_data_definition_size = sizeof(s_reach_x360_tag_data_definition);
static_assert(k_reach_x360_tag_data_definition_size == 44);

class c_reach_x360_tag_data_definition :
	public c_blamtoozle_tag_data_definition
{
protected:
	c_reach_x360_tag_data_definition(c_reach_x360_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_reach_x360_tag_data_definition(const c_reach_x360_tag_data_definition&) = delete;
	c_reach_x360_tag_data_definition(c_reach_x360_tag_data_definition&&) = delete;
	~c_reach_x360_tag_data_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_reach_x360_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual uint32_t get_flags() override;
	virtual uint32_t get_alignment_bits() override;
	virtual uint32_t get_maximum_element_count() override;
	virtual const char* get_maximum_element_count_string() override;

protected:
	ptr32 definition_address;
	s_reach_x360_tag_data_definition data_definition;
	const char* name;
	const char* maximum_element_count_string;
	std::string code_symbol_name;
};






