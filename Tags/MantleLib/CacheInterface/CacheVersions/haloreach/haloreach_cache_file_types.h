#pragma once

namespace haloreach
{
	struct s_cache_file_section_index_file_bounds
	{
		long offset;
		long size;
	};

	struct s_haloreach_cache_file_header : blamlib::s_cache_file_header
	{
		//e_cache_file_magic header_signature = _cache_file_magic_header;
		//int32_t file_version = 12;
		//int32_t file_length = 0;
		//int32_t file_compressed_length = 0;

		uint64_t tags_header_address = 0;

		int32_t memory_buffer_offset = 0;
		int32_t memory_buffer_size = 0;

		char source_file[256] = "";
		char build[32] = "";
		c_enum<e_scenario_type, int16_t> scenario_type = _scenario_type_none;
		c_enum<e_scenario_load_type, int16_t> load_type = _scenario_load_none;


		char unknown1 = 0;
		bool tracked_build = false;
		char unknown2 = 0;
		char unknown3 = 0;

		int32_t unknown4 = 0;
		int32_t unknown5 = 0;
		int32_t unknown6 = 0;
		int32_t unknown7 = 0;
		int32_t unknown8 = 0;

		uint32_t string_id_count = 0;
		uint32_t string_ids_buffer_size = 0;
		uint32_t string_id_indices_offset = 0;
		uint32_t string_ids_buffer_offset = 0;

		gen3::e_cache_file_flags unknown_bits = {};

		uint64_t timestamp = 0;
		uint64_t mainmenu_timestamp = 0;
		uint64_t shared_timestamp = 0;
		uint64_t campaign_timestamp = 0;
		uint64_t multiplayer_timestamp = 0;

		char name[32] = "";

		int32_t unknown15 = 0;

		char scenario_path[256] = "";

		int32_t minor_version = 0;

		int32_t tag_name_count = 0;
		int32_t tag_names_buffer_offset = 0;
		int32_t tag_names_buffer_size = 0;
		int32_t tag_name_indices_offset = 0;

		uint32_t checksum = 0;

		int32_t unknown17 = 0;
		int32_t unknown18 = 0;
		int32_t unknown19 = 0;
		int32_t unknown20 = 0;
		int32_t unknown21 = 0;
		int32_t unknown22 = 0;
		int32_t unknown23 = 0;
		int32_t unknown24 = 0;
		int32_t unknown25 = 0;

		uint64_t virtual_base_address = 0;

		uint32_t xdk_version = 0;
		int32_t unknown26 = 0;

		s_basic_buffer tag_post_link_buffer = {};
		s_basic_buffer tag_language_dependent_read_only_buffer = {};
		s_basic_buffer tag_language_dependent_read_write_buffer = {};
		s_basic_buffer tag_language_neutral_read_write_buffer = {};
		s_basic_buffer tag_language_neutral_write_combined_buffer = {};
		s_basic_buffer tag_language_neutral_read_only_buffer = {};

		uint64_t unknown29 = 0;
		uint64_t unknown30 = 0;

		int32_t sha1_a[5];
		int32_t sha1_b[5];
		int32_t sha1_c[5];

		int32_t rsa[64];

		int32_t section_offsets[gen3::k_number_of_cache_file_sections];
		s_cache_file_section_index_file_bounds section_bounds[gen3::k_number_of_cache_file_sections];

		int32_t guid[4];

		int32_t unknown34[0x26C2];

		e_cache_file_magic footer_signature = _cache_file_magic_footer;
	};
	static constexpr size_t k_haloreach_cache_file_header_size = sizeof(s_haloreach_cache_file_header);
	static_assert(k_haloreach_cache_file_header_size == 0xA000);

	struct s_cache_file_tags_header
	{
		template <typename t_type>
		struct s_section
		{
			uint32_t count = 0;
			uint32_t post_count_signature = k_cache_file_tags_section_signature;
			qword address = 0;
		};

		s_section<gen3::s_cache_file_tag_group> tag_groups;
		s_section<gen3::s_cache_file_tag_instance> tag_instances;
		s_section<gen3::s_cache_file_tag_global_instance> tag_global_instance;
		s_section<gen3::s_cache_file_tag_interop> tag_interop_table;

		long unknown40; // datum index?

		dword checksum;
		uint32_t signature;

		long unknown4C; // datum index?
	};
	static_assert(sizeof(s_cache_file_tags_header) == 0x50);
}
