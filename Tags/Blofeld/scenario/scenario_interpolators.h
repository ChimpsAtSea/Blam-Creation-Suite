#pragma once

namespace blofeld
{

	constexpr unsigned long SCENARIO_INTERPOLATOR_TAG = 'sirp';

	extern s_tag_group scenario_interpolator_group;

	extern s_tag_struct_definition scenario_interpolator_data_block_block_struct;
	extern s_tag_block_definition scenario_interpolator_data_block_block;
	extern s_tag_block_definition scenario_interpolator_block_block;

	extern s_tag_struct_definition scenario_interpolator_struct_definition_struct_definition; // tag group

	extern const char* scenario_interpolator_reset_value_enum_strings[];
	extern s_string_list_definition scenario_interpolator_reset_value_enum;
	extern const char* scenario_interpolator_start_value_enum_strings[];
	extern s_string_list_definition scenario_interpolator_start_value_enum;
	extern const char* scenario_interpolator_stop_value_enum_strings[];
	extern s_string_list_definition scenario_interpolator_stop_value_enum;
	extern const char* scenario_interpolator_flags_strings[];
	extern s_string_list_definition scenario_interpolator_flags;

	extern s_tag_reference_definition global_scenario_interpolator_reference;

} // namespace blofeld

