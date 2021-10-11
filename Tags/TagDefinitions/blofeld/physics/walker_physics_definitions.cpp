#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define WALKER_PHYSICS_LEG_BLOCK_ID { 0x3DED37EB, 0xB2934219, 0x901F0006, 0x75D3AF53 }
	TAG_BLOCK(
		walker_physics_leg_block,
		"walker_physics_leg_block",
		s_walker_physics_definition::k_maximum_leg_count,
		"s_walker_physics_leg",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WALKER_PHYSICS_LEG_BLOCK_ID)
	{
		FIELD_EXPLANATION_EX("walker physics", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_char_enum, "leg group", &walker_physics_leg_group_enum },
		{ _field_char_enum, "leg side", &walker_physics_leg_side_enum },
		{ _field_char_integer, "leg side order", "for each side order the legs from 0-n where 0 is the most forward leg" },
		{ _field_char_integer, "valid", FIELD_FLAG_UNKNOWN0 },
		{ _field_string_id, "hip node a name" },
		{ _field_string_id, "hip node b name" },
		{ _field_string_id, "knee node a name" },
		{ _field_string_id, "knee node b name" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "foot marker name" },
		FIELD_PAD_EX("RLTGT", nullptr, FIELD_FLAG_NONE, 60),
		{ _field_long_flags, "flags", &walker_physics_leg_flags },
		{ _field_real_vector_3d, "runtime initial origin to hip offset", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_vector_3d, "runtime pivot center to hip offset", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime upper leg length", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime lower leg length", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime hip node a index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime hip node b index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime knee node a index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime knee node b index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime foot marker group index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime foot node index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime hip node index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime knee node index", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_vector_3d, "plant constraint position", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD_EX("GKX", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	#define WALKER_PHYSICS_STRUCT_ID { 0x769D2C0D, 0xAEF54395, 0x86ECFA87, 0xB067AB04 }
	TAG_STRUCT(
		walker_physics_struct,
		"walker_physics_struct",
		"s_walker_physics_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WALKER_PHYSICS_STRUCT_ID)
	{
		{ _field_real_vector_3d, "maximum leg motion", "in WU, how far can we displace the legs in x,y,z each step" },
		{ _field_real, "maximum turn", "in degrees, how much can this walker turn in one step" },
		{ _field_block, "legs", &walker_physics_leg_block },
		{ _field_real, "leg apex fraction", "0-1 fraction.  where the leg tansitions from lift to drop" },
		{ _field_real, "lift exponent", "x(0-1) power exponent" },
		{ _field_real, "drop exponent", "x(0-1) power exponent" },
		{ _field_real_vector_3d, "object space pivot position", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	STRINGS(walker_physics_leg_group_enum)
	{
		"primary",
		"secondary"
	};
	STRING_LIST(walker_physics_leg_group_enum, walker_physics_leg_group_enum_strings, _countof(walker_physics_leg_group_enum_strings));

	STRINGS(walker_physics_leg_side_enum)
	{
		"left",
		"right"
	};
	STRING_LIST(walker_physics_leg_side_enum, walker_physics_leg_side_enum_strings, _countof(walker_physics_leg_side_enum_strings));

	STRINGS(walker_physics_leg_flags)
	{
		"constrained plant"
	};
	STRING_LIST(walker_physics_leg_flags, walker_physics_leg_flags_strings, _countof(walker_physics_leg_flags_strings));



} // namespace blofeld

