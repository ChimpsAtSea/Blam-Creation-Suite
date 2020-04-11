#pragma once

struct nicename("scenario") tag_group('scnr') s_scenario_definition
{
	enum nicename("Map Type") e_map_type : uint16_t
	{
		/*nicename("Single Player")*/ _map_type_single_player = 0ui16,
		/*nicename("Multiplayer")*/ _map_type_multiplayer = 1ui16,
		/*nicename("Main Menu")*/ _map_type_main_menu = 2ui16,
	};

	enum nicename("Flags") b_flags : uint16_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _flags_bit_0 = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
		/*nicename("Snap to White at Start")*/ _flags_snap_to_white_at_start = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
		/*nicename("Firefight")*/ _flags_firefight = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
	};

	struct nicename("Structure BSPs") s_structure_bsps_definition
	{
		enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags1_bit_0 = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui16 << 9ui16,
			/*nicename("Prevents Forging")*/ _flags1_prevents_forging = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui16 << 15ui16,
		};

		s_tag_reference_legacy nicename("Structure BSP") structure_bsp_reference;
		s_tag_reference_legacy __unknown0;
		s_tag_reference_legacy nicename("Structure Lighting") structure_lighting_reference;
		s_tag_reference_legacy __unknown1;
		int32_t __unknown2;
		float __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		b_flags1 nicename("Flags") flags;
		int16_t __unknown6;
		s_undefined32_legacy __unknown7;
		s_tag_reference_legacy nicename("Cubemap") cubemap_reference;
		s_tag_reference_legacy nicename("Wind") wind_reference;
		s_undefined32_legacy __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		s_undefined32_legacy __unknown16;
		float __unknown17;
		s_undefined32_legacy __unknown18;
		int32_t __unknown19;
		float nicename("Gravity Percentage") gravity_percentage;
	};

	struct nicename("Structure Design") s_structure_design_definition
	{
		s_tag_reference_legacy nicename("Design") design_reference;
		s_tag_reference_legacy __unknown0;
	};

	struct nicename("Sky References") s_sky_references_definition
	{
		enum nicename("Active BSPs") b_active_bsps : uint16_t /* bitfield */
		{
			/*nicename("BSP 0")*/ _active_bsps_bsp_0 = 1ui16 << 0ui16,
			/*nicename("BSP 1")*/ _active_bsps_bsp_1 = 1ui16 << 1ui16,
			/*nicename("BSP 2")*/ _active_bsps_bsp_2 = 1ui16 << 2ui16,
			/*nicename("BSP 3")*/ _active_bsps_bsp_3 = 1ui16 << 3ui16,
			/*nicename("BSP 4")*/ _active_bsps_bsp_4 = 1ui16 << 4ui16,
			/*nicename("BSP 5")*/ _active_bsps_bsp_5 = 1ui16 << 5ui16,
			/*nicename("BSP 6")*/ _active_bsps_bsp_6 = 1ui16 << 6ui16,
			/*nicename("BSP 7")*/ _active_bsps_bsp_7 = 1ui16 << 7ui16,
			/*nicename("BSP 8")*/ _active_bsps_bsp_8 = 1ui16 << 8ui16,
			/*nicename("BSP 9")*/ _active_bsps_bsp_9 = 1ui16 << 9ui16,
			/*nicename("BSP 10")*/ _active_bsps_bsp_10 = 1ui16 << 10ui16,
			/*nicename("BSP 11")*/ _active_bsps_bsp_11 = 1ui16 << 11ui16,
			/*nicename("BSP 12")*/ _active_bsps_bsp_12 = 1ui16 << 12ui16,
			/*nicename("BSP 13")*/ _active_bsps_bsp_13 = 1ui16 << 13ui16,
			/*nicename("BSP 14")*/ _active_bsps_bsp_14 = 1ui16 << 14ui16,
			/*nicename("BSP 15")*/ _active_bsps_bsp_15 = 1ui16 << 15ui16,
		};

		s_tag_reference_legacy nicename("Sky Object") sky_object_reference;
		float __unknown0;
		float __unknown1;
		float __unknown2;
		s_tag_reference_legacy __unknown3;
		int16_t nicename("Name Index") name_index;
		b_active_bsps nicename("Active BSPs") active_bsps;
	};

	struct nicename("BSP Groups") s_bsp_groups_definition
	{
		enum nicename("Included BSPs") b_included_bsps : uint32_t /* bitfield */
		{
			/*nicename("BSP 0")*/ _included_bsps_bsp_0 = 1ui32 << 0ui32,
			/*nicename("BSP 1")*/ _included_bsps_bsp_1 = 1ui32 << 1ui32,
			/*nicename("BSP 2")*/ _included_bsps_bsp_2 = 1ui32 << 2ui32,
			/*nicename("BSP 3")*/ _included_bsps_bsp_3 = 1ui32 << 3ui32,
			/*nicename("BSP 4")*/ _included_bsps_bsp_4 = 1ui32 << 4ui32,
			/*nicename("BSP 5")*/ _included_bsps_bsp_5 = 1ui32 << 5ui32,
			/*nicename("BSP 6")*/ _included_bsps_bsp_6 = 1ui32 << 6ui32,
			/*nicename("BSP 7")*/ _included_bsps_bsp_7 = 1ui32 << 7ui32,
			/*nicename("BSP 8")*/ _included_bsps_bsp_8 = 1ui32 << 8ui32,
			/*nicename("BSP 9")*/ _included_bsps_bsp_9 = 1ui32 << 9ui32,
			/*nicename("BSP 10")*/ _included_bsps_bsp_10 = 1ui32 << 10ui32,
			/*nicename("BSP 11")*/ _included_bsps_bsp_11 = 1ui32 << 11ui32,
			/*nicename("BSP 12")*/ _included_bsps_bsp_12 = 1ui32 << 12ui32,
			/*nicename("BSP 13")*/ _included_bsps_bsp_13 = 1ui32 << 13ui32,
			/*nicename("BSP 14")*/ _included_bsps_bsp_14 = 1ui32 << 14ui32,
			/*nicename("BSP 15")*/ _included_bsps_bsp_15 = 1ui32 << 15ui32,
			/*nicename("BSP 16")*/ _included_bsps_bsp_16 = 1ui32 << 16ui32,
			/*nicename("BSP 17")*/ _included_bsps_bsp_17 = 1ui32 << 17ui32,
			/*nicename("BSP 18")*/ _included_bsps_bsp_18 = 1ui32 << 18ui32,
			/*nicename("BSP 19")*/ _included_bsps_bsp_19 = 1ui32 << 19ui32,
			/*nicename("BSP 20")*/ _included_bsps_bsp_20 = 1ui32 << 20ui32,
			/*nicename("BSP 21")*/ _included_bsps_bsp_21 = 1ui32 << 21ui32,
			/*nicename("BSP 22")*/ _included_bsps_bsp_22 = 1ui32 << 22ui32,
			/*nicename("BSP 23")*/ _included_bsps_bsp_23 = 1ui32 << 23ui32,
			/*nicename("BSP 24")*/ _included_bsps_bsp_24 = 1ui32 << 24ui32,
			/*nicename("BSP 25")*/ _included_bsps_bsp_25 = 1ui32 << 25ui32,
			/*nicename("BSP 26")*/ _included_bsps_bsp_26 = 1ui32 << 26ui32,
			/*nicename("BSP 27")*/ _included_bsps_bsp_27 = 1ui32 << 27ui32,
			/*nicename("BSP 28")*/ _included_bsps_bsp_28 = 1ui32 << 28ui32,
			/*nicename("BSP 29")*/ _included_bsps_bsp_29 = 1ui32 << 29ui32,
			/*nicename("BSP 30")*/ _included_bsps_bsp_30 = 1ui32 << 30ui32,
			/*nicename("BSP 31")*/ _included_bsps_bsp_31 = 1ui32 << 31ui32,
		};

		struct nicename("BSP Checksums") s_bsp_checksums_definition
		{
			int32_t nicename("Structure Checksum") structure_checksum;
		};

		struct nicename("BSPs") s_bsps_definition
		{
			struct nicename("Clusters") s_clusters_definition
			{
				struct nicename("BSPs") s_bsps1_definition
				{
					struct nicename("Unknown") s_unknown_definition
					{
						enum nicename("Allow...") b_allow : uint32_t /* bitfield */
						{
							/*nicename("Bit 0")*/ _allow_bit_0 = 1ui32 << 0ui32,
							/*nicename("Bit 1")*/ _allow_bit_1 = 1ui32 << 1ui32,
							/*nicename("Bit 2")*/ _allow_bit_2 = 1ui32 << 2ui32,
							/*nicename("Bit 3")*/ _allow_bit_3 = 1ui32 << 3ui32,
							/*nicename("Bit 4")*/ _allow_bit_4 = 1ui32 << 4ui32,
							/*nicename("Effects")*/ _allow_effects = 1ui32 << 5ui32,
							/*nicename("Bit 6")*/ _allow_bit_6 = 1ui32 << 6ui32,
							/*nicename("Bit 7")*/ _allow_bit_7 = 1ui32 << 7ui32,
							/*nicename("Bit 8")*/ _allow_bit_8 = 1ui32 << 8ui32,
							/*nicename("Bit 9")*/ _allow_bit_9 = 1ui32 << 9ui32,
							/*nicename("Bit 10")*/ _allow_bit_10 = 1ui32 << 10ui32,
							/*nicename("Bit 11")*/ _allow_bit_11 = 1ui32 << 11ui32,
							/*nicename("Bit 12")*/ _allow_bit_12 = 1ui32 << 12ui32,
							/*nicename("Bit 13")*/ _allow_bit_13 = 1ui32 << 13ui32,
							/*nicename("Bit 14")*/ _allow_bit_14 = 1ui32 << 14ui32,
							/*nicename("Bit 15")*/ _allow_bit_15 = 1ui32 << 15ui32,
							/*nicename("Firing Effects?")*/ _allow_firing_effects = 1ui32 << 16ui32,
							/*nicename("Bit 17")*/ _allow_bit_17 = 1ui32 << 17ui32,
							/*nicename("Bit 18")*/ _allow_bit_18 = 1ui32 << 18ui32,
							/*nicename("Bit 19")*/ _allow_bit_19 = 1ui32 << 19ui32,
							/*nicename("Bit 20")*/ _allow_bit_20 = 1ui32 << 20ui32,
							/*nicename("Bit 21")*/ _allow_bit_21 = 1ui32 << 21ui32,
							/*nicename("Bit 22")*/ _allow_bit_22 = 1ui32 << 22ui32,
							/*nicename("Bit 23")*/ _allow_bit_23 = 1ui32 << 23ui32,
							/*nicename("Decals")*/ _allow_decals = 1ui32 << 24ui32,
							/*nicename("Bit 25")*/ _allow_bit_25 = 1ui32 << 25ui32,
							/*nicename("Bit 26")*/ _allow_bit_26 = 1ui32 << 26ui32,
							/*nicename("Bit 27")*/ _allow_bit_27 = 1ui32 << 27ui32,
							/*nicename("Bit 28")*/ _allow_bit_28 = 1ui32 << 28ui32,
							/*nicename("Bit 29")*/ _allow_bit_29 = 1ui32 << 29ui32,
							/*nicename("Bit 30")*/ _allow_bit_30 = 1ui32 << 30ui32,
							/*nicename("Bit 31")*/ _allow_bit_31 = 1ui32 << 31ui32,
						};

						b_allow nicename("Allow...") allow;
					};

					s_tag_block_legacy<s_unknown_definition> __unknown0;
				};

				s_tag_block_legacy<s_bsps1_definition> nicename("BSPs") bsps_block;
			};

			struct nicename("Clusters") s_clusters1_definition
			{
				struct nicename("BSPs") s_bsps2_definition
				{
					struct nicename("Unknown") s_unknown1_definition
					{
						enum nicename("Show...") b_show : uint32_t /* bitfield */
						{
							/*nicename("Bit 0")*/ _show_bit_0 = 1ui32 << 0ui32,
							/*nicename("Bit 1")*/ _show_bit_1 = 1ui32 << 1ui32,
							/*nicename("Bit 2")*/ _show_bit_2 = 1ui32 << 2ui32,
							/*nicename("Bit 3")*/ _show_bit_3 = 1ui32 << 3ui32,
							/*nicename("Bit 4")*/ _show_bit_4 = 1ui32 << 4ui32,
							/*nicename("Effects")*/ _show_effects = 1ui32 << 5ui32,
							/*nicename("Bit 6")*/ _show_bit_6 = 1ui32 << 6ui32,
							/*nicename("Bit 7")*/ _show_bit_7 = 1ui32 << 7ui32,
							/*nicename("Bit 8")*/ _show_bit_8 = 1ui32 << 8ui32,
							/*nicename("Bit 9")*/ _show_bit_9 = 1ui32 << 9ui32,
							/*nicename("Bit 10")*/ _show_bit_10 = 1ui32 << 10ui32,
							/*nicename("Bit 11")*/ _show_bit_11 = 1ui32 << 11ui32,
							/*nicename("Bit 12")*/ _show_bit_12 = 1ui32 << 12ui32,
							/*nicename("Bit 13")*/ _show_bit_13 = 1ui32 << 13ui32,
							/*nicename("Bit 14")*/ _show_bit_14 = 1ui32 << 14ui32,
							/*nicename("Bit 15")*/ _show_bit_15 = 1ui32 << 15ui32,
							/*nicename("Firing Effects?")*/ _show_firing_effects = 1ui32 << 16ui32,
							/*nicename("Bit 17")*/ _show_bit_17 = 1ui32 << 17ui32,
							/*nicename("Bit 18")*/ _show_bit_18 = 1ui32 << 18ui32,
							/*nicename("Bit 19")*/ _show_bit_19 = 1ui32 << 19ui32,
							/*nicename("Bit 20")*/ _show_bit_20 = 1ui32 << 20ui32,
							/*nicename("Bit 21")*/ _show_bit_21 = 1ui32 << 21ui32,
							/*nicename("Bit 22")*/ _show_bit_22 = 1ui32 << 22ui32,
							/*nicename("Bit 23")*/ _show_bit_23 = 1ui32 << 23ui32,
							/*nicename("Decals")*/ _show_decals = 1ui32 << 24ui32,
							/*nicename("Bit 25")*/ _show_bit_25 = 1ui32 << 25ui32,
							/*nicename("Bit 26")*/ _show_bit_26 = 1ui32 << 26ui32,
							/*nicename("Bit 27")*/ _show_bit_27 = 1ui32 << 27ui32,
							/*nicename("Bit 28")*/ _show_bit_28 = 1ui32 << 28ui32,
							/*nicename("Bit 29")*/ _show_bit_29 = 1ui32 << 29ui32,
							/*nicename("Bit 30")*/ _show_bit_30 = 1ui32 << 30ui32,
							/*nicename("Bit 31")*/ _show_bit_31 = 1ui32 << 31ui32,
						};

						b_show nicename("Show...") show;
					};

					s_tag_block_legacy<s_unknown1_definition> __unknown0;
				};

				s_tag_block_legacy<s_bsps2_definition> nicename("BSPs") bsps_block;
			};

			struct nicename("Cluster Skies") s_cluster_skies_definition
			{
				int8_t nicename("Sky Index") sky_index;
			};

			struct nicename("Cluster Visible Skies") s_cluster_visible_skies_definition
			{
				int8_t nicename("Sky Index") sky_index;
			};

			struct nicename("Unknown") s_unknown2_definition
			{
				s_undefined32_legacy __unknown0;
			};

			struct nicename("Clusters") s_clusters2_definition
			{
				struct nicename("Unknown") s_unknown3_definition
				{
					int8_t __unknown0;
					int8_t __unknown1;
				};

				struct nicename("Unknown") s_unknown4_definition
				{
					int8_t __unknown0;
					int8_t __unknown1;
				};

				struct nicename("Unknown") s_unknown5_definition
				{
					int8_t __unknown0;
					int8_t __unknown1;
				};

				s_tag_block_legacy<s_unknown3_definition> __unknown0;
				s_tag_block_legacy<s_unknown4_definition> __unknown1;
				s_tag_block_legacy<s_unknown5_definition> __unknown2;
			};

			s_tag_block_legacy<s_clusters_definition> nicename("Clusters") clusters_block;
			s_tag_block_legacy<s_clusters1_definition> nicename("Clusters") clusters1_block;
			s_tag_block_legacy<s_cluster_skies_definition> nicename("Cluster Skies") cluster_skies_block;
			s_tag_block_legacy<s_cluster_visible_skies_definition> nicename("Cluster Visible Skies") cluster_visible_skies_block;
			s_tag_block_legacy<s_unknown2_definition> __unknown0;
			s_tag_block_legacy<s_clusters2_definition> nicename("Clusters") clusters2_block;
		};

		struct nicename("BSPs") s_bsps3_definition
		{
			struct nicename("Unknown") s_unknown6_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int32_t __unknown2;
				int16_t __unknown3;
				int16_t __unknown4;
			};

			struct nicename("Unknown") s_unknown7_definition
			{
				int16_t __unknown0;
			};

			s_tag_block_legacy<s_unknown6_definition> __unknown0;
			s_tag_block_legacy<s_unknown7_definition> __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
			s_undefined32_legacy __unknown4;
		};

		b_included_bsps nicename("Included BSPs") included_bsps;
		int32_t __unknown0;
		s_tag_block_legacy<s_bsp_checksums_definition> nicename("BSP Checksums") bsp_checksums_block;
		s_tag_block_legacy<s_bsps_definition> nicename("BSPs") bsps_block;
		s_tag_block_legacy<s_bsps3_definition> nicename("BSPs") bsps1_block;
	};

	struct nicename("Scenario BSP Audibility") s_scenario_bsp_audibility_definition
	{
		struct nicename("Encoded Door PAS") s_encoded_door_pas_definition
		{
			int32_t __unknown0;
		};

		struct nicename("Cluster Door Portal Encoded PAS") s_cluster_door_portal_encoded_pas_definition
		{
			int32_t __unknown0;
		};

		struct nicename("AI Deafening PAS") s_ai_deafening_pas_definition
		{
			int32_t __unknown0;
		};

		struct nicename("Cluster Distances") s_cluster_distances_definition
		{
			int8_t __unknown0;
		};

		struct nicename("BSPs") s_bsps4_definition
		{
			int32_t nicename("Start") start;
			int32_t nicename("Count") count;
		};

		struct nicename("BSP Cluster List") s_bsp_cluster_list_definition
		{
			int32_t nicename("Start Index") start_index;
			int32_t nicename("Cluster Count") cluster_count;
		};

		struct nicename("Cluster Mapping") s_cluster_mapping_definition
		{
			int16_t nicename("Index") index;
		};

		int32_t nicename("Door Portal Count") door_portal_count;
		int32_t nicename("Unique Cluster Count") unique_cluster_count;
		float nicename("Cluster Distance Bounds min") cluster_distance_bounds_min;
		float nicename("Cluster Distance Bounds max") cluster_distance_bounds_max;
		s_tag_block_legacy<s_encoded_door_pas_definition> nicename("Encoded Door PAS") encoded_door_pas_block;
		s_tag_block_legacy<s_cluster_door_portal_encoded_pas_definition> nicename("Cluster Door Portal Encoded PAS") cluster_door_portal_encoded_pas_block;
		s_tag_block_legacy<s_ai_deafening_pas_definition> nicename("AI Deafening PAS") ai_deafening_pas_block;
		s_tag_block_legacy<s_cluster_distances_definition> nicename("Cluster Distances") cluster_distances_block;
		s_tag_block_legacy<s_bsps4_definition> nicename("BSPs") bsps_block;
		s_tag_block_legacy<s_bsp_cluster_list_definition> nicename("BSP Cluster List") bsp_cluster_list_block;
		s_tag_block_legacy<s_cluster_mapping_definition> nicename("Cluster Mapping") cluster_mapping_block;
	};

	struct nicename("Scenario Zoneset Groups") s_scenario_zoneset_groups_definition
	{
		enum nicename("Loaded BSPs 1") b_loaded_bsps_1 : uint32_t /* bitfield */
		{
			/*nicename("BSP 0")*/ _loaded_bsps_1_bsp_0 = 1ui32 << 0ui32,
			/*nicename("BSP 1")*/ _loaded_bsps_1_bsp_1 = 1ui32 << 1ui32,
			/*nicename("BSP 2")*/ _loaded_bsps_1_bsp_2 = 1ui32 << 2ui32,
			/*nicename("BSP 3")*/ _loaded_bsps_1_bsp_3 = 1ui32 << 3ui32,
			/*nicename("BSP 4")*/ _loaded_bsps_1_bsp_4 = 1ui32 << 4ui32,
			/*nicename("BSP 5")*/ _loaded_bsps_1_bsp_5 = 1ui32 << 5ui32,
			/*nicename("BSP 6")*/ _loaded_bsps_1_bsp_6 = 1ui32 << 6ui32,
			/*nicename("BSP 7")*/ _loaded_bsps_1_bsp_7 = 1ui32 << 7ui32,
			/*nicename("BSP 8")*/ _loaded_bsps_1_bsp_8 = 1ui32 << 8ui32,
			/*nicename("BSP 9")*/ _loaded_bsps_1_bsp_9 = 1ui32 << 9ui32,
			/*nicename("BSP 10")*/ _loaded_bsps_1_bsp_10 = 1ui32 << 10ui32,
			/*nicename("BSP 11")*/ _loaded_bsps_1_bsp_11 = 1ui32 << 11ui32,
			/*nicename("BSP 12")*/ _loaded_bsps_1_bsp_12 = 1ui32 << 12ui32,
			/*nicename("BSP 13")*/ _loaded_bsps_1_bsp_13 = 1ui32 << 13ui32,
			/*nicename("BSP 14")*/ _loaded_bsps_1_bsp_14 = 1ui32 << 14ui32,
			/*nicename("BSP 15")*/ _loaded_bsps_1_bsp_15 = 1ui32 << 15ui32,
			/*nicename("BSP 16")*/ _loaded_bsps_1_bsp_16 = 1ui32 << 16ui32,
			/*nicename("BSP 17")*/ _loaded_bsps_1_bsp_17 = 1ui32 << 17ui32,
			/*nicename("BSP 18")*/ _loaded_bsps_1_bsp_18 = 1ui32 << 18ui32,
			/*nicename("BSP 19")*/ _loaded_bsps_1_bsp_19 = 1ui32 << 19ui32,
			/*nicename("BSP 20")*/ _loaded_bsps_1_bsp_20 = 1ui32 << 20ui32,
			/*nicename("BSP 21")*/ _loaded_bsps_1_bsp_21 = 1ui32 << 21ui32,
			/*nicename("BSP 22")*/ _loaded_bsps_1_bsp_22 = 1ui32 << 22ui32,
			/*nicename("BSP 23")*/ _loaded_bsps_1_bsp_23 = 1ui32 << 23ui32,
			/*nicename("BSP 24")*/ _loaded_bsps_1_bsp_24 = 1ui32 << 24ui32,
			/*nicename("BSP 25")*/ _loaded_bsps_1_bsp_25 = 1ui32 << 25ui32,
			/*nicename("BSP 26")*/ _loaded_bsps_1_bsp_26 = 1ui32 << 26ui32,
			/*nicename("BSP 27")*/ _loaded_bsps_1_bsp_27 = 1ui32 << 27ui32,
			/*nicename("BSP 28")*/ _loaded_bsps_1_bsp_28 = 1ui32 << 28ui32,
			/*nicename("BSP 29")*/ _loaded_bsps_1_bsp_29 = 1ui32 << 29ui32,
			/*nicename("BSP 30")*/ _loaded_bsps_1_bsp_30 = 1ui32 << 30ui32,
			/*nicename("BSP 31")*/ _loaded_bsps_1_bsp_31 = 1ui32 << 31ui32,
		};

		enum nicename("Loaded BSPs 2") b_loaded_bsps_2 : uint32_t /* bitfield */
		{
			/*nicename("BSP 0")*/ _loaded_bsps_2_bsp_0 = 1ui32 << 0ui32,
			/*nicename("BSP 1")*/ _loaded_bsps_2_bsp_1 = 1ui32 << 1ui32,
			/*nicename("BSP 2")*/ _loaded_bsps_2_bsp_2 = 1ui32 << 2ui32,
			/*nicename("BSP 3")*/ _loaded_bsps_2_bsp_3 = 1ui32 << 3ui32,
			/*nicename("BSP 4")*/ _loaded_bsps_2_bsp_4 = 1ui32 << 4ui32,
			/*nicename("BSP 5")*/ _loaded_bsps_2_bsp_5 = 1ui32 << 5ui32,
			/*nicename("BSP 6")*/ _loaded_bsps_2_bsp_6 = 1ui32 << 6ui32,
			/*nicename("BSP 7")*/ _loaded_bsps_2_bsp_7 = 1ui32 << 7ui32,
			/*nicename("BSP 8")*/ _loaded_bsps_2_bsp_8 = 1ui32 << 8ui32,
			/*nicename("BSP 9")*/ _loaded_bsps_2_bsp_9 = 1ui32 << 9ui32,
			/*nicename("BSP 10")*/ _loaded_bsps_2_bsp_10 = 1ui32 << 10ui32,
			/*nicename("BSP 11")*/ _loaded_bsps_2_bsp_11 = 1ui32 << 11ui32,
			/*nicename("BSP 12")*/ _loaded_bsps_2_bsp_12 = 1ui32 << 12ui32,
			/*nicename("BSP 13")*/ _loaded_bsps_2_bsp_13 = 1ui32 << 13ui32,
			/*nicename("BSP 14")*/ _loaded_bsps_2_bsp_14 = 1ui32 << 14ui32,
			/*nicename("BSP 15")*/ _loaded_bsps_2_bsp_15 = 1ui32 << 15ui32,
			/*nicename("BSP 16")*/ _loaded_bsps_2_bsp_16 = 1ui32 << 16ui32,
			/*nicename("BSP 17")*/ _loaded_bsps_2_bsp_17 = 1ui32 << 17ui32,
			/*nicename("BSP 18")*/ _loaded_bsps_2_bsp_18 = 1ui32 << 18ui32,
			/*nicename("BSP 19")*/ _loaded_bsps_2_bsp_19 = 1ui32 << 19ui32,
			/*nicename("BSP 20")*/ _loaded_bsps_2_bsp_20 = 1ui32 << 20ui32,
			/*nicename("BSP 21")*/ _loaded_bsps_2_bsp_21 = 1ui32 << 21ui32,
			/*nicename("BSP 22")*/ _loaded_bsps_2_bsp_22 = 1ui32 << 22ui32,
			/*nicename("BSP 23")*/ _loaded_bsps_2_bsp_23 = 1ui32 << 23ui32,
			/*nicename("BSP 24")*/ _loaded_bsps_2_bsp_24 = 1ui32 << 24ui32,
			/*nicename("BSP 25")*/ _loaded_bsps_2_bsp_25 = 1ui32 << 25ui32,
			/*nicename("BSP 26")*/ _loaded_bsps_2_bsp_26 = 1ui32 << 26ui32,
			/*nicename("BSP 27")*/ _loaded_bsps_2_bsp_27 = 1ui32 << 27ui32,
			/*nicename("BSP 28")*/ _loaded_bsps_2_bsp_28 = 1ui32 << 28ui32,
			/*nicename("BSP 29")*/ _loaded_bsps_2_bsp_29 = 1ui32 << 29ui32,
			/*nicename("BSP 30")*/ _loaded_bsps_2_bsp_30 = 1ui32 << 30ui32,
			/*nicename("BSP 31")*/ _loaded_bsps_2_bsp_31 = 1ui32 << 31ui32,
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

		struct nicename("Unknown 6") s_unknown_6_definition
		{
			struct nicename("BSPs") s_bsps5_definition
			{
				struct nicename("Clusters") s_clusters3_definition
				{
					struct nicename("Unknown 6") s_unknown_61_definition
					{
						s_undefined32_legacy __unknown0;
					};

					s_tag_block_legacy<s_unknown_61_definition> nicename("Unknown 6") unknown_6_block;
				};

				s_tag_block_legacy<s_clusters3_definition> nicename("Clusters") clusters_block;
			};

			s_tag_block_legacy<s_bsps5_definition> nicename("BSPs") bsps_block;
		};

		string_id_legacy nicename("Name") name;
		char nicename("Name String") name_string[256];
		int32_t nicename("BSP Group Index") bsp_group_index;
		int32_t __unknown0;
		b_loaded_bsps_1 nicename("Loaded BSPs 1") loaded_bsps_1;
		int32_t __unknown1;
		b_loaded_bsps_2 nicename("Loaded BSPs 2") loaded_bsps_2;
		int32_t __unknown2;
		b_loaded_designer_zonesets nicename("Loaded Designer Zonesets") loaded_designer_zonesets;
		b_unloaded_designer_zonesets nicename("Unloaded Designer Zonesets") unloaded_designer_zonesets;
		b_loaded_cinematic_zonesets nicename("Loaded Cinematic Zonesets") loaded_cinematic_zonesets;
		int32_t nicename("BSP Atlas Index") bsp_atlas_index;
		int32_t nicename("Scenario BSP Audibility Index") scenario_bsp_audibility_index;
		s_tag_block_legacy<s_unknown_6_definition> nicename("Unknown 6") unknown_6_block;
	};

	struct nicename("Object Names") s_object_names_definition
	{
		enum nicename("Type") e_type : uint16_t
		{
			/*nicename("Null")*/ _type_null = 0ui16,
			/*nicename("Biped")*/ _type_biped = 1ui16,
			/*nicename("Vehicle")*/ _type_vehicle = 2ui16,
			/*nicename("Weapon")*/ _type_weapon = 3ui16,
			/*nicename("Equipment")*/ _type_equipment = 4ui16,
			/*nicename("Terminal")*/ _type_terminal = 5ui16,
			/*nicename("Projectile")*/ _type_projectile = 6ui16,
			/*nicename("Scenery")*/ _type_scenery = 7ui16,
			/*nicename("Machine")*/ _type_machine = 8ui16,
			/*nicename("Control")*/ _type_control = 9ui16,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 10ui16,
			/*nicename("Crate")*/ _type_crate = 11ui16,
			/*nicename("Creature")*/ _type_creature = 12ui16,
			/*nicename("Giant")*/ _type_giant = 13ui16,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 14ui16,
		};

		string_id_legacy nicename("Name") name;
		e_type nicename("Type") type;
		int16_t nicename("Placement Index") placement_index;
	};

	struct nicename("Scenery") s_scenery_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Pathfinding Policy") e_pathfinding_policy : uint16_t
		{
			/*nicename("Tag Default")*/ _pathfinding_policy_tag_default = 0ui16,
			/*nicename("Dynamic")*/ _pathfinding_policy_dynamic = 1ui16,
			/*nicename("Cut-Out")*/ _pathfinding_policy_cut_out = 2ui16,
			/*nicename("Standard")*/ _pathfinding_policy_standard = 3ui16,
			/*nicename("None")*/ _pathfinding_policy_none = 4ui16,
		};

		enum nicename("Lightmapping Policy") e_lightmapping_policy : uint16_t
		{
			/*nicename("Tag Default")*/ _lightmapping_policy_tag_default = 0ui16,
			/*nicename("Dynamic")*/ _lightmapping_policy_dynamic = 1ui16,
			/*nicename("Per-Vertex")*/ _lightmapping_policy_per_vertex = 2ui16,
		};

		enum nicename("Symmetry") e_symmetry : uint32_t
		{
			/*nicename("Both")*/ _symmetry_both = 0ui32,
			/*nicename("Symmetric")*/ _symmetry_symmetric = 1ui32,
			/*nicename("Asymmetric")*/ _symmetry_asymmetric = 2ui32,
		};

		enum nicename("Team") e_team : uint8_t
		{
			/*nicename("Red")*/ _team_red = 0ui8,
			/*nicename("Blue")*/ _team_blue = 1ui8,
			/*nicename("Green")*/ _team_green = 2ui8,
			/*nicename("Orange")*/ _team_orange = 3ui8,
			/*nicename("Purple")*/ _team_purple = 4ui8,
			/*nicename("Yellow")*/ _team_yellow = 5ui8,
			/*nicename("Brown")*/ _team_brown = 6ui8,
			/*nicename("Pink")*/ _team_pink = 7ui8,
			/*nicename("Neutral")*/ _team_neutral = 8ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Multiplayer Flags") b_multiplayer_flags : uint8_t /* bitfield */
		{
			/*nicename("Is Unique Object")*/ _multiplayer_flags_is_unique_object = 1ui8 << 0ui8,
			/*nicename("Not Placed At Start")*/ _multiplayer_flags_not_placed_at_start = 1ui8 << 1ui8,
			/*nicename("Is Gametype-Specific")*/ _multiplayer_flags_is_gametype_specific = 1ui8 << 2ui8,
			/*nicename("Is Shortcut")*/ _multiplayer_flags_is_shortcut = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _multiplayer_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _multiplayer_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _multiplayer_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _multiplayer_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		struct nicename("Node Positioning") s_node_positioning_definition
		{
			struct nicename("Node Flags") s_node_flags_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		struct nicename("Pathfinding References") s_pathfinding_references_definition
		{
			int16_t nicename("BSP Index") bsp_index;
			int16_t nicename("Pathfinding Object Index") pathfinding_object_index;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Scenery Data : 
		e_pathfinding_policy nicename("Pathfinding Policy") pathfinding_policy;
		e_lightmapping_policy nicename("Lightmapping Policy") lightmapping_policy;
		s_tag_block_legacy<s_pathfinding_references_definition> nicename("Pathfinding References") pathfinding_references_block;
		int16_t __unknown11;
		int16_t __unknown12;
		// Multiplayer Data : 
		char nicename("Custom Label") custom_label[32];
		e_symmetry nicename("Symmetry") symmetry;
		int8_t __unknown13;
		e_team nicename("Team") team;
		int16_t __unknown14;
		int8_t nicename("Spawn Sequence") spawn_sequence;
		int8_t nicename("Runtime Minimum") runtime_minimum;
		int8_t nicename("Runtime Maximum") runtime_maximum;
		b_multiplayer_flags nicename("Multiplayer Flags") multiplayer_flags;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		float nicename("Shape Width/Radius") shape_width_radius;
		float nicename("Shape Length") shape_length;
		float nicename("Shape Top") shape_top;
		float nicename("Shape Bottom") shape_bottom;
		e_shape nicename("Shape") shape;
		int8_t __unknown15;
		uint8_t nicename("Teleporter Channel") teleporter_channel;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		string_id_legacy nicename("Location String") location_string;
		int16_t __unknown16;
		int16_t nicename("Attached Name Index") attached_name_index;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		// Unknown Data : 
		s_undefined32_legacy __unknown19;
	};

	struct nicename("Scenery Palette") s_scenery_palette_definition
	{
		s_tag_reference_legacy nicename("Scenery") scenery_reference;
	};

	struct nicename("Bipeds") s_bipeds_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Dead")*/ _flags1_dead = 1ui32 << 0ui32,
			/*nicename("Closed")*/ _flags1_closed = 1ui32 << 1ui32,
			/*nicename("Not Enterable by Player")*/ _flags1_not_enterable_by_player = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Node Positioning") s_node_positioning1_definition
		{
			struct nicename("Node Flags") s_node_flags1_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations1_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable1_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable1_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags1_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations1_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable1_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable1_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning1_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Unit Data : 
		float nicename("Body Vitality Percentage") body_vitality_percentage;
		b_flags1 nicename("Flags") flags;
	};

	struct nicename("Biped Palette") s_biped_palette_definition
	{
		s_tag_reference_legacy nicename("Biped") biped_reference;
	};

	struct nicename("Vehicles") s_vehicles_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Symmetry") e_symmetry : uint32_t
		{
			/*nicename("Both")*/ _symmetry_both = 0ui32,
			/*nicename("Symmetric")*/ _symmetry_symmetric = 1ui32,
			/*nicename("Asymmetric")*/ _symmetry_asymmetric = 2ui32,
		};

		enum nicename("Team") e_team : uint8_t
		{
			/*nicename("Red")*/ _team_red = 0ui8,
			/*nicename("Blue")*/ _team_blue = 1ui8,
			/*nicename("Green")*/ _team_green = 2ui8,
			/*nicename("Orange")*/ _team_orange = 3ui8,
			/*nicename("Purple")*/ _team_purple = 4ui8,
			/*nicename("Yellow")*/ _team_yellow = 5ui8,
			/*nicename("Brown")*/ _team_brown = 6ui8,
			/*nicename("Pink")*/ _team_pink = 7ui8,
			/*nicename("Neutral")*/ _team_neutral = 8ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Dead")*/ _flags1_dead = 1ui32 << 0ui32,
			/*nicename("Closed")*/ _flags1_closed = 1ui32 << 1ui32,
			/*nicename("Not Enterable by Player")*/ _flags1_not_enterable_by_player = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Multiplayer Flags") b_multiplayer_flags : uint8_t /* bitfield */
		{
			/*nicename("Is Unique Object")*/ _multiplayer_flags_is_unique_object = 1ui8 << 0ui8,
			/*nicename("Not Placed At Start")*/ _multiplayer_flags_not_placed_at_start = 1ui8 << 1ui8,
			/*nicename("Is Gametype-Specific")*/ _multiplayer_flags_is_gametype_specific = 1ui8 << 2ui8,
			/*nicename("Is Shortcut")*/ _multiplayer_flags_is_shortcut = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _multiplayer_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _multiplayer_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _multiplayer_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _multiplayer_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		struct nicename("Node Positioning") s_node_positioning2_definition
		{
			struct nicename("Node Flags") s_node_flags2_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations2_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable2_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable2_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags2_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations2_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable2_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable2_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning2_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Unit Data : 
		float nicename("Body Vitality Percentage") body_vitality_percentage;
		b_flags1 nicename("Flags") flags;
		// Multiplayer Data : 
		char nicename("Custom Label") custom_label[32];
		e_symmetry nicename("Symmetry") symmetry;
		int8_t __unknown11;
		e_team nicename("Team") team;
		int16_t __unknown12;
		int8_t nicename("Spawn Sequence") spawn_sequence;
		int8_t nicename("Runtime Minimum") runtime_minimum;
		int8_t nicename("Runtime Maximum") runtime_maximum;
		b_multiplayer_flags nicename("Multiplayer Flags") multiplayer_flags;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		float nicename("Shape Width/Radius") shape_width_radius;
		float nicename("Shape Length") shape_length;
		float nicename("Shape Top") shape_top;
		float nicename("Shape Bottom") shape_bottom;
		e_shape nicename("Shape") shape;
		int8_t __unknown13;
		uint8_t nicename("Teleporter Channel") teleporter_channel;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		string_id_legacy nicename("Location String") location_string;
		int16_t __unknown14;
		int16_t nicename("Attached Name Index") attached_name_index;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		// Unknown Data : 
		s_undefined32_legacy __unknown17;
	};

	struct nicename("Vehicle Palette") s_vehicle_palette_definition
	{
		s_tag_reference_legacy nicename("Vehicle") vehicle_reference;
	};

	struct nicename("Equipment") s_equipment_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Symmetry") e_symmetry : uint32_t
		{
			/*nicename("Both")*/ _symmetry_both = 0ui32,
			/*nicename("Symmetric")*/ _symmetry_symmetric = 1ui32,
			/*nicename("Asymmetric")*/ _symmetry_asymmetric = 2ui32,
		};

		enum nicename("Team") e_team : uint8_t
		{
			/*nicename("Red")*/ _team_red = 0ui8,
			/*nicename("Blue")*/ _team_blue = 1ui8,
			/*nicename("Green")*/ _team_green = 2ui8,
			/*nicename("Orange")*/ _team_orange = 3ui8,
			/*nicename("Purple")*/ _team_purple = 4ui8,
			/*nicename("Yellow")*/ _team_yellow = 5ui8,
			/*nicename("Brown")*/ _team_brown = 6ui8,
			/*nicename("Pink")*/ _team_pink = 7ui8,
			/*nicename("Neutral")*/ _team_neutral = 8ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Equipment Flags") b_equipment_flags : uint32_t /* bitfield */
		{
			/*nicename("Initially At Rest (Does Not Fall)")*/ _equipment_flags_initially_at_rest_does_not_fall = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _equipment_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Does Accelerate (Moves Due to Explosions)")*/ _equipment_flags_does_accelerate_moves_due_to_explosions = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _equipment_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _equipment_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _equipment_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _equipment_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _equipment_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _equipment_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _equipment_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _equipment_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _equipment_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _equipment_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _equipment_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _equipment_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _equipment_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _equipment_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _equipment_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _equipment_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _equipment_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _equipment_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _equipment_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _equipment_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _equipment_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _equipment_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _equipment_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _equipment_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _equipment_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _equipment_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _equipment_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _equipment_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _equipment_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Multiplayer Flags") b_multiplayer_flags : uint8_t /* bitfield */
		{
			/*nicename("Is Unique Object")*/ _multiplayer_flags_is_unique_object = 1ui8 << 0ui8,
			/*nicename("Not Placed At Start")*/ _multiplayer_flags_not_placed_at_start = 1ui8 << 1ui8,
			/*nicename("Is Gametype-Specific")*/ _multiplayer_flags_is_gametype_specific = 1ui8 << 2ui8,
			/*nicename("Is Shortcut")*/ _multiplayer_flags_is_shortcut = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _multiplayer_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _multiplayer_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _multiplayer_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _multiplayer_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		struct nicename("Node Positioning") s_node_positioning3_definition
		{
			struct nicename("Node Flags") s_node_flags3_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations3_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable3_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable3_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags3_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations3_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable3_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable3_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning3_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Equipment Data : 
		b_equipment_flags nicename("Equipment Flags") equipment_flags;
		// Multiplayer Data : 
		char nicename("Custom Label") custom_label[32];
		e_symmetry nicename("Symmetry") symmetry;
		int8_t __unknown8;
		e_team nicename("Team") team;
		int16_t __unknown9;
		int8_t nicename("Spawn Sequence") spawn_sequence;
		int8_t nicename("Runtime Minimum") runtime_minimum;
		int8_t nicename("Runtime Maximum") runtime_maximum;
		b_multiplayer_flags nicename("Multiplayer Flags") multiplayer_flags;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		float nicename("Shape Width/Radius") shape_width_radius;
		float nicename("Shape Length") shape_length;
		float nicename("Shape Top") shape_top;
		float nicename("Shape Bottom") shape_bottom;
		e_shape nicename("Shape") shape;
		int8_t __unknown10;
		uint8_t nicename("Teleporter Channel") teleporter_channel;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		string_id_legacy nicename("Location String") location_string;
		int16_t __unknown11;
		int16_t nicename("Attached Name Index") attached_name_index;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		// Unknown Data : 
		s_undefined32_legacy __unknown14;
	};

	struct nicename("Equipment Palette") s_equipment_palette_definition
	{
		s_tag_reference_legacy nicename("Equipment") equipment_reference;
	};

	struct nicename("Weapons") s_weapons_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Symmetry") e_symmetry : uint32_t
		{
			/*nicename("Both")*/ _symmetry_both = 0ui32,
			/*nicename("Symmetric")*/ _symmetry_symmetric = 1ui32,
			/*nicename("Asymmetric")*/ _symmetry_asymmetric = 2ui32,
		};

		enum nicename("Team") e_team : uint8_t
		{
			/*nicename("Red")*/ _team_red = 0ui8,
			/*nicename("Blue")*/ _team_blue = 1ui8,
			/*nicename("Green")*/ _team_green = 2ui8,
			/*nicename("Orange")*/ _team_orange = 3ui8,
			/*nicename("Purple")*/ _team_purple = 4ui8,
			/*nicename("Yellow")*/ _team_yellow = 5ui8,
			/*nicename("Brown")*/ _team_brown = 6ui8,
			/*nicename("Pink")*/ _team_pink = 7ui8,
			/*nicename("Neutral")*/ _team_neutral = 8ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Weapon Flags") b_weapon_flags : uint32_t /* bitfield */
		{
			/*nicename("Initially At Rest (Does Not Fall)")*/ _weapon_flags_initially_at_rest_does_not_fall = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _weapon_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Does Accelerate (Moves Due to Explosions)")*/ _weapon_flags_does_accelerate_moves_due_to_explosions = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _weapon_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _weapon_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _weapon_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _weapon_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _weapon_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _weapon_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _weapon_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _weapon_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _weapon_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _weapon_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _weapon_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _weapon_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _weapon_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _weapon_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _weapon_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _weapon_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _weapon_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _weapon_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _weapon_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _weapon_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _weapon_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _weapon_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _weapon_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _weapon_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _weapon_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _weapon_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _weapon_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _weapon_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _weapon_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Multiplayer Flags") b_multiplayer_flags : uint8_t /* bitfield */
		{
			/*nicename("Is Unique Object")*/ _multiplayer_flags_is_unique_object = 1ui8 << 0ui8,
			/*nicename("Not Placed At Start")*/ _multiplayer_flags_not_placed_at_start = 1ui8 << 1ui8,
			/*nicename("Is Gametype-Specific")*/ _multiplayer_flags_is_gametype_specific = 1ui8 << 2ui8,
			/*nicename("Is Shortcut")*/ _multiplayer_flags_is_shortcut = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _multiplayer_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _multiplayer_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _multiplayer_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _multiplayer_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		struct nicename("Node Positioning") s_node_positioning4_definition
		{
			struct nicename("Node Flags") s_node_flags4_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations4_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable4_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable4_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags4_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations4_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable4_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable4_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning4_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Weapon Data : 
		int16_t nicename("Rounds Left") rounds_left;
		int16_t nicename("Rounds Loaded") rounds_loaded;
		b_weapon_flags nicename("Weapon Flags") weapon_flags;
		// Multiplayer Data : 
		char nicename("Custom Label") custom_label[32];
		e_symmetry nicename("Symmetry") symmetry;
		int8_t __unknown11;
		e_team nicename("Team") team;
		int16_t __unknown12;
		int8_t nicename("Spawn Sequence") spawn_sequence;
		int8_t nicename("Runtime Minimum") runtime_minimum;
		int8_t nicename("Runtime Maximum") runtime_maximum;
		b_multiplayer_flags nicename("Multiplayer Flags") multiplayer_flags;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		float nicename("Shape Width/Radius") shape_width_radius;
		float nicename("Shape Length") shape_length;
		float nicename("Shape Top") shape_top;
		float nicename("Shape Bottom") shape_bottom;
		e_shape nicename("Shape") shape;
		int8_t __unknown13;
		uint8_t nicename("Teleporter Channel") teleporter_channel;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		string_id_legacy nicename("Location String") location_string;
		int16_t __unknown14;
		int16_t nicename("Attached Name Index") attached_name_index;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		// Unknown Data : 
		s_undefined32_legacy __unknown17;
	};

	struct nicename("Weapon Palette") s_weapon_palette_definition
	{
		s_tag_reference_legacy nicename("Weapon") weapon_reference;
	};

	struct nicename("Device Groups") s_device_groups_definition
	{
		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Only Use Once")*/ _flags1_only_use_once = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		char nicename("Name") name[32];
		float nicename("Initial Value") initial_value;
		b_flags1 nicename("Flags") flags;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown0;
	};

	struct nicename("Machines") s_machines_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Pathfinding Policy") e_pathfinding_policy : uint16_t
		{
			/*nicename("Tag Default")*/ _pathfinding_policy_tag_default = 0ui16,
			/*nicename("Cut-Out")*/ _pathfinding_policy_cut_out = 1ui16,
			/*nicename("Sectors")*/ _pathfinding_policy_sectors = 2ui16,
			/*nicename("Discs")*/ _pathfinding_policy_discs = 3ui16,
			/*nicename("None")*/ _pathfinding_policy_none = 4ui16,
		};

		enum nicename("Symmetry") e_symmetry : uint32_t
		{
			/*nicename("Both")*/ _symmetry_both = 0ui32,
			/*nicename("Symmetric")*/ _symmetry_symmetric = 1ui32,
			/*nicename("Asymmetric")*/ _symmetry_asymmetric = 2ui32,
		};

		enum nicename("Team") e_team : uint8_t
		{
			/*nicename("Red")*/ _team_red = 0ui8,
			/*nicename("Blue")*/ _team_blue = 1ui8,
			/*nicename("Green")*/ _team_green = 2ui8,
			/*nicename("Orange")*/ _team_orange = 3ui8,
			/*nicename("Purple")*/ _team_purple = 4ui8,
			/*nicename("Yellow")*/ _team_yellow = 5ui8,
			/*nicename("Brown")*/ _team_brown = 6ui8,
			/*nicename("Pink")*/ _team_pink = 7ui8,
			/*nicename("Neutral")*/ _team_neutral = 8ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Device Flags") b_device_flags : uint32_t /* bitfield */
		{
			/*nicename("Initially Open")*/ _device_flags_initially_open = 1ui32 << 0ui32,
			/*nicename("Initially Closed")*/ _device_flags_initially_closed = 1ui32 << 1ui32,
			/*nicename("Can Only Change Once")*/ _device_flags_can_only_change_once = 1ui32 << 2ui32,
			/*nicename("Position Reversed")*/ _device_flags_position_reversed = 1ui32 << 3ui32,
			/*nicename("Usable from Both Sides")*/ _device_flags_usable_from_both_sides = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _device_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _device_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _device_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _device_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _device_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _device_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _device_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _device_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _device_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _device_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _device_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _device_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _device_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _device_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _device_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _device_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _device_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _device_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _device_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _device_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _device_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _device_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _device_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _device_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _device_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _device_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _device_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Machine Flags") b_machine_flags : uint32_t /* bitfield */
		{
			/*nicename("Does Not Operate Automatically")*/ _machine_flags_does_not_operate_automatically = 1ui32 << 0ui32,
			/*nicename("One-Sided")*/ _machine_flags_one_sided = 1ui32 << 1ui32,
			/*nicename("Never Appears Locked")*/ _machine_flags_never_appears_locked = 1ui32 << 2ui32,
			/*nicename("Opened by Melee Attack")*/ _machine_flags_opened_by_melee_attack = 1ui32 << 3ui32,
			/*nicename("One Sided for Player")*/ _machine_flags_one_sided_for_player = 1ui32 << 4ui32,
			/*nicename("Does Not Close Automatically")*/ _machine_flags_does_not_close_automatically = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _machine_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _machine_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _machine_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _machine_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _machine_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _machine_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _machine_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _machine_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _machine_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _machine_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _machine_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _machine_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _machine_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _machine_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _machine_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _machine_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _machine_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _machine_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _machine_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _machine_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _machine_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _machine_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _machine_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _machine_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _machine_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _machine_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Multiplayer Flags") b_multiplayer_flags : uint8_t /* bitfield */
		{
			/*nicename("Is Unique Object")*/ _multiplayer_flags_is_unique_object = 1ui8 << 0ui8,
			/*nicename("Not Placed At Start")*/ _multiplayer_flags_not_placed_at_start = 1ui8 << 1ui8,
			/*nicename("Is Gametype-Specific")*/ _multiplayer_flags_is_gametype_specific = 1ui8 << 2ui8,
			/*nicename("Is Shortcut")*/ _multiplayer_flags_is_shortcut = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _multiplayer_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _multiplayer_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _multiplayer_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _multiplayer_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		struct nicename("Node Positioning") s_node_positioning5_definition
		{
			struct nicename("Node Flags") s_node_flags5_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations5_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable5_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable5_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags5_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations5_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable5_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable5_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		struct nicename("Pathfinding References") s_pathfinding_references1_definition
		{
			int16_t nicename("BSP Index") bsp_index;
			int16_t nicename("Pathfinding Object Index") pathfinding_object_index;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning5_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Device Data : 
		int16_t nicename("Power Group") power_group;
		int16_t nicename("Position Group") position_group;
		b_device_flags nicename("Device Flags") device_flags;
		// Machine Data : 
		b_machine_flags nicename("Machine Flags") machine_flags;
		s_tag_block_legacy<s_pathfinding_references1_definition> nicename("Pathfinding References") pathfinding_references_block;
		e_pathfinding_policy nicename("Pathfinding Policy") pathfinding_policy;
		int16_t __unknown11;
		// Multiplayer Data : 
		char nicename("Custom Label") custom_label[32];
		e_symmetry nicename("Symmetry") symmetry;
		int8_t __unknown12;
		e_team nicename("Team") team;
		int16_t __unknown13;
		int8_t nicename("Spawn Sequence") spawn_sequence;
		int8_t nicename("Runtime Minimum") runtime_minimum;
		int8_t nicename("Runtime Maximum") runtime_maximum;
		b_multiplayer_flags nicename("Multiplayer Flags") multiplayer_flags;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		float nicename("Shape Width/Radius") shape_width_radius;
		float nicename("Shape Length") shape_length;
		float nicename("Shape Top") shape_top;
		float nicename("Shape Bottom") shape_bottom;
		e_shape nicename("Shape") shape;
		int8_t __unknown14;
		uint8_t nicename("Teleporter Channel") teleporter_channel;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		string_id_legacy nicename("Location String") location_string;
		int16_t __unknown15;
		int16_t nicename("Attached Name Index") attached_name_index;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
	};

	struct nicename("Machine Palette") s_machine_palette_definition
	{
		s_tag_reference_legacy nicename("Machine") machine_reference;
	};

	struct nicename("Terminals") s_terminals_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Device Flags") b_device_flags : uint32_t /* bitfield */
		{
			/*nicename("Initially Open")*/ _device_flags_initially_open = 1ui32 << 0ui32,
			/*nicename("Initially Closed")*/ _device_flags_initially_closed = 1ui32 << 1ui32,
			/*nicename("Can Only Change Once")*/ _device_flags_can_only_change_once = 1ui32 << 2ui32,
			/*nicename("Position Reversed")*/ _device_flags_position_reversed = 1ui32 << 3ui32,
			/*nicename("Usable from Both Sides")*/ _device_flags_usable_from_both_sides = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _device_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _device_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _device_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _device_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _device_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _device_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _device_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _device_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _device_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _device_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _device_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _device_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _device_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _device_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _device_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _device_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _device_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _device_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _device_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _device_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _device_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _device_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _device_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _device_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _device_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _device_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _device_flags_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Node Positioning") s_node_positioning6_definition
		{
			struct nicename("Node Flags") s_node_flags6_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations6_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable6_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable6_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags6_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations6_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable6_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable6_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning6_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Device Data : 
		int16_t nicename("Power Group") power_group;
		int16_t nicename("Position Group") position_group;
		b_device_flags nicename("Device Flags") device_flags;
		// Terminal Data : 
		s_undefined32_legacy __unknown11;
	};

	struct nicename("Terminal Palette") s_terminal_palette_definition
	{
		s_tag_reference_legacy nicename("Terminal") terminal_reference;
	};

	struct nicename("Controls") s_controls_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Symmetry") e_symmetry : uint32_t
		{
			/*nicename("Both")*/ _symmetry_both = 0ui32,
			/*nicename("Symmetric")*/ _symmetry_symmetric = 1ui32,
			/*nicename("Asymmetric")*/ _symmetry_asymmetric = 2ui32,
		};

		enum nicename("Team") e_team : uint8_t
		{
			/*nicename("Red")*/ _team_red = 0ui8,
			/*nicename("Blue")*/ _team_blue = 1ui8,
			/*nicename("Green")*/ _team_green = 2ui8,
			/*nicename("Orange")*/ _team_orange = 3ui8,
			/*nicename("Purple")*/ _team_purple = 4ui8,
			/*nicename("Yellow")*/ _team_yellow = 5ui8,
			/*nicename("Brown")*/ _team_brown = 6ui8,
			/*nicename("Pink")*/ _team_pink = 7ui8,
			/*nicename("Neutral")*/ _team_neutral = 8ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Device Flags") b_device_flags : uint32_t /* bitfield */
		{
			/*nicename("Initially Open")*/ _device_flags_initially_open = 1ui32 << 0ui32,
			/*nicename("Initially Closed")*/ _device_flags_initially_closed = 1ui32 << 1ui32,
			/*nicename("Can Only Change Once")*/ _device_flags_can_only_change_once = 1ui32 << 2ui32,
			/*nicename("Position Reversed")*/ _device_flags_position_reversed = 1ui32 << 3ui32,
			/*nicename("Usable from Both Sides")*/ _device_flags_usable_from_both_sides = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _device_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _device_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _device_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _device_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _device_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _device_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _device_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _device_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _device_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _device_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _device_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _device_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _device_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _device_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _device_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _device_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _device_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _device_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _device_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _device_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _device_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _device_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _device_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _device_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _device_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _device_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _device_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Control Flags") b_control_flags : uint32_t /* bitfield */
		{
			/*nicename("Usable From Both Sides")*/ _control_flags_usable_from_both_sides = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _control_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _control_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _control_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _control_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _control_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _control_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _control_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _control_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _control_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _control_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _control_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _control_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _control_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _control_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _control_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _control_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _control_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _control_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _control_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _control_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _control_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _control_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _control_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _control_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _control_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _control_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _control_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _control_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _control_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _control_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _control_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Multiplayer Flags") b_multiplayer_flags : uint8_t /* bitfield */
		{
			/*nicename("Is Unique Object")*/ _multiplayer_flags_is_unique_object = 1ui8 << 0ui8,
			/*nicename("Not Placed At Start")*/ _multiplayer_flags_not_placed_at_start = 1ui8 << 1ui8,
			/*nicename("Is Gametype-Specific")*/ _multiplayer_flags_is_gametype_specific = 1ui8 << 2ui8,
			/*nicename("Is Shortcut")*/ _multiplayer_flags_is_shortcut = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _multiplayer_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _multiplayer_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _multiplayer_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _multiplayer_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		struct nicename("Node Positioning") s_node_positioning7_definition
		{
			struct nicename("Node Flags") s_node_flags7_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations7_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable7_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable7_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags7_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations7_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable7_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable7_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning7_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Device Data : 
		int16_t nicename("Power Group") power_group;
		int16_t nicename("Position Group") position_group;
		b_device_flags nicename("Device Flags") device_flags;
		// Control Data : 
		int32_t __unknown11;
		b_control_flags nicename("Control Flags") control_flags;
		int16_t __unknown12;
		int16_t __unknown13;
		// Multiplayer Data : 
		char nicename("Custom Label") custom_label[32];
		e_symmetry nicename("Symmetry") symmetry;
		int8_t __unknown14;
		e_team nicename("Team") team;
		int16_t __unknown15;
		int8_t nicename("Spawn Sequence") spawn_sequence;
		int8_t nicename("Runtime Minimum") runtime_minimum;
		int8_t nicename("Runtime Maximum") runtime_maximum;
		b_multiplayer_flags nicename("Multiplayer Flags") multiplayer_flags;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		float nicename("Shape Width/Radius") shape_width_radius;
		float nicename("Shape Length") shape_length;
		float nicename("Shape Top") shape_top;
		float nicename("Shape Bottom") shape_bottom;
		e_shape nicename("Shape") shape;
		int8_t __unknown16;
		uint8_t nicename("Teleporter Channel") teleporter_channel;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		string_id_legacy nicename("Location String") location_string;
		int16_t __unknown17;
		int16_t nicename("Attached Name Index") attached_name_index;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		// Unknown Data : 
		s_undefined32_legacy __unknown20;
	};

	struct nicename("Control Palette") s_control_palette_definition
	{
		s_tag_reference_legacy nicename("Control") control_reference;
	};

	struct nicename("Sound Scenery") s_sound_scenery_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		struct nicename("Node Positioning") s_node_positioning8_definition
		{
			struct nicename("Node Flags") s_node_flags8_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations8_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable8_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable8_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags8_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations8_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable8_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable8_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning8_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Sound Scenery Data : 
		int32_t nicename("Volume Type") volume_type;
		s_undefined32_legacy __unknown8;
		float __unknown9;
		float __unknown10;
		s_undefined32_legacy __unknown11;
		float __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		float __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		float __unknown18;
	};

	struct nicename("Sound Scenery Palette") s_sound_scenery_palette_definition
	{
		s_tag_reference_legacy nicename("Sound Scenery") sound_scenery_reference;
	};

	struct nicename("Giants") s_giants_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Dead")*/ _flags1_dead = 1ui32 << 0ui32,
			/*nicename("Closed")*/ _flags1_closed = 1ui32 << 1ui32,
			/*nicename("Not Enterable by Player")*/ _flags1_not_enterable_by_player = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Node Positioning") s_node_positioning9_definition
		{
			struct nicename("Node Flags") s_node_flags9_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations9_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable9_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable9_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags9_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations9_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable9_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable9_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		struct nicename("Pathfinding References") s_pathfinding_references2_definition
		{
			int16_t nicename("BSP Index") bsp_index;
			int16_t nicename("Pathfinding Object Index") pathfinding_object_index;
		};

		// Note : This block is based off the layout of H3/ODST's block. May be incorrect.
		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning9_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Unit Data : 
		float nicename("Body Vitality Percentage") body_vitality_percentage;
		b_flags1 nicename("Flags") flags;
		// Giant Data : 
		int16_t __unknown11;
		int16_t __unknown12;
		s_tag_block_legacy<s_pathfinding_references2_definition> nicename("Pathfinding References") pathfinding_references_block;
	};

	struct nicename("Giant Palette") s_giant_palette_definition
	{
		s_tag_reference_legacy nicename("Giant") giant_reference;
	};

	struct nicename("Effect Scenery") s_effect_scenery_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Symmetry") e_symmetry : uint32_t
		{
			/*nicename("Both")*/ _symmetry_both = 0ui32,
			/*nicename("Symmetric")*/ _symmetry_symmetric = 1ui32,
			/*nicename("Asymmetric")*/ _symmetry_asymmetric = 2ui32,
		};

		enum nicename("Team") e_team : uint8_t
		{
			/*nicename("Red")*/ _team_red = 0ui8,
			/*nicename("Blue")*/ _team_blue = 1ui8,
			/*nicename("Green")*/ _team_green = 2ui8,
			/*nicename("Orange")*/ _team_orange = 3ui8,
			/*nicename("Purple")*/ _team_purple = 4ui8,
			/*nicename("Yellow")*/ _team_yellow = 5ui8,
			/*nicename("Brown")*/ _team_brown = 6ui8,
			/*nicename("Pink")*/ _team_pink = 7ui8,
			/*nicename("Neutral")*/ _team_neutral = 8ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Multiplayer Flags") b_multiplayer_flags : uint8_t /* bitfield */
		{
			/*nicename("Is Unique Object")*/ _multiplayer_flags_is_unique_object = 1ui8 << 0ui8,
			/*nicename("Not Placed At Start")*/ _multiplayer_flags_not_placed_at_start = 1ui8 << 1ui8,
			/*nicename("Is Gametype-Specific")*/ _multiplayer_flags_is_gametype_specific = 1ui8 << 2ui8,
			/*nicename("Is Shortcut")*/ _multiplayer_flags_is_shortcut = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _multiplayer_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _multiplayer_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _multiplayer_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _multiplayer_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		struct nicename("Node Positioning") s_node_positioning10_definition
		{
			struct nicename("Node Flags") s_node_flags10_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations10_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable10_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable10_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags10_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations10_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable10_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable10_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning10_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Multiplayer Data : 
		char nicename("Custom Label") custom_label[32];
		e_symmetry nicename("Symmetry") symmetry;
		int8_t __unknown8;
		e_team nicename("Team") team;
		int16_t __unknown9;
		int8_t nicename("Spawn Sequence") spawn_sequence;
		int8_t nicename("Runtime Minimum") runtime_minimum;
		int8_t nicename("Runtime Maximum") runtime_maximum;
		b_multiplayer_flags nicename("Multiplayer Flags") multiplayer_flags;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		float nicename("Shape Width/Radius") shape_width_radius;
		float nicename("Shape Length") shape_length;
		float nicename("Shape Top") shape_top;
		float nicename("Shape Bottom") shape_bottom;
		e_shape nicename("Shape") shape;
		int8_t __unknown10;
		uint8_t nicename("Teleporter Channel") teleporter_channel;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		string_id_legacy nicename("Location String") location_string;
		int16_t __unknown11;
		int16_t nicename("Attached Name Index") attached_name_index;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		// Unknown Data : 
		s_undefined32_legacy __unknown14;
	};

	struct nicename("Effect Scenery Palette") s_effect_scenery_palette_definition
	{
		s_tag_reference_legacy nicename("Effect Scenery") effect_scenery_reference;
	};

	struct nicename("Light Volumes") s_light_volumes_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Type") e_type1 : uint16_t
		{
			/*nicename("Sphere")*/ _type1_sphere = 0ui16,
			/*nicename("Projective")*/ _type1_projective = 1ui16,
		};

		enum nicename("Lightmap Type") e_lightmap_type : uint16_t
		{
			/*nicename("Use Light Tag Setting")*/ _lightmap_type_use_light_tag_setting = 0ui16,
			/*nicename("Dynamic Only")*/ _lightmap_type_dynamic_only = 1ui16,
			/*nicename("Dynamic With Lightmaps")*/ _lightmap_type_dynamic_with_lightmaps = 2ui16,
			/*nicename("Lightmaps Only")*/ _lightmap_type_lightmaps_only = 3ui16,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Device Flags") b_device_flags : uint32_t /* bitfield */
		{
			/*nicename("Initially Open")*/ _device_flags_initially_open = 1ui32 << 0ui32,
			/*nicename("Initially Closed")*/ _device_flags_initially_closed = 1ui32 << 1ui32,
			/*nicename("Can Only Change Once")*/ _device_flags_can_only_change_once = 1ui32 << 2ui32,
			/*nicename("Position Reversed")*/ _device_flags_position_reversed = 1ui32 << 3ui32,
			/*nicename("Usable from Both Sides")*/ _device_flags_usable_from_both_sides = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _device_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _device_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _device_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _device_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _device_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _device_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _device_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _device_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _device_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _device_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _device_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _device_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _device_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _device_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _device_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _device_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _device_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _device_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _device_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _device_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _device_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _device_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _device_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _device_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _device_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _device_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _device_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
		{
			/*nicename("Custom Geometry")*/ _flags1_custom_geometry = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui16 << 1ui16,
			/*nicename("Cinematic Only")*/ _flags1_cinematic_only = 1ui16 << 2ui16,
		};

		enum nicename("Lightmap Flags") b_lightmap_flags : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _lightmap_flags_bit_0 = 1ui16 << 0ui16,
		};

		struct nicename("Node Positioning") s_node_positioning11_definition
		{
			struct nicename("Node Flags") s_node_flags11_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations11_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable11_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable11_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags11_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations11_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable11_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable11_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning11_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Device Data : 
		int16_t nicename("Power Group") power_group;
		int16_t nicename("Position Group") position_group;
		b_device_flags nicename("Device Flags") device_flags;
		// Light Data : 
		e_type1 nicename("Type") type1;
		b_flags1 nicename("Flags") flags;
		e_lightmap_type nicename("Lightmap Type") lightmap_type;
		b_lightmap_flags nicename("Lightmap Flags") lightmap_flags;
		float nicename("Lightmap Half Life") lightmap_half_life;
		float nicename("Lightmap Light Scale") lightmap_light_scale;
		float nicename("X") x;
		float nicename("Y") y;
		float nicename("Z") z;
		float nicename("Width") width;
		float nicename("Height Scale") height_scale;
		float nicename("Field of View") field_of_view;
		float nicename("Falloff Distance") falloff_distance;
		float nicename("Cutoff Distance") cutoff_distance;
	};

	struct nicename("Light Volumes Palette") s_light_volumes_palette_definition
	{
		s_tag_reference_legacy nicename("Light Volume") light_volume_reference;
	};

	struct nicename("Sandbox Palette") s_sandbox_palette_definition
	{
		enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
		{
			/*nicename("Hidden")*/ _flags1_hidden = 1ui8 << 0ui8,
		};

		struct nicename("Entries") s_entries_definition
		{
			struct nicename("Entry Variants") s_entry_variants_definition
			{
				string_id_legacy nicename("Name") name;
				s_tag_reference_legacy nicename("Palette Object") palette_object_reference;
				string_id_legacy nicename("Palette Object Variant") palette_object_variant;
			};

			string_id_legacy nicename("Name") name;
			s_tag_block_legacy<s_entry_variants_definition> nicename("Entry Variants") entry_variants_block;
			int32_t nicename("Entry Count") entry_count;
			int32_t nicename("Entry Price") entry_price;
			int8_t nicename("Thorage") thorage;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		b_flags1 nicename("Flags") flags;
		int8_t __unknown0;
		int8_t nicename("Thorage") thorage;
		int8_t __unknown1;
		s_tag_block_legacy<s_entries_definition> nicename("Entries") entries_block;
	};

	struct nicename("Legacy Sandbox Info") s_legacy_sandbox_info_definition
	{
		struct nicename("Builds") s_builds_definition
		{
			uint32_t __unknown0;
			int32_t nicename("Quota Count") quota_count;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			char nicename("Build Number") build_number[32];
		};

		s_tag_block_legacy<s_builds_definition> nicename("Builds") builds_block;
	};

	struct nicename("Soft Ceilings") s_soft_ceilings_definition
	{
		int16_t nicename("Type") type;
		int16_t __unknown0;
		string_id_legacy nicename("Name") name;
		int16_t __unknown1;
		int16_t __unknown2;
	};

	struct nicename("Player Starting Profile") s_player_starting_profile_definition
	{
		char nicename("Name") name[32];
		float nicename("Starting Health Damage") starting_health_damage;
		float nicename("Starting Shield Damage") starting_shield_damage;
		s_tag_reference_legacy nicename("Primary Weapon") primary_weapon_reference;
		int16_t nicename("Rounds Loaded") rounds_loaded;
		int16_t nicename("Rounds Total") rounds_total;
		s_tag_reference_legacy nicename("Secondary Weapon") secondary_weapon_reference;
		int16_t nicename("Rounds Loaded") rounds_loaded1;
		int16_t nicename("Rounds Total") rounds_total1;
		uint8_t nicename("Starting Frag Grenade Count") starting_frag_grenade_count;
		uint8_t nicename("Starting Plasma Grenade Count") starting_plasma_grenade_count;
		uint8_t nicename("Starting Unused Grenade Count") starting_unused_grenade_count;
		uint8_t nicename("Starting Unused Grenade Count") starting_unused_grenade_count1;
		s_tag_reference_legacy nicename("Equipment") equipment_reference;
		int16_t __unknown0;
		int16_t __unknown1;
	};

	struct nicename("Player Starting Locations") s_player_starting_locations_definition
	{
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Facing y") facing_y;
		float nicename("Facing p") facing_p;
		int16_t __unknown0;
		int16_t __unknown1;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown2;
	};

	struct nicename("Trigger Volumes") s_trigger_volumes_definition
	{
		struct nicename("Unknown") s_unknown8_definition
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
			float __unknown4;
		};

		struct nicename("Unknown") s_unknown9_definition
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			float __unknown2;
			float __unknown3;
			s_undefined32_legacy __unknown4;
			s_undefined32_legacy __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			float __unknown9;
			s_undefined32_legacy __unknown10;
			float __unknown11;
			float __unknown12;
			float __unknown13;
			s_undefined32_legacy __unknown14;
			float __unknown15;
			float __unknown16;
			float __unknown17;
			s_undefined32_legacy __unknown18;
			float __unknown19;
			float __unknown20;
			float __unknown21;
			float __unknown22;
			float __unknown23;
			float __unknown24;
			float __unknown25;
			s_undefined32_legacy __unknown26;
			s_undefined32_legacy __unknown27;
		};

		string_id_legacy nicename("Name") name;
		int16_t nicename("Object Name") object_name;
		int16_t __unknown0;
		string_id_legacy nicename("Node Name") node_name;
		int16_t __unknown1;
		int16_t __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Extents x") extents_x;
		float nicename("Extents y") extents_y;
		float nicename("Extents z") extents_z;
		float __unknown9;
		s_tag_block_legacy<s_unknown8_definition> __unknown10;
		s_tag_block_legacy<s_unknown9_definition> __unknown11;
		float __unknown12;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
		float __unknown18;
		int16_t nicename("Kill Volume") kill_volume;
		int16_t nicename("Editor Folder Index") editor_folder_index;
	};

	struct nicename("Unknown 22") s_unknown_22_definition
	{
		struct nicename("Unknown 23") s_unknown_23_definition
		{
			float nicename("X") x;
			float nicename("Y") y;
			float nicename("Z") z;
		};

		s_tag_block_legacy<s_unknown_23_definition> nicename("Unknown 23") unknown_23_block;
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		int16_t __unknown8;
		int16_t __unknown9;
		float __unknown10;
		float __unknown11;
	};

	struct nicename("Unknown 23") s_unknown_231_definition
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		int16_t __unknown13;
		int16_t __unknown14;
		int16_t __unknown15;
		int16_t __unknown16;
		int16_t __unknown17;
		int16_t __unknown18;
		int16_t __unknown19;
		int16_t __unknown20;
	};

	struct nicename("Unknown 28") s_unknown_28_definition
	{
		struct nicename("Unknown 29") s_unknown_29_definition
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			s_undefined32_legacy __unknown3;
			s_undefined32_legacy __unknown4;
		};

		struct nicename("Unknown 30") s_unknown_30_definition
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			s_undefined32_legacy __unknown3;
			s_undefined32_legacy __unknown4;
		};

		s_tag_block_legacy<s_unknown_29_definition> nicename("Unknown 29") unknown_29_block;
		s_tag_block_legacy<s_unknown_30_definition> nicename("Unknown 30") unknown_30_block;
		float __unknown0;
		float __unknown1;
		float __unknown2;
		s_undefined32_legacy __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		int16_t __unknown8;
		int16_t __unknown9;
	};

	struct nicename("Zoneset Switch Trigger Volumes") s_zoneset_switch_trigger_volumes_definition
	{
		int16_t __unknown0;
		int16_t nicename("Included Zoneset Index") included_zoneset_index;
		int16_t nicename("Trigger Volume") trigger_volume;
		int16_t nicename("Sole Zoneset Index") sole_zoneset_index;
	};

	struct nicename("Location Name Callouts") s_location_name_callouts_definition
	{
		struct nicename("Location Bounds Points") s_location_bounds_points_definition
		{
			float nicename("X") x;
			float nicename("Y") y;
			float nicename("Z") z;
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
		};

		s_tag_block_legacy<s_location_bounds_points_definition> nicename("Location Bounds Points") location_bounds_points_block;
		float __unknown0;
		float __unknown1;
		string_id_legacy nicename("Name") name;
	};

	struct nicename("Unknown 40") s_unknown_40_definition
	{
		float __unknown0;
		float __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
	};

	struct nicename("Unknown 40") s_unknown_401_definition
	{
		float __unknown0;
		float __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
	};

	struct nicename("Unknown 40") s_unknown_402_definition
	{
		float __unknown0;
		float __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
	};

	struct nicename("Unknown 41") s_unknown_41_definition
	{
		float __unknown0;
		float __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
	};

	struct nicename("Decals") s_decals_definition
	{
		int16_t nicename("Palette Index") palette_index;
		int8_t nicename("Yaw") yaw;
		int8_t nicename("Pitch") pitch;
		float nicename("i") i;
		float nicename("j") j;
		float nicename("k") k;
		float nicename("w") w;
		float nicename("X") x;
		float nicename("Y") y;
		float nicename("Z") z;
		float nicename("Scale min") scale_min;
		float nicename("Scale max") scale_max;
	};

	struct nicename("Decal Palette") s_decal_palette_definition
	{
		s_tag_reference_legacy nicename("Decal") decal_reference;
	};

	struct nicename("Squad Groups") s_squad_groups_definition
	{
		char nicename("Name") name[32];
		int16_t nicename("Parent Index") parent_index;
		int16_t nicename("Objective Index") objective_index;
		int16_t __unknown0;
		int16_t nicename("Editor Folder Index") editor_folder_index;
	};

	struct nicename("Squads") s_squads_definition
	{
		enum nicename("Team") e_team : uint16_t
		{
			/*nicename("Default")*/ _team_default = 0ui16,
			/*nicename("Player")*/ _team_player = 1ui16,
			/*nicename("Human")*/ _team_human = 2ui16,
			/*nicename("Covenant")*/ _team_covenant = 3ui16,
			/*nicename("Brute")*/ _team_brute = 4ui16,
			/*nicename("Mule")*/ _team_mule = 5ui16,
			/*nicename("Spare")*/ _team_spare = 6ui16,
			/*nicename("Covenant Player")*/ _team_covenant_player = 7ui16,
		};

		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags1_bit_0 = 1ui32 << 0ui32,
			/*nicename("Blind")*/ _flags1_blind = 1ui32 << 1ui32,
			/*nicename("Deaf")*/ _flags1_deaf = 1ui32 << 2ui32,
			/*nicename("Braindead")*/ _flags1_braindead = 1ui32 << 3ui32,
			/*nicename("Initially Placed")*/ _flags1_initially_placed = 1ui32 << 4ui32,
			/*nicename("Units Not Enterable By Player")*/ _flags1_units_not_enterable_by_player = 1ui32 << 5ui32,
			/*nicename("Dynamic Firefight Squad")*/ _flags1_dynamic_firefight_squad = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Group Locations") s_group_locations_definition
		{
			struct nicename("Multi-State") s_multi_state_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				float __unknown2;
				float __unknown3;
				string_id_legacy nicename("State") state;
				s_undefined32_legacy __unknown4;
				string_id_legacy nicename("Command Script Name") command_script_name;
				int16_t nicename("Command Script Index") command_script_index;
				int16_t __unknown5;
			};

			int16_t __unknown0;
			int16_t __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
			string_id_legacy nicename("Name") name;
			float nicename("Position x") position_x;
			float nicename("Position y") position_y;
			float nicename("Position z") position_z;
			int16_t nicename("Reference Frame") reference_frame;
			int16_t __unknown4;
			float nicename("Facing i") facing_i;
			float nicename("Facing j") facing_j;
			float nicename("Facing k") facing_k;
			string_id_legacy nicename("Formation Type") formation_type;
			float __unknown5;
			int16_t __unknown6;
			int16_t nicename("Command Script Index") command_script_index;
			string_id_legacy nicename("Command Script Name") command_script_name;
			string_id_legacy nicename("Initial State") initial_state;
			int16_t __unknown7;
			int16_t __unknown8;
			int16_t __unknown9;
			int16_t __unknown10;
			s_tag_block_legacy<s_multi_state_definition> nicename("Multi-State") multi_state_block;
		};

		struct nicename("Single Locations") s_single_locations_definition
		{
			enum nicename("Seat Type") e_seat_type : uint16_t
			{
				/*nicename("Default")*/ _seat_type_default = 0ui16,
				/*nicename("Spawn In Passenger")*/ _seat_type_spawn_in_passenger = 1ui16,
				/*nicename("Spawn In Gunner")*/ _seat_type_spawn_in_gunner = 2ui16,
				/*nicename("Spawn In Driver")*/ _seat_type_spawn_in_driver = 3ui16,
				/*nicename("Spawn Out Of Vehicle")*/ _seat_type_spawn_out_of_vehicle = 4ui16,
				/*nicename("Spawn Vehicle Only")*/ _seat_type_spawn_vehicle_only = 5ui16,
				/*nicename("Spawn In Passenger")*/ _seat_type_spawn_in_passenger1 = 6ui16,
			};

			enum nicename("Grenade Type") e_grenade_type : uint16_t
			{
				/*nicename("None")*/ _grenade_type_none = 0ui16,
				/*nicename("Frag")*/ _grenade_type_frag = 1ui16,
				/*nicename("Plasma")*/ _grenade_type_plasma = 2ui16,
			};

			enum nicename("Initial Movement Mode") e_initial_movement_mode : uint16_t
			{
				/*nicename("Default")*/ _initial_movement_mode_default = 0ui16,
				/*nicename("Climbing")*/ _initial_movement_mode_climbing = 1ui16,
				/*nicename("Flying")*/ _initial_movement_mode_flying = 2ui16,
			};

			enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _flags1_bit_0 = 1ui16 << 0ui16,
				/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui16 << 1ui16,
				/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui16 << 2ui16,
				/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui16 << 3ui16,
				/*nicename("Kill Vehicle If No Driver")*/ _flags1_kill_vehicle_if_no_driver = 1ui16 << 4ui16,
				/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui16 << 5ui16,
				/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui16 << 6ui16,
				/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui16 << 7ui16,
				/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui16 << 8ui16,
				/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui16 << 9ui16,
				/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui16 << 10ui16,
				/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui16 << 11ui16,
				/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui16 << 12ui16,
				/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui16 << 13ui16,
				/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui16 << 14ui16,
				/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui16 << 15ui16,
			};

			struct nicename("Multi-State") s_multi_state1_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				float __unknown2;
				float __unknown3;
				string_id_legacy nicename("State") state;
				s_undefined32_legacy __unknown4;
				string_id_legacy nicename("Command Script Name") command_script_name;
				int16_t nicename("Command Script Index") command_script_index;
				int16_t __unknown5;
			};

			int16_t __unknown0;
			int16_t __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
			string_id_legacy nicename("Name") name;
			int16_t nicename("Squad Member Index") squad_member_index;
			int16_t __unknown4;
			float nicename("Position x") position_x;
			float nicename("Position y") position_y;
			float nicename("Position z") position_z;
			int16_t nicename("Reference Frame") reference_frame;
			int16_t __unknown5;
			float nicename("Facing i") facing_i;
			float nicename("Facing j") facing_j;
			float nicename("Facing k") facing_k;
			b_flags1 nicename("Flags") flags;
			int16_t nicename("Character Type") character_type;
			int16_t nicename("Initial Primary Weapon") initial_primary_weapon;
			int16_t nicename("Initial Secondary Weapon") initial_secondary_weapon;
			int16_t nicename("Initial Equipment") initial_equipment;
			int16_t nicename("Vehicle") vehicle;
			e_seat_type nicename("Seat Type") seat_type;
			e_grenade_type nicename("Grenade Type") grenade_type;
			int16_t nicename("Swarm Count") swarm_count;
			int16_t __unknown6;
			string_id_legacy nicename("Actor Variant") actor_variant;
			string_id_legacy nicename("Vehicle Variant") vehicle_variant;
			string_id_legacy __unknown7;
			float nicename("Initial Movement Distance") initial_movement_distance;
			e_initial_movement_mode nicename("Initial Movement Mode") initial_movement_mode;
			int16_t nicename("Emitter Vehicle") emitter_vehicle;
			int16_t nicename("Emitter Giant") emitter_giant;
			int16_t nicename("Emitter Biped") emitter_biped;
			string_id_legacy nicename("Command Script Name") command_script_name;
			int16_t nicename("Command Script Index") command_script_index;
			int16_t __unknown8;
			string_id_legacy nicename("Initial State") initial_state;
			int16_t __unknown9;
			int16_t __unknown10;
			int16_t __unknown11;
			int16_t __unknown12;
			s_tag_block_legacy<s_multi_state1_definition> nicename("Multi-State") multi_state_block;
		};

		struct nicename("Squad A") s_squad_a_definition
		{
			enum nicename("Difficulty") b_difficulty : uint16_t /* bitfield */
			{
				/*nicename("Easy")*/ _difficulty_easy = 1ui16 << 0ui16,
				/*nicename("Normal")*/ _difficulty_normal = 1ui16 << 1ui16,
				/*nicename("Heroic")*/ _difficulty_heroic = 1ui16 << 2ui16,
				/*nicename("Legendary")*/ _difficulty_legendary = 1ui16 << 3ui16,
				/*nicename("Bit 4")*/ _difficulty_bit_4 = 1ui16 << 4ui16,
				/*nicename("Bit 5")*/ _difficulty_bit_5 = 1ui16 << 5ui16,
				/*nicename("Bit 6")*/ _difficulty_bit_6 = 1ui16 << 6ui16,
				/*nicename("Bit 7")*/ _difficulty_bit_7 = 1ui16 << 7ui16,
				/*nicename("Bit 8")*/ _difficulty_bit_8 = 1ui16 << 8ui16,
				/*nicename("Bit 9")*/ _difficulty_bit_9 = 1ui16 << 9ui16,
				/*nicename("Bit 10")*/ _difficulty_bit_10 = 1ui16 << 10ui16,
				/*nicename("Bit 11")*/ _difficulty_bit_11 = 1ui16 << 11ui16,
				/*nicename("Bit 12")*/ _difficulty_bit_12 = 1ui16 << 12ui16,
				/*nicename("Bit 13")*/ _difficulty_bit_13 = 1ui16 << 13ui16,
				/*nicename("Bit 14")*/ _difficulty_bit_14 = 1ui16 << 14ui16,
				/*nicename("Bit 15")*/ _difficulty_bit_15 = 1ui16 << 15ui16,
			};

			struct nicename("Actors") s_actors_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t nicename("Minimum Round") minimum_round;
				int16_t nicename("Maximum Round") maximum_round;
				s_undefined32_legacy __unknown2;
				int16_t nicename("Character") character;
				int16_t nicename("Probability") probability;
			};

			struct nicename("Weapons") s_weapons1_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t nicename("Minimum Round") minimum_round;
				int16_t nicename("Maximum Round") maximum_round;
				s_undefined32_legacy __unknown2;
				int16_t nicename("Weapon") weapon;
				int16_t nicename("Probability") probability;
			};

			struct nicename("Secondary Weapons") s_secondary_weapons_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t nicename("Minimum Round") minimum_round;
				int16_t nicename("Maximum Round") maximum_round;
				s_undefined32_legacy __unknown2;
				int16_t nicename("Weapon") weapon;
				int16_t nicename("Probability") probability;
			};

			struct nicename("Equipment") s_equipment1_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t nicename("Minimum Round") minimum_round;
				int16_t nicename("Maximum Round") maximum_round;
				s_undefined32_legacy __unknown2;
				int16_t nicename("Equipment") equipment;
				int16_t nicename("Probability") probability;
			};

			string_id_legacy nicename("Name") name;
			b_difficulty nicename("Difficulty") difficulty;
			int16_t __unknown0;
			int16_t nicename("Minimum Round") minimum_round;
			int16_t nicename("Maximum Round") maximum_round;
			int16_t __unknown1;
			int16_t __unknown2;
			int16_t nicename("Count") count;
			int16_t __unknown3;
			s_tag_block_legacy<s_actors_definition> nicename("Actors") actors_block;
			s_tag_block_legacy<s_weapons1_definition> nicename("Weapons") weapons_block;
			s_tag_block_legacy<s_secondary_weapons_definition> nicename("Secondary Weapons") secondary_weapons_block;
			s_tag_block_legacy<s_equipment1_definition> nicename("Equipment") equipment_block;
			int16_t __unknown4;
			int16_t nicename("Vehicle") vehicle;
			string_id_legacy nicename("Vehicle Variant") vehicle_variant;
			string_id_legacy nicename("Command Script Name") command_script_name;
			int16_t nicename("Command Script Index") command_script_index;
			int16_t __unknown5;
			string_id_legacy __unknown6;
			s_undefined32_legacy __unknown7;
			int16_t __unknown8;
			int16_t __unknown9;
			s_undefined32_legacy __unknown10;
			s_undefined32_legacy __unknown11;
			s_undefined32_legacy __unknown12;
		};

		struct nicename("Squad B") s_squad_b_definition
		{
			enum nicename("Difficulty") b_difficulty : uint16_t /* bitfield */
			{
				/*nicename("Easy")*/ _difficulty_easy = 1ui16 << 0ui16,
				/*nicename("Normal")*/ _difficulty_normal = 1ui16 << 1ui16,
				/*nicename("Heroic")*/ _difficulty_heroic = 1ui16 << 2ui16,
				/*nicename("Legendary")*/ _difficulty_legendary = 1ui16 << 3ui16,
				/*nicename("Bit 4")*/ _difficulty_bit_4 = 1ui16 << 4ui16,
				/*nicename("Bit 5")*/ _difficulty_bit_5 = 1ui16 << 5ui16,
				/*nicename("Bit 6")*/ _difficulty_bit_6 = 1ui16 << 6ui16,
				/*nicename("Bit 7")*/ _difficulty_bit_7 = 1ui16 << 7ui16,
				/*nicename("Bit 8")*/ _difficulty_bit_8 = 1ui16 << 8ui16,
				/*nicename("Bit 9")*/ _difficulty_bit_9 = 1ui16 << 9ui16,
				/*nicename("Bit 10")*/ _difficulty_bit_10 = 1ui16 << 10ui16,
				/*nicename("Bit 11")*/ _difficulty_bit_11 = 1ui16 << 11ui16,
				/*nicename("Bit 12")*/ _difficulty_bit_12 = 1ui16 << 12ui16,
				/*nicename("Bit 13")*/ _difficulty_bit_13 = 1ui16 << 13ui16,
				/*nicename("Bit 14")*/ _difficulty_bit_14 = 1ui16 << 14ui16,
				/*nicename("Bit 15")*/ _difficulty_bit_15 = 1ui16 << 15ui16,
			};

			struct nicename("Actors") s_actors1_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t nicename("Minimum Round") minimum_round;
				int16_t nicename("Maximum Round") maximum_round;
				s_undefined32_legacy __unknown2;
				int16_t nicename("Character") character;
				int16_t nicename("Probability") probability;
			};

			struct nicename("Weapons") s_weapons2_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t nicename("Minimum Round") minimum_round;
				int16_t nicename("Maximum Round") maximum_round;
				s_undefined32_legacy __unknown2;
				int16_t nicename("Weapon") weapon;
				int16_t nicename("Probability") probability;
			};

			struct nicename("Secondary Weapons") s_secondary_weapons1_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t nicename("Minimum Round") minimum_round;
				int16_t nicename("Maximum Round") maximum_round;
				s_undefined32_legacy __unknown2;
				int16_t nicename("Weapon") weapon;
				int16_t nicename("Probability") probability;
			};

			struct nicename("Equipment") s_equipment2_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t nicename("Minimum Round") minimum_round;
				int16_t nicename("Maximum Round") maximum_round;
				s_undefined32_legacy __unknown2;
				int16_t nicename("Equipment") equipment;
				int16_t nicename("Probability") probability;
			};

			string_id_legacy nicename("Name") name;
			b_difficulty nicename("Difficulty") difficulty;
			int16_t __unknown0;
			int16_t nicename("Minimum Round") minimum_round;
			int16_t nicename("Maximum Round") maximum_round;
			int16_t __unknown1;
			int16_t __unknown2;
			int16_t nicename("Count") count;
			int16_t __unknown3;
			s_tag_block_legacy<s_actors1_definition> nicename("Actors") actors_block;
			s_tag_block_legacy<s_weapons2_definition> nicename("Weapons") weapons_block;
			s_tag_block_legacy<s_secondary_weapons1_definition> nicename("Secondary Weapons") secondary_weapons_block;
			s_tag_block_legacy<s_equipment2_definition> nicename("Equipment") equipment_block;
			int16_t __unknown4;
			int16_t nicename("Vehicle") vehicle;
			string_id_legacy nicename("Vehicle Variant") vehicle_variant;
			string_id_legacy nicename("Command Script Name") command_script_name;
			int16_t nicename("Command Script Index") command_script_index;
			int16_t __unknown5;
			string_id_legacy __unknown6;
			s_undefined32_legacy __unknown7;
			int16_t __unknown8;
			int16_t __unknown9;
			s_undefined32_legacy __unknown10;
			s_undefined32_legacy __unknown11;
			s_undefined32_legacy __unknown12;
		};

		char nicename("Name") name[32];
		b_flags1 nicename("Flags") flags;
		e_team nicename("Team") team;
		int16_t nicename("Parent Squad Group Index") parent_squad_group_index;
		int16_t nicename("Parent Zone") parent_zone;
		int16_t nicename("Objective Index") objective_index;
		int16_t nicename("Objective Role Index") objective_role_index;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		s_tag_block_legacy<s_group_locations_definition> nicename("Group Locations") group_locations_block;
		s_tag_block_legacy<s_single_locations_definition> nicename("Single Locations") single_locations_block;
		s_undefined32_legacy __unknown0;
		string_id_legacy nicename("Squad Template Name") squad_template_name;
		s_tag_reference_legacy nicename("Squad Template") squad_template_reference;
		s_tag_block_legacy<s_squad_a_definition> nicename("Squad A") squad_a_block;
		s_tag_block_legacy<s_squad_b_definition> nicename("Squad B") squad_b_block;
	};

	struct nicename("Zones") s_zones_definition
	{
		struct nicename("Firing Positions") s_firing_positions_definition
		{
			enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
			{
				/*nicename("Open")*/ _flags1_open = 1ui16 << 0ui16,
				/*nicename("Partial")*/ _flags1_partial = 1ui16 << 1ui16,
				/*nicename("Closed")*/ _flags1_closed = 1ui16 << 2ui16,
				/*nicename("Mobile")*/ _flags1_mobile = 1ui16 << 3ui16,
				/*nicename("Wall Lean")*/ _flags1_wall_lean = 1ui16 << 4ui16,
				/*nicename("Perch")*/ _flags1_perch = 1ui16 << 5ui16,
				/*nicename("Ground Point")*/ _flags1_ground_point = 1ui16 << 6ui16,
				/*nicename("Dynamic Cover Point")*/ _flags1_dynamic_cover_point = 1ui16 << 7ui16,
				/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui16 << 8ui16,
				/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui16 << 9ui16,
				/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui16 << 10ui16,
				/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui16 << 11ui16,
				/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui16 << 12ui16,
				/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui16 << 13ui16,
				/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui16 << 14ui16,
				/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui16 << 15ui16,
			};

			float nicename("Position x") position_x;
			float nicename("Position y") position_y;
			float nicename("Position z") position_z;
			int16_t nicename("Reference Frame") reference_frame;
			int16_t __unknown0;
			b_flags1 nicename("Flags") flags;
			int16_t __unknown1;
			int16_t nicename("Area Index") area_index;
			int16_t nicename("Cluster Index") cluster_index;
			int32_t __unknown2;
			float nicename("Normal y") normal_y;
			float nicename("Normal p") normal_p;
			s_undefined32_legacy __unknown3;
		};

		struct nicename("Areas") s_areas_definition
		{
			enum nicename("Area Flags") b_area_flags : uint32_t /* bitfield */
			{
				/*nicename("Vehicle Area")*/ _area_flags_vehicle_area = 1ui32 << 0ui32,
				/*nicename("Perch")*/ _area_flags_perch = 1ui32 << 1ui32,
				/*nicename("Manual Reference Frame")*/ _area_flags_manual_reference_frame = 1ui32 << 2ui32,
				/*nicename("Bit 3")*/ _area_flags_bit_3 = 1ui32 << 3ui32,
				/*nicename("Bit 4")*/ _area_flags_bit_4 = 1ui32 << 4ui32,
				/*nicename("Bit 5")*/ _area_flags_bit_5 = 1ui32 << 5ui32,
				/*nicename("Bit 6")*/ _area_flags_bit_6 = 1ui32 << 6ui32,
				/*nicename("Bit 7")*/ _area_flags_bit_7 = 1ui32 << 7ui32,
				/*nicename("Bit 8")*/ _area_flags_bit_8 = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _area_flags_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _area_flags_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _area_flags_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _area_flags_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _area_flags_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _area_flags_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _area_flags_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _area_flags_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _area_flags_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _area_flags_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _area_flags_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _area_flags_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _area_flags_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _area_flags_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _area_flags_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _area_flags_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _area_flags_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _area_flags_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _area_flags_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _area_flags_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _area_flags_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _area_flags_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _area_flags_bit_31 = 1ui32 << 31ui32,
			};

			struct nicename("Flight Hints") s_flight_hints_definition
			{
				int16_t nicename("Flight Hint Index") flight_hint_index;
				int16_t nicename("Poit Index") poit_index;
				s_undefined32_legacy __unknown0;
			};

			struct nicename("Unknown 50") s_unknown_50_definition
			{
				float nicename("Position x") position_x;
				float nicename("Position y") position_y;
				float nicename("Position z") position_z;
				int16_t __unknown0;
				int16_t __unknown1;
				float nicename("Facing y") facing_y;
				float nicename("Facing p") facing_p;
			};

			char nicename("Name") name[32];
			b_area_flags nicename("Area Flags") area_flags;
			float nicename("Position x") position_x;
			float nicename("Position y") position_y;
			float nicename("Position z") position_z;
			int32_t __unknown0;
			float __unknown1;
			int16_t nicename("Firing Position Start Index") firing_position_start_index;
			int16_t nicename("Firing Position Count") firing_position_count;
			int16_t __unknown2;
			int16_t __unknown3;
			int32_t __unknown4;
			s_undefined32_legacy __unknown5;
			s_undefined32_legacy __unknown6;
			s_undefined32_legacy __unknown7;
			s_undefined32_legacy __unknown8;
			s_undefined32_legacy __unknown9;
			s_undefined32_legacy __unknown10;
			int16_t nicename("Manual Reference Frame") manual_reference_frame;
			int16_t __unknown11;
			s_tag_block_legacy<s_flight_hints_definition> nicename("Flight Hints") flight_hints_block;
			s_tag_block_legacy<s_unknown_50_definition> nicename("Unknown 50") unknown_50_block;
			int16_t __unknown12;
			int16_t __unknown13;
			s_undefined32_legacy __unknown14;
			s_undefined32_legacy __unknown15;
			s_undefined32_legacy __unknown16;
			s_undefined32_legacy __unknown17;
			s_undefined32_legacy __unknown18;
			s_undefined32_legacy __unknown19;
			s_undefined32_legacy __unknown20;
			s_undefined32_legacy __unknown21;
			s_undefined32_legacy __unknown22;
			s_undefined32_legacy __unknown23;
			s_undefined32_legacy __unknown24;
		};

		char nicename("Name") name[32];
		int16_t __unknown0;
		int16_t __unknown1;
		s_tag_block_legacy<s_firing_positions_definition> nicename("Firing Positions") firing_positions_block;
		s_tag_block_legacy<s_areas_definition> nicename("Areas") areas_block;
		int16_t __unknown2;
		int16_t __unknown3;
	};

	struct nicename("Unknown 43") s_unknown_43_definition
	{
		struct nicename("Unknown 44") s_unknown_44_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
		};

		struct nicename("Unknown 45") s_unknown_45_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
			float __unknown2;
			float __unknown3;
			float __unknown4;
			float __unknown5;
		};

		string_id_legacy __unknown0;
		s_tag_block_legacy<s_unknown_44_definition> nicename("Unknown 44") unknown_44_block;
		s_tag_block_legacy<s_unknown_45_definition> nicename("Unknown 45") unknown_45_block;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		int16_t __unknown4;
		int16_t __unknown5;
	};

	struct nicename("AI Cues") s_ai_cues_definition
	{
		struct nicename("Unknown 45") s_unknown_451_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
		};

		struct nicename("Unknown 46") s_unknown_46_definition
		{
			float __unknown0;
			s_undefined32_legacy __unknown1;
		};

		struct nicename("Unknown 47") s_unknown_47_definition
		{
			float __unknown0;
		};

		struct nicename("Unknown 48") s_unknown_48_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
		};

		struct nicename("Unknown 49") s_unknown_49_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
		};

		struct nicename("Unknown 50") s_unknown_501_definition
		{
			float __unknown0;
		};

		struct nicename("Actor Stimuli") s_actor_stimuli_definition
		{
			string_id_legacy nicename("Actor Name") actor_name;
		};

		string_id_legacy __unknown0;
		int16_t __unknown1;
		int16_t __unknown2;
		float nicename("X") x;
		float nicename("Y") y;
		float nicename("Z") z;
		int32_t __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		s_tag_block_legacy<s_unknown_451_definition> nicename("Unknown 45") unknown_45_block;
		s_tag_block_legacy<s_unknown_46_definition> nicename("Unknown 46") unknown_46_block;
		s_tag_block_legacy<s_unknown_47_definition> nicename("Unknown 47") unknown_47_block;
		s_tag_block_legacy<s_unknown_48_definition> nicename("Unknown 48") unknown_48_block;
		s_tag_block_legacy<s_unknown_49_definition> nicename("Unknown 49") unknown_49_block;
		s_tag_block_legacy<s_unknown_501_definition> nicename("Unknown 50") unknown_50_block;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_tag_block_legacy<s_actor_stimuli_definition> nicename("Actor Stimuli") actor_stimuli_block;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
	};

	struct nicename("Character Palette") s_character_palette_definition
	{
		s_tag_reference_legacy nicename("Character") character_reference;
	};

	struct nicename("AI Pathfinding Data") s_ai_pathfinding_data_definition
	{
		struct nicename("Unknown 36") s_unknown_36_definition
		{
			s_undefined32_legacy __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
			int16_t __unknown4;
			int16_t __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			int16_t __unknown9;
			int16_t __unknown10;
		};

		struct nicename("Unknown 37") s_unknown_37_definition
		{
			s_undefined32_legacy __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
			int16_t __unknown4;
			int16_t __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			int16_t __unknown9;
			int16_t __unknown10;
			float __unknown11;
			float __unknown12;
			float __unknown13;
			int16_t __unknown14;
			int16_t __unknown15;
			float __unknown16;
			float __unknown17;
			float __unknown18;
			int16_t __unknown19;
			int16_t __unknown20;
			int16_t __unknown21;
			int16_t __unknown22;
		};

		struct nicename("Unknown 38") s_unknown_38_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
		};

		struct nicename("Unknown 38") s_unknown_381_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
		};

		struct nicename("Unknown 52") s_unknown_52_definition
		{
			struct nicename("Unknown 53") s_unknown_53_definition
			{
				float __unknown0;
				float __unknown1;
				float __unknown2;
			};

			s_tag_block_legacy<s_unknown_53_definition> nicename("Unknown 53") unknown_53_block;
		};

		struct nicename("Unknown 53") s_unknown_531_definition
		{
			int32_t __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
			float __unknown4;
			float __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			int16_t __unknown9;
			int16_t __unknown10;
			int32_t __unknown11;
		};

		struct nicename("Unknown 54") s_unknown_54_definition
		{
			struct nicename("Unknown 55") s_unknown_55_definition
			{
				s_undefined32_legacy __unknown0;
				float __unknown1;
				float __unknown2;
				float __unknown3;
				float __unknown4;
				float __unknown5;
				float __unknown6;
				float __unknown7;
			};

			struct nicename("Unknown 56") s_unknown_56_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				s_undefined32_legacy __unknown2;
				s_undefined32_legacy __unknown3;
				s_undefined32_legacy __unknown4;
				s_undefined32_legacy __unknown5;
				s_undefined32_legacy __unknown6;
				s_undefined32_legacy __unknown7;
			};

			string_id_legacy __unknown0;
			float __unknown1;
			float __unknown2;
			s_tag_block_legacy<s_unknown_55_definition> nicename("Unknown 55") unknown_55_block;
			int16_t __unknown3;
			int16_t __unknown4;
			s_tag_block_legacy<s_unknown_56_definition> nicename("Unknown 56") unknown_56_block;
		};

		struct nicename("Unknown 39") s_unknown_39_definition
		{
			struct nicename("Unknown 40") s_unknown_403_definition
			{
				float __unknown0;
				float __unknown1;
				float __unknown2;
				int16_t __unknown3;
				int16_t __unknown4;
				float __unknown5;
				float __unknown6;
			};

			s_tag_block_legacy<s_unknown_403_definition> nicename("Unknown 40") unknown_40_block;
			float __unknown0;
			float __unknown1;
		};

		struct nicename("Unknown 53") s_unknown_532_definition
		{
			struct nicename("Unknown 54") s_unknown_541_definition
			{
				struct nicename("Unknown 55") s_unknown_551_definition
				{
					s_undefined32_legacy __unknown0;
					s_undefined32_legacy __unknown1;
					s_undefined32_legacy __unknown2;
					s_undefined32_legacy __unknown3;
					s_undefined32_legacy __unknown4;
					s_undefined32_legacy __unknown5;
				};

				s_tag_block_legacy<s_unknown_551_definition> nicename("Unknown 55") unknown_55_block;
			};

			s_tag_block_legacy<s_unknown_541_definition> nicename("Unknown 54") unknown_54_block;
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
		};

		struct nicename("Unknown 41") s_unknown_411_definition
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
		};

		s_tag_block_legacy<s_unknown_36_definition> nicename("Unknown 36") unknown_36_block;
		s_tag_block_legacy<s_unknown_37_definition> nicename("Unknown 37") unknown_37_block;
		s_tag_block_legacy<s_unknown_38_definition> nicename("Unknown 38") unknown_38_block;
		s_tag_block_legacy<s_unknown_381_definition> nicename("Unknown 38") unknown_381_block;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_tag_block_legacy<s_unknown_52_definition> nicename("Unknown 52") unknown_52_block;
		s_tag_block_legacy<s_unknown_531_definition> nicename("Unknown 53") unknown_53_block;
		s_tag_block_legacy<s_unknown_54_definition> nicename("Unknown 54") unknown_54_block;
		s_tag_block_legacy<s_unknown_39_definition> nicename("Unknown 39") unknown_39_block;
		s_tag_block_legacy<s_unknown_532_definition> nicename("Unknown 53") unknown_531_block;
		s_tag_block_legacy<s_unknown_411_definition> nicename("Unknown 41") unknown_41_block;
	};

	struct nicename("Scripts") s_scripts_definition
	{
		enum nicename("Script Type") e_script_type : uint16_t
		{
			/*nicename("Startup")*/ _script_type_startup = 0ui16,
			/*nicename("Dormant")*/ _script_type_dormant = 1ui16,
			/*nicename("Continous")*/ _script_type_continous = 2ui16,
			/*nicename("Static")*/ _script_type_static = 3ui16,
			/*nicename("Command Script")*/ _script_type_command_script = 4ui16,
			/*nicename("Stub")*/ _script_type_stub = 5ui16,
		};

		enum nicename("Return Type") e_return_type : uint16_t
		{
			/*nicename("unparsed")*/ _return_type_unparsed = 0ui16,
			/*nicename("special_form")*/ _return_type_special_form = 1ui16,
			/*nicename("function_name")*/ _return_type_function_name = 2ui16,
			/*nicename("passthrough")*/ _return_type_passthrough = 3ui16,
			/*nicename("void")*/ _return_type_void = 4ui16,
			/*nicename("boolean")*/ _return_type_boolean = 5ui16,
			/*nicename("real")*/ _return_type_real = 6ui16,
			/*nicename("short")*/ _return_type_short = 7ui16,
			/*nicename("long")*/ _return_type_long = 8ui16,
			/*nicename("string")*/ _return_type_string = 9ui16,
			/*nicename("script")*/ _return_type_script = 10ui16,
			/*nicename("string_id")*/ _return_type_string_id = 11ui16,
			/*nicename("unit_seat_mapping")*/ _return_type_unit_seat_mapping = 12ui16,
			/*nicename("trigger_volume")*/ _return_type_trigger_volume = 13ui16,
			/*nicename("cutscene_flag")*/ _return_type_cutscene_flag = 14ui16,
			/*nicename("cutscene_camera_point")*/ _return_type_cutscene_camera_point = 15ui16,
			/*nicename("cutscene_title")*/ _return_type_cutscene_title = 16ui16,
			/*nicename("cutscene_recording")*/ _return_type_cutscene_recording = 17ui16,
			/*nicename("device_group")*/ _return_type_device_group = 18ui16,
			/*nicename("ai")*/ _return_type_ai = 19ui16,
			/*nicename("ai_command_list")*/ _return_type_ai_command_list = 20ui16,
			/*nicename("ai_command_script")*/ _return_type_ai_command_script = 21ui16,
			/*nicename("ai_behavior")*/ _return_type_ai_behavior = 22ui16,
			/*nicename("ai_orders")*/ _return_type_ai_orders = 23ui16,
			/*nicename("ai_line")*/ _return_type_ai_line = 24ui16,
			/*nicename("starting_profile")*/ _return_type_starting_profile = 25ui16,
			/*nicename("conversation")*/ _return_type_conversation = 26ui16,
			/*nicename("player")*/ _return_type_player = 27ui16,
			/*nicename("zone_set")*/ _return_type_zone_set = 28ui16,
			/*nicename("designer_zone")*/ _return_type_designer_zone = 29ui16,
			/*nicename("point_reference")*/ _return_type_point_reference = 30ui16,
			/*nicename("style")*/ _return_type_style = 31ui16,
			/*nicename("object_list")*/ _return_type_object_list = 32ui16,
			/*nicename("folder")*/ _return_type_folder = 33ui16,
			/*nicename("sound")*/ _return_type_sound = 34ui16,
			/*nicename("effect")*/ _return_type_effect = 35ui16,
			/*nicename("damage")*/ _return_type_damage = 36ui16,
			/*nicename("looping_sound")*/ _return_type_looping_sound = 37ui16,
			/*nicename("animation_graph")*/ _return_type_animation_graph = 38ui16,
			/*nicename("damage_effect")*/ _return_type_damage_effect = 39ui16,
			/*nicename("object_definition")*/ _return_type_object_definition = 40ui16,
			/*nicename("bitmap")*/ _return_type_bitmap = 41ui16,
			/*nicename("shader")*/ _return_type_shader = 42ui16,
			/*nicename("render_model")*/ _return_type_render_model = 43ui16,
			/*nicename("structure_definition")*/ _return_type_structure_definition = 44ui16,
			/*nicename("lightmap_definition")*/ _return_type_lightmap_definition = 45ui16,
			/*nicename("cinematic_definition")*/ _return_type_cinematic_definition = 46ui16,
			/*nicename("cinematic_scene_definition")*/ _return_type_cinematic_scene_definition = 47ui16,
			/*nicename("cinematic_transition_definition")*/ _return_type_cinematic_transition_definition = 48ui16,
			/*nicename("bink_definition")*/ _return_type_bink_definition = 49ui16,
			/*nicename("cui_screen_definition")*/ _return_type_cui_screen_definition = 50ui16,
			/*nicename("any_tag")*/ _return_type_any_tag = 51ui16,
			/*nicename("any_tag_not_resolving")*/ _return_type_any_tag_not_resolving = 52ui16,
			/*nicename("game_difficulty")*/ _return_type_game_difficulty = 53ui16,
			/*nicename("team")*/ _return_type_team = 54ui16,
			/*nicename("mp_team")*/ _return_type_mp_team = 55ui16,
			/*nicename("controller")*/ _return_type_controller = 56ui16,
			/*nicename("button_preset")*/ _return_type_button_preset = 57ui16,
			/*nicename("joystick_preset")*/ _return_type_joystick_preset = 58ui16,
			/*nicename("player_color")*/ _return_type_player_color = 59ui16,
			/*nicename("player_model_choice")*/ _return_type_player_model_choice = 60ui16,
			/*nicename("voice_output_setting")*/ _return_type_voice_output_setting = 61ui16,
			/*nicename("voice_mask")*/ _return_type_voice_mask = 62ui16,
			/*nicename("subtitle_setting")*/ _return_type_subtitle_setting = 63ui16,
			/*nicename("actor_type")*/ _return_type_actor_type = 64ui16,
			/*nicename("model_state")*/ _return_type_model_state = 65ui16,
			/*nicename("event")*/ _return_type_event = 66ui16,
			/*nicename("character_physics")*/ _return_type_character_physics = 67ui16,
			/*nicename("skull")*/ _return_type_skull = 68ui16,
			/*nicename("firing_point_evaluator")*/ _return_type_firing_point_evaluator = 69ui16,
			/*nicename("damage_region")*/ _return_type_damage_region = 70ui16,
			/*nicename("object")*/ _return_type_object = 71ui16,
			/*nicename("unit")*/ _return_type_unit = 72ui16,
			/*nicename("vehicle")*/ _return_type_vehicle = 73ui16,
			/*nicename("weapon")*/ _return_type_weapon = 74ui16,
			/*nicename("device")*/ _return_type_device = 75ui16,
			/*nicename("scenery")*/ _return_type_scenery = 76ui16,
			/*nicename("effect_scenery")*/ _return_type_effect_scenery = 77ui16,
			/*nicename("object_name")*/ _return_type_object_name = 78ui16,
			/*nicename("unit_name")*/ _return_type_unit_name = 79ui16,
			/*nicename("vehicle_name")*/ _return_type_vehicle_name = 80ui16,
			/*nicename("weapon_name")*/ _return_type_weapon_name = 81ui16,
			/*nicename("device_name")*/ _return_type_device_name = 82ui16,
			/*nicename("scenery_name")*/ _return_type_scenery_name = 83ui16,
			/*nicename("effect_scenery_name")*/ _return_type_effect_scenery_name = 84ui16,
			/*nicename("cinematic_lightprobe")*/ _return_type_cinematic_lightprobe = 85ui16,
			/*nicename("animation_budget_reference")*/ _return_type_animation_budget_reference = 86ui16,
			/*nicename("looping_sound_budget_reference")*/ _return_type_looping_sound_budget_reference = 87ui16,
			/*nicename("sound_budget_reference")*/ _return_type_sound_budget_reference = 88ui16,
		};

		struct nicename("Parameters") s_parameters_definition
		{
			enum nicename("Type") e_type : uint16_t
			{
				/*nicename("unparsed")*/ _type_unparsed = 0ui16,
				/*nicename("special_form")*/ _type_special_form = 1ui16,
				/*nicename("function_name")*/ _type_function_name = 2ui16,
				/*nicename("passthrough")*/ _type_passthrough = 3ui16,
				/*nicename("void")*/ _type_void = 4ui16,
				/*nicename("boolean")*/ _type_boolean = 5ui16,
				/*nicename("real")*/ _type_real = 6ui16,
				/*nicename("short")*/ _type_short = 7ui16,
				/*nicename("long")*/ _type_long = 8ui16,
				/*nicename("string")*/ _type_string = 9ui16,
				/*nicename("script")*/ _type_script = 10ui16,
				/*nicename("string_id")*/ _type_string_id = 11ui16,
				/*nicename("unit_seat_mapping")*/ _type_unit_seat_mapping = 12ui16,
				/*nicename("trigger_volume")*/ _type_trigger_volume = 13ui16,
				/*nicename("cutscene_flag")*/ _type_cutscene_flag = 14ui16,
				/*nicename("cutscene_camera_point")*/ _type_cutscene_camera_point = 15ui16,
				/*nicename("cutscene_title")*/ _type_cutscene_title = 16ui16,
				/*nicename("cutscene_recording")*/ _type_cutscene_recording = 17ui16,
				/*nicename("device_group")*/ _type_device_group = 18ui16,
				/*nicename("ai")*/ _type_ai = 19ui16,
				/*nicename("ai_command_list")*/ _type_ai_command_list = 20ui16,
				/*nicename("ai_command_script")*/ _type_ai_command_script = 21ui16,
				/*nicename("ai_behavior")*/ _type_ai_behavior = 22ui16,
				/*nicename("ai_orders")*/ _type_ai_orders = 23ui16,
				/*nicename("ai_line")*/ _type_ai_line = 24ui16,
				/*nicename("starting_profile")*/ _type_starting_profile = 25ui16,
				/*nicename("conversation")*/ _type_conversation = 26ui16,
				/*nicename("player")*/ _type_player = 27ui16,
				/*nicename("zone_set")*/ _type_zone_set = 28ui16,
				/*nicename("designer_zone")*/ _type_designer_zone = 29ui16,
				/*nicename("point_reference")*/ _type_point_reference = 30ui16,
				/*nicename("style")*/ _type_style = 31ui16,
				/*nicename("object_list")*/ _type_object_list = 32ui16,
				/*nicename("folder")*/ _type_folder = 33ui16,
				/*nicename("sound")*/ _type_sound = 34ui16,
				/*nicename("effect")*/ _type_effect = 35ui16,
				/*nicename("damage")*/ _type_damage = 36ui16,
				/*nicename("looping_sound")*/ _type_looping_sound = 37ui16,
				/*nicename("animation_graph")*/ _type_animation_graph = 38ui16,
				/*nicename("damage_effect")*/ _type_damage_effect = 39ui16,
				/*nicename("object_definition")*/ _type_object_definition = 40ui16,
				/*nicename("bitmap")*/ _type_bitmap = 41ui16,
				/*nicename("shader")*/ _type_shader = 42ui16,
				/*nicename("render_model")*/ _type_render_model = 43ui16,
				/*nicename("structure_definition")*/ _type_structure_definition = 44ui16,
				/*nicename("lightmap_definition")*/ _type_lightmap_definition = 45ui16,
				/*nicename("cinematic_definition")*/ _type_cinematic_definition = 46ui16,
				/*nicename("cinematic_scene_definition")*/ _type_cinematic_scene_definition = 47ui16,
				/*nicename("cinematic_transition_definition")*/ _type_cinematic_transition_definition = 48ui16,
				/*nicename("bink_definition")*/ _type_bink_definition = 49ui16,
				/*nicename("cui_screen_definition")*/ _type_cui_screen_definition = 50ui16,
				/*nicename("any_tag")*/ _type_any_tag = 51ui16,
				/*nicename("any_tag_not_resolving")*/ _type_any_tag_not_resolving = 52ui16,
				/*nicename("game_difficulty")*/ _type_game_difficulty = 53ui16,
				/*nicename("team")*/ _type_team = 54ui16,
				/*nicename("mp_team")*/ _type_mp_team = 55ui16,
				/*nicename("controller")*/ _type_controller = 56ui16,
				/*nicename("button_preset")*/ _type_button_preset = 57ui16,
				/*nicename("joystick_preset")*/ _type_joystick_preset = 58ui16,
				/*nicename("player_color")*/ _type_player_color = 59ui16,
				/*nicename("player_model_choice")*/ _type_player_model_choice = 60ui16,
				/*nicename("voice_output_setting")*/ _type_voice_output_setting = 61ui16,
				/*nicename("voice_mask")*/ _type_voice_mask = 62ui16,
				/*nicename("subtitle_setting")*/ _type_subtitle_setting = 63ui16,
				/*nicename("actor_type")*/ _type_actor_type = 64ui16,
				/*nicename("model_state")*/ _type_model_state = 65ui16,
				/*nicename("event")*/ _type_event = 66ui16,
				/*nicename("character_physics")*/ _type_character_physics = 67ui16,
				/*nicename("skull")*/ _type_skull = 68ui16,
				/*nicename("firing_point_evaluator")*/ _type_firing_point_evaluator = 69ui16,
				/*nicename("damage_region")*/ _type_damage_region = 70ui16,
				/*nicename("object")*/ _type_object = 71ui16,
				/*nicename("unit")*/ _type_unit = 72ui16,
				/*nicename("vehicle")*/ _type_vehicle = 73ui16,
				/*nicename("weapon")*/ _type_weapon = 74ui16,
				/*nicename("device")*/ _type_device = 75ui16,
				/*nicename("scenery")*/ _type_scenery = 76ui16,
				/*nicename("effect_scenery")*/ _type_effect_scenery = 77ui16,
				/*nicename("object_name")*/ _type_object_name = 78ui16,
				/*nicename("unit_name")*/ _type_unit_name = 79ui16,
				/*nicename("vehicle_name")*/ _type_vehicle_name = 80ui16,
				/*nicename("weapon_name")*/ _type_weapon_name = 81ui16,
				/*nicename("device_name")*/ _type_device_name = 82ui16,
				/*nicename("scenery_name")*/ _type_scenery_name = 83ui16,
				/*nicename("effect_scenery_name")*/ _type_effect_scenery_name = 84ui16,
				/*nicename("cinematic_lightprobe")*/ _type_cinematic_lightprobe = 85ui16,
				/*nicename("animation_budget_reference")*/ _type_animation_budget_reference = 86ui16,
				/*nicename("looping_sound_budget_reference")*/ _type_looping_sound_budget_reference = 87ui16,
				/*nicename("sound_budget_reference")*/ _type_sound_budget_reference = 88ui16,
			};

			char nicename("Name") name[32];
			e_type nicename("Type") type;
			int16_t __unknown0;
		};

		string_id_legacy nicename("Name") name;
		e_script_type nicename("Script Type") script_type;
		e_return_type nicename("Return Type") return_type;
		uint16_t nicename("Root Expression Index") root_expression_index;
		uint16_t nicename("Root Expression Salt") root_expression_salt;
		s_tag_block_legacy<s_parameters_definition> nicename("Parameters") parameters_block;
	};

	struct nicename("Globals") s_globals_definition
	{
		enum nicename("Type") e_type : uint16_t
		{
			/*nicename("unparsed")*/ _type_unparsed = 0ui16,
			/*nicename("special_form")*/ _type_special_form = 1ui16,
			/*nicename("function_name")*/ _type_function_name = 2ui16,
			/*nicename("passthrough")*/ _type_passthrough = 3ui16,
			/*nicename("void")*/ _type_void = 4ui16,
			/*nicename("boolean")*/ _type_boolean = 5ui16,
			/*nicename("real")*/ _type_real = 6ui16,
			/*nicename("short")*/ _type_short = 7ui16,
			/*nicename("long")*/ _type_long = 8ui16,
			/*nicename("string")*/ _type_string = 9ui16,
			/*nicename("script")*/ _type_script = 10ui16,
			/*nicename("string_id")*/ _type_string_id = 11ui16,
			/*nicename("unit_seat_mapping")*/ _type_unit_seat_mapping = 12ui16,
			/*nicename("trigger_volume")*/ _type_trigger_volume = 13ui16,
			/*nicename("cutscene_flag")*/ _type_cutscene_flag = 14ui16,
			/*nicename("cutscene_camera_point")*/ _type_cutscene_camera_point = 15ui16,
			/*nicename("cutscene_title")*/ _type_cutscene_title = 16ui16,
			/*nicename("cutscene_recording")*/ _type_cutscene_recording = 17ui16,
			/*nicename("device_group")*/ _type_device_group = 18ui16,
			/*nicename("ai")*/ _type_ai = 19ui16,
			/*nicename("ai_command_list")*/ _type_ai_command_list = 20ui16,
			/*nicename("ai_command_script")*/ _type_ai_command_script = 21ui16,
			/*nicename("ai_behavior")*/ _type_ai_behavior = 22ui16,
			/*nicename("ai_orders")*/ _type_ai_orders = 23ui16,
			/*nicename("ai_line")*/ _type_ai_line = 24ui16,
			/*nicename("starting_profile")*/ _type_starting_profile = 25ui16,
			/*nicename("conversation")*/ _type_conversation = 26ui16,
			/*nicename("player")*/ _type_player = 27ui16,
			/*nicename("zone_set")*/ _type_zone_set = 28ui16,
			/*nicename("designer_zone")*/ _type_designer_zone = 29ui16,
			/*nicename("point_reference")*/ _type_point_reference = 30ui16,
			/*nicename("style")*/ _type_style = 31ui16,
			/*nicename("object_list")*/ _type_object_list = 32ui16,
			/*nicename("folder")*/ _type_folder = 33ui16,
			/*nicename("sound")*/ _type_sound = 34ui16,
			/*nicename("effect")*/ _type_effect = 35ui16,
			/*nicename("damage")*/ _type_damage = 36ui16,
			/*nicename("looping_sound")*/ _type_looping_sound = 37ui16,
			/*nicename("animation_graph")*/ _type_animation_graph = 38ui16,
			/*nicename("damage_effect")*/ _type_damage_effect = 39ui16,
			/*nicename("object_definition")*/ _type_object_definition = 40ui16,
			/*nicename("bitmap")*/ _type_bitmap = 41ui16,
			/*nicename("shader")*/ _type_shader = 42ui16,
			/*nicename("render_model")*/ _type_render_model = 43ui16,
			/*nicename("structure_definition")*/ _type_structure_definition = 44ui16,
			/*nicename("lightmap_definition")*/ _type_lightmap_definition = 45ui16,
			/*nicename("cinematic_definition")*/ _type_cinematic_definition = 46ui16,
			/*nicename("cinematic_scene_definition")*/ _type_cinematic_scene_definition = 47ui16,
			/*nicename("cinematic_transition_definition")*/ _type_cinematic_transition_definition = 48ui16,
			/*nicename("bink_definition")*/ _type_bink_definition = 49ui16,
			/*nicename("cui_screen_definition")*/ _type_cui_screen_definition = 50ui16,
			/*nicename("any_tag")*/ _type_any_tag = 51ui16,
			/*nicename("any_tag_not_resolving")*/ _type_any_tag_not_resolving = 52ui16,
			/*nicename("game_difficulty")*/ _type_game_difficulty = 53ui16,
			/*nicename("team")*/ _type_team = 54ui16,
			/*nicename("mp_team")*/ _type_mp_team = 55ui16,
			/*nicename("controller")*/ _type_controller = 56ui16,
			/*nicename("button_preset")*/ _type_button_preset = 57ui16,
			/*nicename("joystick_preset")*/ _type_joystick_preset = 58ui16,
			/*nicename("player_color")*/ _type_player_color = 59ui16,
			/*nicename("player_model_choice")*/ _type_player_model_choice = 60ui16,
			/*nicename("voice_output_setting")*/ _type_voice_output_setting = 61ui16,
			/*nicename("voice_mask")*/ _type_voice_mask = 62ui16,
			/*nicename("subtitle_setting")*/ _type_subtitle_setting = 63ui16,
			/*nicename("actor_type")*/ _type_actor_type = 64ui16,
			/*nicename("model_state")*/ _type_model_state = 65ui16,
			/*nicename("event")*/ _type_event = 66ui16,
			/*nicename("character_physics")*/ _type_character_physics = 67ui16,
			/*nicename("skull")*/ _type_skull = 68ui16,
			/*nicename("firing_point_evaluator")*/ _type_firing_point_evaluator = 69ui16,
			/*nicename("damage_region")*/ _type_damage_region = 70ui16,
			/*nicename("object")*/ _type_object = 71ui16,
			/*nicename("unit")*/ _type_unit = 72ui16,
			/*nicename("vehicle")*/ _type_vehicle = 73ui16,
			/*nicename("weapon")*/ _type_weapon = 74ui16,
			/*nicename("device")*/ _type_device = 75ui16,
			/*nicename("scenery")*/ _type_scenery = 76ui16,
			/*nicename("effect_scenery")*/ _type_effect_scenery = 77ui16,
			/*nicename("object_name")*/ _type_object_name = 78ui16,
			/*nicename("unit_name")*/ _type_unit_name = 79ui16,
			/*nicename("vehicle_name")*/ _type_vehicle_name = 80ui16,
			/*nicename("weapon_name")*/ _type_weapon_name = 81ui16,
			/*nicename("device_name")*/ _type_device_name = 82ui16,
			/*nicename("scenery_name")*/ _type_scenery_name = 83ui16,
			/*nicename("effect_scenery_name")*/ _type_effect_scenery_name = 84ui16,
			/*nicename("cinematic_lightprobe")*/ _type_cinematic_lightprobe = 85ui16,
			/*nicename("animation_budget_reference")*/ _type_animation_budget_reference = 86ui16,
			/*nicename("looping_sound_budget_reference")*/ _type_looping_sound_budget_reference = 87ui16,
			/*nicename("sound_budget_reference")*/ _type_sound_budget_reference = 88ui16,
		};

		char nicename("Name") name[32];
		e_type nicename("Type") type;
		int16_t __unknown0;
		uint16_t nicename("Initialization Expression Index") initialization_expression_index;
		uint16_t nicename("Initialization Expression Salt") initialization_expression_salt;
	};

	struct nicename("Script References") s_script_references_definition
	{
		s_tag_reference_legacy nicename("References") references_reference;
	};

	struct nicename("Scripting Data") s_scripting_data_definition
	{
		struct nicename("Point Sets") s_point_sets_definition
		{
			enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _flags1_bit_0 = 1ui32 << 0ui32,
				/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui32 << 1ui32,
				/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui32 << 2ui32,
				/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
				/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui32 << 4ui32,
				/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
				/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui32 << 6ui32,
				/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
				/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
			};

			struct nicename("Points") s_points_definition
			{
				char nicename("Name") name[32];
				string_id_legacy nicename("Name") name1;
				float nicename("Position x") position_x;
				float nicename("Position y") position_y;
				float nicename("Position z") position_z;
				int16_t nicename("Reference Frame") reference_frame;
				int16_t __unknown0;
				int32_t nicename("Surface Index") surface_index;
				float nicename("Facing Direction y") facing_direction_y;
				float nicename("Facing Direction p") facing_direction_p;
			};

			char nicename("Name") name[32];
			s_tag_block_legacy<s_points_definition> nicename("Points") points_block;
			int16_t nicename("BSP Index") bsp_index;
			int16_t nicename("Manual Reference Frame") manual_reference_frame;
			b_flags1 nicename("Flags") flags;
			int16_t nicename("Editor Folder Index") editor_folder_index;
			int16_t __unknown0;
		};

		s_tag_block_legacy<s_point_sets_definition> nicename("Point Sets") point_sets_block;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
		s_undefined32_legacy __unknown23;
		s_undefined32_legacy __unknown24;
		s_undefined32_legacy __unknown25;
		s_undefined32_legacy __unknown26;
		s_undefined32_legacy __unknown27;
		s_undefined32_legacy __unknown28;
		s_undefined32_legacy __unknown29;
	};

	struct nicename("Cutscene Flags") s_cutscene_flags_definition
	{
		s_undefined32_legacy __unknown0;
		string_id_legacy nicename("Name") name;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Facing y") facing_y;
		float nicename("Facing p") facing_p;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown1;
	};

	struct nicename("Cutscene Camera Points") s_cutscene_camera_points_definition
	{
		enum nicename("Type") e_type : uint16_t
		{
			/*nicename("Normal")*/ _type_normal = 0ui16,
			/*nicename("Ignore Target Orientation")*/ _type_ignore_target_orientation = 1ui16,
			/*nicename("Dolly")*/ _type_dolly = 2ui16,
			/*nicename("Ignore Target Updates")*/ _type_ignore_target_updates = 3ui16,
		};

		enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags1_bit_0 = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui16 << 15ui16,
		};

		b_flags1 nicename("Flags") flags;
		e_type nicename("Type") type;
		char __unknown0[32];
		s_undefined32_legacy __unknown1;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Orientation y") orientation_y;
		float nicename("Orientation p") orientation_p;
		float nicename("Orientation r") orientation_r;
	};

	struct nicename("Cutscene Titles") s_cutscene_titles_definition
	{
		enum nicename("Justification") e_justification : uint16_t
		{
			/*nicename("Left")*/ _justification_left = 0ui16,
			/*nicename("Right")*/ _justification_right = 1ui16,
			/*nicename("Center")*/ _justification_center = 2ui16,
		};

		enum nicename("Vertical Justification") e_vertical_justification : uint16_t
		{
			/*nicename("Bottom")*/ _vertical_justification_bottom = 0ui16,
			/*nicename("Top")*/ _vertical_justification_top = 1ui16,
			/*nicename("Middle")*/ _vertical_justification_middle = 2ui16,
			/*nicename("Bottom 2")*/ _vertical_justification_bottom_2 = 3ui16,
			/*nicename("Top 2")*/ _vertical_justification_top_2 = 4ui16,
		};

		string_id_legacy nicename("Name") name;
		s_undefined32_legacy __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		e_justification nicename("Justification") justification;
		e_vertical_justification nicename("Vertical Justification") vertical_justification;
		int16_t nicename("Font") font;
		int16_t __unknown4;
		s_color32_legacy nicename("Text Color") text_color;
		s_color32_legacy nicename("Shadow Color") shadow_color;
		float nicename("Fade In Time") fade_in_time;
		float nicename("Uptime") uptime;
		float nicename("Fade Out Time") fade_out_time;
	};

	struct nicename("Scenario Resources") s_scenario_resources_definition
	{
		struct nicename("Script Source") s_script_source_definition
		{
			s_tag_reference_legacy nicename("HS Source File") hs_source_file_reference;
		};

		struct nicename("AI Resources") s_ai_resources_definition
		{
			s_tag_reference_legacy nicename("AI Resource") ai_resource_reference;
		};

		struct nicename("References") s_references_definition
		{
			s_tag_reference_legacy nicename("Scenery Resource") scenery_resource_reference;
			s_tag_reference_legacy nicename("Bipeds Resource") bipeds_resource_reference;
			s_tag_reference_legacy nicename("Vehicles Resource") vehicles_resource_reference;
			s_tag_reference_legacy nicename("Equipment Resource") equipment_resource_reference;
			s_tag_reference_legacy nicename("Weapons Resource") weapons_resource_reference;
			s_tag_reference_legacy nicename("Sound Scenery Resource") sound_scenery_resource_reference;
			s_tag_reference_legacy nicename("Lights Resource") lights_resource_reference;
			s_tag_reference_legacy nicename("Devices Resource") devices_resource_reference;
			s_tag_reference_legacy nicename("Effect Scenery Resource") effect_scenery_resource_reference;
			s_tag_reference_legacy nicename("Decals Resource") decals_resource_reference;
			s_tag_reference_legacy nicename("Cinematics Resource") cinematics_resource_reference;
			s_tag_reference_legacy nicename("Trigger Volumes Resource") trigger_volumes_resource_reference;
			s_tag_reference_legacy nicename("Cluster Data Resource") cluster_data_resource_reference;
			s_tag_reference_legacy nicename("Comments Resource") comments_resource_reference;
			s_tag_reference_legacy nicename("Creature Resource") creature_resource_reference;
			s_tag_reference_legacy nicename("Structure Lighing Resource") structure_lighing_resource_reference;
			s_tag_reference_legacy nicename("Decorators Resource") decorators_resource_reference;
			s_tag_reference_legacy nicename("Sky References Resource") sky_references_resource_reference;
			s_tag_reference_legacy nicename("Cubemap Resource") cubemap_resource_reference;
			s_tag_reference_legacy nicename("Performances Resource") performances_resource_reference;
			s_tag_reference_legacy nicename("Dumplings Resource") dumplings_resource_reference;
		};

		int32_t __unknown0;
		s_tag_block_legacy<s_script_source_definition> nicename("Script Source") script_source_block;
		s_tag_block_legacy<s_ai_resources_definition> nicename("AI Resources") ai_resources_block;
		s_tag_block_legacy<s_references_definition> nicename("References") references_block;
	};

	struct nicename("Unit Seats Mapping") s_unit_seats_mapping_definition
	{
		enum nicename("Seats") b_seats : uint32_t /* bitfield */
		{
			/*nicename("Seat 0")*/ _seats_seat_0 = 1ui32 << 0ui32,
			/*nicename("Seat 1")*/ _seats_seat_1 = 1ui32 << 1ui32,
			/*nicename("Seat 2")*/ _seats_seat_2 = 1ui32 << 2ui32,
			/*nicename("Seat 3")*/ _seats_seat_3 = 1ui32 << 3ui32,
			/*nicename("Seat 4")*/ _seats_seat_4 = 1ui32 << 4ui32,
			/*nicename("Seat 5")*/ _seats_seat_5 = 1ui32 << 5ui32,
			/*nicename("Seat 6")*/ _seats_seat_6 = 1ui32 << 6ui32,
			/*nicename("Seat 7")*/ _seats_seat_7 = 1ui32 << 7ui32,
			/*nicename("Seat 8")*/ _seats_seat_8 = 1ui32 << 8ui32,
			/*nicename("Seat 9")*/ _seats_seat_9 = 1ui32 << 9ui32,
			/*nicename("Seat 10")*/ _seats_seat_10 = 1ui32 << 10ui32,
			/*nicename("Seat 11")*/ _seats_seat_11 = 1ui32 << 11ui32,
			/*nicename("Seat 12")*/ _seats_seat_12 = 1ui32 << 12ui32,
			/*nicename("Seat 13")*/ _seats_seat_13 = 1ui32 << 13ui32,
			/*nicename("Seat 14")*/ _seats_seat_14 = 1ui32 << 14ui32,
			/*nicename("Seat 15")*/ _seats_seat_15 = 1ui32 << 15ui32,
			/*nicename("Seat 16")*/ _seats_seat_16 = 1ui32 << 16ui32,
			/*nicename("Seat 17")*/ _seats_seat_17 = 1ui32 << 17ui32,
			/*nicename("Seat 18")*/ _seats_seat_18 = 1ui32 << 18ui32,
			/*nicename("Seat 19")*/ _seats_seat_19 = 1ui32 << 19ui32,
			/*nicename("Seat 20")*/ _seats_seat_20 = 1ui32 << 20ui32,
			/*nicename("Seat 21")*/ _seats_seat_21 = 1ui32 << 21ui32,
			/*nicename("Seat 22")*/ _seats_seat_22 = 1ui32 << 22ui32,
			/*nicename("Seat 23")*/ _seats_seat_23 = 1ui32 << 23ui32,
			/*nicename("Seat 24")*/ _seats_seat_24 = 1ui32 << 24ui32,
			/*nicename("Seat 25")*/ _seats_seat_25 = 1ui32 << 25ui32,
			/*nicename("Seat 26")*/ _seats_seat_26 = 1ui32 << 26ui32,
			/*nicename("Seat 27")*/ _seats_seat_27 = 1ui32 << 27ui32,
			/*nicename("Seat 28")*/ _seats_seat_28 = 1ui32 << 28ui32,
			/*nicename("Seat 29")*/ _seats_seat_29 = 1ui32 << 29ui32,
			/*nicename("Seat 30")*/ _seats_seat_30 = 1ui32 << 30ui32,
			/*nicename("Seat 31")*/ _seats_seat_31 = 1ui32 << 31ui32,
		};

		enum nicename("Seats 2") b_seats_2 : uint32_t /* bitfield */
		{
			/*nicename("Seat 32")*/ _seats_2_seat_32 = 1ui32 << 0ui32,
			/*nicename("Seat 33")*/ _seats_2_seat_33 = 1ui32 << 1ui32,
			/*nicename("Seat 34")*/ _seats_2_seat_34 = 1ui32 << 2ui32,
			/*nicename("Seat 35")*/ _seats_2_seat_35 = 1ui32 << 3ui32,
			/*nicename("Seat 36")*/ _seats_2_seat_36 = 1ui32 << 4ui32,
			/*nicename("Seat 37")*/ _seats_2_seat_37 = 1ui32 << 5ui32,
			/*nicename("Seat 38")*/ _seats_2_seat_38 = 1ui32 << 6ui32,
			/*nicename("Seat 39")*/ _seats_2_seat_39 = 1ui32 << 7ui32,
			/*nicename("Seat 40")*/ _seats_2_seat_40 = 1ui32 << 8ui32,
			/*nicename("Seat 41")*/ _seats_2_seat_41 = 1ui32 << 9ui32,
			/*nicename("Seat 42")*/ _seats_2_seat_42 = 1ui32 << 10ui32,
			/*nicename("Seat 43")*/ _seats_2_seat_43 = 1ui32 << 11ui32,
			/*nicename("Seat 44")*/ _seats_2_seat_44 = 1ui32 << 12ui32,
			/*nicename("Seat 45")*/ _seats_2_seat_45 = 1ui32 << 13ui32,
			/*nicename("Seat 46")*/ _seats_2_seat_46 = 1ui32 << 14ui32,
			/*nicename("Seat 47")*/ _seats_2_seat_47 = 1ui32 << 15ui32,
			/*nicename("Seat 48")*/ _seats_2_seat_48 = 1ui32 << 16ui32,
			/*nicename("Seat 49")*/ _seats_2_seat_49 = 1ui32 << 17ui32,
			/*nicename("Seat 50")*/ _seats_2_seat_50 = 1ui32 << 18ui32,
			/*nicename("Seat 51")*/ _seats_2_seat_51 = 1ui32 << 19ui32,
			/*nicename("Seat 52")*/ _seats_2_seat_52 = 1ui32 << 20ui32,
			/*nicename("Seat 53")*/ _seats_2_seat_53 = 1ui32 << 21ui32,
			/*nicename("Seat 54")*/ _seats_2_seat_54 = 1ui32 << 22ui32,
			/*nicename("Seat 55")*/ _seats_2_seat_55 = 1ui32 << 23ui32,
			/*nicename("Seat 56")*/ _seats_2_seat_56 = 1ui32 << 24ui32,
			/*nicename("Seat 57")*/ _seats_2_seat_57 = 1ui32 << 25ui32,
			/*nicename("Seat 58")*/ _seats_2_seat_58 = 1ui32 << 26ui32,
			/*nicename("Seat 59")*/ _seats_2_seat_59 = 1ui32 << 27ui32,
			/*nicename("Seat 60")*/ _seats_2_seat_60 = 1ui32 << 28ui32,
			/*nicename("Seat 61")*/ _seats_2_seat_61 = 1ui32 << 29ui32,
			/*nicename("Seat 62")*/ _seats_2_seat_62 = 1ui32 << 30ui32,
			/*nicename("Seat 63")*/ _seats_2_seat_63 = 1ui32 << 31ui32,
		};

		s_tag_reference_legacy nicename("Unit") unit_reference;
		b_seats nicename("Seats") seats;
		b_seats_2 nicename("Seats 2") seats_2;
	};

	struct nicename("Scenario Kill Triggers") s_scenario_kill_triggers_definition
	{
		enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
		{
			/*nicename("Soft Volume")*/ _flags1_soft_volume = 1ui8 << 0ui8,
			/*nicename("Player Only")*/ _flags1_player_only = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui8 << 7ui8,
		};

		int16_t nicename("Trigger Volume") trigger_volume;
		b_flags1 nicename("Flags") flags;
		int8_t __unknown0;
	};

	struct nicename("Scenario Safe Triggers") s_scenario_safe_triggers_definition
	{
		enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
		{
			/*nicename("Soft Volume")*/ _flags1_soft_volume = 1ui8 << 0ui8,
			/*nicename("Player Only")*/ _flags1_player_only = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui8 << 7ui8,
		};

		int16_t nicename("Trigger Volume") trigger_volume;
		b_flags1 nicename("Flags") flags;
		int8_t __unknown0;
	};

	struct nicename("Scenario MOPP Triggers") s_scenario_mopp_triggers_definition
	{
		struct nicename("MOPP Codes") s_mopp_codes_definition
		{
			struct nicename("Data") s_data_definition
			{
				uint8_t nicename("Data Byte") data_byte;
			};

			int32_t __unknown0;
			s_undefined32_legacy __unknown1;
			int16_t nicename("Size") size;
			int16_t nicename("Count") count;
			int32_t nicename("Offset") offset;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
			s_undefined32_legacy __unknown4;
			s_undefined32_legacy __unknown5;
			float nicename("Offset x") offset_x;
			float nicename("Offset y") offset_y;
			float nicename("Offset z") offset_z;
			float nicename("Offset Scale") offset_scale;
			s_undefined32_legacy __unknown6;
			s_undefined32_legacy __unknown7;
			int32_t nicename("Data Size") data_size;
			uint32_t nicename("Data Capacity") data_capacity;
			s_undefined32_legacy __unknown8;
			s_undefined32_legacy __unknown9;
			s_undefined32_legacy __unknown10;
			s_undefined32_legacy __unknown11;
			s_tag_block_legacy<s_data_definition> nicename("Data") data_block;
			s_undefined32_legacy __unknown12;
		};

		int32_t __unknown0;
		s_tag_block_legacy<s_mopp_codes_definition> nicename("MOPP Codes") mopp_codes_block;
	};

	struct nicename("Script Expressions") s_script_expressions_definition
	{
		enum nicename("Value Type") e_value_type : uint16_t
		{
			/*nicename("INVALID")*/ _value_type_invalid = 0ui16,
			/*nicename("unparsed")*/ _value_type_unparsed = 1ui16,
			/*nicename("special_form")*/ _value_type_special_form = 2ui16,
			/*nicename("function_name")*/ _value_type_function_name = 3ui16,
			/*nicename("passthrough")*/ _value_type_passthrough = 4ui16,
			/*nicename("void")*/ _value_type_void = 5ui16,
			/*nicename("boolean")*/ _value_type_boolean = 6ui16,
			/*nicename("real")*/ _value_type_real = 7ui16,
			/*nicename("short")*/ _value_type_short = 8ui16,
			/*nicename("long")*/ _value_type_long = 9ui16,
			/*nicename("string")*/ _value_type_string = 10ui16,
			/*nicename("script")*/ _value_type_script = 11ui16,
			/*nicename("string_id")*/ _value_type_string_id = 12ui16,
			/*nicename("unit_seat_mapping")*/ _value_type_unit_seat_mapping = 13ui16,
			/*nicename("trigger_volume")*/ _value_type_trigger_volume = 14ui16,
			/*nicename("cutscene_flag")*/ _value_type_cutscene_flag = 15ui16,
			/*nicename("cutscene_camera_point")*/ _value_type_cutscene_camera_point = 16ui16,
			/*nicename("cutscene_title")*/ _value_type_cutscene_title = 17ui16,
			/*nicename("cutscene_recording")*/ _value_type_cutscene_recording = 18ui16,
			/*nicename("device_group")*/ _value_type_device_group = 19ui16,
			/*nicename("ai")*/ _value_type_ai = 20ui16,
			/*nicename("ai_command_list")*/ _value_type_ai_command_list = 21ui16,
			/*nicename("ai_command_script")*/ _value_type_ai_command_script = 22ui16,
			/*nicename("ai_behavior")*/ _value_type_ai_behavior = 23ui16,
			/*nicename("ai_orders")*/ _value_type_ai_orders = 24ui16,
			/*nicename("ai_line")*/ _value_type_ai_line = 25ui16,
			/*nicename("starting_profile")*/ _value_type_starting_profile = 26ui16,
			/*nicename("conversation")*/ _value_type_conversation = 27ui16,
			/*nicename("player")*/ _value_type_player = 28ui16,
			/*nicename("zone_set")*/ _value_type_zone_set = 29ui16,
			/*nicename("designer_zone")*/ _value_type_designer_zone = 30ui16,
			/*nicename("point_reference")*/ _value_type_point_reference = 31ui16,
			/*nicename("style")*/ _value_type_style = 32ui16,
			/*nicename("object_list")*/ _value_type_object_list = 33ui16,
			/*nicename("folder")*/ _value_type_folder = 34ui16,
			/*nicename("sound")*/ _value_type_sound = 35ui16,
			/*nicename("effect")*/ _value_type_effect = 36ui16,
			/*nicename("damage")*/ _value_type_damage = 37ui16,
			/*nicename("looping_sound")*/ _value_type_looping_sound = 38ui16,
			/*nicename("animation_graph")*/ _value_type_animation_graph = 39ui16,
			/*nicename("damage_effect")*/ _value_type_damage_effect = 40ui16,
			/*nicename("object_definition")*/ _value_type_object_definition = 41ui16,
			/*nicename("bitmap")*/ _value_type_bitmap = 42ui16,
			/*nicename("shader")*/ _value_type_shader = 43ui16,
			/*nicename("render_model")*/ _value_type_render_model = 44ui16,
			/*nicename("structure_definition")*/ _value_type_structure_definition = 45ui16,
			/*nicename("lightmap_definition")*/ _value_type_lightmap_definition = 46ui16,
			/*nicename("cinematic_definition")*/ _value_type_cinematic_definition = 47ui16,
			/*nicename("cinematic_scene_definition")*/ _value_type_cinematic_scene_definition = 48ui16,
			/*nicename("cinematic_transition_definition")*/ _value_type_cinematic_transition_definition = 49ui16,
			/*nicename("bink_definition")*/ _value_type_bink_definition = 50ui16,
			/*nicename("cui_screen_definition")*/ _value_type_cui_screen_definition = 51ui16,
			/*nicename("any_tag")*/ _value_type_any_tag = 52ui16,
			/*nicename("any_tag_not_resolving")*/ _value_type_any_tag_not_resolving = 53ui16,
			/*nicename("game_difficulty")*/ _value_type_game_difficulty = 54ui16,
			/*nicename("team")*/ _value_type_team = 55ui16,
			/*nicename("mp_team")*/ _value_type_mp_team = 56ui16,
			/*nicename("controller")*/ _value_type_controller = 57ui16,
			/*nicename("button_preset")*/ _value_type_button_preset = 58ui16,
			/*nicename("joystick_preset")*/ _value_type_joystick_preset = 59ui16,
			/*nicename("player_color")*/ _value_type_player_color = 60ui16,
			/*nicename("player_model_choice")*/ _value_type_player_model_choice = 61ui16,
			/*nicename("voice_output_setting")*/ _value_type_voice_output_setting = 62ui16,
			/*nicename("voice_mask")*/ _value_type_voice_mask = 63ui16,
			/*nicename("subtitle_setting")*/ _value_type_subtitle_setting = 64ui16,
			/*nicename("actor_type")*/ _value_type_actor_type = 65ui16,
			/*nicename("model_state")*/ _value_type_model_state = 66ui16,
			/*nicename("event")*/ _value_type_event = 67ui16,
			/*nicename("character_physics")*/ _value_type_character_physics = 68ui16,
			/*nicename("skull")*/ _value_type_skull = 69ui16,
			/*nicename("firing_point_evaluator")*/ _value_type_firing_point_evaluator = 70ui16,
			/*nicename("damage_region")*/ _value_type_damage_region = 71ui16,
			/*nicename("object")*/ _value_type_object = 72ui16,
			/*nicename("unit")*/ _value_type_unit = 73ui16,
			/*nicename("vehicle")*/ _value_type_vehicle = 74ui16,
			/*nicename("weapon")*/ _value_type_weapon = 75ui16,
			/*nicename("device")*/ _value_type_device = 76ui16,
			/*nicename("scenery")*/ _value_type_scenery = 77ui16,
			/*nicename("effect_scenery")*/ _value_type_effect_scenery = 78ui16,
			/*nicename("object_name")*/ _value_type_object_name = 79ui16,
			/*nicename("unit_name")*/ _value_type_unit_name = 80ui16,
			/*nicename("vehicle_name")*/ _value_type_vehicle_name = 81ui16,
			/*nicename("weapon_name")*/ _value_type_weapon_name = 82ui16,
			/*nicename("device_name")*/ _value_type_device_name = 83ui16,
			/*nicename("scenery_name")*/ _value_type_scenery_name = 84ui16,
			/*nicename("effect_scenery_name")*/ _value_type_effect_scenery_name = 85ui16,
			/*nicename("cinematic_lightprobe")*/ _value_type_cinematic_lightprobe = 86ui16,
			/*nicename("animation_budget_reference")*/ _value_type_animation_budget_reference = 87ui16,
			/*nicename("looping_sound_budget_reference")*/ _value_type_looping_sound_budget_reference = 88ui16,
			/*nicename("sound_budget_reference")*/ _value_type_sound_budget_reference = 89ui16,
		};

		uint16_t nicename("Salt") salt;
		uint16_t nicename("Opcode") opcode;
		e_value_type nicename("Value Type") value_type;
		int16_t nicename("Expression Type") expression_type;
		uint16_t nicename("Next Expression Index") next_expression_index;
		uint16_t nicename("Next Expression Salt") next_expression_salt;
		uint32_t nicename("String Address") string_address;
		int8_t nicename("Value 03 (MSB)") value_03_msb;
		int8_t nicename("Value 02 Byte") value_02_byte;
		int8_t nicename("Value 01 Byte") value_01_byte;
		int8_t nicename("Value 00 (LSB)") value_00_lsb;
		int16_t nicename("Line Number") line_number;
		int16_t __unknown0;
	};

	struct nicename("Background Sound Environment Palette") s_background_sound_environment_palette_definition
	{
		enum nicename("Scale Flags") b_scale_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _scale_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _scale_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _scale_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _scale_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _scale_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _scale_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _scale_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _scale_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _scale_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _scale_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _scale_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _scale_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _scale_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _scale_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _scale_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _scale_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _scale_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _scale_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _scale_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _scale_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _scale_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _scale_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _scale_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _scale_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _scale_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _scale_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _scale_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _scale_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _scale_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _scale_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _scale_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _scale_flags_bit_31 = 1ui32 << 31ui32,
		};

		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Sound Environment") sound_environment_reference;
		int32_t __unknown0;
		float nicename("Cutoff Distance") cutoff_distance;
		float nicename("Interpolation Speed") interpolation_speed;
		s_tag_reference_legacy nicename("Background Sound") background_sound_reference;
		s_tag_reference_legacy nicename("Inside Cluster Sound") inside_cluster_sound_reference;
		s_tag_reference_legacy nicename("Transition In") transition_in_reference;
		s_tag_reference_legacy nicename("Transition Out") transition_out_reference;
		float nicename("Cutoff Distance") cutoff_distance1;
		b_scale_flags nicename("Scale Flags") scale_flags;
		float nicename("Interior Scale") interior_scale;
		float nicename("Portal Scale") portal_scale;
		float nicename("Exterior Scale") exterior_scale;
		float nicename("Interpolation Speed") interpolation_speed1;
	};

	struct nicename("Fog") s_fog_definition
	{
		string_id_legacy nicename("Name") name;
		int16_t __unknown0;
		int16_t __unknown1;
		s_tag_reference_legacy nicename("Fog") fog_reference;
	};

	struct nicename("Camera FX") s_camera_fx_definition
	{
		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Camera FX") camera_fx_reference;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
	};

	struct nicename("Weather") s_weather_definition
	{
		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Weather") weather_reference;
	};

	struct nicename("Scenario Cluster Data") s_scenario_cluster_data_definition
	{
		struct nicename("Cluster Centroids") s_cluster_centroids_definition
		{
			float nicename("Centroid X") centroid_x;
			float nicename("Centroid Y") centroid_y;
			float nicename("Centroid Z") centroid_z;
		};

		struct nicename("Background Sound Environments") s_background_sound_environments_definition
		{
			int16_t nicename("Background Sound Environment Index") background_sound_environment_index;
			int16_t __unknown0;
		};

		struct nicename("Fog") s_fog1_definition
		{
			int16_t nicename("Fog Index") fog_index;
			int16_t __unknown0;
		};

		struct nicename("Camera FX") s_camera_fx1_definition
		{
			int16_t nicename("Camera FX Index") camera_fx_index;
			int16_t __unknown0;
		};

		struct nicename("Weather") s_weather1_definition
		{
			int16_t nicename("Weather Index") weather_index;
			int16_t __unknown0;
		};

		s_tag_reference_legacy nicename("BSP") bsp_reference;
		int32_t nicename("BSP Checksum") bsp_checksum;
		s_tag_block_legacy<s_cluster_centroids_definition> nicename("Cluster Centroids") cluster_centroids_block;
		int32_t __unknown0;
		s_tag_block_legacy<s_background_sound_environments_definition> nicename("Background Sound Environments") background_sound_environments_block;
		s_tag_block_legacy<s_fog1_definition> nicename("Fog") fog_block;
		s_tag_block_legacy<s_camera_fx1_definition> nicename("Camera FX") camera_fx_block;
		s_tag_block_legacy<s_weather1_definition> nicename("Weather") weather_block;
	};

	struct nicename("Spawn Data") s_spawn_data_definition
	{
		float __unknown0;
	};

	struct nicename("Crates") s_crates_definition
	{
		enum nicename("BSP Policy") e_bsp_policy : uint8_t
		{
			/*nicename("Default")*/ _bsp_policy_default = 0ui8,
			/*nicename("Always Placed")*/ _bsp_policy_always_placed = 1ui8,
			/*nicename("Manual BSP Index")*/ _bsp_policy_manual_bsp_index = 2ui8,
		};

		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Biped")*/ _type_biped = 0ui8,
			/*nicename("Vehicle")*/ _type_vehicle = 1ui8,
			/*nicename("Weapon")*/ _type_weapon = 2ui8,
			/*nicename("Equipment")*/ _type_equipment = 3ui8,
			/*nicename("Terminal")*/ _type_terminal = 4ui8,
			/*nicename("Projectile")*/ _type_projectile = 5ui8,
			/*nicename("Scenery")*/ _type_scenery = 6ui8,
			/*nicename("Machine")*/ _type_machine = 7ui8,
			/*nicename("Control")*/ _type_control = 8ui8,
			/*nicename("Sound Scenery")*/ _type_sound_scenery = 9ui8,
			/*nicename("Crate")*/ _type_crate = 10ui8,
			/*nicename("Creature")*/ _type_creature = 11ui8,
			/*nicename("Giant")*/ _type_giant = 12ui8,
			/*nicename("Effect Scenery")*/ _type_effect_scenery = 13ui8,
		};

		enum nicename("Source") e_source : uint8_t
		{
			/*nicename("Structure")*/ _source_structure = 0ui8,
			/*nicename("Editor")*/ _source_editor = 1ui8,
			/*nicename("Dynamic")*/ _source_dynamic = 2ui8,
			/*nicename("Legacy")*/ _source_legacy = 3ui8,
		};

		enum nicename("Symmetry") e_symmetry : uint32_t
		{
			/*nicename("Both")*/ _symmetry_both = 0ui32,
			/*nicename("Symmetric")*/ _symmetry_symmetric = 1ui32,
			/*nicename("Asymmetric")*/ _symmetry_asymmetric = 2ui32,
		};

		enum nicename("Team") e_team : uint8_t
		{
			/*nicename("Red")*/ _team_red = 0ui8,
			/*nicename("Blue")*/ _team_blue = 1ui8,
			/*nicename("Green")*/ _team_green = 2ui8,
			/*nicename("Orange")*/ _team_orange = 3ui8,
			/*nicename("Purple")*/ _team_purple = 4ui8,
			/*nicename("Yellow")*/ _team_yellow = 5ui8,
			/*nicename("Brown")*/ _team_brown = 6ui8,
			/*nicename("Pink")*/ _team_pink = 7ui8,
			/*nicename("Neutral")*/ _team_neutral = 8ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Placement Flags") b_placement_flags : uint32_t /* bitfield */
		{
			/*nicename("Not Automatically")*/ _placement_flags_not_automatically = 1ui32 << 0ui32,
			/*nicename("Not On Easy")*/ _placement_flags_not_on_easy = 1ui32 << 1ui32,
			/*nicename("Not On Normal")*/ _placement_flags_not_on_normal = 1ui32 << 2ui32,
			/*nicename("Not On Hard")*/ _placement_flags_not_on_hard = 1ui32 << 3ui32,
			/*nicename("Lock Type To Env Object")*/ _placement_flags_lock_type_to_env_object = 1ui32 << 4ui32,
			/*nicename("Lock Transform To Env Object")*/ _placement_flags_lock_transform_to_env_object = 1ui32 << 5ui32,
			/*nicename("Never Placed")*/ _placement_flags_never_placed = 1ui32 << 6ui32,
			/*nicename("Lock Name to Env Object")*/ _placement_flags_lock_name_to_env_object = 1ui32 << 7ui32,
			/*nicename("Create At Rest")*/ _placement_flags_create_at_rest = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _placement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _placement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _placement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _placement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _placement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _placement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _placement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _placement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _placement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _placement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _placement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _placement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _placement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _placement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _placement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _placement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _placement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _placement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _placement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _placement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _placement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _placement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _placement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Old Manual BSP Flags (Now Zonesets)") b_old_manual_bsp_flags_now_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _old_manual_bsp_flags_now_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _old_manual_bsp_flags_now_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _old_manual_bsp_flags_now_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _old_manual_bsp_flags_now_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _old_manual_bsp_flags_now_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _old_manual_bsp_flags_now_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _old_manual_bsp_flags_now_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _old_manual_bsp_flags_now_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _old_manual_bsp_flags_now_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _old_manual_bsp_flags_now_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _old_manual_bsp_flags_now_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _old_manual_bsp_flags_now_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _old_manual_bsp_flags_now_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _old_manual_bsp_flags_now_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _old_manual_bsp_flags_now_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _old_manual_bsp_flags_now_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Allowed Zonesets") b_allowed_zonesets : uint16_t /* bitfield */
		{
			/*nicename("Set 0")*/ _allowed_zonesets_set_0 = 1ui16 << 0ui16,
			/*nicename("Set 1")*/ _allowed_zonesets_set_1 = 1ui16 << 1ui16,
			/*nicename("Set 2")*/ _allowed_zonesets_set_2 = 1ui16 << 2ui16,
			/*nicename("Set 3")*/ _allowed_zonesets_set_3 = 1ui16 << 3ui16,
			/*nicename("Set 4")*/ _allowed_zonesets_set_4 = 1ui16 << 4ui16,
			/*nicename("Set 5")*/ _allowed_zonesets_set_5 = 1ui16 << 5ui16,
			/*nicename("Set 6")*/ _allowed_zonesets_set_6 = 1ui16 << 6ui16,
			/*nicename("Set 7")*/ _allowed_zonesets_set_7 = 1ui16 << 7ui16,
			/*nicename("Set 8")*/ _allowed_zonesets_set_8 = 1ui16 << 8ui16,
			/*nicename("Set 9")*/ _allowed_zonesets_set_9 = 1ui16 << 9ui16,
			/*nicename("Set 10")*/ _allowed_zonesets_set_10 = 1ui16 << 10ui16,
			/*nicename("Set 11")*/ _allowed_zonesets_set_11 = 1ui16 << 11ui16,
			/*nicename("Set 12")*/ _allowed_zonesets_set_12 = 1ui16 << 12ui16,
			/*nicename("Set 13")*/ _allowed_zonesets_set_13 = 1ui16 << 13ui16,
			/*nicename("Set 14")*/ _allowed_zonesets_set_14 = 1ui16 << 14ui16,
			/*nicename("Set 15")*/ _allowed_zonesets_set_15 = 1ui16 << 15ui16,
		};

		enum nicename("Active Change Colors") b_active_change_colors : uint8_t /* bitfield */
		{
			/*nicename("Primary")*/ _active_change_colors_primary = 1ui8 << 0ui8,
			/*nicename("Secondary")*/ _active_change_colors_secondary = 1ui8 << 1ui8,
			/*nicename("Tertiary")*/ _active_change_colors_tertiary = 1ui8 << 2ui8,
			/*nicename("Quaternary")*/ _active_change_colors_quaternary = 1ui8 << 3ui8,
		};

		enum nicename("Multiplayer Flags") b_multiplayer_flags : uint8_t /* bitfield */
		{
			/*nicename("Is Unique Object")*/ _multiplayer_flags_is_unique_object = 1ui8 << 0ui8,
			/*nicename("Not Placed At Start")*/ _multiplayer_flags_not_placed_at_start = 1ui8 << 1ui8,
			/*nicename("Is Gametype-Specific")*/ _multiplayer_flags_is_gametype_specific = 1ui8 << 2ui8,
			/*nicename("Is Shortcut")*/ _multiplayer_flags_is_shortcut = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _multiplayer_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _multiplayer_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _multiplayer_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _multiplayer_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		struct nicename("Node Positioning") s_node_positioning12_definition
		{
			struct nicename("Node Flags") s_node_flags12_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96")*/ _flags1_node_0_8_16_24_32_40_48_56_64_72_80_88_96 = 1ui8 << 0ui8,
					/*nicename("Node 1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97")*/ _flags1_node_1_9_17_25_33_41_49_57_65_73_81_89_97 = 1ui8 << 1ui8,
					/*nicename("Node 2, 10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98")*/ _flags1_node_2_10_18_26_34_42_50_58_66_74_82_90_98 = 1ui8 << 2ui8,
					/*nicename("Node 3, 11, 19, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99")*/ _flags1_node_3_11_19_27_35_43_51_59_67_75_83_91_99 = 1ui8 << 3ui8,
					/*nicename("Node 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100")*/ _flags1_node_4_12_20_28_36_44_52_60_68_76_84_92_100 = 1ui8 << 4ui8,
					/*nicename("Node 5, 13, 21, 29, 37, 45, 53, 61, 69, 77, 85, 93, 101")*/ _flags1_node_5_13_21_29_37_45_53_61_69_77_85_93_101 = 1ui8 << 5ui8,
					/*nicename("Node 6, 14, 22, 30, 38, 46, 54, 62, 70, 78, 86, 94, 102")*/ _flags1_node_6_14_22_30_38_46_54_62_70_78_86_94_102 = 1ui8 << 6ui8,
					/*nicename("Node 7, 15, 23, 31, 39, 47, 55, 63, 71, 79, 87, 95, 103")*/ _flags1_node_7_15_23_31_39_47_55_63_71_79_87_95_103 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
			};

			struct nicename("Orientations") s_orientations12_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x_y_z_w;
			};

			struct nicename("Node Flags [Readable]") s_node_flags_readable12_definition
			{
				enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
				{
					/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _flags1_node_0_32_64_96_128_160_192_224 = 1ui8 << 0ui8,
					/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _flags1_node_1_33_65_97_129_161_193_225 = 1ui8 << 1ui8,
					/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _flags1_node_2_34_66_98_130_162_194_226 = 1ui8 << 2ui8,
					/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _flags1_node_3_35_67_99_131_163_195_227 = 1ui8 << 3ui8,
					/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _flags1_node_4_36_68_100_132_164_196_228 = 1ui8 << 4ui8,
					/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _flags1_node_5_37_69_101_133_165_197_229 = 1ui8 << 5ui8,
					/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _flags1_node_6_38_70_102_134_166_198_230 = 1ui8 << 6ui8,
					/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _flags1_node_7_39_71_103_135_167_199_231 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
				{
					/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _flags2_node_8_40_72_104_136_168_200_232 = 1ui8 << 0ui8,
					/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _flags2_node_9_41_73_105_137_169_201_233 = 1ui8 << 1ui8,
					/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _flags2_node_10_42_74_106_138_170_202_234 = 1ui8 << 2ui8,
					/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _flags2_node_11_43_75_107_139_171_203_235 = 1ui8 << 3ui8,
					/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _flags2_node_12_44_76_108_140_172_204_236 = 1ui8 << 4ui8,
					/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _flags2_node_13_45_77_109_141_173_205_237 = 1ui8 << 5ui8,
					/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _flags2_node_14_46_78_110_142_174_206_238 = 1ui8 << 6ui8,
					/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _flags2_node_15_47_79_111_143_175_207_239 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
				{
					/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _flags3_node_16_48_80_112_144_176_208_240 = 1ui8 << 0ui8,
					/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _flags3_node_17_49_81_113_145_177_209_241 = 1ui8 << 1ui8,
					/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _flags3_node_18_50_82_114_146_178_210_242 = 1ui8 << 2ui8,
					/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _flags3_node_19_51_83_115_147_179_211_243 = 1ui8 << 3ui8,
					/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _flags3_node_20_52_84_116_148_180_212_244 = 1ui8 << 4ui8,
					/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _flags3_node_21_53_85_117_149_181_213_245 = 1ui8 << 5ui8,
					/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _flags3_node_22_54_86_118_150_182_214_246 = 1ui8 << 6ui8,
					/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _flags3_node_23_55_87_119_151_183_215_247 = 1ui8 << 7ui8,
				};

				enum nicename("Flags") b_flags4 : uint8_t /* bitfield */
				{
					/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _flags4_node_24_56_88_120_152_184_216_248 = 1ui8 << 0ui8,
					/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _flags4_node_25_57_89_121_153_185_217_249 = 1ui8 << 1ui8,
					/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _flags4_node_26_58_90_122_154_186_218_250 = 1ui8 << 2ui8,
					/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _flags4_node_27_59_91_123_155_187_219_251 = 1ui8 << 3ui8,
					/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _flags4_node_28_60_92_124_156_188_220_252 = 1ui8 << 4ui8,
					/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _flags4_node_29_61_93_125_157_189_221_253 = 1ui8 << 5ui8,
					/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _flags4_node_30_62_94_126_158_190_222_254 = 1ui8 << 6ui8,
					/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _flags4_node_31_63_95_127_159_191_223_255 = 1ui8 << 7ui8,
				};

				b_flags1 nicename("Flags") flags;
				b_flags2 nicename("Flags") flags1;
				b_flags3 nicename("Flags") flags2;
				b_flags4 nicename("Flags") flags3;
			};

			struct nicename("Orientations [Readable]") s_orientations_readable12_definition
			{
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
			};

			int16_t nicename("Node Count") node_count;
			int16_t __unknown0;
			s_tag_block_legacy<s_node_flags12_definition> nicename("Node Flags") node_flags_block;
			s_tag_block_legacy<s_orientations12_definition> nicename("Orientations") orientations_block;
			s_tag_block_legacy<s_node_flags_readable12_definition> nicename("Node Flags [Readable]") node_flags_readable_block;
			s_tag_block_legacy<s_orientations_readable12_definition> nicename("Orientations [Readable]") orientations_readable_block;
		};

		struct nicename("Unknown") s_unknown10_definition
		{
			s_undefined32_legacy __unknown0;
		};

		int16_t nicename("Palette Index") palette_index;
		int16_t nicename("Name Index") name_index;
		b_placement_flags nicename("Placement Flags") placement_flags;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		float nicename("Rotation i") rotation_i;
		float nicename("Rotation j") rotation_j;
		float nicename("Rotation k") rotation_k;
		float nicename("Scale") scale;
		/* Node Positioning : This block allows you to "pose" this objects nodes. Used normally for dead bodies. The orientations block has an entry for each checked node flag, skipping unchecked ones.
		   The blocks labeled [Readable] are modified to make reading/editing the values easier, but as a result the entry counts will be innaccurate, going too far may result in editing the wrong data.
		   DO NOT USE THE BLOCK REALLOCATOR ON THE [READABLE] BLOCKS! */
		s_tag_block_legacy<s_node_positioning12_definition> nicename("Node Positioning") node_positioning1_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		e_bsp_policy nicename("BSP Policy") bsp_policy;
		b_old_manual_bsp_flags_now_zonesets nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets;
		int16_t __unknown3;
		string_id_legacy nicename("Unique Name") unique_name;
		uint16_t nicename("Unique ID Index") unique_id_index;
		uint16_t nicename("Unique ID Salt") unique_id_salt;
		int16_t nicename("Origin BSP Index") origin_bsp_index;
		e_type nicename("Type") type;
		e_source nicename("Source") source;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t nicename("Parent Name Index") parent_name_index;
		string_id_legacy nicename("Child Name") child_name;
		string_id_legacy __unknown6;
		b_allowed_zonesets nicename("Allowed Zonesets") allowed_zonesets;
		int16_t __unknown7;
		// Permutation Data : 
		string_id_legacy nicename("Variant") variant;
		int16_t __unknown8;
		b_active_change_colors nicename("Active Change Colors") active_change_colors;
		int8_t __unknown9;
		int8_t __unknown10;
		int8_t __unknown11;
		s_color32_legacy nicename("Primary Color") primary_color;
		s_color32_legacy nicename("Secondary Color") secondary_color;
		s_color32_legacy nicename("Tertiary Color") tertiary_color;
		s_color32_legacy nicename("Quaternary Color") quaternary_color;
		// Crate Data : 
		s_undefined32_legacy __unknown12;
		s_tag_block_legacy<s_unknown10_definition> __unknown13;
		// Multiplayer Data : 
		char nicename("Custom Label") custom_label[32];
		e_symmetry nicename("Symmetry") symmetry;
		int8_t __unknown14;
		e_team nicename("Team") team;
		int16_t __unknown15;
		int8_t nicename("Spawn Sequence") spawn_sequence;
		int8_t nicename("Runtime Minimum") runtime_minimum;
		int8_t nicename("Runtime Maximum") runtime_maximum;
		b_multiplayer_flags nicename("Multiplayer Flags") multiplayer_flags;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		float nicename("Shape Width/Radius") shape_width_radius;
		float nicename("Shape Length") shape_length;
		float nicename("Shape Top") shape_top;
		float nicename("Shape Bottom") shape_bottom;
		e_shape nicename("Shape") shape;
		int8_t __unknown16;
		uint8_t nicename("Teleporter Channel") teleporter_channel;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		string_id_legacy nicename("Location String") location_string;
		int16_t __unknown17;
		int16_t nicename("Attached Name Index") attached_name_index;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		// Unknown Data : 
		s_undefined32_legacy __unknown20;
	};

	struct nicename("Crate Palette") s_crate_palette_definition
	{
		s_tag_reference_legacy nicename("Crate") crate_reference;
	};

	struct nicename("Flock Palette") s_flock_palette_definition
	{
		s_tag_reference_legacy nicename("Flock") flock_reference;
	};

	struct nicename("Flocks") s_flocks_definition
	{
		struct nicename("Sources") s_sources_definition
		{
			string_id_legacy nicename("Name") name;
			int32_t __unknown0;
			float nicename("Position x") position_x;
			float nicename("Position y") position_y;
			float nicename("Position z") position_z;
			float nicename("Starting y") starting_y;
			float nicename("Starting p") starting_p;
			float nicename("Radius") radius;
			float nicename("Weight") weight;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		struct nicename("Sinks") s_sinks_definition
		{
			string_id_legacy nicename("Name") name;
			s_undefined32_legacy __unknown0;
			float nicename("Position x") position_x;
			float nicename("Position y") position_y;
			float nicename("Position z") position_z;
			float nicename("Radius") radius;
			s_undefined32_legacy __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
		};

		string_id_legacy nicename("Name") name;
		int16_t nicename("Flock Palette Index") flock_palette_index;
		int16_t nicename("BSP Index") bsp_index;
		int16_t nicename("Bounding Trigger Volume") bounding_trigger_volume;
		int16_t __unknown0;
		float __unknown1;
		s_tag_block_legacy<s_sources_definition> nicename("Sources") sources_block;
		s_tag_block_legacy<s_sinks_definition> nicename("Sinks") sinks_block;
		float nicename("Production Frequency min") production_frequency_min;
		float nicename("Production Frequency max") production_frequency_max;
		float nicename("Scale min") scale_min;
		float nicename("Scale max") scale_max;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		int16_t nicename("Creature Palette Index") creature_palette_index;
		int16_t __unknown5;
		int16_t nicename("Boid Count min") boid_count_min;
		int16_t nicename("Boid Count max") boid_count_max;
		int16_t __unknown6;
		int16_t __unknown7;
		float __unknown8;
	};

	struct nicename("Creature Palette") s_creature_palette_definition
	{
		s_tag_reference_legacy nicename("Creature") creature_reference;
	};

	struct nicename("Big Battle Creatures") s_big_battle_creatures_definition
	{
		s_tag_reference_legacy nicename("Big Battle Creature") big_battle_creature_reference;
	};

	struct nicename("Editor Folders") s_editor_folders_definition
	{
		int32_t nicename("Parent Folder") parent_folder;
		char nicename("Name") name[256];
	};

	struct nicename("Mission Dialogue") s_mission_dialogue_definition
	{
		s_tag_reference_legacy nicename("Mission Dialogue") mission_dialogue_reference;
	};

	struct nicename("Unknown 59") s_unknown_59_definition
	{
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t __unknown6;
		int16_t __unknown7;
		int16_t __unknown8;
		int16_t __unknown9;
	};

	struct nicename("AI Objectives") s_ai_objectives_definition
	{
		struct nicename("Unknown 78") s_unknown_78_definition
		{
			s_undefined32_legacy __unknown0;
		};

		struct nicename("Roles") s_roles_definition
		{
			struct nicename("Conditions") s_conditions_definition
			{
				string_id_legacy nicename("Name") name;
				char nicename("Condition") condition[32];
				int16_t __unknown0;
				int16_t __unknown1;
			};

			struct nicename("Unknown 63") s_unknown_63_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t __unknown2;
				int16_t __unknown3;
				float __unknown4;
				int16_t __unknown5;
				int16_t __unknown6;
				s_undefined32_legacy __unknown7;
				s_undefined32_legacy __unknown8;
				s_undefined32_legacy __unknown9;
			};

			struct nicename("Point Geometry") s_point_geometry_definition
			{
				struct nicename("Points") s_points1_definition
				{
					float nicename("Point X") point_x;
					float nicename("Point Y") point_y;
					float nicename("Point Z") point_z;
					int16_t nicename("Reference Frame") reference_frame;
					int16_t __unknown0;
				};

				s_tag_block_legacy<s_points1_definition> nicename("Points") points_block;
			};

			int16_t __unknown0;
			int16_t __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
			int16_t __unknown4;
			int16_t __unknown5;
			float __unknown6;
			float __unknown7;
			int16_t __unknown8;
			int16_t __unknown9;
			s_undefined32_legacy __unknown10;
			s_undefined32_legacy __unknown11;
			s_undefined32_legacy __unknown12;
			string_id_legacy nicename("Command Script Name 1") command_script_name_1;
			string_id_legacy nicename("Command Script Name 2") command_script_name_2;
			string_id_legacy nicename("Command Script Name 3") command_script_name_3;
			int16_t nicename("Command Script Index 1") command_script_index_1;
			int16_t nicename("Command Script Index 2") command_script_index_2;
			int16_t nicename("Command Script Index 3") command_script_index_3;
			int16_t __unknown13;
			int16_t __unknown14;
			int16_t __unknown15;
			int16_t __unknown16;
			int16_t __unknown17;
			string_id_legacy nicename("Task") task;
			int16_t nicename("Hierarchy Level (From 100)") hierarchy_level_from_100;
			int16_t nicename("Previous Role") previous_role;
			int16_t nicename("Next Role") next_role;
			int16_t nicename("Parent Role") parent_role;
			s_tag_block_legacy<s_conditions_definition> nicename("Conditions") conditions_block;
			int16_t nicename("Script Index") script_index;
			int16_t __unknown18;
			int16_t __unknown19;
			int16_t nicename("Filter") filter;
			int16_t nicename("Min") min;
			int16_t nicename("Max") max;
			int16_t nicename("Bodies") bodies;
			int16_t __unknown20;
			s_undefined32_legacy __unknown21;
			s_tag_block_legacy<s_unknown_63_definition> nicename("Unknown 63") unknown_63_block;
			s_tag_block_legacy<s_point_geometry_definition> nicename("Point Geometry") point_geometry_block;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_unknown_78_definition> nicename("Unknown 78") unknown_78_block;
		int16_t __unknown0;
		int16_t nicename("Zone") zone;
		int16_t __unknown1;
		int16_t nicename("Editor Folder Index") editor_folder_index;
		s_tag_block_legacy<s_roles_definition> nicename("Roles") roles_block;
	};

	struct nicename("Designer Zonesets") s_designer_zonesets_definition
	{
		struct nicename("Bipeds") s_bipeds1_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Vehicles") s_vehicles1_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Weapons") s_weapons3_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Equipment") s_equipment3_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Scenery") s_scenery1_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Machines") s_machines1_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Terminals") s_terminals1_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Controls") s_controls1_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Unknown") s_unknown11_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Crates") s_crates1_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Creatures") s_creatures_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Giants") s_giants1_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Unknown") s_unknown12_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		struct nicename("Characters") s_characters_definition
		{
			int16_t nicename("Palette Index") palette_index;
		};

		string_id_legacy nicename("Name") name;
		s_undefined32_legacy __unknown0;
		s_tag_block_legacy<s_bipeds1_definition> nicename("Bipeds") bipeds_block;
		s_tag_block_legacy<s_vehicles1_definition> nicename("Vehicles") vehicles_block;
		s_tag_block_legacy<s_weapons3_definition> nicename("Weapons") weapons_block;
		s_tag_block_legacy<s_equipment3_definition> nicename("Equipment") equipment_block;
		s_tag_block_legacy<s_scenery1_definition> nicename("Scenery") scenery_block;
		s_tag_block_legacy<s_machines1_definition> nicename("Machines") machines_block;
		s_tag_block_legacy<s_terminals1_definition> nicename("Terminals") terminals_block;
		s_tag_block_legacy<s_controls1_definition> nicename("Controls") controls_block;
		s_tag_block_legacy<s_unknown11_definition> __unknown1;
		s_tag_block_legacy<s_crates1_definition> nicename("Crates") crates_block;
		s_tag_block_legacy<s_creatures_definition> nicename("Creatures") creatures_block;
		s_tag_block_legacy<s_giants1_definition> nicename("Giants") giants_block;
		s_tag_block_legacy<s_unknown12_definition> __unknown2;
		s_tag_block_legacy<s_characters_definition> nicename("Characters") characters_block;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
	};

	struct nicename("Unknown 61") s_unknown_61_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
	};

	struct nicename("Particle Emitters") s_particle_emitters_definition
	{
		s_tag_reference_legacy nicename("Emitter") emitter_reference;
	};

	struct nicename("Unknown") s_unknown13_definition
	{
		s_undefined32_legacy __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
	};

	struct nicename("Cinematics") s_cinematics_definition
	{
		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Cinematic") cinematic_reference;
	};

	struct nicename("Cinematic Lights") s_cinematic_lights_definition
	{
		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Light") light_reference;
	};

	struct nicename("Scenario Metagame") s_scenario_metagame_definition
	{
		struct nicename("Time Multipliers") s_time_multipliers_definition
		{
			float nicename("Time") time;
			float nicename("Multiplier") multiplier;
		};

		float nicename("Par Score") par_score;
		s_tag_block_legacy<s_time_multipliers_definition> nicename("Time Multipliers") time_multipliers_block;
	};

	struct nicename("Unknown 64") s_unknown_64_definition
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
	};

	struct nicename("Unknown 65") s_unknown_65_definition
	{
		struct nicename("Unknown 85") s_unknown_85_definition
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			s_undefined32_legacy __unknown3;
		};

		string_id_legacy __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		int16_t __unknown4;
		int16_t __unknown5;
		s_tag_block_legacy<s_unknown_85_definition> nicename("Unknown 85") unknown_85_block;
	};

	struct nicename("Vignettes") s_vignettes_definition
	{
		struct nicename("Unknown 86") s_unknown_86_definition
		{
			int32_t __unknown0;
			string_id_legacy __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
			int16_t __unknown4;
			int16_t __unknown5;
			int32_t __unknown6;
		};

		struct nicename("Unknown 87") s_unknown_87_definition
		{
			struct nicename("Script") s_script_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				char nicename("Script") script[512];
			};

			struct nicename("Unknown 89") s_unknown_89_definition
			{
				int32_t __unknown0;
				int16_t __unknown1;
				int16_t __unknown2;
				int32_t __unknown3;
				int32_t __unknown4;
			};

			struct nicename("Animation") s_animation_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t __unknown2;
				int16_t __unknown3;
				string_id_legacy nicename("Animation") animation;
				s_undefined32_legacy nicename("ZUnknown") zunknown;
				float __unknown4;
				s_undefined32_legacy nicename("ZUnknown") zunknown1;
				s_undefined32_legacy nicename("ZUnknown") zunknown2;
			};

			struct nicename("Unknown 88") s_unknown_88_definition
			{
				string_id_legacy __unknown0;
				float __unknown1;
				int16_t __unknown2;
				int16_t __unknown3;
				s_undefined32_legacy nicename("ZUnknown") zunknown;
				s_undefined32_legacy nicename("ZUnknown") zunknown1;
				s_undefined32_legacy nicename("ZUnknown") zunknown2;
			};

			struct nicename("Unknown 91") s_unknown_91_definition
			{
				int32_t __unknown0;
				float __unknown1;
			};

			string_id_legacy __unknown0;
			int16_t __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
			int16_t __unknown4;
			int32_t __unknown5;
			s_tag_block_legacy<s_script_definition> nicename("Script") script_block;
			s_tag_block_legacy<s_unknown_89_definition> nicename("Unknown 89") unknown_89_block;
			s_tag_block_legacy<s_animation_definition> nicename("Animation") animation_block;
			s_tag_block_legacy<s_unknown_88_definition> nicename("Unknown 88") unknown_88_block;
			s_undefined32_legacy nicename("ZUnknown") zunknown;
			s_undefined32_legacy nicename("ZUnknown") zunknown1;
			s_undefined32_legacy nicename("ZUnknown") zunknown2;
			s_tag_block_legacy<s_unknown_91_definition> nicename("Unknown 91") unknown_91_block;
			s_undefined32_legacy nicename("ZUnknown") zunknown3;
			s_undefined32_legacy nicename("ZUnknown") zunknown4;
			s_undefined32_legacy nicename("ZUnknown") zunknown5;
		};

		struct nicename("Unknown 85") s_unknown_851_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
		};

		string_id_legacy __unknown0;
		string_id_legacy __unknown1;
		string_id_legacy __unknown2;
		int16_t __unknown3;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t __unknown6;
		s_tag_block_legacy<s_unknown_86_definition> nicename("Unknown 86") unknown_86_block;
		s_tag_block_legacy<s_unknown_87_definition> nicename("Unknown 87") unknown_87_block;
		float nicename("X") x;
		float nicename("Y") y;
		float nicename("Z") z;
		float nicename("Yaw") yaw;
		float nicename("Pitch") pitch;
		float __unknown7;
		float __unknown8;
		float __unknown9;
		string_id_legacy nicename("Performane Template Name") performane_template_name;
		s_tag_reference_legacy nicename("Performance Template") performance_template_reference;
		s_tag_block_legacy<s_unknown_851_definition> nicename("Unknown 85") unknown_85_block;
	};

	struct nicename("Unknown 66") s_unknown_66_definition
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
	};

	struct nicename("Compiled Data") s_compiled_data_definition
	{
		uint32_t nicename("[effe] Compiled Data Pointer") effe_compiled_data_pointer;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		uint32_t nicename("[beam] Compiled Data Pointer") beam_compiled_data_pointer;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		uint32_t nicename("[cntl] Compiled Data Pointer") cntl_compiled_data_pointer;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		uint32_t nicename("[ltvl] Compiled Data Pointer") ltvl_compiled_data_pointer;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
	};

	e_map_type nicename("Map Type") map_type;
	b_flags nicename("Flags") flags;
	int32_t __unknown0;
	int32_t nicename("Campaign ID") campaign_id;
	int32_t nicename("Map ID") map_id;
	string_id_legacy nicename("Scenario Name") scenario_name;
	int16_t nicename("Campaign Level Index") campaign_level_index;
	int16_t __unknown1;
	int32_t __unknown2;
	float nicename("Local North") local_north;
	float __unknown3;
	float __unknown4;
	s_undefined32_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	float __unknown7;
	float nicename("Sandbox Budget") sandbox_budget;
	string_id_legacy nicename("Default Vehicle Filter") default_vehicle_filter;
	s_tag_reference_legacy nicename("Performance Throttle Profile") performance_throttle_profile_reference;
	s_tag_block_legacy<s_structure_bsps_definition> nicename("Structure BSPs") structure_bsps_block;
	s_tag_block_legacy<s_structure_design_definition> nicename("Structure Design") structure_design_block;
	s_tag_reference_legacy __unknown8;
	s_tag_reference_legacy __unknown9;
	s_tag_block_legacy<s_sky_references_definition> nicename("Sky References") sky_references_block;
	s_tag_block_legacy<s_bsp_groups_definition> nicename("BSP Groups") bsp_groups_block;
	s_tag_block_legacy<s_scenario_bsp_audibility_definition> nicename("Scenario BSP Audibility") scenario_bsp_audibility_block;
	s_tag_block_legacy<s_scenario_zoneset_groups_definition> nicename("Scenario Zoneset Groups") scenario_zoneset_groups_block;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	s_undefined32_legacy __unknown12;
	s_undefined32_legacy __unknown13;
	s_undefined32_legacy __unknown14;
	s_undefined32_legacy __unknown15;
	s_undefined32_legacy __unknown16;
	s_undefined32_legacy __unknown17;
	s_undefined32_legacy __unknown18;
	s_undefined32_legacy __unknown19;
	s_undefined32_legacy __unknown20;
	s_undefined32_legacy __unknown21;
	s_data_reference_legacy nicename("Editor Scenario Data") editor_scenario_data_data_reference;
	s_undefined32_legacy __unknown22;
	s_undefined32_legacy __unknown23;
	s_undefined32_legacy __unknown24;
	s_tag_block_legacy<s_object_names_definition> nicename("Object Names") object_names_block;
	s_tag_block_legacy<s_scenery_definition> nicename("Scenery") scenery_block;
	s_tag_block_legacy<s_scenery_palette_definition> nicename("Scenery Palette") scenery_palette_block;
	s_tag_block_legacy<s_bipeds_definition> nicename("Bipeds") bipeds_block;
	s_tag_block_legacy<s_biped_palette_definition> nicename("Biped Palette") biped_palette_block;
	s_tag_block_legacy<s_vehicles_definition> nicename("Vehicles") vehicles_block;
	s_tag_block_legacy<s_vehicle_palette_definition> nicename("Vehicle Palette") vehicle_palette_block;
	s_tag_block_legacy<s_equipment_definition> nicename("Equipment") equipment_block;
	s_tag_block_legacy<s_equipment_palette_definition> nicename("Equipment Palette") equipment_palette_block;
	s_tag_block_legacy<s_weapons_definition> nicename("Weapons") weapons_block;
	s_tag_block_legacy<s_weapon_palette_definition> nicename("Weapon Palette") weapon_palette_block;
	s_tag_block_legacy<s_device_groups_definition> nicename("Device Groups") device_groups_block;
	s_tag_block_legacy<s_machines_definition> nicename("Machines") machines_block;
	s_tag_block_legacy<s_machine_palette_definition> nicename("Machine Palette") machine_palette_block;
	s_tag_block_legacy<s_terminals_definition> nicename("Terminals") terminals_block;
	s_tag_block_legacy<s_terminal_palette_definition> nicename("Terminal Palette") terminal_palette_block;
	s_tag_block_legacy<s_controls_definition> nicename("Controls") controls_block;
	s_tag_block_legacy<s_control_palette_definition> nicename("Control Palette") control_palette_block;
	s_tag_block_legacy<s_sound_scenery_definition> nicename("Sound Scenery") sound_scenery_block;
	s_tag_block_legacy<s_sound_scenery_palette_definition> nicename("Sound Scenery Palette") sound_scenery_palette_block;
	s_tag_block_legacy<s_giants_definition> nicename("Giants") giants_block;
	s_tag_block_legacy<s_giant_palette_definition> nicename("Giant Palette") giant_palette_block;
	s_tag_block_legacy<s_effect_scenery_definition> nicename("Effect Scenery") effect_scenery_block;
	s_tag_block_legacy<s_effect_scenery_palette_definition> nicename("Effect Scenery Palette") effect_scenery_palette_block;
	s_tag_block_legacy<s_light_volumes_definition> nicename("Light Volumes") light_volumes_block;
	s_tag_block_legacy<s_light_volumes_palette_definition> nicename("Light Volumes Palette") light_volumes_palette_block;
	s_tag_block_legacy<s_sandbox_palette_definition> nicename("Sandbox Palette") sandbox_palette_block;
	s_tag_block_legacy<s_legacy_sandbox_info_definition> nicename("Legacy Sandbox Info") legacy_sandbox_info_block;
	s_tag_reference_legacy __unknown25;
	s_undefined32_legacy __unknown26;
	s_undefined32_legacy __unknown27;
	s_undefined32_legacy __unknown28;
	s_tag_block_legacy<s_soft_ceilings_definition> nicename("Soft Ceilings") soft_ceilings_block;
	s_tag_block_legacy<s_player_starting_profile_definition> nicename("Player Starting Profile") player_starting_profile_block;
	s_tag_block_legacy<s_player_starting_locations_definition> nicename("Player Starting Locations") player_starting_locations_block;
	s_tag_block_legacy<s_trigger_volumes_definition> nicename("Trigger Volumes") trigger_volumes_block;
	s_tag_block_legacy<s_unknown_22_definition> nicename("Unknown 22") unknown_22_block;
	s_tag_block_legacy<s_unknown_231_definition> nicename("Unknown 23") unknown_23_block;
	s_tag_block_legacy<s_unknown_28_definition> nicename("Unknown 28") unknown_28_block;
	s_undefined32_legacy __unknown29;
	s_undefined32_legacy __unknown30;
	s_undefined32_legacy __unknown31;
	s_undefined32_legacy __unknown32;
	s_undefined32_legacy __unknown33;
	s_undefined32_legacy __unknown34;
	s_tag_block_legacy<s_zoneset_switch_trigger_volumes_definition> nicename("Zoneset Switch Trigger Volumes") zoneset_switch_trigger_volumes_block;
	s_tag_block_legacy<s_location_name_callouts_definition> nicename("Location Name Callouts") location_name_callouts_block;
	s_tag_reference_legacy nicename("Airstrike Globals") airstrike_globals_reference;
	s_undefined32_legacy __unknown35;
	s_undefined32_legacy __unknown36;
	s_undefined32_legacy __unknown37;
	s_tag_block_legacy<s_unknown_40_definition> nicename("Unknown 40") unknown_40_block;
	s_tag_block_legacy<s_unknown_401_definition> nicename("Unknown 40") unknown_401_block;
	s_tag_block_legacy<s_unknown_402_definition> nicename("Unknown 40") unknown_402_block;
	s_tag_block_legacy<s_unknown_41_definition> nicename("Unknown 41") unknown_41_block;
	s_undefined32_legacy __unknown38;
	s_undefined32_legacy __unknown39;
	s_undefined32_legacy __unknown40;
	s_undefined32_legacy __unknown41;
	s_undefined32_legacy __unknown42;
	s_undefined32_legacy __unknown43;
	s_undefined32_legacy __unknown44;
	s_undefined32_legacy __unknown45;
	s_undefined32_legacy __unknown46;
	s_undefined32_legacy __unknown47;
	s_undefined32_legacy __unknown48;
	s_undefined32_legacy __unknown49;
	s_undefined32_legacy __unknown50;
	s_undefined32_legacy __unknown51;
	s_undefined32_legacy __unknown52;
	s_tag_block_legacy<s_decals_definition> nicename("Decals") decals_block;
	s_tag_block_legacy<s_decal_palette_definition> nicename("Decal Palette") decal_palette_block;
	s_undefined32_legacy __unknown53;
	s_undefined32_legacy __unknown54;
	s_undefined32_legacy __unknown55;
	s_undefined32_legacy __unknown56;
	s_undefined32_legacy __unknown57;
	s_undefined32_legacy __unknown58;
	s_tag_block_legacy<s_squad_groups_definition> nicename("Squad Groups") squad_groups_block;
	s_tag_block_legacy<s_squads_definition> nicename("Squads") squads_block;
	s_tag_block_legacy<s_zones_definition> nicename("Zones") zones_block;
	s_tag_block_legacy<s_unknown_43_definition> nicename("Unknown 43") unknown_43_block;
	s_tag_block_legacy<s_ai_cues_definition> nicename("AI Cues") ai_cues_block;
	s_undefined32_legacy __unknown59;
	s_undefined32_legacy __unknown60;
	s_undefined32_legacy __unknown61;
	s_undefined32_legacy __unknown62;
	s_undefined32_legacy __unknown63;
	s_undefined32_legacy __unknown64;
	s_undefined32_legacy __unknown65;
	s_undefined32_legacy __unknown66;
	s_undefined32_legacy __unknown67;
	s_tag_block_legacy<s_character_palette_definition> nicename("Character Palette") character_palette_block;
	s_undefined32_legacy __unknown68;
	s_undefined32_legacy __unknown69;
	s_undefined32_legacy __unknown70;
	s_tag_block_legacy<s_ai_pathfinding_data_definition> nicename("AI Pathfinding Data") ai_pathfinding_data_block;
	s_undefined32_legacy __unknown71;
	s_undefined32_legacy __unknown72;
	s_undefined32_legacy __unknown73;
	s_data_reference_legacy nicename("Script Strings") script_strings_data_reference;
	s_tag_block_legacy<s_scripts_definition> nicename("Scripts") scripts_block;
	s_tag_block_legacy<s_globals_definition> nicename("Globals") globals_block;
	s_tag_block_legacy<s_script_references_definition> nicename("Script References") script_references_block;
	s_undefined32_legacy __unknown74;
	s_undefined32_legacy __unknown75;
	s_undefined32_legacy __unknown76;
	s_tag_block_legacy<s_scripting_data_definition> nicename("Scripting Data") scripting_data_block;
	s_tag_block_legacy<s_cutscene_flags_definition> nicename("Cutscene Flags") cutscene_flags_block;
	s_tag_block_legacy<s_cutscene_camera_points_definition> nicename("Cutscene Camera Points") cutscene_camera_points_block;
	s_tag_block_legacy<s_cutscene_titles_definition> nicename("Cutscene Titles") cutscene_titles_block;
	s_tag_reference_legacy nicename("Custom Object Name Strings") custom_object_name_strings_reference;
	s_tag_reference_legacy nicename("Chapter Title Strings") chapter_title_strings_reference;
	s_tag_block_legacy<s_scenario_resources_definition> nicename("Scenario Resources") scenario_resources_block;
	s_tag_block_legacy<s_unit_seats_mapping_definition> nicename("Unit Seats Mapping") unit_seats_mapping_block;
	s_tag_block_legacy<s_scenario_kill_triggers_definition> nicename("Scenario Kill Triggers") scenario_kill_triggers_block;
	s_tag_block_legacy<s_scenario_safe_triggers_definition> nicename("Scenario Safe Triggers") scenario_safe_triggers_block;
	s_tag_block_legacy<s_scenario_mopp_triggers_definition> nicename("Scenario MOPP Triggers") scenario_mopp_triggers_block;
	s_undefined32_legacy __unknown77;
	s_undefined32_legacy __unknown78;
	s_undefined32_legacy __unknown79;
	s_undefined32_legacy __unknown80;
	s_undefined32_legacy __unknown81;
	s_undefined32_legacy __unknown82;
	s_tag_block_legacy<s_script_expressions_definition> nicename("Script Expressions") script_expressions_block;
	s_undefined32_legacy __unknown83;
	s_undefined32_legacy __unknown84;
	s_undefined32_legacy __unknown85;
	s_undefined32_legacy __unknown86;
	s_undefined32_legacy __unknown87;
	s_undefined32_legacy __unknown88;
	s_tag_block_legacy<s_background_sound_environment_palette_definition> nicename("Background Sound Environment Palette") background_sound_environment_palette_block;
	s_tag_block_legacy<s_fog_definition> nicename("Fog") fog_block;
	s_tag_block_legacy<s_camera_fx_definition> nicename("Camera FX") camera_fx_block;
	s_tag_block_legacy<s_weather_definition> nicename("Weather") weather_block;
	s_tag_block_legacy<s_scenario_cluster_data_definition> nicename("Scenario Cluster Data") scenario_cluster_data_block;
	int32_t nicename("Object Salts  1") object_salts__1;
	int32_t nicename("Object Salts  2") object_salts__2;
	int32_t nicename("Object Salts  3") object_salts__3;
	int32_t nicename("Object Salts  4") object_salts__4;
	int32_t nicename("Object Salts  5") object_salts__5;
	int32_t nicename("Object Salts  6") object_salts__6;
	int32_t nicename("Object Salts  7") object_salts__7;
	int32_t nicename("Object Salts  8") object_salts__8;
	int32_t nicename("Object Salts  9") object_salts__9;
	int32_t nicename("Object Salts 10") object_salts_10;
	int32_t nicename("Object Salts 11") object_salts_11;
	int32_t nicename("Object Salts 12") object_salts_12;
	int32_t nicename("Object Salts 13") object_salts_13;
	int32_t nicename("Object Salts 14") object_salts_14;
	int32_t nicename("Object Salts 15") object_salts_15;
	int32_t nicename("Object Salts 16") object_salts_16;
	int32_t nicename("Object Salts 17") object_salts_17;
	int32_t nicename("Object Salts 18") object_salts_18;
	int32_t nicename("Object Salts 19") object_salts_19;
	int32_t nicename("Object Salts 20") object_salts_20;
	int32_t nicename("Object Salts 21") object_salts_21;
	int32_t nicename("Object Salts 22") object_salts_22;
	int32_t nicename("Object Salts 23") object_salts_23;
	int32_t nicename("Object Salts 24") object_salts_24;
	int32_t nicename("Object Salts 25") object_salts_25;
	int32_t nicename("Object Salts 26") object_salts_26;
	int32_t nicename("Object Salts 27") object_salts_27;
	int32_t nicename("Object Salts 28") object_salts_28;
	int32_t nicename("Object Salts 29") object_salts_29;
	int32_t nicename("Object Salts 30") object_salts_30;
	int32_t nicename("Object Salts 31") object_salts_31;
	int32_t nicename("Object Salts 32") object_salts_32;
	s_tag_block_legacy<s_spawn_data_definition> nicename("Spawn Data") spawn_data_block;
	s_tag_reference_legacy nicename("Sound Effects Collection") sound_effects_collection_reference;
	s_tag_block_legacy<s_crates_definition> nicename("Crates") crates_block;
	s_tag_block_legacy<s_crate_palette_definition> nicename("Crate Palette") crate_palette_block;
	s_tag_block_legacy<s_flock_palette_definition> nicename("Flock Palette") flock_palette_block;
	s_tag_block_legacy<s_flocks_definition> nicename("Flocks") flocks_block;
	s_tag_reference_legacy nicename("Subtitle Strings") subtitle_strings_reference;
	s_undefined32_legacy __unknown89;
	s_undefined32_legacy __unknown90;
	s_undefined32_legacy __unknown91;
	s_tag_block_legacy<s_creature_palette_definition> nicename("Creature Palette") creature_palette_block;
	s_tag_block_legacy<s_big_battle_creatures_definition> nicename("Big Battle Creatures") big_battle_creatures_block;
	s_tag_block_legacy<s_editor_folders_definition> nicename("Editor Folders") editor_folders_block;
	s_tag_reference_legacy nicename("Territory Location Name Strings") territory_location_name_strings_reference;
	s_undefined32_legacy __unknown92;
	s_undefined32_legacy __unknown93;
	s_tag_block_legacy<s_mission_dialogue_definition> nicename("Mission Dialogue") mission_dialogue_block;
	s_tag_reference_legacy nicename("Objective Strings") objective_strings_reference;
	s_tag_reference_legacy nicename("Scenario Interpolator") scenario_interpolator_reference;
	s_undefined32_legacy __unknown94;
	s_undefined32_legacy __unknown95;
	s_undefined32_legacy __unknown96;
	s_tag_reference_legacy nicename("Default Camera FX") default_camera_fx_reference;
	s_tag_reference_legacy nicename("Default Screen FX") default_screen_fx_reference;
	s_tag_reference_legacy nicename("Ambient Occlusion Profile") ambient_occlusion_profile_reference;
	s_tag_reference_legacy nicename("Sky Parameters") sky_parameters_reference;
	s_tag_reference_legacy nicename("Fog Parameters") fog_parameters_reference;
	s_tag_reference_legacy nicename("Global Lighting") global_lighting_reference;
	s_tag_reference_legacy nicename("Lightmap") lightmap_reference;
	s_tag_reference_legacy nicename("Performance Throttles") performance_throttles_reference;
	s_tag_block_legacy<s_unknown_59_definition> nicename("Unknown 59") unknown_59_block;
	s_tag_block_legacy<s_ai_objectives_definition> nicename("AI Objectives") ai_objectives_block;
	s_tag_block_legacy<s_designer_zonesets_definition> nicename("Designer Zonesets") designer_zonesets_block;
	s_tag_block_legacy<s_unknown_61_definition> nicename("Unknown 61") unknown_61_block;
	s_undefined32_legacy __unknown97;
	s_undefined32_legacy __unknown98;
	s_undefined32_legacy __unknown99;
	s_tag_block_legacy<s_particle_emitters_definition> nicename("Particle Emitters") particle_emitters_block;
	s_tag_block_legacy<s_unknown13_definition> __unknown100;
	s_tag_block_legacy<s_cinematics_definition> nicename("Cinematics") cinematics_block;
	s_tag_block_legacy<s_cinematic_lights_definition> nicename("Cinematic Lights") cinematic_lights_block;
	s_undefined32_legacy __unknown101;
	s_undefined32_legacy __unknown102;
	s_undefined32_legacy __unknown103;
	s_tag_block_legacy<s_scenario_metagame_definition> nicename("Scenario Metagame") scenario_metagame_block;
	s_tag_block_legacy<s_unknown_64_definition> nicename("Unknown 64") unknown_64_block;
	s_tag_block_legacy<s_unknown_65_definition> nicename("Unknown 65") unknown_65_block;
	s_undefined32_legacy __unknown104;
	s_undefined32_legacy __unknown105;
	s_undefined32_legacy __unknown106;
	s_undefined32_legacy __unknown107;
	s_undefined32_legacy __unknown108;
	s_undefined32_legacy __unknown109;
	s_undefined32_legacy __unknown110;
	s_undefined32_legacy __unknown111;
	s_undefined32_legacy __unknown112;
	s_tag_block_legacy<s_vignettes_definition> nicename("Vignettes") vignettes_block;
	s_tag_reference_legacy nicename("Map Location Globals") map_location_globals_reference;
	s_tag_block_legacy<s_unknown_66_definition> nicename("Unknown 66") unknown_66_block;
	s_tag_reference_legacy nicename("Mission HUD") mission_hud_reference;
	s_tag_reference_legacy nicename("Required Resources") required_resources_reference;
	s_tag_reference_legacy nicename("Variant Globals") variant_globals_reference;
	s_tag_block_legacy<s_compiled_data_definition> nicename("Compiled Data") compiled_data_block;
};

