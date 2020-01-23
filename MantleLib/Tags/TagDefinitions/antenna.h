#pragma once

struct nicename("Antenna") group('ant!') s_antenna_definition
{
	struct nicename("Vertices") s_vertex_block_definition;

	string_id nicename("Attachment Marker Name") attachment_marker_name; 
	TagReference nicename("Bitmaps") bitmaps_reference; 
	TagReference nicename("Physics") physics_reference; 
	float __unknown; 
	float __unknown2; 
	float __unknown3; 
	float __unknown4; 
	float __unknown5; 
	float __unknown6; 
	float __unknown7; 
	float __unknown8; 
	s_tag_block_definition<s_vertex_block_definition> nicename("Vertices") vertices_block; 

	struct nicename("vertex") s_vertex_block_definition
	{
		float nicename("Angle y") angle_y; 
		float nicename("Angle p") angle_p; 
		float nicename("Length") length; 
		int16_t nicename("Sequence Index") sequence_index; 
		int16_t __unknown; 
		float nicename("Color a") color_a; 
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
		float nicename("LOD Color a") lod_color_a; 
		float nicename("LOD Color r") lod_color_r; 
		float nicename("LOD Color g") lod_color_g; 
		float nicename("LOD Color b") lod_color_b; 
		Undefined32 __width; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
	};
};
