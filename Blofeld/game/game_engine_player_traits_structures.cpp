#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_engine_player_traits, 1)
{
	FIELD( _field_block, "vitality traits", &player_traits_vitality_block ),
	FIELD( _field_block, "weapon traits", &player_traits_weapons_block ),
	FIELD( _field_block, "movement traits", &player_traits_movement_block ),
	FIELD( _field_block, "appearance traits", &player_traits_appearance_block ),
	FIELD( _field_block, "sensor traits", &player_traits_sensors_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_traits_vitality, 1)
{
	FIELD( _field_long_flags, "should apply trait" ),
	FIELD( _field_explanation, "damage resistance" ),
	FIELD( _field_real, "damage resistance" ),
	FIELD( _field_real, "shield multiplier" ),
	FIELD( _field_real, "body multiplier" ),
	FIELD( _field_real, "shield stun duration" ),
	FIELD( _field_real, "shield recharge rate" ),
	FIELD( _field_real, "body recharge rate" ),
	FIELD( _field_real, "overshield recharge rate" ),
	FIELD( _field_real, "vampirism percent" ),
	FIELD( _field_real, "explosive damage resistance#incoming damage multiplied by (1 - resistance)" ),
	FIELD( _field_real, "wheelman armor vehicle stun time modifier" ),
	FIELD( _field_real, "wheelman armor vehicle recharge time modifier" ),
	FIELD( _field_real, "wheelman armor vehicle emp disabled time modifier" ),
	FIELD( _field_real, "fall damage multiplier" ),
	FIELD( _field_char_enum, "headshot immunity" ),
	FIELD( _field_char_enum, "assassination immunity" ),
	FIELD( _field_char_enum, "deathless" ),
	FIELD( _field_char_enum, "fast track armor" ),
	FIELD( _field_char_enum, "powerup cancellation" ),
	FIELD( _field_pad, "pad", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_traits_weapons, 1)
{
	FIELD( _field_long_flags, "should apply trait" ),
	FIELD( _field_real, "damage multiplier" ),
	FIELD( _field_real, "melee damage multiplier" ),
	FIELD( _field_real, "grenade recharge seconds frag" ),
	FIELD( _field_real, "grenade recharge seconds plasma" ),
	FIELD( _field_real, "grenade recharge seconds spike" ),
	FIELD( _field_real, "hero equipment energy use rate modifier" ),
	FIELD( _field_real, "hero equipment energy recharge delay modifier" ),
	FIELD( _field_real, "hero equipment energy recharge rate modifier" ),
	FIELD( _field_real, "hero equipment initial energy modifier" ),
	FIELD( _field_real, "equipment energy use rate modifier" ),
	FIELD( _field_real, "equipment energy recharge delay modifier" ),
	FIELD( _field_real, "equipment energy use recharge rate modifier" ),
	FIELD( _field_real, "equipment energy initial energy modifier" ),
	FIELD( _field_real, "switch speed modifier" ),
	FIELD( _field_real, "reload speed modifier" ),
	FIELD( _field_real, "ordnance points modifier" ),
	FIELD( _field_real, "explosive area of effect radius modifier" ),
	FIELD( _field_real, "gunner armor modifier" ),
	FIELD( _field_real, "stability armor modifier" ),
	FIELD( _field_real, "drop recon warning seconds" ),
	FIELD( _field_real, "drop recon distance modifier" ),
	FIELD( _field_real, "assassination speed modifier" ),
	FIELD( _field_char_enum, "weapon pickup allowed" ),
	FIELD( _field_char_enum, "initial grenade count" ),
	FIELD( _field_char_enum, "infinite ammo" ),
	FIELD( _field_char_enum, "equipment usage" ),
	FIELD( _field_char_enum, "equipment usage excepting auto turret#false will disable all equipment except auto turret" ),
	FIELD( _field_char_enum, "equipment drop" ),
	FIELD( _field_char_enum, "infinite equipment" ),
	FIELD( _field_char_enum, "weapons ammopack" ),
	FIELD( _field_char_enum, "weapons grenadier" ),
	FIELD( _field_char_enum, "weapons explode on death armormod#spawns projectile specified in globals.globals" ),
	FIELD( _field_char_enum, "ordnance markers visible" ),
	FIELD( _field_char_enum, "weapons ordnance reroll available" ),
	FIELD( _field_char_enum, "weapons resourceful#grenade probabilities defined in grenade_list.game_globals_grenade_list" ),
	FIELD( _field_char_enum, "weapons well equipped" ),
	FIELD( _field_char_enum, "ordnance disabled" ),
	FIELD( _field_pad, "weapons_padding", 1 ),
	FIELD( _field_explanation, "initial weapons/equipment" ),
	FIELD( _field_string_id, "initial primary weapon" ),
	FIELD( _field_string_id, "initial secondary weapon" ),
	FIELD( _field_string_id, "initial equipment" ),
	FIELD( _field_string_id, "initial tactical package" ),
	FIELD( _field_string_id, "initial support upgrade" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_traits_movement, 1)
{
	FIELD( _field_long_flags, "should apply trait" ),
	FIELD( _field_real, "speed" ),
	FIELD( _field_real, "gravity multiplier" ),
	FIELD( _field_real, "jump multiplier" ),
	FIELD( _field_real, "turn speed multiplier" ),
	FIELD( _field_char_enum, "vehicle usage" ),
	FIELD( _field_char_enum, "double jump" ),
	FIELD( _field_char_enum, "sprint usage" ),
	FIELD( _field_char_enum, "automatic momentum usage" ),
	FIELD( _field_char_enum, "vaulting enabled" ),
	FIELD( _field_char_enum, "stealthy" ),
	FIELD( _field_pad, "grue", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_traits_appearance, 1)
{
	FIELD( _field_char_enum, "active camo" ),
	FIELD( _field_char_enum, "waypoint" ),
	FIELD( _field_char_enum, "gamertag visible" ),
	FIELD( _field_char_enum, "aura" ),
	FIELD( _field_explanation, "death effect/attached effect" ),
	FIELD( _field_string_id, "death effect" ),
	FIELD( _field_string_id, "attached effect" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_traits_sensors, 1)
{
	FIELD( _field_long_flags, "should apply trait" ),
	FIELD( _field_real, "motion tracker range" ),
	FIELD( _field_real, "nemesis duration:seconds" ),
	FIELD( _field_char_enum, "motion tracker" ),
	FIELD( _field_char_enum, "motion tracker while zoomed" ),
	FIELD( _field_char_enum, "directional damage indicator" ),
	FIELD( _field_char_enum, "vision mode" ),
	FIELD( _field_char_enum, "battle awareness" ),
	FIELD( _field_char_enum, "threat view" ),
	FIELD( _field_char_enum, "aural enhancement" ),
	FIELD( _field_char_enum, "nemesis" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_player_traits_list, 64)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_block, "vitality traits", &player_traits_vitality_block ),
	FIELD( _field_block, "weapon traits", &player_traits_weapons_block ),
	FIELD( _field_block, "movement traits", &player_traits_movement_block ),
	FIELD( _field_block, "appearance traits", &player_traits_appearance_block ),
	FIELD( _field_block, "sensor traits", &player_traits_sensors_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

