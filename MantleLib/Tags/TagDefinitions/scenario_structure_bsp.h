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

	Unknown32 __unknown; 
	float __unknown2; 
	Unknown32 __unknown3; 
	float __unknown4; 
	signed int __unknown5; 
	signed int __unknown6; 
	Unknown32 __unknown7; 
	Unknown32 __unknown8; 
	Unknown32 __unknown9; 
	Unknown32 __unknown10; 
	Unknown32 __unknown11; 
	Unknown32 __unknown12; 
	signed int nicename("BSP Checksum") bsp_checksum; 
	signed int __unknown13; 
	signed short __unknown14; 
	signed short __unknown15; 
	signed short __unknown16; 
	signed short __unknown17; 
	s_tag_block_definition<s_structure_seam_block_definition> nicename("Structure Seams") structure_seams_block; 
	Unknown32 __unknown18; 
	Unknown32 __unknown19; 
	Unknown32 __unknown20; 
	s_tag_block_definition<s_collision_material_block_definition> nicename("Collision Materials") collision_materials_block; 
	s_tag_block_definition<s_unknown_2_block_definition> __unknown_2_block; 
	s_tag_block_definition<s_unknown_3_block_definition> __unknown_3_block; 
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
	Unknown32 __unknown42; 
	Unknown32 __unknown43; 
	Unknown32 __unknown44; 
	Unknown32 __unknown45; 
	Unknown32 __unknown46; 
	Unknown32 __unknown47; 
	Unknown32 __unknown48; 
	Unknown32 __unknown49; 
	float nicename("World Bounds X min") world_bounds_x_min; 
	float nicename("World Bounds X max") world_bounds_x_max; 
	float nicename("World Bounds Y min") world_bounds_y_min; 
	float nicename("World Bounds Y max") world_bounds_y_max; 
	float nicename("World Bounds Z min") world_bounds_z_min; 
	float nicename("World Bounds Z max") world_bounds_z_max; 
	Unknown32 __unknown50; 
	Unknown32 __unknown51; 
	Unknown32 __unknown52; 
	Unknown32 __unknown53; 
	Unknown32 __unknown54; 
	Unknown32 __unknown55; 
	s_tag_block_definition<s_cluster_portal_block_definition> nicename("Cluster Portals") cluster_portals_block; 
	s_tag_block_definition<s_detail_object_block_definition> nicename("Detail Objects") detail_objects_block; 
	s_tag_block_definition<s_cluster_block_definition> nicename("Clusters") clusters_block; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	s_tag_block_definition<s_sky_owner_cluster_block_definition> nicename("Sky Owner Cluster") sky_owner_cluster_block; 
	Unknown32 __unknown56; 
	Unknown32 __unknown57; 
	Unknown32 __unknown58; 
	Unknown32 __unknown59; 
	Unknown32 __unknown60; 
	Unknown32 __unknown61; 
	Unknown32 __unknown62; 
	Unknown32 __unknown63; 
	Unknown32 __unknown64; 
	Unknown32 __unknown65; 
	Unknown32 __unknown66; 
	Unknown32 __unknown67; 
	Unknown32 __unknown68; 
	Unknown32 __unknown69; 
	Unknown32 __unknown70; 
	s_tag_block_definition<s_background_sound_environment_palette_block_definition> nicename("Background Sound Environment Palette") background_sound_environment_palette_block; 
	DataReference __unknown71_data_reference; 
	s_tag_block_definition<s_marker_block_definition> nicename("Markers") markers_block; 
	Unknown32 __unknown72; 
	Unknown32 __unknown73; 
	Unknown32 __unknown74; 
	s_tag_block_definition<s_unknown_11_block_definition> __unknown_11_block; 
	s_tag_block_definition<s_runtime_decal_block_definition> nicename("Runtime Decals") runtime_decals_block; 
	s_tag_block_definition<s_environment_object_palette_block_definition> nicename("Environment Object Palette") environment_object_palette_block; 
	s_tag_block_definition<s_environment_object_block_definition> nicename("Environment Objects") environment_objects_block; 
	Unknown32 __unknown75; 
	Unknown32 __unknown76; 
	Unknown32 __unknown77; 
	Unknown32 __unknown78; 
	Unknown32 __unknown79; 
	Unknown32 __unknown80; 
	Unknown32 __unknown81; 
	Unknown32 __unknown82; 
	Unknown32 __unknown83; 
	Unknown32 __unknown84; 
	Unknown32 __unknown85; 
	Unknown32 __unknown86; 
	Unknown32 __unknown87; 
	Unknown32 __unknown88; 
	Unknown32 __unknown89; 
	Unknown32 __unknown90; 
	s_tag_block_definition<s_instanced_geometry_group_block_definition> nicename("Instanced Geometry Groups") instanced_geometry_groups_block; 
	s_tag_block_definition<s_instanced_geometry_sub_group_block_definition> nicename("Instanced Geometry Sub Groups") instanced_geometry_sub_groups_block; 
	Unknown32 __unknown91; 
	Unknown32 __unknown92; 
	Unknown32 __unknown93; 
	s_tag_block_definition<s_instanced_geometry_instance_block_definition> nicename("Instanced Geometry Instances") instanced_geometry_instances_block; 
	TagReference nicename("Instance Geometry Impostors") instance_geometry_impostors_reference; 
	s_tag_block_definition<s_decorator_block_definition> nicename("Decorators") decorators_block; 
	signed int __unknown94; 
	s_tag_block_definition<s_mesh_block_definition> nicename("Meshes") meshes_block; 
	s_tag_block_definition<s_compression_info_block_definition> nicename("Compression Info") compression_info_block; 
	s_tag_block_definition<s_unknown_nodey_block_definition> __unknown_nodey_block; 
	s_tag_block_definition<s_unknown_30_block_definition> __unknown_30_block; 
	Unknown32 __unknown95; 
	Unknown32 __unknown96; 
	Unknown32 __unknown97; 
	Unknown32 __unknown98; 
	Unknown32 __unknown99; 
	Unknown32 __unknown100; 
	s_tag_block_definition<s_node_map_block_definition> nicename("Node Maps") node_maps_block; 
	Unknown32 __unknown101; 
	Unknown32 __unknown102; 
	Unknown32 __unknown103; 
	Unknown32 __unknown104; 
	Unknown32 __unknown105; 
	Unknown32 __unknown106; 
	Unknown32 __unknown107; 
	Unknown32 __unknown108; 
	Unknown32 __unknown109; 
	s_tag_block_definition<s_unknown_yo_block_definition> __unknown_yo_block; 
	s_tag_block_definition<s_water_mesh_block_definition> nicename("Water Meshes") water_meshes_block; 
	unsigned int nicename("[zone] Asset Datum 1") zone_asset_datum_1; 
	unsigned short nicename("[easy read] Index 1") easy_read_index_1; 
	unsigned short nicename("[easy read] Salt 1") easy_read_salt_1; 
	signed int nicename("Useless Padding") useless_padding; 
	s_tag_block_definition<s_unknown_compression_info_block_definition> __unknown_compression_info_block; 
	s_tag_block_definition<s_decal_block_definition> nicename("Decals") decals_block; 
	s_tag_block_definition<s_decal_property_block_definition> nicename("Decal Properties") decal_properties_block; 
	signed int __unknown110; 
	s_tag_block_definition<s_mesh2_block_definition> nicename("Meshes") meshes2_block; 
	s_tag_block_definition<s_compression_info2_block_definition> nicename("Compression Info") compression_info2_block; 
	s_tag_block_definition<s_unknown_nodey2_block_definition> __unknown_nodey2_block; 
	s_tag_block_definition<s_unknown_30_2_block_definition> __unknown_30_2_block; 
	Unknown32 __unknown111; 
	Unknown32 __unknown112; 
	Unknown32 __unknown113; 
	Unknown32 __unknown114; 
	Unknown32 __unknown115; 
	Unknown32 __unknown116; 
	s_tag_block_definition<s_node_map2_block_definition> nicename("Node Maps") node_maps2_block; 
	Unknown32 __unknown117; 
	Unknown32 __unknown118; 
	Unknown32 __unknown119; 
	Unknown32 __unknown120; 
	Unknown32 __unknown121; 
	Unknown32 __unknown122; 
	Unknown32 __unknown123; 
	Unknown32 __unknown124; 
	Unknown32 __unknown125; 
	s_tag_block_definition<s_unknown_yo2_block_definition> __unknown_yo2_block; 
	s_tag_block_definition<s_water_mesh2_block_definition> nicename("Water Meshes") water_meshes2_block; 
	unsigned int nicename("[zone] Asset Datum 2") zone_asset_datum_2; 
	unsigned short nicename("[easy read] Index 2") easy_read_index_2; 
	unsigned short nicename("[easy read] Salt 2") easy_read_salt_2; 
	signed int nicename("Useless Padding") useless_padding2; 
	s_tag_block_definition<s_unknown_compression_info2_block_definition> __unknown_compression_info2_block; 
	s_tag_block_definition<s_unknown_sound_clusters_a_block_definition> __unknown_sound_clusters_a_block; 
	s_tag_block_definition<s_transparent_plane_block_definition> nicename("Transparent Planes") transparent_planes_block; 
	Unknown32 __unknown126; 
	Unknown32 __unknown127; 
	Unknown32 __unknown128; 
	s_tag_block_definition<s_collision_mopp_code_block_definition> nicename("Collision MOPP Codes") collision_mopp_codes_block; 
	Unknown32 __unknown129; 
	float nicename("Collision Bounds Min X") collision_bounds_min_x; 
	float nicename("Collision Bounds Min Y") collision_bounds_min_y; 
	float nicename("Collision Bounds Min Z") collision_bounds_min_z; 
	float nicename("Collision Bounds Max X") collision_bounds_max_x; 
	float nicename("Collision Bounds Max Y") collision_bounds_max_y; 
	float nicename("Collision Bounds Max Z") collision_bounds_max_z; 
	s_tag_block_definition<s_breakable_surface_mopp_code_block_definition> nicename("Breakable Surface MOPP Codes") breakable_surface_mopp_codes_block; 
	s_tag_block_definition<s_breakable_surface_key_table_block_definition> nicename("Breakable Surface Key Table") breakable_surface_key_table_block; 
	Unknown32 __unknown130; 
	Unknown32 __unknown131; 
	Unknown32 __unknown132; 
	signed int __unknown133; 
	s_tag_block_definition<s_mesh3_block_definition> nicename("Meshes") meshes3_block; 
	s_tag_block_definition<s_compression_info3_block_definition> nicename("Compression Info") compression_info3_block; 
	s_tag_block_definition<s_unknown_nodey3_block_definition> __unknown_nodey3_block; 
	s_tag_block_definition<s_unknown_30_3_block_definition> __unknown_30_3_block; 
	Unknown32 __unknown134; 
	Unknown32 __unknown135; 
	Unknown32 __unknown136; 
	Unknown32 __unknown137; 
	Unknown32 __unknown138; 
	Unknown32 __unknown139; 
	s_tag_block_definition<s_node_map3_block_definition> nicename("Node Maps") node_maps3_block; 
	Unknown32 __unknown140; 
	Unknown32 __unknown141; 
	Unknown32 __unknown142; 
	Unknown32 __unknown143; 
	Unknown32 __unknown144; 
	Unknown32 __unknown145; 
	Unknown32 __unknown146; 
	Unknown32 __unknown147; 
	Unknown32 __unknown148; 
	s_tag_block_definition<s_unknown_yo3_block_definition> __unknown_yo3_block; 
	s_tag_block_definition<s_water_mesh3_block_definition> nicename("Water Meshes") water_meshes3_block; 
	unsigned int nicename("[zone] Asset Datum 3") zone_asset_datum_3; 
	unsigned short nicename("[easy read] Index 3") easy_read_index_3; 
	unsigned short nicename("[easy read] Salt 3") easy_read_salt_3; 
	signed int nicename("Useless Padding") useless_padding3; 
	s_tag_block_definition<s_unknown_compression_info3_block_definition> __unknown_compression_info3_block; 
	Unknown32 __unknown149; 
	Unknown32 __unknown150; 
	Unknown32 __unknown151; 
	Unknown32 __unknown152; 
	Unknown32 __unknown153; 
	Unknown32 __unknown154; 
	Unknown32 __unknown155; 
	Unknown32 __unknown156; 
	Unknown32 __unknown157; 
	unsigned int nicename("[zone] Asset Datum 4") zone_asset_datum_4; 
	unsigned short nicename("[easy read] Index 4") easy_read_index_4; 
	unsigned short nicename("[easy read] Salt 4") easy_read_salt_4; 
	signed int nicename("Useless Padding") useless_padding4; 
	unsigned int nicename("[zone] Asset Datum 5") zone_asset_datum_5; 
	unsigned short nicename("[easy read] Index 5") easy_read_index_5; 
	unsigned short nicename("[easy read] Salt 5") easy_read_salt_5; 
	signed int nicename("Useless Padding") useless_padding5; 
	signed int __unknown158; 
	Unknown32 __unknown159; 

	struct nicename("structure_seam") s_structure_seam_block_definition
	{
		struct s_unknown_block_definition;
		struct nicename("Seam Clusters") s_seam_cluster_block_definition;

		unsigned int __unknown; 
		unsigned int __unknown2; 
		unsigned int __unknown3; 
		unsigned int __unknown4; 
		s_tag_block_definition<s_unknown_block_definition> __unknown5_block; 
		s_tag_block_definition<s_seam_cluster_block_definition> nicename("Seam Clusters") seam_clusters_block; 

		struct s_unknown_block_definition
		{
			signed int __unknown; 
		};

		struct nicename("seam_cluster") s_seam_cluster_block_definition
		{
			signed int nicename("Cluster Index") cluster_index; 
			float nicename("Centroid X") centroid_x; 
			float nicename("Centroid Y") centroid_y; 
			float nicename("Centroid Z") centroid_z; 
		};
	};

	struct nicename("collision_material") s_collision_material_block_definition
	{
		TagReference nicename("Shader") shader_reference; 
		signed short nicename("Global Material Index") global_material_index; 
		signed short nicename("Conveyor Surface Index") conveyor_surface_index; 
		signed short nicename("Seam Index") seam_index; 
		signed short __unknown; 
	};

	struct s_unknown_2_block_definition
	{
		unsigned char __unknown; 
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
		signed short nicename("Back Cluster") back_cluster; 
		signed short nicename("Front Cluster") front_cluster; 
		signed int nicename("Plane Index") plane_index; 
		float nicename("Centroid X") centroid_x; 
		float nicename("Centroid Y") centroid_y; 
		float nicename("Centroid Z") centroid_z; 
		float nicename("Bounding Radius") bounding_radius; 
		signed int nicename("Flags") flags; 
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
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
		signed short __unknown5; 
		signed short __unknown6; 
		signed short nicename("Runtime Decal Start Index") runtime_decal_start_index; 
		signed short nicename("Runtime Decal Entry Count") runtime_decal_entry_count; 
		signed short __unknown7; 
		signed short __unknown8; 
		signed short __unknown9; 
		signed short __unknown10; 
		signed short __unknown11; 
		signed short __unknown12; 
		Unknown32 __unknown13; 
		s_tag_block_definition<s_portal_block_definition> nicename("Portals") portals_block; 
		signed short nicename("Mesh Index") mesh_index; 
		signed short __unknown14; 
		s_tag_block_definition<s_seam_block_definition> nicename("Seams") seams_block; 
		s_tag_block_definition<s_decorator_grid_block_definition> nicename("Decorator Grids") decorator_grids_block; 
		Unknown32 __unknown15; 
		Unknown32 __unknown16; 
		Unknown32 __unknown17; 
		Unknown32 __unknown18; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		s_tag_block_definition<s_unknown_10_block_definition> __unknown_10_block; 
		s_tag_block_definition<s_unknown_11_block_definition> __unknown_11_block; 

		struct nicename("portal") s_portal_block_definition
		{
			signed short nicename("Portal Index") portal_index; 
		};

		struct nicename("seam") s_seam_block_definition
		{
			signed char nicename("Seam Index") seam_index; 
		};

		struct nicename("decorator_grid") s_decorator_grid_block_definition
		{
			struct s_unknown_block_definition;

			signed short nicename("Amount") amount; 
			signed char nicename("Decorator Index") decorator_index; 
			signed char nicename("Decorator Index - Scattering") decorator_index___scattering; 
			signed int __unknown; 
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
				Unknown32 __unknown; 
				Unknown32 __unknown2; 
			};
		};

		struct s_unknown_10_block_definition
		{
			Unknown32 __unknown; 
		};

		struct s_unknown_11_block_definition
		{
			struct s_unknown_12_block_definition;

			signed short __unknown; 
			signed short __unknown2; 
			s_tag_block_definition<s_unknown_12_block_definition> __unknown_12_block; 

			struct s_unknown_12_block_definition
			{
				float __unknown; 
				float __unknown2; 
				float __unknown3; 
				Unknown32 __unknown4; 
			};
		};
	};

	struct nicename("material") s_material_block_definition
	{
		TagReference nicename("Shader") shader_reference; 
		signed int __unknown; 
		float __unknown2; 
		Unknown32 __unknown3; 
		signed char __unknown4; 
		signed char __unknown5; 
		signed char __unknown6; 
		signed char __unknown7; 
		float __unknown8; 
		float __unknown9; 
		signed char __unknown10; 
		signed char nicename("Breakable Surface Index") breakable_surface_index; 
		signed char __unknown11; 
		signed char __unknown12; 
	};

	struct nicename("sky_owner_cluster") s_sky_owner_cluster_block_definition
	{
		signed short nicename("Cluster Owner") cluster_owner; 
	};

	struct nicename("background_sound_environment_palette") s_background_sound_environment_palette_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Sound Environment") sound_environment_reference; 
		signed int __unknown; 
		float nicename("Cutoff Distance") cutoff_distance; 
		float nicename("Interpolation Speed") interpolation_speed; 
		TagReference nicename("Background Sound") background_sound_reference; 
		TagReference nicename("Inside Cluster Sound") inside_cluster_sound_reference; 
		TagReference nicename("Transition In") transition_in_reference; 
		TagReference nicename("Transition Out") transition_out_reference; 
		float nicename("Cutoff Distance") cutoff_distance2; 
		signed int nicename("Scale Flags") scale_flags; 
		float nicename("Interior Scale") interior_scale; 
		float nicename("Portal Scale") portal_scale; 
		float nicename("Exterior Scale") exterior_scale; 
		float nicename("Interpolation Speed") interpolation_speed2; 
	};

	struct nicename("marker") s_marker_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
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
		signed short __unknown; 
	};

	struct nicename("runtime_decal") s_runtime_decal_block_definition
	{
		signed short nicename("Palette Index") palette_index; 
		signed char nicename("Yaw") yaw; 
		signed char nicename("Pitch") pitch; 
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
		signed int nicename("Object Type") object_type; 
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
		signed short nicename("Palette Index") palette_index; 
		signed short __unknown; 
		signed int nicename("Unique ID") unique_id; 
		char nicename("Scenario Object Name") scenario_object_name[4];
		string_id nicename("Name") name; 
		signed int __unknown2; 
	};

	struct nicename("instanced_geometry_group") s_instanced_geometry_group_block_definition
	{
		struct nicename("Members") s_member_block_definition;

		signed int __unknown; 
		s_tag_block_definition<s_member_block_definition> nicename("Members") members_block; 

		struct nicename("member") s_member_block_definition
		{
			signed short nicename("Sub Group Index") sub_group_index; 
		};
	};

	struct nicename("instanced_geometry_sub_group") s_instanced_geometry_sub_group_block_definition
	{
		struct nicename("Members") s_member_block_definition;

		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		float __unknown; 
		signed short __unknown2; 
		signed short __unknown3; 
		float __unknown4; 
		float __unknown5; 
		s_tag_block_definition<s_member_block_definition> nicename("Members") members_block; 

		struct nicename("member") s_member_block_definition
		{
			signed short nicename("Name Index") name_index; 
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
		signed short nicename("Vertex Buffer Index 1") vertex_buffer_index_1; 
		signed short nicename("Vertex Buffer Index 2") vertex_buffer_index_2; 
		signed short nicename("Vertex Buffer Index 3") vertex_buffer_index_3; 
		signed short nicename("Vertex Buffer Index 4") vertex_buffer_index_4; 
		signed short nicename("Vertex Buffer Index 5") vertex_buffer_index_5; 
		signed short nicename("Vertex Buffer Index 6") vertex_buffer_index_6; 
		signed short nicename("Vertex Buffer Index 7") vertex_buffer_index_7; 
		signed short nicename("Vertex Buffer Index 8") vertex_buffer_index_8; 
		signed short nicename("Index Buffer Index 1") index_buffer_index_1; 
		signed short nicename("Index Buffer Index 2") index_buffer_index_2; 
		unsigned short nicename("Flags") flags; 
		signed char nicename("Rigid Node") rigid_node; 
		signed char nicename("Vertex Type") vertex_type; 
		signed char nicename("PRT Type") prt_type; 
		signed char __unknown; 
		signed char nicename("Index Buffer Type") index_buffer_type; 
		signed char __unknown2; 
		s_tag_block_definition<s_instanced_geometry_index_block_definition> nicename("Instanced Geometry Indices") instanced_geometry_indices_block; 
		s_tag_block_definition<s_unknown_water_block_definition> __unknown_water_block; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 

		struct nicename("part") s_part_block_definition
		{
			signed short nicename("Material Index") material_index; 
			signed short nicename("'Unknown Nodey' Index") _unknown_nodey__index; 
			signed int nicename("Index Buffer Start") index_buffer_start; 
			signed int nicename("Index Buffer Count") index_buffer_count; 
			signed short nicename("Subpart Start") subpart_start; 
			signed short nicename("Subpart Count") subpart_count; 
			signed char __unknown_enum; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed short nicename("Vertex Count") vertex_count; 
			signed short __unknown4; 
		};

		struct nicename("subpart") s_subpart_block_definition
		{
			signed int nicename("Index Buffer Start") index_buffer_start; 
			signed int nicename("Index Buffer Count") index_buffer_count; 
			signed short nicename("Part Index") part_index; 
			signed short nicename("Vertex Count") vertex_count; 
			signed int __unknown; 
		};

		struct nicename("instanced_geometry_index") s_instanced_geometry_index_block_definition
		{
			struct nicename("Instanced Geometry Mesh Contents") s_instanced_geometry_mesh_content_block_definition;

			signed short nicename("Instanced Geometry Mesh Index 1") instanced_geometry_mesh_index_1; 
			signed short nicename("Instanced Geometry Mesh Index 2") instanced_geometry_mesh_index_2; 
			s_tag_block_definition<s_instanced_geometry_mesh_content_block_definition> nicename("Instanced Geometry Mesh Contents") instanced_geometry_mesh_contents_block; 

			struct nicename("instanced_geometry_mesh_content") s_instanced_geometry_mesh_content_block_definition
			{
				signed short nicename("Instanced Geometry Index") instanced_geometry_index; 
			};
		};

		struct s_unknown_water_block_definition
		{
			signed short __unknown; 
		};
	};

	struct nicename("compression_info") s_compression_info_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
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
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
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
		signed char nicename("Node Index") node_index; 
		signed char nicename("Node Index") node_index2; 
		signed char nicename("Node Index") node_index3; 
		signed char nicename("Node Index") node_index4; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
	};

	struct s_unknown_30_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
		DataReference __unknown3_data_reference; 
	};

	struct nicename("node_map") s_node_map_block_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

		struct s_unknown_block_definition
		{
			unsigned char nicename("Node Index") node_index; 
		};
	};

	struct s_unknown_yo_block_definition
	{
		signed short __unknown_index; 
	};

	struct nicename("water_mesh") s_water_mesh_block_definition
	{
		signed short nicename("Mesh Index") mesh_index; 
		signed short __unknown; 
		float nicename("X Min") x_min; 
		float nicename("X Max") x_max; 
		float nicename("Y Min") y_min; 
		float nicename("Y Max") y_max; 
		float nicename("Z Min") z_min; 
		float nicename("Z Max") z_max; 
	};

	struct s_unknown_compression_info_block_definition
	{
		unsigned int nicename("Polyart Asset Address") polyart_asset_address; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
	};

	struct nicename("decal") s_decal_block_definition
	{
		unsigned int nicename("Decal") decal; 
		signed short __unknown; 
		signed short __unknown2; 
		signed short __unknown3; 
		signed short __unknown4; 
		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		signed short nicename("Decal Property Index") decal_property_index; 
		signed short __unknown5; 
	};

	struct nicename("decal_property") s_decal_property_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
		signed short __unknown3; 
		signed short __unknown4; 
		Unknown32 __unknown5; 
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
		signed short nicename("Vertex Buffer Index 1") vertex_buffer_index_1; 
		signed short nicename("Vertex Buffer Index 2") vertex_buffer_index_2; 
		signed short nicename("Vertex Buffer Index 3") vertex_buffer_index_3; 
		signed short nicename("Vertex Buffer Index 4") vertex_buffer_index_4; 
		signed short nicename("Vertex Buffer Index 5") vertex_buffer_index_5; 
		signed short nicename("Vertex Buffer Index 6") vertex_buffer_index_6; 
		signed short nicename("Vertex Buffer Index 7") vertex_buffer_index_7; 
		signed short nicename("Vertex Buffer Index 8") vertex_buffer_index_8; 
		signed short nicename("Index Buffer Index 1") index_buffer_index_1; 
		signed short nicename("Index Buffer Index 2") index_buffer_index_2; 
		unsigned short nicename("Flags") flags; 
		signed char nicename("Rigid Node") rigid_node; 
		signed char nicename("Vertex Type") vertex_type; 
		signed char nicename("PRT Type") prt_type; 
		signed char __unknown; 
		signed char nicename("Index Buffer Type") index_buffer_type; 
		signed char __unknown2; 
		s_tag_block_definition<s_instanced_geometry_index_block_definition> nicename("Instanced Geometry Indices") instanced_geometry_indices_block; 
		s_tag_block_definition<s_unknown_water_block_definition> __unknown_water_block; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 

		struct nicename("part") s_part_block_definition
		{
			signed short nicename("Material Index") material_index; 
			signed short nicename("'Unknown Nodey' Index") _unknown_nodey__index; 
			signed int nicename("Index Buffer Start") index_buffer_start; 
			signed int nicename("Index Buffer Count") index_buffer_count; 
			signed short nicename("Subpart Start") subpart_start; 
			signed short nicename("Subpart Count") subpart_count; 
			signed char __unknown_enum; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed short nicename("Vertex Count") vertex_count; 
			signed short __unknown4; 
		};

		struct nicename("subpart") s_subpart_block_definition
		{
			signed int nicename("Index Buffer Start") index_buffer_start; 
			signed int nicename("Index Buffer Count") index_buffer_count; 
			signed short nicename("Part Index") part_index; 
			signed short nicename("Vertex Count") vertex_count; 
			signed int __unknown; 
		};

		struct nicename("instanced_geometry_index") s_instanced_geometry_index_block_definition
		{
			struct nicename("Instanced Geometry Mesh Contents") s_instanced_geometry_mesh_content_block_definition;

			signed short nicename("Instanced Geometry Mesh Index 1") instanced_geometry_mesh_index_1; 
			signed short nicename("Instanced Geometry Mesh Index 2") instanced_geometry_mesh_index_2; 
			s_tag_block_definition<s_instanced_geometry_mesh_content_block_definition> nicename("Instanced Geometry Mesh Contents") instanced_geometry_mesh_contents_block; 

			struct nicename("instanced_geometry_mesh_content") s_instanced_geometry_mesh_content_block_definition
			{
				signed short nicename("Instanced Geometry Index") instanced_geometry_index; 
			};
		};

		struct s_unknown_water_block_definition
		{
			signed short __unknown; 
		};
	};

	struct nicename("compression_info2") s_compression_info2_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
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
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
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
		signed char nicename("Node Index") node_index; 
		signed char nicename("Node Index") node_index2; 
		signed char nicename("Node Index") node_index3; 
		signed char nicename("Node Index") node_index4; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
	};

	struct s_unknown_30_2_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
		DataReference __unknown3_data_reference; 
	};

	struct nicename("node_map2") s_node_map2_block_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

		struct s_unknown_block_definition
		{
			unsigned char nicename("Node Index") node_index; 
		};
	};

	struct s_unknown_yo2_block_definition
	{
		signed short __unknown_index; 
	};

	struct nicename("water_mesh2") s_water_mesh2_block_definition
	{
		signed short nicename("Mesh Index") mesh_index; 
		signed short __unknown; 
		float nicename("X Min") x_min; 
		float nicename("X Max") x_max; 
		float nicename("Y Min") y_min; 
		float nicename("Y Max") y_max; 
		float nicename("Z Min") z_min; 
		float nicename("Z Max") z_max; 
	};

	struct s_unknown_compression_info2_block_definition
	{
		unsigned int nicename("Polyart Asset Address") polyart_asset_address; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
	};

	struct s_unknown_sound_clusters_a_block_definition
	{
		struct nicename("Portal Designators") s_portal_designator_block_definition;
		struct nicename("Interior Cluster Indices") s_interior_cluster_index_block_definition;

		signed short nicename("Background Sound Environment Index") background_sound_environment_index; 
		signed short __unknown; 
		s_tag_block_definition<s_portal_designator_block_definition> nicename("Portal Designators") portal_designators_block; 
		s_tag_block_definition<s_interior_cluster_index_block_definition> nicename("Interior Cluster Indices") interior_cluster_indices_block; 

		struct nicename("portal_designator") s_portal_designator_block_definition
		{
			signed short nicename("Portal Designator") portal_designator; 
		};

		struct nicename("interior_cluster_index") s_interior_cluster_index_block_definition
		{
			signed short nicename("Interior Cluster Index") interior_cluster_index; 
		};
	};

	struct nicename("transparent_plane") s_transparent_plane_block_definition
	{
		signed short nicename("Mesh Index") mesh_index; 
		signed short nicename("Part Index") part_index; 
		float nicename("Plane i") plane_i; 
		float nicename("Plane j") plane_j; 
		float nicename("Plane k") plane_k; 
		float nicename("Plane d") plane_d; 
	};

	struct nicename("collision_mopp_code") s_collision_mopp_code_block_definition
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

	struct nicename("breakable_surface_mopp_code") s_breakable_surface_mopp_code_block_definition
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

	struct nicename("breakable_surface_key_table") s_breakable_surface_key_table_block_definition
	{
		signed short nicename("Instanced Geometry Index") instanced_geometry_index; 
		signed char nicename("Breakable Surface Index") breakable_surface_index; 
		unsigned char nicename("Breakable Surface Sub-Index") breakable_surface_sub_index; 
		signed int nicename("Seed Surface Index") seed_surface_index; 
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
		signed short nicename("Vertex Buffer Index 1") vertex_buffer_index_1; 
		signed short nicename("Vertex Buffer Index 2") vertex_buffer_index_2; 
		signed short nicename("Vertex Buffer Index 3") vertex_buffer_index_3; 
		signed short nicename("Vertex Buffer Index 4") vertex_buffer_index_4; 
		signed short nicename("Vertex Buffer Index 5") vertex_buffer_index_5; 
		signed short nicename("Vertex Buffer Index 6") vertex_buffer_index_6; 
		signed short nicename("Vertex Buffer Index 7") vertex_buffer_index_7; 
		signed short nicename("Vertex Buffer Index 8") vertex_buffer_index_8; 
		signed short nicename("Index Buffer Index 1") index_buffer_index_1; 
		signed short nicename("Index Buffer Index 2") index_buffer_index_2; 
		unsigned short nicename("Flags") flags; 
		signed char nicename("Rigid Node") rigid_node; 
		signed char nicename("Vertex Type") vertex_type; 
		signed char nicename("PRT Type") prt_type; 
		signed char __unknown; 
		signed char nicename("Index Buffer Type") index_buffer_type; 
		signed char __unknown2; 
		s_tag_block_definition<s_instanced_geometry_index_block_definition> nicename("Instanced Geometry Indices") instanced_geometry_indices_block; 
		s_tag_block_definition<s_unknown_water_block_definition> __unknown_water_block; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 

		struct nicename("part") s_part_block_definition
		{
			signed short nicename("Material Index") material_index; 
			signed short nicename("'Unknown Nodey' Index") _unknown_nodey__index; 
			signed int nicename("Index Buffer Start") index_buffer_start; 
			signed int nicename("Index Buffer Count") index_buffer_count; 
			signed short nicename("Subpart Start") subpart_start; 
			signed short nicename("Subpart Count") subpart_count; 
			signed char __unknown_enum; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed short nicename("Vertex Count") vertex_count; 
			signed short __unknown4; 
		};

		struct nicename("subpart") s_subpart_block_definition
		{
			signed int nicename("Index Buffer Start") index_buffer_start; 
			signed int nicename("Index Buffer Count") index_buffer_count; 
			signed short nicename("Part Index") part_index; 
			signed short nicename("Vertex Count") vertex_count; 
			signed int __unknown; 
		};

		struct nicename("instanced_geometry_index") s_instanced_geometry_index_block_definition
		{
			struct nicename("Instanced Geometry Mesh Contents") s_instanced_geometry_mesh_content_block_definition;

			signed short nicename("Instanced Geometry Mesh Index 1") instanced_geometry_mesh_index_1; 
			signed short nicename("Instanced Geometry Mesh Index 2") instanced_geometry_mesh_index_2; 
			s_tag_block_definition<s_instanced_geometry_mesh_content_block_definition> nicename("Instanced Geometry Mesh Contents") instanced_geometry_mesh_contents_block; 

			struct nicename("instanced_geometry_mesh_content") s_instanced_geometry_mesh_content_block_definition
			{
				signed short nicename("Instanced Geometry Index") instanced_geometry_index; 
			};
		};

		struct s_unknown_water_block_definition
		{
			signed short __unknown; 
		};
	};

	struct nicename("compression_info3") s_compression_info3_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
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
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
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
		signed char nicename("Node Index") node_index; 
		signed char nicename("Node Index") node_index2; 
		signed char nicename("Node Index") node_index3; 
		signed char nicename("Node Index") node_index4; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
	};

	struct s_unknown_30_3_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
		DataReference __unknown3_data_reference; 
	};

	struct nicename("node_map3") s_node_map3_block_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

		struct s_unknown_block_definition
		{
			unsigned char nicename("Node Index") node_index; 
		};
	};

	struct s_unknown_yo3_block_definition
	{
		signed short __unknown_index; 
	};

	struct nicename("water_mesh3") s_water_mesh3_block_definition
	{
		signed short nicename("Mesh Index") mesh_index; 
		signed short __unknown; 
		float nicename("X Min") x_min; 
		float nicename("X Max") x_max; 
		float nicename("Y Min") y_min; 
		float nicename("Y Max") y_max; 
		float nicename("Z Min") z_min; 
		float nicename("Z Max") z_max; 
	};

	struct s_unknown_compression_info3_block_definition
	{
		unsigned int nicename("Polyart Asset Address") polyart_asset_address; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
	};
};
