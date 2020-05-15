#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_geometry_material, MAXIMUM_MATERIALS_PER_GEOMETRY)
{
	{ _field_tag_reference, "render method^*" },
	{ _field_long_integer, "imported material index*" },
	{ _field_real, "lightmap resolution scale" },
	{ _field_long_integer, "lightmap additive transparency color" },
	{ _field_long_integer, "lightmap traslucency tint color" },
	{ _field_real, "lightmap analytical light absorb" },
	{ _field_real, "lightmap normal light absorb" },
	{ _field_byte_flags, "lightmap flags" },
	{ _field_char_integer, "breakable surface index*" },
	{ _field_short_integer, "lightmap chart group index" },
	{ _field_terminator },
};

} // namespace blofeld

