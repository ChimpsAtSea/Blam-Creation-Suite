#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(havok_collision_filter_group, k_havok_group_count)
{
	{ _field_long_flags, "filter" },
	{ _field_terminator },
};

TAG_GROUP(havok_collision_filter, HAVOK_COLLISION_FILTER_TAG)
{
	{ _field_explanation, "specify what each group collides with" },
	{ _field_block, "groups", &havok_collision_filter_group_block },
	{ _field_pad, "alignment_pad", 4 },
	{ _field_struct, "group filter*!" },
	{ _field_terminator },
};

} // namespace blofeld

