#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		game_performance_throttle_group,
		GAME_PERFORMANCE_THROTTLE_TAG,
		nullptr,
		INVALID_TAG,
		game_performance_throttle_block );

	TAG_BLOCK_FROM_STRUCT(
		game_performance_throttle_block,
		"game_performance_throttle_block",
		1,
		game_performance_throttle_struct_definition);

	#define GAME_PERFORMANCE_THROTTLE_ENTRIES_BLOCK_ID { 0x7195A903, 0x69BE49A5, 0xC5CD305E, 0x57868FDC }
	TAG_BLOCK(
		game_performance_throttle_entries_block,
		"game_performance_throttle_entries_block",
		32,
		"s_game_performance_throttle_entry",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_POSTPROCESS_RECURSIVELY | 
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_PERFORMANCE_THROTTLE_ENTRIES_BLOCK_ID)
	{
		{ _field_struct, "filter", &game_performance_throttle_filter_struct },
		{ _field_struct, "profile", &game_performance_throttle_profile_struct },
		{ _field_terminator }
	};

	#define GAME_PERFORMANCE_THROTTLE_STRUCT_DEFINITION_ID { 0x1073ABE0, 0x3D1447BB, 0x89E0B4FC, 0xB0BD63B1 }
	TAG_STRUCT(
		game_performance_throttle_struct_definition,
		"game_performance_throttle_struct_definition",
		"s_game_performance_throttle_definitions",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_PERFORMANCE_THROTTLE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "entries", &game_performance_throttle_entries_block },
		{ _field_terminator }
	};

	#define GAME_PERFORMANCE_THROTTLE_FILTER_STRUCT_ID { 0xAAA4CF05, 0x08434959, 0xC0C30D92, 0x12AB070E }
	TAG_STRUCT(
		game_performance_throttle_filter_struct,
		"game_performance_throttle_filter_struct",
		"s_game_performance_throttle_filter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_PERFORMANCE_THROTTLE_FILTER_STRUCT_ID)
	{
		{ _field_long_integer, "minimum player count" },
		{ _field_terminator }
	};

	#define GAME_PERFORMANCE_THROTTLE_PROFILE_STRUCT_ID { 0xA9A4CF05, 0x88434959, 0xB0C30D92, 0x16AB070E }
	TAG_STRUCT(
		game_performance_throttle_profile_struct,
		"game_performance_throttle_profile_struct",
		"s_game_performance_throttle_profile",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_PERFORMANCE_THROTTLE_PROFILE_STRUCT_ID)
	{
		{ _field_long_integer, "maximum havok proxy count" },
		{ _field_long_integer, "maximum ragdoll count" },
		{ _field_long_integer, "maximum impact count" },
		{ _field_long_integer, "vehicle suspension update frequency" },
		{ _field_long_integer, "Actor LOD, AI actors to update fully each frame" },
		{ _field_long_integer, "Actor LOD, Number of frames to tick LODed AI" },
		{ _field_long_integer, "Actor LOD, Number of concurrent LOD actors to tick" },
		{ _field_terminator }
	};



} // namespace blofeld

