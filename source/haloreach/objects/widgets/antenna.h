#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_antenna_group_tag = 'ant!';

/* ---------- types */

struct s_antenna_vertex
{
	real_euler_angles2d angles; // direction toward next vertex
	real length; // distance between this vertex and the next
	short sequence_index; // bitmap group sequence index for this vertex's texture
	short : 16;
	argb_color color; // color at this vertex
	argb_color lod_color; // color at this vertex for the low-LOD line primitives
	real hermite_t;
	real_vector3d vector_to_next;
};
static_assert(sizeof(s_antenna_vertex) == 0x40);

struct s_antenna_definition
{
	string_id attachment_marker_name; // the marker name where the antenna should be attached
	s_tag_reference bitmaps; // 'bitm'
	s_tag_reference physics; // 'pphy'
	real spring_strength_coefficient; // strength of the spring (larger values make the spring stronger)
	real texel_to_world_width_scale;
	real falloff_pixels;
	real cutoff_pixels;
	real point_of_bend; // [0,1]
	real starting_bend; // [0,1]
	real ending_bend; // [0,1]
	real runtime_total_length;
	c_typed_tag_block<s_antenna_vertex> vertices;
};
static_assert(sizeof(s_antenna_definition) == 0x50);
