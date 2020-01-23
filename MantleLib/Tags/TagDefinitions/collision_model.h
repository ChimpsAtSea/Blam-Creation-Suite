#pragma once

struct nicename("Collision Model") group('coll') s_collision_model_definition
{
	struct nicename("Materials") s_material_block_definition;
	struct nicename("Regions") s_region_block_definition;
	struct nicename("Pathfinding Spheres") s_pathfinding_sphere_block_definition;
	struct nicename("Nodes") s_node_block_definition;

	signed int nicename("Collision Model Checksum") collision_model_checksum; 
	Unknown32 __unknown; 
	Unknown32 __unknown2; 
	Unknown32 __unknown3; 
	signed int nicename("Flags") flags; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	s_tag_block_definition<s_region_block_definition> nicename("Regions") regions_block; 
	Unknown32 __unknown4; 
	Unknown32 __unknown5; 
	Unknown32 __unknown6; 
	s_tag_block_definition<s_pathfinding_sphere_block_definition> nicename("Pathfinding Spheres") pathfinding_spheres_block; 
	s_tag_block_definition<s_node_block_definition> nicename("Nodes") nodes_block; 
	Unknown32 __unknown7; 

	struct nicename("material") s_material_block_definition
	{
		string_id nicename("Name") name; 
	};

	struct nicename("region") s_region_block_definition
	{
		struct nicename("Permutations") s_permutation_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_permutation_block_definition> nicename("Permutations") permutations_block; 

		struct nicename("permutation") s_permutation_block_definition
		{
			struct nicename("BSPs") s_bsp_block_definition;
			struct nicename("BSP Physics") s_bsp_physic_block_definition;
			struct nicename("BSP MOPP Codes") s_bsp_mopp_code_block_definition;

			string_id nicename("Name") name; 
			s_tag_block_definition<s_bsp_block_definition> nicename("BSPs") bsps_block; 
			s_tag_block_definition<s_bsp_physic_block_definition> nicename("BSP Physics") bsp_physics_block; 
			s_tag_block_definition<s_bsp_mopp_code_block_definition> nicename("BSP MOPP Codes") bsp_mopp_codes_block; 

			struct nicename("bsp") s_bsp_block_definition
			{
				struct nicename("BSP 3D Nodes") s_bsp_3d_node_block_definition;
				struct s_unknown_block_definition;
				struct nicename("Planes") s_plane_block_definition;
				struct nicename("Leaves") s_leaf_block_definition;
				struct nicename("BSP 2D References") s_bsp_2d_reference_block_definition;
				struct nicename("BSP 2D Nodes") s_bsp_2d_node_block_definition;
				struct nicename("Surfaces") s_surface_block_definition;
				struct nicename("Edges") s_edge_block_definition;
				struct nicename("Vertices") s_vertex_block_definition;

				signed short nicename("Node Index") node_index; 
				signed short __unknown; 
				s_tag_block_definition<s_bsp_3d_node_block_definition> nicename("BSP 3D Nodes") bsp_3d_nodes_block; 
				s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
				s_tag_block_definition<s_plane_block_definition> nicename("Planes") planes_block; 
				s_tag_block_definition<s_leaf_block_definition> nicename("Leaves") leaves_block; 
				s_tag_block_definition<s_bsp_2d_reference_block_definition> nicename("BSP 2D References") bsp_2d_references_block; 
				s_tag_block_definition<s_bsp_2d_node_block_definition> nicename("BSP 2D Nodes") bsp_2d_nodes_block; 
				s_tag_block_definition<s_surface_block_definition> nicename("Surfaces") surfaces_block; 
				s_tag_block_definition<s_edge_block_definition> nicename("Edges") edges_block; 
				s_tag_block_definition<s_vertex_block_definition> nicename("Vertices") vertices_block; 

				struct nicename("bsp_3d_node") s_bsp_3d_node_block_definition
				{
					unsigned char __unknown; 
					signed short nicename("Second Child") second_child; 
					unsigned char __unknown2; 
					signed short nicename("First Child") first_child; 
					signed short nicename("Plane") plane; 
				};

				struct s_unknown_block_definition
				{
					Unknown32 __unknown; 
					Unknown32 __unknown2; 
					Unknown32 __unknown3; 
					Unknown32 __unknown4; 
					Unknown32 __unknown5; 
					Unknown32 __unknown6; 
					Unknown32 __unknown7; 
					Unknown32 __unknown8; 
					Unknown32 __unknown9; 
					Unknown32 __unknown10; 
					Unknown32 __unknown11; 
					Unknown32 __unknown12; 
					Unknown32 __unknown13; 
					Unknown32 __unknown14; 
					Unknown32 __unknown15; 
					Unknown32 __unknown16; 
					Unknown32 __unknown17; 
					Unknown32 __unknown18; 
					Unknown32 __unknown19; 
					Unknown32 __unknown20; 
					Unknown32 __unknown21; 
					Unknown32 __unknown22; 
					Unknown32 __unknown23; 
					Unknown32 __unknown24; 
					Unknown32 __unknown25; 
					Unknown32 __unknown26; 
					Unknown32 __unknown27; 
					Unknown32 __unknown28; 
					Unknown32 __unknown29; 
					Unknown32 __unknown30; 
					Unknown32 __unknown31; 
					Unknown32 __unknown32; 
				};

				struct nicename("plane") s_plane_block_definition
				{
					float nicename("Plane i") plane_i; 
					float nicename("Plane j") plane_j; 
					float nicename("Plane k") plane_k; 
					float nicename("Plane d") plane_d; 
				};

				struct nicename("leaf") s_leaf_block_definition
				{
					signed short nicename("Flags") flags; 
					signed short nicename("BSP 2D Reference Count") bsp_2d_reference_count; 
					signed short __unknown; 
					signed short nicename("First BSP 2D Reference") first_bsp_2d_reference; 
				};

				struct nicename("bsp_2d_reference") s_bsp_2d_reference_block_definition
				{
					signed short nicename("Plane") plane; 
					signed short nicename("BSP 2D Node") bsp_2d_node; 
				};

				struct nicename("bsp_2d_node") s_bsp_2d_node_block_definition
				{
					float nicename("Plane i") plane_i; 
					float nicename("Plane j") plane_j; 
					float nicename("Plane d") plane_d; 
					signed short nicename("Left Child") left_child; 
					signed short nicename("Right Child") right_child; 
				};

				struct nicename("surface") s_surface_block_definition
				{
					signed short nicename("Plane") plane; 
					signed short nicename("First Edge") first_edge; 
					signed short nicename("Material") material; 
					signed short __unknown; 
					signed short nicename("Breakable Surface") breakable_surface; 
					signed short __unknown2; 
				};

				struct nicename("edge") s_edge_block_definition
				{
					signed short nicename("Start Vertex") start_vertex; 
					signed short nicename("End Vertex") end_vertex; 
					signed short nicename("Forward Edge") forward_edge; 
					signed short nicename("Reverse Edge") reverse_edge; 
					signed short nicename("Left Surface") left_surface; 
					signed short nicename("Right Surface") right_surface; 
				};

				struct nicename("vertex") s_vertex_block_definition
				{
					Unknown32 __point_x; 
					Unknown32 __point_y; 
					Unknown32 __point_z; 
					signed short nicename("First Edge") first_edge; 
					signed short __unknown; 
				};
			};

			struct nicename("bsp_physic") s_bsp_physic_block_definition
			{
				signed int __unknown; 
				Unknown32 __unknown2; 
				signed short nicename("Size") size; 
				signed short nicename("Count") count; 
				signed int nicename("Offset") offset; 
				Unknown32 __unknown3; 
				Unknown32 __unknown4; 
				Unknown32 __unknown5; 
				Unknown32 __unknown6; 
				Unknown32 __unknown7; 
				Unknown32 __unknown8; 
				Unknown32 __unknown9; 
				Unknown32 __unknown10; 
				Unknown32 __unknown11; 
				Unknown32 __unknown12; 
				Unknown32 __unknown13; 
				Unknown32 __unknown14; 
				Unknown32 __unknown15; 
				Unknown32 __unknown16; 
				Unknown32 __unknown17; 
				Unknown32 __unknown18; 
				unsigned int nicename("Model") model; 
				Unknown32 __unknown19; 
				Unknown32 __unknown20; 
				Unknown32 __unknown21; 
				Unknown32 __unknown22; 
				Unknown32 __unknown23; 
				Unknown32 __unknown24; 
				Unknown32 __unknown25; 
				Unknown32 __unknown26; 
				Unknown32 __unknown27; 
				Unknown32 __unknown28; 
				Unknown32 __unknown29; 
				signed int __unknown30; 
				Unknown32 __unknown31; 
				signed short nicename("Size") size2; 
				signed short nicename("Count") count2; 
				signed int nicename("Offset") offset2; 
				Unknown32 __unknown32; 
				Unknown32 __unknown33; 
				Unknown32 __unknown34; 
				Unknown32 __unknown35; 
				Unknown32 __unknown36; 
				Unknown32 __unknown37; 
				Unknown32 __unknown38; 
				Unknown32 __unknown39; 
				Unknown32 __unknown40; 
				Unknown32 __unknown41; 
				signed int nicename("MOPP Data Count") mopp_data_count; 
				Unknown32 __unknown42; 
				float nicename("MOPP Offset x") mopp_offset_x; 
				float nicename("MOPP Offset y") mopp_offset_y; 
				float nicename("MOPP Offset z") mopp_offset_z; 
				float nicename("MOPP Offset Scale") mopp_offset_scale; 
				Unknown32 __unknown43; 
				Unknown32 __unknown44; 
				Unknown32 __unknown45; 
				Unknown32 __unknown46; 
				Unknown32 __unknown47; 
				Unknown32 __unknown48; 
				Unknown32 __unknown49; 
				Unknown32 __unknown50; 
				Unknown32 __unknown51; 
				Unknown32 __unknown52; 
				Unknown32 __unknown53; 
				Unknown32 __unknown54; 
			};

			struct nicename("bsp_mopp_code") s_bsp_mopp_code_block_definition
			{
				struct nicename("Data") s_datum_block_definition;

				signed int __unknown; 
				Unknown32 __unknown2; 
				signed short nicename("Size") size; 
				signed short nicename("Count") count; 
				signed int nicename("Offset") offset; 
				Unknown32 __unknown3; 
				Unknown32 __unknown4; 
				Unknown32 __unknown5; 
				Unknown32 __unknown6; 
				float nicename("Offset x") offset_x; 
				float nicename("Offset y") offset_y; 
				float nicename("Offset z") offset_z; 
				float nicename("Offset Scale") offset_scale; 
				Unknown32 __unknown7; 
				Unknown32 __unknown8; 
				signed int nicename("Data Size") data_size; 
				unsigned int nicename("Data Capacity") data_capacity; 
				Unknown32 __unknown9; 
				Unknown32 __unknown10; 
				Unknown32 __unknown11; 
				Unknown32 __unknown12; 
				s_tag_block_definition<s_datum_block_definition> nicename("Data") data_block; 
				Unknown32 __unknown13; 

				struct nicename("datum") s_datum_block_definition
				{
					unsigned char nicename("Data Byte") data_byte; 
				};
			};
		};
	};

	struct nicename("pathfinding_sphere") s_pathfinding_sphere_block_definition
	{
		signed short nicename("Node") node; 
		unsigned short nicename("Flags") flags; 
		float nicename("Center x") center_x; 
		float nicename("Center y") center_y; 
		float nicename("Center z") center_z; 
		float nicename("Radius") radius; 
	};

	struct nicename("node") s_node_block_definition
	{
		string_id nicename("Name") name; 
		signed short __unknown; 
		signed short nicename("Parent Node") parent_node; 
		signed short nicename("Next Sibling Node") next_sibling_node; 
		signed short nicename("First Child Node") first_child_node; 
	};
};
