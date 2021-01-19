#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define PATHFINDING_STRUCT_DEFINITION_ID { 0xD3F52F17, 0x90744223, 0x826FDF85, 0xF45838AC }
	TAG_BLOCK(
		pathfinding_block,
		"pathfinding_block",
		1,
		"ai_pathfinding",
		PATHFINDING_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "bsp pathfinding data", &pathfinding_data_block },
		{ _field_block, "mobileNavMeshes*~", &MobileNavMeshBlock_block },
		{ _field_block, "navVolumes*~", &NavVolumeBlock_block },
		{ _field_block, "navClimbs*~", &NavClimbBlock_block },
		{ _field_block, "user edges*~", &user_edge_block },
		{ _field_block, "hints", &user_hint_block },
		{ _field_byte_integer, "already Converted!" },
		{ _field_pad, "fuckPad", 3 },
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
		PATHFINDING_DATA_BLOCK_ID,
		4)
	{
		{ _field_long_integer, "runtimeNavMesh*~!", nullptr, 'nuke' },
		{ _field_long_integer, "runtimeNavGraph*~!", nullptr, 'nuke' },
		{ _field_long_integer, "runtimeNavMediator*~!", nullptr, 'nuke' },
		{ _field_pad, "pads", 4 },
		{ _field_data, "navGraphData*~" },
		{ _field_data, "navMediatorData*~" },
		{ _field_block, "faceUserData*~", &FaceUserDataBlock_block },
		{ _field_long_integer, "structure checksum*~" },
		{ _field_pad, "pads2", 8 },
		{ _field_terminator }
	};

	#define FACEUSERDATABLOCK_ID { 0x40F96E3C, 0xA1EA4642, 0x9824E997, 0x515857CB }
	TAG_BLOCK(
		FaceUserDataBlock_block,
		"FaceUserDataBlock",
		256*1024,
		"FaceUserData",
		FACEUSERDATABLOCK_ID)
	{
		{ _field_short_integer, "m_flags*~" },
		{ _field_pad, "pad", 2 },
		{ _field_real, "currentMinPathDistance!*~" },
		{ _field_real, "currentMinTargetApproachDistance!*~" },
		{ _field_terminator }
	};

	#define MOBILENAVMESHBLOCK_ID { 0x9417C730, 0x26644159, 0x9CEB6CB2, 0x8574A920 }
	TAG_BLOCK(
		MobileNavMeshBlock_block,
		"MobileNavMeshBlock",
		MAX_NUM_MOBILE_NAVMESHES,
		"MobileNavMesh",
		MOBILENAVMESHBLOCK_ID,
		4)
	{
		{ _field_long_integer, "runtimeNavMesh*~!", nullptr, 'nuke' },
		{ _field_long_integer, "runtimeNavGraph*~!", nullptr, 'nuke' },
		{ _field_long_integer, "runtimeNavMediator*~!", nullptr, 'nuke' },
		{ _field_pad, "pads2", 4 },
		{ _field_data, "navGraphData*~" },
		{ _field_data, "navMediatorData*~" },
		{ _field_block, "faceUserData*~", &FaceUserDataBlock_block },
		{ _field_struct, "object id", &scenario_object_id_struct },
		{ _field_byte_flags, "flags", &MobileNavMeshFlagsDefinition },
		{ _field_pad, "pads", 3 },
		{ _field_terminator }
	};

	#define NAVVOLUMEBLOCK_ID { 0x967C1DD5, 0x6B6D4334, 0x884F288F, 0xD1AEBBC8 }
	TAG_BLOCK(
		NavVolumeBlock_block,
		"NavVolumeBlock",
		MAX_NUM_NAV_VOLUMES,
		"NavVolume",
		NAVVOLUMEBLOCK_ID)
	{
		{ _field_short_integer, "zoneIndex*~" },
		{ _field_short_integer, "areaIndex*~" },
		{ _field_long_integer, "runtimeNavVolume*~!", nullptr, 'nuke' },
		{ _field_long_integer, "runtimeNavMediator*~!", nullptr, 'nuke' },
		{ _field_data, "navMediatorData*~" },
		{ _field_terminator }
	};

	#define NAVCLIMBBLOCK_ID { 0x5C34E203, 0xF75D4F21, 0xB9392D66, 0x4B604601 }
	TAG_BLOCK(
		NavClimbBlock_block,
		"NavClimbBlock",
		MAX_NUM_NAV_CLIMBS,
		"NavClimb",
		NAVCLIMBBLOCK_ID,
		4)
	{
		{ _field_long_integer, "runtimeNavMesh*~!", nullptr, 'nuke' },
		{ _field_long_integer, "runtimeNavGraph*~!", nullptr, 'nuke' },
		{ _field_long_integer, "runtimeNavMediator*~!", nullptr, 'nuke' },
		{ _field_pad, "pads", 4 },
		{ _field_data, "navGraphData*~" },
		{ _field_data, "navMediatorData*~" },
		{ _field_block, "faceUserData*~", &FaceUserDataBlock_block },
		{ _field_short_integer, "zoneIndex*~" },
		{ _field_short_integer, "areaIndex*~" },
		{ _field_pad, "pads2", 8 },
		{ _field_terminator }
	};

	#define USER_EDGE_BLOCK_ID { 0x4DBD3F0D, 0x82D242CD, 0xA695A5CE, 0x2C7C98DB }
	TAG_BLOCK(
		user_edge_block,
		"user_edge_block",
		4*1024,
		"hkaiUserEdgeUtils::UserEdgePair",
		USER_EDGE_BLOCK_ID,
		4)
	{
		{ _field_real_vector_3d, "m_x*~" },
		{ _field_real, "havok w m_x*~!" },
		{ _field_real_vector_3d, "m_y*~" },
		{ _field_real, "havok w m_y*~!" },
		{ _field_real_vector_3d, "m_z*~" },
		{ _field_real, "havok w m_z*~!" },
		{ _field_long_integer, "m_meshUidA*~" },
		{ _field_long_integer, "m_meshUidB*~" },
		{ _field_long_integer, "m_faceA*~" },
		{ _field_long_integer, "m_faceB*~" },
		{ _field_long_integer, "m_userDataA*~" },
		{ _field_long_integer, "m_userDataB*~" },
		{ _field_short_integer, "m_costAtoB*~" },
		{ _field_short_integer, "m_costBtoA*~" },
		{ _field_char_integer, "m_direction*~" },
		{ _field_pad, "padding", 3 },
		{ _field_terminator }
	};

	STRINGS(MobileNavMeshFlagsDefinition)
	{
		"always loaded"
	};
	STRING_LIST(MobileNavMeshFlagsDefinition, MobileNavMeshFlagsDefinition_strings, _countof(MobileNavMeshFlagsDefinition_strings));

} // namespace macaque

} // namespace blofeld

