#pragma once

namespace halo3
{
	struct s_cache_file_header : ::s_cache_file_header
	{
		long __unknown0;
		long __unknown1;
		long __unknown2;
		long __unknown3;

		char source_file[256] = "";
		char build[32] = "";
		c_enum<e_scenario_type, int16_t> scenario_type = _scenario_type_none;
		c_enum<e_scenario_load_type, int16_t> load_type = _scenario_load_none;

		char unknown1 = 0;
		bool tracked_build = false;
		char unknown2 = 0;
		char unknown3 = 0;

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
		
	};

	struct s_cache_file_tag
	{

	};

	struct s_cache_file_tag_group
	{

	};

}
