#pragma once

class c_blamtoozle_tag_field;

class c_blamtoozle_tag_struct_definition
{
public:
	BCS_SHARED c_blamtoozle_tag_struct_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_struct_definition(const c_blamtoozle_tag_struct_definition&) = delete;
	c_blamtoozle_tag_struct_definition(c_blamtoozle_tag_struct_definition&&) = delete;
	BCS_SHARED virtual ~c_blamtoozle_tag_struct_definition();

	BCS_SHARED virtual const char* get_pretty_name() = 0;
	BCS_SHARED virtual const char* get_name() = 0;
	BCS_SHARED virtual const char* get_code_symbol_name() = 0;
	BCS_SHARED virtual const char* get_structure_type_name() = 0;
	BCS_SHARED virtual uint32_t get_alignment_bits() = 0;
	BCS_SHARED virtual const char* get_file_path();
	BCS_SHARED virtual int32_t get_line_number();
	BCS_SHARED virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() = 0;
	BCS_SHARED virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() = 0;

	BCS_SHARED virtual bool is_legacy_struct();
	BCS_SHARED virtual bool is_latest_structure_version();
	BCS_SHARED virtual uint32_t get_structure_version();
	BCS_SHARED virtual c_blamtoozle_tag_struct_definition* get_previous_struct_definition();
	BCS_SHARED virtual c_blamtoozle_tag_struct_definition* get_next_struct_definition();
	BCS_SHARED virtual c_blamtoozle_tag_struct_definition& get_latest_struct_definition();

	using t_fields = std::vector<t_blamtoozle_tag_field*>;
	t_fields fields;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;

protected:
	void clear_fields();
};

