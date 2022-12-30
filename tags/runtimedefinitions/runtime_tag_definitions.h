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
class c_runtime_tag_field_definition;

class c_tag_file_reader;
struct s_tag_persist_struct_definition;
struct s_tag_persist_field;

struct s_tag_persist_block_definition;
struct s_tag_persist_struct_definition;
struct s_tag_persist_array_definition;
struct s_tag_persist_string_list;
struct s_tag_persist_resource_definition;
struct s_tag_persist_interop_definition;
struct s_tag_persist_string_character_index;
struct s_tag_persist_string_character_index;
struct s_tag_persist_field;

class c_runtime_tag_definitions :
	public c_blamtoozle_tag_definition_manager
{
public:
	c_runtime_tag_definitions(c_runtime_tag_definitions const&) = delete;
	BCS_SHARED c_runtime_tag_definitions();
	BCS_SHARED void init_from_blofeld(s_engine_platform_build engine_platform_build, blofeld::t_tag_group_collection tag_groups);
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
	std::vector<c_runtime_tag_field_definition*> tag_field_definitions;

	BCS_SHARED c_runtime_tag_group_definition* get_tag_group_by_group_tag(tag group_tag);

	BCS_SHARED void sort_tag_group_definitions();
	BCS_SHARED void sort_tag_block_definitions();
	BCS_SHARED void sort_tag_struct_definitions();
	BCS_SHARED void sort_tag_array_definitions();
	BCS_SHARED void sort_string_list_definitions();
	BCS_SHARED void sort_tag_reference_definitions();
	BCS_SHARED void sort_tag_resource_definitions();
	BCS_SHARED void sort_tag_api_interop_definitions();
	BCS_SHARED void sort_tag_data_definitions();
	BCS_SHARED void sort_block_index_custom_search_definitions();

	BCS_SHARED c_runtime_tag_group_definition& create_tag_group_definition();
	BCS_SHARED c_runtime_tag_block_definition& create_tag_block_definition();
	BCS_SHARED c_runtime_tag_struct_definition& create_tag_struct_definition();
	BCS_SHARED c_runtime_tag_array_definition& create_tag_array_definition();
	BCS_SHARED c_runtime_string_list_definition& create_string_list_definition();
	BCS_SHARED c_runtime_tag_reference_definition& create_tag_reference_definition();
	BCS_SHARED c_runtime_tag_resource_definition& create_tag_resource_definition();
	BCS_SHARED c_runtime_tag_api_interop_definition& create_tag_api_interop_definition();
	BCS_SHARED c_runtime_tag_data_definition& create_tag_data_definition();
	BCS_SHARED c_runtime_tag_block_index_custom_search_definition& create_block_index_custom_search_definition();
	BCS_SHARED c_runtime_tag_field_definition& create_tag_field_definition();

	BCS_SHARED c_runtime_tag_group_definition& duplicate_tag_group_definition(c_runtime_tag_group_definition& group_definition);
	BCS_SHARED c_runtime_tag_block_definition& duplicate_tag_block_definition(c_runtime_tag_block_definition& block_definition);
	BCS_SHARED c_runtime_tag_struct_definition& duplicate_tag_struct_definition(c_runtime_tag_struct_definition& struct_definition);
	BCS_SHARED c_runtime_tag_array_definition& duplicate_tag_array_definition(c_runtime_tag_array_definition& array_definition);
	BCS_SHARED c_runtime_string_list_definition& duplicate_string_list_definition(c_runtime_string_list_definition& string_list_definition);
	BCS_SHARED c_runtime_tag_reference_definition& duplicate_tag_reference_definition(c_runtime_tag_reference_definition& reference_definition);
	BCS_SHARED c_runtime_tag_resource_definition& duplicate_tag_resource_definition(c_runtime_tag_resource_definition& resource_definition);
	BCS_SHARED c_runtime_tag_api_interop_definition& duplicate_tag_api_interop_definition(c_runtime_tag_api_interop_definition& api_interop_definition);
	BCS_SHARED c_runtime_tag_data_definition& duplicate_tag_data_definition(c_runtime_tag_data_definition& data_definition);
	BCS_SHARED c_runtime_tag_block_index_custom_search_definition& duplicate_block_index_custom_search_definition(c_runtime_tag_block_index_custom_search_definition& block_index_custom_search_definition);
	BCS_SHARED c_runtime_tag_field_definition& duplicate_tag_field_definition(c_runtime_tag_field_definition& field_definition);

	BCS_SHARED bool is_tag_group_definition_valid(c_runtime_tag_group_definition* group_definition);
	BCS_SHARED bool is_tag_block_definition_valid(c_runtime_tag_block_definition* block_definition);
	BCS_SHARED bool is_tag_struct_definition_valid(c_runtime_tag_struct_definition* struct_definition);
	BCS_SHARED bool is_tag_array_definition_valid(c_runtime_tag_array_definition* array_definition);
	BCS_SHARED bool is_string_list_definition_valid(c_runtime_string_list_definition* string_list_definition);
	BCS_SHARED bool is_tag_reference_definition_valid(c_runtime_tag_reference_definition* reference_definition);
	BCS_SHARED bool is_tag_resource_definition_valid(c_runtime_tag_resource_definition* resource_definition);
	BCS_SHARED bool is_tag_api_interop_definition_valid(c_runtime_tag_api_interop_definition* api_interop_definition);
	BCS_SHARED bool is_tag_data_definition_valid(c_runtime_tag_data_definition* data_definition);
	BCS_SHARED bool is_block_index_custom_search_definition_valid(c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition);
	BCS_SHARED bool is_tag_field_definition_valid(c_runtime_tag_field_definition* field_definition);

	BCS_SHARED void delete_tag_group_definition(c_runtime_tag_group_definition& group_definition);
	BCS_SHARED void delete_tag_block_definition(c_runtime_tag_block_definition& block_definition);
	BCS_SHARED void delete_tag_struct_definition(c_runtime_tag_struct_definition& struct_definition);
	BCS_SHARED void delete_tag_array_definition(c_runtime_tag_array_definition& array_definition);
	BCS_SHARED void delete_string_list_definition(c_runtime_string_list_definition& string_list_definition);
	BCS_SHARED void delete_tag_reference_definition(c_runtime_tag_reference_definition& reference_definition);
	BCS_SHARED void delete_tag_resource_definition(c_runtime_tag_resource_definition& resource_definition);
	BCS_SHARED void delete_tag_api_interop_definition(c_runtime_tag_api_interop_definition& api_interop_definition);
	BCS_SHARED void delete_tag_data_definition(c_runtime_tag_data_definition& data_definition);
	BCS_SHARED void delete_block_index_custom_search_definition(c_runtime_tag_block_index_custom_search_definition& block_index_custom_search_definition);
	BCS_SHARED void delete_tag_field_definition(c_runtime_tag_field_definition& field_definition);

	BCS_SHARED c_runtime_tag_group_definition& enqueue_tag_group_definition(s_engine_platform_build engine_platform_build, blofeld::s_tag_group const& tag_group_definition);
	BCS_SHARED c_runtime_tag_block_definition& enqueue_tag_block_definition(s_engine_platform_build engine_platform_build, blofeld::s_tag_block_definition const& tag_block_definition);
	BCS_SHARED c_runtime_tag_struct_definition& enqueue_tag_struct_definition(s_engine_platform_build engine_platform_build, blofeld::s_tag_struct_definition const& tag_struct_definition);
	BCS_SHARED c_runtime_tag_array_definition& enqueue_tag_array_definition(s_engine_platform_build engine_platform_build, const blofeld::s_tag_array_definition& tag_array_definition);
	BCS_SHARED c_runtime_string_list_definition& enqueue_string_list_definition(s_engine_platform_build engine_platform_build, const blofeld::s_string_list_definition& string_list_definition);
	BCS_SHARED c_runtime_tag_reference_definition& enqueue_tag_reference_definition(s_engine_platform_build engine_platform_build, const blofeld::s_tag_reference_definition& tag_reference_definition);
	BCS_SHARED c_runtime_tag_resource_definition& enqueue_tag_resource_definition(s_engine_platform_build engine_platform_build, const blofeld::s_tag_resource_definition& tag_resource_definition);
	BCS_SHARED c_runtime_tag_api_interop_definition& enqueue_tag_api_interop_definition(s_engine_platform_build engine_platform_build, const blofeld::s_tag_interop_definition& tag_api_interop_definition);
	BCS_SHARED c_runtime_tag_data_definition& enqueue_tag_data_definition(s_engine_platform_build engine_platform_build, const blofeld::s_tag_data_definition& tag_data_definition);
	BCS_SHARED c_runtime_tag_block_index_custom_search_definition& enqueue_block_index_custom_search_definition(s_engine_platform_build engine_platform_build, const blofeld::s_block_index_custom_search_definition& block_index_custom_search_definition);
	BCS_SHARED c_runtime_tag_field_definition& enqueue_tag_field_definition(s_engine_platform_build engine_platform_build, blofeld::s_tag_field const& field_definition);

	BCS_SHARED c_runtime_tag_block_definition& enqueue_tag_block_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_block_definition const& tag_persist_block_definition);
	BCS_SHARED c_runtime_tag_struct_definition& enqueue_tag_struct_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_struct_definition const& tag_persist_struct_definition);
	BCS_SHARED c_runtime_tag_array_definition& enqueue_tag_array_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_array_definition const& tag_persist_array_definition);
	BCS_SHARED c_runtime_string_list_definition& enqueue_string_list_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_string_list const& tag_persist_string_list);
	BCS_SHARED c_runtime_tag_reference_definition& enqueue_tag_reference_definition(c_tag_file_reader& tag_file_reader);
	BCS_SHARED c_runtime_tag_resource_definition& enqueue_tag_resource_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_resource_definition const& tag_persist_resource_definition);
	BCS_SHARED c_runtime_tag_api_interop_definition& enqueue_tag_api_interop_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_interop_definition const& tag_persist_interop_definition);
	BCS_SHARED c_runtime_tag_data_definition& enqueue_tag_data_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_string_character_index const& tag_persist_string_character_index);
	BCS_SHARED c_runtime_tag_block_index_custom_search_definition& enqueue_block_index_custom_search_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_string_character_index const& tag_persist_string_character_index);
	BCS_SHARED c_runtime_tag_field_definition& enqueue_tag_field_definition(c_tag_file_reader& tag_file_reader, s_tag_persist_field const& tag_persist_field);
};