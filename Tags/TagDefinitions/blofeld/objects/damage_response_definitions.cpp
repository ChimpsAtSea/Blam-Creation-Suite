#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(damage_response_definition, DAMAGE_RESPONSE_DEFINITION_TAG, damage_response_definition_block_block );

	TAG_BLOCK(damage_response_global_sound_effect_block, 1)
	{
		{ _field_string_id, "effect name" },
		{ _field_custom },
		{ _field_struct, "scale => duration:seconds", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_response_class_block, 2)
	{
		{ _field_enum, "type", &damage_response_class_type_enum },
		{ _field_word_flags, "flags", &damage_response_class_flags },
		{ _field_explanation, "directional flash", "" },
		{ _field_struct, "directional flash", &damage_response_directional_flash_struct_struct_definition },
		{ _field_explanation, "motion sensor ping", "WARNING \'motion sensor ping\' section no longer functions post CHUD-2-CUI switchover!" },
		{ _field_struct, "motion sensor ping", &damage_response_motion_sensor_ping_struct_definition },
		{ _field_explanation, "rumble", "" },
		{ _field_tag_reference, "rumble{rumble data}", &global_rumble_reference },
		{ _field_explanation, "camera shake and impulse data", "" },
		{ _field_tag_reference, "camera shake{camera shake data}", &global_camera_shake_reference },
		{ _field_tag_reference, "camera shake zoomed{camera shake data} #falls back on camerashake if untuned", &global_camera_shake_reference },
		{ _field_explanation, "simulated input", "" },
		{ _field_tag_reference, "simulated_input", &global_simulated_input_reference },
		{ _field_tag_reference, "simulated_input zoomed #falls back on simulated input if untuned", &global_simulated_input_reference },
		{ _field_explanation, "global sound effect", "" },
		{ _field_block, "global sound effect", &damage_response_global_sound_effect_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(area_control_block, 1)
	{
		{ _field_explanation, "AREA CONTROL", "Higher level scale controls for camera shake, camera impulse and rumble." },
		{ _field_word_flags, "flags", &area_control_flags },
		{ _field_pad, "DRCS", 2 },
		{ _field_explanation, "Distance Falloff", "controls the maximum distance and the distance falloff of this effect\nNOTE: not used for scenario global effects" },
		{ _field_real, "maximum distance:world units#the maximum distance this player feedback will affect" },
		{ _field_struct, "distance falloff", &area_control_scalar_function_struct_struct_definition },
		{ _field_explanation, "Angle Falloff", "controls the falloff of this effect based on how close you are to looking directly at it\nNOTE: not used for scenario global effects" },
		{ _field_struct, "angle falloff", &area_control_scalar_function_struct_struct_definition },
		{ _field_explanation, "Object Falloff", "applies a falloff based on an object function - ignored if the effect is not attached to an object" },
		{ _field_struct, "object falloff", &area_control_scalar_object_function_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(damage_response_definition_block, 1, damage_response_definition_struct_definition_struct_definition );

	TAG_STRUCT(damage_response_definition_struct_definition)
	{
		{ _field_block, "classes", &damage_response_class_block_block },
		{ _field_block, "area control", &area_control_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(damage_response_directional_flash_struct)
	{
		{ _field_real, "indicator duration" },
		{ _field_real, "flash duration {duration}" },
		{ _field_enum, "fade function", &global_reverse_transition_functions_enum },
		{ _field_pad, "ZASSFACE", 2 },
		{ _field_real, "center size" },
		{ _field_real, "offscreen size{size}" },
		{ _field_real, "center alpha" },
		{ _field_real, "offscreen alpha" },
		{ _field_real, "inner alpha{inner scale}" },
		{ _field_real, "outer alpha{outer scale}" },
		{ _field_real_argb_color, "flash color" },
		{ _field_real_argb_color, "arrow color" },
		{ _field_terminator }
	};

	TAG_STRUCT(damage_response_motion_sensor_ping)
	{
		{ _field_short_integer, "ping duration:ticks" },
		{ _field_short_integer, "ping scale" },
		{ _field_terminator }
	};

	TAG_STRUCT(area_control_scalar_function_struct)
	{
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(area_control_scalar_object_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	STRINGS(area_control_flags)
	{
		"distance_falloff",
		"angle_falloff",
		"object function falloff",
		"use unit position#use the head position and facing vector of the unit instead of the player camera"
	};
	STRING_LIST(area_control_flags, area_control_flags_strings, _countof(area_control_flags_strings));

	STRINGS(damage_response_class_type_enum)
	{
		"shielded",
		"unshielded",
		"all"
	};
	STRING_LIST(damage_response_class_type_enum, damage_response_class_type_enum_strings, _countof(damage_response_class_type_enum_strings));

	STRINGS(damage_response_class_flags)
	{
		"ignore on no damage",
		"suppress directional damage flashes",
		"suppress directional damage arrows",
		"only when zoomed#if target is zoomed",
		"sound effect only applied when scale is full"
	};
	STRING_LIST(damage_response_class_flags, damage_response_class_flags_strings, _countof(damage_response_class_flags_strings));

	TAG_REFERENCE_GROUP(global_damage_effect_or_response_definition_reference)
	{
		DAMAGE_EFFECT_TAG,
		DAMAGE_RESPONSE_DEFINITION_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(global_damage_response_definition_reference, DAMAGE_RESPONSE_DEFINITION_TAG);

} // namespace blofeld

