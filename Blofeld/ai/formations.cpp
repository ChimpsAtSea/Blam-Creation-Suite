#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(formation_primitive_definition, k_max_primitives_per_formation)
{
	{ _field_explanation, "" },
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "priority" },
	{ _field_short_integer, "capacity*!" },
	{ _field_pad, "post-capacity-pad", 2 },
	{ _field_real, "dist forwards" },
	{ _field_real, "dist backwards" },
	{ _field_real, "rank spacing" },
	{ _field_real, "file spacing" },
	{ _field_block, "points", &formation_point_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(formation_point_definition, k_max_points_per_primitive)
{
	{ _field_explanation, "" },
	{ _field_angle, "angle" },
	{ _field_real, "offset" },
	{ _field_terminator },
};

TAG_GROUP(formation, FORMATION_TAG)
{
	{ _field_string_id, "name^" },
	{ _field_block, "primitives", &formation_primitive_definition_block },
	{ _field_terminator },
};

} // namespace blofeld

