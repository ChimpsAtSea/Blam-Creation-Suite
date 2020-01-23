#pragma once

nicename("render_model") struct s_render_model_definition
{
	nicename("Regions") struct s_region_block_definition;
	nicename("Instances") struct s_instance_block_definition;
	nicename("Nodes") struct s_node_block_definition;
	nicename("Marker Groups") struct s_marker_group_block_definition;
	nicename("Materials") struct s_material_block_definition;
	nicename("Meshes") struct s_mesh_block_definition;
	nicename("Compression Info") struct s_compression_info_block_definition;
	nicename("Unknown Nodey") struct s_unknown_nodey_block_definition;
	nicename("Unknown 8") struct s_unknown_8_block_definition;
	nicename("Node Maps") struct s_node_map_block_definition;
	nicename("Unknown Yo") struct s_unknown_yo_block_definition;
	nicename("Water Meshes") struct s_water_mesh_block_definition;
	nicename("Unknown Compression Info") struct s_unknown_compression_info_block_definition;
	nicename("Unknown Nodes") struct s_unknown_node_block_definition;
	nicename("Unknown 11") struct s_unknown_11_block_definition;
	nicename("Unknown 12") struct s_unknown_12_block_definition;
	nicename("Runtime Nodes") struct s_runtime_node_block_definition;

	nicename("Name") string_id name;
	nicename("Flags") unsigned short flags;
	nicename("Unknown") signed short unknown;
	nicename("Model Checksum") signed int model_checksum;
	nicename("Regions") s_tag_block_definition<s_region_block_definition> regions;
	nicename("Unknown") unsigned int unknown2;
	nicename("Instance Starting Mesh Index") signed int instance_starting_mesh_index;
	nicename("Instances") s_tag_block_definition<s_instance_block_definition> instances;
	nicename("Unknown") unsigned int unknown3;
	nicename("Nodes") s_tag_block_definition<s_node_block_definition> nodes;
	nicename("Marker Groups") s_tag_block_definition<s_marker_group_block_definition> marker_groups;
	nicename("Materials") s_tag_block_definition<s_material_block_definition> materials;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") unsigned int unknown5;
	nicename("Unknown") unsigned int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") signed int unknown8;
	nicename("Meshes") s_tag_block_definition<s_mesh_block_definition> meshes;
	nicename("Compression Info") s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	nicename("Unknown Nodey") s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	nicename("Unknown 8") s_tag_block_definition<s_unknown_8_block_definition> unknown_8_2;
	nicename("Unknown") unsigned int unknown9;
	nicename("Unknown") unsigned int unknown10;
	nicename("Unknown") unsigned int unknown11;
	nicename("Unknown") unsigned int unknown12;
	nicename("Unknown") unsigned int unknown13;
	nicename("Unknown") unsigned int unknown14;
	nicename("Node Maps") s_tag_block_definition<s_node_map_block_definition> node_maps;
	nicename("Unknown") unsigned int unknown15;
	nicename("Unknown") unsigned int unknown16;
	nicename("Unknown") unsigned int unknown17;
	nicename("Unknown") unsigned int unknown18;
	nicename("Unknown") unsigned int unknown19;
	nicename("Unknown") unsigned int unknown20;
	nicename("Unknown") unsigned int unknown21;
	nicename("Unknown") unsigned int unknown22;
	nicename("Unknown") unsigned int unknown23;
	nicename("Unknown Yo") s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	nicename("Water Meshes") s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
	nicename("[easy read] Index") unsigned short easy_read_index;
	nicename("[easy read] Salt") unsigned short easy_read_salt;
	nicename("Useless Padding") signed int useless_padding;
	nicename("Unknown Compression Info") s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	nicename("Unknown Nodes") s_tag_block_definition<s_unknown_node_block_definition> unknown_nodes;
	nicename("Unknown 11") s_tag_block_definition<s_unknown_11_block_definition> unknown_11_2;
	nicename("Unknown A") unsigned int unknown_a;
	nicename("Unknown A") unsigned int unknown_a2;
	nicename("Unknown A") unsigned int unknown_a3;
	nicename("Unknown A") unsigned int unknown_a4;
	nicename("Unknown A") unsigned int unknown_a5;
	nicename("Unknown A") unsigned int unknown_a6;
	nicename("Unknown A") unsigned int unknown_a7;
	nicename("Unknown A") unsigned int unknown_a8;
	nicename("Unknown A") unsigned int unknown_a9;
	nicename("Unknown A") unsigned int unknown_a10;
	nicename("Unknown A") unsigned int unknown_a11;
	nicename("Unknown A") unsigned int unknown_a12;
	nicename("Unknown A") unsigned int unknown_a13;
	nicename("Unknown A") unsigned int unknown_a14;
	nicename("Unknown A") unsigned int unknown_a15;
	nicename("Unknown A") unsigned int unknown_a16;
	nicename("Unknown B") unsigned int unknown_b;
	nicename("Unknown B") unsigned int unknown_b2;
	nicename("Unknown B") unsigned int unknown_b3;
	nicename("Unknown B") unsigned int unknown_b4;
	nicename("Unknown B") unsigned int unknown_b5;
	nicename("Unknown B") unsigned int unknown_b6;
	nicename("Unknown B") unsigned int unknown_b7;
	nicename("Unknown B") unsigned int unknown_b8;
	nicename("Unknown B") unsigned int unknown_b9;
	nicename("Unknown B") unsigned int unknown_b10;
	nicename("Unknown B") unsigned int unknown_b11;
	nicename("Unknown B") unsigned int unknown_b12;
	nicename("Unknown B") unsigned int unknown_b13;
	nicename("Unknown B") unsigned int unknown_b14;
	nicename("Unknown B") unsigned int unknown_b15;
	nicename("Unknown B") unsigned int unknown_b16;
	nicename("Unknown C") unsigned int unknown_c;
	nicename("Unknown C") unsigned int unknown_c2;
	nicename("Unknown C") unsigned int unknown_c3;
	nicename("Unknown C") unsigned int unknown_c4;
	nicename("Unknown C") unsigned int unknown_c5;
	nicename("Unknown C") unsigned int unknown_c6;
	nicename("Unknown C") unsigned int unknown_c7;
	nicename("Unknown C") unsigned int unknown_c8;
	nicename("Unknown C") unsigned int unknown_c9;
	nicename("Unknown C") unsigned int unknown_c10;
	nicename("Unknown C") unsigned int unknown_c11;
	nicename("Unknown C") unsigned int unknown_c12;
	nicename("Unknown C") unsigned int unknown_c13;
	nicename("Unknown C") unsigned int unknown_c14;
	nicename("Unknown C") unsigned int unknown_c15;
	nicename("Unknown C") unsigned int unknown_c16;
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
	nicename("Unknown") unsigned int unknown34;
	nicename("Unknown") unsigned int unknown35;
	nicename("Unknown") unsigned int unknown36;
	nicename("Unknown") unsigned int unknown37;
	nicename("Unknown") unsigned int unknown38;
	nicename("Unknown") unsigned int unknown39;
	nicename("Unknown") unsigned int unknown40;
	nicename("Unknown") unsigned int unknown41;
	nicename("Unknown") unsigned int unknown42;
	nicename("Unknown") unsigned int unknown43;
	nicename("Unknown") unsigned int unknown44;
	nicename("Unknown") unsigned int unknown45;
	nicename("Unknown") unsigned int unknown46;
	nicename("Unknown") unsigned int unknown47;
	nicename("Unknown") unsigned int unknown48;
	nicename("Unknown") unsigned int unknown49;
	nicename("Unknown 12") s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;
	nicename("Runtime Nodes") s_tag_block_definition<s_runtime_node_block_definition> runtime_nodes;

	nicename("Region") struct s_region_definition
	{
		nicename("Permutations") struct s_permutation_block_definition;

		nicename("Name") string_id name;
		nicename("Permutations") s_tag_block_definition<s_permutation_block_definition> permutations;

		nicename("Permutation") struct s_permutation_definition
		{
			nicename("Name") string_id name;
			nicename("Mesh Index") signed short mesh_index;
			nicename("Mesh Count") signed short mesh_count;
			nicename("Instance Flags 1") signed int instance_flags_1;
			nicename("Instance Flags 2") signed int instance_flags_2;
			nicename("Instance Flags 3") signed int instance_flags_3;
			nicename("Instance Flags 4") signed int instance_flags_4;
		};
	};

	nicename("Instance") struct s_instance_definition
	{
		nicename("Name") string_id name;
		nicename("Node Index") signed int node_index;
		nicename("Default Scale") float default_scale;
		nicename("Inverse Forward i") float inverse_forward_i;
		nicename("Inverse Forward j") float inverse_forward_j;
		nicename("Inverse Forward k") float inverse_forward_k;
		nicename("Inverse Left i") float inverse_left_i;
		nicename("Inverse Left j") float inverse_left_j;
		nicename("Inverse Left k") float inverse_left_k;
		nicename("Inverse Up i") float inverse_up_i;
		nicename("Inverse Up j") float inverse_up_j;
		nicename("Inverse Up k") float inverse_up_k;
		nicename("Inverse Position x") float inverse_position_x;
		nicename("Inverse Position y") float inverse_position_y;
		nicename("Inverse Position z") float inverse_position_z;
	};

	nicename("Node") struct s_node_definition
	{
		nicename("Name") string_id name;
		nicename("Parent Node") signed short parent_node;
		nicename("First Child Node") signed short first_child_node;
		nicename("Next Sibling Node") signed short next_sibling_node;
		nicename("Import Node Index") signed short import_node_index;
		nicename("Default Translation x") float default_translation_x;
		nicename("Default Translation y") float default_translation_y;
		nicename("Default Translation z") float default_translation_z;
		nicename("Default Rotation i") float default_rotation_i;
		nicename("Default Rotation j") float default_rotation_j;
		nicename("Default Rotation k") float default_rotation_k;
		nicename("Default Rotation w") float default_rotation_w;
		nicename("Default Scale") float default_scale;
		nicename("Inverse Forward i") float inverse_forward_i;
		nicename("Inverse Forward j") float inverse_forward_j;
		nicename("Inverse Forward k") float inverse_forward_k;
		nicename("Inverse Left i") float inverse_left_i;
		nicename("Inverse Left j") float inverse_left_j;
		nicename("Inverse Left k") float inverse_left_k;
		nicename("Inverse Up i") float inverse_up_i;
		nicename("Inverse Up j") float inverse_up_j;
		nicename("Inverse Up k") float inverse_up_k;
		nicename("Inverse Position x") float inverse_position_x;
		nicename("Inverse Position y") float inverse_position_y;
		nicename("Inverse Position z") float inverse_position_z;
		nicename("Distance from Parent") float distance_from_parent;
	};

	nicename("Marker Group") struct s_marker_group_definition
	{
		nicename("Markers") struct s_marker_block_definition;

		nicename("Name") string_id name;
		nicename("Markers") s_tag_block_definition<s_marker_block_definition> markers;

		nicename("Marker") struct s_marker_definition
		{
			nicename("Region Index") signed char region_index;
			nicename("Permutation Index") signed char permutation_index;
			nicename("Node Index") signed char node_index;
			nicename("Unknown") signed char unknown;
			nicename("Translation x") float translation_x;
			nicename("Translation y") float translation_y;
			nicename("Translation z") float translation_z;
			nicename("Rotation i") float rotation_i;
			nicename("Rotation j") float rotation_j;
			nicename("Rotation k") float rotation_k;
			nicename("Rotation w") float rotation_w;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Unknown") unsigned int unknown5;
		};
	};

	nicename("Material") struct s_material_definition
	{
		nicename("Shader") TagReference shader;
		nicename("Unknown") signed int unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") signed char unknown5;
		nicename("Unknown") signed char unknown6;
		nicename("Unknown") signed char unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Breakable Surface Index") signed char breakable_surface_index;
		nicename("Unknown") signed char unknown11;
		nicename("Unknown") signed char unknown12;
	};

	nicename("Mesh") struct s_mesh_definition
	{
		nicename("Parts") struct s_part_block_definition;
		nicename("Subparts") struct s_subpart_block_definition;
		nicename("Instanced Geometry Indices") struct s_instanced_geometry_index_block_definition;
		nicename("Unknown Water") struct s_unknown_water_block_definition;

		nicename("Parts") s_tag_block_definition<s_part_block_definition> parts;
		nicename("Subparts") s_tag_block_definition<s_subpart_block_definition> subparts;
		nicename("Vertex Buffer Index 1") signed short vertex_buffer_index_1;
		nicename("Vertex Buffer Index 2") signed short vertex_buffer_index_2;
		nicename("Vertex Buffer Index 3") signed short vertex_buffer_index_3;
		nicename("Vertex Buffer Index 4") signed short vertex_buffer_index_4;
		nicename("Vertex Buffer Index 5") signed short vertex_buffer_index_5;
		nicename("Vertex Buffer Index 6") signed short vertex_buffer_index_6;
		nicename("Vertex Buffer Index 7") signed short vertex_buffer_index_7;
		nicename("Vertex Buffer Index 8") signed short vertex_buffer_index_8;
		nicename("Index Buffer Index 1") signed short index_buffer_index_1;
		nicename("Index Buffer Index 2") signed short index_buffer_index_2;
		nicename("Flags") unsigned short flags;
		nicename("Rigid Node") signed char rigid_node;
		nicename("Vertex Type") signed char vertex_type;
		nicename("PRT Type") signed char prt_type;
		nicename("Unknown") signed char unknown;
		nicename("Index Buffer Type") signed char index_buffer_type;
		nicename("Unknown") signed char unknown2;
		nicename("Instanced Geometry Indices") s_tag_block_definition<s_instanced_geometry_index_block_definition> instanced_geometry_indices;
		nicename("Unknown Water") s_tag_block_definition<s_unknown_water_block_definition> unknown_water2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;

		nicename("Part") struct s_part_definition
		{
			nicename("Material Index") signed short material_index;
			nicename("'Unknown Nodey' Index") signed short _unknown_nodey__index;
			nicename("Index Buffer Start") signed int index_buffer_start;
			nicename("Index Buffer Count") signed int index_buffer_count;
			nicename("Subpart Start") signed short subpart_start;
			nicename("Subpart Count") signed short subpart_count;
			nicename("Unknown Enum?") signed char unknown_enum?;
			nicename("Unknown") signed char unknown;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Vertex Count") signed short vertex_count;
			nicename("Unknown") signed short unknown4;
		};

		nicename("Subpart") struct s_subpart_definition
		{
			nicename("Index Buffer Start") signed int index_buffer_start;
			nicename("Index Buffer Count") signed int index_buffer_count;
			nicename("Part Index") signed short part_index;
			nicename("Vertex Count") signed short vertex_count;
			nicename("Unknown") signed int unknown;
		};

		nicename("Instanced Geometry Index") struct s_instanced_geometry_index_definition
		{
			nicename("Instanced Geometry Mesh Contents") struct s_instanced_geometry_mesh_content_block_definition;

			nicename("Instanced Geometry Mesh Index 1") signed short instanced_geometry_mesh_index_1;
			nicename("Instanced Geometry Mesh Index 2") signed short instanced_geometry_mesh_index_2;
			nicename("Instanced Geometry Mesh Contents") s_tag_block_definition<s_instanced_geometry_mesh_content_block_definition> instanced_geometry_mesh_contents;

			nicename("Instanced Geometry Mesh Content") struct s_instanced_geometry_mesh_content_definition
			{
				nicename("Instanced Geometry Index") signed short instanced_geometry_index;
			};
		};

		nicename("Unknown Water") struct s_unknown_water_definition
		{
			nicename("Unknown") signed short unknown;
		};
	};

	nicename("Compression Info") struct s_compression_info_definition
	{
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Position Bounds X min") float position_bounds_x_min;
		nicename("Position Bounds X max") float position_bounds_x_max;
		nicename("Position Bounds Y min") float position_bounds_y_min;
		nicename("Position Bounds Y max") float position_bounds_y_max;
		nicename("Position Bounds Z min") float position_bounds_z_min;
		nicename("Position Bounds Z max") float position_bounds_z_max;
		nicename("Texcoord Bounds X min") float texcoord_bounds_x_min;
		nicename("Texcoord Bounds X max") float texcoord_bounds_x_max;
		nicename("Texcoord Bounds Y min") float texcoord_bounds_y_min;
		nicename("Texcoord Bounds Y max") float texcoord_bounds_y_max;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
	};

	nicename("Unknown Nodey") struct s_unknown_nodey_definition
	{
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Node Index") signed char node_index;
		nicename("Node Index") signed char node_index2;
		nicename("Node Index") signed char node_index3;
		nicename("Node Index") signed char node_index4;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
	};

	nicename("Unknown 8") struct s_unknown_8_definition
	{
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") DataReference unknown3;
	};

	nicename("Node Map") struct s_node_map_definition
	{
		nicename("Unknown") struct s_unknown_block_definition;

		nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Node Index") unsigned char node_index;
		};
	};

	nicename("Unknown Yo") struct s_unknown_yo_definition
	{
		nicename("Unknown Index") signed short unknown_index;
	};

	nicename("Water Mesh") struct s_water_mesh_definition
	{
		nicename("Mesh Index") signed short mesh_index;
		nicename("Unknown") signed short unknown;
		nicename("X Min") float x_min;
		nicename("X Max") float x_max;
		nicename("Y Min") float y_min;
		nicename("Y Max") float y_max;
		nicename("Z Min") float z_min;
		nicename("Z Max") float z_max;
	};

	nicename("Unknown Compression Info") struct s_unknown_compression_info_definition
	{
		nicename("Polyart Asset Address") unsigned int polyart_asset_address;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
	};

	nicename("Unknown Node") struct s_unknown_node_definition
	{
		nicename("Unknown") signed short unknown;
	};

	nicename("Unknown 11") struct s_unknown_11_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
	};

	nicename("Unknown 12") struct s_unknown_12_definition
	{
		nicename("Unknown") unsigned int unknown;
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
		nicename("Unknown") unsigned int unknown34;
		nicename("Unknown") unsigned int unknown35;
		nicename("Unknown") unsigned int unknown36;
		nicename("Unknown") unsigned int unknown37;
		nicename("Unknown") unsigned int unknown38;
		nicename("Unknown") unsigned int unknown39;
		nicename("Unknown") unsigned int unknown40;
		nicename("Unknown") unsigned int unknown41;
		nicename("Unknown") unsigned int unknown42;
		nicename("Unknown") unsigned int unknown43;
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
		nicename("Unknown") unsigned int unknown56;
		nicename("Unknown") unsigned int unknown57;
		nicename("Unknown") unsigned int unknown58;
		nicename("Unknown") unsigned int unknown59;
		nicename("Unknown") unsigned int unknown60;
		nicename("Unknown") unsigned int unknown61;
		nicename("Unknown") unsigned int unknown62;
		nicename("Unknown") unsigned int unknown63;
		nicename("Unknown") unsigned int unknown64;
		nicename("Unknown") unsigned int unknown65;
		nicename("Unknown") unsigned int unknown66;
		nicename("Unknown") unsigned int unknown67;
		nicename("Unknown") unsigned int unknown68;
		nicename("Unknown") unsigned int unknown69;
		nicename("Unknown") unsigned int unknown70;
		nicename("Unknown") unsigned int unknown71;
		nicename("Unknown") unsigned int unknown72;
		nicename("Unknown") unsigned int unknown73;
		nicename("Unknown") unsigned int unknown74;
		nicename("Unknown") unsigned int unknown75;
		nicename("Unknown") unsigned int unknown76;
		nicename("Unknown") unsigned int unknown77;
		nicename("Unknown") unsigned int unknown78;
		nicename("Unknown") unsigned int unknown79;
		nicename("Unknown") unsigned int unknown80;
		nicename("Unknown") unsigned int unknown81;
		nicename("Unknown") unsigned int unknown82;
		nicename("Unknown") unsigned int unknown83;
		nicename("Unknown") unsigned int unknown84;
	};

	nicename("Runtime Node") struct s_runtime_node_definition
	{
		nicename("Default Rotation i") float default_rotation_i;
		nicename("Default Rotation j") float default_rotation_j;
		nicename("Default Rotation k") float default_rotation_k;
		nicename("Default Rotation w") float default_rotation_w;
		nicename("Default Translation x") float default_translation_x;
		nicename("Default Translation y") float default_translation_y;
		nicename("Default Translation z") float default_translation_z;
		nicename("Default Scale") float default_scale;
	};
};
