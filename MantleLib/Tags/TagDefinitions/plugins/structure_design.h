#pragma once

struct s_structure_design_definition
{
	struct s_design_mopp_code_block_definition;
	struct s_design_shapes_2_block_definition;
	struct s_water_mopp_code_block_definition;
	struct s_water_name_block_definition;
	struct s_underwater_definition_block_definition;
	struct s_planar_fog_block_definition;
	struct s_unknown_mopp_code_block_definition;
	struct s_mesh_block_definition;
	struct s_compression_info_block_definition;
	struct s_unknown_nodey_block_definition;
	struct s_unknown_8_block_definition;
	struct s_node_map_block_definition;
	struct s_unknown_yo_block_definition;
	struct s_water_mesh_block_definition;
	struct s_unknown_compression_info_block_definition;
	struct s_unknown_7_block_definition;
	struct s_instanced_geometry_instance_block_definition;
	struct s_material_block_definition;

	unsigned int unknown;
	unsigned int unknown2;
	unsigned int unknown3;
	unsigned int unknown4;
	signed int unknown5;
	signed int unknown6;
	unsigned int unknown7;
	unsigned int unknown8;
	unsigned int unknown9;
	unsigned int unknown10;
	unsigned int unknown11;
	unsigned int unknown12;
	signed int unknown13;
	s_tag_block_definition<s_design_mopp_code_block_definition> design_mopp_codes;
	s_tag_block_definition<s_design_shapes_2_block_definition> design_shapes_2_2;
	s_tag_block_definition<s_water_mopp_code_block_definition> water_mopp_codes;
	s_tag_block_definition<s_water_name_block_definition> water_names;
	s_tag_block_definition<s_underwater_definition_block_definition> underwater_definitions;
	s_tag_block_definition<s_planar_fog_block_definition> planar_fog2;
	s_tag_block_definition<s_unknown_mopp_code_block_definition> unknown_mopp_codes;
	signed int unknown14;
	s_tag_block_definition<s_mesh_block_definition> meshes;
	s_tag_block_definition<s_compression_info_block_definition> compression_info2;
	s_tag_block_definition<s_unknown_nodey_block_definition> unknown_nodey2;
	s_tag_block_definition<s_unknown_8_block_definition> unknown_8_2;
	unsigned int unknown15;
	unsigned int unknown16;
	unsigned int unknown17;
	unsigned int unknown18;
	unsigned int unknown19;
	unsigned int unknown20;
	s_tag_block_definition<s_node_map_block_definition> node_maps;
	unsigned int unknown21;
	unsigned int unknown22;
	unsigned int unknown23;
	unsigned int unknown24;
	unsigned int unknown25;
	unsigned int unknown26;
	unsigned int unknown27;
	unsigned int unknown28;
	unsigned int unknown29;
	s_tag_block_definition<s_unknown_yo_block_definition> unknown_yo2;
	s_tag_block_definition<s_water_mesh_block_definition> water_meshes;
	unsigned int zone_asset_datum;
	unsigned short easy_read_index;
	unsigned short easy_read_salt;
	signed int useless_padding;
	s_tag_block_definition<s_unknown_compression_info_block_definition> unknown_compression_info2;
	s_tag_block_definition<s_unknown_7_block_definition> unknown_7_2;
	s_tag_block_definition<s_instanced_geometry_instance_block_definition> instanced_geometry_instances;
	s_tag_block_definition<s_material_block_definition> materials;
	unsigned int unknown30;
	unsigned int unknown31;
	unsigned int unknown32;

	struct s_design_mopp_code_definition
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

	struct s_design_shapes_2_definition
	{
		struct s_unknown_2_block_definition;

		string_id name;
		signed short unknown;
		signed short unknown2;
		s_tag_block_definition<s_unknown_2_block_definition> unknown_2_2;

		struct s_unknown_2_definition
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
			unsigned int unknown14;
			unsigned int unknown15;
			unsigned int unknown16;
			unsigned int unknown17;
		};
	};

	struct s_water_mopp_code_definition
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

	struct s_water_name_definition
	{
		string_id name;
	};

	struct s_underwater_definition_definition
	{
		struct s_unknown2_block_definition;

		signed short water_name_index;
		signed short unknown;
		float flow_force_x;
		float flow_force_y;
		float flow_force_z;
		float flow_force_z_2;
		float mask_color_r;
		float mask_color_g;
		float mask_color_b;
		float obscure_amount;
		s_tag_block_definition<s_unknown2_block_definition> unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int x_min;
		unsigned int x_max;
		unsigned int y_min;
		unsigned int y_max;
		unsigned int z_min;
		unsigned int z_max;

		struct s_unknown_definition
		{
			float unknown2;
			float unknown3;
			float unknown4;
			float unknown5;
		};
	};

	struct s_planar_fog_definition
	{
		struct s_unknown_block_definition;
		struct s_unknown3_block_definition;

		string_id name;
		TagReference planar_fog_parameters;
		s_tag_block_definition<s_unknown_block_definition> unknown2;
		s_tag_block_definition<s_unknown3_block_definition> unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;

		struct s_unknown_definition
		{
			unsigned int unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
		};

		struct s_unknown_definition
		{
			struct s_unknown2_block_definition;

			s_tag_block_definition<s_unknown2_block_definition> unknown3;

			struct s_unknown_definition
			{
				unsigned int unknown2;
				unsigned int unknown3;
				unsigned int unknown4;
				unsigned int unknown5;
			};
		};
	};

	struct s_unknown_mopp_code_definition
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

	struct s_unknown_7_definition
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
		unsigned int unknown14;
		unsigned int unknown15;
		unsigned int unknown16;
		unsigned int unknown17;
		unsigned int unknown18;
		unsigned int unknown19;
		unsigned int unknown20;
		unsigned int unknown21;
		unsigned int unknown22;
		unsigned int unknown23;
		unsigned int unknown24;
		unsigned int unknown25;
		unsigned int unknown26;
		unsigned int unknown27;
		unsigned int unknown28;
		unsigned int unknown29;
		unsigned int unknown30;
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
		unsigned int unknown50;
		unsigned int unknown51;
		unsigned int unknown52;
		unsigned int unknown53;
		unsigned int unknown54;
		unsigned int unknown55;
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
		unsigned int unknown71;
		unsigned int unknown72;
		unsigned int unknown73;
		unsigned int unknown74;
		unsigned int unknown75;
		unsigned int unknown76;
		unsigned int unknown77;
		unsigned int unknown78;
		unsigned int unknown79;
		unsigned int unknown80;
		signed short unknown81;
		signed short unknown82;
	};

	struct s_instanced_geometry_instance_definition
	{
		float scale;
		float forward_i;
		float forward_j;
		float forward_k;
		float left_i;
		float left_j;
		float left_k;
		float up_i;
		float up_j;
		float up_k;
		float position_x;
		float position_y;
		float position_z;
		signed short mesh_index;
		unsigned short flags;
		signed short unknown;
		signed short unknown2;
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
		float bounding_sphere_x;
		float bounding_sphere_y;
		float bounding_sphere_z;
		float bounding_sphere_radius1;
		float unknown13;
		float bounding_sphere_radius2;
		signed char unknown14;
		signed char unknown15;
		signed char unknown16;
		signed char unknown17;
		float unknown18;
		unsigned int unknown19;
		unsigned int unknown20;
		unsigned int unknown21;
		unsigned int unknown22;
		unsigned int unknown23;
		unsigned int unknown24;
		string_id name;
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
};
