#pragma once

class c_blamtoozle_tag_field;

class c_blamtoozle_tag_struct_definition
{
public:
	c_blamtoozle_tag_struct_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_struct_definition(const c_blamtoozle_tag_struct_definition&) = delete;
	c_blamtoozle_tag_struct_definition(c_blamtoozle_tag_struct_definition&&) = delete;
	virtual ~c_blamtoozle_tag_struct_definition();

	virtual const char* get_display_name() = 0;
	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual const char* get_structure_type_name() = 0;
	virtual unsigned long get_alignment_bits() = 0;
	virtual const char* get_file_path();
	virtual long get_line_number();
	virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() = 0;
	virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() = 0;

	virtual bool is_legacy_struct();
	virtual bool is_latest_structure_version();
	virtual unsigned long get_structure_version();
	virtual c_blamtoozle_tag_struct_definition* get_previous_struct_definition();
	virtual c_blamtoozle_tag_struct_definition* get_next_struct_definition();
	virtual c_blamtoozle_tag_struct_definition& get_latest_struct_definition();

	using t_fields = std::vector<t_blamtoozle_tag_field*>;
	t_fields fields;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;

protected:
	void clear_fields();
};

