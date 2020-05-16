#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(damage_response_definition, DAMAGE_RESPONSE_DEFINITION_TAG, damage_response_definition_block_block )

TAG_BLOCK_FROM_STRUCT(damage_response_definition_block, 1, damage_response_definition_struct_definition_struct_definition );

TAG_BLOCK(damage_response_class_block, 2)
{
	FIELD( _field_enum, "type" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_explanation, "directional flash" ),
	FIELD( _field_struct, "directional flash", &damage_response_directional_flash_struct_struct_definition ),
	FIELD( _field_explanation, "motion sensor ping" ),
	FIELD( _field_struct, "motion sensor ping", &damage_response_motion_sensor_ping_struct_definition ),
	FIELD( _field_explanation, "rumble" ),
	FIELD( _field_tag_reference, "rumble{rumble data}" ),
	FIELD( _field_explanation, "camera shake and impulse data" ),
	FIELD( _field_tag_reference, "camera shake{camera shake data}" ),
	FIELD( _field_tag_reference, "camera shake zoomed{camera shake data} #falls back on camerashake if untuned" ),
	FIELD( _field_explanation, "simulated input" ),
	FIELD( _field_tag_reference, "simulated_input" ),
	FIELD( _field_tag_reference, "simulated_input zoomed #falls back on simulated input if untuned" ),
	FIELD( _field_explanation, "global sound effect" ),
	FIELD( _field_block, "global sound effect", &damage_response_global_sound_effect_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(damage_response_global_sound_effect_block, 1)
{
	FIELD( _field_string_id, "effect name" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "scale => duration:seconds", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(area_control_block, 1)
{
	FIELD( _field_explanation, "AREA CONTROL" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "DRCS", 2 ),
	FIELD( _field_explanation, "Distance Falloff" ),
	FIELD( _field_real, "maximum distance:world units#the maximum distance this player feedback will affect" ),
	FIELD( _field_struct, "distance falloff", &area_control_scalar_function_struct_struct_definition ),
	FIELD( _field_explanation, "Angle Falloff" ),
	FIELD( _field_struct, "angle falloff", &area_control_scalar_function_struct_struct_definition ),
	FIELD( _field_explanation, "Object Falloff" ),
	FIELD( _field_struct, "object falloff", &area_control_scalar_object_function_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(damage_response_definition_struct_definition)
{
	FIELD( _field_block, "classes", &damage_response_class_block_block ),
	FIELD( _field_block, "area control", &area_control_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(damage_response_directional_flash_struct)
{
	FIELD( _field_real, "indicator duration" ),
	FIELD( _field_real, "flash duration {duration}" ),
	FIELD( _field_enum, "fade function" ),
	FIELD( _field_pad, "ZASSFACE", 2 ),
	FIELD( _field_real, "center size" ),
	FIELD( _field_real, "offscreen size{size}" ),
	FIELD( _field_real, "center alpha" ),
	FIELD( _field_real, "offscreen alpha" ),
	FIELD( _field_real, "inner alpha{inner scale}" ),
	FIELD( _field_real, "outer alpha{outer scale}" ),
	FIELD( _field_real_argb_color, "flash color" ),
	FIELD( _field_real_argb_color, "arrow color" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(damage_response_motion_sensor_ping)
{
	FIELD( _field_short_integer, "ping duration:ticks" ),
	FIELD( _field_short_integer, "ping scale" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(area_control_scalar_function_struct)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(area_control_scalar_object_function_struct)
{
	FIELD( _field_string_id, "Input Variable!" ),
	FIELD( _field_string_id, "Range Variable!" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

