#pragma once

namespace halo3odst
{
	struct s_cache_file_header : gen3::s_cache_file_header
	{
		char __unknown4E4[0x2B04];

		unsigned long footer_signature;
	};
	static constexpr size_t k_halo3odst_cache_file_header_size = sizeof(s_cache_file_header);
	static_assert(sizeof(s_cache_file_header) == 0x2FFC);

	struct s_cache_file_tags_header
	{
		gen3::s_section<gen3::s_cache_file_tag_group> tag_groups;
		gen3::s_section<gen3::s_cache_file_tag_instance> tag_instances;
		gen3::s_section<gen3::s_cache_file_tag_global_instance> tag_global_instance;
		gen3::s_section<gen3::s_cache_file_tag_interop> tag_interop_table;
		long : 32;
		unsigned long tags_signature;
	};

}
