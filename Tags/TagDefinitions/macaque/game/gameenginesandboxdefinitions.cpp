#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define FORGE_GLOBALS_STRUCT_DEFINITION_ID { 0x9480BF0C, 0x93F311E1, 0xA5A3AFAF, 0xBAE59B18 }
	TAG_BLOCK(
		forge_globals_block,
		"forge_globals_block",
		1,
		"GameEngineSandboxGlobalsDefinition",
		FORGE_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "forge colors", &forge_color_block },
		{ _field_explanation, "Magnets", "Forge magnet parameters" },
		{ _field_tag_reference, "magnet effect scenery", &effect_scenery_reference },
		{ _field_string_id, "parent magnet marker name" },
		{ _field_string_id, "child magnet marker name" },
		{ _field_real_fraction, "throttle sensitivity" },
		{ _field_real, "v.low magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_real, "low magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_real, "med magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_real, "high magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_real, "v.high magnetism factor#multiplied against selected object bounding sphere radius" },
		{ _field_real, "magnetism angle#degrees#multiplied against selected object bounding sphere radius" },
		{ _field_real_fraction, "magnet offset influence#influence of magnet selection based on selection center in forge" },
		{ _field_explanation, "Forge Camera Manipulation", "Forge camera and manipulator parameters" },
		{ _field_real, "object grab range#how close you must be to an object in order to grab it for manipulation" },
		{ _field_real, "default focal distance#default manipulation camera distance" },
		{ _field_real, "minimum focal distance#minimum manipulation camera distance" },
		{ _field_real, "maximum focal distance#maximum manipulation camera distance" },
		{ _field_real, "focal distance multiplier#effective maximum distance = MIN(max_focal_distance, multiplier x min_focal_distance)" },
		{ _field_terminator }
	};

	TAG_GROUP(
		forge_globals_group,
		FORGE_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		forge_globals_block );

	#define FORGE_COLOR_BLOCK_ID { 0x5F309018, 0x93F611E1, 0x97D1F9B1, 0xBAE59B18 }
	TAG_BLOCK(
		forge_color_block,
		"forge_color_block",
		k_forge_named_color_count,
		"s_named_rgb_color",
		FORGE_COLOR_BLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_real_rgb_color, "color" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

