#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(point_physics, POINT_PHYSICS_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_real, "runtime mass over radius cubed!" },
	{ _field_real, "runtime inverse density!" },
	{ _field_long_integer, "IGNORE1!" },
	{ _field_long_integer, "IGNORE2!" },
	{ _field_long_integer, "IGNORE3!" },
	{ _field_long_integer, "IGNORE4!" },
	{ _field_long_integer, "IGNORE5!" },
	{ _field_real, "density:g/mL" },
	{ _field_real, "air friction" },
	{ _field_real, "water friction" },
	{ _field_real, "surface friction#when hitting the ground or interior, percentage of velocity lost in one collision" },
	{ _field_real, "elasticity#0.0 is inelastic collisions (no bounce) 1.0 is perfectly elastic (reflected velocity equals incoming velocity)" },
	{ _field_pad, "DR", 12 },
	{ _field_explanation, "Densities (g/mL)" },
	{ _field_terminator },
};

} // namespace blofeld

