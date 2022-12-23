#pragma once

struct s_tag_d3d_vertex_buffer
{
	unsigned char type;
	unsigned char stride;
	unsigned short count;
	unsigned int actual_vertex_offset_bytes;
	unsigned int default_vertex_offset_bytes;
	unsigned int unknownC;
	unsigned int unknown10;
	unsigned int hardware_format;
	unsigned int unknown18;
	unsigned int unknown1C;
};
static_assert(sizeof(s_tag_d3d_vertex_buffer) == 32);
