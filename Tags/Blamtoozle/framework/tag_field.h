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
	c_blamtoozle_tag_field(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_field(const c_blamtoozle_tag_field&) = delete;
	c_blamtoozle_tag_field(c_blamtoozle_tag_field &&) = delete;
	virtual ~c_blamtoozle_tag_field();

	virtual const char* get_name() = 0;
	virtual blofeld::e_field get_field_type() = 0;

	virtual unsigned long get_padding() = 0;
	virtual unsigned long get_skip_length() = 0;
	virtual const char* get_explanation() = 0;
	virtual blofeld::e_field_id get_field_id() = 0;

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
	unsigned long count;
	e_blamtoozle_tag_field_combined_fixup_type fixup_type;

	c_blamtoozle_tag_field_combined_fixup(
		c_blamtoozle_tag_group_definition& group_definition,
		unsigned long count,
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
