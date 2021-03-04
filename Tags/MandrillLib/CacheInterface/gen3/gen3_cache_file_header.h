#pragma once

namespace gen3
{
	enum e_scenario_type
	{
		_scenario_type_none = NONE,
		_scenario_type_campaign,
		_scenario_type_multiplayer,
		_scenario_type_mainmenu,
		_scenario_type_shared,
		_scenario_type_shared_campaign,
		_scenario_type_shared_multiplayer,
		k_number_of_scenario_types
	};

	enum e_scenario_load_type
	{
		_scenario_load_none = NONE,
		_scenario_load_default,
		_scenario_load_shared,
		_scenario_load_shared_campaign,
		_scenario_load_shared_multiplayer,
		k_number_of_scenario_load_types
	};

	enum e_map_file_index
	{
		k_total_tracked_cached_map_files_count = 9,
		k_no_cached_map_file_index = -1
	};

	enum e_cache_file_header_bit
	{
		_cache_file_header_bit_use_absolute_addressing, // #NOTE: Appears to be related to loading maps off of a hard drive
		_cache_file_header_bit_unknown,
		k_num_cache_file_header_bits,
	};

	enum e_cache_file_shared_file_type
	{
		_shared_file_type_none = NONE,
		k_number_of_shared_file_types = 3
	};

	enum e_cache_file_section
	{
		_cache_file_section_index_debug,
		_cache_file_section_index_resource,
		_cache_file_section_index_tags,
		_cache_file_section_index_localization,
		k_num_cache_file_section,
	};

	enum e_cache_file_content_hash
	{
		_cache_file_content_hash_tags_language_unknown = 0,
		_cache_file_content_hash_tags_language_dependent = 1,
		_cache_file_content_hash_tags_language_neutral = 2,
		k_num_cache_file_content_hash = 3
	};

	struct s_cache_file_section_file_bounds
	{
		long offset;
		long size;
	};

	struct s_network_http_request_hash
	{
		char SHA1[3][20];
	};

	struct s_rsa_signature
	{
		char data[256];
	};

#pragma pack(push, 4)
	struct s_file_last_modification_date
	{
		long unknown0;
		long unknown4;
	};
#pragma pack(pop)

	struct s_cache_file_insertion_point_resource_usage
	{
		char unknown0[1548];
	};
}
