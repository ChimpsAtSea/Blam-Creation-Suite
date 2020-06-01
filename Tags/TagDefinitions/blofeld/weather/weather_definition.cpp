#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(rain_definition, RAIN_DEFINITION_TAG, rain_definition_block_block );

	TAG_BLOCK_FROM_STRUCT(rain_definition_block, 1, rain_definition_struct_definition_struct_definition );

	TAG_STRUCT(rain_definition_struct_definition)
	{
		{ _field_long_integer, "version!#INTERNAL TAG USE ONLY DO NOT CHANGE" },
		{ _field_real, "rain amount:[0,1]#fade control for all rain effects" },
		{ _field_explanation, "Rain Effects", "These effects are applied when this rain is active\n" },
		{ _field_tag_reference, "effect", &global_effect_reference },
		{ _field_tag_reference, "screen effect", &global_area_screen_effect_reference },
		{ _field_tag_reference, "camera fx", &global_camera_fx_settings_reference },
		{ _field_custom, "particles" },
		{ _field_long_flags, "flags", &rain_particle_flags },
		{ _field_tag_reference, "drop texture", &global_bitmap_reference },
		{ _field_tag_reference, "splash texture", &global_bitmap_reference },
		{ _field_real, "density:particles per square world unit" },
		{ _field_real_vector_3d, "direction#k -1 is down" },
		{ _field_real, "fall speed:world units per second" },
		{ _field_real, "size:world units#size of the rain particles" },
		{ _field_real, "max vertical camera-relative motion:world units per second#the max velocity in which we allow world-relative vertical rain motion.  over this velocity we clamp to camera-relative vertical rain motion" },
		{ _field_real, "max aspect ratio#height to width ratio" },
		{ _field_real, "min aspect for intensity#intensity will scale inversely with aspect ratio, this clamps the aspect ratio before scaling" },
		{ _field_real_rgb_color, "tint color#tints the rain drops" },
		{ _field_real, "intensity#brightness of the rain drops" },
		{ _field_real, "alpha scale#transparency of the rain drops" },
		{ _field_real, "drop near fade distance:world units#distance at which the drops fade out" },
		{ _field_real, "collision range:world units#depth range over which the particle will search for collisions with the depth buffer" },
		{ _field_real, "splash size:world units#length of a side of the splash particle card" },
		{ _field_real, "splash height:world units#height off the ground of the center of the splash particle" },
		{ _field_real, "splash lifetime:seconds#how long the splash lasts" },
		{ _field_real, "near fade distance:world units#distance at which the splash fades out" },
		{ _field_real_rgb_color, "splash tint#tints the splashes" },
		{ _field_real, "splash intensity#brightness of the splashes" },
		{ _field_real, "splash alpha#transparency of the splashes" },
		{ _field_real, "ripple initial size#size of the ripple at impact" },
		{ _field_real, "ripple max size#maximum size of the ripple" },
		{ _field_real, "ripple lifetime:seconds#how long the ripples last" },
		{ _field_real, "ripple intensity#intensifies ripples" },
		{ _field_custom },
		{ _field_custom, "rain sheet" },
		{ _field_tag_reference, "rain sheet texture", &global_bitmap_reference },
		{ _field_real, "rain sheet speed" },
		{ _field_real, "rain sheet intervals" },
		{ _field_real, "rain sheet minimum distance" },
		{ _field_real, "rain sheet intensity" },
		{ _field_real, "rain texture tile scale" },
		{ _field_real, "rain sheet parallax speed" },
		{ _field_real, "rain sheet depth fade{rain sheet fade factor}" },
		{ _field_real, "transparent sort distance" },
		{ _field_real, "transparent sort layer" },
		{ _field_custom },
		{ _field_custom, "light volume" },
		{ _field_tag_reference, "light volume texture", &global_bitmap_reference },
		{ _field_real, "light volume intensity" },
		{ _field_real, "light volume texture scale" },
		{ _field_real, "rain drop/particle intensity" },
		{ _field_real, "farthest rain particle distance" },
		{ _field_real, "closest rain sheet distance" },
		{ _field_real, "rain drop length compensation#make it longer when it is far" },
		{ _field_custom },
		{ _field_custom, "rain transition" },
		{ _field_real, "wetness fade in time:seconds" },
		{ _field_real, "wetness fade out time:seconds" },
		{ _field_custom },
		{ _field_custom, "material dim" },
		{ _field_real, "dim of point light" },
		{ _field_real, "dim of imposters" },
		{ _field_real, "dim of decorators" },
		{ _field_custom },
		{ _field_terminator }
	};

	STRINGS(rain_particle_flags)
	{
		"alpha blend",
		"disable collision"
	};
	STRING_LIST(rain_particle_flags, rain_particle_flags_strings, _countof(rain_particle_flags_strings));

	TAG_REFERENCE(global_rain_definition_reference, RAIN_DEFINITION_TAG);

} // namespace blofeld

