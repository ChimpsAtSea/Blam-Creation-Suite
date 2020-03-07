#pragma once

struct nicename("Zone") group('zone') s_zone_definition
{
	struct nicename("Resource Types") s_resource_type_block_definition;
	struct nicename("Resource Structure Types") s_resource_structure_type_block_definition;
	struct nicename("Compression Codecs") s_compression_codec_block_definition;
	struct nicename("External Cache References") s_external_cache_reference_block_definition;
	struct nicename("Raw Pages") s_raw_page_block_definition;
	struct nicename("Sizes") s_size_block_definition;
	struct s_unknown_block_definition;
	struct nicename("Segments") s_segment_block_definition;
	struct nicename("Tag Resources") s_tag_resource_block_definition;
	struct nicename("Designer Zonesets") s_designer_zoneset_block_definition;
	struct nicename("Global Zoneset") s_global_zoneset_block_definition;
	struct nicename("Unattached Zoneset") s_unattached_zoneset_block_definition;
	struct nicename("Disc-Forbidden Zoneset") s_disc_forbidden_zoneset_block_definition;
	struct nicename("Disc-Always-Streaming Zoneset") s_disc_always_streaming_zoneset_block_definition;
	struct nicename("BSP Zonesets") s_bsp_zoneset_block_definition;
	struct nicename("BSP Zonesets 2") s_bsp_zonesets_2_block_definition;
	struct nicename("BSP Zonesets 3") s_bsp_zonesets_3_block_definition;
	struct nicename("Cinematic Zonesets") s_cinematic_zoneset_block_definition;
	struct nicename("Scenario Zonesets") s_scenario_zoneset_block_definition;
	struct nicename("Scenario Zoneset Groups") s_scenario_zoneset_group_block_definition;
	struct nicename("Scenario BSPs") s_scenario_bsp_block_definition;
	struct s_unknown_13_block_definition;
	struct nicename("Prediction A") s_prediction_a_block_definition;
	struct nicename("Prediction B") s_prediction_b_block_definition;
	struct nicename("Prediction C") s_prediction_c_block_definition;
	struct nicename("Prediction D - Tags") s_prediction_d___tag_block_definition;
	struct nicename("Prediction D2 - Tags") s_prediction_d2___tag_block_definition;

	int16_t nicename("Map Type") map_type; 
	int16_t nicename("Flags") flags; 
	s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
	s_tag_block_definition<s_resource_structure_type_block_definition> nicename("Resource Structure Types") resource_structure_types_block; 
	s_tag_block_definition<s_compression_codec_block_definition> nicename("Compression Codecs") compression_codecs_block; 
	s_tag_block_definition<s_external_cache_reference_block_definition> nicename("External Cache References") external_cache_references_block; 
	s_tag_block_definition<s_raw_page_block_definition> nicename("Raw Pages") raw_pages_block; 
	s_tag_block_definition<s_size_block_definition> nicename("Sizes") sizes_block; 
	s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
	s_tag_block_definition<s_segment_block_definition> nicename("Segments") segments_block; 
	s_tag_block_definition<s_tag_resource_block_definition> nicename("Tag Resources") tag_resources_block; 
	// comment
	s_tag_block_definition<s_designer_zoneset_block_definition> nicename("Designer Zonesets") designer_zonesets_block; 
	s_tag_block_definition<s_global_zoneset_block_definition> nicename("Global Zoneset") global_zoneset_block; 
	Undefined32 __unknown2; 
	Undefined32 __unknown3; 
	Undefined32 __unknown4; 
	s_tag_block_definition<s_unattached_zoneset_block_definition> nicename("Unattached Zoneset") unattached_zoneset_block; 
	s_tag_block_definition<s_disc_forbidden_zoneset_block_definition> nicename("Disc-Forbidden Zoneset") disc_forbidden_zoneset_block; 
	s_tag_block_definition<s_disc_always_streaming_zoneset_block_definition> nicename("Disc-Always-Streaming Zoneset") disc_always_streaming_zoneset_block; 
	s_tag_block_definition<s_bsp_zoneset_block_definition> nicename("BSP Zonesets") bsp_zonesets_block; 
	s_tag_block_definition<s_bsp_zonesets_2_block_definition> nicename("BSP Zonesets 2") bsp_zonesets_2_block; 
	s_tag_block_definition<s_bsp_zonesets_3_block_definition> nicename("BSP Zonesets 3") bsp_zonesets_3_block; 
	s_tag_block_definition<s_cinematic_zoneset_block_definition> nicename("Cinematic Zonesets") cinematic_zonesets_block; 
	s_tag_block_definition<s_scenario_zoneset_block_definition> nicename("Scenario Zonesets") scenario_zonesets_block; 
	Undefined32 __unknown5; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	Undefined32 __unknown8; 
	Undefined32 __unknown9; 
	Undefined32 __unknown10; 
	s_tag_block_definition<s_scenario_zoneset_group_block_definition> nicename("Scenario Zoneset Groups") scenario_zoneset_groups_block; 
	s_tag_block_definition<s_scenario_bsp_block_definition> nicename("Scenario BSPs") scenario_bsps_block; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	Undefined32 __unknown13; 
	Undefined32 __unknown14; 
	Undefined32 __unknown15; 
	Undefined32 __unknown16; 
	Undefined32 __unknown17; 
	Undefined32 __unknown18; 
	Undefined32 __unknown19; 
	DataReference nicename("Fixup Information") fixup_information_data_reference; 
	Undefined32 __unknown20; 
	Undefined32 __unknown21; 
	Undefined32 __unknown22; 
	Undefined32 __unknown23; 
	Undefined32 __unknown24; 
	s_tag_block_definition<s_unknown_13_block_definition> __unknown_13_block; 
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
	Undefined32 __unknown48; 
	s_tag_block_definition<s_prediction_a_block_definition> nicename("Prediction A") prediction_a_block; 
	s_tag_block_definition<s_prediction_b_block_definition> nicename("Prediction B") prediction_b_block; 
	s_tag_block_definition<s_prediction_c_block_definition> nicename("Prediction C") prediction_c_block; 
	s_tag_block_definition<s_prediction_d___tag_block_definition> nicename("Prediction D - Tags") prediction_d___tags_block; 
	s_tag_block_definition<s_prediction_d2___tag_block_definition> nicename("Prediction D2 - Tags") prediction_d2___tags_block; 
	int32_t nicename("Campaign ID") campaign_id; 
	int32_t nicename("Map ID") map_id; 

	struct nicename("resource_type") s_resource_type_block_definition
	{
		uint8_t nicename("Guid") guid[16];
		int16_t __unknown; 
		int16_t __unknown2; 
		int16_t __unknown3; 
		int16_t __unknown4; 
		string_id nicename("Name") name; 
	};

	struct nicename("resource_structure_type") s_resource_structure_type_block_definition
	{
		uint8_t nicename("Guid") guid[16];
		string_id nicename("Name") name; 
	};

	struct nicename("compression_codec") s_compression_codec_block_definition
	{
		uint8_t nicename("Guid") guid[16];
	};

	struct nicename("external_cache_reference") s_external_cache_reference_block_definition
	{
		char nicename("Map Path") map_path[256];
		int16_t __unknown; 
		int16_t __unknown2; 
		Undefined32 __unknown3; 
	};

	struct nicename("raw_page") s_raw_page_block_definition
	{
		int16_t nicename("Salt") salt; 
		int8_t nicename("Flags") flags; 
		int8_t nicename("Compression Codec Index") compression_codec_index; 
		int16_t nicename("Shared Cache Index") shared_cache_index; 
		int16_t __unknown; 
		// comment
		int32_t nicename("Block Offset") block_offset; 
		int32_t nicename("Compressed Block Size") compressed_block_size; 
		int32_t nicename("Uncompressed Block Size") uncompressed_block_size; 
		int32_t nicename("CRC Checksum") crc_checksum; 
		uint8_t nicename("Entire Buffer Hash") entire_buffer_hash[20];
		uint8_t nicename("First Chunk Hash") first_chunk_hash[20];
		uint8_t nicename("Last Chunk Hash") last_chunk_hash[20];
		int16_t nicename("Block Asset Count?") block_asset_count; 
		int16_t __unknown2; 
	};

	struct nicename("size") s_size_block_definition
	{
		struct nicename("Parts") s_part_block_definition;

		int32_t nicename("Overall Size") overall_size; 
		s_tag_block_definition<s_part_block_definition> nicename("Parts") parts_block; 

		struct nicename("part") s_part_block_definition
		{
			int32_t __unknown; 
			int32_t nicename("Size") size; 
		};
	};

	struct s_unknown_block_definition
	{
		int32_t __unknown; 
		int32_t __unknown2; 
		int32_t __unknown3; 
	};

	struct nicename("segment") s_segment_block_definition
	{
		int16_t nicename("Primary Page Index") primary_page_index; 
		int16_t nicename("Secondary Page Index") secondary_page_index; 
		int32_t nicename("Primary Segment Offset") primary_segment_offset; 
		int32_t nicename("Secondary Segment Offset") secondary_segment_offset; 
		int16_t nicename("Primary Size Index") primary_size_index; 
		int16_t nicename("Secondary Size Index") secondary_size_index; 
	};

	struct nicename("tag_resource") s_tag_resource_block_definition
	{
		struct nicename("Resource Fixups") s_resource_fixup_block_definition;
		struct nicename("Resource Definition Fixups") s_resource_definition_fixup_block_definition;

		TagReference nicename("Parent Tag") parent_tag_reference; 
		uint16_t nicename("Salt") salt; 
		uint8_t nicename("Resource Type Index") resource_type_index; 
		uint8_t nicename("Flags") flags; 
		int32_t nicename("Fixup Information Offset") fixup_information_offset; 
		int32_t nicename("Fixup Information Length") fixup_information_length; 
		int32_t nicename("Secondary Fixup Information Offset") secondary_fixup_information_offset; 
		int16_t __unknown; 
		uint16_t nicename("[play] Segment Index") play_segment_index; 
		uint8_t nicename("Root Definition Address Location/High Bits") root_definition_address_location_high_bits; 
		uint8_t nicename("Root Definition Address Upper Bits") root_definition_address_upper_bits; 
		uint16_t nicename("Root Definition Address") root_definition_address; 
		s_tag_block_definition<s_resource_fixup_block_definition> nicename("Resource Fixups") resource_fixups_block; 
		s_tag_block_definition<s_resource_definition_fixup_block_definition> nicename("Resource Definition Fixups") resource_definition_fixups_block; 

		struct nicename("resource_fixup") s_resource_fixup_block_definition
		{
			// comment
			int32_t nicename("Block Offset") block_offset; 
			uint8_t nicename("Address Location/High Bits") address_location_high_bits; 
			uint8_t nicename("Address Upper Bits") address_upper_bits; 
			uint16_t nicename("Address") address; 
		};

		struct nicename("resource_definition_fixup") s_resource_definition_fixup_block_definition
		{
			uint8_t nicename("Offset Location/High Bits") offset_location_high_bits; 
			uint8_t nicename("Offset Upper Bits") offset_upper_bits; 
			uint16_t nicename("Offset") offset; 
			int32_t nicename("Resource Structure Type Index") resource_structure_type_index; 
		};
	};

	struct nicename("designer_zoneset") s_designer_zoneset_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("global_zoneset") s_global_zoneset_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("unattached_zoneset") s_unattached_zoneset_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("disc_forbidden_zoneset") s_disc_forbidden_zoneset_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("disc_always_streaming_zoneset") s_disc_always_streaming_zoneset_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("bsp_zoneset") s_bsp_zoneset_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("bsp_zonesets_2") s_bsp_zonesets_2_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("bsp_zonesets_3") s_bsp_zonesets_3_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("cinematic_zoneset") s_cinematic_zoneset_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("scenario_zoneset") s_scenario_zoneset_block_definition
	{
		struct nicename("Required Raw Pool") s_required_raw_pool_block_definition;
		struct nicename("Optional Raw Pool") s_optional_raw_pool_block_definition;
		struct nicename("Optional Raw Pool 2") s_optional_raw_pool_2_block_definition;
		struct nicename("Resource Types") s_resource_type_block_definition;
		struct nicename("Required Tag Pool") s_required_tag_pool_block_definition;
		struct nicename("Optional Tag Pool") s_optional_tag_pool_block_definition;

		s_tag_block_definition<s_required_raw_pool_block_definition> nicename("Required Raw Pool") required_raw_pool_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_optional_raw_pool_block_definition> nicename("Optional Raw Pool") optional_raw_pool_block; 
		s_tag_block_definition<s_optional_raw_pool_2_block_definition> nicename("Optional Raw Pool 2") optional_raw_pool_2_block; 
		string_id nicename("Set Name") set_name; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		s_tag_block_definition<s_resource_type_block_definition> nicename("Resource Types") resource_types_block; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		s_tag_block_definition<s_required_tag_pool_block_definition> nicename("Required Tag Pool") required_tag_pool_block; 
		s_tag_block_definition<s_optional_tag_pool_block_definition> nicename("Optional Tag Pool") optional_tag_pool_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 

		struct nicename("required_raw_pool") s_required_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool") s_optional_raw_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_raw_pool_2") s_optional_raw_pool_2_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("resource_type") s_resource_type_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct nicename("required_tag_pool") s_required_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};

		struct nicename("optional_tag_pool") s_optional_tag_pool_block_definition
		{
			int32_t nicename("Active Members") active_members; 
		};
	};

	struct nicename("scenario_zoneset_group") s_scenario_zoneset_group_block_definition
	{
		string_id nicename("Name") name; 
		int32_t nicename("BSP Group Index") bsp_group_index; 
		int32_t nicename("Import Loaded BSPs") import_loaded_bsps; 
		int32_t nicename("Loaded BSPs") loaded_bsps; 
		int32_t nicename("Loaded Designer Zonesets") loaded_designer_zonesets; 
		int32_t __unknown_loaded_designer_zonesets; 
		int32_t nicename("Unloaded Designer Zonesets") unloaded_designer_zonesets; 
		int32_t nicename("Loaded Cinematic Zonesets") loaded_cinematic_zonesets; 
		int32_t nicename("BSP Atlas Index") bsp_atlas_index; 
	};

	struct nicename("scenario_bsp") s_scenario_bsp_block_definition
	{
		TagReference nicename("BSP") bsp_reference; 
	};

	struct s_unknown_13_block_definition
	{
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
	};

	struct nicename("prediction_a") s_prediction_a_block_definition
	{
		uint32_t nicename("Key") key; 
	};

	struct nicename("prediction_b") s_prediction_b_block_definition
	{
		int16_t nicename("Overall Index") overall_index; 
		int16_t nicename("A Count") a_count; 
		int32_t nicename("A Index") a_index; 
	};

	struct nicename("prediction_c") s_prediction_c_block_definition
	{
		int16_t nicename("Overall Index") overall_index; 
		int16_t nicename("B Index") b_index; 
	};

	struct nicename("prediction_d___tag") s_prediction_d___tag_block_definition
	{
		int16_t nicename("C Count") c_count; 
		int16_t nicename("C Index") c_index; 
		int16_t nicename("A Count") a_count; 
		int16_t nicename("A Index") a_index; 
	};

	struct nicename("prediction_d2___tag") s_prediction_d2___tag_block_definition
	{
		TagReference nicename("Tag") tag_reference; 
		int32_t nicename("First Value") first_value; 
		int32_t nicename("Second Value") second_value; 
	};
};
