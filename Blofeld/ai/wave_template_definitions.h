#pragma once

namespace blofeld
{

	extern const char* wave_placement_filter_enum_strings[];
	extern s_string_list_definition wave_placement_filter_enum;

	constexpr unsigned long WAVE_TEMPLATE_TAG = 'wave';

	extern s_tag_struct wave_template_block_struct;
	extern s_tag_block_definition wave_template_block;
	extern s_tag_group wave_template_group;

	extern s_tag_block_definition wave_squad_specification_struct_block;

	extern s_tag_struct wave_squad_specification_struct_struct_struct_definition;

} // namespace blofeld

