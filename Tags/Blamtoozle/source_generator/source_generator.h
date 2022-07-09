#pragma once

class c_blamtoozle_tag_group_definition;
class c_blamtoozle_tag_block_definition;
class c_blamtoozle_tag_array_definition;
class c_blamtoozle_tag_struct_definition;
class c_blamtoozle_tag_data_definition;
class c_blamtoozle_tag_resource_definition;
class c_blamtoozle_tag_api_interop_definition;
class c_blamtoozle_tag_block_index_custom_search_definition;

class c_blamlib_string_parser_v2;

template<typename t_definition_type>
class c_blamtoozle_definition_generator_helper
{
public:
	c_blamtoozle_definition_generator_helper(t_definition_type* _definition) :
		definition(_definition),
		is_exported(false)
	{

	}
	c_blamtoozle_definition_generator_helper(const c_blamtoozle_definition_generator_helper&) = default;
	c_blamtoozle_definition_generator_helper(c_blamtoozle_definition_generator_helper&&) = default;
	~c_blamtoozle_definition_generator_helper() = default;

	t_definition_type* definition;
	bool is_exported;

	bool can_export()
	{
		bool _is_exported = is_exported;
		is_exported = true;
		return !_is_exported;
	}
};

class c_blamtoozle_source_generator
{
public:
	c_blamtoozle_source_generator(
		c_blamtoozle_tag_definition_manager& tag_definition_manager,
		const char* engine_namespace,
		const char* platform_namespace);
	c_blamtoozle_source_generator(const c_blamtoozle_source_generator&) = delete;
	c_blamtoozle_source_generator(c_blamtoozle_source_generator&&) = delete;
	~c_blamtoozle_source_generator();

	c_blamtoozle_tag_definition_manager& tag_definition_manager;

	void export_single_tag_definitions_header(const wchar_t* file_path);
	void export_single_tag_definitions_source(const wchar_t* file_path);
	void export_tag_groups_header(const wchar_t* file_path);
	void export_tag_groups_source(const wchar_t* file_path);
protected:
	void coerce_definitions();
	void clear_is_exported();

	void write_tag_types_header(std::stringstream& stream, c_blamtoozle_tag_struct_definition::t_fields& fields);
	void write_tag_types_source(std::stringstream& stream, c_blamtoozle_tag_struct_definition::t_fields& fields);
	void write_fields(std::stringstream& stream, c_blamtoozle_tag_struct_definition::t_fields& fields);
	static void write_tag_field_flags(std::stringstream& stream, c_blamlib_string_parser_v2& string_parser);
	static const char* tag_field_set_bit_to_field_set_bit_macro(blofeld::e_tag_field_set_bit flags);
	static void write_tag_reference_flags(std::stringstream& stream, c_blamtoozle_tag_reference_definition& tag_reference_definition);

	bool is_group_exported(c_blamtoozle_tag_group_definition& definition);
	bool is_block_exported(c_blamtoozle_tag_block_definition& definition);
	bool is_tag_reference_exported(c_blamtoozle_tag_reference_definition& definition);
	bool is_array_exported(c_blamtoozle_tag_array_definition& definition);
	bool is_struct_exported(c_blamtoozle_tag_struct_definition& definition);
	bool is_data_exported(c_blamtoozle_tag_data_definition& definition);
	bool is_string_list_exported(c_blamtoozle_string_list_definition& definition);
	bool is_resource_exported(c_blamtoozle_tag_resource_definition& definition);
	bool is_api_interop_exported(c_blamtoozle_tag_api_interop_definition& definition);
	bool is_block_index_custom_search_exported(c_blamtoozle_tag_block_index_custom_search_definition& definition);

	const char* engine_namespace;
	const char* platform_namespace;

	std::vector<c_blamtoozle_tag_group_definition*> group_definitions;
	std::vector<c_blamtoozle_tag_block_definition*> block_definitions;
	std::vector<c_blamtoozle_tag_reference_definition*> tag_reference_definitions;
	std::vector<c_blamtoozle_tag_array_definition*> array_definitions;
	std::vector<c_blamtoozle_tag_struct_definition*> struct_definitions;
	std::vector<c_blamtoozle_tag_data_definition*> data_definitions;
	std::vector<c_blamtoozle_string_list_definition*> string_list_definitions;
	std::vector<c_blamtoozle_tag_resource_definition*> resource_definitions;
	std::vector<c_blamtoozle_tag_api_interop_definition*> api_interop_definitions;
	std::vector<c_blamtoozle_tag_block_index_custom_search_definition*> block_index_custom_search_definitions;

	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_group_definition>> group_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_block_definition>> block_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_reference_definition>> tag_reference_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_array_definition>> array_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_struct_definition>> struct_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_data_definition>> data_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_string_list_definition>> string_list_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_resource_definition>> resource_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_api_interop_definition>> api_interop_definitions_helpers;
	std::vector<c_blamtoozle_definition_generator_helper<c_blamtoozle_tag_block_index_custom_search_definition>> block_index_custom_search_definitions_helpers;
};
