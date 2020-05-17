#pragma once

namespace blofeld
{

	constexpr unsigned long RENDER_WATER_RIPPLE_TAG = 'rwrd';

	extern s_tag_group render_water_ripple_group;

	extern s_tag_block_definition render_water_ripple_block_block;


	extern s_tag_struct_definition render_water_ripple_struct_definition_struct_definition; // tag group

	extern const char* ripple_behavior_flags_strings[];
	extern s_string_list_definition ripple_behavior_flags;
	extern const char* transition_function_enum_strings[];
	extern s_string_list_definition transition_function_enum;

} // namespace blofeld

