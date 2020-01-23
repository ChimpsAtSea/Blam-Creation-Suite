#pragma once

struct nicename("Structure Design") group('sddt') s_structure_design_definition
{
	struct nicename("Design MOPP Codes") s_design_mopp_code_block_definition;
	struct nicename("Design Shapes 2") s_design_shapes_2_block_definition;
	struct nicename("Water MOPP Codes") s_water_mopp_code_block_definition;
	struct nicename("Water Names") s_water_name_block_definition;
	struct nicename("Underwater Definitions") s_underwater_definition_block_definition;
	struct nicename("Planar Fog") s_planar_fog_block_definition;
	struct s_unknown_mopp_code_block_definition;
	struct nicename("Meshes") s_mesh_block_definition;
	struct nicename("Compression Info") s_compression_info_block_definition;
	struct s_unknown_nodey_block_definition;
	struct s_unknown_8_block_definition;
	struct nicename("Node Maps") s_node_map_block_definition;
	struct s_unknown_yo_block_definition;
	struct nicename("Water Meshes") s_water_mesh_block_definition;
	struct s_unknown_compression_info_block_definition;
	struct s_unknown_7_block_definition;
	struct nicename("Instanced Geometry Instances") s_instanced_geometry_instance_block_definition;
	struct nicename("Materials") s_material_block_definition;

	Undefined32 __unknown; 
	Undefined32 __unknown2; 
	Undefined32 __unknown3; 
	Undefined32 __unknown4; 
	int32_t __unknown5; 
	int32_t __unknown6; 
	Undefined32 __unknown7; 
	Undefined32 __unknown8; 
	Undefined32 __unknown9; 
	Undefined32 __unknown10; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	int32_t __unknown13; 
	s_tag_block_definition<s_design_mopp_code_block_definition> nicename("Design MOPP Codes") design_mopp_codes_block; 
	s_tag_block_definition<s_design_shapes_2_block_definition> nicename("Design Shapes 2") design_shapes_2_block; 
	s_tag_block_definition<s_water_mopp_code_block_definition> nicename("Water MOPP Codes") water_mopp_codes_block; 
	s_tag_block_definition<s_water_name_block_definition> nicename("Water Names") water_names_block; 
	s_tag_block_definition<s_underwater_definition_block_definition> nicename("Underwater Definitions") underwater_definitions_block; 
	s_tag_block_definition<s_planar_fog_block_definition> nicename("Planar Fog") planar_fog_block; 
	s_tag_block_definition<s_unknown_mopp_code_block_definition> __unknown_mopp_codes_block; 
	int32_t __unknown14; 
	s_tag_block_definition<s_mesh_block_definition> nicename("Meshes") meshes_block; 
	s_tag_block_definition<s_compression_info_block_definition> nicename("Compression Info") compression_info_block; 
	s_tag_block_definition<s_unknown_nodey_block_definition> __unknown_nodey_block; 
	s_tag_block_definition<s_unknown_8_block_definition> __unknown_8_block; 
	Undefined32 __unknown15; 
	Undefined32 __unknown16; 
	Undefined32 __unknown17; 
	Undefined32 __unknown18; 
	Undefined32 __unknown19; 
	Undefined32 __unknown20; 
	s_tag_block_definition<s_node_map_block_definition> nicename("Node Maps") node_maps_block; 
	Undefined32 __unknown21; 
	Undefined32 __unknown22; 
	Undefined32 __unknown23; 
	Undefined32 __unknown24; 
	Undefined32 __unknown25; 
	Undefined32 __unknown26; 
	Undefined32 __unknown27; 
	Undefined32 __unknown28; 
	Undefined32 __unknown29; 
	s_tag_block_definition<s_unknown_yo_block_definition> __unknown_yo_block; 
	s_tag_block_definition<s_water_mesh_block_definition> nicename("Water Meshes") water_meshes_block; 
	int32_t nicename("[zone] Asset Datum") zone_asset_datum; 
	uint16_t nicename("[easy read] Index") easy_read_index; 
	uint16_t nicename("[easy read] Salt") easy_read_salt; 
	int32_t nicename("Useless Padding") useless_padding; 
	s_tag_block_definition<s_unknown_compression_info_block_definition> __unknown_compression_info_block; 
	s_tag_block_definition<s_unknown_7_block_definition> __unknown_7_block; 
	s_tag_block_definition<s_instanced_geometry_instance_block_definition> nicename("Instanced Geometry Instances") instanced_geometry_instances_block; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	Undefined32 __unknown30; 
	Undefined32 __unknown31; 
	Undefined32 __unknown32; 

	struct nicename("design_mopp_code") s_design_mopp_code_block_definition
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

	struct nicename("design_shapes_2") s_design_shapes_2_block_definition
	{
		struct s_unknown_2_block_definition;

		string_id nicename("Name") name; 
		int16_t __unknown; 
		int16_t __unknown2; 
		s_tag_block_definition<s_unknown_2_block_definition> __unknown_2_block; 

		struct s_unknown_2_block_definition
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
		};
	};

	struct nicename("water_mopp_code") s_water_mopp_code_block_definition
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

	struct nicename("water_name") s_water_name_block_definition
	{
		string_id nicename("Name") name; 
	};

	struct nicename("underwater_definition") s_underwater_definition_block_definition
	{
		struct s_unknown_block_definition;

		int16_t nicename("Water Name Index") water_name_index; 
		int16_t __unknown; 
		float nicename("Flow Force x") flow_force_x; 
		float nicename("Flow Force y") flow_force_y; 
		float nicename("Flow Force z") flow_force_z; 
		float nicename("Flow Force z 2") flow_force_z_2; 
		float nicename("Mask Color r") mask_color_r; 
		float nicename("Mask Color g") mask_color_g; 
		float nicename("Mask Color b") mask_color_b; 
		float nicename("Obscure Amount") obscure_amount; 
		s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __x_min; 
		Undefined32 __x_max; 
		Undefined32 __y_min; 
		Undefined32 __y_max; 
		Undefined32 __z_min; 
		Undefined32 __z_max; 

		struct s_unknown_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
		};
	};

	struct nicename("planar_fog") s_planar_fog_block_definition
	{
		struct s_unknown_block_definition;
		struct s_unknown2_block_definition;

		string_id nicename("Name") name; 
		TagReference nicename("Planar Fog Parameters") planar_fog_parameters_reference; 
		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 

		struct s_unknown_block_definition
		{
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
		};

		struct s_unknown2_block_definition
		{
			struct s_unknown_block_definition;

			s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

			struct s_unknown_block_definition
			{
				Undefined32 __unknown; 
				Undefined32 __unknown2; 
				Undefined32 __unknown3; 
				Undefined32 __unknown4; 
			};
		};
	};

	struct s_unknown_mopp_code_block_definition
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

	struct s_unknown_7_block_definition
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
		int16_t __unknown81; 
		int16_t __unknown82; 
	};

	struct nicename("instanced_geometry_instance") s_instanced_geometry_instance_block_definition
	{
		float nicename("Scale") scale; 
		float nicename("Forward i") forward_i; 
		float nicename("Forward j") forward_j; 
		float nicename("Forward k") forward_k; 
		float nicename("Left i") left_i; 
		float nicename("Left j") left_j; 
		float nicename("Left k") left_k; 
		float nicename("Up i") up_i; 
		float nicename("Up j") up_j; 
		float nicename("Up k") up_k; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		int16_t nicename("Mesh Index") mesh_index; 
		uint16_t nicename("Flags") flags; 
		int16_t __unknown; 
		int16_t __unknown2; 
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
		float nicename("Bounding Sphere x") bounding_sphere_x; 
		float nicename("Bounding Sphere y") bounding_sphere_y; 
		float nicename("Bounding Sphere z") bounding_sphere_z; 
		float nicename("Bounding Sphere Radius1") bounding_sphere_radius1; 
		float __unknown13; 
		float nicename("Bounding Sphere Radius2") bounding_sphere_radius2; 
		int8_t __unknown14; 
		int8_t __unknown15; 
		int8_t __unknown16; 
		int8_t __unknown17; 
		float __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 
		Undefined32 __unknown22; 
		Undefined32 __unknown23; 
		Undefined32 __unknown24; 
		string_id nicename("Name") name; 
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
};
