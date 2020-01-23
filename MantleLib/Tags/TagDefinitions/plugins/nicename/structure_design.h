#pragma once

nicename("structure_design") struct s_structure_design_definition
{
	nicename("Design MOPP Codes") struct s_design_mopp_code_block_definition;
	nicename("Design Shapes 2") struct s_design_shapes_2_block_definition;
	nicename("Water MOPP Codes") struct s_water_mopp_code_block_definition;
	nicename("Water Names") struct s_water_name_block_definition;
	nicename("Underwater Definitions") struct s_underwater_definition_block_definition;
	nicename("Planar Fog") struct s_planar_fog_block_definition;
	nicename("Unknown MOPP Codes") struct s_unknown_mopp_code_block_definition;
	nicename("Meshes") struct s_mesh_block_definition;
	nicename("Compression Info") struct s_compression_info_block_definition;
	nicename("Unknown Nodey") struct s_unknown_nodey_block_definition;
	nicename("Unknown 8") struct s_unknown_8_block_definition;
	nicename("Node Maps") struct s_node_map_block_definition;
	nicename("Unknown Yo") struct s_unknown_yo_block_definition;
	nicename("Water Meshes") struct s_water_mesh_block_definition;
	nicename("Unknown Compression Info") struct s_unknown_compression_info_block_definition;
	nicename("Unknown 7") struct s_unknown_7_block_definition;
	nicename("Instanced Geometry Instances") struct s_instanced_geometry_instance_block_definition;
	nicename("Materials") struct s_material_block_definition;

	nicename("Unknown") unsigned int unknown;
	nicename("Unknown") unsigned int unknown2;
	nicename("Unknown") unsigned int unknown3;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") signed int unknown5;
	nicename("Unknown") signed int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") unsigned int unknown9;
	nicename("Unknown") unsigned int unknown10;
	nicename("Unknown") unsigned int unknown11;
	nicename("Unknown") unsigned int unknown12;
	nicename("Unknown") signed int unknown13;
	nicename("Design MOPP Codes") s_tag_block_definition<s_design_mopp_code_block_definition> design_mopp_codes;
	nicename("Design Shapes 2") s_tag_block_definition<s_design_shapes_2_block_definition> design_shapes_2_2;
	nicename("Water MOPP Codes") s_tag_block_definition<s_water_mopp_code_block_definition> water_mopp_codes;
	nicename("Water Names") s_tag_block_definition<s_water_name_block_definition> water_names;
	nicename("Underwater Definitions") s_tag_block_definition<s_underwater_definition_block_definition> underwater_definitions;
	nicename("Planar Fog") s_tag_block_definition<s_planar_fog_block_definition> planar_fog2;
	nicename("Unknown MOPP Codes") s_tag_block_definition<s_unknown_mopp_code_block_definition> unknown_mopp_codes;
	nicename("Unknown") signed int unknown14;
	nicename("Meshes") s_tag_block_definition<s_mesh_block_definition> meshes;
	nicename("Compression Info") s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	nicename("Unknown Nodey") s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	nicename("Unknown 8") s_tag_block_definition<s_unknown_8_block_definition> unknown_8_2;
	nicename("Unknown") unsigned int unknown15;
	nicename("Unknown") unsigned int unknown16;
	nicename("Unknown") unsigned int unknown17;
	nicename("Unknown") unsigned int unknown18;
	nicename("Unknown") unsigned int unknown19;
	nicename("Unknown") unsigned int unknown20;
	nicename("Node Maps") s_tag_block_definition<s_node_map_block_definition> node_maps;
	nicename("Unknown") unsigned int unknown21;
	nicename("Unknown") unsigned int unknown22;
	nicename("Unknown") unsigned int unknown23;
	nicename("Unknown") unsigned int unknown24;
	nicename("Unknown") unsigned int unknown25;
	nicename("Unknown") unsigned int unknown26;
	nicename("Unknown") unsigned int unknown27;
	nicename("Unknown") unsigned int unknown28;
	nicename("Unknown") unsigned int unknown29;
	nicename("Unknown Yo") s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	nicename("Water Meshes") s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
	nicename("[easy read] Index") unsigned short easy_read_index;
	nicename("[easy read] Salt") unsigned short easy_read_salt;
	nicename("Useless Padding") signed int useless_padding;
	nicename("Unknown Compression Info") s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	nicename("Unknown 7") s_tag_block_definition<s_unknown_7_block_definition> unknown_7_2;
	nicename("Instanced Geometry Instances") s_tag_block_definition<s_instanced_geometry_instance_block_definition> instanced_geometry_instances;
	nicename("Materials") s_tag_block_definition<s_material_block_definition> materials;
	nicename("Unknown") unsigned int unknown30;
	nicename("Unknown") unsigned int unknown31;
	nicename("Unknown") unsigned int unknown32;

	nicename("Design MOPP Code") struct s_design_mopp_code_definition
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

	nicename("Design Shapes 2") struct s_design_shapes_2_definition
	{
		nicename("Unknown 2") struct s_unknown_2_block_definition;

		nicename("Name") string_id name;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown 2") s_tag_block_definition<s_unknown_2_block_definition> unknown_2_2;

		nicename("Unknown 2") struct s_unknown_2_definition
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
		};
	};

	nicename("Water MOPP Code") struct s_water_mopp_code_definition
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

	nicename("Water Name") struct s_water_name_definition
	{
		nicename("Name") string_id name;
	};

	nicename("Underwater Definition") struct s_underwater_definition_definition
	{
		nicename("Unknown") struct s_unknown2_block_definition;

		nicename("Water Name Index") signed short water_name_index;
		nicename("Unknown") signed short unknown;
		nicename("Flow Force x") float flow_force_x;
		nicename("Flow Force y") float flow_force_y;
		nicename("Flow Force z") float flow_force_z;
		nicename("Flow Force z 2") float flow_force_z_2;
		nicename("Mask Color r") float mask_color_r;
		nicename("Mask Color g") float mask_color_g;
		nicename("Mask Color b") float mask_color_b;
		nicename("Obscure Amount") float obscure_amount;
		nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("X Min") unsigned int x_min;
		nicename("X Max") unsigned int x_max;
		nicename("Y Min") unsigned int y_min;
		nicename("Y Max") unsigned int y_max;
		nicename("Z Min") unsigned int z_min;
		nicename("Z Max") unsigned int z_max;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") float unknown5;
		};
	};

	nicename("Planar Fog") struct s_planar_fog_definition
	{
		nicename("Unknown") struct s_unknown_block_definition;
		nicename("Unknown") struct s_unknown3_block_definition;

		nicename("Name") string_id name;
		nicename("Planar Fog Parameters") TagReference planar_fog_parameters;
		nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
		nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") struct s_unknown2_block_definition;

			nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") unsigned int unknown2;
				nicename("Unknown") unsigned int unknown3;
				nicename("Unknown") unsigned int unknown4;
				nicename("Unknown") unsigned int unknown5;
			};
		};
	};

	nicename("Unknown MOPP Code") struct s_unknown_mopp_code_definition
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

	nicename("Unknown 7") struct s_unknown_7_definition
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
		nicename("Unknown") signed short unknown81;
		nicename("Unknown") signed short unknown82;
	};

	nicename("Instanced Geometry Instance") struct s_instanced_geometry_instance_definition
	{
		nicename("Scale") float scale;
		nicename("Forward i") float forward_i;
		nicename("Forward j") float forward_j;
		nicename("Forward k") float forward_k;
		nicename("Left i") float left_i;
		nicename("Left j") float left_j;
		nicename("Left k") float left_k;
		nicename("Up i") float up_i;
		nicename("Up j") float up_j;
		nicename("Up k") float up_k;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Mesh Index") signed short mesh_index;
		nicename("Flags") unsigned short flags;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
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
		nicename("Bounding Sphere x") float bounding_sphere_x;
		nicename("Bounding Sphere y") float bounding_sphere_y;
		nicename("Bounding Sphere z") float bounding_sphere_z;
		nicename("Bounding Sphere Radius1") float bounding_sphere_radius1;
		nicename("Unknown") float unknown13;
		nicename("Bounding Sphere Radius2") float bounding_sphere_radius2;
		nicename("Unknown") signed char unknown14;
		nicename("Unknown") signed char unknown15;
		nicename("Unknown") signed char unknown16;
		nicename("Unknown") signed char unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") unsigned int unknown20;
		nicename("Unknown") unsigned int unknown21;
		nicename("Unknown") unsigned int unknown22;
		nicename("Unknown") unsigned int unknown23;
		nicename("Unknown") unsigned int unknown24;
		nicename("Name") string_id name;
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
};
