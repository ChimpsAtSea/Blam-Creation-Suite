#pragma once

class c_runtime_tag_definitions;

class c_runtime_tag_field_definition :
	public c_blamtoozle_tag_field
{
public:
	friend c_runtime_tag_definitions;

	blofeld::e_field field_type;
	std::string name;
	std::string description;
	std::string units;
	std::string limits;
	std::vector< std::string> old_names;
	c_flags<blofeld::e_tag_field_flag> flags;
	c_runtime_tag_block_definition* block_definition;
	c_runtime_tag_struct_definition* struct_definition;
	c_runtime_tag_array_definition* array_definition;
	c_runtime_string_list_definition* string_list_definition;
	c_runtime_tag_reference_definition* tag_reference_definition;
	c_runtime_tag_resource_definition* tag_resource_definition;
	c_runtime_tag_api_interop_definition* tag_interop_definition;
	c_runtime_tag_data_definition* tag_data_definition;
	c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition;
	std::string explanation;
	uint32_t padding;
	uint32_t length;
	blofeld::s_tag_field_versioning versioning;
	blofeld::e_field_id field_id;
	const blofeld::s_tag_field* original_field;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_field_definition() = delete;
	c_runtime_tag_field_definition(c_runtime_tag_field_definition const&) = delete;
	c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_field_definition const& source);
	c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_field& field);

	virtual const char* get_raw_name() override;
	virtual const char* get_name() override;
	virtual const char* get_description() override;
	virtual const char* get_units() override;
	virtual const char* get_limits() override;
	virtual const char* get_limits_legacy() override;
	virtual const char* get_old_name() override;
	virtual blofeld::e_field get_field_type() override;
	virtual c_flags<blofeld::e_tag_field_flag> get_field_flags() override;
	virtual uint32_t get_padding() override;
	virtual uint32_t get_skip_length() override;
	virtual const char* get_explanation() override;
	virtual blofeld::e_field_id get_field_id() override;
	virtual c_blamtoozle_tag_block_definition* get_block_definition() override;
	virtual c_blamtoozle_tag_reference_definition* get_tag_reference_definition() override;
	virtual c_blamtoozle_tag_struct_definition* get_struct_definition() override;
	virtual c_blamtoozle_tag_array_definition* get_array_definition() override;
	virtual c_blamtoozle_string_list_definition* get_string_list_definition() override;
	virtual c_blamtoozle_tag_resource_definition* get_tag_resource_definition() override;
	virtual c_blamtoozle_tag_data_definition* get_data_definition() override;
	virtual c_blamtoozle_tag_api_interop_definition* get_api_interop_definition() override;
	virtual c_blamtoozle_tag_block_index_custom_search_definition* get_block_index_custom_search_definition() override;

public:
	void restore();
};
