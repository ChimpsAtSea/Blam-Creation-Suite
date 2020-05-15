#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_globals_damage, s_damage_globals_definition::k_numBlockElements)
{
	{ _field_block, "damage groups", &damage_group_block },
	{ _field_terminator },
};

TAG_BLOCK(damage_group, k_maximum_material_types)
{
	{ _field_string_id, "name^" },
	{ _field_block, "armor modifiers", &armor_modifier_block },
	{ _field_terminator },
};

TAG_BLOCK(armor_modifier, k_maximum_material_types)
{
	{ _field_string_id, "name^" },
	{ _field_real, "damage multiplier" },
	{ _field_terminator },
};

TAG_BLOCK(damage_globals, 1)
{
	{ _field_tag_reference, "falling damage" },
	{ _field_tag_reference, "jumping damage" },
	{ _field_tag_reference, "soft landing damage" },
	{ _field_tag_reference, "hard landing damage" },
	{ _field_tag_reference, "hs damage" },
	{ _field_tag_reference, "hs fire damage" },
	{ _field_real, "terminal velocity:wu/s#you die if you fall faster than this (non-multiplayer only)" },
	{ _field_tag_reference, "terminal velocity damage{distance damage}" },
	{ _field_tag_reference, "default damage response{damage response}#fall back if none is specified in damage effect tags" },
	{ _field_tag_reference, "friendly fire damage response#anytime your teammate shoots you" },
	{ _field_real, "player shield spillover#the minimum amount of shield vitality needed to prevent spillover from damage types that do not spillover." },
	{ _field_custom, "damage decay" },
	{ _field_struct, "damage decay props*!" },
	{ _field_custom },
	{ _field_custom, "AI damage decay" },
	{ _field_struct, "ai damage decay props*!" },
	{ _field_custom },
	{ _field_custom, "shield impact decay" },
	{ _field_struct, "shield impact decay props" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(shield_boost, 1)
{
	{ _field_explanation, "shield boosting" },
	{ _field_real, "shield boost decay#amount of shield-boost to decay per second" },
	{ _field_real, "shield boost recharge time#time to recharge full shields when getting boosted" },
	{ _field_real, "shield boost stun time#stun time when getting boosted" },
	{ _field_terminator },
};

} // namespace blofeld

