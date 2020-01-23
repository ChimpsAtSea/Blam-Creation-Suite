#pragma once

struct nicename("Render Model") group('mode') s_render_model_definition
{
	struct nicename("Regions") s_region_block_definition;
	struct nicename("Instances") s_instance_block_definition;
	struct nicename("Nodes") s_node_block_definition;
	struct nicename("Marker Groups") s_marker_group_block_definition;
	struct nicename("Materials") s_material_block_definition;
	struct nicename("Meshes") s_mesh_block_definition;
	struct nicename("Compression Info") s_compression_info_block_definition;
	struct s_unknown_nodey_block_definition;
	struct s_unknown_8_block_definition;
	struct nicename("Node Maps") s_node_map_block_definition;
	struct s_unknown_yo_block_definition;
	struct nicename("Water Meshes") s_water_mesh_block_definition;
	struct s_unknown_compression_info_block_definition;
	struct s_unknown_node_block_definition;
	struct s_unknown_11_block_definition;
	struct s_unknown_12_block_definition;
	struct nicename("Runtime Nodes") s_runtime_node_block_definition;

	string_id nicename("Name") name; 
	uint16_t nicename("Flags") flags; 
	int16_t __unknown; 
	int32_t nicename("Model Checksum") model_checksum; 
	s_tag_block_definition<s_region_block_definition> nicename("Regions") regions_block; 
	Undefined32 __unknown2; 
	int32_t nicename("Instance Starting Mesh Index") instance_starting_mesh_index; 
	s_tag_block_definition<s_instance_block_definition> nicename("Instances") instances_block; 
	Undefined32 __unknown3; 
	s_tag_block_definition<s_node_block_definition> nicename("Nodes") nodes_block; 
	s_tag_block_definition<s_marker_group_block_definition> nicename("Marker Groups") marker_groups_block; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	Undefined32 __unknown4; 
	Undefined32 __unknown5; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	int32_t __unknown8; 
	s_tag_block_definition<s_mesh_block_definition> nicename("Meshes") meshes_block; 
	s_tag_block_definition<s_compression_info_block_definition> nicename("Compression Info") compression_info_block; 
	s_tag_block_definition<s_unknown_nodey_block_definition> __unknown_nodey_block; 
	s_tag_block_definition<s_unknown_8_block_definition> __unknown_8_block; 
	Undefined32 __unknown9; 
	Undefined32 __unknown10; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	Undefined32 __unknown13; 
	Undefined32 __unknown14; 
	s_tag_block_definition<s_node_map_block_definition> nicename("Node Maps") node_maps_block; 
	Undefined32 __unknown15; 
	Undefined32 __unknown16; 
	Undefined32 __unknown17; 
	Undefined32 __unknown18; 
	Undefined32 __unknown19; 
	Undefined32 __unknown20; 
	Undefined32 __unknown21; 
	Undefined32 __unknown22; 
	Undefined32 __unknown23; 
	s_tag_block_definition<s_unknown_yo_block_definition> __unknown_yo_block; 
	s_tag_block_definition<s_water_mesh_block_definition> nicename("Water Meshes") water_meshes_block; 
	int32_t nicename("[zone] Asset Datum") zone_asset_datum; 
	uint16_t nicename("[easy read] Index") easy_read_index; 
	uint16_t nicename("[easy read] Salt") easy_read_salt; 
	int32_t nicename("Useless Padding") useless_padding; 
	s_tag_block_definition<s_unknown_compression_info_block_definition> __unknown_compression_info_block; 
	s_tag_block_definition<s_unknown_node_block_definition> __unknown_nodes_block; 
	s_tag_block_definition<s_unknown_11_block_definition> __unknown_11_block; 
	Undefined32 __unknown_a; 
	Undefined32 __unknown_a2; 
	Undefined32 __unknown_a3; 
	Undefined32 __unknown_a4; 
	Undefined32 __unknown_a5; 
	Undefined32 __unknown_a6; 
	Undefined32 __unknown_a7; 
	Undefined32 __unknown_a8; 
	Undefined32 __unknown_a9; 
	Undefined32 __unknown_a10; 
	Undefined32 __unknown_a11; 
	Undefined32 __unknown_a12; 
	Undefined32 __unknown_a13; 
	Undefined32 __unknown_a14; 
	Undefined32 __unknown_a15; 
	Undefined32 __unknown_a16; 
	Undefined32 __unknown_b; 
	Undefined32 __unknown_b2; 
	Undefined32 __unknown_b3; 
	Undefined32 __unknown_b4; 
	Undefined32 __unknown_b5; 
	Undefined32 __unknown_b6; 
	Undefined32 __unknown_b7; 
	Undefined32 __unknown_b8; 
	Undefined32 __unknown_b9; 
	Undefined32 __unknown_b10; 
	Undefined32 __unknown_b11; 
	Undefined32 __unknown_b12; 
	Undefined32 __unknown_b13; 
	Undefined32 __unknown_b14; 
	Undefined32 __unknown_b15; 
	Undefined32 __unknown_b16; 
	Undefined32 __unknown_c; 
	Undefined32 __unknown_c2; 
	Undefined32 __unknown_c3; 
	Undefined32 __unknown_c4; 
	Undefined32 __unknown_c5; 
	Undefined32 __unknown_c6; 
	Undefined32 __unknown_c7; 
	Undefined32 __unknown_c8; 
	Undefined32 __unknown_c9; 
	Undefined32 __unknown_c10; 
	Undefined32 __unknown_c11; 
	Undefined32 __unknown_c12; 
	Undefined32 __unknown_c13; 
	Undefined32 __unknown_c14; 
	Undefined32 __unknown_c15; 
	Undefined32 __unknown_c16; 
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
	Undefined32 __unknown48; 
	Undefined32 __unknown49; 
	s_tag_block_definition<s_unknown_12_block_definition> __unknown_12_block; 
	s_tag_block_definition<s_runtime_node_block_definition> nicename("Runtime Nodes") runtime_nodes_block; 

	struct nicename("region") s_region_block_definition
	{
		struct nicename("Permutations") s_permutation_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_permutation_block_definition> nicename("Permutations") permutations_block; 

		struct nicename("permutation") s_permutation_block_definition
		{
			string_id nicename("Name") name; 
			int16_t nicename("Mesh Index") mesh_index; 
			int16_t nicename("Mesh Count") mesh_count; 
			int32_t nicename("Instance Flags 1") instance_flags_1; 
			int32_t nicename("Instance Flags 2") instance_flags_2; 
			int32_t nicename("Instance Flags 3") instance_flags_3; 
			int32_t nicename("Instance Flags 4") instance_flags_4; 
		};
	};

	struct nicename("instance") s_instance_block_definition
	{
		string_id nicename("Name") name; 
		int32_t nicename("Node Index") node_index; 
		float nicename("Default Scale") default_scale; 
		float nicename("Inverse Forward i") inverse_forward_i; 
		float nicename("Inverse Forward j") inverse_forward_j; 
		float nicename("Inverse Forward k") inverse_forward_k; 
		float nicename("Inverse Left i") inverse_left_i; 
		float nicename("Inverse Left j") inverse_left_j; 
		float nicename("Inverse Left k") inverse_left_k; 
		float nicename("Inverse Up i") inverse_up_i; 
		float nicename("Inverse Up j") inverse_up_j; 
		float nicename("Inverse Up k") inverse_up_k; 
		float nicename("Inverse Position x") inverse_position_x; 
		float nicename("Inverse Position y") inverse_position_y; 
		float nicename("Inverse Position z") inverse_position_z; 
	};

	struct nicename("node") s_node_block_definition
	{
		string_id nicename("Name") name; 
		int16_t nicename("Parent Node") parent_node; 
		int16_t nicename("First Child Node") first_child_node; 
		int16_t nicename("Next Sibling Node") next_sibling_node; 
		int16_t nicename("Import Node Index") import_node_index; 
		float nicename("Default Translation x") default_translation_x; 
		float nicename("Default Translation y") default_translation_y; 
		float nicename("Default Translation z") default_translation_z; 
		float nicename("Default Rotation i") default_rotation_i; 
		float nicename("Default Rotation j") default_rotation_j; 
		float nicename("Default Rotation k") default_rotation_k; 
		float nicename("Default Rotation w") default_rotation_w; 
		float nicename("Default Scale") default_scale; 
		float nicename("Inverse Forward i") inverse_forward_i; 
		float nicename("Inverse Forward j") inverse_forward_j; 
		float nicename("Inverse Forward k") inverse_forward_k; 
		float nicename("Inverse Left i") inverse_left_i; 
		float nicename("Inverse Left j") inverse_left_j; 
		float nicename("Inverse Left k") inverse_left_k; 
		float nicename("Inverse Up i") inverse_up_i; 
		float nicename("Inverse Up j") inverse_up_j; 
		float nicename("Inverse Up k") inverse_up_k; 
		float nicename("Inverse Position x") inverse_position_x; 
		float nicename("Inverse Position y") inverse_position_y; 
		float nicename("Inverse Position z") inverse_position_z; 
		float nicename("Distance from Parent") distance_from_parent; 
	};

	struct nicename("marker_group") s_marker_group_block_definition
	{
		struct nicename("Markers") s_marker_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_marker_block_definition> nicename("Markers") markers_block; 

		struct nicename("marker") s_marker_block_definition
		{
			int8_t nicename("Region Index") region_index; 
			int8_t nicename("Permutation Index") permutation_index; 
			int8_t nicename("Node Index") node_index; 
			int8_t __unknown; 
			float nicename("Translation x") translation_x; 
			float nicename("Translation y") translation_y; 
			float nicename("Translation z") translation_z; 
			float nicename("Rotation i") rotation_i; 
			float nicename("Rotation j") rotation_j; 
			float nicename("Rotation k") rotation_k; 
			float nicename("Rotation w") rotation_w; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};
	};

	struct nicename("material") s_material_block_definition
	{
		TagReference nicename("Shader") shader_reference; 
		int32_t __unknown; 
		float __unknown2; 
		Undefined32 __unknown3; 
		int8_t __unknown4; 
		int8_t __unknown5; 
		int8_t __unknown6; 
		int8_t __unknown7; 
		float __unknown8; 
		float __unknown9; 
		int8_t __unknown10; 
		int8_t nicename("Breakable Surface Index") breakable_surface_index; 
		int8_t __unknown11; 
		int8_t __unknown12; 
	};

	struct nicename("mesh") s_mesh_block_definition
	{
		struct nicename("Parts") s_part_block_definition;
		struct nicename("Subparts") s_subpart_block_definition;
		struct nicename("Instanced Geometry Indices") s_instanced_geometry_index_block_definition;
		struct s_unknown_water_block_definition;

		s_tag_block_definition<s_part_block_definition> nicename("Parts") parts_block; 
		s_tag_block_definition<s_subpart_block_definition> nicename("Subparts") subparts_block; 
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
		uint16_t nicename("Flags") flags; 
		int8_t nicename("Rigid Node") rigid_node; 
		int8_t nicename("Vertex Type") vertex_type; 
		int8_t nicename("PRT Type") prt_type; 
		int8_t __unknown; 
		int8_t nicename("Index Buffer Type") index_buffer_type; 
		int8_t __unknown2; 
		s_tag_block_definition<s_instanced_geometry_index_block_definition> nicename("Instanced Geometry Indices") instanced_geometry_indices_block; 
		s_tag_block_definition<s_unknown_water_block_definition> __unknown_water_block; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 

		struct nicename("part") s_part_block_definition
		{
			int16_t nicename("Material Index") material_index; 
			int16_t nicename("'Unknown Nodey' Index") _unknown_nodey__index; 
			int32_t nicename("Index Buffer Start") index_buffer_start; 
			int32_t nicename("Index Buffer Count") index_buffer_count; 
			int16_t nicename("Subpart Start") subpart_start; 
			int16_t nicename("Subpart Count") subpart_count; 
			int8_t __unknown_enum; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int16_t nicename("Vertex Count") vertex_count; 
			int16_t __unknown4; 
		};

		struct nicename("subpart") s_subpart_block_definition
		{
			int32_t nicename("Index Buffer Start") index_buffer_start; 
			int32_t nicename("Index Buffer Count") index_buffer_count; 
			int16_t nicename("Part Index") part_index; 
			int16_t nicename("Vertex Count") vertex_count; 
			int32_t __unknown; 
		};

		struct nicename("instanced_geometry_index") s_instanced_geometry_index_block_definition
		{
			struct nicename("Instanced Geometry Mesh Contents") s_instanced_geometry_mesh_content_block_definition;

			int16_t nicename("Instanced Geometry Mesh Index 1") instanced_geometry_mesh_index_1; 
			int16_t nicename("Instanced Geometry Mesh Index 2") instanced_geometry_mesh_index_2; 
			s_tag_block_definition<s_instanced_geometry_mesh_content_block_definition> nicename("Instanced Geometry Mesh Contents") instanced_geometry_mesh_contents_block; 

			struct nicename("instanced_geometry_mesh_content") s_instanced_geometry_mesh_content_block_definition
			{
				int16_t nicename("Instanced Geometry Index") instanced_geometry_index; 
			};
		};

		struct s_unknown_water_block_definition
		{
			int16_t __unknown; 
		};
	};

	struct nicename("compression_info") s_compression_info_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
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
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
	};

	struct s_unknown_nodey_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		int8_t nicename("Node Index") node_index; 
		int8_t nicename("Node Index") node_index2; 
		int8_t nicename("Node Index") node_index3; 
		int8_t nicename("Node Index") node_index4; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
	};

	struct s_unknown_8_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
		DataReference __unknown3_data_reference; 
	};

	struct nicename("node_map") s_node_map_block_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

		struct s_unknown_block_definition
		{
			uint8_t nicename("Node Index") node_index; 
		};
	};

	struct s_unknown_yo_block_definition
	{
		int16_t __unknown_index; 
	};

	struct nicename("water_mesh") s_water_mesh_block_definition
	{
		int16_t nicename("Mesh Index") mesh_index; 
		int16_t __unknown; 
		float nicename("X Min") x_min; 
		float nicename("X Max") x_max; 
		float nicename("Y Min") y_min; 
		float nicename("Y Max") y_max; 
		float nicename("Z Min") z_min; 
		float nicename("Z Max") z_max; 
	};

	struct s_unknown_compression_info_block_definition
	{
		uint32_t nicename("Polyart Asset Address") polyart_asset_address; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
	};

	struct s_unknown_node_block_definition
	{
		int16_t __unknown; 
	};

	struct s_unknown_11_block_definition
	{
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
	};

	struct s_unknown_12_block_definition
	{
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 
		Undefined32 __unknown22; 
		Undefined32 __unknown23; 
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
		Undefined32 __unknown48; 
		Undefined32 __unknown49; 
		Undefined32 __unknown50; 
		Undefined32 __unknown51; 
		Undefined32 __unknown52; 
		Undefined32 __unknown53; 
		Undefined32 __unknown54; 
		Undefined32 __unknown55; 
		Undefined32 __unknown56; 
		Undefined32 __unknown57; 
		Undefined32 __unknown58; 
		Undefined32 __unknown59; 
		Undefined32 __unknown60; 
		Undefined32 __unknown61; 
		Undefined32 __unknown62; 
		Undefined32 __unknown63; 
		Undefined32 __unknown64; 
		Undefined32 __unknown65; 
		Undefined32 __unknown66; 
		Undefined32 __unknown67; 
		Undefined32 __unknown68; 
		Undefined32 __unknown69; 
		Undefined32 __unknown70; 
		Undefined32 __unknown71; 
		Undefined32 __unknown72; 
		Undefined32 __unknown73; 
		Undefined32 __unknown74; 
		Undefined32 __unknown75; 
		Undefined32 __unknown76; 
		Undefined32 __unknown77; 
		Undefined32 __unknown78; 
		Undefined32 __unknown79; 
		Undefined32 __unknown80; 
		Undefined32 __unknown81; 
		Undefined32 __unknown82; 
		Undefined32 __unknown83; 
		Undefined32 __unknown84; 
	};

	struct nicename("runtime_node") s_runtime_node_block_definition
	{
		float nicename("Default Rotation i") default_rotation_i; 
		float nicename("Default Rotation j") default_rotation_j; 
		float nicename("Default Rotation k") default_rotation_k; 
		float nicename("Default Rotation w") default_rotation_w; 
		float nicename("Default Translation x") default_translation_x; 
		float nicename("Default Translation y") default_translation_y; 
		float nicename("Default Translation z") default_translation_z; 
		float nicename("Default Scale") default_scale; 
	};
};
