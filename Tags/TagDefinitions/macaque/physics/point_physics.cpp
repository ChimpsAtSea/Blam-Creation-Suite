#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		point_physics_group,
		POINT_PHYSICS_TAG,
		nullptr,
		INVALID_TAG,
		point_physics_block );

	TAG_BLOCK_FROM_STRUCT(
		point_physics_block,
		"point_physics_block",
		1,
		point_physics_struct_definition);

	#define POINT_PHYSICS_STRUCT_DEFINITION_ID { 0x25622995, 0xA9214233, 0x8BD5DA29, 0xE1C6CC0A }
	TAG_STRUCT(
		point_physics_struct_definition,
		"point_physics_struct_definition",
		"point_physics_definition",
		POINT_PHYSICS_STRUCT_DEFINITION_ID)
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
		{ _field_explanation, "Densities (g/mL)", "air        0.0011 (g/mL)\nsnow       0.128\ncork       0.24\ncedar      0.43\noak        0.866\nice        0.897\nwater      1.0\nsoil       1.1\ncotton     1.491\ndry earth  1.52\nsand       1.7\ngranite    2.4\nglass      2.5\niron       7.65\nsteel      7.77\nlead       11.37\nuranium    18.74\ngold       19.3\n" },
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

} // namespace macaque

} // namespace blofeld

