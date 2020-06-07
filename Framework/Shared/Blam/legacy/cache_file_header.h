#pragma once

enum e_cache_file_unknown_bits : uint32_t
{
	_unknown_bits_use_absolute_addressing = 1u << 0u,
	_unknown_bits_bit1 = 1u << 1u,
	_unknown_bits_bit2 = 1u << 2u,
	_unknown_bits_bit3 = 1u << 3u,
	_unknown_bits_bit4 = 1u << 4u,
	_unknown_bits_bit5 = 1u << 5u,
	_unknown_bits_bit6 = 1u << 6u,
	_unknown_bits_bit7 = 1u << 7u,
	_unknown_bits_bit8 = 1u << 8u,
	_unknown_bits_bit9 = 1u << 9u,
	_unknown_bits_bit10 = 1u << 10u,
	_unknown_bits_bit11 = 1u << 11u,
	_unknown_bits_bit12 = 1u << 12u,
	_unknown_bits_bit13 = 1u << 13u,
	_unknown_bits_bit14 = 1u << 14u,
	_unknown_bits_bit15 = 1u << 15u,
	_unknown_bits_bit16 = 1u << 16u,
	_unknown_bits_bit17 = 1u << 17u,
	_unknown_bits_bit18 = 1u << 18u,
	_unknown_bits_bit19 = 1u << 19u,
	_unknown_bits_bit20 = 1u << 20u,
	_unknown_bits_bit21 = 1u << 21u,
	_unknown_bits_bit22 = 1u << 22u,
	_unknown_bits_bit23 = 1u << 23u,
	_unknown_bits_bit24 = 1u << 24u,
	_unknown_bits_bit25 = 1u << 25u,
	_unknown_bits_bit26 = 1u << 26u,
	_unknown_bits_bit27 = 1u << 27u,
	_unknown_bits_bit28 = 1u << 28u,
	_unknown_bits_bit29 = 1u << 29u,
	_unknown_bits_bit30 = 1u << 30u,
	_unknown_bits_bit31 = 1u << 31u,

};

enum e_haloreach_cache_file_section_index
{
	_haloreach_cache_file_section_index_debug,
	_haloreach_cache_file_section_index_resource,
	_haloreach_cache_file_section_index_tags,
	_haloreach_cache_file_section_index_localization,
	k_number_of_haloreach_cache_file_sections
};


struct s_haloreach_cache_file_header : s_cache_file_header
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

	// unconfirmed if bitfields, but the first bit changes when the addressing changed
	e_cache_file_unknown_bits unknown_bits = {};

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

	int32_t section_offsets[k_number_of_haloreach_cache_file_sections];
	s_haloreach_cache_file_section_index_file_bounds section_bounds[k_number_of_haloreach_cache_file_sections];

	int32_t guid[4];

	int32_t unknown34[0x26C2];

	e_cache_file_magic footer_signature = _cache_file_magic_footer;
};
static constexpr size_t k_DEPRECATED_reach_cache_file_header_size = sizeof(s_haloreach_cache_file_header);
static_assert(k_DEPRECATED_reach_cache_file_header_size == 0xA000);


struct s_groundhog_cache_file_header : s_cache_file_header
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

	// unconfirmed if bitfields, but the first bit changes when the addressing changed
	e_cache_file_unknown_bits unknown_bits = {};

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