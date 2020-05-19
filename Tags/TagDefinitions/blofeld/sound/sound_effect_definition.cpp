#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(sound_effect_template, SOUND_EFFECT_TEMPLATE_TAG, sound_effect_template_block_block );

	TAG_BLOCK(sound_effect_template_parameter_block, k_maximum_number_of_sound_effect_parameters)
	{
		{ _field_string_id, "name" },
		{ _field_enum, "type", &sound_effect_template_type_enum_definition },
		{ _field_word_flags, "flags", &sound_effect_template_parameter_flags_definition },
		{ _field_long_integer, "hardware offset" },
		{ _field_long_integer, "default enum integer value" },
		{ _field_real, "default scalar value" },
		{ _field_custom },
		{ _field_struct, "default function", &mapping_function_struct_definition },
		{ _field_real, "minimum scalar value" },
		{ _field_real, "maximum scalar value" },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_effect_templates_block, k_maximum_number_of_sound_effect_templates)
	{
		{ _field_string_id, "dsp effect" },
		{ _field_explanation, "WARNING" },
		{ _field_data, "explanation" },
		{ _field_long_flags, "flags", &sound_effect_template_flags_definition },
		{ _field_short_integer, "dsp state offset!" },
		{ _field_short_integer, "dsp state size!" },
		{ _field_block, "parameters", &sound_effect_template_parameter_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_effect_template_additional_sound_input_block, 1)
	{
		{ _field_string_id, "dsp effect" },
		{ _field_custom },
		{ _field_struct, "low frequency sound", &mapping_function_struct_definition },
		{ _field_real, "time period: seconds" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(sound_effect_template_block, 1, sound_effect_template_struct_definition_struct_definition );

	TAG_STRUCT(sound_effect_template_struct_definition)
	{
		{ _field_block, "template collection", &sound_effect_templates_block_block },
		{ _field_string_id, "internal dsp effect name{input effect name}" },
		{ _field_block, "additional sound inputs", &sound_effect_template_additional_sound_input_block_block },
		{ _field_terminator }
	};

	STRINGS(sound_effect_template_type_enum_definition)
	{
		"integer",
		"real",
		"filter type"
	};
	STRING_LIST(sound_effect_template_type_enum_definition, sound_effect_template_type_enum_definition_strings, _countof(sound_effect_template_type_enum_definition_strings));

	STRINGS(sound_effect_template_parameter_flags_definition)
	{
		"expose as function"
	};
	STRING_LIST(sound_effect_template_parameter_flags_definition, sound_effect_template_parameter_flags_definition_strings, _countof(sound_effect_template_parameter_flags_definition_strings));

	STRINGS(sound_effect_template_flags_definition)
	{
		"use high level parameters",
		"custom parameters"
	};
	STRING_LIST(sound_effect_template_flags_definition, sound_effect_template_flags_definition_strings, _countof(sound_effect_template_flags_definition_strings));

} // namespace blofeld

