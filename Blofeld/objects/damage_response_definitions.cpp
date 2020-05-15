#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(damage_response_class, 2)
{
	{ _field_enum, "type" },
	{ _field_word_flags, "flags" },
	{ _field_explanation, "directional flash" },
	{ _field_struct, "directional flash" },
	{ _field_explanation, "motion sensor ping" },
	{ _field_struct, "motion sensor ping" },
	{ _field_explanation, "rumble" },
	{ _field_tag_reference, "rumble{rumble data}" },
	{ _field_explanation, "camera shake and impulse data" },
	{ _field_tag_reference, "camera shake{camera shake data}" },
	{ _field_tag_reference, "camera shake zoomed{camera shake data} #falls back on camerashake if untuned" },
	{ _field_explanation, "simulated input" },
	{ _field_tag_reference, "simulated_input" },
	{ _field_tag_reference, "simulated_input zoomed #falls back on simulated input if untuned" },
	{ _field_explanation, "global sound effect" },
	{ _field_block, "global sound effect", &damage_response_global_sound_effect_block },
	{ _field_terminator },
};

TAG_BLOCK(damage_response_global_sound_effect, 1)
{
	{ _field_string_id, "effect name" },
	{ _field_custom },
	{ _field_struct, "scale => duration:seconds" },
	{ _field_terminator },
};

TAG_BLOCK(area_control, 1)
{
	{ _field_explanation, "AREA CONTROL" },
	{ _field_word_flags, "flags" },
	{ _field_pad, "DRCS", 2 },
	{ _field_explanation, "Distance Falloff" },
	{ _field_real, "maximum distance:world units#the maximum distance this player feedback will affect" },
	{ _field_struct, "distance falloff" },
	{ _field_explanation, "Angle Falloff" },
	{ _field_struct, "angle falloff" },
	{ _field_explanation, "Object Falloff" },
	{ _field_struct, "object falloff" },
	{ _field_terminator },
};

TAG_GROUP(damage_response_definition, DAMAGE_RESPONSE_DEFINITION_TAG)
{
	{ _field_block, "classes", &damage_response_class_block },
	{ _field_block, "area control", &area_control_block },
	{ _field_terminator },
};

} // namespace blofeld

