#pragma once

#define _CHECK_OFFSET_CONCAT1(X,Y) X##Y
#define _CHECK_OFFSET_CONCAT(X,Y) _CHECK_OFFSET_CONCAT1(X,Y)
#define CHECK_OFFSET(_struct, _field, _offset) \
inline void _CHECK_OFFSET_CONCAT(__static_assert_, __LINE__) () \
{ \
	static_assert(offsetof(_struct, _struct::_field) == _offset, #_struct "::" #_field " invalid offset"); \
}

namespace groundhog
{
#pragma pack(push, 1)
	struct s_groundhog_cache_file_header : blamlib::s_cache_file_header
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
		time64_t scenario_type_timestamps[3];

		char name[32];
		unsigned long __unknown1B8;
		char scenario_path[256];
		long minor_version;

		unsigned long file_count;
		unsigned long file_table_offset;
		unsigned long file_table_length;
		unsigned long file_table_indices_offset;

		unsigned long unknown_table_count;
		unsigned long unknown_table_offset;

		unsigned long checksum;

		unsigned long a : 32;
		unsigned long b : 32;
		unsigned long c : 32;
		unsigned long d : 32;
		unsigned long e : 32;
		unsigned long f : 32;
		unsigned long g : 32;


		unsigned long h : 32;
		unsigned long i : 32;
		unsigned long j : 32;
		unsigned long k : 32;

		unsigned long long virtual_base_address;
		unsigned long xdk_version;
		unsigned long l : 32;

		s_basic_buffer64 partitions[6];

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
	static constexpr size_t k_section_table_offset = offsetof(s_groundhog_cache_file_header, section_table);
	static constexpr size_t k_virtual_base_address_offset = offsetof(s_groundhog_cache_file_header, virtual_base_address);
	static constexpr size_t k_xdk_offset = offsetof(s_groundhog_cache_file_header, xdk_version);
	static constexpr size_t k_gen3_groundhog_cache_file_header_size = sizeof(s_groundhog_cache_file_header);
	//static_assert(k_gen3_groundhog_cache_file_header_size == 1260);
#pragma pack(pop)

	struct s_cache_file_header : s_groundhog_cache_file_header
	{
		int32_t unknown34[(0x1E000 - (sizeof(s_groundhog_cache_file_header) + 4)) / 4];

		e_cache_file_magic footer_signature = _cache_file_magic_footer;
	};
	static constexpr size_t k_haloreach_cache_file_header_size = sizeof(s_cache_file_header);
	static_assert(k_haloreach_cache_file_header_size == 0x1E000);

	struct s_cache_file_tags_header
	{
		gen3::s_section<gen3::s_cache_file_tag_group> tag_groups;
		gen3::s_section<gen3::s_cache_file_tag_instance> tag_instances;
		gen3::s_section<gen3::s_cache_file_tag_global_instance> tag_global_instance;
		gen3::s_section<gen3::s_cache_file_tag_interop> tag_interop_table;
		long : 32;
		dword checksum;
		unsigned long tags_signature;
	};
	static constexpr size_t k_cache_file_tags_header = sizeof(s_cache_file_tags_header);
	static_assert(k_cache_file_tags_header == 0x50);
}
