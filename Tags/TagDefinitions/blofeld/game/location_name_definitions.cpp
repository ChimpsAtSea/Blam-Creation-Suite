#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		location_name_globals_definition_group,
		LOCATION_NAME_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		location_name_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		location_name_globals_definition_block,
		"location_name_globals_definition_block",
		1,
		location_name_globals_definition_struct_definition);

	#define LOCATION_NAME_BLOCK_ID { 0x04DCE9A5, 0x6A094478, 0x8B8EB132, 0x2A8C5A6A }
	TAG_BLOCK(
		location_name_block,
		"location_name_block",
		s_location_name_globals_tag_definition::k_maximum_location_names,
		"s_location_name_tag_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LOCATION_NAME_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define LOCATION_NAME_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0xEB8D99C2, 0xBA8D4F05, 0xBC2A8672, 0xFC4A012A }
	TAG_STRUCT_V6(
		location_name_globals_definition_struct_definition,
		"location_name_globals_definition_struct_definition",
		"s_location_name_globals_tag_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LOCATION_NAME_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "location names", &location_name_block },
		{ _field_tag_reference, "location name string list", &global_multilingual_unicode_string_list_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_location_name_globals_reference, LOCATION_NAME_GLOBALS_DEFINITION_TAG);



} // namespace blofeld

