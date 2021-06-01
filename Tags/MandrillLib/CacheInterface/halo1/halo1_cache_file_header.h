#pragma once

/* ---------- types */

namespace halo1
{
	namespace pc
	{
#pragma pack(push, 4)

		struct s_cache_file_header
		{
			tag header_signature; // k_cache_header_signature
			long file_version;
			long file_length;
			long padding_length; //#TODO: is this not compressed_file_length ?
			long tag_data_offset;
			long tag_data_size;
			long memory_buffer_offset;
			long memory_buffer_size;
			c_static_string<32> scenario_name;
			c_static_string<32> build_version;
			short scenario_type;
			long checksum;
			char _padding68[0x794];
			tag footer_signature; // k_cache_footer_signature
		};
		static_assert(sizeof(s_cache_file_header) == 0x800);

#pragma pack(pop)
	}

	namespace demo
	{
#pragma pack(push, 4)

		struct s_cache_file_header
		{
			char __data0[2];

			short scenario_type;

			char __data4[700];

			tag header_signature; // k_cache_header_signature_halo1_demo
			long tag_data_size;
			c_static_string<32> build_version;

			char __data2C8[672];

			long file_version;
			c_static_string<32> scenario_name;

			char __data5AC[4];

			long checksum;

			char __data5B4[52];

			long file_length;
			long tag_data_offset;
			tag footer_signature; // k_cache_footer_signature_halo1_demo

			char __data5F4[524];
		};
		static_assert(sizeof(s_cache_file_header) == 0x800);

#pragma pack(pop)
	}

	struct s_cache_file_tags_header
	{
		unsigned long tag_instances_address;
		unsigned long scenario_datum_index;

		unsigned long checksum;

		long tag_instance_count;

		long geometry_vertices_count;
		unsigned long geometry_vertices_offset;

		long geometry_indices_count;
		unsigned long geometry_indices_offset;
		long geometry_data_total_size;

		unsigned long tags_signature;
	};
	constexpr size_t k_halo1_cache_file_tags_header_size = sizeof(s_cache_file_tags_header);
	static_assert(k_halo1_cache_file_tags_header_size == 40, "sizeof(s_halo1_cache_file_tags_header) != 0x28");

	struct s_cache_file_tag_instance
	{
		tag group_tags[3];

		unsigned long datum_index;

		unsigned long name_address;
		unsigned long address;

		bool in_data_file;
		char : 8;
		char : 8;
		char : 8;
		long : 32;
	};

	struct s_cache_file_resource_header
	{
		unsigned long type;
		unsigned long tag_names_offset;
		unsigned long tag_data_offset;
		unsigned long tag_instance_count;
	};

	struct s_cache_file_resource_instance
	{
		unsigned long name_address;
		unsigned long size;
		unsigned long address;
	};
}
