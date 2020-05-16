#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_geometry_material_block, MAXIMUM_MATERIALS_PER_GEOMETRY)
{
	FIELD( _field_tag_reference, "render method^*" ),
	FIELD( _field_long_integer, "imported material index*" ),
	FIELD( _field_real, "lightmap resolution scale" ),
	FIELD( _field_long_integer, "lightmap additive transparency color" ),
	FIELD( _field_long_integer, "lightmap traslucency tint color" ),
	FIELD( _field_real, "lightmap analytical light absorb" ),
	FIELD( _field_real, "lightmap normal light absorb" ),
	FIELD( _field_byte_flags, "lightmap flags" ),
	FIELD( _field_char_integer, "breakable surface index*" ),
	FIELD( _field_short_integer, "lightmap chart group index" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

