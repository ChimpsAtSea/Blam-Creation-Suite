#pragma once

nicename("particle_model") struct s_particle_model_definition
{
	nicename("Meshes") struct s_mesh_block_definition;
	nicename("Compression Info") struct s_compression_info_block_definition;
	nicename("Unknown Nodey") struct s_unknown_nodey_block_definition;
	nicename("Unknown 8") struct s_unknown_8_block_definition;
	nicename("Node Maps") struct s_node_map_block_definition;
	nicename("Unknown Yo") struct s_unknown_yo_block_definition;
	nicename("Water Meshes") struct s_water_mesh_block_definition;
	nicename("Unknown Compression Info") struct s_unknown_compression_info_block_definition;
	nicename("Unknown 2") struct s_unknown_2_block_definition;

	nicename("Unknown") signed int unknown;
	nicename("Meshes") s_tag_block_definition<s_mesh_block_definition> meshes;
	nicename("Compression Info") s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	nicename("Unknown Nodey") s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	nicename("Unknown 8") s_tag_block_definition<s_unknown_8_block_definition> unknown_8_2;
	nicename("Unknown") unsigned int unknown2;
	nicename("Unknown") unsigned int unknown3;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") unsigned int unknown5;
	nicename("Unknown") unsigned int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Node Maps") s_tag_block_definition<s_node_map_block_definition> node_maps;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") unsigned int unknown9;
	nicename("Unknown") unsigned int unknown10;
	nicename("Unknown") unsigned int unknown11;
	nicename("Unknown") unsigned int unknown12;
	nicename("Unknown") unsigned int unknown13;
	nicename("Unknown") unsigned int unknown14;
	nicename("Unknown") unsigned int unknown15;
	nicename("Unknown") unsigned int unknown16;
	nicename("Unknown Yo") s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	nicename("Water Meshes") s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
	nicename("[easy read] Index") unsigned short easy_read_index;
	nicename("[easy read] Salt") unsigned short easy_read_salt;
	nicename("Useless Padding") signed int useless_padding;
	nicename("Unknown Compression Info") s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	nicename("Unknown 2") s_tag_block_definition<s_unknown_2_block_definition> unknown_2_2;

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

	nicename("Unknown 2") struct s_unknown_2_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
	};
};
