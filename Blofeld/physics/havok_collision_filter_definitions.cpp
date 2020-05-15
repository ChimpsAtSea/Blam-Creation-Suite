#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(havok_collision_filter_group, k_havok_group_count)
{
	FIELD( _field_long_flags, "filter" ),
	FIELD( _field_terminator )
};

TAG_GROUP(havok_collision_filter, HAVOK_COLLISION_FILTER_TAG)
{
	FIELD( _field_explanation, "specify what each group collides with" ),
	FIELD( _field_block, "groups", &havok_collision_filter_group_block ),
	FIELD( _field_pad, "alignment_pad", 4 ),
	FIELD( _field_struct, "group filter*!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

