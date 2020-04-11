#pragma once

struct nicename("collision_model") tag_group('coll') s_collision_model_definition
{
	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Contains Open Edges")*/ _flags_contains_open_edges = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
	};

	struct nicename("Materials") s_materials_definition
	{
		string_id_legacy nicename("Name") name;
	};

	struct nicename("Regions") s_regions_definition
	{
		struct nicename("Permutations") s_permutations_definition
		{
			struct nicename("BSPs") s_bsps_definition
			{
				struct nicename("BSP 3D Nodes") s_bsp_3d_nodes_definition
				{
					uint8_t __unknown0;
					int16_t nicename("Second Child") second_child;
					uint8_t __unknown1;
					int16_t nicename("First Child") first_child;
					int16_t nicename("Plane") plane;
				};

				struct nicename("Unknown") s_unknown_definition
				{
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
					s_undefined32_legacy __unknown30;
					s_undefined32_legacy __unknown31;
				};

				struct nicename("Planes") s_planes_definition
				{
					float nicename("Plane i") plane_i;
					float nicename("Plane j") plane_j;
					float nicename("Plane k") plane_k;
					float nicename("Plane d") plane_d;
				};

				struct nicename("Leaves") s_leaves_definition
				{
					int16_t nicename("Flags") flags;
					int16_t nicename("BSP 2D Reference Count") bsp_2d_reference_count;
					int16_t __unknown0;
					int16_t nicename("First BSP 2D Reference") first_bsp_2d_reference;
				};

				struct nicename("BSP 2D References") s_bsp_2d_references_definition
				{
					int16_t nicename("Plane") plane;
					int16_t nicename("BSP 2D Node") bsp_2d_node;
				};

				struct nicename("BSP 2D Nodes") s_bsp_2d_nodes_definition
				{
					float nicename("Plane i") plane_i;
					float nicename("Plane j") plane_j;
					float nicename("Plane d") plane_d;
					int16_t nicename("Left Child") left_child;
					int16_t nicename("Right Child") right_child;
				};

				struct nicename("Surfaces") s_surfaces_definition
				{
					int16_t nicename("Plane") plane;
					int16_t nicename("First Edge") first_edge;
					int16_t nicename("Material") material;
					int16_t __unknown0;
					int16_t nicename("Breakable Surface") breakable_surface;
					int16_t __unknown1;
				};

				struct nicename("Edges") s_edges_definition
				{
					int16_t nicename("Start Vertex") start_vertex;
					int16_t nicename("End Vertex") end_vertex;
					int16_t nicename("Forward Edge") forward_edge;
					int16_t nicename("Reverse Edge") reverse_edge;
					int16_t nicename("Left Surface") left_surface;
					int16_t nicename("Right Surface") right_surface;
				};

				struct nicename("Vertices") s_vertices_definition
				{
					s_undefined32_legacy nicename("Point x") point_x;
					s_undefined32_legacy nicename("Point y") point_y;
					s_undefined32_legacy nicename("Point z") point_z;
					int16_t nicename("First Edge") first_edge;
					int16_t __unknown0;
				};

				int16_t nicename("Node Index") node_index;
				int16_t __unknown0;
				s_tag_block_legacy<s_bsp_3d_nodes_definition> nicename("BSP 3D Nodes") bsp_3d_nodes_block;
				s_tag_block_legacy<s_unknown_definition> __unknown1;
				s_tag_block_legacy<s_planes_definition> nicename("Planes") planes_block;
				s_tag_block_legacy<s_leaves_definition> nicename("Leaves") leaves_block;
				s_tag_block_legacy<s_bsp_2d_references_definition> nicename("BSP 2D References") bsp_2d_references_block;
				s_tag_block_legacy<s_bsp_2d_nodes_definition> nicename("BSP 2D Nodes") bsp_2d_nodes_block;
				s_tag_block_legacy<s_surfaces_definition> nicename("Surfaces") surfaces_block;
				s_tag_block_legacy<s_edges_definition> nicename("Edges") edges_block;
				s_tag_block_legacy<s_vertices_definition> nicename("Vertices") vertices_block;
			};

			struct nicename("BSP Physics") s_bsp_physics_definition
			{
				int32_t __unknown0;
				s_undefined32_legacy __unknown1;
				int16_t nicename("Size") size;
				int16_t nicename("Count") count;
				int32_t nicename("Offset") offset;
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
				s_tag_reference_legacy nicename("Model") model_reference;
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
				int32_t __unknown29;
				s_undefined32_legacy __unknown30;
				int16_t nicename("Size") size1;
				int16_t nicename("Count") count1;
				int32_t nicename("Offset") offset1;
				s_undefined32_legacy __unknown31;
				s_undefined32_legacy __unknown32;
				s_undefined32_legacy __unknown33;
				s_undefined32_legacy __unknown34;
				s_undefined32_legacy __unknown35;
				s_undefined32_legacy __unknown36;
				s_undefined32_legacy __unknown37;
				s_undefined32_legacy __unknown38;
				s_undefined32_legacy __unknown39;
				s_undefined32_legacy __unknown40;
				int32_t nicename("MOPP Data Count") mopp_data_count;
				s_undefined32_legacy __unknown41;
				float nicename("MOPP Offset x") mopp_offset_x;
				float nicename("MOPP Offset y") mopp_offset_y;
				float nicename("MOPP Offset z") mopp_offset_z;
				float nicename("MOPP Offset Scale") mopp_offset_scale;
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
				s_undefined32_legacy __unknown53;
			};

			struct nicename("BSP MOPP Codes") s_bsp_mopp_codes_definition
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

			string_id_legacy nicename("Name") name;
			s_tag_block_legacy<s_bsps_definition> nicename("BSPs") bsps_block;
			s_tag_block_legacy<s_bsp_physics_definition> nicename("BSP Physics") bsp_physics_block;
			s_tag_block_legacy<s_bsp_mopp_codes_definition> nicename("BSP MOPP Codes") bsp_mopp_codes_block;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_permutations_definition> nicename("Permutations") permutations_block;
	};

	struct nicename("Pathfinding Spheres") s_pathfinding_spheres_definition
	{
		enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
		{
			/*nicename("Remains When Open")*/ _flags1_remains_when_open = 1ui16 << 0ui16,
			/*nicename("Vehicle Only")*/ _flags1_vehicle_only = 1ui16 << 1ui16,
			/*nicename("With Sectors")*/ _flags1_with_sectors = 1ui16 << 2ui16,
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

		int16_t nicename("Node") node;
		b_flags1 nicename("Flags") flags;
		float nicename("Center x") center_x;
		float nicename("Center y") center_y;
		float nicename("Center z") center_z;
		float nicename("Radius") radius;
	};

	struct nicename("Nodes") s_nodes_definition
	{
		string_id_legacy nicename("Name") name;
		int16_t __unknown0;
		int16_t nicename("Parent Node") parent_node;
		int16_t nicename("Next Sibling Node") next_sibling_node;
		int16_t nicename("First Child Node") first_child_node;
	};

	int32_t nicename("Collision Model Checksum") collision_model_checksum;
	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	b_flags nicename("Flags") flags;
	s_tag_block_legacy<s_materials_definition> nicename("Materials") materials_block;
	s_tag_block_legacy<s_regions_definition> nicename("Regions") regions_block;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	s_undefined32_legacy __unknown5;
	s_tag_block_legacy<s_pathfinding_spheres_definition> nicename("Pathfinding Spheres") pathfinding_spheres_block;
	s_tag_block_legacy<s_nodes_definition> nicename("Nodes") nodes_block;
	s_undefined32_legacy __unknown6;
};

