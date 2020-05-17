#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(firing_positions_block, k_max_firing_positions_per_zone)
	{
		FIELD( _field_explanation, "CONTROLS~" ),
		FIELD( _field_real_point_3d, "position (local)" ),
		FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
		FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
		FIELD( _field_word_flags, "flags*", &g_firing_position_flags ),
		FIELD( _field_word_flags, "posture flags", &g_firing_position_posture_flags ),
		FIELD( _field_short_block_index, "area^" ),
		FIELD( _field_short_integer, "cluster index*" ),
		FIELD( _field_short_integer, "cluster bsp*" ),
		FIELD( _field_char_integer, "bits and pad!" ),
		FIELD( _field_pad, "PAD1", 1 ),
		FIELD( _field_real_euler_angles_2d, "normal" ),
		FIELD( _field_custom ),
		FIELD( _field_angle, "facing" ),
		FIELD( _field_long_integer, "lastAbsoluteRejectionGameTime!" ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(g_firing_position_flags, 10)
	{
		OPTION("open"),
		OPTION("partial"),
		OPTION("closed"),
		OPTION("mobile"),
		OPTION("wall lean"),
		OPTION("perch"),
		OPTION("ground point"),
		OPTION("dynamic cover point"),
		OPTION("automatically generated!"),
		OPTION("nav volume"),
	};

	TAG_ENUM(g_firing_position_posture_flags, 5)
	{
		OPTION("corner_left"),
		OPTION("corner_right"),
		OPTION("bunker"),
		OPTION("bunker high"),
		OPTION("bunker low"),
	};

} // namespace blofeld

