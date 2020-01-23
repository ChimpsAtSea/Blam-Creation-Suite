#pragma once

struct s_render_model_definition
{
	struct s_region_block_definition;
	struct s_instance_block_definition;
	struct s_node_block_definition;
	struct s_marker_group_block_definition;
	struct s_material_block_definition;
	struct s_mesh_block_definition;
	struct s_compression_info_block_definition;
	struct s_unknown_nodey_block_definition;
	struct s_unknown_8_block_definition;
	struct s_node_map_block_definition;
	struct s_unknown_yo_block_definition;
	struct s_water_mesh_block_definition;
	struct s_unknown_compression_info_block_definition;
	struct s_unknown_node_block_definition;
	struct s_unknown_11_block_definition;
	struct s_unknown_12_block_definition;
	struct s_runtime_node_block_definition;

	string_id name;
	unsigned short flags;
	signed short unknown;
	signed int model_checksum;
	s_tag_block_definition<s_region_block_definition> regions;
	unsigned int unknown2;
	signed int instance_starting_mesh_index;
	s_tag_block_definition<s_instance_block_definition> instances;
	unsigned int unknown3;
	s_tag_block_definition<s_node_block_definition> nodes;
	s_tag_block_definition<s_marker_group_block_definition> marker_groups;
	s_tag_block_definition<s_material_block_definition> materials;
	unsigned int unknown4;
	unsigned int unknown5;
	unsigned int unknown6;
	unsigned int unknown7;
	signed int unknown8;
	s_tag_block_definition<s_mesh_block_definition> meshes;
	s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	s_tag_block_definition<s_unknown_8_block_definition> unknown_8_2;
	unsigned int unknown9;
	unsigned int unknown10;
	unsigned int unknown11;
	unsigned int unknown12;
	unsigned int unknown13;
	unsigned int unknown14;
	s_tag_block_definition<s_node_map_block_definition> node_maps;
	unsigned int unknown15;
	unsigned int unknown16;
	unsigned int unknown17;
	unsigned int unknown18;
	unsigned int unknown19;
	unsigned int unknown20;
	unsigned int unknown21;
	unsigned int unknown22;
	unsigned int unknown23;
	s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	unsigned int zone_asset_datum;
	unsigned short easy_read_index;
	unsigned short easy_read_salt;
	signed int useless_padding;
	s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	s_tag_block_definition<s_unknown_node_block_definition> unknown_nodes;
	s_tag_block_definition<s_unknown_11_block_definition> unknown_11_2;
	unsigned int unknown_a;
	unsigned int unknown_a2;
	unsigned int unknown_a3;
	unsigned int unknown_a4;
	unsigned int unknown_a5;
	unsigned int unknown_a6;
	unsigned int unknown_a7;
	unsigned int unknown_a8;
	unsigned int unknown_a9;
	unsigned int unknown_a10;
	unsigned int unknown_a11;
	unsigned int unknown_a12;
	unsigned int unknown_a13;
	unsigned int unknown_a14;
	unsigned int unknown_a15;
	unsigned int unknown_a16;
	unsigned int unknown_b;
	unsigned int unknown_b2;
	unsigned int unknown_b3;
	unsigned int unknown_b4;
	unsigned int unknown_b5;
	unsigned int unknown_b6;
	unsigned int unknown_b7;
	unsigned int unknown_b8;
	unsigned int unknown_b9;
	unsigned int unknown_b10;
	unsigned int unknown_b11;
	unsigned int unknown_b12;
	unsigned int unknown_b13;
	unsigned int unknown_b14;
	unsigned int unknown_b15;
	unsigned int unknown_b16;
	unsigned int unknown_c;
	unsigned int unknown_c2;
	unsigned int unknown_c3;
	unsigned int unknown_c4;
	unsigned int unknown_c5;
	unsigned int unknown_c6;
	unsigned int unknown_c7;
	unsigned int unknown_c8;
	unsigned int unknown_c9;
	unsigned int unknown_c10;
	unsigned int unknown_c11;
	unsigned int unknown_c12;
	unsigned int unknown_c13;
	unsigned int unknown_c14;
	unsigned int unknown_c15;
	unsigned int unknown_c16;
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
	unsigned int unknown34;
	unsigned int unknown35;
	unsigned int unknown36;
	unsigned int unknown37;
	unsigned int unknown38;
	unsigned int unknown39;
	unsigned int unknown40;
	unsigned int unknown41;
	unsigned int unknown42;
	unsigned int unknown43;
	unsigned int unknown44;
	unsigned int unknown45;
	unsigned int unknown46;
	unsigned int unknown47;
	unsigned int unknown48;
	unsigned int unknown49;
	s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;
	s_tag_block_definition<s_runtime_node_block_definition> runtime_nodes;

	struct s_region_definition
	{
		struct s_permutation_block_definition;

		string_id name;
		s_tag_block_definition<s_permutation_block_definition> permutations;

		struct s_permutation_definition
		{
			string_id name;
			signed short mesh_index;
			signed short mesh_count;
			signed int instance_flags_1;
			signed int instance_flags_2;
			signed int instance_flags_3;
			signed int instance_flags_4;
		};
	};

	struct s_instance_definition
	{
		string_id name;
		signed int node_index;
		float default_scale;
		float inverse_forward_i;
		float inverse_forward_j;
		float inverse_forward_k;
		float inverse_left_i;
		float inverse_left_j;
		float inverse_left_k;
		float inverse_up_i;
		float inverse_up_j;
		float inverse_up_k;
		float inverse_position_x;
		float inverse_position_y;
		float inverse_position_z;
	};

	struct s_node_definition
	{
		string_id name;
		signed short parent_node;
		signed short first_child_node;
		signed short next_sibling_node;
		signed short import_node_index;
		float default_translation_x;
		float default_translation_y;
		float default_translation_z;
		float default_rotation_i;
		float default_rotation_j;
		float default_rotation_k;
		float default_rotation_w;
		float default_scale;
		float inverse_forward_i;
		float inverse_forward_j;
		float inverse_forward_k;
		float inverse_left_i;
		float inverse_left_j;
		float inverse_left_k;
		float inverse_up_i;
		float inverse_up_j;
		float inverse_up_k;
		float inverse_position_x;
		float inverse_position_y;
		float inverse_position_z;
		float distance_from_parent;
	};

	struct s_marker_group_definition
	{
		struct s_marker_block_definition;

		string_id name;
		s_tag_block_definition<s_marker_block_definition> markers;

		struct s_marker_definition
		{
			signed char region_index;
			signed char permutation_index;
			signed char node_index;
			signed char unknown;
			float translation_x;
			float translation_y;
			float translation_z;
			float rotation_i;
			float rotation_j;
			float rotation_k;
			float rotation_w;
			unsigned int unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
			unsigned int unknown5;
		};
	};

	struct s_material_definition
	{
		TagReference shader;
		signed int unknown;
		float unknown2;
		unsigned int unknown3;
		signed char unknown4;
		signed char unknown5;
		signed char unknown6;
		signed char unknown7;
		float unknown8;
		float unknown9;
		signed char unknown10;
		signed char breakable_surface_index;
		signed char unknown11;
		signed char unknown12;
	};

	struct s_mesh_definition
	{
		struct s_part_block_definition;
		struct s_subpart_block_definition;
		struct s_instanced_geometry_index_block_definition;
		struct s_unknown_water_block_definition;

		s_tag_block_definition<s_part_block_definition> parts;
		s_tag_block_definition<s_subpart_block_definition> subparts;
		signed short vertex_buffer_index_1;
		signed short vertex_buffer_index_2;
		signed short vertex_buffer_index_3;
		signed short vertex_buffer_index_4;
		signed short vertex_buffer_index_5;
		signed short vertex_buffer_index_6;
		signed short vertex_buffer_index_7;
		signed short vertex_buffer_index_8;
		signed short index_buffer_index_1;
		signed short index_buffer_index_2;
		unsigned short flags;
		signed char rigid_node;
		signed char vertex_type;
		signed char prt_type;
		signed char unknown;
		signed char index_buffer_type;
		signed char unknown2;
		s_tag_block_definition<s_instanced_geometry_index_block_definition> instanced_geometry_indices;
		s_tag_block_definition<s_unknown_water_block_definition> unknown_water2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;

		struct s_part_definition
		{
			signed short material_index;
			signed short _unknown_nodey__index;
			signed int index_buffer_start;
			signed int index_buffer_count;
			signed short subpart_start;
			signed short subpart_count;
			signed char unknown_enum?;
			signed char unknown;
			signed char unknown2;
			signed char unknown3;
			signed short vertex_count;
			signed short unknown4;
		};

		struct s_subpart_definition
		{
			signed int index_buffer_start;
			signed int index_buffer_count;
			signed short part_index;
			signed short vertex_count;
			signed int unknown;
		};

		struct s_instanced_geometry_index_definition
		{
			struct s_instanced_geometry_mesh_content_block_definition;

			signed short instanced_geometry_mesh_index_1;
			signed short instanced_geometry_mesh_index_2;
			s_tag_block_definition<s_instanced_geometry_mesh_content_block_definition> instanced_geometry_mesh_contents;

			struct s_instanced_geometry_mesh_content_definition
			{
				signed short instanced_geometry_index;
			};
		};

		struct s_unknown_water_definition
		{
			signed short unknown;
		};
	};

	struct s_compression_info_definition
	{
		signed short unknown;
		signed short unknown2;
		float position_bounds_x_min;
		float position_bounds_x_max;
		float position_bounds_y_min;
		float position_bounds_y_max;
		float position_bounds_z_min;
		float position_bounds_z_max;
		float texcoord_bounds_x_min;
		float texcoord_bounds_x_max;
		float texcoord_bounds_y_min;
		float texcoord_bounds_y_max;
		unsigned int unknown3;
		unsigned int unknown4;
	};

	struct s_unknown_nodey_definition
	{
		float unknown;
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		signed char node_index;
		signed char node_index2;
		signed char node_index3;
		signed char node_index4;
		float unknown9;
		float unknown10;
		float unknown11;
	};

	struct s_unknown_8_definition
	{
		signed short unknown;
		signed short unknown2;
		DataReference unknown3;
	};

	struct s_node_map_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> unknown2;

		struct s_unknown_definition
		{
			unsigned char node_index;
		};
	};

	struct s_unknown_yo_definition
	{
		signed short unknown_index;
	};

	struct s_water_mesh_definition
	{
		signed short mesh_index;
		signed short unknown;
		float x_min;
		float x_max;
		float y_min;
		float y_max;
		float z_min;
		float z_max;
	};

	struct s_unknown_compression_info_definition
	{
		unsigned int polyart_asset_address;
		unsigned int unknown;
		unsigned int unknown2;
	};

	struct s_unknown_node_definition
	{
		signed short unknown;
	};

	struct s_unknown_11_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
	};

	struct s_unknown_12_definition
	{
		unsigned int unknown;
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
		unsigned int unknown34;
		unsigned int unknown35;
		unsigned int unknown36;
		unsigned int unknown37;
		unsigned int unknown38;
		unsigned int unknown39;
		unsigned int unknown40;
		unsigned int unknown41;
		unsigned int unknown42;
		unsigned int unknown43;
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
		unsigned int unknown56;
		unsigned int unknown57;
		unsigned int unknown58;
		unsigned int unknown59;
		unsigned int unknown60;
		unsigned int unknown61;
		unsigned int unknown62;
		unsigned int unknown63;
		unsigned int unknown64;
		unsigned int unknown65;
		unsigned int unknown66;
		unsigned int unknown67;
		unsigned int unknown68;
		unsigned int unknown69;
		unsigned int unknown70;
		unsigned int unknown71;
		unsigned int unknown72;
		unsigned int unknown73;
		unsigned int unknown74;
		unsigned int unknown75;
		unsigned int unknown76;
		unsigned int unknown77;
		unsigned int unknown78;
		unsigned int unknown79;
		unsigned int unknown80;
		unsigned int unknown81;
		unsigned int unknown82;
		unsigned int unknown83;
		unsigned int unknown84;
	};

	struct s_runtime_node_definition
	{
		float default_rotation_i;
		float default_rotation_j;
		float default_rotation_k;
		float default_rotation_w;
		float default_translation_x;
		float default_translation_y;
		float default_translation_z;
		float default_scale;
	};
};
