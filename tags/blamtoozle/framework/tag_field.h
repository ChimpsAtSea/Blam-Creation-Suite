#pragma once

class c_blamtoozle_tag_block_definition;
class c_blamtoozle_tag_reference_definition;
class c_blamtoozle_tag_array_definition;
class c_blamtoozle_tag_struct_definition;
class c_blamtoozle_tag_resource_definition;
class c_blamtoozle_tag_data_definition;
class c_blamtoozle_tag_api_interop_definition;

using t_blamtoozle_tag_field = t_virtual;

class c_blamtoozle_tag_field :
	public t_blamtoozle_tag_field
{
public:
	BCS_SHARED c_blamtoozle_tag_field(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_field(const c_blamtoozle_tag_field&) = delete;
	c_blamtoozle_tag_field(c_blamtoozle_tag_field &&) = delete;
	BCS_SHARED virtual ~c_blamtoozle_tag_field();

	virtual const char* get_raw_name() = 0;
	virtual std::string const& get_name() = 0;
	virtual std::string const& get_description() = 0;
	virtual std::string const& get_units() = 0;
	virtual std::string const& get_limits() = 0;
	virtual std::string const& get_limits_legacy() = 0;
	virtual std::vector<std::string> const& get_old_names() = 0;
	virtual blofeld::e_field get_field_type() = 0;
	virtual blofeld::f_tag_field_flags get_field_flags() = 0;
	virtual uint32_t get_padding() = 0;
	virtual uint32_t get_skip_length() = 0;
	virtual const char* get_explanation() = 0;
	virtual bool get_tag_field_attributed_definition(blofeld::e_tag_field_attributed_definition& tag_field_attributed_definition) = 0;
	virtual bool get_tag_field_custom_type(blofeld::e_tag_field_custom_type& tag_field_custom_type) = 0;
	virtual bool get_tag_field_id(blofeld::e_field_id& field_id) = 0;
	BCS_SHARED virtual blofeld::s_tag_field_versioning const& get_tag_field_versioning();

	virtual c_blamtoozle_tag_block_definition* get_block_definition() = 0;
	virtual c_blamtoozle_tag_reference_definition* get_tag_reference_definition() = 0;
	virtual c_blamtoozle_tag_struct_definition* get_struct_definition() = 0;
	virtual c_blamtoozle_tag_array_definition* get_array_definition() = 0;
	virtual c_blamtoozle_string_list_definition* get_string_list_definition() = 0;
	virtual c_blamtoozle_tag_resource_definition* get_tag_resource_definition() = 0;
	virtual c_blamtoozle_tag_data_definition* get_data_definition() = 0;
	virtual c_blamtoozle_tag_api_interop_definition* get_api_interop_definition() = 0;
	virtual c_blamtoozle_tag_block_index_custom_search_definition* get_block_index_custom_search_definition() = 0;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};

enum e_blamtoozle_tag_field_combined_fixup_type
{
	_blamtoozle_tag_field_combined_fixup_type_equal,
	_blamtoozle_tag_field_combined_fixup_type_not_equal,
};

class c_blamtoozle_tag_field_combined_fixup :
	public t_blamtoozle_tag_field
{
public:
	c_blamtoozle_tag_group_definition& group_definition;
	uint32_t count;
	e_blamtoozle_tag_field_combined_fixup_type fixup_type;

	c_blamtoozle_tag_field_combined_fixup(
		c_blamtoozle_tag_group_definition& group_definition,
		uint32_t count,
		e_blamtoozle_tag_field_combined_fixup_type fixup_type);
	virtual ~c_blamtoozle_tag_field_combined_fixup();
};

class c_blamtoozle_tag_field_dummy_space :
	public t_blamtoozle_tag_field
{
public:
	c_blamtoozle_tag_field_dummy_space();
	virtual ~c_blamtoozle_tag_field_dummy_space();
};

extern void string_parser(
	const char* raw_name,
	std::string& name,
	std::string& description,
	std::string& units,
	std::string& limits,
	std::string& limits_legacy,
	std::vector<std::string>& old_names,
	blofeld::f_tag_field_flags& flags);
