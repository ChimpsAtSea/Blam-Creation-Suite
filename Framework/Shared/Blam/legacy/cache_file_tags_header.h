#pragma once

#define qword uint64_t
#define dword uint32_t
#define word uint16_t

struct s_cache_file_tag_global_instance
{
	uint32_t group_tag;
	long definition_index;
};
static_assert(sizeof(s_cache_file_tag_global_instance) == 0x8);

struct s_cache_file_tag_interop
{
	dword page_address;
	long count;
};

constexpr uint32_t k_cache_file_tags_section_signature = 'tags';

struct s_cache_file_tags_header
{
	template <typename t_type>
	struct s_section
	{
		uint32_t count = 0;
		uint32_t post_count_signature = k_cache_file_tags_section_signature;
		qword address = 0;
	};

	s_section<s_cache_file_tag_group> tag_groups;
	s_section<s_cache_file_tag_instance> tag_instances;
	s_section<s_cache_file_tag_global_instance> tag_global_instance;
	s_section<s_cache_file_tag_interop> tag_interop_table;

	long unknown40; // datum index?

	dword checksum;
	uint32_t signature;

	long unknown4C; // datum index?
};
static_assert(sizeof(s_cache_file_tags_header) == 0x50);
