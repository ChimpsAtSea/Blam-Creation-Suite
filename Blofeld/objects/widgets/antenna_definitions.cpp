#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(antenna_vertex, MAXIMUM_NUMBER_OF_ANTENNA_VERTICES)
{
	{ _field_real_euler_angles_2d, "angles#direction toward next vertex!" },
	{ _field_real, "length:world units#distance between this vertex and the next" },
	{ _field_short_integer, "sequence index#bitmap group sequence index for this vertex\'s texture" },
	{ _field_pad, "NTCTQQF", 2 },
	{ _field_real_argb_color, "color#color at this vertex" },
	{ _field_real_argb_color, "LOD color#color at this vertex for the low-LOD line primitives!" },
	{ _field_real, "hermite t!" },
	{ _field_real_vector_3d, "vector to next!" },
	{ _field_terminator },
};

TAG_GROUP(antenna, ANTENNA_TAG)
{
	{ _field_old_string_id, "attachment marker name#the marker name where the antenna should be attached" },
	{ _field_tag_reference, "bitmaps" },
	{ _field_tag_reference, "physics" },
	{ _field_real_fraction, "spring strength coefficient#strength of the spring (larger values make the spring stronger)" },
	{ _field_real, "texel to world width scale" },
	{ _field_real, "falloff pixels!" },
	{ _field_real, "cutoff pixels!" },
	{ _field_real, "point of bend#[0,1]" },
	{ _field_real, "starting bend#[0,1]" },
	{ _field_real, "ending bend#[0,1]" },
	{ _field_real, "runtime total length!" },
	{ _field_block, "vertices", &antenna_vertex_block },
	{ _field_terminator },
};

} // namespace blofeld

