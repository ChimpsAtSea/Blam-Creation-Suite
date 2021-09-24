#pragma once

namespace blofeld
{



	constexpr unsigned long SCENARIO_INTERPOLATOR_TAG = 'sirp';
	extern s_tag_group scenario_interpolator_group; // scenario_interpolator_block


	extern s_tag_block_definition scenario_interpolator_block;
	extern s_tag_block_definition scenario_interpolator_data_block;
	extern s_tag_struct_definition scenario_interpolator_data_block_struct_definition; // scenario_interpolator_data_block

	extern s_tag_struct_definition scenario_interpolator_struct_definition; // tag group

	extern s_string_list_definition scenario_interpolator_reset_value_enum;
	extern s_string_list_definition scenario_interpolator_start_value_enum;
	extern s_string_list_definition scenario_interpolator_stop_value_enum;
	extern s_string_list_definition scenario_interpolator_flags;

	extern s_tag_reference_definition global_scenario_interpolator_reference;



} // namespace blofeld

