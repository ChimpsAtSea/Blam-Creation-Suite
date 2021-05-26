#pragma once

namespace blofeld
{



	constexpr unsigned long WAVE_TEMPLATE_TAG = 'wave';
	extern s_tag_group wave_template_group; // wave_template_block
	extern s_tag_block_definition wave_template_block;
	extern s_tag_struct_definition wave_template_block_struct_definition; // wave_template_block


	extern s_tag_block_definition wave_squad_specification_struct_block;

	extern s_tag_struct_definition wave_squad_specification_struct_struct;

	extern c_versioned_string_list wave_placement_filter_enum_strings;
	extern s_string_list_definition wave_placement_filter_enum;



} // namespace blofeld

