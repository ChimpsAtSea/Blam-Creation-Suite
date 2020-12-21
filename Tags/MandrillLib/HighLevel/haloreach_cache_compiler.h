#pragma once

DEBUG_ONLY(class c_haloreach_cache_file);

class h_object;
class c_string_id_manager;

namespace cache_compiler
{
	struct s_cache_file_header;
	struct s_cache_file_info;
	struct s_cache_file_metadata;
	struct s_cache_file_tags_header;
	struct s_cache_file_tag_group;
	struct s_cache_file_tag_instance;
}


class c_haloreach_cache_compiler
{
public:
	c_haloreach_cache_compiler(c_tag_project& tag_project);
	~c_haloreach_cache_compiler();
	uint32_t calculate_size(h_tag& tag);
	void calculate_object_memory_footprint(uint32_t& memory_footprint, h_object& object);
	uint16_t get_tag_index(const h_tag* tag) const;
	void compile_tag(const h_tag& tag, char* tag_data, uint32_t tag_data_size);
	void compile_object(const h_object& object, char* tag_data, char*& tag_allocation_postion);
	void create_tag_groups();
	void init_tags();
	void create_tag_file_table();
	void pre_compile_tags();
	void compile_tags();
	void compile_string_ids();
	void compile_resources();
	void compile_tag_instances();
	void pre_compile_global_tag_instances();
	void compile_global_tag_instances();
	void pre_compile_interops(DEBUG_ONLY(c_haloreach_cache_file* cache_file));
	void compile_interops(DEBUG_ONLY(c_haloreach_cache_file* cache_file));


	void compile(const wchar_t* filepath DEBUG_ONLY(, c_haloreach_cache_file* cache_file));


protected:

	//static constexpr uint64_t virtual_base_address = 0x00000001C9C40000;
	//static constexpr uint64_t virtual_base_address = 0x00000001bcf98000;
	static constexpr uint32_t page_address_offset_relative = 0x50000000ull;
	static constexpr uint32_t block_memory_alignment = 0x4u;
	static constexpr uint32_t tag_memory_alignment = 0x4u;

	uint32_t get_tag_pointer_relative_offset(const char* tag_data);
	uint32_t encode_page_offset(uint64_t virtual_address);
	uint64_t decode_page_offset(uint32_t page_offset);

	c_tag_project& tag_project;
	c_string_id_manager& string_id_manager;

	cache_compiler::s_cache_file_metadata& cache_file_metadata;
	std::vector<char> section_data[4];

	uint64_t virtual_base_address;

	// tag groups

	uint32_t tag_group_count;
	uint32_t tag_groups_buffer_size;
	char* tag_groups_buffer;
	cache_compiler::s_cache_file_tag_group* tag_groups;

	// tag data

	char* tag_data_buffer;
	uint32_t tag_data_data_size;
	uint32_t tag_data_buffer_size;

	struct s_tag_data_entry
	{
		h_tag& tag;
		uint32_t tag_data_offset;
		uint32_t tag_data_size;
		char* tag_data;
		uint32_t tag_file_table_offset;
		uint32_t tag_file_table_index;
		char* tag_file_table_entry;
		cache_compiler::s_cache_file_tag_group* tag_group;
		uint32_t tag_group_index;
		c_fixed_path path;
	};
	s_tag_data_entry* tag_data_entries;
	uint32_t tag_data_entry_count;

	// tag instances

	char* tag_instances_buffer;
	uint32_t tag_instances_data_size;
	uint32_t tag_instances_buffer_size;
	uint32_t tag_instance_count;

	// global tag instances

	char* tag_global_instances_buffer;
	uint32_t tag_global_instances_data_size;
	uint32_t tag_global_instances_buffer_size;
	uint32_t tag_global_instances_count;

	// api interops

	char* tag_api_interops_buffer;
	uint32_t tag_api_interops_data_size;
	uint32_t tag_api_interops_buffer_size;
	uint32_t tag_api_interops_count;

	// file table

	char* tag_file_table_buffer; 
	uint32_t tag_file_table_data_size;
	uint32_t tag_file_table_buffer_size;
	char* tag_file_table_indices_buffer;
	uint32_t tag_file_table_indices_buffer_size;
	uint32_t tag_file_table_indices_count;

	// resources

	char* resources_buffer;
	uint32_t resources_data_size;
	uint32_t resources_buffer_size;

	// localization

	char* localization_buffer;
	uint32_t localization_data_size;
	uint32_t localization_buffer_size;

	// string_ids

	uint32_t string_ids_count;
	char* string_ids_indices_buffer;
	uint32_t string_ids_indices_data_size;
	uint32_t string_ids_indices_buffer_size;

	char* string_ids_buffer;
	uint32_t string_ids_data_size;
	uint32_t string_ids_buffer_size;

	uint32_t string_id_namespace_count;
	char* string_id_namespaces_buffer;
	uint32_t string_id_namespaces_data_size;
	uint32_t string_id_namespaces_buffer_size;

};
