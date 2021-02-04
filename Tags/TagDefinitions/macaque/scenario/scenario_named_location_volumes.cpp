#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SCENARIO_NAMED_LOCATION_VOLUME_BLOCK_STRUCT_ID { 0x788095DE, 0x7C514271, 0xBB149679, 0x682095DA }
	TAG_BLOCK(
		scenario_named_location_volume_block,
		"scenario_named_location_volume_block",
		s_scenario_named_location_volume::k_maximum_scenario_named_location_volumes,
		"s_scenario_named_location_volume",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_NAMED_LOCATION_VOLUME_BLOCK_STRUCT_ID)
	{
		{ _field_block, "points", &named_location_volume_point_block },
		{ _field_real, "height" },
		{ _field_real, "sink" },
		{ _field_string_id, "location name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define NAMED_LOCATION_VOLUME_POINT_BLOCK_ID { 0x93E2B78A, 0x31554713, 0x814F05D1, 0xE48C66BB }
	TAG_BLOCK(
		named_location_volume_point_block,
		"named_location_volume_point_block",
		k_maximum_points_per_sector,
		"s_real_sector_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		NAMED_LOCATION_VOLUME_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

