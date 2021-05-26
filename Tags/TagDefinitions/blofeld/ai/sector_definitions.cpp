#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define PATHFINDING_STRUCT_DEFINITION_ID { 0xD3F52F17, 0x90744223, 0x826FDF85, 0xF45838AC }
	TAG_BLOCK(
		pathfinding_block,
		"pathfinding_block",
		1,
		"ai_pathfinding",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		PATHFINDING_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "bsp pathfinding data", &pathfinding_data_block },
		{ _field_block, "mobileNavMeshes", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &MobileNavMeshBlock_block },
		{ _field_block, "navVolumes", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &NavVolumeBlock_block },
		{ _field_block, "navClimbs", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &NavClimbBlock_block },
		{ _field_block, "user edges", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &user_edge_block },
		{ _field_block, "hints", &user_hint_block },
		{ _field_byte_integer, "already Converted", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("fuckPad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	TAG_GROUP(
		pathfinding_group,
		PATHFINDING_TAG,
		nullptr,
		INVALID_TAG,
		pathfinding_block );

	#define PATHFINDING_DATA_BLOCK_ID { 0xD935AB3C, 0x86AC4216, 0xBCB736BB, 0x9AE0727C }
	TAG_BLOCK(
		pathfinding_data_block,
		"pathfinding_data_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"pathfinding_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		PATHFINDING_DATA_BLOCK_ID,
		4)
	{
		{ _field_long_integer, "runtimeNavMesh", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "runtimeNavGraph", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "runtimeNavMediator", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		FIELD_PAD("pads", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_data, "navGraphData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_data, "navMediatorData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_block, "faceUserData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &FaceUserDataBlock_block },
		{ _field_long_integer, "structure checksum", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("pads2", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	#define FACEUSERDATABLOCK_ID { 0x40F96E3C, 0xA1EA4642, 0x9824E997, 0x515857CB }
	TAG_BLOCK(
		FaceUserDataBlock_block,
		"FaceUserDataBlock",
		256*1024,
		"FaceUserData",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		FACEUSERDATABLOCK_ID)
	{
		{ _field_short_integer, "m_flags", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "currentMinPathDistance", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "currentMinTargetApproachDistance", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_terminator }
	};

	#define MOBILENAVMESHBLOCK_ID { 0x9417C730, 0x26644159, 0x9CEB6CB2, 0x8574A920 }
	TAG_BLOCK(
		MobileNavMeshBlock_block,
		"MobileNavMeshBlock",
		MAX_NUM_MOBILE_NAVMESHES,
		"MobileNavMesh",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		MOBILENAVMESHBLOCK_ID,
		4)
	{
		{ _field_long_integer, "runtimeNavMesh", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "runtimeNavGraph", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "runtimeNavMediator", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		FIELD_PAD("pads2", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_data, "navGraphData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_data, "navMediatorData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_block, "faceUserData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &FaceUserDataBlock_block },
		{ _field_struct, "object id", &scenario_object_id_struct },
		{ _field_byte_flags, "flags", &MobileNavMeshFlagsDefinition },
		FIELD_PAD("pads", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define NAVVOLUMEBLOCK_ID { 0x967C1DD5, 0x6B6D4334, 0x884F288F, 0xD1AEBBC8 }
	TAG_BLOCK(
		NavVolumeBlock_block,
		"NavVolumeBlock",
		MAX_NUM_NAV_VOLUMES,
		"NavVolume",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		NAVVOLUMEBLOCK_ID)
	{
		{ _field_short_integer, "zoneIndex", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "areaIndex", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "runtimeNavVolume", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "runtimeNavMediator", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_data, "navMediatorData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_terminator }
	};

	#define NAVCLIMBBLOCK_ID { 0x5C34E203, 0xF75D4F21, 0xB9392D66, 0x4B604601 }
	TAG_BLOCK(
		NavClimbBlock_block,
		"NavClimbBlock",
		MAX_NUM_NAV_CLIMBS,
		"NavClimb",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		NAVCLIMBBLOCK_ID,
		4)
	{
		{ _field_long_integer, "runtimeNavMesh", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "runtimeNavGraph", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "runtimeNavMediator", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		FIELD_PAD("pads", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_data, "navGraphData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_data, "navMediatorData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_block, "faceUserData", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &FaceUserDataBlock_block },
		{ _field_short_integer, "zoneIndex", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "areaIndex", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("pads2", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	#define USER_EDGE_BLOCK_ID { 0x4DBD3F0D, 0x82D242CD, 0xA695A5CE, 0x2C7C98DB }
	TAG_BLOCK(
		user_edge_block,
		"user_edge_block",
		4*1024,
		"hkaiUserEdgeUtils::UserEdgePair",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		USER_EDGE_BLOCK_ID,
		4)
	{
		{ _field_real_vector_3d, "m_x", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "havok w m_x", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_vector_3d, "m_y", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "havok w m_y", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_vector_3d, "m_z", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "havok w m_z", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_meshUidA", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_meshUidB", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_faceA", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_faceB", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_userDataA", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_userDataB", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "m_costAtoB", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "m_costBtoA", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_char_integer, "m_direction", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("padding", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	STRINGS(MobileNavMeshFlagsDefinition)
	{
		"always loaded"
	};
	STRING_LIST(MobileNavMeshFlagsDefinition, MobileNavMeshFlagsDefinition_strings, _countof(MobileNavMeshFlagsDefinition_strings));



} // namespace blofeld

