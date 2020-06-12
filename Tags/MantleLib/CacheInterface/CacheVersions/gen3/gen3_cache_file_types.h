#pragma once

namespace gen3
{
	constexpr uint32_t k_cache_file_tags_section_signature = 'tags';

	enum e_cache_file_flags : uint32_t
	{
		_cache_file_flag_use_absolute_addressing = 1u << 0u,
	};

	enum e_cache_file_section_index
	{
		_cache_file_section_index_debug,
		_cache_file_section_index_resource,
		_cache_file_section_index_tags,
		_cache_file_section_index_localization,
		k_number_of_cache_file_sections
	};

	struct s_cache_file_tag_group
	{
		unsigned long group_tags[3];
		unsigned long name;
	};
	static_assert(sizeof(s_cache_file_tag_group) == 0x10);

	struct s_cache_file_tag_instance
	{
		uint16_t group_index;
		uint16_t identifier;
		uint32_t address;
	};
	static_assert(sizeof(s_cache_file_tag_instance) == 0x8);

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
	static_assert(sizeof(s_cache_file_tag_interop) == 0x8);
}


