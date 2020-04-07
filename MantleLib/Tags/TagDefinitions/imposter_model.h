#pragma once

struct nicename("imposter_model") tag_group('impo') s_imposter_model_definition
{
	struct nicename("Nodes") s_nodes_definition
	{
		string_id nicename("Name") name;
		uint8_t __unknown0;
		uint8_t nicename("Parent Model Node Index") parent_model_node_index;
		uint8_t __unknown1;
		uint8_t __unknown2;
	};

	struct nicename("Regions") s_regions_definition
	{
		struct nicename("Permutations") s_permutations_definition
		{
			enum nicename("Instance Flags 1") b_instance_flags_1 : uint32_t /* bitfield */
			{
				/*nicename("Instance 0")*/ _instance_flags_1_instance_0 = 1ui32 << 0ui32,
				/*nicename("Instance 1")*/ _instance_flags_1_instance_1 = 1ui32 << 1ui32,
				/*nicename("Instance 2")*/ _instance_flags_1_instance_2 = 1ui32 << 2ui32,
				/*nicename("Instance 3")*/ _instance_flags_1_instance_3 = 1ui32 << 3ui32,
				/*nicename("Instance 4")*/ _instance_flags_1_instance_4 = 1ui32 << 4ui32,
				/*nicename("Instance 5")*/ _instance_flags_1_instance_5 = 1ui32 << 5ui32,
				/*nicename("Instance 6")*/ _instance_flags_1_instance_6 = 1ui32 << 6ui32,
				/*nicename("Instance 7")*/ _instance_flags_1_instance_7 = 1ui32 << 7ui32,
				/*nicename("Instance 8")*/ _instance_flags_1_instance_8 = 1ui32 << 8ui32,
				/*nicename("Instance 9")*/ _instance_flags_1_instance_9 = 1ui32 << 9ui32,
				/*nicename("Instance 10")*/ _instance_flags_1_instance_10 = 1ui32 << 10ui32,
				/*nicename("Instance 11")*/ _instance_flags_1_instance_11 = 1ui32 << 11ui32,
				/*nicename("Instance 12")*/ _instance_flags_1_instance_12 = 1ui32 << 12ui32,
				/*nicename("Instance 13")*/ _instance_flags_1_instance_13 = 1ui32 << 13ui32,
				/*nicename("Instance 14")*/ _instance_flags_1_instance_14 = 1ui32 << 14ui32,
				/*nicename("Instance 15")*/ _instance_flags_1_instance_15 = 1ui32 << 15ui32,
				/*nicename("Instance 16")*/ _instance_flags_1_instance_16 = 1ui32 << 16ui32,
				/*nicename("Instance 17")*/ _instance_flags_1_instance_17 = 1ui32 << 17ui32,
				/*nicename("Instance 18")*/ _instance_flags_1_instance_18 = 1ui32 << 18ui32,
				/*nicename("Instance 19")*/ _instance_flags_1_instance_19 = 1ui32 << 19ui32,
				/*nicename("Instance 20")*/ _instance_flags_1_instance_20 = 1ui32 << 20ui32,
				/*nicename("Instance 21")*/ _instance_flags_1_instance_21 = 1ui32 << 21ui32,
				/*nicename("Instance 22")*/ _instance_flags_1_instance_22 = 1ui32 << 22ui32,
				/*nicename("Instance 23")*/ _instance_flags_1_instance_23 = 1ui32 << 23ui32,
				/*nicename("Instance 24")*/ _instance_flags_1_instance_24 = 1ui32 << 24ui32,
				/*nicename("Instance 25")*/ _instance_flags_1_instance_25 = 1ui32 << 25ui32,
				/*nicename("Instance 26")*/ _instance_flags_1_instance_26 = 1ui32 << 26ui32,
				/*nicename("Instance 27")*/ _instance_flags_1_instance_27 = 1ui32 << 27ui32,
				/*nicename("Instance 28")*/ _instance_flags_1_instance_28 = 1ui32 << 28ui32,
				/*nicename("Instance 29")*/ _instance_flags_1_instance_29 = 1ui32 << 29ui32,
				/*nicename("Instance 30")*/ _instance_flags_1_instance_30 = 1ui32 << 30ui32,
				/*nicename("Instance 31")*/ _instance_flags_1_instance_31 = 1ui32 << 31ui32,
			};

			enum nicename("Instance Flags 2") b_instance_flags_2 : uint32_t /* bitfield */
			{
				/*nicename("Instance 32")*/ _instance_flags_2_instance_32 = 1ui32 << 0ui32,
				/*nicename("Instance 33")*/ _instance_flags_2_instance_33 = 1ui32 << 1ui32,
				/*nicename("Instance 34")*/ _instance_flags_2_instance_34 = 1ui32 << 2ui32,
				/*nicename("Instance 35")*/ _instance_flags_2_instance_35 = 1ui32 << 3ui32,
				/*nicename("Instance 36")*/ _instance_flags_2_instance_36 = 1ui32 << 4ui32,
				/*nicename("Instance 37")*/ _instance_flags_2_instance_37 = 1ui32 << 5ui32,
				/*nicename("Instance 38")*/ _instance_flags_2_instance_38 = 1ui32 << 6ui32,
				/*nicename("Instance 39")*/ _instance_flags_2_instance_39 = 1ui32 << 7ui32,
				/*nicename("Instance 40")*/ _instance_flags_2_instance_40 = 1ui32 << 8ui32,
				/*nicename("Instance 41")*/ _instance_flags_2_instance_41 = 1ui32 << 9ui32,
				/*nicename("Instance 42")*/ _instance_flags_2_instance_42 = 1ui32 << 10ui32,
				/*nicename("Instance 43")*/ _instance_flags_2_instance_43 = 1ui32 << 11ui32,
				/*nicename("Instance 44")*/ _instance_flags_2_instance_44 = 1ui32 << 12ui32,
				/*nicename("Instance 45")*/ _instance_flags_2_instance_45 = 1ui32 << 13ui32,
				/*nicename("Instance 46")*/ _instance_flags_2_instance_46 = 1ui32 << 14ui32,
				/*nicename("Instance 47")*/ _instance_flags_2_instance_47 = 1ui32 << 15ui32,
				/*nicename("Instance 48")*/ _instance_flags_2_instance_48 = 1ui32 << 16ui32,
				/*nicename("Instance 49")*/ _instance_flags_2_instance_49 = 1ui32 << 17ui32,
				/*nicename("Instance 50")*/ _instance_flags_2_instance_50 = 1ui32 << 18ui32,
				/*nicename("Instance 51")*/ _instance_flags_2_instance_51 = 1ui32 << 19ui32,
				/*nicename("Instance 52")*/ _instance_flags_2_instance_52 = 1ui32 << 20ui32,
				/*nicename("Instance 53")*/ _instance_flags_2_instance_53 = 1ui32 << 21ui32,
				/*nicename("Instance 54")*/ _instance_flags_2_instance_54 = 1ui32 << 22ui32,
				/*nicename("Instance 55")*/ _instance_flags_2_instance_55 = 1ui32 << 23ui32,
				/*nicename("Instance 56")*/ _instance_flags_2_instance_56 = 1ui32 << 24ui32,
				/*nicename("Instance 57")*/ _instance_flags_2_instance_57 = 1ui32 << 25ui32,
				/*nicename("Instance 58")*/ _instance_flags_2_instance_58 = 1ui32 << 26ui32,
				/*nicename("Instance 59")*/ _instance_flags_2_instance_59 = 1ui32 << 27ui32,
				/*nicename("Instance 60")*/ _instance_flags_2_instance_60 = 1ui32 << 28ui32,
				/*nicename("Instance 61")*/ _instance_flags_2_instance_61 = 1ui32 << 29ui32,
				/*nicename("Instance 62")*/ _instance_flags_2_instance_62 = 1ui32 << 30ui32,
				/*nicename("Instance 63")*/ _instance_flags_2_instance_63 = 1ui32 << 31ui32,
			};

			enum nicename("Instance Flags 3") b_instance_flags_3 : uint32_t /* bitfield */
			{
				/*nicename("Instance 64")*/ _instance_flags_3_instance_64 = 1ui32 << 0ui32,
				/*nicename("Instance 65")*/ _instance_flags_3_instance_65 = 1ui32 << 1ui32,
				/*nicename("Instance 66")*/ _instance_flags_3_instance_66 = 1ui32 << 2ui32,
				/*nicename("Instance 67")*/ _instance_flags_3_instance_67 = 1ui32 << 3ui32,
				/*nicename("Instance 68")*/ _instance_flags_3_instance_68 = 1ui32 << 4ui32,
				/*nicename("Instance 69")*/ _instance_flags_3_instance_69 = 1ui32 << 5ui32,
				/*nicename("Instance 70")*/ _instance_flags_3_instance_70 = 1ui32 << 6ui32,
				/*nicename("Instance 71")*/ _instance_flags_3_instance_71 = 1ui32 << 7ui32,
				/*nicename("Instance 72")*/ _instance_flags_3_instance_72 = 1ui32 << 8ui32,
				/*nicename("Instance 73")*/ _instance_flags_3_instance_73 = 1ui32 << 9ui32,
				/*nicename("Instance 74")*/ _instance_flags_3_instance_74 = 1ui32 << 10ui32,
				/*nicename("Instance 75")*/ _instance_flags_3_instance_75 = 1ui32 << 11ui32,
				/*nicename("Instance 76")*/ _instance_flags_3_instance_76 = 1ui32 << 12ui32,
				/*nicename("Instance 77")*/ _instance_flags_3_instance_77 = 1ui32 << 13ui32,
				/*nicename("Instance 78")*/ _instance_flags_3_instance_78 = 1ui32 << 14ui32,
				/*nicename("Instance 79")*/ _instance_flags_3_instance_79 = 1ui32 << 15ui32,
				/*nicename("Instance 80")*/ _instance_flags_3_instance_80 = 1ui32 << 16ui32,
				/*nicename("Instance 81")*/ _instance_flags_3_instance_81 = 1ui32 << 17ui32,
				/*nicename("Instance 82")*/ _instance_flags_3_instance_82 = 1ui32 << 18ui32,
				/*nicename("Instance 83")*/ _instance_flags_3_instance_83 = 1ui32 << 19ui32,
				/*nicename("Instance 84")*/ _instance_flags_3_instance_84 = 1ui32 << 20ui32,
				/*nicename("Instance 85")*/ _instance_flags_3_instance_85 = 1ui32 << 21ui32,
				/*nicename("Instance 86")*/ _instance_flags_3_instance_86 = 1ui32 << 22ui32,
				/*nicename("Instance 87")*/ _instance_flags_3_instance_87 = 1ui32 << 23ui32,
				/*nicename("Instance 88")*/ _instance_flags_3_instance_88 = 1ui32 << 24ui32,
				/*nicename("Instance 89")*/ _instance_flags_3_instance_89 = 1ui32 << 25ui32,
				/*nicename("Instance 90")*/ _instance_flags_3_instance_90 = 1ui32 << 26ui32,
				/*nicename("Instance 91")*/ _instance_flags_3_instance_91 = 1ui32 << 27ui32,
				/*nicename("Instance 92")*/ _instance_flags_3_instance_92 = 1ui32 << 28ui32,
				/*nicename("Instance 93")*/ _instance_flags_3_instance_93 = 1ui32 << 29ui32,
				/*nicename("Instance 94")*/ _instance_flags_3_instance_94 = 1ui32 << 30ui32,
				/*nicename("Instance 95")*/ _instance_flags_3_instance_95 = 1ui32 << 31ui32,
			};

			enum nicename("Instance Flags 4") b_instance_flags_4 : uint32_t /* bitfield */
			{
				/*nicename("Instance 96")*/ _instance_flags_4_instance_96 = 1ui32 << 0ui32,
				/*nicename("Instance 97")*/ _instance_flags_4_instance_97 = 1ui32 << 1ui32,
				/*nicename("Instance 98")*/ _instance_flags_4_instance_98 = 1ui32 << 2ui32,
				/*nicename("Instance 99")*/ _instance_flags_4_instance_99 = 1ui32 << 3ui32,
				/*nicename("Instance 100")*/ _instance_flags_4_instance_100 = 1ui32 << 4ui32,
				/*nicename("Instance 101")*/ _instance_flags_4_instance_101 = 1ui32 << 5ui32,
				/*nicename("Instance 102")*/ _instance_flags_4_instance_102 = 1ui32 << 6ui32,
				/*nicename("Instance 103")*/ _instance_flags_4_instance_103 = 1ui32 << 7ui32,
				/*nicename("Instance 104")*/ _instance_flags_4_instance_104 = 1ui32 << 8ui32,
				/*nicename("Instance 105")*/ _instance_flags_4_instance_105 = 1ui32 << 9ui32,
				/*nicename("Instance 106")*/ _instance_flags_4_instance_106 = 1ui32 << 10ui32,
				/*nicename("Instance 107")*/ _instance_flags_4_instance_107 = 1ui32 << 11ui32,
				/*nicename("Instance 108")*/ _instance_flags_4_instance_108 = 1ui32 << 12ui32,
				/*nicename("Instance 109")*/ _instance_flags_4_instance_109 = 1ui32 << 13ui32,
				/*nicename("Instance 110")*/ _instance_flags_4_instance_110 = 1ui32 << 14ui32,
				/*nicename("Instance 111")*/ _instance_flags_4_instance_111 = 1ui32 << 15ui32,
				/*nicename("Instance 112")*/ _instance_flags_4_instance_112 = 1ui32 << 16ui32,
				/*nicename("Instance 113")*/ _instance_flags_4_instance_113 = 1ui32 << 17ui32,
				/*nicename("Instance 114")*/ _instance_flags_4_instance_114 = 1ui32 << 18ui32,
				/*nicename("Instance 115")*/ _instance_flags_4_instance_115 = 1ui32 << 19ui32,
				/*nicename("Instance 116")*/ _instance_flags_4_instance_116 = 1ui32 << 20ui32,
				/*nicename("Instance 117")*/ _instance_flags_4_instance_117 = 1ui32 << 21ui32,
				/*nicename("Instance 118")*/ _instance_flags_4_instance_118 = 1ui32 << 22ui32,
				/*nicename("Instance 119")*/ _instance_flags_4_instance_119 = 1ui32 << 23ui32,
				/*nicename("Instance 120")*/ _instance_flags_4_instance_120 = 1ui32 << 24ui32,
				/*nicename("Instance 121")*/ _instance_flags_4_instance_121 = 1ui32 << 25ui32,
				/*nicename("Instance 122")*/ _instance_flags_4_instance_122 = 1ui32 << 26ui32,
				/*nicename("Instance 123")*/ _instance_flags_4_instance_123 = 1ui32 << 27ui32,
				/*nicename("Instance 124")*/ _instance_flags_4_instance_124 = 1ui32 << 28ui32,
				/*nicename("Instance 125")*/ _instance_flags_4_instance_125 = 1ui32 << 29ui32,
				/*nicename("Instance 126")*/ _instance_flags_4_instance_126 = 1ui32 << 30ui32,
				/*nicename("Instance 127")*/ _instance_flags_4_instance_127 = 1ui32 << 31ui32,
			};

			string_id nicename("Name") name;
			int16_t nicename("Mesh Index") mesh_index;
			int16_t nicename("Mesh Count") mesh_count;
			b_instance_flags_1 nicename("Instance Flags 1") instance_flags_1;
			b_instance_flags_2 nicename("Instance Flags 2") instance_flags_2;
			b_instance_flags_3 nicename("Instance Flags 3") instance_flags_3;
			b_instance_flags_4 nicename("Instance Flags 4") instance_flags_4;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_permutations_definition> nicename("Permutations") permutations_block;
	};

	struct nicename("Meshes") s_meshes_definition
	{
		enum nicename("Vertex Type") e_vertex_type : uint8_t
		{
			/*nicename("World")*/ _vertex_type_world = 0ui8,
			/*nicename("Rigid")*/ _vertex_type_rigid = 1ui8,
			/*nicename("Skinned")*/ _vertex_type_skinned = 2ui8,
			/*nicename("Particle Model")*/ _vertex_type_particle_model = 3ui8,
			/*nicename("Flat World")*/ _vertex_type_flat_world = 4ui8,
			/*nicename("Flat Rigid")*/ _vertex_type_flat_rigid = 5ui8,
			/*nicename("Flat Skinned")*/ _vertex_type_flat_skinned = 6ui8,
			/*nicename("Screen")*/ _vertex_type_screen = 7ui8,
			/*nicename("Debug")*/ _vertex_type_debug = 8ui8,
			/*nicename("Transparent")*/ _vertex_type_transparent = 9ui8,
			/*nicename("Particle")*/ _vertex_type_particle = 10ui8,
			/*nicename("Contrail")*/ _vertex_type_contrail = 11ui8,
			/*nicename("Light Volume")*/ _vertex_type_light_volume = 12ui8,
			/*nicename("Chud Simple")*/ _vertex_type_chud_simple = 13ui8,
			/*nicename("Chud Fancy")*/ _vertex_type_chud_fancy = 14ui8,
			/*nicename("Decorator")*/ _vertex_type_decorator = 15ui8,
			/*nicename("Tiny Position")*/ _vertex_type_tiny_position = 16ui8,
			/*nicename("Patchy Fog")*/ _vertex_type_patchy_fog = 17ui8,
			/*nicename("Water")*/ _vertex_type_water = 18ui8,
			/*nicename("Ripple")*/ _vertex_type_ripple = 19ui8,
			/*nicename("Implicit")*/ _vertex_type_implicit = 20ui8,
			/*nicename("Beam")*/ _vertex_type_beam = 21ui8,
			/*nicename("World Tessellated")*/ _vertex_type_world_tessellated = 22ui8,
			/*nicename("Rigid Tessellated")*/ _vertex_type_rigid_tessellated = 23ui8,
			/*nicename("Skinned Tessellated")*/ _vertex_type_skinned_tessellated = 24ui8,
			/*nicename("Shader Cache")*/ _vertex_type_shader_cache = 25ui8,
			/*nicename("Structure Instance Imposter")*/ _vertex_type_structure_instance_imposter = 26ui8,
			/*nicename("Object Imposter")*/ _vertex_type_object_imposter = 27ui8,
			/*nicename("Rigid Compressed")*/ _vertex_type_rigid_compressed = 28ui8,
			/*nicename("Skinned Compressed")*/ _vertex_type_skinned_compressed = 29ui8,
			/*nicename("Light Volume Precompiled")*/ _vertex_type_light_volume_precompiled = 30ui8,
		};

		enum nicename("PRT Type") e_prt_type : uint8_t
		{
			/*nicename("None")*/ _prt_type_none = 0ui8,
			/*nicename("Ambient")*/ _prt_type_ambient = 1ui8,
			/*nicename("Linear")*/ _prt_type_linear = 2ui8,
			/*nicename("Quadratic")*/ _prt_type_quadratic = 3ui8,
		};

		enum nicename("Index Buffer Type") e_index_buffer_type : uint8_t
		{
			/*nicename("Point List")*/ _index_buffer_type_point_list = 0ui8,
			/*nicename("Line List")*/ _index_buffer_type_line_list = 1ui8,
			/*nicename("Line Strip")*/ _index_buffer_type_line_strip = 2ui8,
			/*nicename("Triange List")*/ _index_buffer_type_triange_list = 3ui8,
			/*nicename("Triange Fan")*/ _index_buffer_type_triange_fan = 4ui8,
			/*nicename("Triange Strip")*/ _index_buffer_type_triange_strip = 5ui8,
		};

		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Has Vertex Colors")*/ _flags_has_vertex_colors = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		struct nicename("Parts") s_parts_definition
		{
			int16_t nicename("Material Index") material_index;
			int16_t nicename("'Unknown Nodey' Index") unknown_nodey_index;
			int32_t nicename("Index Buffer Start") index_buffer_start;
			int32_t nicename("Index Buffer Count") index_buffer_count;
			int16_t nicename("Subpart Start") subpart_start;
			int16_t nicename("Subpart Count") subpart_count;
			int8_t nicename("Unknown Enum?") unknown_enum;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int16_t nicename("Vertex Count") vertex_count;
			int16_t __unknown3;
		};

		struct nicename("Subparts") s_subparts_definition
		{
			int32_t nicename("Index Buffer Start") index_buffer_start;
			int32_t nicename("Index Buffer Count") index_buffer_count;
			int16_t nicename("Part Index") part_index;
			int16_t nicename("Vertex Count") vertex_count;
			int32_t __unknown0;
		};

		struct nicename("Instanced Geometry Indices") s_instanced_geometry_indices_definition
		{
			struct nicename("Instanced Geometry Mesh Contents") s_instanced_geometry_mesh_contents_definition
			{
				int16_t nicename("Instanced Geometry Index") instanced_geometry_index;
			};

			int16_t nicename("Instanced Geometry Mesh Index 1") instanced_geometry_mesh_index_1;
			int16_t nicename("Instanced Geometry Mesh Index 2") instanced_geometry_mesh_index_2;
			s_tag_block_definition<s_instanced_geometry_mesh_contents_definition> nicename("Instanced Geometry Mesh Contents") instanced_geometry_mesh_contents_block;
		};

		struct nicename("Unknown Water") s_unknown_water_definition
		{
			int16_t __unknown0;
		};

		s_tag_block_definition<s_parts_definition> nicename("Parts") parts_block;
		s_tag_block_definition<s_subparts_definition> nicename("Subparts") subparts_block;
		int16_t nicename("Vertex Buffer Index 1") vertex_buffer_index_1;
		int16_t nicename("Vertex Buffer Index 2") vertex_buffer_index_2;
		int16_t nicename("Vertex Buffer Index 3") vertex_buffer_index_3;
		int16_t nicename("Vertex Buffer Index 4") vertex_buffer_index_4;
		int16_t nicename("Vertex Buffer Index 5") vertex_buffer_index_5;
		int16_t nicename("Vertex Buffer Index 6") vertex_buffer_index_6;
		int16_t nicename("Vertex Buffer Index 7") vertex_buffer_index_7;
		int16_t nicename("Vertex Buffer Index 8") vertex_buffer_index_8;
		int16_t nicename("Index Buffer Index 1") index_buffer_index_1;
		int16_t nicename("Index Buffer Index 2") index_buffer_index_2;
		b_flags nicename("Flags") flags;
		int8_t nicename("Rigid Node") rigid_node;
		e_vertex_type nicename("Vertex Type") vertex_type;
		e_prt_type nicename("PRT Type") prt_type;
		int8_t __unknown0;
		e_index_buffer_type nicename("Index Buffer Type") index_buffer_type;
		int8_t __unknown1;
		s_tag_block_definition<s_instanced_geometry_indices_definition> nicename("Instanced Geometry Indices") instanced_geometry_indices_block;
		s_tag_block_definition<s_unknown_water_definition> nicename("Unknown Water") unknown_water_block;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
	};

	struct nicename("Compression Info") s_compression_info_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
		float nicename("Position Bounds X min") position_bounds_x_min;
		float nicename("Position Bounds X max") position_bounds_x_max;
		float nicename("Position Bounds Y min") position_bounds_y_min;
		float nicename("Position Bounds Y max") position_bounds_y_max;
		float nicename("Position Bounds Z min") position_bounds_z_min;
		float nicename("Position Bounds Z max") position_bounds_z_max;
		float nicename("Texcoord Bounds X min") texcoord_bounds_x_min;
		float nicename("Texcoord Bounds X max") texcoord_bounds_x_max;
		float nicename("Texcoord Bounds Y min") texcoord_bounds_y_min;
		float nicename("Texcoord Bounds Y max") texcoord_bounds_y_max;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
	};

	struct nicename("Unknown Nodey") s_unknown_nodey_definition
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		int8_t nicename("Node Index") node_index;
		int8_t nicename("Node Index") node_index1;
		int8_t nicename("Node Index") node_index2;
		int8_t nicename("Node Index") node_index3;
		float __unknown8;
		float __unknown9;
		float __unknown10;
	};

	struct nicename("Unknown 8") s_unknown_8_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
		DataReference __unknown2;
	};

	struct nicename("Node Maps") s_node_maps_definition
	{
		struct nicename("Unknown") s_unknown_definition
		{
			uint8_t nicename("Node Index") node_index;
		};

		s_tag_block_definition<s_unknown_definition> __unknown0;
	};

	struct nicename("Unknown Yo") s_unknown_yo_definition
	{
		int16_t nicename("Unknown Index") unknown_index;
	};

	struct nicename("Water Meshes") s_water_meshes_definition
	{
		int16_t nicename("Mesh Index") mesh_index;
		int16_t __unknown0;
		float nicename("X Min") x_min;
		float nicename("X Max") x_max;
		float nicename("Y Min") y_min;
		float nicename("Y Max") y_max;
		float nicename("Z Min") z_min;
		float nicename("Z Max") z_max;
	};

	struct nicename("Unknown Compression Info") s_unknown_compression_info_definition
	{
		uint32_t nicename("Polyart Asset Address") polyart_asset_address;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
	};

	string_id nicename("Build Path") build_path;
	int16_t __unknown0;
	int16_t __unknown1;
	Undefined32 __unknown2;
	s_tag_block_definition<s_nodes_definition> nicename("Nodes") nodes_block;
	s_tag_block_definition<s_regions_definition> nicename("Regions") regions_block;
	int32_t __unknown3;
	s_tag_block_definition<s_meshes_definition> nicename("Meshes") meshes_block;
	s_tag_block_definition<s_compression_info_definition> nicename("Compression Info") compression_info_block;
	s_tag_block_definition<s_unknown_nodey_definition> nicename("Unknown Nodey") unknown_nodey_block;
	s_tag_block_definition<s_unknown_8_definition> nicename("Unknown 8") unknown_8_block;
	Undefined32 __unknown4;
	Undefined32 __unknown5;
	Undefined32 __unknown6;
	Undefined32 __unknown7;
	Undefined32 __unknown8;
	Undefined32 __unknown9;
	s_tag_block_definition<s_node_maps_definition> nicename("Node Maps") node_maps_block;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	Undefined32 __unknown12;
	Undefined32 __unknown13;
	Undefined32 __unknown14;
	Undefined32 __unknown15;
	Undefined32 __unknown16;
	Undefined32 __unknown17;
	Undefined32 __unknown18;
	s_tag_block_definition<s_unknown_yo_definition> nicename("Unknown Yo") unknown_yo_block;
	s_tag_block_definition<s_water_meshes_definition> nicename("Water Meshes") water_meshes_block;
	int32_t nicename("[zone] Asset Datum") zone_asset_datum;
	uint16_t nicename("[easy read] Index") easy_read_index;
	uint16_t nicename("[easy read] Salt") easy_read_salt;
	int32_t nicename("Useless Padding") useless_padding;
	s_tag_block_definition<s_unknown_compression_info_definition> nicename("Unknown Compression Info") unknown_compression_info_block;
};

