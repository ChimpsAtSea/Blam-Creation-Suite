#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long FX_TEST_TAG = 'fxtt';
	extern s_tag_group fx_test_group; // fx_test_block


	extern s_tag_block_definition fx_test_block;
	extern s_tag_block_definition fx_property_block;
	extern s_tag_struct_definition fx_property_block_struct_definition; // fx_property_block
	extern s_tag_block_definition fx_property_default_block;
	extern s_tag_struct_definition fx_property_default_block_struct_definition; // fx_property_default_block

	extern s_tag_struct_definition fx_test_struct_definition; // tag group
	extern s_tag_struct_definition fx_test_scalar_function_struct;

	extern c_versioned_string_list fx_property_flags_strings;
	extern s_string_list_definition fx_property_flags;
	extern c_versioned_string_list fx_property_value_type_enum_strings;
	extern s_string_list_definition fx_property_value_type_enum;
	extern c_versioned_string_list fx_property_bitmap_filter_enum_strings;
	extern s_string_list_definition fx_property_bitmap_filter_enum;
	extern c_versioned_string_list fx_property_bitmap_address_enum_strings;
	extern s_string_list_definition fx_property_bitmap_address_enum;
	extern c_versioned_string_list fx_property_bitmap_bias_enum_strings;
	extern s_string_list_definition fx_property_bitmap_bias_enum;

} // namespace macaque

} // namespace blofeld

