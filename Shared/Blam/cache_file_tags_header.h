#pragma once

#define tag uint32_t
#define qword uint64_t
#define dword uint32_t
#define word uint16_t

struct s_cache_file_tag_global_instance
{
	tag group_tag;
	long definition_index;
};
static_assert(sizeof(s_cache_file_tag_global_instance) == 0x8);

struct s_cache_file_tag_interop
{
	dword page_address;
	long count;
};

struct s_cache_file_tags_header
{
	template <typename t_type>
	struct s_section
	{
		uint32_t count = 0;
		tag post_count_signature = k_cache_file_tags_section_signature;
		qword address = 0;
	};

	s_section<s_cache_file_tag_group> groups;
	s_section<s_cache_file_tag_instance> instances;
	s_section<s_cache_file_tag_global_instance> global_instances;
	s_section<s_cache_file_tag_interop> interop_table;

	long unknown40; // datum index?

	dword checksum;
	tag signature;

	long unknown4C; // datum index?
};
static_assert(sizeof(s_cache_file_tags_header) == 0x50);
