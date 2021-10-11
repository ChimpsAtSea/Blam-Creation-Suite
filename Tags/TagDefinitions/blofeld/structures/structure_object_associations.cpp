#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define STRUCTURE_PORTAL_DEVICE_MAPPING_BLOCK_ID { 0xF9BA6A28, 0xBF964539, 0xBB2BA621, 0x11162D6C }
	TAG_BLOCK(
		structure_portal_device_mapping_block,
		"structure_portal_device_mapping_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_structure_portal_device_map",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_PORTAL_DEVICE_MAPPING_BLOCK_ID)
	{
		{ _field_block, "device portal associations", &structure_device_portal_association_block },
		{ _field_block, "game portal to portal map", &game_portal_to_portal_mapping_block },
		{ _field_block, "occluding portal to portal map", &occluding_portal_to_portal_mapping_block },
		{ _field_terminator }
	};

	#define STRUCTURE_DEVICE_PORTAL_ASSOCIATION_BLOCK_ID { 0xB39054AF, 0x2CB3457E, 0x844CFA19, 0x64B70FB3 }
	TAG_BLOCK(
		structure_device_portal_association_block,
		"structure_device_portal_association_block",
		k_maximum_machine_door_portal_associations,
		"s_structure_portal_device_machine_association",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_DEVICE_PORTAL_ASSOCIATION_BLOCK_ID)
	{
		{ _field_struct, "device id", &scenario_object_id_struct },
		{ _field_short_integer, "first game portal index" },
		{ _field_word_integer, "game portal count" },
		{ _field_terminator }
	};

	#define GAME_PORTAL_TO_PORTAL_MAPPING_BLOCK_ID { 0xB0BFEAC7, 0x25274FE1, 0xBAC1087B, 0x16519CB7 }
	TAG_BLOCK(
		game_portal_to_portal_mapping_block,
		"game_portal_to_portal_mapping_block",
		k_maximum_machine_door_portal_associations,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_PORTAL_TO_PORTAL_MAPPING_BLOCK_ID)
	{
		{ _field_short_integer, "portal index" },
		{ _field_terminator }
	};

	#define OCCLUDING_PORTAL_TO_PORTAL_MAPPING_BLOCK_ID { 0x2C0DB1E1, 0xB4BF44D2, 0xA25D8986, 0x1E698E9F }
	TAG_BLOCK(
		occluding_portal_to_portal_mapping_block,
		"occluding_portal_to_portal_mapping_block",
		k_maximum_occluding_portal_associations,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		OCCLUDING_PORTAL_TO_PORTAL_MAPPING_BLOCK_ID)
	{
		{ _field_short_integer, "portal index" },
		{ _field_terminator }
	};



} // namespace blofeld

