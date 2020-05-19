#pragma once

namespace blofeld
{

	constexpr unsigned long DEATH_PROGRAM_SELECTOR_TAG = 'bdpd';

	extern s_tag_group death_program_selector_group;

	extern s_tag_struct_definition death_program_velocity_gate_block_block_struct;
	extern s_tag_block_definition death_program_velocity_gate_block_block;
	extern s_tag_struct_definition death_program_damage_reporting_block_block_struct;
	extern s_tag_block_definition death_program_damage_reporting_block_block;
	extern s_tag_struct_definition death_program_special_block_block_struct;
	extern s_tag_block_definition death_program_special_block_block;
	extern s_tag_block_definition death_program_selector_block_block;

	extern s_tag_struct_definition death_program_selector_struct_definition_struct_definition; // tag group

	extern const char* death_program_result_enum_strings[];
	extern s_string_list_definition death_program_result_enum;

	extern s_tag_reference_definition death_program_selector_reference;

} // namespace blofeld

