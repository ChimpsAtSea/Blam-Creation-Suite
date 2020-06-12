#pragma once

namespace halo3
{
	struct s_cache_file_header
	{
		unsigned long header_signature;

		unsigned long file_version;
		unsigned long file_length;
		unsigned long file_compressed_length;

		unsigned long long tags_header_address;

		unsigned long tag_buffer_offset;
		unsigned long tag_buffer_size;

		char source_file[256];
		char build[32];

		short scenario_type;
		short scenario_shared_type;

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

		unsigned long dependencies;

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

		struct
		{
			unsigned long long virtual_address;
			unsigned long long size;
		} partitions[6];

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


		char __unknown4E4[0x2B14];

		unsigned long __unknown2FFC;
		unsigned long footer_signature;
	};

	struct s_cache_file_tags_header
	{
		template <typename t_type>
		struct s_section
		{
			uint32_t count = 0;
			uint32_t post_count_signature = k_cache_file_tags_section_signature;
			qword address = 0;
		};

		s_section<gen3::s_cache_file_tag_group> tag_groups;
		s_section<gen3::s_cache_file_tag_instance> tag_instances;
		s_section<gen3::s_cache_file_tag_global_instance> tag_global_instance;
		s_section<gen3::s_cache_file_tag_interop> tag_interop_table;

		long : 32;
		unsigned long tags_signature;
	};

}
