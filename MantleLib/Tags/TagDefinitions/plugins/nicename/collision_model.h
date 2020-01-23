#pragma once

nicename("collision_model") struct s_collision_model_definition
{
	nicename("Materials") struct s_material_block_definition;
	nicename("Regions") struct s_region_block_definition;
	nicename("Pathfinding Spheres") struct s_pathfinding_sphere_block_definition;
	nicename("Nodes") struct s_node_block_definition;

	nicename("Collision Model Checksum") signed int collision_model_checksum;
	nicename("Unknown") unsigned int unknown;
	nicename("Unknown") unsigned int unknown2;
	nicename("Unknown") unsigned int unknown3;
	nicename("Flags") signed int flags;
	nicename("Materials") s_tag_block_definition<s_material_block_definition> materials;
	nicename("Regions") s_tag_block_definition<s_region_block_definition> regions;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") unsigned int unknown5;
	nicename("Unknown") unsigned int unknown6;
	nicename("Pathfinding Spheres") s_tag_block_definition<s_pathfinding_sphere_block_definition> pathfinding_spheres;
	nicename("Nodes") s_tag_block_definition<s_node_block_definition> nodes;
	nicename("Unknown") unsigned int unknown7;

	nicename("Material") struct s_material_definition
	{
		nicename("Name") string_id name;
	};

	nicename("Region") struct s_region_definition
	{
		nicename("Permutations") struct s_permutation_block_definition;

		nicename("Name") string_id name;
		nicename("Permutations") s_tag_block_definition<s_permutation_block_definition> permutations;

		nicename("Permutation") struct s_permutation_definition
		{
			nicename("BSPs") struct s_bsp_block_definition;
			nicename("BSP Physics") struct s_bsp_physic_block_definition;
			nicename("BSP MOPP Codes") struct s_bsp_mopp_code_block_definition;

			nicename("Name") string_id name;
			nicename("BSPs") s_tag_block_definition<s_bsp_block_definition> bsps;
			nicename("BSP Physics") s_tag_block_definition<s_bsp_physic_block_definition> bsp_physics;
			nicename("BSP MOPP Codes") s_tag_block_definition<s_bsp_mopp_code_block_definition> bsp_mopp_codes;

			nicename("BSP") struct s_bsp_definition
			{
				nicename("BSP 3D Nodes") struct s_bsp_3d_node_block_definition;
				nicename("Unknown") struct s_unknown2_block_definition;
				nicename("Planes") struct s_plane_block_definition;
				nicename("Leaves") struct s_leaf_block_definition;
				nicename("BSP 2D References") struct s_bsp_2d_reference_block_definition;
				nicename("BSP 2D Nodes") struct s_bsp_2d_node_block_definition;
				nicename("Surfaces") struct s_surface_block_definition;
				nicename("Edges") struct s_edge_block_definition;
				nicename("Vertices") struct s_vertex_block_definition;

				nicename("Node Index") signed short node_index;
				nicename("Unknown") signed short unknown;
				nicename("BSP 3D Nodes") s_tag_block_definition<s_bsp_3d_node_block_definition> bsp_3d_nodes;
				nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;
				nicename("Planes") s_tag_block_definition<s_plane_block_definition> planes;
				nicename("Leaves") s_tag_block_definition<s_leaf_block_definition> leaves;
				nicename("BSP 2D References") s_tag_block_definition<s_bsp_2d_reference_block_definition> bsp_2d_references;
				nicename("BSP 2D Nodes") s_tag_block_definition<s_bsp_2d_node_block_definition> bsp_2d_nodes;
				nicename("Surfaces") s_tag_block_definition<s_surface_block_definition> surfaces;
				nicename("Edges") s_tag_block_definition<s_edge_block_definition> edges;
				nicename("Vertices") s_tag_block_definition<s_vertex_block_definition> vertices;

				nicename("BSP 3D Node") struct s_bsp_3d_node_definition
				{
					nicename("Unknown") unsigned char unknown;
					nicename("Second Child") signed short second_child;
					nicename("Unknown") unsigned char unknown2;
					nicename("First Child") signed short first_child;
					nicename("Plane") signed short plane;
				};

				nicename("Unknown") struct s_unknown_definition
				{
					nicename("Unknown") unsigned int unknown2;
					nicename("Unknown") unsigned int unknown3;
					nicename("Unknown") unsigned int unknown4;
					nicename("Unknown") unsigned int unknown5;
					nicename("Unknown") unsigned int unknown6;
					nicename("Unknown") unsigned int unknown7;
					nicename("Unknown") unsigned int unknown8;
					nicename("Unknown") unsigned int unknown9;
					nicename("Unknown") unsigned int unknown10;
					nicename("Unknown") unsigned int unknown11;
					nicename("Unknown") unsigned int unknown12;
					nicename("Unknown") unsigned int unknown13;
					nicename("Unknown") unsigned int unknown14;
					nicename("Unknown") unsigned int unknown15;
					nicename("Unknown") unsigned int unknown16;
					nicename("Unknown") unsigned int unknown17;
					nicename("Unknown") unsigned int unknown18;
					nicename("Unknown") unsigned int unknown19;
					nicename("Unknown") unsigned int unknown20;
					nicename("Unknown") unsigned int unknown21;
					nicename("Unknown") unsigned int unknown22;
					nicename("Unknown") unsigned int unknown23;
					nicename("Unknown") unsigned int unknown24;
					nicename("Unknown") unsigned int unknown25;
					nicename("Unknown") unsigned int unknown26;
					nicename("Unknown") unsigned int unknown27;
					nicename("Unknown") unsigned int unknown28;
					nicename("Unknown") unsigned int unknown29;
					nicename("Unknown") unsigned int unknown30;
					nicename("Unknown") unsigned int unknown31;
					nicename("Unknown") unsigned int unknown32;
					nicename("Unknown") unsigned int unknown33;
				};

				nicename("Plane") struct s_plane_definition
				{
					nicename("Plane i") float plane_i;
					nicename("Plane j") float plane_j;
					nicename("Plane k") float plane_k;
					nicename("Plane d") float plane_d;
				};

				nicename("Leaf") struct s_leaf_definition
				{
					nicename("Flags") signed short flags;
					nicename("BSP 2D Reference Count") signed short bsp_2d_reference_count;
					nicename("Unknown") signed short unknown;
					nicename("First BSP 2D Reference") signed short first_bsp_2d_reference;
				};

				nicename("BSP 2D Reference") struct s_bsp_2d_reference_definition
				{
					nicename("Plane") signed short plane;
					nicename("BSP 2D Node") signed short bsp_2d_node;
				};

				nicename("BSP 2D Node") struct s_bsp_2d_node_definition
				{
					nicename("Plane i") float plane_i;
					nicename("Plane j") float plane_j;
					nicename("Plane d") float plane_d;
					nicename("Left Child") signed short left_child;
					nicename("Right Child") signed short right_child;
				};

				nicename("Surface") struct s_surface_definition
				{
					nicename("Plane") signed short plane;
					nicename("First Edge") signed short first_edge;
					nicename("Material") signed short material;
					nicename("Unknown") signed short unknown;
					nicename("Breakable Surface") signed short breakable_surface;
					nicename("Unknown") signed short unknown2;
				};

				nicename("Edge") struct s_edge_definition
				{
					nicename("Start Vertex") signed short start_vertex;
					nicename("End Vertex") signed short end_vertex;
					nicename("Forward Edge") signed short forward_edge;
					nicename("Reverse Edge") signed short reverse_edge;
					nicename("Left Surface") signed short left_surface;
					nicename("Right Surface") signed short right_surface;
				};

				nicename("Vertex") struct s_vertex_definition
				{
					nicename("Point x") unsigned int point_x;
					nicename("Point y") unsigned int point_y;
					nicename("Point z") unsigned int point_z;
					nicename("First Edge") signed short first_edge;
					nicename("Unknown") signed short unknown;
				};
			};

			nicename("BSP Physic") struct s_bsp_physic_definition
			{
				nicename("Unknown") signed int unknown;
				nicename("Unknown") unsigned int unknown2;
				nicename("Size") signed short size;
				nicename("Count") signed short count;
				nicename("Offset") signed int offset;
				nicename("Unknown") unsigned int unknown3;
				nicename("Unknown") unsigned int unknown4;
				nicename("Unknown") unsigned int unknown5;
				nicename("Unknown") unsigned int unknown6;
				nicename("Unknown") unsigned int unknown7;
				nicename("Unknown") unsigned int unknown8;
				nicename("Unknown") unsigned int unknown9;
				nicename("Unknown") unsigned int unknown10;
				nicename("Unknown") unsigned int unknown11;
				nicename("Unknown") unsigned int unknown12;
				nicename("Unknown") unsigned int unknown13;
				nicename("Unknown") unsigned int unknown14;
				nicename("Unknown") unsigned int unknown15;
				nicename("Unknown") unsigned int unknown16;
				nicename("Unknown") unsigned int unknown17;
				nicename("Unknown") unsigned int unknown18;
				nicename("Unknown") unsigned int unknown19;
				nicename("Model") unsigned int model;
				nicename("Unknown") unsigned int unknown20;
				nicename("Unknown") unsigned int unknown21;
				nicename("Unknown") unsigned int unknown22;
				nicename("Unknown") unsigned int unknown23;
				nicename("Unknown") unsigned int unknown24;
				nicename("Unknown") unsigned int unknown25;
				nicename("Unknown") unsigned int unknown26;
				nicename("Unknown") unsigned int unknown27;
				nicename("Unknown") unsigned int unknown28;
				nicename("Unknown") unsigned int unknown29;
				nicename("Unknown") unsigned int unknown30;
				nicename("Unknown") signed int unknown31;
				nicename("Unknown") unsigned int unknown32;
				nicename("Size") signed short size2;
				nicename("Count") signed short count2;
				nicename("Offset") signed int offset2;
				nicename("Unknown") unsigned int unknown33;
				nicename("Unknown") unsigned int unknown34;
				nicename("Unknown") unsigned int unknown35;
				nicename("Unknown") unsigned int unknown36;
				nicename("Unknown") unsigned int unknown37;
				nicename("Unknown") unsigned int unknown38;
				nicename("Unknown") unsigned int unknown39;
				nicename("Unknown") unsigned int unknown40;
				nicename("Unknown") unsigned int unknown41;
				nicename("Unknown") unsigned int unknown42;
				nicename("MOPP Data Count") signed int mopp_data_count;
				nicename("Unknown") unsigned int unknown43;
				nicename("MOPP Offset x") float mopp_offset_x;
				nicename("MOPP Offset y") float mopp_offset_y;
				nicename("MOPP Offset z") float mopp_offset_z;
				nicename("MOPP Offset Scale") float mopp_offset_scale;
				nicename("Unknown") unsigned int unknown44;
				nicename("Unknown") unsigned int unknown45;
				nicename("Unknown") unsigned int unknown46;
				nicename("Unknown") unsigned int unknown47;
				nicename("Unknown") unsigned int unknown48;
				nicename("Unknown") unsigned int unknown49;
				nicename("Unknown") unsigned int unknown50;
				nicename("Unknown") unsigned int unknown51;
				nicename("Unknown") unsigned int unknown52;
				nicename("Unknown") unsigned int unknown53;
				nicename("Unknown") unsigned int unknown54;
				nicename("Unknown") unsigned int unknown55;
			};

			nicename("BSP MOPP Code") struct s_bsp_mopp_code_definition
			{
				nicename("Data") struct s_datum_block_definition;

				nicename("Unknown") signed int unknown;
				nicename("Unknown") unsigned int unknown2;
				nicename("Size") signed short size;
				nicename("Count") signed short count;
				nicename("Offset") signed int offset;
				nicename("Unknown") unsigned int unknown3;
				nicename("Unknown") unsigned int unknown4;
				nicename("Unknown") unsigned int unknown5;
				nicename("Unknown") unsigned int unknown6;
				nicename("Unknown") unsigned int unknown7;
				nicename("Offset x") float offset_x;
				nicename("Offset y") float offset_y;
				nicename("Offset z") float offset_z;
				nicename("Offset Scale") float offset_scale;
				nicename("Unknown") unsigned int unknown8;
				nicename("Unknown") unsigned int unknown9;
				nicename("Data Size") signed int data_size;
				nicename("Data Capacity") unsigned int data_capacity;
				nicename("Unknown") unsigned int unknown10;
				nicename("Unknown") unsigned int unknown11;
				nicename("Unknown") unsigned int unknown12;
				nicename("Unknown") unsigned int unknown13;
				nicename("Data") s_tag_block_definition<s_datum_block_definition> data;
				nicename("Unknown") unsigned int unknown14;

				nicename("Datum") struct s_datum_definition
				{
					nicename("Data Byte") unsigned char data_byte;
				};
			};
		};
	};

	nicename("Pathfinding Sphere") struct s_pathfinding_sphere_definition
	{
		nicename("Node") signed short node;
		nicename("Flags") unsigned short flags;
		nicename("Center x") float center_x;
		nicename("Center y") float center_y;
		nicename("Center z") float center_z;
		nicename("Radius") float radius;
	};

	nicename("Node") struct s_node_definition
	{
		nicename("Name") string_id name;
		nicename("Unknown") signed short unknown;
		nicename("Parent Node") signed short parent_node;
		nicename("Next Sibling Node") signed short next_sibling_node;
		nicename("First Child Node") signed short first_child_node;
	};
};
