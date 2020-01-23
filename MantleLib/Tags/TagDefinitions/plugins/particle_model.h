#pragma once

struct s_particle_model_definition
{
	struct s_mesh_block_definition;
	struct s_compression_info_block_definition;
	struct s_unknown_nodey_block_definition;
	struct s_unknown_8_block_definition;
	struct s_node_map_block_definition;
	struct s_unknown_yo_block_definition;
	struct s_water_mesh_block_definition;
	struct s_unknown_compression_info_block_definition;
	struct s_unknown_2_block_definition;

	signed int unknown;
	s_tag_block_definition<s_mesh_block_definition> meshes;
	s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	s_tag_block_definition<s_unknown_8_block_definition> unknown_8_2;
	unsigned int unknown2;
	unsigned int unknown3;
	unsigned int unknown4;
	unsigned int unknown5;
	unsigned int unknown6;
	unsigned int unknown7;
	s_tag_block_definition<s_node_map_block_definition> node_maps;
	unsigned int unknown8;
	unsigned int unknown9;
	unsigned int unknown10;
	unsigned int unknown11;
	unsigned int unknown12;
	unsigned int unknown13;
	unsigned int unknown14;
	unsigned int unknown15;
	unsigned int unknown16;
	s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	unsigned int zone_asset_datum;
	unsigned short easy_read_index;
	unsigned short easy_read_salt;
	signed int useless_padding;
	s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	s_tag_block_definition<s_unknown_2_block_definition> unknown_2_2;

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

	struct s_unknown_8_definition
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

	struct s_unknown_2_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
	};
};
