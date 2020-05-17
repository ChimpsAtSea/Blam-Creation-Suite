#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(formation_primitive_flags, 2)
	{
		OPTION("radial"),
		OPTION("leader"),
	};

	TAG_GROUP(formation, FORMATION_TAG)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "primitives", &formation_primitive_definition_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(formation_primitive_definition, k_max_primitives_per_formation)
	{
		FIELD( _field_explanation, "" ),
		FIELD( _field_word_flags, "flags", &formation_primitive_flags ),
		FIELD( _field_short_integer, "priority" ),
		FIELD( _field_short_integer, "capacity*!" ),
		FIELD( _field_pad, "post-capacity-pad", 2 ),
		FIELD( _field_real, "dist forwards" ),
		FIELD( _field_real, "dist backwards" ),
		FIELD( _field_real, "rank spacing" ),
		FIELD( _field_real, "file spacing" ),
		FIELD( _field_block, "points", &formation_point_definition_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(formation_point_definition, k_max_points_per_primitive)
	{
		FIELD( _field_explanation, "" ),
		FIELD( _field_angle, "angle" ),
		FIELD( _field_real, "offset" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

