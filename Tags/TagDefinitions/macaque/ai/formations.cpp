#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define FORMATION_STRUCT_DEFINITION_ID { 0x5D813D70, 0x900F4DC8, 0x9167C364, 0x5A2BA310 }
	TAG_BLOCK(
		formation_block,
		"formation_block",
		1,
		"s_formation_definition",
		FORMATION_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "name" },
		{ _field_block, "primitives", &formation_primitive_definition_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		formation_group,
		FORMATION_TAG,
		nullptr,
		INVALID_TAG,
		formation_block );

	#define FORMATION_PRIMITIVE_DEFINITION_ID { 0x8FA0D708, 0xB9F34F88, 0x85458122, 0xCCCA2133 }
	TAG_BLOCK(
		formation_primitive_definition_block,
		"formation_primitive_definition",
		k_max_primitives_per_formation,
		"s_formation_primitive",
		FORMATION_PRIMITIVE_DEFINITION_ID)
	{
		{ _field_explanation, "", "" },
		{ _field_word_flags, "flags", &formation_primitive_flags },
		{ _field_short_integer, "priority" },
		{ _field_short_integer, "capacity" },
		FIELD_PAD("post-capacity-pad", nullptr, 2),
		{ _field_real, "dist forwards" },
		{ _field_real, "dist backwards" },
		{ _field_real, "rank spacing" },
		{ _field_real, "file spacing" },
		{ _field_block, "points", &formation_point_definition_block },
		{ _field_terminator }
	};

	#define FORMATION_POINT_DEFINITION_ID { 0x23ABAAB1, 0xA504407E, 0xA02EA842, 0x827B6483 }
	TAG_BLOCK(
		formation_point_definition_block,
		"formation_point_definition",
		k_max_points_per_primitive,
		"s_formation_point",
		FORMATION_POINT_DEFINITION_ID)
	{
		{ _field_explanation, "", "" },
		{ _field_angle, "angle" },
		{ _field_real, "offset" },
		{ _field_terminator }
	};

	STRINGS(formation_primitive_flags)
	{
		"radial",
		"leader"
	};
	STRING_LIST(formation_primitive_flags, formation_primitive_flags_strings, _countof(formation_primitive_flags_strings));

} // namespace macaque

} // namespace blofeld

