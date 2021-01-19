#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long METER_TAG = 'metr';
	extern s_tag_group meter_group; // meter_block


	extern s_tag_block_definition meter_block;

	extern s_tag_struct_definition meter_struct_definition; // tag group

	extern c_versioned_string_list meter_flags_strings;
	extern s_string_list_definition meter_flags;
	extern c_versioned_string_list color_interpolation_modes_enum_strings;
	extern s_string_list_definition color_interpolation_modes_enum;
	extern c_versioned_string_list color_anchors_enum_strings;
	extern s_string_list_definition color_anchors_enum;

} // namespace macaque

} // namespace blofeld

