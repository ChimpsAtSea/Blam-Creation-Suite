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

	Unknown32 __unknown; 
	Unknown32 __unknown2; 
	Unknown32 __unknown3; 
	Unknown32 __unknown4; 
	signed int __unknown5; 
	signed int __unknown6; 
	Unknown32 __unknown7; 
	Unknown32 __unknown8; 
	Unknown32 __unknown9; 
	Unknown32 __unknown10; 
	Unknown32 __unknown11; 
	Unknown32 __unknown12; 
	signed int __unknown13; 
	s_tag_block_definition<s_design_mopp_code_block_definition> nicename("Design MOPP Codes") design_mopp_codes_block; 
	s_tag_block_definition<s_design_shapes_2_block_definition> nicename("Design Shapes 2") design_shapes_2_block; 
	s_tag_block_definition<s_water_mopp_code_block_definition> nicename("Water MOPP Codes") water_mopp_codes_block; 
	s_tag_block_definition<s_water_name_block_definition> nicename("Water Names") water_names_block; 
	s_tag_block_definition<s_underwater_definition_block_definition> nicename("Underwater Definitions") underwater_definitions_block; 
	s_tag_block_definition<s_planar_fog_block_definition> nicename("Planar Fog") planar_fog_block; 
	s_tag_block_definition<s_unknown_mopp_code_block_definition> __unknown_mopp_codes_block; 
	signed int __unknown14; 
	s_tag_block_definition<s_mesh_block_definition> nicename("Meshes") meshes_block; 
	s_tag_block_definition<s_compression_info_block_definition> nicename("Compression Info") compression_info_block; 
	s_tag_block_definition<s_unknown_nodey_block_definition> __unknown_nodey_block; 
	s_tag_block_definition<s_unknown_8_block_definition> __unknown_8_block; 
	Unknown32 __unknown15; 
	Unknown32 __unknown16; 
	Unknown32 __unknown17; 
	Unknown32 __unknown18; 
	Unknown32 __unknown19; 
	Unknown32 __unknown20; 
	s_tag_block_definition<s_node_map_block_definition> nicename("Node Maps") node_maps_block; 
	Unknown32 __unknown21; 
	Unknown32 __unknown22; 
	Unknown32 __unknown23; 
	Unknown32 __unknown24; 
	Unknown32 __unknown25; 
	Unknown32 __unknown26; 
	Unknown32 __unknown27; 
	Unknown32 __unknown28; 
	Unknown32 __unknown29; 
	s_tag_block_definition<s_unknown_yo_block_definition> __unknown_yo_block; 
	s_tag_block_definition<s_water_mesh_block_definition> nicename("Water Meshes") water_meshes_block; 
	signed int nicename("[zone] Asset Datum") zone_asset_datum; 
	unsigned short nicename("[easy read] Index") easy_read_index; 
	unsigned short nicename("[easy read] Salt") easy_read_salt; 
	signed int nicename("Useless Padding") useless_padding; 
	s_tag_block_definition<s_unknown_compression_info_block_definition> __unknown_compression_info_block; 
	s_tag_block_definition<s_unknown_7_block_definition> __unknown_7_block; 
	s_tag_block_definition<s_instanced_geometry_instance_block_definition> nicename("Instanced Geometry Instances") instanced_geometry_instances_block; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	Unknown32 __unknown30; 
	Unknown32 __unknown31; 
	Unknown32 __unknown32; 

	struct nicename("design_mopp_code") s_design_mopp_code_block_definition
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

	struct nicename("design_shapes_2") s_design_shapes_2_block_definition
	{
		struct s_unknown_2_block_definition;

		string_id nicename("Name") name; 
		signed short __unknown; 
		signed short __unknown2; 
		s_tag_block_definition<s_unknown_2_block_definition> __unknown_2_block; 

		struct s_unknown_2_block_definition
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
			Unknown32 __unknown14; 
			Unknown32 __unknown15; 
			Unknown32 __unknown16; 
			Unknown32 __unknown17; 
		};
	};

	struct nicename("water_mopp_code") s_water_mopp_code_block_definition
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

	struct nicename("water_name") s_water_name_block_definition
	{
		string_id nicename("Name") name; 
	};

	struct nicename("underwater_definition") s_underwater_definition_block_definition
	{
		struct s_unknown_block_definition;

		signed short nicename("Water Name Index") water_name_index; 
		signed short __unknown; 
		float nicename("Flow Force x") flow_force_x; 
		float nicename("Flow Force y") flow_force_y; 
		float nicename("Flow Force z") flow_force_z; 
		float nicename("Flow Force z 2") flow_force_z_2; 
		float nicename("Mask Color r") mask_color_r; 
		float nicename("Mask Color g") mask_color_g; 
		float nicename("Mask Color b") mask_color_b; 
		float nicename("Obscure Amount") obscure_amount; 
		s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __x_min; 
		Unknown32 __x_max; 
		Unknown32 __y_min; 
		Unknown32 __y_max; 
		Unknown32 __z_min; 
		Unknown32 __z_max; 

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
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 

		struct s_unknown_block_definition
		{
			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			Unknown32 __unknown3; 
		};

		struct s_unknown2_block_definition
		{
			struct s_unknown_block_definition;

			s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

			struct s_unknown_block_definition
			{
				Unknown32 __unknown; 
				Unknown32 __unknown2; 
				Unknown32 __unknown3; 
				Unknown32 __unknown4; 
			};
		};
	};

	struct s_unknown_mopp_code_block_definition
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

	struct s_unknown_8_block_definition
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

	struct s_unknown_7_block_definition
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
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		Unknown32 __unknown16; 
		Unknown32 __unknown17; 
		Unknown32 __unknown18; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
		Unknown32 __unknown23; 
		Unknown32 __unknown24; 
		Unknown32 __unknown25; 
		Unknown32 __unknown26; 
		Unknown32 __unknown27; 
		Unknown32 __unknown28; 
		Unknown32 __unknown29; 
		Unknown32 __unknown30; 
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
		Unknown32 __unknown50; 
		Unknown32 __unknown51; 
		Unknown32 __unknown52; 
		Unknown32 __unknown53; 
		Unknown32 __unknown54; 
		Unknown32 __unknown55; 
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
		Unknown32 __unknown71; 
		Unknown32 __unknown72; 
		Unknown32 __unknown73; 
		Unknown32 __unknown74; 
		Unknown32 __unknown75; 
		Unknown32 __unknown76; 
		Unknown32 __unknown77; 
		Unknown32 __unknown78; 
		Unknown32 __unknown79; 
		Unknown32 __unknown80; 
		signed short __unknown81; 
		signed short __unknown82; 
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
		signed short nicename("Mesh Index") mesh_index; 
		unsigned short nicename("Flags") flags; 
		signed short __unknown; 
		signed short __unknown2; 
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
		float nicename("Bounding Sphere x") bounding_sphere_x; 
		float nicename("Bounding Sphere y") bounding_sphere_y; 
		float nicename("Bounding Sphere z") bounding_sphere_z; 
		float nicename("Bounding Sphere Radius1") bounding_sphere_radius1; 
		float __unknown13; 
		float nicename("Bounding Sphere Radius2") bounding_sphere_radius2; 
		signed char __unknown14; 
		signed char __unknown15; 
		signed char __unknown16; 
		signed char __unknown17; 
		float __unknown18; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
		Unknown32 __unknown23; 
		Unknown32 __unknown24; 
		string_id nicename("Name") name; 
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
};
