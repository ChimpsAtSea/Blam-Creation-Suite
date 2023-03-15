#include "tagdefinitionsyntaxtest-private-pch.h"
#include <tagframework\definitions\definitions.h>




namespace blofeld::tagdefinitionsyntaxtest
{

	BCS_SHARED extern s_string_list_definition syntax_test_string_list;

	BCS_SHARED extern s_tag_data_definition syntax_test_data;

	BCS_SHARED extern s_tag_resource_definition syntax_test_resource;

	BCS_SHARED extern s_tag_interop_definition syntax_test_interop;

	BCS_SHARED extern s_block_index_custom_search_definition syntax_test_block_index_custom_search;

	TAG_GROUP_V8(
		"syntax_test",
		syntax_test_group,
		SYNTAX_TEST_TAG,
		1,
		nullptr,
		syntax_test_block_group_block);

	TAG_BLOCK_FROM_STRUCT(
		syntax_test_block_group_block,
		"syntax_test_block",
		"syntax_test_block",
		1,
		versioned_struct_syntax_test_struct);

#define VERSIONED_STRUCT_SYNTAX_TEST_STRUCT_ID { 0x01234567, 0x01234567, 0x01234567, 0x01234567 }
	VERSIONED_TAG_STRUCT(
		versioned_struct_syntax_test_struct,
		"versioned_struct_syntax_test_struct",
		"versioned_struct_syntax_test_struct",
		"s_versioned_struct_syntax_test_struct",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VERSIONED_STRUCT_SYNTAX_TEST_STRUCT_ID)
	{
		{ _struct_version_mode_greater_or_equal, 1, 1 },
		{ _field_struct, "test", &struct_syntax_test_struct },

		{ _struct_version_mode_equal, 0, 0 },

		{ _field_terminator }
	};

	TAG_STRUCT(
		struct_syntax_test_struct,
		"struct_syntax_test_struct",
		"struct_syntax_test_struct",
		"s_struct_syntax_test_struct",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_EMPTY)
	{
		{ _field_terminator }
	};

	TAG_ARRAY_FROM_STRUCT(
		syntax_test_array,
		"syntax_test_array",
		128,
		struct_syntax_test_struct);
	
	STRINGS(syntax_test_string_list)
	{
		"test"
	};
	STRING_LIST(syntax_test_string_list, syntax_test_string_list_strings, _countof(syntax_test_string_list_strings));

}
