#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(pathfinding, PATHFINDING_TAG)
	{
		FIELD( _field_block, "bsp pathfinding data", &pathfinding_data_block_block ),
		FIELD( _field_block, "mobileNavMeshes*~", &MobileNavMeshBlock_block ),
		FIELD( _field_block, "navVolumes*~", &NavVolumeBlock_block ),
		FIELD( _field_block, "navClimbs*~", &NavClimbBlock_block ),
		FIELD( _field_block, "user edges*~", &user_edge_block_block ),
		FIELD( _field_block, "hints", &user_hint_block_block ),
		FIELD( _field_byte_integer, "already Converted!" ),
		FIELD( _field_pad, "fuckPad", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(FaceUserDataBlock, 256*1024)
	{
		FIELD( _field_short_integer, "m_flags*~" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_real, "currentMinPathDistance!*~" ),
		FIELD( _field_real, "currentMinTargetApproachDistance!*~" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(pathfinding_data_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_long_integer, "runtimeNavMesh*~!" ),
		FIELD( _field_long_integer, "runtimeNavGraph*~!" ),
		FIELD( _field_long_integer, "runtimeNavMediator*~!" ),
		FIELD( _field_pad, "pads", 4 ),
		FIELD( _field_data, "navGraphData*~" ),
		FIELD( _field_data, "navMediatorData*~" ),
		FIELD( _field_block, "faceUserData*~", &FaceUserDataBlock_block ),
		FIELD( _field_long_integer, "structure checksum*~" ),
		FIELD( _field_pad, "pads2", 8 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(MobileNavMeshBlock, MAX_NUM_MOBILE_NAVMESHES)
	{
		FIELD( _field_long_integer, "runtimeNavMesh*~!" ),
		FIELD( _field_long_integer, "runtimeNavGraph*~!" ),
		FIELD( _field_long_integer, "runtimeNavMediator*~!" ),
		FIELD( _field_pad, "pads2", 4 ),
		FIELD( _field_data, "navGraphData*~" ),
		FIELD( _field_data, "navMediatorData*~" ),
		FIELD( _field_block, "faceUserData*~", &FaceUserDataBlock_block ),
		FIELD( _field_struct, "object id", &scenario_object_id_struct_struct_definition ),
		FIELD( _field_byte_flags, "flags", &MobileNavMeshFlagsDefinition ),
		FIELD( _field_pad, "pads", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(NavVolumeBlock, MAX_NUM_NAV_VOLUMES)
	{
		FIELD( _field_short_integer, "zoneIndex*~" ),
		FIELD( _field_short_integer, "areaIndex*~" ),
		FIELD( _field_long_integer, "runtimeNavVolume*~!" ),
		FIELD( _field_long_integer, "runtimeNavMediator*~!" ),
		FIELD( _field_data, "navMediatorData*~" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(NavClimbBlock, MAX_NUM_NAV_CLIMBS)
	{
		FIELD( _field_long_integer, "runtimeNavMesh*~!" ),
		FIELD( _field_long_integer, "runtimeNavGraph*~!" ),
		FIELD( _field_long_integer, "runtimeNavMediator*~!" ),
		FIELD( _field_pad, "pads", 4 ),
		FIELD( _field_data, "navGraphData*~" ),
		FIELD( _field_data, "navMediatorData*~" ),
		FIELD( _field_block, "faceUserData*~", &FaceUserDataBlock_block ),
		FIELD( _field_short_integer, "zoneIndex*~" ),
		FIELD( _field_short_integer, "areaIndex*~" ),
		FIELD( _field_pad, "pads2", 8 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(user_edge_block, 4*1024)
	{
		FIELD( _field_real_vector_3d, "m_x*~" ),
		FIELD( _field_real, "havok w m_x*~!" ),
		FIELD( _field_real_vector_3d, "m_y*~" ),
		FIELD( _field_real, "havok w m_y*~!" ),
		FIELD( _field_real_vector_3d, "m_z*~" ),
		FIELD( _field_real, "havok w m_z*~!" ),
		FIELD( _field_long_integer, "m_meshUidA*~" ),
		FIELD( _field_long_integer, "m_meshUidB*~" ),
		FIELD( _field_long_integer, "m_faceA*~" ),
		FIELD( _field_long_integer, "m_faceB*~" ),
		FIELD( _field_long_integer, "m_userDataA*~" ),
		FIELD( _field_long_integer, "m_userDataB*~" ),
		FIELD( _field_short_integer, "m_costAtoB*~" ),
		FIELD( _field_short_integer, "m_costBtoA*~" ),
		FIELD( _field_char_integer, "m_direction*~" ),
		FIELD( _field_pad, "padding", 3 ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(MobileNavMeshFlagsDefinition, 1)
	{
		OPTION("always loaded"),
	};

} // namespace blofeld

