#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		sound_effect_template_group,
		SOUND_EFFECT_TEMPLATE_TAG,
		nullptr,
		INVALID_TAG,
		sound_effect_template_block );

	TAG_BLOCK_FROM_STRUCT(
		sound_effect_template_block,
		"sound_effect_template_block",
		1,
		sound_effect_template_struct_definition);

	#define SOUND_EFFECT_TEMPLATES_BLOCK_ID { 0x5C8458F8, 0x94B84560, 0x93EBB56F, 0xA67E6E02 }
	TAG_BLOCK(
		sound_effect_templates_block,
		"sound_effect_templates_block",
		k_maximum_number_of_sound_effect_templates,
		"sound_effect_templates_block",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_EFFECT_TEMPLATES_BLOCK_ID)
	{
		{ _field_string_id, "dsp effect" },
		FIELD_EXPLANATION("WARNING", nullptr, "DON\'T MODIFY THIS TAG UNLESS YOU KNOW WHAT YOU ARE DOING"),
		{ _field_data, "explanation" },
		{ _field_long_flags, "flags", &sound_effect_template_flags_definition },
		{ _field_short_integer, "dsp state offset" },
		{ _field_short_integer, "dsp state size" },
		{ _field_block, "parameters", &sound_effect_template_parameter_block },
		{ _field_terminator }
	};

	#define SOUND_EFFECT_TEMPLATE_PARAMETER_BLOCK_ID { 0x0C097B16, 0x12DF427A, 0xA170402E, 0xBFD48E4F }
	TAG_BLOCK(
		sound_effect_template_parameter_block,
		"sound_effect_template_parameter_block",
		k_maximum_number_of_sound_effect_parameters,
		"s_sound_effect_template_parameter_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_EFFECT_TEMPLATE_PARAMETER_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_enum, "type", &sound_effect_template_type_enum_definition },
		{ _field_word_flags, "flags", &sound_effect_template_parameter_flags_definition },
		{ _field_long_integer, "hardware offset" },
		{ _field_long_integer, "default enum integer value" },
		{ _field_real, "default scalar value" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_default),
		{ _field_struct, "default function", &mapping_function },
		{ _field_real, "minimum scalar value" },
		{ _field_real, "maximum scalar value" },
		{ _field_terminator }
	};

	#define SOUND_EFFECT_TEMPLATE_ADDITIONAL_SOUND_INPUT_BLOCK_ID { 0xC146FB4E, 0x44454229, 0xB830C667, 0x1A9F31F0 }
	TAG_BLOCK(
		sound_effect_template_additional_sound_input_block,
		"sound_effect_template_additional_sound_input_block",
		1,
		"s_sound_effect_template_sound_input_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_EFFECT_TEMPLATE_ADDITIONAL_SOUND_INPUT_BLOCK_ID)
	{
		{ _field_string_id, "dsp effect" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_default),
		{ _field_struct, "low frequency sound", &mapping_function },
		{ _field_real, "time period", " seconds", _field_id_function_unknown },
		{ _field_terminator }
	};

	#define SOUND_EFFECT_TEMPLATE_STRUCT_DEFINITION_ID { 0xAB4E33F8, 0x77314AE8, 0x9EC2A912, 0x98B0CCCD }
	TAG_STRUCT(
		sound_effect_template_struct_definition,
		"sound_effect_template_struct_definition",
		"s_sound_effect_template_collection",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_EFFECT_TEMPLATE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "template collection", &sound_effect_templates_block },
		{ _field_string_id, "internal dsp effect name" },
		{ _field_block, "additional sound inputs", &sound_effect_template_additional_sound_input_block },
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

} // namespace macaque

} // namespace blofeld

