#pragma once

struct nicename("antenna") group('ant!') s_antenna_definition
{
	struct nicename("Vertices") s_vertices_definition
	{
		float nicename("Angle y") angle_y;
		float nicename("Angle p") angle_p;
		float nicename("Length") length;
		int16_t nicename("Sequence Index") sequence_index;
		int16_t __unknown0;
		colorf nicename("Color") color;
		colorf nicename("LOD Color") lod_color;
		Undefined32 nicename("Width") width;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
	};

	string_id nicename("Attachment Marker Name") attachment_marker_name;
	TagReference nicename("Bitmaps") bitmaps_reference;
	TagReference nicename("Physics") physics_reference;
	float __unknown0;
	float __unknown1;
	float __unknown2;
	float __unknown3;
	float __unknown4;
	float __unknown5;
	float __unknown6;
	float __unknown7;
	s_tag_block_definition<s_vertices_definition> nicename("Vertices") vertices_block;
};

