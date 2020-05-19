#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(point_physics, POINT_PHYSICS_TAG, point_physics_block_block );

	TAG_BLOCK_FROM_STRUCT(point_physics_block, 1, point_physics_struct_definition_struct_definition );

	TAG_STRUCT(point_physics_struct_definition)
	{
		{ _field_long_flags, "flags", &point_physics_definition_flags },
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
		{ _field_terminator }
	};

	STRINGS(point_physics_definition_flags)
	{
		"UNUSED",
		"collides with structures",
		"collides with water surface",
		"uses simple wind#the wind on this point won\'t have high-frequency variations",
		"uses damped wind#the wind on this point will be artificially slow",
		"no gravity#the point is not affected by gravity"
	};
	STRING_LIST(point_physics_definition_flags, point_physics_definition_flags_strings, _countof(point_physics_definition_flags_strings));

	TAG_REFERENCE(global_point_physics_reference, POINT_PHYSICS_TAG);

} // namespace blofeld

