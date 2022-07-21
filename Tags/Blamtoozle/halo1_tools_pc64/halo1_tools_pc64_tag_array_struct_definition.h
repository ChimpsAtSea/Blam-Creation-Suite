#pragma once

class c_halo1_tools_pc64_tag_struct_definition;
class c_halo1_tools_pc64_tag_group_definition;
class c_halo1_tools_pc64_tag_array_definition;

class c_halo1_tools_pc64_tag_array_struct_definition :
	public c_blamtoozle_tag_struct_definition
{
protected:
	c_halo1_tools_pc64_tag_array_struct_definition(c_halo1_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo1_tools_pc64_tag_array_struct_definition(const c_halo1_tools_pc64_tag_array_struct_definition&) = delete;
	c_halo1_tools_pc64_tag_array_struct_definition(c_halo1_tools_pc64_tag_array_struct_definition&&) = delete;
	~c_halo1_tools_pc64_tag_array_struct_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo1_tools_pc64_tag_definition_manager;
	friend c_halo1_tools_pc64_tag_group_definition;
	friend c_halo1_tools_pc64_tag_array_definition;

	virtual const char* get_display_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_structure_type_name() override;
	virtual uint32_t get_alignment_bits() override;
	virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() override;

protected:
	ptr32 definition_address;
	const char* display_name;
	const char* name;
	std::string code_symbol_name;
	std::string code_type_name;
	bool conflict_handled;
	
};
