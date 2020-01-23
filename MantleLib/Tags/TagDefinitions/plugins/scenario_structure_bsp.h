#pragma once

struct s_scenario_structure_bsp_definition
{
	struct s_structure_seam_block_definition;
	struct s_collision_material_block_definition;
	struct s_unknown_2_block_definition;
	struct s_unknown_3_block_definition;
	struct s_cluster_portal_block_definition;
	struct s_detail_object_block_definition;
	struct s_cluster_block_definition;
	struct s_material_block_definition;
	struct s_sky_owner_cluster_block_definition;
	struct s_background_sound_environment_palette_block_definition;
	struct s_marker_block_definition;
	struct s_unknown_11_block_definition;
	struct s_runtime_decal_block_definition;
	struct s_environment_object_palette_block_definition;
	struct s_environment_object_block_definition;
	struct s_instanced_geometry_group_block_definition;
	struct s_instanced_geometry_sub_group_block_definition;
	struct s_instanced_geometry_instance_block_definition;
	struct s_decorator_block_definition;
	struct s_mesh_block_definition;
	struct s_compression_info_block_definition;
	struct s_unknown_nodey_block_definition;
	struct s_unknown_30_block_definition;
	struct s_node_map_block_definition;
	struct s_unknown_yo_block_definition;
	struct s_water_mesh_block_definition;
	struct s_unknown_compression_info_block_definition;
	struct s_decal_block_definition;
	struct s_decal_property_block_definition;
	struct s_mesh2_block_definition;
	struct s_compression_info3_block_definition;
	struct s_unknown_nodey3_block_definition;
	struct s_unknown_30_3_block_definition;
	struct s_node_map2_block_definition;
	struct s_unknown_yo3_block_definition;
	struct s_water_mesh2_block_definition;
	struct s_unknown_compression_info3_block_definition;
	struct s_unknown_sound_clusters_a_block_definition;
	struct s_transparent_plane_block_definition;
	struct s_collision_mopp_code_block_definition;
	struct s_breakable_surface_mopp_code_block_definition;
	struct s_breakable_surface_key_table_block_definition;
	struct s_mesh3_block_definition;
	struct s_compression_info5_block_definition;
	struct s_unknown_nodey5_block_definition;
	struct s_unknown_30_5_block_definition;
	struct s_node_map3_block_definition;
	struct s_unknown_yo5_block_definition;
	struct s_water_mesh3_block_definition;
	struct s_unknown_compression_info5_block_definition;

	unsigned int unknown;
	float unknown2;
	unsigned int unknown3;
	float unknown4;
	signed int unknown5;
	signed int unknown6;
	unsigned int unknown7;
	unsigned int unknown8;
	unsigned int unknown9;
	unsigned int unknown10;
	unsigned int unknown11;
	unsigned int unknown12;
	signed int bsp_checksum;
	signed int unknown13;
	signed short unknown14;
	signed short unknown15;
	signed short unknown16;
	signed short unknown17;
	s_tag_block_definition<s_structure_seam_block_definition> structure_seams;
	unsigned int unknown18;
	unsigned int unknown19;
	unsigned int unknown20;
	s_tag_block_definition<s_collision_material_block_definition> collision_materials;
	s_tag_block_definition<s_unknown_2_block_definition> unknown_2_2;
	s_tag_block_definition<s_unknown_3_block_definition> unknown_3_2;
	unsigned int unknown21;
	unsigned int unknown22;
	unsigned int unknown23;
	unsigned int unknown24;
	unsigned int unknown25;
	unsigned int unknown26;
	unsigned int unknown27;
	unsigned int unknown28;
	unsigned int unknown29;
	signed int unknown30;
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
	float world_bounds_x_min;
	float world_bounds_x_max;
	float world_bounds_y_min;
	float world_bounds_y_max;
	float world_bounds_z_min;
	float world_bounds_z_max;
	unsigned int unknown50;
	unsigned int unknown51;
	unsigned int unknown52;
	unsigned int unknown53;
	unsigned int unknown54;
	unsigned int unknown55;
	s_tag_block_definition<s_cluster_portal_block_definition> cluster_portals;
	s_tag_block_definition<s_detail_object_block_definition> detail_objects;
	s_tag_block_definition<s_cluster_block_definition> clusters;
	s_tag_block_definition<s_material_block_definition> materials;
	s_tag_block_definition<s_sky_owner_cluster_block_definition> sky_owner_cluster2;
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
	s_tag_block_definition<s_background_sound_environment_palette_block_definition> background_sound_environment_palette2;
	DataReference unknown71;
	s_tag_block_definition<s_marker_block_definition> markers;
	unsigned int unknown72;
	unsigned int unknown73;
	unsigned int unknown74;
	s_tag_block_definition<s_unknown_11_block_definition> unknown_11_2;
	s_tag_block_definition<s_runtime_decal_block_definition> runtime_decals;
	s_tag_block_definition<s_environment_object_palette_block_definition> environment_object_palette2;
	s_tag_block_definition<s_environment_object_block_definition> environment_objects;
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
	unsigned int unknown85;
	unsigned int unknown86;
	unsigned int unknown87;
	unsigned int unknown88;
	unsigned int unknown89;
	unsigned int unknown90;
	s_tag_block_definition<s_instanced_geometry_group_block_definition> instanced_geometry_groups;
	s_tag_block_definition<s_instanced_geometry_sub_group_block_definition> instanced_geometry_sub_groups;
	unsigned int unknown91;
	unsigned int unknown92;
	unsigned int unknown93;
	s_tag_block_definition<s_instanced_geometry_instance_block_definition> instanced_geometry_instances;
	TagReference instance_geometry_impostors;
	s_tag_block_definition<s_decorator_block_definition> decorators;
	signed int unknown94;
	s_tag_block_definition<s_mesh_block_definition> meshes;
	s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	s_tag_block_definition<s_unknown_30_block_definition> unknown_30_2;
	unsigned int unknown95;
	unsigned int unknown96;
	unsigned int unknown97;
	unsigned int unknown98;
	unsigned int unknown99;
	unsigned int unknown100;
	s_tag_block_definition<s_node_map_block_definition> node_maps;
	unsigned int unknown101;
	unsigned int unknown102;
	unsigned int unknown103;
	unsigned int unknown104;
	unsigned int unknown105;
	unsigned int unknown106;
	unsigned int unknown107;
	unsigned int unknown108;
	unsigned int unknown109;
	s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	unsigned int zone_asset_datum_1;
	unsigned short easy_read_index_1;
	unsigned short easy_read_salt_1;
	signed int useless_padding;
	s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	s_tag_block_definition<s_decal_block_definition> decals;
	s_tag_block_definition<s_decal_property_block_definition> decal_properties;
	signed int unknown110;
	s_tag_block_definition<s_mesh2_block_definition> meshes2;
	s_tag_block_definition<s_compression_info3_block_definition> compression_info4;
	s_tag_block_definition<s_unknown_nodey3_block_definition> unknown_nodey4;
	s_tag_block_definition<s_unknown_30_3_block_definition> unknown_30_4;
	unsigned int unknown111;
	unsigned int unknown112;
	unsigned int unknown113;
	unsigned int unknown114;
	unsigned int unknown115;
	unsigned int unknown116;
	s_tag_block_definition<s_node_map2_block_definition> node_maps2;
	unsigned int unknown117;
	unsigned int unknown118;
	unsigned int unknown119;
	unsigned int unknown120;
	unsigned int unknown121;
	unsigned int unknown122;
	unsigned int unknown123;
	unsigned int unknown124;
	unsigned int unknown125;
	s_tag_block_definition<s_unknown_yo3_block_definition> unknown_yo4;
	s_tag_block_definition<s_water_mesh2_block_definition> water_meshes2;
	unsigned int zone_asset_datum_2;
	unsigned short easy_read_index_2;
	unsigned short easy_read_salt_2;
	signed int useless_padding2;
	s_tag_block_definition<s_unknown_compression_info3_block_definition> unknown_compression_info4;
	s_tag_block_definition<s_unknown_sound_clusters_a_block_definition> unknown_sound_clusters_a2;
	s_tag_block_definition<s_transparent_plane_block_definition> transparent_planes;
	unsigned int unknown126;
	unsigned int unknown127;
	unsigned int unknown128;
	s_tag_block_definition<s_collision_mopp_code_block_definition> collision_mopp_codes;
	unsigned int unknown129;
	float collision_bounds_min_x;
	float collision_bounds_min_y;
	float collision_bounds_min_z;
	float collision_bounds_max_x;
	float collision_bounds_max_y;
	float collision_bounds_max_z;
	s_tag_block_definition<s_breakable_surface_mopp_code_block_definition> breakable_surface_mopp_codes;
	s_tag_block_definition<s_breakable_surface_key_table_block_definition> breakable_surface_key_table2;
	unsigned int unknown130;
	unsigned int unknown131;
	unsigned int unknown132;
	signed int unknown133;
	s_tag_block_definition<s_mesh3_block_definition> meshes3;
	s_tag_block_definition<s_compression_info5_block_definition> compression_info6;
	s_tag_block_definition<s_unknown_nodey5_block_definition> unknown_nodey6;
	s_tag_block_definition<s_unknown_30_5_block_definition> unknown_30_6;
	unsigned int unknown134;
	unsigned int unknown135;
	unsigned int unknown136;
	unsigned int unknown137;
	unsigned int unknown138;
	unsigned int unknown139;
	s_tag_block_definition<s_node_map3_block_definition> node_maps3;
	unsigned int unknown140;
	unsigned int unknown141;
	unsigned int unknown142;
	unsigned int unknown143;
	unsigned int unknown144;
	unsigned int unknown145;
	unsigned int unknown146;
	unsigned int unknown147;
	unsigned int unknown148;
	s_tag_block_definition<s_unknown_yo5_block_definition> unknown_yo6;
	s_tag_block_definition<s_water_mesh3_block_definition> water_meshes3;
	unsigned int zone_asset_datum_3;
	unsigned short easy_read_index_3;
	unsigned short easy_read_salt_3;
	signed int useless_padding3;
	s_tag_block_definition<s_unknown_compression_info5_block_definition> unknown_compression_info6;
	unsigned int unknown149;
	unsigned int unknown150;
	unsigned int unknown151;
	unsigned int unknown152;
	unsigned int unknown153;
	unsigned int unknown154;
	unsigned int unknown155;
	unsigned int unknown156;
	unsigned int unknown157;
	unsigned int zone_asset_datum_4;
	unsigned short easy_read_index_4;
	unsigned short easy_read_salt_4;
	signed int useless_padding4;
	unsigned int zone_asset_datum_5;
	unsigned short easy_read_index_5;
	unsigned short easy_read_salt_5;
	signed int useless_padding5;
	signed int unknown158;

	struct s_structure_seam_definition
	{
		struct s_unknown5_block_definition;
		struct s_seam_cluster_block_definition;

		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		s_tag_block_definition<s_unknown5_block_definition> unknown6;
		s_tag_block_definition<s_seam_cluster_block_definition> seam_clusters;

		struct s_unknown_definition
		{
			signed int unknown2;
		};

		struct s_seam_cluster_definition
		{
			signed int cluster_index;
			float centroid_x;
			float centroid_y;
			float centroid_z;
		};
	};

	struct s_collision_material_definition
	{
		TagReference shader;
		signed short global_material_index;
		signed short conveyor_surface_index;
		signed short seam_index;
		signed short unknown;
	};

	struct s_unknown_2_definition
	{
		unsigned char unknown;
	};

	struct s_unknown_3_definition
	{
		float unknown;
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
	};

	struct s_cluster_portal_definition
	{
		struct s_vertex_block_definition;

		float x;
		float y;
		float z;
		float unknown;
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		signed short back_cluster;
		signed short front_cluster;
		signed int plane_index;
		float centroid_x;
		float centroid_y;
		float centroid_z;
		float bounding_radius;
		signed int flags;
		s_tag_block_definition<s_vertex_block_definition> vertices;

		struct s_vertex_definition
		{
			float x;
			float y;
			float z;
		};
	};

	struct s_detail_object_definition
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
	};

	struct s_cluster_definition
	{
		struct s_portal_block_definition;
		struct s_seam_block_definition;
		struct s_decorator_grid_block_definition;
		struct s_unknown_10_block_definition;
		struct s_unknown_11_block_definition;

		float bounds_x_min;
		float bounds_x_max;
		float bounds_y_min;
		float bounds_y_max;
		float bounds_z_min;
		float bounds_z_max;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		signed short unknown5;
		signed short unknown6;
		signed short runtime_decal_start_index;
		signed short runtime_decal_entry_count;
		signed short unknown7;
		signed short unknown8;
		signed short unknown9;
		signed short unknown10;
		signed short unknown11;
		signed short unknown12;
		unsigned int unknown13;
		s_tag_block_definition<s_portal_block_definition> portals;
		signed short mesh_index;
		signed short unknown14;
		s_tag_block_definition<s_seam_block_definition> seams;
		s_tag_block_definition<s_decorator_grid_block_definition> decorator_grids;
		unsigned int unknown15;
		unsigned int unknown16;
		unsigned int unknown17;
		unsigned int unknown18;
		unsigned int unknown19;
		unsigned int unknown20;
		s_tag_block_definition<s_unknown_10_block_definition> unknown_10_2;
		s_tag_block_definition<s_unknown_11_block_definition> unknown_11_2;

		struct s_portal_definition
		{
			signed short portal_index;
		};

		struct s_seam_definition
		{
			signed char seam_index;
		};

		struct s_decorator_grid_definition
		{
			struct s_unknown2_block_definition;

			signed short amount;
			signed char decorator_index;
			signed char decorator_index___scattering;
			signed int unknown;
			float position_x;
			float position_y;
			float position_z;
			float radius;
			float grid_size_x;
			float grid_size_y;
			float grid_size_z;
			float bounding_sphere_x;
			float bounding_sphere_y;
			float bounding_sphere_z;
			s_tag_block_definition<s_unknown2_block_definition> unknown3;

			struct s_unknown_definition
			{
				unsigned int unknown2;
				unsigned int unknown3;
			};
		};

		struct s_unknown_10_definition
		{
			unsigned int unknown;
		};

		struct s_unknown_11_definition
		{
			struct s_unknown_12_block_definition;

			signed short unknown;
			signed short unknown2;
			s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;

			struct s_unknown_12_definition
			{
				float unknown;
				float unknown2;
				float unknown3;
				unsigned int unknown4;
			};
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

	struct s_sky_owner_cluster_definition
	{
		signed short cluster_owner;
	};

	struct s_background_sound_environment_palette_definition
	{
		string_id name;
		TagReference sound_environment;
		signed int unknown;
		float cutoff_distance;
		float interpolation_speed;
		TagReference background_sound;
		TagReference inside_cluster_sound;
		TagReference transition_in;
		TagReference transition_out;
		float cutoff_distance2;
		signed int scale_flags;
		float interior_scale;
		float portal_scale;
		float exterior_scale;
		float interpolation_speed2;
	};

	struct s_marker_definition
	{
		signed short unknown;
		signed short unknown2;
		char name[32];
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float rotation_w;
		float position_x;
		float position_y;
		float position_z;
	};

	struct s_unknown_11_definition
	{
		signed short unknown;
	};

	struct s_runtime_decal_definition
	{
		signed short palette_index;
		signed char yaw;
		signed char pitch;
		float i;
		float j;
		float k;
		float w;
		float x;
		float y;
		float z;
		float scale_min;
		float scale_max;
	};

	struct s_environment_object_palette_definition
	{
		TagReference definition;
		TagReference model;
		signed int object_type;
	};

	struct s_environment_object_definition
	{
		char name_string[32];
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float rotation_w;
		float position_x;
		float position_y;
		float position_z;
		float scale;
		signed short palette_index;
		signed short unknown;
		signed int unique_id;
		char scenario_object_name[4];
		string_id name;
		signed int unknown2;
	};

	struct s_instanced_geometry_group_definition
	{
		struct s_member_block_definition;

		signed int unknown;
		s_tag_block_definition<s_member_block_definition> members;

		struct s_member_definition
		{
			signed short sub_group_index;
		};
	};

	struct s_instanced_geometry_sub_group_definition
	{
		struct s_member_block_definition;

		float x;
		float y;
		float z;
		float unknown;
		signed short unknown2;
		signed short unknown3;
		float unknown4;
		float unknown5;
		s_tag_block_definition<s_member_block_definition> members;

		struct s_member_definition
		{
			signed short name_index;
		};
	};

	struct s_instanced_geometry_instance_definition
	{
		string_id name;
	};

	struct s_decorator_definition
	{
		TagReference decorator2;
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

	struct s_unknown_30_definition
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

	struct s_decal_definition
	{
		unsigned int decal2;
		signed short unknown;
		signed short unknown2;
		signed short unknown3;
		signed short unknown4;
		float x;
		float y;
		float z;
		signed short decal_property_index;
		signed short unknown5;
	};

	struct s_decal_property_definition
	{
		signed short unknown;
		signed short unknown2;
		signed short unknown3;
		signed short unknown4;
		unsigned int unknown5;
		float x;
		float y;
		float tile_x;
		float tile_y;
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

	struct s_unknown_30_definition
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

	struct s_unknown_sound_clusters_a_definition
	{
		struct s_portal_designator_block_definition;
		struct s_interior_cluster_index_block_definition;

		signed short background_sound_environment_index;
		signed short unknown;
		s_tag_block_definition<s_portal_designator_block_definition> portal_designators;
		s_tag_block_definition<s_interior_cluster_index_block_definition> interior_cluster_indices;

		struct s_portal_designator_definition
		{
			signed short portal_designator2;
		};

		struct s_interior_cluster_index_definition
		{
			signed short interior_cluster_index2;
		};
	};

	struct s_transparent_plane_definition
	{
		signed short mesh_index;
		signed short part_index;
		float plane_i;
		float plane_j;
		float plane_k;
		float plane_d;
	};

	struct s_collision_mopp_code_definition
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

	struct s_breakable_surface_mopp_code_definition
	{
		struct s_datum_block_definition;

		signed int unknown;
		signed short size;
		signed short count;
		signed int offset;
		unsigned int unknown2;
		float offset_x;
		float offset_y;
		float offset_z;
		float offset_scale;
		unsigned int unknown3;
		signed int data_size;
		unsigned int data_capacity;
		signed char unknown4;
		signed char unknown5;
		signed char unknown6;
		signed char unknown7;
		s_tag_block_definition<s_datum_block_definition> data;
		unsigned int unknown8;

		struct s_datum_definition
		{
			unsigned char data_byte;
		};
	};

	struct s_breakable_surface_key_table_definition
	{
		signed short instanced_geometry_index;
		signed char breakable_surface_index;
		unsigned char breakable_surface_sub_index;
		signed int seed_surface_index;
		float x0;
		float x1;
		float y0;
		float y1;
		float z0;
		float z1;
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

	struct s_unknown_30_definition
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
};
