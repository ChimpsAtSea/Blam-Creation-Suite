#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define WALKER_PHYSICS_LEG_BLOCK_ID { 0x3DED37EB, 0xB2934219, 0x901F0006, 0x75D3AF53 }
	TAG_BLOCK(
		walker_physics_leg_block,
		"walker_physics_leg_block",
		s_walker_physics_definition::k_maximum_leg_count,
		"s_walker_physics_leg",
		WALKER_PHYSICS_LEG_BLOCK_ID)
	{
		{ _field_explanation, "walker physics", "" },
		{ _field_char_enum, "leg group", &walker_physics_leg_group_enum },
		{ _field_char_enum, "leg side", &walker_physics_leg_side_enum },
		{ _field_char_integer, "leg side order#for each side order the legs from 0-n where 0 is the most forward leg" },
		{ _field_char_integer, "valid!" },
		{ _field_string_id, "hip node a name" },
		{ _field_string_id, "hip node b name" },
		{ _field_string_id, "knee node a name" },
		{ _field_string_id, "knee node b name" },
		FIELD_CUSTOM(nullptr, _custom_field_marker),
		{ _field_string_id, "foot marker name" },
		{ _field_pad, "RLTGT", 60 },
		{ _field_long_flags, "flags", &walker_physics_leg_flags },
		{ _field_real_vector_3d, "runtime initial origin to hip offset!" },
		{ _field_real_vector_3d, "runtime pivot center to hip offset!" },
		{ _field_real, "runtime upper leg length!" },
		{ _field_real, "runtime lower leg length!" },
		{ _field_short_integer, "runtime hip node a index!" },
		{ _field_short_integer, "runtime hip node b index!" },
		{ _field_short_integer, "runtime knee node a index!" },
		{ _field_short_integer, "runtime knee node b index!" },
		{ _field_short_integer, "runtime foot marker group index!" },
		{ _field_short_integer, "runtime foot node index!" },
		{ _field_short_integer, "runtime hip node index!" },
		{ _field_short_integer, "runtime knee node index!" },
		{ _field_real_vector_3d, "plant constraint position!" },
		{ _field_pad, "GKX", 12 },
		{ _field_terminator }
	};

	#define WALKER_PHYSICS_STRUCT_ID { 0x769D2C0D, 0xAEF54395, 0x86ECFA87, 0xB067AB04 }
	TAG_STRUCT(
		walker_physics_struct,
		"walker_physics_struct",
		"s_walker_physics_definition",
		WALKER_PHYSICS_STRUCT_ID)
	{
		{ _field_real_vector_3d, "maximum leg motion#in WU, how far can we displace the legs in x,y,z each step" },
		{ _field_real, "maximum turn#in degrees, how much can this walker turn in one step" },
		{ _field_block, "legs", &walker_physics_leg_block },
		{ _field_real, "leg apex fraction#0-1 fraction.  where the leg tansitions from lift to drop" },
		{ _field_real, "lift exponent# x(0-1) power exponent" },
		{ _field_real, "drop exponent# x(0-1) power exponent" },
		{ _field_real_vector_3d, "object space pivot position!" },
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

} // namespace macaque

} // namespace blofeld

