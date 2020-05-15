#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_engine_player_traits, 1)
{
	{ _field_block, "vitality traits", &player_traits_vitality_block },
	{ _field_block, "weapon traits", &player_traits_weapons_block },
	{ _field_block, "movement traits", &player_traits_movement_block },
	{ _field_block, "appearance traits", &player_traits_appearance_block },
	{ _field_block, "sensor traits", &player_traits_sensors_block },
	{ _field_terminator },
};

TAG_BLOCK(player_traits_vitality, 1)
{
	{ _field_long_flags, "should apply trait" },
	{ _field_explanation, "damage resistance" },
	{ _field_real, "damage resistance" },
	{ _field_real, "shield multiplier" },
	{ _field_real, "body multiplier" },
	{ _field_real, "shield stun duration" },
	{ _field_real, "shield recharge rate" },
	{ _field_real, "body recharge rate" },
	{ _field_real, "overshield recharge rate" },
	{ _field_real, "vampirism percent" },
	{ _field_real, "explosive damage resistance#incoming damage multiplied by (1 - resistance)" },
	{ _field_real, "wheelman armor vehicle stun time modifier" },
	{ _field_real, "wheelman armor vehicle recharge time modifier" },
	{ _field_real, "wheelman armor vehicle emp disabled time modifier" },
	{ _field_real, "fall damage multiplier" },
	{ _field_char_enum, "headshot immunity" },
	{ _field_char_enum, "assassination immunity" },
	{ _field_char_enum, "deathless" },
	{ _field_char_enum, "fast track armor" },
	{ _field_char_enum, "powerup cancellation" },
	{ _field_pad, "pad", 3 },
	{ _field_terminator },
};

TAG_BLOCK(player_traits_weapons, 1)
{
	{ _field_long_flags, "should apply trait" },
	{ _field_real, "damage multiplier" },
	{ _field_real, "melee damage multiplier" },
	{ _field_real, "grenade recharge seconds frag" },
	{ _field_real, "grenade recharge seconds plasma" },
	{ _field_real, "grenade recharge seconds spike" },
	{ _field_real, "hero equipment energy use rate modifier" },
	{ _field_real, "hero equipment energy recharge delay modifier" },
	{ _field_real, "hero equipment energy recharge rate modifier" },
	{ _field_real, "hero equipment initial energy modifier" },
	{ _field_real, "equipment energy use rate modifier" },
	{ _field_real, "equipment energy recharge delay modifier" },
	{ _field_real, "equipment energy use recharge rate modifier" },
	{ _field_real, "equipment energy initial energy modifier" },
	{ _field_real, "switch speed modifier" },
	{ _field_real, "reload speed modifier" },
	{ _field_real, "ordnance points modifier" },
	{ _field_real, "explosive area of effect radius modifier" },
	{ _field_real, "gunner armor modifier" },
	{ _field_real, "stability armor modifier" },
	{ _field_real, "drop recon warning seconds" },
	{ _field_real, "drop recon distance modifier" },
	{ _field_real, "assassination speed modifier" },
	{ _field_char_enum, "weapon pickup allowed" },
	{ _field_char_enum, "initial grenade count" },
	{ _field_char_enum, "infinite ammo" },
	{ _field_char_enum, "equipment usage" },
	{ _field_char_enum, "equipment usage excepting auto turret#false will disable all equipment except auto turret" },
	{ _field_char_enum, "equipment drop" },
	{ _field_char_enum, "infinite equipment" },
	{ _field_char_enum, "weapons ammopack" },
	{ _field_char_enum, "weapons grenadier" },
	{ _field_char_enum, "weapons explode on death armormod#spawns projectile specified in globals.globals" },
	{ _field_char_enum, "ordnance markers visible" },
	{ _field_char_enum, "weapons ordnance reroll available" },
	{ _field_char_enum, "weapons resourceful#grenade probabilities defined in grenade_list.game_globals_grenade_list" },
	{ _field_char_enum, "weapons well equipped" },
	{ _field_char_enum, "ordnance disabled" },
	{ _field_pad, "weapons_padding", 1 },
	{ _field_explanation, "initial weapons/equipment" },
	{ _field_string_id, "initial primary weapon" },
	{ _field_string_id, "initial secondary weapon" },
	{ _field_string_id, "initial equipment" },
	{ _field_string_id, "initial tactical package" },
	{ _field_string_id, "initial support upgrade" },
	{ _field_terminator },
};

TAG_BLOCK(player_traits_movement, 1)
{
	{ _field_long_flags, "should apply trait" },
	{ _field_real, "speed" },
	{ _field_real, "gravity multiplier" },
	{ _field_real, "jump multiplier" },
	{ _field_real, "turn speed multiplier" },
	{ _field_char_enum, "vehicle usage" },
	{ _field_char_enum, "double jump" },
	{ _field_char_enum, "sprint usage" },
	{ _field_char_enum, "automatic momentum usage" },
	{ _field_char_enum, "vaulting enabled" },
	{ _field_char_enum, "stealthy" },
	{ _field_pad, "grue", 2 },
	{ _field_terminator },
};

TAG_BLOCK(player_traits_appearance, 1)
{
	{ _field_char_enum, "active camo" },
	{ _field_char_enum, "waypoint" },
	{ _field_char_enum, "gamertag visible" },
	{ _field_char_enum, "aura" },
	{ _field_explanation, "death effect/attached effect" },
	{ _field_string_id, "death effect" },
	{ _field_string_id, "attached effect" },
	{ _field_terminator },
};

TAG_BLOCK(player_traits_sensors, 1)
{
	{ _field_long_flags, "should apply trait" },
	{ _field_real, "motion tracker range" },
	{ _field_real, "nemesis duration:seconds" },
	{ _field_char_enum, "motion tracker" },
	{ _field_char_enum, "motion tracker while zoomed" },
	{ _field_char_enum, "directional damage indicator" },
	{ _field_char_enum, "vision mode" },
	{ _field_char_enum, "battle awareness" },
	{ _field_char_enum, "threat view" },
	{ _field_char_enum, "aural enhancement" },
	{ _field_char_enum, "nemesis" },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_player_traits_list, 64)
{
	{ _field_string_id, "name^" },
	{ _field_block, "vitality traits", &player_traits_vitality_block },
	{ _field_block, "weapon traits", &player_traits_weapons_block },
	{ _field_block, "movement traits", &player_traits_movement_block },
	{ _field_block, "appearance traits", &player_traits_appearance_block },
	{ _field_block, "sensor traits", &player_traits_sensors_block },
	{ _field_terminator },
};

} // namespace blofeld

