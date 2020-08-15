#pragma once

namespace gen3
{
	constexpr uint32_t k_cache_file_tags_section_signature = 'tags';

	enum e_cache_file_flags : uint32_t
	{
		_cache_file_flag_use_absolute_addressing = 1u << 0u,
	};

	enum e_cache_file_section_index
	{
		_cache_file_section_index_debug,
		_cache_file_section_index_resource,
		_cache_file_section_index_tags,
		_cache_file_section_index_localization,
		k_number_of_cache_file_sections
	};

	struct s_cache_file_tag_group
	{
		unsigned long group_tags[3];
		unsigned long name;
	};
	static_assert(sizeof(s_cache_file_tag_group) == 0x10);

	struct s_cache_file_tag_instance
	{
		uint16_t group_index;
		uint16_t identifier;
		uint32_t address;
	};
	static_assert(sizeof(s_cache_file_tag_instance) == 0x8);

	struct s_cache_file_tag_global_instance
	{
		uint32_t group_tag;
		long definition_index;
	};
	static_assert(sizeof(s_cache_file_tag_global_instance) == 0x8);

	struct s_cache_file_tag_interop
	{
		dword page_address;
		long count;
	};
	static_assert(sizeof(s_cache_file_tag_interop) == 0x8);

#pragma pack(push, 1)
	struct s_cache_file_header : blamlib::s_cache_file_header
	{
		uint64_t tags_header_address = 0;

		unsigned long tag_buffer_offset;
		unsigned long tag_buffer_size;

		char source_file[256] = "";
		char build[32] = "";

		e_scenario_type scenario_type = _scenario_type_none;
		e_scenario_load_type load_type = _scenario_load_none;

		unsigned char : 8;
		char tracked_build;
		unsigned char : 8;
		unsigned char : 8;

		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;

		unsigned long string_count;
		unsigned long string_table_length;
		unsigned long string_table_indices_offset;
		unsigned long string_table_offset;

		gen3::e_cache_file_flags flags = {};

		time64_t timestamp;
		time64_t scenario_type_timestamps[4];

		char name[32];
		unsigned long __unknown1B8;
		char scenario_path[256];
		long minor_version;

		unsigned long file_count;
		unsigned long file_table_offset;
		unsigned long file_table_length;
		unsigned long file_table_indices_offset;

		unsigned long checksum;

		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;

		unsigned long long virtual_base_address;
		unsigned long xdk_version;
		unsigned long : 32;

		s_basic_buffer64 tag_post_link_buffer = {};
		s_basic_buffer64 tag_language_dependent_read_only_buffer = {};
		s_basic_buffer64 tag_language_dependent_read_write_buffer = {};
		s_basic_buffer64 tag_language_neutral_read_write_buffer = {};
		s_basic_buffer64 tag_language_neutral_write_combined_buffer = {};
		s_basic_buffer64 tag_language_neutral_read_only_buffer = {};

		unsigned long SHA1_A[5];
		unsigned long SHA1_B[5];
		unsigned long SHA1_C[5];
		unsigned long RSA[64];

		unsigned long GUID[4];

		struct
		{
			unsigned long offset_masks[gen3::k_number_of_cache_file_sections];
			struct
			{
				unsigned long offset;
				unsigned long size;
			} sections[gen3::k_number_of_cache_file_sections];
		} section_table;

		int32_t guid[4];
	};
	static constexpr size_t k_gen3_cache_file_header_size = sizeof(s_cache_file_header);
	static_assert(k_gen3_cache_file_header_size == 1268);

	struct s_cache_file_header_v13 : blamlib::s_cache_file_header
	{
		uint64_t tags_header_address = 0;

		unsigned long tag_buffer_offset;
		unsigned long tag_buffer_size;

		char source_file[256] = "";
		char build[32] = "";

		e_scenario_type scenario_type = _scenario_type_none;
		e_scenario_load_type load_type = _scenario_load_none;

		unsigned char : 8;
		char tracked_build;
		unsigned char : 8;
		unsigned char : 8;

		unsigned long : 32;
		unsigned long : 32;

		unsigned long string_count;
		unsigned long string_table_length;
		unsigned long string_table_indices_offset;
		unsigned long string_table_offset;
		unsigned long string_ids_namespace_table_count;
		unsigned long string_ids_namespace_table_offset;

		gen3::e_cache_file_flags flags = {};

		time64_t timestamp;
		time64_t scenario_type_timestamps[4];

		char name[32];
		unsigned long __unknown1B4;
		char scenario_path[256];
		long minor_version;

		unsigned long file_count;
		unsigned long file_table_offset;
		unsigned long file_table_length;
		unsigned long file_table_indices_offset;

		unsigned long checksum;

		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;

		unsigned long long virtual_base_address;
		unsigned long xdk_version;
		unsigned long : 32;

		s_basic_buffer64 tag_post_link_buffer = {};
		s_basic_buffer64 tag_language_dependent_read_only_buffer = {};
		s_basic_buffer64 tag_language_dependent_read_write_buffer = {};
		s_basic_buffer64 tag_language_neutral_read_write_buffer = {};
		s_basic_buffer64 tag_language_neutral_write_combined_buffer = {};
		s_basic_buffer64 tag_language_neutral_read_only_buffer = {};

		unsigned long SHA1_A[5];
		unsigned long SHA1_B[5];
		unsigned long SHA1_C[5];
		unsigned long RSA[64];

		unsigned long GUID[4];

		struct
		{
			unsigned long offset_masks[gen3::k_number_of_cache_file_sections];
			struct
			{
				unsigned long offset;
				unsigned long size;
			} sections[gen3::k_number_of_cache_file_sections];
		} section_table;

		int32_t guid[4];
	};
	static constexpr size_t k_gen3_cache_file_header_v13_size = sizeof(s_cache_file_header_v13);
	static_assert(k_gen3_cache_file_header_v13_size == 1260);
#pragma pack(pop)

	template <typename t_type>
	struct s_section
	{
		uint32_t count = 0;
		uint32_t post_count_signature = k_cache_file_tags_section_signature;
		qword address = 0;
	};
}

