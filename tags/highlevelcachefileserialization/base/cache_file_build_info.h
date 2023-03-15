#pragma once

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

enum e_cache_file_header_bit
{
	_cache_file_header_bit_use_absolute_addressing,
	_cache_file_header_bit_unknown,
	k_num_cache_file_header_bits,
};

enum e_cache_file_shared_file_type
{
	_shared_file_type_none = NONE,
	_shared_file_type_unknown0,
	_shared_file_type_unknown1,
	_shared_file_type_unknown2,
	k_number_of_shared_file_types = 3
};

struct s_cache_file_build_info
{
	int32_t file_version;
	int32_t file_length;
	int32_t file_compressed_length;
	c_static_string<256> source_file;
	c_static_string<32> build_version;
	c_enum_no_init<e_scenario_type, short> scenario_type;
	c_enum_no_init<e_scenario_load_type, short> scenario_load_type;
	bool tracked_build;
	c_flags_no_init<e_cache_file_header_bit, unsigned char> header_flags;
	c_flags_no_init<e_cache_file_shared_file_type, unsigned char> shared_file_type_flags;
	s_file_last_modification_date timestamp;
	c_static_string<32> name;
	c_static_string<256> relative_path;
	intptr32_t expected_base_address;
	uint32_t xdk_version;
	s_network_http_request_hash hash;
	s_rsa_signature rsa;
};
