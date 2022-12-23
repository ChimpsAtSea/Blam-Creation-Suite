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
			int32_t file_version;
			int32_t file_length;
			int32_t padding_length; //#TODO: is this not compressed_file_length ?
			int32_t tag_data_offset;
			int32_t tag_data_size;
			int32_t memory_buffer_offset;
			int32_t memory_buffer_size;
			c_static_string<32> scenario_name;
			c_static_string<32> build_version;
			short scenario_type;
			int32_t checksum;
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
			int32_t tag_data_size;
			c_static_string<32> build_version;

			char __data2C8[672];

			int32_t file_version;
			c_static_string<32> scenario_name;

			char __data5AC[4];

			int32_t checksum;

			char __data5B4[52];

			int32_t file_length;
			int32_t tag_data_offset;
			tag footer_signature; // k_cache_footer_signature_halo1_demo

			char __data5F4[524];
		};
		static_assert(sizeof(s_cache_file_header) == 0x800);

#pragma pack(pop)
	}

	struct s_cache_file_tags_header
	{
		uint32_t tag_instances_address;
		uint32_t scenario_datum_index;

		uint32_t checksum;

		uint32_t tag_instance_count;

		int32_t geometry_vertices_count;
		uint32_t geometry_vertices_offset;

		int32_t geometry_indices_count;
		uint32_t geometry_indices_offset;
		int32_t geometry_data_total_size;

		uint32_t tags_signature;
	};
	constexpr size_t k_halo1_cache_file_tags_header_size = sizeof(s_cache_file_tags_header);
	static_assert(k_halo1_cache_file_tags_header_size == 40, "sizeof(s_halo1_cache_file_tags_header) != 0x28");

	struct s_cache_file_tag_instance
	{
		tag group_tags[3];

		uint32_t datum_index;

		uint32_t name_address;
		uint32_t address;

		bool in_data_file;
		char : 8;
		char : 8;
		char : 8;
		int32_t : 32;
	};

	struct s_cache_file_resource_header
	{
		uint32_t type;
		uint32_t tag_names_offset;
		uint32_t tag_data_offset;
		uint32_t tag_instance_count;
	};

	struct s_cache_file_resource_instance
	{
		uint32_t name_address;
		uint32_t size;
		uint32_t address;
	};
}
