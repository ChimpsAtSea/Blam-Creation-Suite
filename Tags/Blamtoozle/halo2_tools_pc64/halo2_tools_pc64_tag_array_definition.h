#pragma once

class c_halo2_tools_pc64_tag_struct_definition;
class c_halo2_tools_pc64_tag_group_definition;

class c_halo2_tools_pc64_tag_array_definition :
	public c_blamtoozle_tag_array_definition
{
protected:
	c_halo2_tools_pc64_tag_array_definition(c_halo2_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo2_tools_pc64_tag_array_definition(const c_halo2_tools_pc64_tag_array_definition&) = delete;
	c_halo2_tools_pc64_tag_array_definition(c_halo2_tools_pc64_tag_array_definition&&) = delete;
	~c_halo2_tools_pc64_tag_array_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo2_tools_pc64_tag_definition_manager;
	friend c_halo2_tools_pc64_tag_field;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual uint32_t get_element_count() override;
	virtual const char* get_element_count_string() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;

protected:
	ptr32 definition_address;
	s_halo2_tools_pc64_tag_field field_definition;
	c_halo2_tools_pc64_tag_array_struct_definition& struct_definition;
	std::string name;
	const char* element_count_string;
	std::string code_symbol_name;
};
