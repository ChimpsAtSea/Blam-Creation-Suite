#pragma once

struct s_collision_model_definition
{
	struct s_material_block_definition;
	struct s_region_block_definition;
	struct s_pathfinding_sphere_block_definition;
	struct s_node_block_definition;

	signed int collision_model_checksum;
	unsigned int unknown;
	unsigned int unknown2;
	unsigned int unknown3;
	signed int flags;
	s_tag_block_definition<s_material_block_definition> materials;
	s_tag_block_definition<s_region_block_definition> regions;
	unsigned int unknown4;
	unsigned int unknown5;
	unsigned int unknown6;
	s_tag_block_definition<s_pathfinding_sphere_block_definition> pathfinding_spheres;
	s_tag_block_definition<s_node_block_definition> nodes;
	unsigned int unknown7;

	struct s_material_definition
	{
		string_id name;
	};

	struct s_region_definition
	{
		struct s_permutation_block_definition;

		string_id name;
		s_tag_block_definition<s_permutation_block_definition> permutations;

		struct s_permutation_definition
		{
			struct s_bsp_block_definition;
			struct s_bsp_physic_block_definition;
			struct s_bsp_mopp_code_block_definition;

			string_id name;
			s_tag_block_definition<s_bsp_block_definition> bsps;
			s_tag_block_definition<s_bsp_physic_block_definition> bsp_physics;
			s_tag_block_definition<s_bsp_mopp_code_block_definition> bsp_mopp_codes;

			struct s_bsp_definition
			{
				struct s_bsp_3d_node_block_definition;
				struct s_unknown2_block_definition;
				struct s_plane_block_definition;
				struct s_leaf_block_definition;
				struct s_bsp_2d_reference_block_definition;
				struct s_bsp_2d_node_block_definition;
				struct s_surface_block_definition;
				struct s_edge_block_definition;
				struct s_vertex_block_definition;

				signed short node_index;
				signed short unknown;
				s_tag_block_definition<s_bsp_3d_node_block_definition> bsp_3d_nodes;
				s_tag_block_definition<s_unknown2_block_definition> unknown3;
				s_tag_block_definition<s_plane_block_definition> planes;
				s_tag_block_definition<s_leaf_block_definition> leaves;
				s_tag_block_definition<s_bsp_2d_reference_block_definition> bsp_2d_references;
				s_tag_block_definition<s_bsp_2d_node_block_definition> bsp_2d_nodes;
				s_tag_block_definition<s_surface_block_definition> surfaces;
				s_tag_block_definition<s_edge_block_definition> edges;
				s_tag_block_definition<s_vertex_block_definition> vertices;

				struct s_bsp_3d_node_definition
				{
					unsigned char unknown;
					signed short second_child;
					unsigned char unknown2;
					signed short first_child;
					signed short plane;
				};

				struct s_unknown_definition
				{
					unsigned int unknown2;
					unsigned int unknown3;
					unsigned int unknown4;
					unsigned int unknown5;
					unsigned int unknown6;
					unsigned int unknown7;
					unsigned int unknown8;
					unsigned int unknown9;
					unsigned int unknown10;
					unsigned int unknown11;
					unsigned int unknown12;
					unsigned int unknown13;
					unsigned int unknown14;
					unsigned int unknown15;
					unsigned int unknown16;
					unsigned int unknown17;
					unsigned int unknown18;
					unsigned int unknown19;
					unsigned int unknown20;
					unsigned int unknown21;
					unsigned int unknown22;
					unsigned int unknown23;
					unsigned int unknown24;
					unsigned int unknown25;
					unsigned int unknown26;
					unsigned int unknown27;
					unsigned int unknown28;
					unsigned int unknown29;
					unsigned int unknown30;
					unsigned int unknown31;
					unsigned int unknown32;
					unsigned int unknown33;
				};

				struct s_plane_definition
				{
					float plane_i;
					float plane_j;
					float plane_k;
					float plane_d;
				};

				struct s_leaf_definition
				{
					signed short flags;
					signed short bsp_2d_reference_count;
					signed short unknown;
					signed short first_bsp_2d_reference;
				};

				struct s_bsp_2d_reference_definition
				{
					signed short plane;
					signed short bsp_2d_node;
				};

				struct s_bsp_2d_node_definition
				{
					float plane_i;
					float plane_j;
					float plane_d;
					signed short left_child;
					signed short right_child;
				};

				struct s_surface_definition
				{
					signed short plane;
					signed short first_edge;
					signed short material;
					signed short unknown;
					signed short breakable_surface;
					signed short unknown2;
				};

				struct s_edge_definition
				{
					signed short start_vertex;
					signed short end_vertex;
					signed short forward_edge;
					signed short reverse_edge;
					signed short left_surface;
					signed short right_surface;
				};

				struct s_vertex_definition
				{
					unsigned int point_x;
					unsigned int point_y;
					unsigned int point_z;
					signed short first_edge;
					signed short unknown;
				};
			};

			struct s_bsp_physic_definition
			{
				signed int unknown;
				unsigned int unknown2;
				signed short size;
				signed short count;
				signed int offset;
				unsigned int unknown3;
				unsigned int unknown4;
				unsigned int unknown5;
				unsigned int unknown6;
				unsigned int unknown7;
				unsigned int unknown8;
				unsigned int unknown9;
				unsigned int unknown10;
				unsigned int unknown11;
				unsigned int unknown12;
				unsigned int unknown13;
				unsigned int unknown14;
				unsigned int unknown15;
				unsigned int unknown16;
				unsigned int unknown17;
				unsigned int unknown18;
				unsigned int unknown19;
				unsigned int model;
				unsigned int unknown20;
				unsigned int unknown21;
				unsigned int unknown22;
				unsigned int unknown23;
				unsigned int unknown24;
				unsigned int unknown25;
				unsigned int unknown26;
				unsigned int unknown27;
				unsigned int unknown28;
				unsigned int unknown29;
				unsigned int unknown30;
				signed int unknown31;
				unsigned int unknown32;
				signed short size2;
				signed short count2;
				signed int offset2;
				unsigned int unknown33;
				unsigned int unknown34;
				unsigned int unknown35;
				unsigned int unknown36;
				unsigned int unknown37;
				unsigned int unknown38;
				unsigned int unknown39;
				unsigned int unknown40;
				unsigned int unknown41;
				unsigned int unknown42;
				signed int mopp_data_count;
				unsigned int unknown43;
				float mopp_offset_x;
				float mopp_offset_y;
				float mopp_offset_z;
				float mopp_offset_scale;
				unsigned int unknown44;
				unsigned int unknown45;
				unsigned int unknown46;
				unsigned int unknown47;
				unsigned int unknown48;
				unsigned int unknown49;
				unsigned int unknown50;
				unsigned int unknown51;
				unsigned int unknown52;
				unsigned int unknown53;
				unsigned int unknown54;
				unsigned int unknown55;
			};

			struct s_bsp_mopp_code_definition
			{
				struct s_datum_block_definition;

				signed int unknown;
				unsigned int unknown2;
				signed short size;
				signed short count;
				signed int offset;
				unsigned int unknown3;
				unsigned int unknown4;
				unsigned int unknown5;
				unsigned int unknown6;
				unsigned int unknown7;
				float offset_x;
				float offset_y;
				float offset_z;
				float offset_scale;
				unsigned int unknown8;
				unsigned int unknown9;
				signed int data_size;
				unsigned int data_capacity;
				unsigned int unknown10;
				unsigned int unknown11;
				unsigned int unknown12;
				unsigned int unknown13;
				s_tag_block_definition<s_datum_block_definition> data;
				unsigned int unknown14;

				struct s_datum_definition
				{
					unsigned char data_byte;
				};
			};
		};
	};

	struct s_pathfinding_sphere_definition
	{
		signed short node;
		unsigned short flags;
		float center_x;
		float center_y;
		float center_z;
		float radius;
	};

	struct s_node_definition
	{
		string_id name;
		signed short unknown;
		signed short parent_node;
		signed short next_sibling_node;
		signed short first_child_node;
	};
};
