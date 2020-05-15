#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(damage_response_class, 2)
{
	FIELD( _field_enum, "type" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_explanation, "directional flash" ),
	FIELD( _field_struct, "directional flash" ),
	FIELD( _field_explanation, "motion sensor ping" ),
	FIELD( _field_struct, "motion sensor ping" ),
	FIELD( _field_explanation, "rumble" ),
	FIELD( _field_tag_reference, "rumble{rumble data}" ),
	FIELD( _field_explanation, "camera shake and impulse data" ),
	FIELD( _field_tag_reference, "camera shake{camera shake data}" ),
	FIELD( _field_tag_reference, "camera shake zoomed{camera shake data} #falls back on camerashake if untuned" ),
	FIELD( _field_explanation, "simulated input" ),
	FIELD( _field_tag_reference, "simulated_input" ),
	FIELD( _field_tag_reference, "simulated_input zoomed #falls back on simulated input if untuned" ),
	FIELD( _field_explanation, "global sound effect" ),
	FIELD( _field_block, "global sound effect", &damage_response_global_sound_effect_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(damage_response_global_sound_effect, 1)
{
	FIELD( _field_string_id, "effect name" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "scale => duration:seconds" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(area_control, 1)
{
	FIELD( _field_explanation, "AREA CONTROL" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "DRCS", 2 ),
	FIELD( _field_explanation, "Distance Falloff" ),
	FIELD( _field_real, "maximum distance:world units#the maximum distance this player feedback will affect" ),
	FIELD( _field_struct, "distance falloff" ),
	FIELD( _field_explanation, "Angle Falloff" ),
	FIELD( _field_struct, "angle falloff" ),
	FIELD( _field_explanation, "Object Falloff" ),
	FIELD( _field_struct, "object falloff" ),
	FIELD( _field_terminator )
};

TAG_GROUP(damage_response_definition, DAMAGE_RESPONSE_DEFINITION_TAG)
{
	FIELD( _field_block, "classes", &damage_response_class_block ),
	FIELD( _field_block, "area control", &area_control_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

