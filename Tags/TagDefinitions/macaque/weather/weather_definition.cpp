#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		rain_definition_group,
		RAIN_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		rain_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		rain_definition_block,
		"rain_definition_block",
		1,
		rain_definition_struct_definition);

	#define RAIN_DEFINITION_STRUCT_DEFINITION_ID { 0xFC205D87, 0xB7394393, 0x92C1BD07, 0x91B04875 }
	TAG_STRUCT(
		rain_definition_struct_definition,
		"rain_definition_struct_definition",
		"s_rain_definition",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RAIN_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "version", "INTERNAL TAG USE ONLY DO NOT CHANGE", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "rain amount", "fade control for all rain effects" },
		FIELD_EXPLANATION("Rain Effects", nullptr, "These effects are applied when this rain is active\n"),
		{ _field_tag_reference, "effect", &global_effect_reference },
		{ _field_tag_reference, "screen effect", &global_area_screen_effect_reference },
		{ _field_tag_reference, "camera fx", &global_camera_fx_settings_reference },
		FIELD_CUSTOM("particles", nullptr, _field_id_function_group_begin),
		{ _field_long_flags, "flags", &rain_particle_flags },
		{ _field_tag_reference, "drop texture", &global_bitmap_reference },
		{ _field_tag_reference, "splash texture", &global_bitmap_reference },
		{ _field_real, "density", nullptr, "particles per square world unit" },
		{ _field_real_vector_3d, "direction", "k -1 is down" },
		{ _field_real, "fall speed", nullptr, "world units per second" },
		{ _field_real, "size", "size of the rain particles", "world units" },
		{ _field_real, "max vertical camera-relative motion", "the max velocity in which we allow world-relative vertical rain motion.  over this velocity we clamp to camera-relative vertical rain motion", "world units per second" },
		{ _field_real, "max aspect ratio", "height to width ratio" },
		{ _field_real, "min aspect for intensity", "intensity will scale inversely with aspect ratio, this clamps the aspect ratio before scaling" },
		{ _field_real_rgb_color, "tint color", "tints the rain drops" },
		{ _field_real, "intensity", "brightness of the rain drops" },
		{ _field_real, "alpha scale", "transparency of the rain drops" },
		{ _field_real, "drop near fade distance", "distance at which the drops fade out", "world units" },
		{ _field_real, "collision range", "depth range over which the particle will search for collisions with the depth buffer", "world units" },
		{ _field_real, "splash size", "length of a side of the splash particle card", "world units" },
		{ _field_real, "splash height", "height off the ground of the center of the splash particle", "world units" },
		{ _field_real, "splash lifetime", "how long the splash lasts", "seconds" },
		{ _field_real, "near fade distance", "distance at which the splash fades out", "world units" },
		{ _field_real_rgb_color, "splash tint", "tints the splashes" },
		{ _field_real, "splash intensity", "brightness of the splashes" },
		{ _field_real, "splash alpha", "transparency of the splashes" },
		{ _field_real, "ripple initial size", "size of the ripple at impact" },
		{ _field_real, "ripple max size", "maximum size of the ripple" },
		{ _field_real, "ripple lifetime", "how long the ripples last", "seconds" },
		{ _field_real, "ripple intensity", "intensifies ripples" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("rain sheet", nullptr, _field_id_function_group_begin),
		{ _field_tag_reference, "rain sheet texture", &global_bitmap_reference },
		{ _field_real, "rain sheet speed" },
		{ _field_real, "rain sheet intervals" },
		{ _field_real, "rain sheet minimum distance" },
		{ _field_real, "rain sheet intensity" },
		{ _field_real, "rain texture tile scale" },
		{ _field_real, "rain sheet parallax speed" },
		{ _field_real, "rain sheet depth fade" },
		{ _field_real, "transparent sort distance" },
		{ _field_real, "transparent sort layer" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("light volume", nullptr, _field_id_function_group_begin),
		{ _field_tag_reference, "light volume texture", &global_bitmap_reference },
		{ _field_real, "light volume intensity" },
		{ _field_real, "light volume texture scale" },
		{ _field_real, "rain drop/particle intensity" },
		{ _field_real, "farthest rain particle distance" },
		{ _field_real, "closest rain sheet distance" },
		{ _field_real, "rain drop length compensation", "make it longer when it is far" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("rain transition", nullptr, _field_id_function_group_begin),
		{ _field_real, "wetness fade in time", nullptr, "seconds" },
		{ _field_real, "wetness fade out time", nullptr, "seconds" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("material dim", nullptr, _field_id_function_group_begin),
		{ _field_real, "dim of point light" },
		{ _field_real, "dim of imposters" },
		{ _field_real, "dim of decorators" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_terminator }
	};

	STRINGS(rain_particle_flags)
	{
		"alpha blend",
		"disable collision"
	};
	STRING_LIST(rain_particle_flags, rain_particle_flags_strings, _countof(rain_particle_flags_strings));

	TAG_REFERENCE(global_rain_definition_reference, RAIN_DEFINITION_TAG);

} // namespace macaque

} // namespace blofeld

