#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(forge_globals, FORGE_GLOBALS_TAG)
	{
		{ _field_legacy, _field_block, "forge colors", &forge_color_block_block },
		{ _field_legacy, _field_explanation, "Magnets", "Forge magnet parameters" },
		{ _field_legacy, _field_tag_reference, "magnet effect scenery", &effect_scenery_reference },
		{ _field_legacy, _field_string_id, "parent magnet marker name" },
		{ _field_legacy, _field_string_id, "child magnet marker name" },
		{ _field_legacy, _field_real_fraction, "throttle sensitivity" },
		{ _field_legacy, _field_real, "v.low magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_legacy, _field_real, "low magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_legacy, _field_real, "med magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_legacy, _field_real, "high magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_legacy, _field_real, "v.high magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_legacy, _field_real, "magnetism angle#degrees#multiplied against selected object bounding sphere radius" },
		{ _field_legacy, _field_real_fraction, "magnet offset influence#influence of magnet selection based on selection center in forge" },
		{ _field_legacy, _field_explanation, "Forge Camera Manipulation", "Forge camera and manipulator parameters" },
		{ _field_legacy, _field_real, "object grab range#how close you must be to an object in order to grab it for manipulation" },
		{ _field_legacy, _field_real, "default focal distance#default manipulation camera distance" },
		{ _field_legacy, _field_real, "minimum focal distance#minimum manipulation camera distance" },
		{ _field_legacy, _field_real, "maximum focal distance#maximum manipulation camera distance" },
		{ _field_legacy, _field_real, "focal distance multiplier#effective maximum distance = MIN(max_focal_distance, multiplier x min_focal_distance)" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(forge_color_block, k_forge_named_color_count)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_real_rgb_color, "color" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

