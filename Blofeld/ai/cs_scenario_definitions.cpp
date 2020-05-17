#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(cs_point_block, 32)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_string_id, "name_id*!" ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
		FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
		FIELD( _field_real_euler_angles_2d, "facing direction" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cs_point_set_block, k_max_point_sets_per_map)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_block, "points", &cs_point_block_block ),
		FIELD( _field_short_block_index, "bsp index" ),
		FIELD( _field_pad, "PAD1", 2 ),
		FIELD( _field_long_flags, "flags", &point_set_flags ),
		FIELD( _field_long_flags, "traversal flags", &point_set_traversal_flags ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_pad, "AJDEYNFD", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cs_animation_point_block, k_max_animation_points_per_map)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_long_block_index, "Animating Object" ),
		FIELD( _field_long_integer, "Animating Object Index!" ),
		FIELD( _field_string_id, "Animation Name" ),
		FIELD( _field_long_integer, "Animation Bone to Track" ),
		FIELD( _field_real_point_3d, "Offset From Bone" ),
		FIELD( _field_real, "Animation Time Offset" ),
		FIELD( _field_real, "Assumed Playback Rate" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cs_script_data_block, 1)
	{
		FIELD( _field_block, "point sets", &cs_point_set_block_block ),
		FIELD( _field_block, "animation points", &cs_animation_point_block_block ),
		FIELD( _field_pad, "TPHWNCUR", 120 ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(point_set_flags, 4)
	{
		OPTION("manual reference frame"),
		OPTION("turret deployment"),
		OPTION("giant set"),
		OPTION("invalid sector refs"),
	};

	TAG_ENUM(point_set_traversal_flags, 2)
	{
		OPTION("curve the traversal path"),
		OPTION("loop when end is reached"),
	};

} // namespace blofeld

