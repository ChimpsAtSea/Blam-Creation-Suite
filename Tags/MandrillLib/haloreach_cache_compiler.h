#pragma once

DEBUG_ONLY(class c_haloreach_cache_file);

class h_object;

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
	uint32_t calculate_size(h_object& object);
	void compile_tag(h_tag& tag, char* tag_data);
	void create_tag_groups();
	void compile(const wchar_t* filepath DEBUG_ONLY(, c_haloreach_cache_file* cache_file));


protected:

	static constexpr uint64_t virtual_base_address = 0x00000001cb780000;
	static constexpr uint32_t page_address_offset_relative = 0x50000000ull;

	static uint32_t encode_page_offset(uint64_t virtual_address);
	static uint64_t decode_page_offset(uint32_t page_offset);

	c_tag_project& tag_project;

	cache_compiler::s_cache_file_metadata& cache_file_metadata;
	std::vector<char> section_data[4];

	// tag groups

	uint32_t tag_group_count;
	uint32_t tag_groups_buffer_size;
	char* tag_groups_buffer;
	cache_compiler::s_cache_file_tag_group* tag_groups;

	// tag data

	char* tag_data_buffer;
	uint32_t total_tag_data_size;
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
		c_fixed_path path;
	};
	std::vector<s_tag_data_entry> tag_data_entries;

	// tag instances

	char* tag_instances_buffer;
	uint32_t tag_instances_buffer_size;
	uint32_t tag_instance_count;

	char* tag_file_table_buffer;
	uint32_t tag_file_table_buffer_size;
	char* tag_file_table_indices_buffer;
	uint32_t tag_file_table_indices_buffer_size;
	uint32_t tag_file_table_indices_count;

};
