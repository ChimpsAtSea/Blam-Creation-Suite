#pragma once

class c_runtime_tag_group_definition;
class c_runtime_tag_block_definition;
class c_runtime_tag_struct_definition;
class c_runtime_tag_array_definition;
class c_runtime_string_list_definition;
class c_runtime_tag_reference_definition;
class c_runtime_tag_resource_definition;
class c_runtime_tag_api_interop_definition;
class c_runtime_tag_data_definition;
class c_runtime_tag_block_index_custom_search_definition;

class c_runtime_tag_definitions :
	public c_blamtoozle_tag_definition_manager
{
public:
	c_runtime_tag_definitions(s_engine_platform_build engine_platform_build);
	virtual void traverse(ptr64 group_table_address, uint32_t num_tag_layouts);
	virtual const char* va_to_pointer(ptr64 address);
	virtual const char* pa_to_pointer(ptr64 address);

	std::vector<c_runtime_tag_group_definition*>& tag_group_definitions;
	std::vector<c_runtime_tag_block_definition*>& tag_block_definitions;
	std::vector<c_runtime_tag_struct_definition*>& tag_struct_definitions;
	std::vector<c_runtime_tag_array_definition*>& tag_array_definitions;
	std::vector<c_runtime_string_list_definition*>& tag_string_list_definitions;
	std::vector<c_runtime_tag_reference_definition*>& tag_reference_definitions;
	std::vector<c_runtime_tag_resource_definition*>& tag_resource_definitions;
	std::vector<c_runtime_tag_api_interop_definition*>& tag_api_interop_definitions;
	std::vector<c_runtime_tag_data_definition*>& tag_data_definitions;
	std::vector<c_runtime_tag_block_index_custom_search_definition*>& tag_block_index_custom_search_definitions;
	std::map<ptr64, c_runtime_tag_group_definition*>& tag_group_definitions_lookup;
	std::map<ptr64, c_runtime_tag_block_definition*>& tag_block_definitions_lookup;
	std::map<ptr64, c_runtime_tag_struct_definition*>& tag_struct_definitions_lookup;
	std::map<ptr64, c_runtime_tag_array_definition*>& tag_array_definitions_lookup;
	std::map<ptr64, c_runtime_string_list_definition*>& tag_string_list_definitions_lookup;
	std::map<ptr64, c_runtime_tag_reference_definition*>& tag_reference_definitions_lookup;
	std::map<ptr64, c_runtime_tag_resource_definition*>& tag_resource_definitions_lookup;
	std::map<ptr64, c_runtime_tag_api_interop_definition*>& tag_api_interop_definitions_lookup;
	std::map<ptr64, c_runtime_tag_data_definition*>& tag_data_definitions_lookup;
	std::map<ptr64, c_runtime_tag_block_index_custom_search_definition*>& tag_block_index_custom_search_definitions_lookup;

	s_engine_platform_build engine_platform_build;

	c_runtime_tag_group_definition* get_tag_group_by_group_tag(tag group_tag);

	void sort_tag_group_definitions();
	void sort_tag_block_definitions();
	void sort_tag_struct_definitions();
	void sort_tag_array_definitions();
	void sort_string_list_definitions();
	void sort_tag_reference_definitions();
	void sort_tag_resource_definitions();
	void sort_tag_interop_definitions();
	void sort_tag_data_definitions();
	void sort_block_index_custom_search_definitions();

	c_runtime_tag_group_definition& create_tag_group_definition();
	c_runtime_tag_block_definition& create_tag_block_definition();
	c_runtime_tag_struct_definition& create_tag_struct_definition();
	c_runtime_tag_array_definition& create_tag_array_definition();
	c_runtime_string_list_definition& create_string_list_definition();
	c_runtime_tag_reference_definition& create_tag_reference_definition();
	c_runtime_tag_resource_definition& create_tag_resource_definition();
	c_runtime_tag_api_interop_definition& create_tag_interop_definition();
	c_runtime_tag_data_definition& create_tag_data_definition();
	c_runtime_tag_block_index_custom_search_definition& create_block_index_custom_search_definition();

	c_runtime_tag_group_definition& duplicate_tag_group_definition(c_runtime_tag_group_definition& group_definition);
	c_runtime_tag_block_definition& duplicate_tag_block_definition(c_runtime_tag_block_definition& block_definition);
	c_runtime_tag_struct_definition& duplicate_tag_struct_definition(c_runtime_tag_struct_definition& struct_definition);
	c_runtime_tag_array_definition& duplicate_tag_array_definition(c_runtime_tag_array_definition& array_definition);
	c_runtime_string_list_definition& duplicate_string_list_definition(c_runtime_string_list_definition& string_list_definition);
	c_runtime_tag_reference_definition& duplicate_tag_reference_definition(c_runtime_tag_reference_definition& reference_definition);
	c_runtime_tag_resource_definition& duplicate_tag_resource_definition(c_runtime_tag_resource_definition& resource_definition);
	c_runtime_tag_api_interop_definition& duplicate_tag_interop_definition(c_runtime_tag_api_interop_definition& interop_definition);
	c_runtime_tag_data_definition& duplicate_tag_data_definition(c_runtime_tag_data_definition& data_definition);
	c_runtime_tag_block_index_custom_search_definition& duplicate_block_index_custom_search_definition(c_runtime_tag_block_index_custom_search_definition& block_index_custom_search_definition);

	c_runtime_tag_group_definition& enqueue_tag_group_definition(const blofeld::s_tag_group& tag_group_definition);
	c_runtime_tag_block_definition& enqueue_tag_block_definition(const blofeld::s_tag_block_definition& tag_block_definition);
	c_runtime_tag_struct_definition& enqueue_tag_struct_definition(const blofeld::s_tag_struct_definition& tag_struct_definition);
	c_runtime_tag_array_definition& enqueue_tag_array_definition(const blofeld::s_tag_array_definition& tag_array_definition);
	c_runtime_string_list_definition& enqueue_string_list_definition(const blofeld::s_string_list_definition& string_list_definition);
	c_runtime_tag_reference_definition& enqueue_tag_reference_definition(const blofeld::s_tag_reference_definition& tag_reference_definition);
	c_runtime_tag_resource_definition& enqueue_tag_resource_definition(const blofeld::s_tag_resource_definition& tag_resource_definition);
	c_runtime_tag_api_interop_definition& enqueue_tag_interop_definition(const blofeld::s_tag_interop_definition& tag_interop_definition);
	c_runtime_tag_data_definition& enqueue_tag_data_definition(const blofeld::s_tag_data_definition& tag_data_definition);
	c_runtime_tag_block_index_custom_search_definition& enqueue_block_index_custom_search_definition(const blofeld::s_block_index_custom_search_definition& block_index_custom_search_definition);
};
