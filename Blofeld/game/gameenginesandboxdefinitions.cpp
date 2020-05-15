#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(forge_color, k_forge_named_color_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_real_rgb_color, "color" ),
	FIELD( _field_terminator )
};

TAG_GROUP(forge_globals, FORGE_GLOBALS_TAG)
{
	FIELD( _field_block, "forge colors", &forge_color_block ),
	FIELD( _field_explanation, "Magnets" ),
	FIELD( _field_tag_reference, "magnet effect scenery" ),
	FIELD( _field_string_id, "parent magnet marker name" ),
	FIELD( _field_string_id, "child magnet marker name" ),
	FIELD( _field_real_fraction, "throttle sensitivity" ),
	FIELD( _field_real, "v.low magnetism factor#multiplied against selected object bounding sphere radius" ),
	FIELD( _field_real, "low magnetism factor#multiplied against selected object bounding sphere radius" ),
	FIELD( _field_real, "med magnetism factor#multiplied against selected object bounding sphere radius" ),
	FIELD( _field_real, "high magnetism factor#multiplied against selected object bounding sphere radius" ),
	FIELD( _field_real, "v.high magnetism factor#multiplied against selected object bounding sphere radius" ),
	FIELD( _field_real, "magnetism angle#degrees#multiplied against selected object bounding sphere radius" ),
	FIELD( _field_real_fraction, "magnet offset influence#influence of magnet selection based on selection center in forge" ),
	FIELD( _field_explanation, "Forge Camera Manipulation" ),
	FIELD( _field_real, "object grab range#how close you must be to an object in order to grab it for manipulation" ),
	FIELD( _field_real, "default focal distance#default manipulation camera distance" ),
	FIELD( _field_real, "minimum focal distance#minimum manipulation camera distance" ),
	FIELD( _field_real, "maximum focal distance#maximum manipulation camera distance" ),
	FIELD( _field_real, "focal distance multiplier#effective maximum distance = MIN(max_focal_distance, multiplier x min_focal_distance)" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

