#pragma once

struct nicename("cache_file_resource_gestalt") group('zone') s_cache_file_resource_gestalt_definition
{
	enum nicename("Map Type") e_map_type : uint16_t
	{
		/*nicename("Single Player")*/ _map_type_single_player = 0ui16,
		/*nicename("Multiplayer")*/ _map_type_multiplayer = 1ui16,
		/*nicename("Main Menu")*/ _map_type_main_menu = 2ui16,
	};

	struct nicename("Resource Types") s_resource_types_definition
	{
		signed char nicename("Guid") guid[16];
		int16_t __unknown0;
		int16_t __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		string_id nicename("Name") name;
	};

	struct nicename("Resource Structure Types") s_resource_structure_types_definition
	{
		signed char nicename("Guid") guid[16];
		string_id nicename("Name") name;
	};

	struct nicename("Compression Codecs") s_compression_codecs_definition
	{
		signed char nicename("Guid") guid[16];
	};

	struct nicename("External Cache References") s_external_cache_references_definition
	{
		char nicename("Map Path") map_path[256];
		int16_t __unknown0;
		int16_t __unknown1;
		Undefined32 __unknown2;
	};

	struct nicename("Raw Pages") s_raw_pages_definition
	{
		int16_t nicename("Salt") salt;
		int8_t nicename("Flags") flags;
		int8_t nicename("Compression Codec Index") compression_codec_index;
		int16_t nicename("Shared Cache Index") shared_cache_index;
		int16_t __unknown0;
		// Blocks : Blocks are stored in the raw table, at the beginning of the map, and compressed using deflate.
		int32_t nicename("Block Offset") block_offset;
		int32_t nicename("Compressed Block Size") compressed_block_size;
		int32_t nicename("Uncompressed Block Size") uncompressed_block_size;
		int32_t nicename("CRC Checksum") crc_checksum;
		signed char nicename("Entire Buffer Hash") entire_buffer_hash[20];
		signed char nicename("First Chunk Hash") first_chunk_hash[20];
		signed char nicename("Last Chunk Hash") last_chunk_hash[20];
		int16_t nicename("Block Asset Count?") block_asset_count;
		int16_t __unknown1;
	};

	struct nicename("Sizes") s_sizes_definition
	{
		struct nicename("Parts") s_parts_definition
		{
			int32_t __unknown0;
			int32_t nicename("Size") size;
		};

		int32_t nicename("Overall Size") overall_size;
		s_tag_block_definition<s_parts_definition> nicename("Parts") parts_block;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		int32_t __unknown0;
		int32_t __unknown1;
		int32_t __unknown2;
	};

	struct nicename("Segments") s_segments_definition
	{
		int16_t nicename("Primary Page Index") primary_page_index;
		int16_t nicename("Secondary Page Index") secondary_page_index;
		int32_t nicename("Primary Segment Offset") primary_segment_offset;
		int32_t nicename("Secondary Segment Offset") secondary_segment_offset;
		int16_t nicename("Primary Size Index") primary_size_index;
		int16_t nicename("Secondary Size Index") secondary_size_index;
	};

	struct nicename("Tag Resources") s_tag_resources_definition
	{
		enum nicename("Root Definition Address Location/High Bits") b_root_definition_address_location_high_bits : uint8_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _root_definition_address_location_high_bits_bit_0 = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _root_definition_address_location_high_bits_bit_1 = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _root_definition_address_location_high_bits_bit_2 = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _root_definition_address_location_high_bits_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _root_definition_address_location_high_bits_bit_4 = 1ui8 << 4ui8,
			/*nicename("Fixup")*/ _root_definition_address_location_high_bits_fixup = 1ui8 << 5ui8,
			/*nicename("Raw Page")*/ _root_definition_address_location_high_bits_raw_page = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _root_definition_address_location_high_bits_bit_7 = 1ui8 << 7ui8,
		};

		struct nicename("Resource Fixups") s_resource_fixups_definition
		{
			enum nicename("Address Location/High Bits") b_address_location_high_bits : uint8_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _address_location_high_bits_bit_0 = 1ui8 << 0ui8,
				/*nicename("Bit 1")*/ _address_location_high_bits_bit_1 = 1ui8 << 1ui8,
				/*nicename("Bit 2")*/ _address_location_high_bits_bit_2 = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _address_location_high_bits_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _address_location_high_bits_bit_4 = 1ui8 << 4ui8,
				/*nicename("Fixup")*/ _address_location_high_bits_fixup = 1ui8 << 5ui8,
				/*nicename("Raw Page")*/ _address_location_high_bits_raw_page = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _address_location_high_bits_bit_7 = 1ui8 << 7ui8,
			};

			/* Members : Block Offset: [offset in tag data sub-buffer].
			   Address: fix-up address (either in the data sub-buffer, or a cache-resource offset. */
			int32_t nicename("Block Offset") block_offset;
			b_address_location_high_bits nicename("Address Location/High Bits") address_location_high_bits;
			uint8_t nicename("Address Upper Bits") address_upper_bits;
			uint16_t nicename("Address") address;
		};

		struct nicename("Resource Definition Fixups") s_resource_definition_fixups_definition
		{
			enum nicename("Offset Location/High Bits") b_offset_location_high_bits : uint8_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _offset_location_high_bits_bit_0 = 1ui8 << 0ui8,
				/*nicename("Bit 1")*/ _offset_location_high_bits_bit_1 = 1ui8 << 1ui8,
				/*nicename("Bit 2")*/ _offset_location_high_bits_bit_2 = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _offset_location_high_bits_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _offset_location_high_bits_bit_4 = 1ui8 << 4ui8,
				/*nicename("Fixup")*/ _offset_location_high_bits_fixup = 1ui8 << 5ui8,
				/*nicename("Raw Page")*/ _offset_location_high_bits_raw_page = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _offset_location_high_bits_bit_7 = 1ui8 << 7ui8,
			};

			b_offset_location_high_bits nicename("Offset Location/High Bits") offset_location_high_bits;
			uint8_t nicename("Offset Upper Bits") offset_upper_bits;
			uint16_t nicename("Offset") offset;
			int32_t nicename("Resource Structure Type Index") resource_structure_type_index;
		};

		TagReference nicename("Parent Tag") parent_tag_reference;
		uint16_t nicename("Salt") salt;
		uint8_t nicename("Resource Type Index") resource_type_index;
		uint8_t nicename("Flags") flags;
		int32_t nicename("Fixup Information Offset") fixup_information_offset;
		int32_t nicename("Fixup Information Length") fixup_information_length;
		int32_t nicename("Secondary Fixup Information Offset") secondary_fixup_information_offset;
		int16_t __unknown0;
		int16_t nicename("[play] Segment Index") play_segment_index;
		b_root_definition_address_location_high_bits nicename("Root Definition Address Location/High Bits") root_definition_address_location_high_bits;
		uint8_t nicename("Root Definition Address Upper Bits") root_definition_address_upper_bits;
		uint16_t nicename("Root Definition Address") root_definition_address;
		s_tag_block_definition<s_resource_fixups_definition> nicename("Resource Fixups") resource_fixups_block;
		s_tag_block_definition<s_resource_definition_fixups_definition> nicename("Resource Definition Fixups") resource_definition_fixups_block;
	};

	struct nicename("Designer Zonesets") s_designer_zonesets_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types1_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_2_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types1_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("Global Zoneset") s_global_zoneset_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool1_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool1_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_21_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types2_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool1_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool1_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool1_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool1_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_21_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types2_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool1_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool1_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("Unattached Zoneset") s_unattached_zoneset_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool2_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool2_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_22_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types3_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool2_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool2_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool2_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool2_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_22_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types3_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool2_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool2_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("Disc-Forbidden Zoneset") s_disc_forbidden_zoneset_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool3_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool3_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_23_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types4_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool3_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool3_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool3_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool3_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_23_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types4_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool3_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool3_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("Disc-Always-Streaming Zoneset") s_disc_always_streaming_zoneset_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool4_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool4_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_24_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types5_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool4_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool4_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool4_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool4_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_24_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types5_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool4_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool4_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("BSP Zonesets") s_bsp_zonesets_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool5_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool5_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_25_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types6_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool5_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool5_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool5_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool5_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_25_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types6_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool5_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool5_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("BSP Zonesets 2") s_bsp_zonesets_2_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool6_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool6_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_26_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types7_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool6_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool6_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool6_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool6_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_26_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types7_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool6_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool6_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("BSP Zonesets 3") s_bsp_zonesets_3_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool7_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool7_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_27_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types8_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool7_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool7_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool7_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool7_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_27_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types8_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool7_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool7_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("Cinematic Zonesets") s_cinematic_zonesets_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool8_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool8_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_28_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types9_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool8_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool8_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool8_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool8_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_28_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types9_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool8_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool8_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("Scenario Zonesets") s_scenario_zonesets_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool9_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool") s_optional_raw_pool9_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_29_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Resource Types") s_resource_types10_definition
		{
			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Required Tag Pool") s_required_tag_pool9_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		struct nicename("Optional Tag Pool") s_optional_tag_pool9_definition
		{
			enum nicename("Active Members") b_active_members : uint32_t /* bitfield */
			{
				/*nicename("0")*/ _active_members__0 = 1ui32 << 0ui32,
				/*nicename("1")*/ _active_members__1 = 1ui32 << 1ui32,
				/*nicename("2")*/ _active_members__2 = 1ui32 << 2ui32,
				/*nicename("3")*/ _active_members__3 = 1ui32 << 3ui32,
				/*nicename("4")*/ _active_members__4 = 1ui32 << 4ui32,
				/*nicename("5")*/ _active_members__5 = 1ui32 << 5ui32,
				/*nicename("6")*/ _active_members__6 = 1ui32 << 6ui32,
				/*nicename("7")*/ _active_members__7 = 1ui32 << 7ui32,
				/*nicename("8")*/ _active_members__8 = 1ui32 << 8ui32,
				/*nicename("9")*/ _active_members__9 = 1ui32 << 9ui32,
				/*nicename("10")*/ _active_members__10 = 1ui32 << 10ui32,
				/*nicename("11")*/ _active_members__11 = 1ui32 << 11ui32,
				/*nicename("12")*/ _active_members__12 = 1ui32 << 12ui32,
				/*nicename("13")*/ _active_members__13 = 1ui32 << 13ui32,
				/*nicename("14")*/ _active_members__14 = 1ui32 << 14ui32,
				/*nicename("15")*/ _active_members__15 = 1ui32 << 15ui32,
				/*nicename("16")*/ _active_members__16 = 1ui32 << 16ui32,
				/*nicename("17")*/ _active_members__17 = 1ui32 << 17ui32,
				/*nicename("18")*/ _active_members__18 = 1ui32 << 18ui32,
				/*nicename("19")*/ _active_members__19 = 1ui32 << 19ui32,
				/*nicename("20")*/ _active_members__20 = 1ui32 << 20ui32,
				/*nicename("21")*/ _active_members__21 = 1ui32 << 21ui32,
				/*nicename("22")*/ _active_members__22 = 1ui32 << 22ui32,
				/*nicename("23")*/ _active_members__23 = 1ui32 << 23ui32,
				/*nicename("24")*/ _active_members__24 = 1ui32 << 24ui32,
				/*nicename("25")*/ _active_members__25 = 1ui32 << 25ui32,
				/*nicename("26")*/ _active_members__26 = 1ui32 << 26ui32,
				/*nicename("27")*/ _active_members__27 = 1ui32 << 27ui32,
				/*nicename("28")*/ _active_members__28 = 1ui32 << 28ui32,
				/*nicename("29")*/ _active_members__29 = 1ui32 << 29ui32,
				/*nicename("30")*/ _active_members__30 = 1ui32 << 30ui32,
				/*nicename("31")*/ _active_members__31 = 1ui32 << 31ui32,
			};

			b_active_members nicename("Active Members") active_members;
		};

		s_tag_block_definition<s_required_raw_pool9_definition> nicename("Required Raw Pool") required_raw_pool_block;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_optional_raw_pool9_definition> nicename("Optional Raw Pool") optional_raw_pool_block;
		s_tag_block_definition<s_optional_raw_pool_29_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block;
		string_id nicename("Set Name") set_name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_resource_types10_definition> nicename("Resource Types") resource_types_block;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		s_tag_block_definition<s_required_tag_pool9_definition> nicename("Required Tag Pool") required_tag_pool_block;
		s_tag_block_definition<s_optional_tag_pool9_definition> nicename("Optional Tag Pool") optional_tag_pool_block;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("Scenario Zoneset Groups") s_scenario_zoneset_groups_definition
	{
		enum nicename("Import Loaded BSPs") b_import_loaded_bsps : uint32_t /* bitfield */
		{
			/*nicename("BSP 0")*/ _import_loaded_bsps_bsp_0 = 1ui32 << 0ui32,
			/*nicename("BSP 1")*/ _import_loaded_bsps_bsp_1 = 1ui32 << 1ui32,
			/*nicename("BSP 2")*/ _import_loaded_bsps_bsp_2 = 1ui32 << 2ui32,
			/*nicename("BSP 3")*/ _import_loaded_bsps_bsp_3 = 1ui32 << 3ui32,
			/*nicename("BSP 4")*/ _import_loaded_bsps_bsp_4 = 1ui32 << 4ui32,
			/*nicename("BSP 5")*/ _import_loaded_bsps_bsp_5 = 1ui32 << 5ui32,
			/*nicename("BSP 6")*/ _import_loaded_bsps_bsp_6 = 1ui32 << 6ui32,
			/*nicename("BSP 7")*/ _import_loaded_bsps_bsp_7 = 1ui32 << 7ui32,
			/*nicename("BSP 8")*/ _import_loaded_bsps_bsp_8 = 1ui32 << 8ui32,
			/*nicename("BSP 9")*/ _import_loaded_bsps_bsp_9 = 1ui32 << 9ui32,
			/*nicename("BSP 10")*/ _import_loaded_bsps_bsp_10 = 1ui32 << 10ui32,
			/*nicename("BSP 11")*/ _import_loaded_bsps_bsp_11 = 1ui32 << 11ui32,
			/*nicename("BSP 12")*/ _import_loaded_bsps_bsp_12 = 1ui32 << 12ui32,
			/*nicename("BSP 13")*/ _import_loaded_bsps_bsp_13 = 1ui32 << 13ui32,
			/*nicename("BSP 14")*/ _import_loaded_bsps_bsp_14 = 1ui32 << 14ui32,
			/*nicename("BSP 15")*/ _import_loaded_bsps_bsp_15 = 1ui32 << 15ui32,
			/*nicename("BSP 16")*/ _import_loaded_bsps_bsp_16 = 1ui32 << 16ui32,
			/*nicename("BSP 17")*/ _import_loaded_bsps_bsp_17 = 1ui32 << 17ui32,
			/*nicename("BSP 18")*/ _import_loaded_bsps_bsp_18 = 1ui32 << 18ui32,
			/*nicename("BSP 19")*/ _import_loaded_bsps_bsp_19 = 1ui32 << 19ui32,
			/*nicename("BSP 20")*/ _import_loaded_bsps_bsp_20 = 1ui32 << 20ui32,
			/*nicename("BSP 21")*/ _import_loaded_bsps_bsp_21 = 1ui32 << 21ui32,
			/*nicename("BSP 22")*/ _import_loaded_bsps_bsp_22 = 1ui32 << 22ui32,
			/*nicename("BSP 23")*/ _import_loaded_bsps_bsp_23 = 1ui32 << 23ui32,
			/*nicename("BSP 24")*/ _import_loaded_bsps_bsp_24 = 1ui32 << 24ui32,
			/*nicename("BSP 25")*/ _import_loaded_bsps_bsp_25 = 1ui32 << 25ui32,
			/*nicename("BSP 26")*/ _import_loaded_bsps_bsp_26 = 1ui32 << 26ui32,
			/*nicename("BSP 27")*/ _import_loaded_bsps_bsp_27 = 1ui32 << 27ui32,
			/*nicename("BSP 28")*/ _import_loaded_bsps_bsp_28 = 1ui32 << 28ui32,
			/*nicename("BSP 29")*/ _import_loaded_bsps_bsp_29 = 1ui32 << 29ui32,
			/*nicename("BSP 30")*/ _import_loaded_bsps_bsp_30 = 1ui32 << 30ui32,
			/*nicename("BSP 31")*/ _import_loaded_bsps_bsp_31 = 1ui32 << 31ui32,
		};

		enum nicename("Loaded BSPs") b_loaded_bsps : uint32_t /* bitfield */
		{
			/*nicename("BSP 0")*/ _loaded_bsps_bsp_0 = 1ui32 << 0ui32,
			/*nicename("BSP 1")*/ _loaded_bsps_bsp_1 = 1ui32 << 1ui32,
			/*nicename("BSP 2")*/ _loaded_bsps_bsp_2 = 1ui32 << 2ui32,
			/*nicename("BSP 3")*/ _loaded_bsps_bsp_3 = 1ui32 << 3ui32,
			/*nicename("BSP 4")*/ _loaded_bsps_bsp_4 = 1ui32 << 4ui32,
			/*nicename("BSP 5")*/ _loaded_bsps_bsp_5 = 1ui32 << 5ui32,
			/*nicename("BSP 6")*/ _loaded_bsps_bsp_6 = 1ui32 << 6ui32,
			/*nicename("BSP 7")*/ _loaded_bsps_bsp_7 = 1ui32 << 7ui32,
			/*nicename("BSP 8")*/ _loaded_bsps_bsp_8 = 1ui32 << 8ui32,
			/*nicename("BSP 9")*/ _loaded_bsps_bsp_9 = 1ui32 << 9ui32,
			/*nicename("BSP 10")*/ _loaded_bsps_bsp_10 = 1ui32 << 10ui32,
			/*nicename("BSP 11")*/ _loaded_bsps_bsp_11 = 1ui32 << 11ui32,
			/*nicename("BSP 12")*/ _loaded_bsps_bsp_12 = 1ui32 << 12ui32,
			/*nicename("BSP 13")*/ _loaded_bsps_bsp_13 = 1ui32 << 13ui32,
			/*nicename("BSP 14")*/ _loaded_bsps_bsp_14 = 1ui32 << 14ui32,
			/*nicename("BSP 15")*/ _loaded_bsps_bsp_15 = 1ui32 << 15ui32,
			/*nicename("BSP 16")*/ _loaded_bsps_bsp_16 = 1ui32 << 16ui32,
			/*nicename("BSP 17")*/ _loaded_bsps_bsp_17 = 1ui32 << 17ui32,
			/*nicename("BSP 18")*/ _loaded_bsps_bsp_18 = 1ui32 << 18ui32,
			/*nicename("BSP 19")*/ _loaded_bsps_bsp_19 = 1ui32 << 19ui32,
			/*nicename("BSP 20")*/ _loaded_bsps_bsp_20 = 1ui32 << 20ui32,
			/*nicename("BSP 21")*/ _loaded_bsps_bsp_21 = 1ui32 << 21ui32,
			/*nicename("BSP 22")*/ _loaded_bsps_bsp_22 = 1ui32 << 22ui32,
			/*nicename("BSP 23")*/ _loaded_bsps_bsp_23 = 1ui32 << 23ui32,
			/*nicename("BSP 24")*/ _loaded_bsps_bsp_24 = 1ui32 << 24ui32,
			/*nicename("BSP 25")*/ _loaded_bsps_bsp_25 = 1ui32 << 25ui32,
			/*nicename("BSP 26")*/ _loaded_bsps_bsp_26 = 1ui32 << 26ui32,
			/*nicename("BSP 27")*/ _loaded_bsps_bsp_27 = 1ui32 << 27ui32,
			/*nicename("BSP 28")*/ _loaded_bsps_bsp_28 = 1ui32 << 28ui32,
			/*nicename("BSP 29")*/ _loaded_bsps_bsp_29 = 1ui32 << 29ui32,
			/*nicename("BSP 30")*/ _loaded_bsps_bsp_30 = 1ui32 << 30ui32,
			/*nicename("BSP 31")*/ _loaded_bsps_bsp_31 = 1ui32 << 31ui32,
		};

		enum nicename("Loaded Designer Zonesets") b_loaded_designer_zonesets : uint32_t /* bitfield */
		{
			/*nicename("Set 0")*/ _loaded_designer_zonesets_set_0 = 1ui32 << 0ui32,
			/*nicename("Set 1")*/ _loaded_designer_zonesets_set_1 = 1ui32 << 1ui32,
			/*nicename("Set 2")*/ _loaded_designer_zonesets_set_2 = 1ui32 << 2ui32,
			/*nicename("Set 3")*/ _loaded_designer_zonesets_set_3 = 1ui32 << 3ui32,
			/*nicename("Set 4")*/ _loaded_designer_zonesets_set_4 = 1ui32 << 4ui32,
			/*nicename("Set 5")*/ _loaded_designer_zonesets_set_5 = 1ui32 << 5ui32,
			/*nicename("Set 6")*/ _loaded_designer_zonesets_set_6 = 1ui32 << 6ui32,
			/*nicename("Set 7")*/ _loaded_designer_zonesets_set_7 = 1ui32 << 7ui32,
			/*nicename("Set 8")*/ _loaded_designer_zonesets_set_8 = 1ui32 << 8ui32,
			/*nicename("Set 9")*/ _loaded_designer_zonesets_set_9 = 1ui32 << 9ui32,
			/*nicename("Set 10")*/ _loaded_designer_zonesets_set_10 = 1ui32 << 10ui32,
			/*nicename("Set 11")*/ _loaded_designer_zonesets_set_11 = 1ui32 << 11ui32,
			/*nicename("Set 12")*/ _loaded_designer_zonesets_set_12 = 1ui32 << 12ui32,
			/*nicename("Set 13")*/ _loaded_designer_zonesets_set_13 = 1ui32 << 13ui32,
			/*nicename("Set 14")*/ _loaded_designer_zonesets_set_14 = 1ui32 << 14ui32,
			/*nicename("Set 15")*/ _loaded_designer_zonesets_set_15 = 1ui32 << 15ui32,
			/*nicename("Set 16")*/ _loaded_designer_zonesets_set_16 = 1ui32 << 16ui32,
			/*nicename("Set 17")*/ _loaded_designer_zonesets_set_17 = 1ui32 << 17ui32,
			/*nicename("Set 18")*/ _loaded_designer_zonesets_set_18 = 1ui32 << 18ui32,
			/*nicename("Set 19")*/ _loaded_designer_zonesets_set_19 = 1ui32 << 19ui32,
			/*nicename("Set 20")*/ _loaded_designer_zonesets_set_20 = 1ui32 << 20ui32,
			/*nicename("Set 21")*/ _loaded_designer_zonesets_set_21 = 1ui32 << 21ui32,
			/*nicename("Set 22")*/ _loaded_designer_zonesets_set_22 = 1ui32 << 22ui32,
			/*nicename("Set 23")*/ _loaded_designer_zonesets_set_23 = 1ui32 << 23ui32,
			/*nicename("Set 24")*/ _loaded_designer_zonesets_set_24 = 1ui32 << 24ui32,
			/*nicename("Set 25")*/ _loaded_designer_zonesets_set_25 = 1ui32 << 25ui32,
			/*nicename("Set 26")*/ _loaded_designer_zonesets_set_26 = 1ui32 << 26ui32,
			/*nicename("Set 27")*/ _loaded_designer_zonesets_set_27 = 1ui32 << 27ui32,
			/*nicename("Set 28")*/ _loaded_designer_zonesets_set_28 = 1ui32 << 28ui32,
			/*nicename("Set 29")*/ _loaded_designer_zonesets_set_29 = 1ui32 << 29ui32,
			/*nicename("Set 30")*/ _loaded_designer_zonesets_set_30 = 1ui32 << 30ui32,
			/*nicename("Set 31")*/ _loaded_designer_zonesets_set_31 = 1ui32 << 31ui32,
		};

		enum nicename("Unknown Loaded Designer Zonesets") b_unknown_loaded_designer_zonesets : uint32_t /* bitfield */
		{
			/*nicename("Set 0")*/ _unknown_loaded_designer_zonesets_set_0 = 1ui32 << 0ui32,
			/*nicename("Set 1")*/ _unknown_loaded_designer_zonesets_set_1 = 1ui32 << 1ui32,
			/*nicename("Set 2")*/ _unknown_loaded_designer_zonesets_set_2 = 1ui32 << 2ui32,
			/*nicename("Set 3")*/ _unknown_loaded_designer_zonesets_set_3 = 1ui32 << 3ui32,
			/*nicename("Set 4")*/ _unknown_loaded_designer_zonesets_set_4 = 1ui32 << 4ui32,
			/*nicename("Set 5")*/ _unknown_loaded_designer_zonesets_set_5 = 1ui32 << 5ui32,
			/*nicename("Set 6")*/ _unknown_loaded_designer_zonesets_set_6 = 1ui32 << 6ui32,
			/*nicename("Set 7")*/ _unknown_loaded_designer_zonesets_set_7 = 1ui32 << 7ui32,
			/*nicename("Set 8")*/ _unknown_loaded_designer_zonesets_set_8 = 1ui32 << 8ui32,
			/*nicename("Set 9")*/ _unknown_loaded_designer_zonesets_set_9 = 1ui32 << 9ui32,
			/*nicename("Set 10")*/ _unknown_loaded_designer_zonesets_set_10 = 1ui32 << 10ui32,
			/*nicename("Set 11")*/ _unknown_loaded_designer_zonesets_set_11 = 1ui32 << 11ui32,
			/*nicename("Set 12")*/ _unknown_loaded_designer_zonesets_set_12 = 1ui32 << 12ui32,
			/*nicename("Set 13")*/ _unknown_loaded_designer_zonesets_set_13 = 1ui32 << 13ui32,
			/*nicename("Set 14")*/ _unknown_loaded_designer_zonesets_set_14 = 1ui32 << 14ui32,
			/*nicename("Set 15")*/ _unknown_loaded_designer_zonesets_set_15 = 1ui32 << 15ui32,
			/*nicename("Set 16")*/ _unknown_loaded_designer_zonesets_set_16 = 1ui32 << 16ui32,
			/*nicename("Set 17")*/ _unknown_loaded_designer_zonesets_set_17 = 1ui32 << 17ui32,
			/*nicename("Set 18")*/ _unknown_loaded_designer_zonesets_set_18 = 1ui32 << 18ui32,
			/*nicename("Set 19")*/ _unknown_loaded_designer_zonesets_set_19 = 1ui32 << 19ui32,
			/*nicename("Set 20")*/ _unknown_loaded_designer_zonesets_set_20 = 1ui32 << 20ui32,
			/*nicename("Set 21")*/ _unknown_loaded_designer_zonesets_set_21 = 1ui32 << 21ui32,
			/*nicename("Set 22")*/ _unknown_loaded_designer_zonesets_set_22 = 1ui32 << 22ui32,
			/*nicename("Set 23")*/ _unknown_loaded_designer_zonesets_set_23 = 1ui32 << 23ui32,
			/*nicename("Set 24")*/ _unknown_loaded_designer_zonesets_set_24 = 1ui32 << 24ui32,
			/*nicename("Set 25")*/ _unknown_loaded_designer_zonesets_set_25 = 1ui32 << 25ui32,
			/*nicename("Set 26")*/ _unknown_loaded_designer_zonesets_set_26 = 1ui32 << 26ui32,
			/*nicename("Set 27")*/ _unknown_loaded_designer_zonesets_set_27 = 1ui32 << 27ui32,
			/*nicename("Set 28")*/ _unknown_loaded_designer_zonesets_set_28 = 1ui32 << 28ui32,
			/*nicename("Set 29")*/ _unknown_loaded_designer_zonesets_set_29 = 1ui32 << 29ui32,
			/*nicename("Set 30")*/ _unknown_loaded_designer_zonesets_set_30 = 1ui32 << 30ui32,
			/*nicename("Set 31")*/ _unknown_loaded_designer_zonesets_set_31 = 1ui32 << 31ui32,
		};

		enum nicename("Unloaded Designer Zonesets") b_unloaded_designer_zonesets : uint32_t /* bitfield */
		{
			/*nicename("Set 0")*/ _unloaded_designer_zonesets_set_0 = 1ui32 << 0ui32,
			/*nicename("Set 1")*/ _unloaded_designer_zonesets_set_1 = 1ui32 << 1ui32,
			/*nicename("Set 2")*/ _unloaded_designer_zonesets_set_2 = 1ui32 << 2ui32,
			/*nicename("Set 3")*/ _unloaded_designer_zonesets_set_3 = 1ui32 << 3ui32,
			/*nicename("Set 4")*/ _unloaded_designer_zonesets_set_4 = 1ui32 << 4ui32,
			/*nicename("Set 5")*/ _unloaded_designer_zonesets_set_5 = 1ui32 << 5ui32,
			/*nicename("Set 6")*/ _unloaded_designer_zonesets_set_6 = 1ui32 << 6ui32,
			/*nicename("Set 7")*/ _unloaded_designer_zonesets_set_7 = 1ui32 << 7ui32,
			/*nicename("Set 8")*/ _unloaded_designer_zonesets_set_8 = 1ui32 << 8ui32,
			/*nicename("Set 9")*/ _unloaded_designer_zonesets_set_9 = 1ui32 << 9ui32,
			/*nicename("Set 10")*/ _unloaded_designer_zonesets_set_10 = 1ui32 << 10ui32,
			/*nicename("Set 11")*/ _unloaded_designer_zonesets_set_11 = 1ui32 << 11ui32,
			/*nicename("Set 12")*/ _unloaded_designer_zonesets_set_12 = 1ui32 << 12ui32,
			/*nicename("Set 13")*/ _unloaded_designer_zonesets_set_13 = 1ui32 << 13ui32,
			/*nicename("Set 14")*/ _unloaded_designer_zonesets_set_14 = 1ui32 << 14ui32,
			/*nicename("Set 15")*/ _unloaded_designer_zonesets_set_15 = 1ui32 << 15ui32,
			/*nicename("Set 16")*/ _unloaded_designer_zonesets_set_16 = 1ui32 << 16ui32,
			/*nicename("Set 17")*/ _unloaded_designer_zonesets_set_17 = 1ui32 << 17ui32,
			/*nicename("Set 18")*/ _unloaded_designer_zonesets_set_18 = 1ui32 << 18ui32,
			/*nicename("Set 19")*/ _unloaded_designer_zonesets_set_19 = 1ui32 << 19ui32,
			/*nicename("Set 20")*/ _unloaded_designer_zonesets_set_20 = 1ui32 << 20ui32,
			/*nicename("Set 21")*/ _unloaded_designer_zonesets_set_21 = 1ui32 << 21ui32,
			/*nicename("Set 22")*/ _unloaded_designer_zonesets_set_22 = 1ui32 << 22ui32,
			/*nicename("Set 23")*/ _unloaded_designer_zonesets_set_23 = 1ui32 << 23ui32,
			/*nicename("Set 24")*/ _unloaded_designer_zonesets_set_24 = 1ui32 << 24ui32,
			/*nicename("Set 25")*/ _unloaded_designer_zonesets_set_25 = 1ui32 << 25ui32,
			/*nicename("Set 26")*/ _unloaded_designer_zonesets_set_26 = 1ui32 << 26ui32,
			/*nicename("Set 27")*/ _unloaded_designer_zonesets_set_27 = 1ui32 << 27ui32,
			/*nicename("Set 28")*/ _unloaded_designer_zonesets_set_28 = 1ui32 << 28ui32,
			/*nicename("Set 29")*/ _unloaded_designer_zonesets_set_29 = 1ui32 << 29ui32,
			/*nicename("Set 30")*/ _unloaded_designer_zonesets_set_30 = 1ui32 << 30ui32,
			/*nicename("Set 31")*/ _unloaded_designer_zonesets_set_31 = 1ui32 << 31ui32,
		};

		enum nicename("Loaded Cinematic Zonesets") b_loaded_cinematic_zonesets : uint32_t /* bitfield */
		{
			/*nicename("Set 0")*/ _loaded_cinematic_zonesets_set_0 = 1ui32 << 0ui32,
			/*nicename("Set 1")*/ _loaded_cinematic_zonesets_set_1 = 1ui32 << 1ui32,
			/*nicename("Set 2")*/ _loaded_cinematic_zonesets_set_2 = 1ui32 << 2ui32,
			/*nicename("Set 3")*/ _loaded_cinematic_zonesets_set_3 = 1ui32 << 3ui32,
			/*nicename("Set 4")*/ _loaded_cinematic_zonesets_set_4 = 1ui32 << 4ui32,
			/*nicename("Set 5")*/ _loaded_cinematic_zonesets_set_5 = 1ui32 << 5ui32,
			/*nicename("Set 6")*/ _loaded_cinematic_zonesets_set_6 = 1ui32 << 6ui32,
			/*nicename("Set 7")*/ _loaded_cinematic_zonesets_set_7 = 1ui32 << 7ui32,
			/*nicename("Set 8")*/ _loaded_cinematic_zonesets_set_8 = 1ui32 << 8ui32,
			/*nicename("Set 9")*/ _loaded_cinematic_zonesets_set_9 = 1ui32 << 9ui32,
			/*nicename("Set 10")*/ _loaded_cinematic_zonesets_set_10 = 1ui32 << 10ui32,
			/*nicename("Set 11")*/ _loaded_cinematic_zonesets_set_11 = 1ui32 << 11ui32,
			/*nicename("Set 12")*/ _loaded_cinematic_zonesets_set_12 = 1ui32 << 12ui32,
			/*nicename("Set 13")*/ _loaded_cinematic_zonesets_set_13 = 1ui32 << 13ui32,
			/*nicename("Set 14")*/ _loaded_cinematic_zonesets_set_14 = 1ui32 << 14ui32,
			/*nicename("Set 15")*/ _loaded_cinematic_zonesets_set_15 = 1ui32 << 15ui32,
			/*nicename("Set 16")*/ _loaded_cinematic_zonesets_set_16 = 1ui32 << 16ui32,
			/*nicename("Set 17")*/ _loaded_cinematic_zonesets_set_17 = 1ui32 << 17ui32,
			/*nicename("Set 18")*/ _loaded_cinematic_zonesets_set_18 = 1ui32 << 18ui32,
			/*nicename("Set 19")*/ _loaded_cinematic_zonesets_set_19 = 1ui32 << 19ui32,
			/*nicename("Set 20")*/ _loaded_cinematic_zonesets_set_20 = 1ui32 << 20ui32,
			/*nicename("Set 21")*/ _loaded_cinematic_zonesets_set_21 = 1ui32 << 21ui32,
			/*nicename("Set 22")*/ _loaded_cinematic_zonesets_set_22 = 1ui32 << 22ui32,
			/*nicename("Set 23")*/ _loaded_cinematic_zonesets_set_23 = 1ui32 << 23ui32,
			/*nicename("Set 24")*/ _loaded_cinematic_zonesets_set_24 = 1ui32 << 24ui32,
			/*nicename("Set 25")*/ _loaded_cinematic_zonesets_set_25 = 1ui32 << 25ui32,
			/*nicename("Set 26")*/ _loaded_cinematic_zonesets_set_26 = 1ui32 << 26ui32,
			/*nicename("Set 27")*/ _loaded_cinematic_zonesets_set_27 = 1ui32 << 27ui32,
			/*nicename("Set 28")*/ _loaded_cinematic_zonesets_set_28 = 1ui32 << 28ui32,
			/*nicename("Set 29")*/ _loaded_cinematic_zonesets_set_29 = 1ui32 << 29ui32,
			/*nicename("Set 30")*/ _loaded_cinematic_zonesets_set_30 = 1ui32 << 30ui32,
			/*nicename("Set 31")*/ _loaded_cinematic_zonesets_set_31 = 1ui32 << 31ui32,
		};

		string_id nicename("Name") name;
		int32_t nicename("BSP Group Index") bsp_group_index;
		b_import_loaded_bsps nicename("Import Loaded BSPs") import_loaded_bsps;
		b_loaded_bsps nicename("Loaded BSPs") loaded_bsps;
		b_loaded_designer_zonesets nicename("Loaded Designer Zonesets") loaded_designer_zonesets;
		b_unknown_loaded_designer_zonesets nicename("Unknown Loaded Designer Zonesets") unknown_loaded_designer_zonesets;
		b_unloaded_designer_zonesets nicename("Unloaded Designer Zonesets") unloaded_designer_zonesets;
		b_loaded_cinematic_zonesets nicename("Loaded Cinematic Zonesets") loaded_cinematic_zonesets;
		int32_t nicename("BSP Atlas Index") bsp_atlas_index;
	};

	struct nicename("Scenario BSPs") s_scenario_bsps_definition
	{
		TagReference nicename("BSP") bsp_reference;
	};

	struct nicename("Unknown 13") s_unknown_13_definition
	{
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
	};

	struct nicename("Prediction A") s_prediction_a_definition
	{
		uint32_t nicename("Key") key;
	};

	struct nicename("Prediction B") s_prediction_b_definition
	{
		int16_t nicename("Overall Index") overall_index;
		int16_t nicename("A Count") a_count;
		int32_t nicename("A Index") a_index;
	};

	struct nicename("Prediction C") s_prediction_c_definition
	{
		int16_t nicename("Overall Index") overall_index;
		int16_t nicename("B Index") b_index;
	};

	struct nicename("Prediction D - Tags") s_prediction_d___tags_definition
	{
		int16_t nicename("C Count") c_count;
		int16_t nicename("C Index") c_index;
		int16_t nicename("A Count") a_count;
		int16_t nicename("A Index") a_index;
	};

	struct nicename("Prediction D2 - Tags") s_prediction_d2___tags_definition
	{
		TagReference nicename("Tag") tag_reference;
		int32_t nicename("First Value") first_value;
		int32_t nicename("Second Value") second_value;
	};

	e_map_type nicename("Map Type") map_type;
	int16_t nicename("Flags") flags;
	s_tag_block_definition<s_resource_types_definition> nicename("Resource Types") resource_types_block;
	s_tag_block_definition<s_resource_structure_types_definition> nicename("Resource Structure Types") resource_structure_types_block;
	s_tag_block_definition<s_compression_codecs_definition> nicename("Compression Codecs") compression_codecs_block;
	s_tag_block_definition<s_external_cache_references_definition> nicename("External Cache References") external_cache_references_block;
	s_tag_block_definition<s_raw_pages_definition> nicename("Raw Pages") raw_pages_block;
	s_tag_block_definition<s_sizes_definition> nicename("Sizes") sizes_block;
	s_tag_block_definition<s_unknown_definition> __unknown0;
	s_tag_block_definition<s_segments_definition> nicename("Segments") segments_block;
	s_tag_block_definition<s_tag_resources_definition> nicename("Tag Resources") tag_resources_block;
	/* Active Pool Members : Pools are divided up into 32-bit groups per chunk.
	   Each bit corresponds to either a chunk in "Tag Resources" above (Raw Pools), or a tag in the overall tag listing (Tag Pools).
	   If a bit is enabled then that member will be loaded. */
	s_tag_block_definition<s_designer_zonesets_definition> nicename("Designer Zonesets") designer_zonesets_block;
	s_tag_block_definition<s_global_zoneset_definition> nicename("Global Zoneset") global_zoneset_block;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
	s_tag_block_definition<s_unattached_zoneset_definition> nicename("Unattached Zoneset") unattached_zoneset_block;
	s_tag_block_definition<s_disc_forbidden_zoneset_definition> nicename("Disc-Forbidden Zoneset") disc_forbidden_zoneset_block;
	s_tag_block_definition<s_disc_always_streaming_zoneset_definition> nicename("Disc-Always-Streaming Zoneset") disc_always_streaming_zoneset_block;
	s_tag_block_definition<s_bsp_zonesets_definition> nicename("BSP Zonesets") bsp_zonesets_block;
	s_tag_block_definition<s_bsp_zonesets_2_definition> nicename("BSP Zonesets 2") bsp_zonesets_2_block;
	s_tag_block_definition<s_bsp_zonesets_3_definition> nicename("BSP Zonesets 3") bsp_zonesets_3_block;
	s_tag_block_definition<s_cinematic_zonesets_definition> nicename("Cinematic Zonesets") cinematic_zonesets_block;
	s_tag_block_definition<s_scenario_zonesets_definition> nicename("Scenario Zonesets") scenario_zonesets_block;
	Undefined32 __unknown4;
	Undefined32 __unknown5;
	Undefined32 __unknown6;
	Undefined32 __unknown7;
	Undefined32 __unknown8;
	Undefined32 __unknown9;
	s_tag_block_definition<s_scenario_zoneset_groups_definition> nicename("Scenario Zoneset Groups") scenario_zoneset_groups_block;
	s_tag_block_definition<s_scenario_bsps_definition> nicename("Scenario BSPs") scenario_bsps_block;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	Undefined32 __unknown12;
	Undefined32 __unknown13;
	Undefined32 __unknown14;
	Undefined32 __unknown15;
	Undefined32 __unknown16;
	Undefined32 __unknown17;
	Undefined32 __unknown18;
	DataReference nicename("Fixup Information") fixup_information_data_reference;
	Undefined32 __unknown19;
	Undefined32 __unknown20;
	Undefined32 __unknown21;
	Undefined32 __unknown22;
	Undefined32 __unknown23;
	s_tag_block_definition<s_unknown_13_definition> nicename("Unknown 13") unknown_13_block;
	Undefined32 __unknown24;
	Undefined32 __unknown25;
	Undefined32 __unknown26;
	Undefined32 __unknown27;
	Undefined32 __unknown28;
	Undefined32 __unknown29;
	Undefined32 __unknown30;
	Undefined32 __unknown31;
	Undefined32 __unknown32;
	Undefined32 __unknown33;
	Undefined32 __unknown34;
	Undefined32 __unknown35;
	Undefined32 __unknown36;
	Undefined32 __unknown37;
	Undefined32 __unknown38;
	Undefined32 __unknown39;
	Undefined32 __unknown40;
	Undefined32 __unknown41;
	Undefined32 __unknown42;
	Undefined32 __unknown43;
	Undefined32 __unknown44;
	Undefined32 __unknown45;
	Undefined32 __unknown46;
	Undefined32 __unknown47;
	s_tag_block_definition<s_prediction_a_definition> nicename("Prediction A") prediction_a_block;
	s_tag_block_definition<s_prediction_b_definition> nicename("Prediction B") prediction_b_block;
	s_tag_block_definition<s_prediction_c_definition> nicename("Prediction C") prediction_c_block;
	s_tag_block_definition<s_prediction_d___tags_definition> nicename("Prediction D - Tags") prediction_d___tags_block;
	s_tag_block_definition<s_prediction_d2___tags_definition> nicename("Prediction D2 - Tags") prediction_d2___tags_block;
	int32_t nicename("Campaign ID") campaign_id;
	int32_t nicename("Map ID") map_id;
};

