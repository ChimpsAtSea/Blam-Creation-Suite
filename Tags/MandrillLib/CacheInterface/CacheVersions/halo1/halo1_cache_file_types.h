#pragma once

namespace halo1
{
	enum class e_cache_file_version : long
	{
		_invalid = 0,

		_halo_xbox = 5,
		_halo_pc = 7,
		_halo_2 = 8,
		_halo_3_beta = 9,
		_halo_3 = 11,
		_halo_reach = 12,
		_halo_online = 18,
		_halo_custom_edition = 609
	};

	enum class e_cache_file_type : short
	{
		_none = -1,

		_campaign,
		_multiplayer,
		_main_menu,
		_shared,
		_shared_campaign,
		_unknown5,
		_unknown6,

		k_number_of_cache_file_types
	};

	enum class e_cache_file_shared_type : short
	{
		_none = -1,
		_main_menu,
		_shared,
		_campaign,

		k_number_of_cache_file_shared_types
	};

	struct s_cache_file_header
	{
		unsigned long header_signature;                 // 'head'
		e_cache_file_version file_version;
		long file_length;
		long file_compressed_length;
		unsigned long tags_header_address;
		long tag_data_size;
		long memory_buffer_offset;
		long memory_buffer_size;
		char name[32];
		char build[32];
		e_cache_file_type scenario_type;
		e_cache_file_shared_type shared_type;
		unsigned long __unknown64;                      // unknown
		char __unknown68[1940];                         // unknown padding?
		unsigned long footer_signature;                 // 'foot'
	};

	struct datum_index
	{
		short index;
		short identifier;
	};

	struct s_cache_file_tag_instance
	{
		unsigned long group_tags[3];                    // group, parent, grandparent
		datum_index handle;                             // salt, index

		unsigned long name_address;                     // offset to string, ptr32_t<char> name
		unsigned long base_address;                     // offset to data, union { ptr32_t<void> base_address; long index_in_data_file };

		bool bool_in_data_file;
		char : 8;
		char : 8;
		char : 8;

		long : 32;
	};

	struct s_cache_file_tags_header
	{
		unsigned long tags_address;                     // ptr32_t<void>, 0x40448028, g_tags_address is 0x40448000
		long scenario_index;
		unsigned long checksum;
		unsigned long tag_count;
		unsigned long geometry_vertices_count;
		unsigned long geometry_vertices_offset;
		unsigned long geometry_indices_count;
		unsigned long geometry_indices_offset;
		unsigned long geometry_data_total_size;
		unsigned long signature;                        // 'tags'
	};
}
