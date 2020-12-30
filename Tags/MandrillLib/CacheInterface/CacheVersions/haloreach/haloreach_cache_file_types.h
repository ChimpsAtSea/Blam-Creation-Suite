#pragma once

namespace haloreach
{

	struct s_cache_file_header : gen3::s_cache_file_header
	{
		int32_t unknown34[0x26C2];

		e_cache_file_magic footer_signature = _cache_file_magic_footer;
	};
	static constexpr size_t k_haloreach_cache_file_header_size = sizeof(s_cache_file_header);
	static_assert(k_haloreach_cache_file_header_size == 0xA000);

#pragma pack(push, 1)
	struct s_cache_file_header_v13
	{
		tag header_signature;
		long file_version;
		long file_length;
		long file_compressed_length;


		uint64_t tags_header_address = 0;

		unsigned long tag_buffer_offset;
		unsigned long tag_buffer_size;

		char source_file[256] = "";
		char build[32] = "";

		e_scenario_type scenario_type = _scenario_type_none;
		e_scenario_load_type load_type = _scenario_load_none;

		unsigned char __unknown0;
		char tracked_build;
		unsigned char __unknown1;
		unsigned char __unknown2;

		unsigned long __unknown3;
		unsigned long __unknown4;

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

		unsigned long __unknown5;
		unsigned long __unknown6;
		unsigned long __unknown7;
		unsigned long __unknown8;
		unsigned long __unknown9;
		unsigned long __unknown10;
		unsigned long __unknown11;
		unsigned long __unknown12;

		unsigned long long virtual_base_address;
		unsigned long xdk_version;
		unsigned long __unknown13;

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
			long offset_masks[gen3::k_number_of_cache_file_sections];
			struct
			{
				long offset;
				long size;
			} sections[gen3::k_number_of_cache_file_sections];
		} section_table;

		int32_t guid[4];


		char _padding[0x9B10];
		tag footer;
	};
#pragma pack(pop)
	static constexpr size_t k_haloreach_cache_file_header_v13_size = sizeof(s_cache_file_header_v13);
	static_assert(k_haloreach_cache_file_header_v13_size == 0xA000);

	struct s_cache_file_tags_header
	{
		gen3::s_section<gen3::s_cache_file_tag_group> tag_groups;
		gen3::s_section<gen3::s_cache_file_tag_instance> tag_instances;
		gen3::s_section<gen3::s_cache_file_tag_global_instance> global_tag_instances;
		gen3::s_section<gen3::s_cache_file_tag_interop> tag_interop_table;
		long : 32;
		dword checksum;
		unsigned long tags_signature;
	};
	static constexpr size_t k_cache_file_tags_header = sizeof(s_cache_file_tags_header);
	static_assert(k_cache_file_tags_header == 0x50);
}
