#pragma once

namespace blofeld
{

	extern const char* sound_effect_template_type_enum_definition_strings[];
	extern s_string_list_definition sound_effect_template_type_enum_definition;
	extern const char* sound_effect_template_parameter_flags_definition_strings[];
	extern s_string_list_definition sound_effect_template_parameter_flags_definition;
	extern const char* sound_effect_template_flags_definition_strings[];
	extern s_string_list_definition sound_effect_template_flags_definition;

	constexpr unsigned long SOUND_EFFECT_TEMPLATE_TAG = '<fx>';

	extern s_tag_group sound_effect_template_group;

	extern s_tag_block_definition sound_effect_template_block_block;
	extern s_tag_struct sound_effect_templates_block_block_struct;
	extern s_tag_block_definition sound_effect_templates_block_block;
	extern s_tag_struct sound_effect_template_parameter_block_block_struct;
	extern s_tag_block_definition sound_effect_template_parameter_block_block;
	extern s_tag_struct sound_effect_template_additional_sound_input_block_block_struct;
	extern s_tag_block_definition sound_effect_template_additional_sound_input_block_block;

	extern s_tag_struct sound_effect_template_struct_definition_struct_definition; // tag group

} // namespace blofeld

