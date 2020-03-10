#pragma once

enum e_cache_file_unknown_bits : uint32_t
{
	_unknown_bits_use_absolute_addressing = 1 << 0,
	_unknown_bits_bit1 = 1 << 1,
	_unknown_bits_bit2 = 1 << 2,
	_unknown_bits_bit3 = 1 << 3,
	_unknown_bits_bit4 = 1 << 4,
	_unknown_bits_bit5 = 1 << 5,
	_unknown_bits_bit6 = 1 << 6,
	_unknown_bits_bit7 = 1 << 7,
	_unknown_bits_bit8 = 1 << 8,
	_unknown_bits_bit9 = 1 << 9,
	_unknown_bits_bit10 = 1 << 10,
	_unknown_bits_bit11 = 1 << 11,
	_unknown_bits_bit12 = 1 << 12,
	_unknown_bits_bit13 = 1 << 13,
	_unknown_bits_bit14 = 1 << 14,
	_unknown_bits_bit15 = 1 << 15,
	_unknown_bits_bit16 = 1 << 16,
	_unknown_bits_bit17 = 1 << 17,
	_unknown_bits_bit18 = 1 << 18,
	_unknown_bits_bit19 = 1 << 19,
	_unknown_bits_bit20 = 1 << 20,
	_unknown_bits_bit21 = 1 << 21,
	_unknown_bits_bit22 = 1 << 22,
	_unknown_bits_bit23 = 1 << 23,
	_unknown_bits_bit24 = 1 << 24,
	_unknown_bits_bit25 = 1 << 25,
	_unknown_bits_bit26 = 1 << 26,
	_unknown_bits_bit27 = 1 << 27,
	_unknown_bits_bit28 = 1 << 28,
	_unknown_bits_bit29 = 1 << 29,
	_unknown_bits_bit30 = 1 << 30,
	_unknown_bits_bit31 = 1 << 31,

};

struct s_cache_file_header
{
	e_cache_file_magic header_signature = _cache_file_magic_header;

	int32_t file_version = 12;
	int32_t file_length = 0;
	int32_t file_compressed_length = 0;

	uint64_t tags_header_address = 0;

	int32_t memory_buffer_offset = 0;
	int32_t memory_buffer_size = 0;

	char source_file[256] = "";
	char build[32] = "";
	e_scenario_type scenario_type = _scenario_type_none;
	e_scenario_load_type load_type = _scenario_load_none;

	char unknown1 = 0;
	bool tracked_build = false;
	char unknown2 = 0;
	char unknown3 = 0;

	int32_t unknown4 = 0;
	int32_t unknown5 = 0;
	int32_t unknown6 = 0;
	int32_t unknown7 = 0;
	int32_t unknown8 = 0;

	int32_t string_id_count = 0;
	int32_t string_ids_buffer_size = 0;
	int32_t string_id_indices_offset = 0;
	int32_t string_ids_buffer_offset = 0;

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

	int32_t section_offsets[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];
	s_cache_file_section_file_bounds section_bounds[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];

	int32_t guid[4];

	int32_t unknown34[0x26C2];

	e_cache_file_magic footer_signature = _cache_file_magic_footer;
};
static_assert(sizeof(s_cache_file_header) == 0xA000);

