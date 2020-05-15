#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(decal_definition, c_decal_system_definition::k_max_decal)
{
	{ _field_string_id, "decal name^" },
	{ _field_long_flags, "flags" },
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_real_bounds, "radius:world units" },
	{ _field_real_bounds, "decay time:seconds!" },
	{ _field_real_bounds, "lifespan:seconds!" },
	{ _field_real, "clamp angle:degrees#Projections at greater than this angle will be clamped to this angle" },
	{ _field_real, "cull angle:degrees#Projections at greater than this angle will not be drawn" },
	{ _field_real, "depth bias" },
	{ _field_custom, "Decal Strip" },
	{ _field_real, "strip U-coordinate tile length" },
	{ _field_real, "strip max profile distance" },
	{ _field_custom },
	{ _field_real, "runtime bitmap aspect!" },
	{ _field_terminator },
};

TAG_GROUP(decal_system, DECAL_SYSTEM_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_long_integer, "ring buffer size (in triangles)#bigger sizes keep more decals around but use much more memory" },
	{ _field_long_integer, "ring buffer size single player (in triangles)#above entry is for MP -- SP can be different" },
	{ _field_real, "material shader fade time#material shader lifetime is modulated from 1 to 0 over this time" },
	{ _field_real_point_2d, "decal scale override#NOTE - If set to non-zero, this will override manual scaling in Sapien and smash it with these values" },
	{ _field_explanation, "Decal bucket sharing" },
	{ _field_short_bounds, "random sprite index bounds#if zero, will use random sprite" },
	{ _field_block, "decals", &decal_definition_block },
	{ _field_real, "runtime max radius!" },
	{ _field_terminator },
};

} // namespace blofeld

