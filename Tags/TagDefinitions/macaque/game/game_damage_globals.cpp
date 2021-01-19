#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GAME_GLOBALS_DAMAGE_BLOCK_ID { 0x5E608798, 0x58964FDC, 0xBCD062B5, 0x7302D300 }
	TAG_BLOCK(
		game_globals_damage_block,
		"game_globals_damage_block",
		s_damage_globals_definition::k_numBlockElements,
		"s_damage_globals_definition",
		GAME_GLOBALS_DAMAGE_BLOCK_ID)
	{
		{ _field_block, "damage groups", &damage_group_block },
		{ _field_terminator }
	};

	#define DAMAGE_GROUP_BLOCK_ID { 0x34945DAA, 0x3110409D, 0xA4F3330D, 0x4B1BFD04 }
	TAG_BLOCK(
		damage_group_block,
		"damage_group_block",
		k_maximum_material_types,
		"s_damage_group_definition",
		DAMAGE_GROUP_BLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "armor modifiers", &armor_modifier_block },
		{ _field_terminator }
	};

	#define ARMOR_MODIFIER_BLOCK_ID { 0x1D0D482B, 0x0AB145C0, 0x86B6EF80, 0x3FDE838A }
	TAG_BLOCK(
		armor_modifier_block,
		"armor_modifier_block",
		k_maximum_material_types,
		"s_armor_modifier_definition",
		ARMOR_MODIFIER_BLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_real, "damage multiplier" },
		{ _field_terminator }
	};

	#define DAMAGE_GLOBALS_BLOCK_ID { 0x2B7CE12A, 0xC9FD4184, 0xA5B5C911, 0x6D515D0A }
	TAG_BLOCK(
		damage_globals_block,
		"damage_globals_block",
		1,
		"s_game_globals_damage",
		DAMAGE_GLOBALS_BLOCK_ID)
	{
		{ _field_tag_reference, "falling damage", &global_damage_reference },
		{ _field_tag_reference, "jumping damage", &global_damage_reference },
		{ _field_tag_reference, "soft landing damage", &global_damage_reference },
		{ _field_tag_reference, "hard landing damage", &global_damage_reference },
		{ _field_tag_reference, "hs damage", &global_damage_reference },
		{ _field_tag_reference, "hs fire damage", &global_damage_reference },
		{ _field_real, "terminal velocity:wu/s#you die if you fall faster than this (non-multiplayer only)" },
		{ _field_tag_reference, "terminal velocity damage{distance damage}", &global_damage_reference },
		{ _field_tag_reference, "default damage response{damage response}#fall back if none is specified in damage effect tags", &global_damage_response_definition_reference },
		{ _field_tag_reference, "friendly fire damage response#anytime your teammate shoots you", &global_damage_response_definition_reference },
		{ _field_real, "player shield spillover#the minimum amount of shield vitality needed to prevent spillover from damage types that do not spillover." },
		FIELD_CUSTOM("damage decay", _custom_field_function_group_begin),
		{ _field_struct, "damage decay props*!", &damage_decay_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("AI damage decay", _custom_field_function_group_begin),
		{ _field_struct, "ai damage decay props*!", &damage_decay_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("shield impact decay", _custom_field_function_group_begin),
		{ _field_struct, "shield impact decay props", &damage_decay_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	#define SHIELD_BOOST_BLOCK_ID { 0xC8A4D40E, 0x830F49E4, 0x90962271, 0x1FDC8F7C }
	TAG_BLOCK(
		shield_boost_block,
		"shield_boost_block",
		1,
		"s_game_globals_shield_boost",
		SHIELD_BOOST_BLOCK_ID)
	{
		{ _field_explanation, "shield boosting", "This feature was implemented for the engineer character in atlas. Shield dynamics overrides for when shields are being \'boosted\' by an external source" },
		{ _field_real, "shield boost decay#amount of shield-boost to decay per second" },
		{ _field_real, "shield boost recharge time#time to recharge full shields when getting boosted" },
		{ _field_real, "shield boost stun time#stun time when getting boosted" },
		{ _field_terminator }
	};

	#define DAMAGE_DECAY_STRUCT_ID { 0x1C1E2343, 0x2E644935, 0xA2CE1C35, 0x2B143905 }
	TAG_STRUCT(
		damage_decay_struct,
		"damage_decay_struct",
		"s_damage_decay",
		DAMAGE_DECAY_STRUCT_ID)
	{
		{ _field_real, "current damage decay delay:seconds#current damage begins to fall after a time delay has passed since last the damage (MAX 4.1, because timer is stored in a char so 127 ticks maximum)" },
		{ _field_real, "current damage decay time:seconds#amount of time it would take for 100% current damage to decay to 0" },
		{ _field_real, "current damage decay rate:damage/second#amount of damage that decays from our current damage every second" },
		{ _field_real, "recent damage decay delay:seconds#recent damage begins to fall after a time delay has passed since last the damage (MAX 4.1, because timer is stored in a char so 127 ticks maximum)" },
		{ _field_real, "recent damage decay time:seconds#amount of time it would take for 100% recent damage to decay to 0" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

