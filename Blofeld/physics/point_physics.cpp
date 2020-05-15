#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(point_physics, POINT_PHYSICS_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "runtime mass over radius cubed!" ),
	FIELD( _field_real, "runtime inverse density!" ),
	FIELD( _field_long_integer, "IGNORE1!" ),
	FIELD( _field_long_integer, "IGNORE2!" ),
	FIELD( _field_long_integer, "IGNORE3!" ),
	FIELD( _field_long_integer, "IGNORE4!" ),
	FIELD( _field_long_integer, "IGNORE5!" ),
	FIELD( _field_real, "density:g/mL" ),
	FIELD( _field_real, "air friction" ),
	FIELD( _field_real, "water friction" ),
	FIELD( _field_real, "surface friction#when hitting the ground or interior, percentage of velocity lost in one collision" ),
	FIELD( _field_real, "elasticity#0.0 is inelastic collisions (no bounce) 1.0 is perfectly elastic (reflected velocity equals incoming velocity)" ),
	FIELD( _field_pad, "DR", 12 ),
	FIELD( _field_explanation, "Densities (g/mL)" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

