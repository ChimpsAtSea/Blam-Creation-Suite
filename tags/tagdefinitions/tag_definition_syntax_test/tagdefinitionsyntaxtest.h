#pragma once

namespace blofeld::tagdefinitionsyntaxtest
{
	static constexpr uint32_t SYNTAX_TEST_TAG = '1337';
	BCS_SHARED extern s_tag_group syntax_test_group;

	BCS_SHARED extern s_tag_block_definition syntax_test_block_group_block;

	BCS_SHARED extern s_tag_array_definition syntax_test_array;

	BCS_SHARED extern s_tag_struct_definition versioned_struct_syntax_test_struct;

	BCS_SHARED extern s_tag_struct_definition struct_syntax_test_struct;

	BCS_SHARED extern s_string_list_definition syntax_test_string_list;

	BCS_SHARED extern s_tag_data_definition syntax_test_data;

	BCS_SHARED extern s_tag_resource_definition syntax_test_resource;

	BCS_SHARED extern s_tag_interop_definition syntax_test_interop;

	BCS_SHARED extern s_block_index_custom_search_definition syntax_test_block_index_custom_search;
}
