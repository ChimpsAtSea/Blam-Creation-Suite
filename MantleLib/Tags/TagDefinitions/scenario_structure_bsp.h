#pragma once

struct nicename("Scenario Structure Bsp") group('sbsp') s_scenario_structure_bsp_definition
{
	struct nicename("Structure Seams") s_structure_seam_block_definition;
	struct nicename("Collision Materials") s_collision_material_block_definition;
	struct s_unknown_2_block_definition;
	struct s_unknown_3_block_definition;
	struct nicename("Cluster Portals") s_cluster_portal_block_definition;
	struct nicename("Detail Objects") s_detail_object_block_definition;
	struct nicename("Clusters") s_cluster_block_definition;
	struct nicename("Materials") s_material_block_definition;
	struct nicename("Sky Owner Cluster") s_sky_owner_cluster_block_definition;
	struct nicename("Background Sound Environment Palette") s_background_sound_environment_palette_block_definition;
	struct nicename("Markers") s_marker_block_definition;
	struct s_unknown_11_block_definition;
	struct nicename("Runtime Decals") s_runtime_decal_block_definition;
	struct nicename("Environment Object Palette") s_environment_object_palette_block_definition;
	struct nicename("Environment Objects") s_environment_object_block_definition;
	struct nicename("Instanced Geometry Groups") s_instanced_geometry_group_block_definition;
	struct nicename("Instanced Geometry Sub Groups") s_instanced_geometry_sub_group_block_definition;
	struct nicename("Instanced Geometry Instances") s_instanced_geometry_instance_block_definition;
	struct nicename("Decorators") s_decorator_block_definition;
	struct nicename("Meshes") s_mesh_block_definition;
	struct nicename("Compression Info") s_compression_info_block_definition;
	struct s_unknown_nodey_block_definition;
	struct s_unknown_30_block_definition;
	struct nicename("Node Maps") s_node_map_block_definition;
	struct s_unknown_yo_block_definition;
	struct nicename("Water Meshes") s_water_mesh_block_definition;
	struct s_unknown_compression_info_block_definition;
	struct nicename("Decals") s_decal_block_definition;
	struct nicename("Decal Properties") s_decal_property_block_definition;
	struct nicename("Meshes") s_mesh2_block_definition;
	struct nicename("Compression Info") s_compression_info2_block_definition;
	struct s_unknown_nodey2_block_definition;
	struct s_unknown_30_2_block_definition;
	struct nicename("Node Maps") s_node_map2_block_definition;
	struct s_unknown_yo2_block_definition;
	struct nicename("Water Meshes") s_water_mesh2_block_definition;
	struct s_unknown_compression_info2_block_definition;
	struct s_unknown_sound_clusters_a_block_definition;
	struct nicename("Transparent Planes") s_transparent_plane_block_definition;
	struct nicename("Collision MOPP Codes") s_collision_mopp_code_block_definition;
	struct nicename("Breakable Surface MOPP Codes") s_breakable_surface_mopp_code_block_definition;
	struct nicename("Breakable Surface Key Table") s_breakable_surface_key_table_block_definition;
	struct nicename("Meshes") s_mesh3_block_definition;
	struct nicename("Compression Info") s_compression_info3_block_definition;
	struct s_unknown_nodey3_block_definition;
	struct s_unknown_30_3_block_definition;
	struct nicename("Node Maps") s_node_map3_block_definition;
	struct s_unknown_yo3_block_definition;
	struct nicename("Water Meshes") s_water_mesh3_block_definition;
	struct s_unknown_compression_info3_block_definition;

	Undefined32 __unknown; 
	float __unknown2; 
	Undefined32 __unknown3; 
	float __unknown4; 
	int32_t __unknown5; 
	int32_t __unknown6; 
	Undefined32 __unknown7; 
	Undefined32 __unknown8; 
	Undefined32 __unknown9; 
	Undefined32 __unknown10; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	int32_t nicename("BSP Checksum") bsp_checksum; 
	int32_t __unknown13; 
	int16_t __unknown14; 
	int16_t __unknown15; 
	int16_t __unknown16; 
	int16_t __unknown17; 
	s_tag_block_definition<s_structure_seam_block_definition> nicename("Structure Seams") structure_seams_block; 
	Undefined32 __unknown18; 
	Undefined32 __unknown19; 
	Undefined32 __unknown20; 
	s_tag_block_definition<s_collision_material_block_definition> nicename("Collision Materials") collision_materials_block; 
	s_tag_block_definition<s_unknown_2_block_definition> __unknown_2_block; 
	s_tag_block_definition<s_unknown_3_block_definition> __unknown_3_block; 
	Undefined32 __unknown21; 
	Undefined32 __unknown22; 
	Undefined32 __unknown23; 
	Undefined32 __unknown24; 
	Undefined32 __unknown25; 
	Undefined32 __unknown26; 
	Undefined32 __unknown27; 
	Undefined32 __unknown28; 
	Undefined32 __unknown29; 
	int32_t __unknown30; 
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
	float nicename("World Bounds X min") world_bounds_x_min; 
	float nicename("World Bounds X max") world_bounds_x_max; 
	float nicename("World Bounds Y min") world_bounds_y_min; 
	float nicename("World Bounds Y max") world_bounds_y_max; 
	float nicename("World Bounds Z min") world_bounds_z_min; 
	float nicename("World Bounds Z max") world_bounds_z_max; 
	Undefined32 __unknown50; 
	Undefined32 __unknown51; 
	Undefined32 __unknown52; 
	Undefined32 __unknown53; 
	Undefined32 __unknown54; 
	Undefined32 __unknown55; 
	s_tag_block_definition<s_cluster_portal_block_definition> nicename("Cluster Portals") cluster_portals_block; 
	s_tag_block_definition<s_detail_object_block_definition> nicename("Detail Objects") detail_objects_block; 
	s_tag_block_definition<s_cluster_block_definition> nicename("Clusters") clusters_block; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	s_tag_block_definition<s_sky_owner_cluster_block_definition> nicename("Sky Owner Cluster") sky_owner_cluster_block; 
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
	s_tag_block_definition<s_background_sound_environment_palette_block_definition> nicename("Background Sound Environment Palette") background_sound_environment_palette_block; 
	DataReference __unknown71_data_reference; 
	s_tag_block_definition<s_marker_block_definition> nicename("Markers") markers_block; 
	Undefined32 __unknown72; 
	Undefined32 __unknown73; 
	Undefined32 __unknown74; 
	s_tag_block_definition<s_unknown_11_block_definition> __unknown_11_block; 
	s_tag_block_definition<s_runtime_decal_block_definition> nicename("Runtime Decals") runtime_decals_block; 
	s_tag_block_definition<s_environment_object_palette_block_definition> nicename("Environment Object Palette") environment_object_palette_block; 
	s_tag_block_definition<s_environment_object_block_definition> nicename("Environment Objects") environment_objects_block; 
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
	Undefined32 __unknown85; 
	Undefined32 __unknown86; 
	Undefined32 __unknown87; 
	Undefined32 __unknown88; 
	Undefined32 __unknown89; 
	Undefined32 __unknown90; 
	s_tag_block_definition<s_instanced_geometry_group_block_definition> nicename("Instanced Geometry Groups") instanced_geometry_groups_block; 
	s_tag_block_definition<s_instanced_geometry_sub_group_block_definition> nicename("Instanced Geometry Sub Groups") instanced_geometry_sub_groups_block; 
	Undefined32 __unknown91; 
	Undefined32 __unknown92; 
	Undefined32 __unknown93; 
	s_tag_block_definition<s_instanced_geometry_instance_block_definition> nicename("Instanced Geometry Instances") instanced_geometry_instances_block; 
	TagReference nicename("Instance Geometry Impostors") instance_geometry_impostors_reference; 
	s_tag_block_definition<s_decorator_block_definition> nicename("Decorators") decorators_block; 
	int32_t __unknown94; 
	s_tag_block_definition<s_mesh_block_definition> nicename("Meshes") meshes_block; 
	s_tag_block_definition<s_compression_info_block_definition> nicename("Compression Info") compression_info_block; 
	s_tag_block_definition<s_unknown_nodey_block_definition> __unknown_nodey_block; 
	s_tag_block_definition<s_unknown_30_block_definition> __unknown_30_block; 
	Undefined32 __unknown95; 
	Undefined32 __unknown96; 
	Undefined32 __unknown97; 
	Undefined32 __unknown98; 
	Undefined32 __unknown99; 
	Undefined32 __unknown100; 
	s_tag_block_definition<s_node_map_block_definition> nicename("Node Maps") node_maps_block; 
	Undefined32 __unknown101; 
	Undefined32 __unknown102; 
	Undefined32 __unknown103; 
	Undefined32 __unknown104; 
	Undefined32 __unknown105; 
	Undefined32 __unknown106; 
	Undefined32 __unknown107; 
	Undefined32 __unknown108; 
	Undefined32 __unknown109; 
	s_tag_block_definition<s_unknown_yo_block_definition> __unknown_yo_block; 
	s_tag_block_definition<s_water_mesh_block_definition> nicename("Water Meshes") water_meshes_block; 
	uint32_t nicename("[zone] Asset Datum 1") zone_asset_datum_1; 
	uint16_t nicename("[easy read] Index 1") easy_read_index_1; 
	uint16_t nicename("[easy read] Salt 1") easy_read_salt_1; 
	int32_t nicename("Useless Padding") useless_padding; 
	s_tag_block_definition<s_unknown_compression_info_block_definition> __unknown_compression_info_block; 
	s_tag_block_definition<s_decal_block_definition> nicename("Decals") decals_block; 
	s_tag_block_definition<s_decal_property_block_definition> nicename("Decal Properties") decal_properties_block; 
	int32_t __unknown110; 
	s_tag_block_definition<s_mesh2_block_definition> nicename("Meshes") meshes2_block; 
	s_tag_block_definition<s_compression_info2_block_definition> nicename("Compression Info") compression_info2_block; 
	s_tag_block_definition<s_unknown_nodey2_block_definition> __unknown_nodey2_block; 
	s_tag_block_definition<s_unknown_30_2_block_definition> __unknown_30_2_block; 
	Undefined32 __unknown111; 
	Undefined32 __unknown112; 
	Undefined32 __unknown113; 
	Undefined32 __unknown114; 
	Undefined32 __unknown115; 
	Undefined32 __unknown116; 
	s_tag_block_definition<s_node_map2_block_definition> nicename("Node Maps") node_maps2_block; 
	Undefined32 __unknown117; 
	Undefined32 __unknown118; 
	Undefined32 __unknown119; 
	Undefined32 __unknown120; 
	Undefined32 __unknown121; 
	Undefined32 __unknown122; 
	Undefined32 __unknown123; 
	Undefined32 __unknown124; 
	Undefined32 __unknown125; 
	s_tag_block_definition<s_unknown_yo2_block_definition> __unknown_yo2_block; 
	s_tag_block_definition<s_water_mesh2_block_definition> nicename("Water Meshes") water_meshes2_block; 
	uint32_t nicename("[zone] Asset Datum 2") zone_asset_datum_2; 
	uint16_t nicename("[easy read] Index 2") easy_read_index_2; 
	uint16_t nicename("[easy read] Salt 2") easy_read_salt_2; 
	int32_t nicename("Useless Padding") useless_padding2; 
	s_tag_block_definition<s_unknown_compression_info2_block_definition> __unknown_compression_info2_block; 
	s_tag_block_definition<s_unknown_sound_clusters_a_block_definition> __unknown_sound_clusters_a_block; 
	s_tag_block_definition<s_transparent_plane_block_definition> nicename("Transparent Planes") transparent_planes_block; 
	Undefined32 __unknown126; 
	Undefined32 __unknown127; 
	Undefined32 __unknown128; 
	s_tag_block_definition<s_collision_mopp_code_block_definition> nicename("Collision MOPP Codes") collision_mopp_codes_block; 
	Undefined32 __unknown129; 
	float nicename("Collision Bounds Min X") collision_bounds_min_x; 
	float nicename("Collision Bounds Min Y") collision_bounds_min_y; 
	float nicename("Collision Bounds Min Z") collision_bounds_min_z; 
	float nicename("Collision Bounds Max X") collision_bounds_max_x; 
	float nicename("Collision Bounds Max Y") collision_bounds_max_y; 
	float nicename("Collision Bounds Max Z") collision_bounds_max_z; 
	s_tag_block_definition<s_breakable_surface_mopp_code_block_definition> nicename("Breakable Surface MOPP Codes") breakable_surface_mopp_codes_block; 
	s_tag_block_definition<s_breakable_surface_key_table_block_definition> nicename("Breakable Surface Key Table") breakable_surface_key_table_block; 
	Undefined32 __unknown130; 
	Undefined32 __unknown131; 
	Undefined32 __unknown132; 
	int32_t __unknown133; 
	s_tag_block_definition<s_mesh3_block_definition> nicename("Meshes") meshes3_block; 
	s_tag_block_definition<s_compression_info3_block_definition> nicename("Compression Info") compression_info3_block; 
	s_tag_block_definition<s_unknown_nodey3_block_definition> __unknown_nodey3_block; 
	s_tag_block_definition<s_unknown_30_3_block_definition> __unknown_30_3_block; 
	Undefined32 __unknown134; 
	Undefined32 __unknown135; 
	Undefined32 __unknown136; 
	Undefined32 __unknown137; 
	Undefined32 __unknown138; 
	Undefined32 __unknown139; 
	s_tag_block_definition<s_node_map3_block_definition> nicename("Node Maps") node_maps3_block; 
	Undefined32 __unknown140; 
	Undefined32 __unknown141; 
	Undefined32 __unknown142; 
	Undefined32 __unknown143; 
	Undefined32 __unknown144; 
	Undefined32 __unknown145; 
	Undefined32 __unknown146; 
	Undefined32 __unknown147; 
	Undefined32 __unknown148; 
	s_tag_block_definition<s_unknown_yo3_block_definition> __unknown_yo3_block; 
	s_tag_block_definition<s_water_mesh3_block_definition> nicename("Water Meshes") water_meshes3_block; 
	uint32_t nicename("[zone] Asset Datum 3") zone_asset_datum_3; 
	uint16_t nicename("[easy read] Index 3") easy_read_index_3; 
	uint16_t nicename("[easy read] Salt 3") easy_read_salt_3; 
	int32_t nicename("Useless Padding") useless_padding3; 
	s_tag_block_definition<s_unknown_compression_info3_block_definition> __unknown_compression_info3_block; 
	Undefined32 __unknown149; 
	Undefined32 __unknown150; 
	Undefined32 __unknown151; 
	Undefined32 __unknown152; 
	Undefined32 __unknown153; 
	Undefined32 __unknown154; 
	Undefined32 __unknown155; 
	Undefined32 __unknown156; 
	Undefined32 __unknown157; 
	uint32_t nicename("[zone] Asset Datum 4") zone_asset_datum_4; 
	uint16_t nicename("[easy read] Index 4") easy_read_index_4; 
	uint16_t nicename("[easy read] Salt 4") easy_read_salt_4; 
	int32_t nicename("Useless Padding") useless_padding4; 
	uint32_t nicename("[zone] Asset Datum 5") zone_asset_datum_5; 
	uint16_t nicename("[easy read] Index 5") easy_read_index_5; 
	uint16_t nicename("[easy read] Salt 5") easy_read_salt_5; 
	int32_t nicename("Useless Padding") useless_padding5; 
	int32_t __unknown158; 
	Undefined32 __unknown159; 

	struct nicename("structure_seam") s_structure_seam_block_definition
	{
		struct s_unknown_block_definition;
		struct nicename("Seam Clusters") s_seam_cluster_block_definition;

		uint32_t __unknown; 
		uint32_t __unknown2; 
		uint32_t __unknown3; 
		uint32_t __unknown4; 
		s_tag_block_definition<s_unknown_block_definition> __unknown5_block; 
		s_tag_block_definition<s_seam_cluster_block_definition> nicename("Seam Clusters") seam_clusters_block; 

		struct s_unknown_block_definition
		{
			int32_t __unknown; 
		};

		struct nicename("seam_cluster") s_seam_cluster_block_definition
		{
			int32_t nicename("Cluster Index") cluster_index; 
			float nicename("Centroid X") centroid_x; 
			float nicename("Centroid Y") centroid_y; 
			float nicename("Centroid Z") centroid_z; 
		};
	};

	struct nicename("collision_material") s_collision_material_block_definition
	{
		TagReference nicename("Shader") shader_reference; 
		int16_t nicename("Global Material Index") global_material_index; 
		int16_t nicename("Conveyor Surface Index") conveyor_surface_index; 
		int16_t nicename("Seam Index") seam_index; 
		int16_t __unknown; 
	};

	struct s_unknown_2_block_definition
	{
		uint8_t __unknown; 
	};

	struct s_unknown_3_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
	};

	struct nicename("cluster_portal") s_cluster_portal_block_definition
	{
		struct nicename("Vertices") s_vertex_block_definition;

		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		int16_t nicename("Back Cluster") back_cluster; 
		int16_t nicename("Front Cluster") front_cluster; 
		int32_t nicename("Plane Index") plane_index; 
		float nicename("Centroid X") centroid_x; 
		float nicename("Centroid Y") centroid_y; 
		float nicename("Centroid Z") centroid_z; 
		float nicename("Bounding Radius") bounding_radius; 
		int32_t nicename("Flags") flags; 
		s_tag_block_definition<s_vertex_block_definition> nicename("Vertices") vertices_block; 

		struct nicename("vertex") s_vertex_block_definition
		{
			float nicename("X") x; 
			float nicename("Y") y; 
			float nicename("Z") z; 
		};
	};

	struct nicename("detail_object") s_detail_object_block_definition
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
	};

	struct nicename("cluster") s_cluster_block_definition
	{
		struct nicename("Portals") s_portal_block_definition;
		struct nicename("Seams") s_seam_block_definition;
		struct nicename("Decorator Grids") s_decorator_grid_block_definition;
		struct s_unknown_10_block_definition;
		struct s_unknown_11_block_definition;

		float nicename("Bounds X min") bounds_x_min; 
		float nicename("Bounds X max") bounds_x_max; 
		float nicename("Bounds Y min") bounds_y_min; 
		float nicename("Bounds Y max") bounds_y_max; 
		float nicename("Bounds Z min") bounds_z_min; 
		float nicename("Bounds Z max") bounds_z_max; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Runtime Decal Start Index") runtime_decal_start_index; 
		int16_t nicename("Runtime Decal Entry Count") runtime_decal_entry_count; 
		int16_t __unknown7; 
		int16_t __unknown8; 
		int16_t __unknown9; 
		int16_t __unknown10; 
		int16_t __unknown11; 
		int16_t __unknown12; 
		Undefined32 __unknown13; 
		s_tag_block_definition<s_portal_block_definition> nicename("Portals") portals_block; 
		int16_t nicename("Mesh Index") mesh_index; 
		int16_t __unknown14; 
		s_tag_block_definition<s_seam_block_definition> nicename("Seams") seams_block; 
		s_tag_block_definition<s_decorator_grid_block_definition> nicename("Decorator Grids") decorator_grids_block; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		s_tag_block_definition<s_unknown_10_block_definition> __unknown_10_block; 
		s_tag_block_definition<s_unknown_11_block_definition> __unknown_11_block; 

		struct nicename("portal") s_portal_block_definition
		{
			int16_t nicename("Portal Index") portal_index; 
		};

		struct nicename("seam") s_seam_block_definition
		{
			int8_t nicename("Seam Index") seam_index; 
		};

		struct nicename("decorator_grid") s_decorator_grid_block_definition
		{
			struct s_unknown_block_definition;

			int16_t nicename("Amount") amount; 
			int8_t nicename("Decorator Index") decorator_index; 
			int8_t nicename("Decorator Index - Scattering") decorator_index___scattering; 
			int32_t __unknown; 
			float nicename("Position X") position_x; 
			float nicename("Position Y") position_y; 
			float nicename("Position Z") position_z; 
			float nicename("Radius") radius; 
			float nicename("Grid Size X") grid_size_x; 
			float nicename("Grid Size Y") grid_size_y; 
			float nicename("Grid Size Z") grid_size_z; 
			float nicename("Bounding Sphere X") bounding_sphere_x; 
			float nicename("Bounding Sphere Y") bounding_sphere_y; 
			float nicename("Bounding Sphere Z") bounding_sphere_z; 
			s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 

			struct s_unknown_block_definition
			{
				Undefined32 __unknown; 
				Undefined32 __unknown2; 
			};
		};

		struct s_unknown_10_block_definition
		{
			Undefined32 __unknown; 
		};

		struct s_unknown_11_block_definition
		{
			struct s_unknown_12_block_definition;

			int16_t __unknown; 
			int16_t __unknown2; 
			s_tag_block_definition<s_unknown_12_block_definition> __unknown_12_block; 

			struct s_unknown_12_block_definition
			{
				float __unknown; 
				float __unknown2; 
				float __unknown3; 
				Undefined32 __unknown4; 
			};
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

	struct nicename("sky_owner_cluster") s_sky_owner_cluster_block_definition
	{
		int16_t nicename("Cluster Owner") cluster_owner; 
	};

	struct nicename("background_sound_environment_palette") s_background_sound_environment_palette_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Sound Environment") sound_environment_reference; 
		int32_t __unknown; 
		float nicename("Cutoff Distance") cutoff_distance; 
		float nicename("Interpolation Speed") interpolation_speed; 
		TagReference nicename("Background Sound") background_sound_reference; 
		TagReference nicename("Inside Cluster Sound") inside_cluster_sound_reference; 
		TagReference nicename("Transition In") transition_in_reference; 
		TagReference nicename("Transition Out") transition_out_reference; 
		float nicename("Cutoff Distance") cutoff_distance2; 
		int32_t nicename("Scale Flags") scale_flags; 
		float nicename("Interior Scale") interior_scale; 
		float nicename("Portal Scale") portal_scale; 
		float nicename("Exterior Scale") exterior_scale; 
		float nicename("Interpolation Speed") interpolation_speed2; 
	};

	struct nicename("marker") s_marker_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
		char nicename("Name") name[32];
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Rotation w") rotation_w; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
	};

	struct s_unknown_11_block_definition
	{
		int16_t __unknown; 
	};

	struct nicename("runtime_decal") s_runtime_decal_block_definition
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

	struct nicename("environment_object_palette") s_environment_object_palette_block_definition
	{
		TagReference nicename("Definition") definition_reference; 
		TagReference nicename("Model") model_reference; 
		int32_t nicename("Object Type") object_type; 
	};

	struct nicename("environment_object") s_environment_object_block_definition
	{
		char nicename("Name String") name_string[32];
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Rotation w") rotation_w; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Scale") scale; 
		int16_t nicename("Palette Index") palette_index; 
		int16_t __unknown; 
		int32_t nicename("Unique ID") unique_id; 
		char nicename("Scenario Object Name") scenario_object_name[4];
		string_id nicename("Name") name; 
		int32_t __unknown2; 
	};

	struct nicename("instanced_geometry_group") s_instanced_geometry_group_block_definition
	{
		struct nicename("Members") s_member_block_definition;

		int32_t __unknown; 
		s_tag_block_definition<s_member_block_definition> nicename("Members") members_block; 

		struct nicename("member") s_member_block_definition
		{
			int16_t nicename("Sub Group Index") sub_group_index; 
		};
	};

	struct nicename("instanced_geometry_sub_group") s_instanced_geometry_sub_group_block_definition
	{
		struct nicename("Members") s_member_block_definition;

		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		float __unknown; 
		int16_t __unknown2; 
		int16_t __unknown3; 
		float __unknown4; 
		float __unknown5; 
		s_tag_block_definition<s_member_block_definition> nicename("Members") members_block; 

		struct nicename("member") s_member_block_definition
		{
			int16_t nicename("Name Index") name_index; 
		};
	};

	struct nicename("instanced_geometry_instance") s_instanced_geometry_instance_block_definition
	{
		string_id nicename("Name") name; 
	};

	struct nicename("decorator") s_decorator_block_definition
	{
		TagReference nicename("Decorator") decorator_reference; 
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

	struct s_unknown_30_block_definition
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

	struct nicename("decal") s_decal_block_definition
	{
		unsigned int nicename("Decal") decal; 
		int16_t __unknown; 
		int16_t __unknown2; 
		int16_t __unknown3; 
		int16_t __unknown4; 
		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		int16_t nicename("Decal Property Index") decal_property_index; 
		int16_t __unknown5; 
	};

	struct nicename("decal_property") s_decal_property_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
		int16_t __unknown3; 
		int16_t __unknown4; 
		Undefined32 __unknown5; 
		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Tile X") tile_x; 
		float nicename("Tile Y") tile_y; 
	};

	struct nicename("mesh2") s_mesh2_block_definition
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

	struct nicename("compression_info2") s_compression_info2_block_definition
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

	struct s_unknown_nodey2_block_definition
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

	struct s_unknown_30_2_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
		DataReference __unknown3_data_reference; 
	};

	struct nicename("node_map2") s_node_map2_block_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

		struct s_unknown_block_definition
		{
			uint8_t nicename("Node Index") node_index; 
		};
	};

	struct s_unknown_yo2_block_definition
	{
		int16_t __unknown_index; 
	};

	struct nicename("water_mesh2") s_water_mesh2_block_definition
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

	struct s_unknown_compression_info2_block_definition
	{
		uint32_t nicename("Polyart Asset Address") polyart_asset_address; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
	};

	struct s_unknown_sound_clusters_a_block_definition
	{
		struct nicename("Portal Designators") s_portal_designator_block_definition;
		struct nicename("Interior Cluster Indices") s_interior_cluster_index_block_definition;

		int16_t nicename("Background Sound Environment Index") background_sound_environment_index; 
		int16_t __unknown; 
		s_tag_block_definition<s_portal_designator_block_definition> nicename("Portal Designators") portal_designators_block; 
		s_tag_block_definition<s_interior_cluster_index_block_definition> nicename("Interior Cluster Indices") interior_cluster_indices_block; 

		struct nicename("portal_designator") s_portal_designator_block_definition
		{
			int16_t nicename("Portal Designator") portal_designator; 
		};

		struct nicename("interior_cluster_index") s_interior_cluster_index_block_definition
		{
			int16_t nicename("Interior Cluster Index") interior_cluster_index; 
		};
	};

	struct nicename("transparent_plane") s_transparent_plane_block_definition
	{
		int16_t nicename("Mesh Index") mesh_index; 
		int16_t nicename("Part Index") part_index; 
		float nicename("Plane i") plane_i; 
		float nicename("Plane j") plane_j; 
		float nicename("Plane k") plane_k; 
		float nicename("Plane d") plane_d; 
	};

	struct nicename("collision_mopp_code") s_collision_mopp_code_block_definition
	{
		struct nicename("Data") s_datum_block_definition;

		int32_t __unknown; 
		Undefined32 __unknown2; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		float nicename("Offset x") offset_x; 
		float nicename("Offset y") offset_y; 
		float nicename("Offset z") offset_z; 
		float nicename("Offset Scale") offset_scale; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		int32_t nicename("Data Size") data_size; 
		uint32_t nicename("Data Capacity") data_capacity; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		s_tag_block_definition<s_datum_block_definition> nicename("Data") data_block; 
		Undefined32 __unknown13; 

		struct nicename("datum") s_datum_block_definition
		{
			uint8_t nicename("Data Byte") data_byte; 
		};
	};

	struct nicename("breakable_surface_mopp_code") s_breakable_surface_mopp_code_block_definition
	{
		struct nicename("Data") s_datum_block_definition;

		int32_t __unknown; 
		Undefined32 __unknown2; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		float nicename("Offset x") offset_x; 
		float nicename("Offset y") offset_y; 
		float nicename("Offset z") offset_z; 
		float nicename("Offset Scale") offset_scale; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		int32_t nicename("Data Size") data_size; 
		uint32_t nicename("Data Capacity") data_capacity; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		s_tag_block_definition<s_datum_block_definition> nicename("Data") data_block; 
		Undefined32 __unknown13; 

		struct nicename("datum") s_datum_block_definition
		{
			uint8_t nicename("Data Byte") data_byte; 
		};
	};

	struct nicename("breakable_surface_key_table") s_breakable_surface_key_table_block_definition
	{
		int16_t nicename("Instanced Geometry Index") instanced_geometry_index; 
		int8_t nicename("Breakable Surface Index") breakable_surface_index; 
		uint8_t nicename("Breakable Surface Sub-Index") breakable_surface_sub_index; 
		int32_t nicename("Seed Surface Index") seed_surface_index; 
		float nicename("x0") x0; 
		float nicename("x1") x1; 
		float nicename("y0") y0; 
		float nicename("y1") y1; 
		float nicename("z0") z0; 
		float nicename("z1") z1; 
	};

	struct nicename("mesh3") s_mesh3_block_definition
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

	struct nicename("compression_info3") s_compression_info3_block_definition
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

	struct s_unknown_nodey3_block_definition
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

	struct s_unknown_30_3_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
		DataReference __unknown3_data_reference; 
	};

	struct nicename("node_map3") s_node_map3_block_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

		struct s_unknown_block_definition
		{
			uint8_t nicename("Node Index") node_index; 
		};
	};

	struct s_unknown_yo3_block_definition
	{
		int16_t __unknown_index; 
	};

	struct nicename("water_mesh3") s_water_mesh3_block_definition
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

	struct s_unknown_compression_info3_block_definition
	{
		uint32_t nicename("Polyart Asset Address") polyart_asset_address; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
	};
};
