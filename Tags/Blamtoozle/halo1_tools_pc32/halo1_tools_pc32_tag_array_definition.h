#pragma once

class c_halo1_tools_pc32_tag_struct_definition;
class c_halo1_tools_pc32_tag_group_definition;

class c_halo1_tools_pc32_tag_array_definition :
	public c_blamtoozle_tag_array_definition
{
protected:
	c_halo1_tools_pc32_tag_array_definition(c_halo1_tools_pc32_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo1_tools_pc32_tag_array_definition(const c_halo1_tools_pc32_tag_array_definition&) = delete;
	c_halo1_tools_pc32_tag_array_definition(c_halo1_tools_pc32_tag_array_definition&&) = delete;
	~c_halo1_tools_pc32_tag_array_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo1_tools_pc32_tag_definition_manager;
	friend c_halo1_tools_pc32_tag_field;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual unsigned long get_element_count() override;
	virtual const char* get_element_count_string() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;

protected:
	ptr32 definition_address;
	s_halo1_tools_pc32_tag_field field_definition;
	c_halo1_tools_pc32_tag_array_struct_definition& struct_definition;
	const char* name;
	const char* element_count_string;
	std::string code_symbol_name;
};
