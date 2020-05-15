#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_globals_damage, s_damage_globals_definition::k_numBlockElements)
{
	FIELD( _field_block, "damage groups", &damage_group_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(damage_group, k_maximum_material_types)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_block, "armor modifiers", &armor_modifier_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(armor_modifier, k_maximum_material_types)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_real, "damage multiplier" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(damage_globals, 1)
{
	FIELD( _field_tag_reference, "falling damage" ),
	FIELD( _field_tag_reference, "jumping damage" ),
	FIELD( _field_tag_reference, "soft landing damage" ),
	FIELD( _field_tag_reference, "hard landing damage" ),
	FIELD( _field_tag_reference, "hs damage" ),
	FIELD( _field_tag_reference, "hs fire damage" ),
	FIELD( _field_real, "terminal velocity:wu/s#you die if you fall faster than this (non-multiplayer only)" ),
	FIELD( _field_tag_reference, "terminal velocity damage{distance damage}" ),
	FIELD( _field_tag_reference, "default damage response{damage response}#fall back if none is specified in damage effect tags" ),
	FIELD( _field_tag_reference, "friendly fire damage response#anytime your teammate shoots you" ),
	FIELD( _field_real, "player shield spillover#the minimum amount of shield vitality needed to prevent spillover from damage types that do not spillover." ),
	FIELD( _field_custom, "damage decay" ),
	FIELD( _field_struct, "damage decay props*!" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "AI damage decay" ),
	FIELD( _field_struct, "ai damage decay props*!" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "shield impact decay" ),
	FIELD( _field_struct, "shield impact decay props" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(shield_boost, 1)
{
	FIELD( _field_explanation, "shield boosting" ),
	FIELD( _field_real, "shield boost decay#amount of shield-boost to decay per second" ),
	FIELD( _field_real, "shield boost recharge time#time to recharge full shields when getting boosted" ),
	FIELD( _field_real, "shield boost stun time#stun time when getting boosted" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

