#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_effect_templates, k_maximum_number_of_sound_effect_templates)
{
	{ _field_string_id, "dsp effect" },
	{ _field_explanation, "WARNING" },
	{ _field_data, "explanation" },
	{ _field_long_flags, "flags" },
	{ _field_short_integer, "dsp state offset!" },
	{ _field_short_integer, "dsp state size!" },
	{ _field_block, "parameters", &sound_effect_template_parameter_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_effect_template_parameter, k_maximum_number_of_sound_effect_parameters)
{
	{ _field_string_id, "name" },
	{ _field_enum, "type" },
	{ _field_word_flags, "flags" },
	{ _field_long_integer, "hardware offset" },
	{ _field_long_integer, "default enum integer value" },
	{ _field_real, "default scalar value" },
	{ _field_custom },
	{ _field_struct, "default function" },
	{ _field_real, "minimum scalar value" },
	{ _field_real, "maximum scalar value" },
	{ _field_terminator },
};

TAG_BLOCK(sound_effect_template_additional_sound_input, 1)
{
	{ _field_string_id, "dsp effect" },
	{ _field_custom },
	{ _field_struct, "low frequency sound" },
	{ _field_real, "time period: seconds" },
	{ _field_terminator },
};

TAG_GROUP(sound_effect_template, SOUND_EFFECT_TEMPLATE_TAG)
{
	{ _field_block, "template collection", &sound_effect_templates_block },
	{ _field_string_id, "internal dsp effect name{input effect name}" },
	{ _field_block, "additional sound inputs", &sound_effect_template_additional_sound_input_block },
	{ _field_terminator },
};

} // namespace blofeld

