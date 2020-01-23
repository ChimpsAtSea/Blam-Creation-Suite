#pragma once

struct s_scenario_lightmap_bsp_data_definition
{
	struct s_unknown_a_block_definition;
	struct s_unknown_b_block_definition;
	struct s_instanced_geometry_block_definition;
	struct s_color_block_definition;
	struct s_mesh_block_definition;
	struct s_compression_info_block_definition;
	struct s_unknown_nodey_block_definition;
	struct s_unknown_7_block_definition;
	struct s_node_map_block_definition;
	struct s_unknown_yo_block_definition;
	struct s_water_mesh_block_definition;
	struct s_unknown_compression_info_block_definition;
	struct s_unknown_10_block_definition;
	struct s_airprobe_block_definition;
	struct s_unknown_12_block_definition;
	struct s_unknown_13_block_definition;
	struct s_compile_datum_block_definition;

	signed short unknown;
	signed short bsp_index;
	signed int structure_checksum;
	TagReference unknown2;
	float brightness;
	TagReference primary_map;
	TagReference intensity_map;
	unsigned int unknown3;
	unsigned int unknown4;
	unsigned int unknown5;
	s_tag_block_definition<s_unknown_a_block_definition> unknown_a2;
	s_tag_block_definition<s_unknown_b_block_definition> unknown_b2;
	s_tag_block_definition<s_instanced_geometry_block_definition> instanced_geometry2;
	s_tag_block_definition<s_color_block_definition> colors;
	signed int unknown6;
	s_tag_block_definition<s_mesh_block_definition> meshes;
	s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	s_tag_block_definition<s_unknown_7_block_definition> unknown_7_2;
	unsigned int unknown7;
	unsigned int unknown8;
	unsigned int unknown9;
	unsigned int unknown10;
	unsigned int unknown11;
	unsigned int unknown12;
	s_tag_block_definition<s_node_map_block_definition> node_maps;
	unsigned int unknown13;
	unsigned int unknown14;
	unsigned int unknown15;
	unsigned int unknown16;
	unsigned int unknown17;
	unsigned int unknown18;
	unsigned int unknown19;
	unsigned int unknown20;
	unsigned int unknown21;
	s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	unsigned int zone_asset_datum;
	unsigned short easy_read_index;
	unsigned short easy_read_salt;
	signed int useless_padding;
	s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	s_tag_block_definition<s_unknown_10_block_definition> unknown_10_2;
	s_tag_block_definition<s_airprobe_block_definition> airprobes;
	s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;
	s_tag_block_definition<s_unknown_13_block_definition> unknown_13_2;
	unsigned int unknown22;
	unsigned int unknown23;
	unsigned int unknown24;
	s_tag_block_definition<s_compile_datum_block_definition> compile_data;

	struct s_unknown_a_definition
	{
		signed short unknown_index;
		signed short unknown;
	};

	struct s_unknown_b_definition
	{
		signed int unknown;
		unsigned int unknown2;
	};

	struct s_instanced_geometry_definition
	{
		signed short unknown;
		signed short unknown_a_index;
		signed short coloring_index;
		signed short unknown2;
		unsigned int unknown3;
	};

	struct s_color_definition
	{
		float unknown;
		float unknown2;
		float red;
		float blue;
		float unknown3;
		signed int unknown4;
		float unknown5;
		float unknown6;
		unsigned int unknown7;
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

	struct s_unknown_7_definition
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

	struct s_unknown_10_definition
	{
		struct s_unknown_11_block_definition;

		s_tag_block_definition<s_unknown_11_block_definition> unknown_11_2;

		struct s_unknown_11_definition
		{
			unsigned int unknown;
		};
	};

	struct s_airprobe_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		string_id name;
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

	struct s_unknown_12_definition
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
	};

	struct s_unknown_13_definition
	{
		struct s_unknown_14_block_definition;

		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		s_tag_block_definition<s_unknown_14_block_definition> unknown_14_2;

		struct s_unknown_14_definition
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
		};
	};

	struct s_compile_datum_definition
	{
		char date[32];
		char culprit[32];
		char build[256];
		char command[256];
	};
};
