#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(cs_script_data, 1)
{
	{ _field_block, "point sets", &cs_point_set_block },
	{ _field_block, "animation points", &cs_animation_point_block },
	{ _field_pad, "TPHWNCUR", 120 },
	{ _field_terminator },
};

TAG_BLOCK(cs_point_set, k_max_point_sets_per_map)
{
	{ _field_string, "name^" },
	{ _field_block, "points", &cs_point_block },
	{ _field_short_block_index, "bsp index" },
	{ _field_pad, "PAD1", 2 },
	{ _field_long_flags, "flags" },
	{ _field_long_flags, "traversal flags" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_pad, "AJDEYNFD", 2 },
	{ _field_terminator },
};

TAG_BLOCK(cs_point, 32)
{
	{ _field_string, "name^" },
	{ _field_string_id, "name_id*!" },
	{ _field_real_point_3d, "position" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "facing direction" },
	{ _field_terminator },
};

TAG_BLOCK(cs_animation_point, k_max_animation_points_per_map)
{
	{ _field_string, "name^" },
	{ _field_long_block_index, "Animating Object" },
	{ _field_long_integer, "Animating Object Index!" },
	{ _field_string_id, "Animation Name" },
	{ _field_long_integer, "Animation Bone to Track" },
	{ _field_real_point_3d, "Offset From Bone" },
	{ _field_real, "Animation Time Offset" },
	{ _field_real, "Assumed Playback Rate" },
	{ _field_terminator },
};

} // namespace blofeld

