#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(firing_positions, k_max_firing_positions_per_zone)
{
	{ _field_explanation, "CONTROLS~" },
	{ _field_real_point_3d, "position (local)" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_word_flags, "flags*" },
	{ _field_word_flags, "posture flags" },
	{ _field_short_block_index, "area^" },
	{ _field_short_integer, "cluster index*" },
	{ _field_short_integer, "cluster bsp*" },
	{ _field_char_integer, "bits and pad!" },
	{ _field_pad, "PAD1", 1 },
	{ _field_real_euler_angles_2d, "normal" },
	{ _field_custom },
	{ _field_angle, "facing" },
	{ _field_long_integer, "lastAbsoluteRejectionGameTime!" },
	{ _field_terminator },
};

} // namespace blofeld

