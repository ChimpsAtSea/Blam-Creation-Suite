#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define FORMATION_STRUCT_DEFINITION_ID { 0x5D813D70, 0x900F4DC8, 0x9167C364, 0x5A2BA310 }
	TAG_BLOCK(
		formation_block,
		"formation_block",
		1,
		"s_formation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FORMATION_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
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
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FORMATION_PRIMITIVE_DEFINITION_ID)
	{
		FIELD_EXPLANATION_EX(nullptr, nullptr, FIELD_FLAG_NONE, ""),
		{ _field_word_flags, "flags", &formation_primitive_flags },
		{ _field_short_integer, "priority" },
		{ _field_short_integer, "capacity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("post-capacity-pad", nullptr, FIELD_FLAG_NONE, 2),
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
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FORMATION_POINT_DEFINITION_ID)
	{
		FIELD_EXPLANATION_EX(nullptr, nullptr, FIELD_FLAG_NONE, ""),
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



} // namespace blofeld

