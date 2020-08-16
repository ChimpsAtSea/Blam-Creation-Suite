#pragma once

namespace groundhog
{
	struct s_groundhog_cache_file_header : blamlib::s_cache_file_header
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
		c_enum<e_scenario_type, int16_t> scenario_type = _scenario_type_none;	// count of 5
		c_enum<e_scenario_load_type, int16_t> load_type = _scenario_load_none;	// count of 5


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

		gen3::e_cache_file_flags flags = {};

		uint64_t timestamp = 0;
		uint64_t mainmenu_timestamp = 0;
		uint64_t shared_timestamp = 0;
		uint64_t campaign_timestamp = 0;

		char name[32] = "";

		int32_t unknown15 = 0;

		char scenario_path[256] = "";

		int32_t minor_version = 0;


		char unknown10[0x1DD40];

		e_cache_file_magic footer_signature = _cache_file_magic_footer;
	};
	static constexpr size_t k_DEPRECATED_groundhog_cache_file_header_size = sizeof(s_groundhog_cache_file_header);
	static_assert(k_DEPRECATED_groundhog_cache_file_header_size == 0x1E000);

}
