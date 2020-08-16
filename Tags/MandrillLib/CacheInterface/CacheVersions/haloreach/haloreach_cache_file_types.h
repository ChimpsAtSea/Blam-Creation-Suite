#pragma once

namespace haloreach
{

	struct s_cache_file_header : gen3::s_cache_file_header
	{
		int32_t unknown34[0x26C2];

		e_cache_file_magic footer_signature = _cache_file_magic_footer;
	};
	static constexpr size_t k_haloreach_cache_file_header_size = sizeof(s_cache_file_header);
	static_assert(k_haloreach_cache_file_header_size == 0xA000);

	struct s_cache_file_header_v13 : gen3::s_cache_file_header_v13
	{
		int32_t unknown34[0x26C4];

		e_cache_file_magic footer_signature = _cache_file_magic_footer;
	};
	static constexpr size_t k_haloreach_cache_file_header_v13_size = sizeof(s_cache_file_header_v13);
	static_assert(k_haloreach_cache_file_header_v13_size == 0xA000);

	struct s_cache_file_tags_header
	{
		gen3::s_section<gen3::s_cache_file_tag_group> tag_groups;
		gen3::s_section<gen3::s_cache_file_tag_instance> tag_instances;
		gen3::s_section<gen3::s_cache_file_tag_global_instance> tag_global_instance;
		gen3::s_section<gen3::s_cache_file_tag_interop> tag_interop_table;
		long : 32;
		dword checksum;
		unsigned long tags_signature;
	};
	static constexpr size_t k_cache_file_tags_header = sizeof(s_cache_file_tags_header);
	static_assert(k_cache_file_tags_header == 0x50);
}
