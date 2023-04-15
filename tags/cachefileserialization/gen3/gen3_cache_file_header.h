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
	BCS_SHARED extern BCS_RESULT gen3_scenario_type_to_base_scenario_type(e_scenario_type gen3_scenario_type, ::e_scenario_type& base_scenario_type);
	BCS_SHARED extern BCS_RESULT base_scenario_type_to_gen3_scenario_type(::e_scenario_type base_scenario_type, e_scenario_type& gen3_scenario_type);

	enum e_scenario_load_type
	{
		_scenario_load_none = NONE,
		_scenario_load_default,
		_scenario_load_shared,
		_scenario_load_shared_campaign,
		_scenario_load_shared_multiplayer,
		k_number_of_scenario_load_types
	};
	BCS_SHARED extern BCS_RESULT gen3_scenario_load_type_to_base_scenario_load_type(e_scenario_load_type gen3_scenario_load_type, ::e_scenario_load_type& base_scenario_load_type);
	BCS_SHARED extern BCS_RESULT base_scenario_load_type_to_gen3_scenario_load_type(::e_scenario_load_type base_scenario_load_type, e_scenario_load_type& gen3_scenario_load_type);

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
	template<typename t_gen3_storage, typename t_base_storage>
	inline BCS_RESULT gen3_cache_file_header_flags_to_base_cache_file_header_flags(
		c_flags_no_init<gen3::e_cache_file_header_bit, t_gen3_storage, k_num_cache_file_header_bits> const& gen3_cache_file_header_flags,
		c_flags_no_init<::e_cache_file_header_bit, t_base_storage, ::k_num_cache_file_header_bits>& base_cache_file_header_flags)
	{
		base_cache_file_header_flags.clear();
		base_cache_file_header_flags.set(::_cache_file_header_bit_use_absolute_addressing, gen3_cache_file_header_flags.test(_cache_file_header_bit_use_absolute_addressing));
		base_cache_file_header_flags.set(::_cache_file_header_bit_unknown, gen3_cache_file_header_flags.test(_cache_file_header_bit_unknown));
		return BCS_S_OK;
	}
	template<typename t_gen3_storage, typename t_base_storage>
	inline BCS_RESULT base_cache_file_header_flags_to_gen3_cache_file_header_flags(
		c_flags_no_init<::e_cache_file_header_bit, t_base_storage, ::k_num_cache_file_header_bits> const& base_cache_file_header_flags,
		c_flags_no_init<gen3::e_cache_file_header_bit, t_gen3_storage, k_num_cache_file_header_bits> & gen3_cache_file_header_flags)
	{
		gen3_cache_file_header_flags.clear();
		gen3_cache_file_header_flags.set(::_cache_file_header_bit_use_absolute_addressing, base_cache_file_header_flags.test(_cache_file_header_bit_use_absolute_addressing));
		gen3_cache_file_header_flags.set(::_cache_file_header_bit_unknown, base_cache_file_header_flags.test(_cache_file_header_bit_unknown));
		return BCS_S_OK;
	}

	enum e_cache_file_shared_file_type
	{
		_shared_file_type_none = NONE,
		_shared_file_type_unknown0,
		_shared_file_type_unknown1,
		_shared_file_type_unknown2,
		k_number_of_shared_file_types
	};
	BCS_SHARED extern BCS_RESULT gen3_cache_file_shared_file_type_to_base_cache_file_shared_file_type(e_cache_file_shared_file_type gen3_cache_file_shared_file_type, ::e_cache_file_shared_file_type& base_cache_file_shared_file_type);
	BCS_SHARED extern BCS_RESULT base_cache_file_shared_file_type_to_gen3_cache_file_shared_file_type(::e_cache_file_shared_file_type base_cache_file_shared_file_type, e_cache_file_shared_file_type& gen3_cache_file_shared_file_type);

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
		int32_t offset;
		int32_t size;
	};

	struct s_cache_file_insertion_point_resource_usage
	{
		char unknown0[1548];
	};
}
