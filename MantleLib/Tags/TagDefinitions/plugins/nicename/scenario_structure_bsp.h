#pragma once

nicename("scenario_structure_bsp") struct s_scenario_structure_bsp_definition
{
	nicename("Structure Seams") struct s_structure_seam_block_definition;
	nicename("Collision Materials") struct s_collision_material_block_definition;
	nicename("Unknown 2") struct s_unknown_2_block_definition;
	nicename("Unknown 3") struct s_unknown_3_block_definition;
	nicename("Cluster Portals") struct s_cluster_portal_block_definition;
	nicename("Detail Objects") struct s_detail_object_block_definition;
	nicename("Clusters") struct s_cluster_block_definition;
	nicename("Materials") struct s_material_block_definition;
	nicename("Sky Owner Cluster") struct s_sky_owner_cluster_block_definition;
	nicename("Background Sound Environment Palette") struct s_background_sound_environment_palette_block_definition;
	nicename("Markers") struct s_marker_block_definition;
	nicename("Unknown 11") struct s_unknown_11_block_definition;
	nicename("Runtime Decals") struct s_runtime_decal_block_definition;
	nicename("Environment Object Palette") struct s_environment_object_palette_block_definition;
	nicename("Environment Objects") struct s_environment_object_block_definition;
	nicename("Instanced Geometry Groups") struct s_instanced_geometry_group_block_definition;
	nicename("Instanced Geometry Sub Groups") struct s_instanced_geometry_sub_group_block_definition;
	nicename("Instanced Geometry Instances") struct s_instanced_geometry_instance_block_definition;
	nicename("Decorators") struct s_decorator_block_definition;
	nicename("Meshes") struct s_mesh_block_definition;
	nicename("Compression Info") struct s_compression_info_block_definition;
	nicename("Unknown Nodey") struct s_unknown_nodey_block_definition;
	nicename("Unknown 30") struct s_unknown_30_block_definition;
	nicename("Node Maps") struct s_node_map_block_definition;
	nicename("Unknown Yo") struct s_unknown_yo_block_definition;
	nicename("Water Meshes") struct s_water_mesh_block_definition;
	nicename("Unknown Compression Info") struct s_unknown_compression_info_block_definition;
	nicename("Decals") struct s_decal_block_definition;
	nicename("Decal Properties") struct s_decal_property_block_definition;
	nicename("Meshes") struct s_mesh2_block_definition;
	nicename("Compression Info") struct s_compression_info3_block_definition;
	nicename("Unknown Nodey") struct s_unknown_nodey3_block_definition;
	nicename("Unknown 30") struct s_unknown_30_3_block_definition;
	nicename("Node Maps") struct s_node_map2_block_definition;
	nicename("Unknown Yo") struct s_unknown_yo3_block_definition;
	nicename("Water Meshes") struct s_water_mesh2_block_definition;
	nicename("Unknown Compression Info") struct s_unknown_compression_info3_block_definition;
	nicename("Unknown Sound Clusters A") struct s_unknown_sound_clusters_a_block_definition;
	nicename("Transparent Planes") struct s_transparent_plane_block_definition;
	nicename("Collision MOPP Codes") struct s_collision_mopp_code_block_definition;
	nicename("Breakable Surface MOPP Codes") struct s_breakable_surface_mopp_code_block_definition;
	nicename("Breakable Surface Key Table") struct s_breakable_surface_key_table_block_definition;
	nicename("Meshes") struct s_mesh3_block_definition;
	nicename("Compression Info") struct s_compression_info5_block_definition;
	nicename("Unknown Nodey") struct s_unknown_nodey5_block_definition;
	nicename("Unknown 30") struct s_unknown_30_5_block_definition;
	nicename("Node Maps") struct s_node_map3_block_definition;
	nicename("Unknown Yo") struct s_unknown_yo5_block_definition;
	nicename("Water Meshes") struct s_water_mesh3_block_definition;
	nicename("Unknown Compression Info") struct s_unknown_compression_info5_block_definition;

	nicename("Unknown") unsigned int unknown;
	nicename("Unknown") float unknown2;
	nicename("Unknown") unsigned int unknown3;
	nicename("Unknown") float unknown4;
	nicename("Unknown") signed int unknown5;
	nicename("Unknown") signed int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") unsigned int unknown9;
	nicename("Unknown") unsigned int unknown10;
	nicename("Unknown") unsigned int unknown11;
	nicename("Unknown") unsigned int unknown12;
	nicename("BSP Checksum") signed int bsp_checksum;
	nicename("Unknown") signed int unknown13;
	nicename("Unknown") signed short unknown14;
	nicename("Unknown") signed short unknown15;
	nicename("Unknown") signed short unknown16;
	nicename("Unknown") signed short unknown17;
	nicename("Structure Seams") s_tag_block_definition<s_structure_seam_block_definition> structure_seams;
	nicename("Unknown") unsigned int unknown18;
	nicename("Unknown") unsigned int unknown19;
	nicename("Unknown") unsigned int unknown20;
	nicename("Collision Materials") s_tag_block_definition<s_collision_material_block_definition> collision_materials;
	nicename("Unknown 2") s_tag_block_definition<s_unknown_2_block_definition> unknown_2_2;
	nicename("Unknown 3") s_tag_block_definition<s_unknown_3_block_definition> unknown_3_2;
	nicename("Unknown") unsigned int unknown21;
	nicename("Unknown") unsigned int unknown22;
	nicename("Unknown") unsigned int unknown23;
	nicename("Unknown") unsigned int unknown24;
	nicename("Unknown") unsigned int unknown25;
	nicename("Unknown") unsigned int unknown26;
	nicename("Unknown") unsigned int unknown27;
	nicename("Unknown") unsigned int unknown28;
	nicename("Unknown") unsigned int unknown29;
	nicename("Unknown") signed int unknown30;
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
	nicename("World Bounds X min") float world_bounds_x_min;
	nicename("World Bounds X max") float world_bounds_x_max;
	nicename("World Bounds Y min") float world_bounds_y_min;
	nicename("World Bounds Y max") float world_bounds_y_max;
	nicename("World Bounds Z min") float world_bounds_z_min;
	nicename("World Bounds Z max") float world_bounds_z_max;
	nicename("Unknown") unsigned int unknown50;
	nicename("Unknown") unsigned int unknown51;
	nicename("Unknown") unsigned int unknown52;
	nicename("Unknown") unsigned int unknown53;
	nicename("Unknown") unsigned int unknown54;
	nicename("Unknown") unsigned int unknown55;
	nicename("Cluster Portals") s_tag_block_definition<s_cluster_portal_block_definition> cluster_portals;
	nicename("Detail Objects") s_tag_block_definition<s_detail_object_block_definition> detail_objects;
	nicename("Clusters") s_tag_block_definition<s_cluster_block_definition> clusters;
	nicename("Materials") s_tag_block_definition<s_material_block_definition> materials;
	nicename("Sky Owner Cluster") s_tag_block_definition<s_sky_owner_cluster_block_definition> sky_owner_cluster2;
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
	nicename("Background Sound Environment Palette") s_tag_block_definition<s_background_sound_environment_palette_block_definition> background_sound_environment_palette2;
	nicename("Unknown") DataReference unknown71;
	nicename("Markers") s_tag_block_definition<s_marker_block_definition> markers;
	nicename("Unknown") unsigned int unknown72;
	nicename("Unknown") unsigned int unknown73;
	nicename("Unknown") unsigned int unknown74;
	nicename("Unknown 11") s_tag_block_definition<s_unknown_11_block_definition> unknown_11_2;
	nicename("Runtime Decals") s_tag_block_definition<s_runtime_decal_block_definition> runtime_decals;
	nicename("Environment Object Palette") s_tag_block_definition<s_environment_object_palette_block_definition> environment_object_palette2;
	nicename("Environment Objects") s_tag_block_definition<s_environment_object_block_definition> environment_objects;
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
	nicename("Unknown") unsigned int unknown85;
	nicename("Unknown") unsigned int unknown86;
	nicename("Unknown") unsigned int unknown87;
	nicename("Unknown") unsigned int unknown88;
	nicename("Unknown") unsigned int unknown89;
	nicename("Unknown") unsigned int unknown90;
	nicename("Instanced Geometry Groups") s_tag_block_definition<s_instanced_geometry_group_block_definition> instanced_geometry_groups;
	nicename("Instanced Geometry Sub Groups") s_tag_block_definition<s_instanced_geometry_sub_group_block_definition> instanced_geometry_sub_groups;
	nicename("Unknown") unsigned int unknown91;
	nicename("Unknown") unsigned int unknown92;
	nicename("Unknown") unsigned int unknown93;
	nicename("Instanced Geometry Instances") s_tag_block_definition<s_instanced_geometry_instance_block_definition> instanced_geometry_instances;
	nicename("Instance Geometry Impostors") TagReference instance_geometry_impostors;
	nicename("Decorators") s_tag_block_definition<s_decorator_block_definition> decorators;
	nicename("Unknown") signed int unknown94;
	nicename("Meshes") s_tag_block_definition<s_mesh_block_definition> meshes;
	nicename("Compression Info") s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	nicename("Unknown Nodey") s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	nicename("Unknown 30") s_tag_block_definition<s_unknown_30_block_definition> unknown_30_2;
	nicename("Unknown") unsigned int unknown95;
	nicename("Unknown") unsigned int unknown96;
	nicename("Unknown") unsigned int unknown97;
	nicename("Unknown") unsigned int unknown98;
	nicename("Unknown") unsigned int unknown99;
	nicename("Unknown") unsigned int unknown100;
	nicename("Node Maps") s_tag_block_definition<s_node_map_block_definition> node_maps;
	nicename("Unknown") unsigned int unknown101;
	nicename("Unknown") unsigned int unknown102;
	nicename("Unknown") unsigned int unknown103;
	nicename("Unknown") unsigned int unknown104;
	nicename("Unknown") unsigned int unknown105;
	nicename("Unknown") unsigned int unknown106;
	nicename("Unknown") unsigned int unknown107;
	nicename("Unknown") unsigned int unknown108;
	nicename("Unknown") unsigned int unknown109;
	nicename("Unknown Yo") s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	nicename("Water Meshes") s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	nicename("[zone] Asset Datum 1") unsigned int zone_asset_datum_1;
	nicename("[easy read] Index 1") unsigned short easy_read_index_1;
	nicename("[easy read] Salt 1") unsigned short easy_read_salt_1;
	nicename("Useless Padding") signed int useless_padding;
	nicename("Unknown Compression Info") s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	nicename("Decals") s_tag_block_definition<s_decal_block_definition> decals;
	nicename("Decal Properties") s_tag_block_definition<s_decal_property_block_definition> decal_properties;
	nicename("Unknown") signed int unknown110;
	nicename("Meshes") s_tag_block_definition<s_mesh2_block_definition> meshes2;
	nicename("Compression Info") s_tag_block_definition<s_compression_info3_block_definition> compression_info4;
	nicename("Unknown Nodey") s_tag_block_definition<s_unknown_nodey3_block_definition> unknown_nodey4;
	nicename("Unknown 30") s_tag_block_definition<s_unknown_30_3_block_definition> unknown_30_4;
	nicename("Unknown") unsigned int unknown111;
	nicename("Unknown") unsigned int unknown112;
	nicename("Unknown") unsigned int unknown113;
	nicename("Unknown") unsigned int unknown114;
	nicename("Unknown") unsigned int unknown115;
	nicename("Unknown") unsigned int unknown116;
	nicename("Node Maps") s_tag_block_definition<s_node_map2_block_definition> node_maps2;
	nicename("Unknown") unsigned int unknown117;
	nicename("Unknown") unsigned int unknown118;
	nicename("Unknown") unsigned int unknown119;
	nicename("Unknown") unsigned int unknown120;
	nicename("Unknown") unsigned int unknown121;
	nicename("Unknown") unsigned int unknown122;
	nicename("Unknown") unsigned int unknown123;
	nicename("Unknown") unsigned int unknown124;
	nicename("Unknown") unsigned int unknown125;
	nicename("Unknown Yo") s_tag_block_definition<s_unknown_yo3_block_definition> unknown_yo4;
	nicename("Water Meshes") s_tag_block_definition<s_water_mesh2_block_definition> water_meshes2;
	nicename("[zone] Asset Datum 2") unsigned int zone_asset_datum_2;
	nicename("[easy read] Index 2") unsigned short easy_read_index_2;
	nicename("[easy read] Salt 2") unsigned short easy_read_salt_2;
	nicename("Useless Padding") signed int useless_padding2;
	nicename("Unknown Compression Info") s_tag_block_definition<s_unknown_compression_info3_block_definition> unknown_compression_info4;
	nicename("Unknown Sound Clusters A") s_tag_block_definition<s_unknown_sound_clusters_a_block_definition> unknown_sound_clusters_a2;
	nicename("Transparent Planes") s_tag_block_definition<s_transparent_plane_block_definition> transparent_planes;
	nicename("Unknown") unsigned int unknown126;
	nicename("Unknown") unsigned int unknown127;
	nicename("Unknown") unsigned int unknown128;
	nicename("Collision MOPP Codes") s_tag_block_definition<s_collision_mopp_code_block_definition> collision_mopp_codes;
	nicename("Unknown") unsigned int unknown129;
	nicename("Collision Bounds Min X") float collision_bounds_min_x;
	nicename("Collision Bounds Min Y") float collision_bounds_min_y;
	nicename("Collision Bounds Min Z") float collision_bounds_min_z;
	nicename("Collision Bounds Max X") float collision_bounds_max_x;
	nicename("Collision Bounds Max Y") float collision_bounds_max_y;
	nicename("Collision Bounds Max Z") float collision_bounds_max_z;
	nicename("Breakable Surface MOPP Codes") s_tag_block_definition<s_breakable_surface_mopp_code_block_definition> breakable_surface_mopp_codes;
	nicename("Breakable Surface Key Table") s_tag_block_definition<s_breakable_surface_key_table_block_definition> breakable_surface_key_table2;
	nicename("Unknown") unsigned int unknown130;
	nicename("Unknown") unsigned int unknown131;
	nicename("Unknown") unsigned int unknown132;
	nicename("Unknown") signed int unknown133;
	nicename("Meshes") s_tag_block_definition<s_mesh3_block_definition> meshes3;
	nicename("Compression Info") s_tag_block_definition<s_compression_info5_block_definition> compression_info6;
	nicename("Unknown Nodey") s_tag_block_definition<s_unknown_nodey5_block_definition> unknown_nodey6;
	nicename("Unknown 30") s_tag_block_definition<s_unknown_30_5_block_definition> unknown_30_6;
	nicename("Unknown") unsigned int unknown134;
	nicename("Unknown") unsigned int unknown135;
	nicename("Unknown") unsigned int unknown136;
	nicename("Unknown") unsigned int unknown137;
	nicename("Unknown") unsigned int unknown138;
	nicename("Unknown") unsigned int unknown139;
	nicename("Node Maps") s_tag_block_definition<s_node_map3_block_definition> node_maps3;
	nicename("Unknown") unsigned int unknown140;
	nicename("Unknown") unsigned int unknown141;
	nicename("Unknown") unsigned int unknown142;
	nicename("Unknown") unsigned int unknown143;
	nicename("Unknown") unsigned int unknown144;
	nicename("Unknown") unsigned int unknown145;
	nicename("Unknown") unsigned int unknown146;
	nicename("Unknown") unsigned int unknown147;
	nicename("Unknown") unsigned int unknown148;
	nicename("Unknown Yo") s_tag_block_definition<s_unknown_yo5_block_definition> unknown_yo6;
	nicename("Water Meshes") s_tag_block_definition<s_water_mesh3_block_definition> water_meshes3;
	nicename("[zone] Asset Datum 3") unsigned int zone_asset_datum_3;
	nicename("[easy read] Index 3") unsigned short easy_read_index_3;
	nicename("[easy read] Salt 3") unsigned short easy_read_salt_3;
	nicename("Useless Padding") signed int useless_padding3;
	nicename("Unknown Compression Info") s_tag_block_definition<s_unknown_compression_info5_block_definition> unknown_compression_info6;
	nicename("Unknown") unsigned int unknown149;
	nicename("Unknown") unsigned int unknown150;
	nicename("Unknown") unsigned int unknown151;
	nicename("Unknown") unsigned int unknown152;
	nicename("Unknown") unsigned int unknown153;
	nicename("Unknown") unsigned int unknown154;
	nicename("Unknown") unsigned int unknown155;
	nicename("Unknown") unsigned int unknown156;
	nicename("Unknown") unsigned int unknown157;
	nicename("[zone] Asset Datum 4") unsigned int zone_asset_datum_4;
	nicename("[easy read] Index 4") unsigned short easy_read_index_4;
	nicename("[easy read] Salt 4") unsigned short easy_read_salt_4;
	nicename("Useless Padding") signed int useless_padding4;
	nicename("[zone] Asset Datum 5") unsigned int zone_asset_datum_5;
	nicename("[easy read] Index 5") unsigned short easy_read_index_5;
	nicename("[easy read] Salt 5") unsigned short easy_read_salt_5;
	nicename("Useless Padding") signed int useless_padding5;
	nicename("Unknown") signed int unknown158;

	nicename("Structure Seam") struct s_structure_seam_definition
	{
		nicename("Unknown") struct s_unknown5_block_definition;
		nicename("Seam Clusters") struct s_seam_cluster_block_definition;

		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") s_tag_block_definition<s_unknown5_block_definition> unknown6;
		nicename("Seam Clusters") s_tag_block_definition<s_seam_cluster_block_definition> seam_clusters;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") signed int unknown2;
		};

		nicename("Seam Cluster") struct s_seam_cluster_definition
		{
			nicename("Cluster Index") signed int cluster_index;
			nicename("Centroid X") float centroid_x;
			nicename("Centroid Y") float centroid_y;
			nicename("Centroid Z") float centroid_z;
		};
	};

	nicename("Collision Material") struct s_collision_material_definition
	{
		nicename("Shader") TagReference shader;
		nicename("Global Material Index") signed short global_material_index;
		nicename("Conveyor Surface Index") signed short conveyor_surface_index;
		nicename("Seam Index") signed short seam_index;
		nicename("Unknown") signed short unknown;
	};

	nicename("Unknown 2") struct s_unknown_2_definition
	{
		nicename("Unknown") unsigned char unknown;
	};

	nicename("Unknown 3") struct s_unknown_3_definition
	{
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
	};

	nicename("Cluster Portal") struct s_cluster_portal_definition
	{
		nicename("Vertices") struct s_vertex_block_definition;

		nicename("X") float x;
		nicename("Y") float y;
		nicename("Z") float z;
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Back Cluster") signed short back_cluster;
		nicename("Front Cluster") signed short front_cluster;
		nicename("Plane Index") signed int plane_index;
		nicename("Centroid X") float centroid_x;
		nicename("Centroid Y") float centroid_y;
		nicename("Centroid Z") float centroid_z;
		nicename("Bounding Radius") float bounding_radius;
		nicename("Flags") signed int flags;
		nicename("Vertices") s_tag_block_definition<s_vertex_block_definition> vertices;

		nicename("Vertex") struct s_vertex_definition
		{
			nicename("X") float x;
			nicename("Y") float y;
			nicename("Z") float z;
		};
	};

	nicename("Detail Object") struct s_detail_object_definition
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
	};

	nicename("Cluster") struct s_cluster_definition
	{
		nicename("Portals") struct s_portal_block_definition;
		nicename("Seams") struct s_seam_block_definition;
		nicename("Decorator Grids") struct s_decorator_grid_block_definition;
		nicename("Unknown 10") struct s_unknown_10_block_definition;
		nicename("Unknown 11") struct s_unknown_11_block_definition;

		nicename("Bounds X min") float bounds_x_min;
		nicename("Bounds X max") float bounds_x_max;
		nicename("Bounds Y min") float bounds_y_min;
		nicename("Bounds Y max") float bounds_y_max;
		nicename("Bounds Z min") float bounds_z_min;
		nicename("Bounds Z max") float bounds_z_max;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Runtime Decal Start Index") signed short runtime_decal_start_index;
		nicename("Runtime Decal Entry Count") signed short runtime_decal_entry_count;
		nicename("Unknown") signed short unknown7;
		nicename("Unknown") signed short unknown8;
		nicename("Unknown") signed short unknown9;
		nicename("Unknown") signed short unknown10;
		nicename("Unknown") signed short unknown11;
		nicename("Unknown") signed short unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Portals") s_tag_block_definition<s_portal_block_definition> portals;
		nicename("Mesh Index") signed short mesh_index;
		nicename("Unknown") signed short unknown14;
		nicename("Seams") s_tag_block_definition<s_seam_block_definition> seams;
		nicename("Decorator Grids") s_tag_block_definition<s_decorator_grid_block_definition> decorator_grids;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") unsigned int unknown16;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") unsigned int unknown20;
		nicename("Unknown 10") s_tag_block_definition<s_unknown_10_block_definition> unknown_10_2;
		nicename("Unknown 11") s_tag_block_definition<s_unknown_11_block_definition> unknown_11_2;

		nicename("Portal") struct s_portal_definition
		{
			nicename("Portal Index") signed short portal_index;
		};

		nicename("Seam") struct s_seam_definition
		{
			nicename("Seam Index") signed char seam_index;
		};

		nicename("Decorator Grid") struct s_decorator_grid_definition
		{
			nicename("Unknown") struct s_unknown2_block_definition;

			nicename("Amount") signed short amount;
			nicename("Decorator Index") signed char decorator_index;
			nicename("Decorator Index - Scattering") signed char decorator_index___scattering;
			nicename("Unknown") signed int unknown;
			nicename("Position X") float position_x;
			nicename("Position Y") float position_y;
			nicename("Position Z") float position_z;
			nicename("Radius") float radius;
			nicename("Grid Size X") float grid_size_x;
			nicename("Grid Size Y") float grid_size_y;
			nicename("Grid Size Z") float grid_size_z;
			nicename("Bounding Sphere X") float bounding_sphere_x;
			nicename("Bounding Sphere Y") float bounding_sphere_y;
			nicename("Bounding Sphere Z") float bounding_sphere_z;
			nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") unsigned int unknown2;
				nicename("Unknown") unsigned int unknown3;
			};
		};

		nicename("Unknown 10") struct s_unknown_10_definition
		{
			nicename("Unknown") unsigned int unknown;
		};

		nicename("Unknown 11") struct s_unknown_11_definition
		{
			nicename("Unknown 12") struct s_unknown_12_block_definition;

			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown 12") s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;

			nicename("Unknown 12") struct s_unknown_12_definition
			{
				nicename("Unknown") float unknown;
				nicename("Unknown") float unknown2;
				nicename("Unknown") float unknown3;
				nicename("Unknown") unsigned int unknown4;
			};
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

	nicename("Sky Owner Cluster") struct s_sky_owner_cluster_definition
	{
		nicename("Cluster Owner") signed short cluster_owner;
	};

	nicename("Background Sound Environment Palette") struct s_background_sound_environment_palette_definition
	{
		nicename("Name") string_id name;
		nicename("Sound Environment") TagReference sound_environment;
		nicename("Unknown") signed int unknown;
		nicename("Cutoff Distance") float cutoff_distance;
		nicename("Interpolation Speed") float interpolation_speed;
		nicename("Background Sound") TagReference background_sound;
		nicename("Inside Cluster Sound") TagReference inside_cluster_sound;
		nicename("Transition In") TagReference transition_in;
		nicename("Transition Out") TagReference transition_out;
		nicename("Cutoff Distance") float cutoff_distance2;
		nicename("Scale Flags") signed int scale_flags;
		nicename("Interior Scale") float interior_scale;
		nicename("Portal Scale") float portal_scale;
		nicename("Exterior Scale") float exterior_scale;
		nicename("Interpolation Speed") float interpolation_speed2;
	};

	nicename("Marker") struct s_marker_definition
	{
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Name") char name[32];
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Rotation w") float rotation_w;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
	};

	nicename("Unknown 11") struct s_unknown_11_definition
	{
		nicename("Unknown") signed short unknown;
	};

	nicename("Runtime Decal") struct s_runtime_decal_definition
	{
		nicename("Palette Index") signed short palette_index;
		nicename("Yaw") signed char yaw;
		nicename("Pitch") signed char pitch;
		nicename("i") float i;
		nicename("j") float j;
		nicename("k") float k;
		nicename("w") float w;
		nicename("X") float x;
		nicename("Y") float y;
		nicename("Z") float z;
		nicename("Scale min") float scale_min;
		nicename("Scale max") float scale_max;
	};

	nicename("Environment Object Palette") struct s_environment_object_palette_definition
	{
		nicename("Definition") TagReference definition;
		nicename("Model") TagReference model;
		nicename("Object Type") signed int object_type;
	};

	nicename("Environment Object") struct s_environment_object_definition
	{
		nicename("Name String") char name_string[32];
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Rotation w") float rotation_w;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Scale") float scale;
		nicename("Palette Index") signed short palette_index;
		nicename("Unknown") signed short unknown;
		nicename("Unique ID") signed int unique_id;
		nicename("Scenario Object Name") char scenario_object_name[4];
		nicename("Name") string_id name;
		nicename("Unknown") signed int unknown2;
	};

	nicename("Instanced Geometry Group") struct s_instanced_geometry_group_definition
	{
		nicename("Members") struct s_member_block_definition;

		nicename("Unknown") signed int unknown;
		nicename("Members") s_tag_block_definition<s_member_block_definition> members;

		nicename("Member") struct s_member_definition
		{
			nicename("Sub Group Index") signed short sub_group_index;
		};
	};

	nicename("Instanced Geometry Sub Group") struct s_instanced_geometry_sub_group_definition
	{
		nicename("Members") struct s_member_block_definition;

		nicename("X") float x;
		nicename("Y") float y;
		nicename("Z") float z;
		nicename("Unknown") float unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Members") s_tag_block_definition<s_member_block_definition> members;

		nicename("Member") struct s_member_definition
		{
			nicename("Name Index") signed short name_index;
		};
	};

	nicename("Instanced Geometry Instance") struct s_instanced_geometry_instance_definition
	{
		nicename("Name") string_id name;
	};

	nicename("Decorator") struct s_decorator_definition
	{
		nicename("Decorator") TagReference decorator2;
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

	nicename("Unknown 30") struct s_unknown_30_definition
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

	nicename("Decal") struct s_decal_definition
	{
		nicename("Decal") unsigned int decal2;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
		nicename("Unknown") signed short unknown4;
		nicename("X") float x;
		nicename("Y") float y;
		nicename("Z") float z;
		nicename("Decal Property Index") signed short decal_property_index;
		nicename("Unknown") signed short unknown5;
	};

	nicename("Decal Property") struct s_decal_property_definition
	{
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
		nicename("Unknown") signed short unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("X") float x;
		nicename("Y") float y;
		nicename("Tile X") float tile_x;
		nicename("Tile Y") float tile_y;
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

	nicename("Unknown 30") struct s_unknown_30_definition
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

	nicename("Unknown Sound Clusters A") struct s_unknown_sound_clusters_a_definition
	{
		nicename("Portal Designators") struct s_portal_designator_block_definition;
		nicename("Interior Cluster Indices") struct s_interior_cluster_index_block_definition;

		nicename("Background Sound Environment Index") signed short background_sound_environment_index;
		nicename("Unknown") signed short unknown;
		nicename("Portal Designators") s_tag_block_definition<s_portal_designator_block_definition> portal_designators;
		nicename("Interior Cluster Indices") s_tag_block_definition<s_interior_cluster_index_block_definition> interior_cluster_indices;

		nicename("Portal Designator") struct s_portal_designator_definition
		{
			nicename("Portal Designator") signed short portal_designator2;
		};

		nicename("Interior Cluster Index") struct s_interior_cluster_index_definition
		{
			nicename("Interior Cluster Index") signed short interior_cluster_index2;
		};
	};

	nicename("Transparent Plane") struct s_transparent_plane_definition
	{
		nicename("Mesh Index") signed short mesh_index;
		nicename("Part Index") signed short part_index;
		nicename("Plane i") float plane_i;
		nicename("Plane j") float plane_j;
		nicename("Plane k") float plane_k;
		nicename("Plane d") float plane_d;
	};

	nicename("Collision MOPP Code") struct s_collision_mopp_code_definition
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

	nicename("Breakable Surface MOPP Code") struct s_breakable_surface_mopp_code_definition
	{
		nicename("Data") struct s_datum_block_definition;

		nicename("Unknown") signed int unknown;
		nicename("Size") signed short size;
		nicename("Count") signed short count;
		nicename("Offset") signed int offset;
		nicename("Unknown") unsigned int unknown2;
		nicename("Offset x") float offset_x;
		nicename("Offset y") float offset_y;
		nicename("Offset z") float offset_z;
		nicename("Offset Scale") float offset_scale;
		nicename("Unknown") unsigned int unknown3;
		nicename("Data Size") signed int data_size;
		nicename("Data Capacity") unsigned int data_capacity;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") signed char unknown5;
		nicename("Unknown") signed char unknown6;
		nicename("Unknown") signed char unknown7;
		nicename("Data") s_tag_block_definition<s_datum_block_definition> data;
		nicename("Unknown") unsigned int unknown8;

		nicename("Datum") struct s_datum_definition
		{
			nicename("Data Byte") unsigned char data_byte;
		};
	};

	nicename("Breakable Surface Key Table") struct s_breakable_surface_key_table_definition
	{
		nicename("Instanced Geometry Index") signed short instanced_geometry_index;
		nicename("Breakable Surface Index") signed char breakable_surface_index;
		nicename("Breakable Surface Sub-Index") unsigned char breakable_surface_sub_index;
		nicename("Seed Surface Index") signed int seed_surface_index;
		nicename("x0") float x0;
		nicename("x1") float x1;
		nicename("y0") float y0;
		nicename("y1") float y1;
		nicename("z0") float z0;
		nicename("z1") float z1;
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

	nicename("Unknown 30") struct s_unknown_30_definition
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
};
