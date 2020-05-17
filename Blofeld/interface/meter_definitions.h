#pragma once

namespace blofeld
{

	extern const char* meter_flags_strings[];
	extern s_string_list_definition meter_flags;
	extern const char* color_interpolation_modes_enum_strings[];
	extern s_string_list_definition color_interpolation_modes_enum;
	extern const char* color_anchors_enum_strings[];
	extern s_string_list_definition color_anchors_enum;

	constexpr unsigned long METER_TAG = 'metr';

	extern s_tag_group meter_group;

	extern s_tag_block_definition meter_block_block;

	extern s_tag_struct meter_struct_definition_struct_definition; // tag group

} // namespace blofeld

