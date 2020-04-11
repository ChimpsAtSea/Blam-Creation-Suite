#pragma once

struct nicename("antenna") tag_group('ant!') s_antenna_definition
{
	struct nicename("Vertices") s_vertices_definition
	{
		float nicename("Angle y") angle_y;
		float nicename("Angle p") angle_p;
		float nicename("Length") length;
		int16_t nicename("Sequence Index") sequence_index;
		int16_t __unknown0;
		s_colorf_legacy nicename("Color") color;
		s_colorf_legacy nicename("LOD Color") lod_color;
		s_undefined32_legacy nicename("Width") width;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
	};

	string_id_legacy nicename("Attachment Marker Name") attachment_marker_name;
	s_tag_reference_legacy nicename("Bitmaps") bitmaps_reference;
	s_tag_reference_legacy nicename("Physics") physics_reference;
	float __unknown0;
	float __unknown1;
	float __unknown2;
	float __unknown3;
	float __unknown4;
	float __unknown5;
	float __unknown6;
	float __unknown7;
	s_tag_block_legacy<s_vertices_definition> nicename("Vertices") vertices_block;
};

