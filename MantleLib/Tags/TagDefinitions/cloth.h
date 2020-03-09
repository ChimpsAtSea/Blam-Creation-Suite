#pragma once

struct nicename("cloth") group('clwd') s_cloth_definition
{
	enum nicename("Integration Type") e_integration_type : uint16_t
	{
		/*nicename("Verlet")*/ _integration_type_verlet = 1ui16,
	};

	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Doesn't Use Wind")*/ _flags_doesnt_use_wind = 1ui32 << 0ui32,
		/*nicename("Uses Grid Attach Top")*/ _flags_uses_grid_attach_top = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
	};

	struct nicename("Vertices") s_vertices_definition
	{
		float nicename("Initial Position X") initial_position_x;
		float nicename("Initial Position Y") initial_position_y;
		float nicename("Initial Position Z") initial_position_z;
		float nicename("UV i") uv_i;
		float nicename("UV j") uv_j;
	};

	struct nicename("Indices") s_indices_definition
	{
		int16_t nicename("Index") index;
	};

	struct nicename("Links") s_links_definition
	{
		float nicename("Default Distance") default_distance;
		int32_t nicename("Index 1") index_1;
		int32_t nicename("Index 2") index_2;
		Undefined32 __unknown0;
	};

	b_flags nicename("Flags") flags;
	string_id nicename("Marker Attachment Name") marker_attachment_name;
	string_id nicename("Second Marker Attachment Name") second_marker_attachment_name;
	TagReference nicename("Shader") shader_reference;
	int16_t nicename("Grid X Dimension") grid_x_dimension;
	int16_t nicename("Grid Y Dimension") grid_y_dimension;
	float nicename("Grid Spacing X") grid_spacing_x;
	float nicename("Grid Spacing Y") grid_spacing_y;
	Undefined32 __unknown0;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
	e_integration_type nicename("Integration Type") integration_type;
	int16_t nicename("Number Iterations") number_iterations;
	float nicename("Weight") weight;
	float nicename("Drag") drag;
	float nicename("Wind Scale") wind_scale;
	float nicename("Wind Flappiness Scale") wind_flappiness_scale;
	float nicename("Longest Rod") longest_rod;
	Undefined32 __unknown3;
	Undefined32 __unknown4;
	Undefined32 __unknown5;
	Undefined32 __unknown6;
	Undefined32 __unknown7;
	Undefined32 __unknown8;
	s_tag_block_definition<s_vertices_definition> nicename("Vertices") vertices_block;
	s_tag_block_definition<s_indices_definition> nicename("Indices") indices_block;
	Undefined32 __unknown9;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	s_tag_block_definition<s_links_definition> nicename("Links") links_block;
};

