#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(player_trait_bool_enum, 3)
	{
		OPTION("unchanged"),
		OPTION("false"),
		OPTION("true"),
	};

	TAG_ENUM(player_trait_initial_grenade_count_enum, 19)
	{
		OPTION("unchanged"),
		OPTION("map_default"),
		OPTION("0"),
		OPTION("1_frag"),
		OPTION("2_frag"),
		OPTION("1_plasma"),
		OPTION("2_plasma"),
		OPTION("1_type2"),
		OPTION("2_type2"),
		OPTION("1_type3"),
		OPTION("2_type3"),
		OPTION("1_type4"),
		OPTION("2_type4"),
		OPTION("1_type5"),
		OPTION("2_type5"),
		OPTION("1_type6"),
		OPTION("2_type6"),
		OPTION("1_type7"),
		OPTION("2_type7"),
	};

	TAG_ENUM(player_trait_infinite_ammo_enum, 4)
	{
		OPTION("unchanged"),
		OPTION("off"),
		OPTION("on"),
		OPTION("bottomless_clip"),
	};

	TAG_ENUM(player_trait_equipment_usage_enum, 4)
	{
		OPTION("unchanged"),
		OPTION("off"),
		OPTION("not with objectives"),
		OPTION("on"),
	};

	TAG_ENUM(player_trait_vehicle_usage, 9)
	{
		OPTION("unchanged"),
		OPTION("none"),
		OPTION("passenger_only"),
		OPTION("driver_only"),
		OPTION("gunner_only"),
		OPTION("not_passenger"),
		OPTION("not_driver"),
		OPTION("not_gunner"),
		OPTION("full"),
	};

	TAG_ENUM(player_trait_double_jump, 4)
	{
		OPTION("unchanged"),
		OPTION("off"),
		OPTION("on"),
		OPTION("on_plus_lunge"),
	};

	TAG_ENUM(player_trait_active_camo, 6)
	{
		OPTION("unchanged"),
		OPTION("off"),
		OPTION("poor"),
		OPTION("good"),
		OPTION("excellent"),
		OPTION("invisible"),
	};

	TAG_ENUM(player_trait_waypoint, 4)
	{
		OPTION("unchanged"),
		OPTION("off"),
		OPTION("allies"),
		OPTION("all"),
	};

	TAG_ENUM(player_trait_aura, 5)
	{
		OPTION("unchanged"),
		OPTION("off"),
		OPTION("team_color"),
		OPTION("black"),
		OPTION("white"),
	};

	TAG_ENUM(player_trait_motion_tracker, 5)
	{
		OPTION("unchanged"),
		OPTION("off"),
		OPTION("moving_friendly_bipeds_moving_neutral_vehicles"),
		OPTION("moving_bipeds_moving_vehicles"),
		OPTION("all_bipeds_moving_vehicles"),
	};

	TAG_ENUM(player_trait_powerup_cancellation_enum, 3)
	{
		OPTION("unchanged"),
		OPTION("none"),
		OPTION("no_overshield"),
	};

	TAG_ENUM(player_traits_vitality_float_flags, 13)
	{
		OPTION("damage resistance"),
		OPTION("shield multiplier"),
		OPTION("body multiplier"),
		OPTION("shield stun duration"),
		OPTION("shield recharge rate"),
		OPTION("body recharge rate"),
		OPTION("overshield recharge rate"),
		OPTION("vampirism percent"),
		OPTION("explosive damage resistance"),
		OPTION("wheelman armor vehicle stun time modifier"),
		OPTION("wheelman armor vehicle recharge time modifier"),
		OPTION("wheelman armor vehicle emp disabled time modifier"),
		OPTION("fall damage multiplier"),
	};

	TAG_ENUM(player_traits_weapons_float_flags, 22)
	{
		OPTION("damage multiplier"),
		OPTION("melee damage multiplier"),
		OPTION("grenade recharge seconds frag"),
		OPTION("grenade recharge seconds plasma"),
		OPTION("grenade recharge seconds spike"),
		OPTION("hero equipment energy use rate modifier"),
		OPTION("hero equipment energy recharge delay modifier"),
		OPTION("hero equipment energy recharge rate modifier"),
		OPTION("hero equipment initial energy modifier"),
		OPTION("equipment energy use rate modifier"),
		OPTION("equipment energy recharge delay modifier"),
		OPTION("equipment energy use recharge rate modifier"),
		OPTION("equipment energy initial energy modifier"),
		OPTION("switch speed modifier"),
		OPTION("reload speed modifier"),
		OPTION("ordnance points modifier"),
		OPTION("explosive area of effect radius modifier"),
		OPTION("gunner armor modifier"),
		OPTION("stability armor modifier"),
		OPTION("drop recon warning seconds"),
		OPTION("drop recon distance modifier"),
		OPTION("assassination speed modifier"),
	};

	TAG_ENUM(player_traits_movement_float_flags, 4)
	{
		OPTION("speed"),
		OPTION("gravity multiplier"),
		OPTION("jump multiplier"),
		OPTION("turn speed multiplier"),
	};

	TAG_ENUM(player_traits_sensors_float_flags, 2)
	{
		OPTION("motion tracker range"),
		OPTION("nemesis duration"),
	};

	TAG_BLOCK(game_engine_player_traits_block, 1)
	{
		FIELD( _field_block, "vitality traits", &player_traits_vitality_block_block ),
		FIELD( _field_block, "weapon traits", &player_traits_weapons_block_block ),
		FIELD( _field_block, "movement traits", &player_traits_movement_block_block ),
		FIELD( _field_block, "appearance traits", &player_traits_appearance_block_block ),
		FIELD( _field_block, "sensor traits", &player_traits_sensors_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(player_traits_vitality_block, 1)
	{
		FIELD( _field_long_flags, "should apply trait", &player_traits_vitality_float_flags ),
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
		FIELD( _field_char_enum, "headshot immunity", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "assassination immunity", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "deathless", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "fast track armor", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "powerup cancellation", &player_trait_powerup_cancellation_enum ),
		FIELD( _field_pad, "pad", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(player_traits_weapons_block, 1)
	{
		FIELD( _field_long_flags, "should apply trait", &player_traits_weapons_float_flags ),
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
		FIELD( _field_char_enum, "weapon pickup allowed", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "initial grenade count", &player_trait_initial_grenade_count_enum ),
		FIELD( _field_char_enum, "infinite ammo", &player_trait_infinite_ammo_enum ),
		FIELD( _field_char_enum, "equipment usage", &player_trait_equipment_usage_enum ),
		FIELD( _field_char_enum, "equipment usage excepting auto turret#false will disable all equipment except auto turret", &player_trait_equipment_usage_enum ),
		FIELD( _field_char_enum, "equipment drop", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "infinite equipment", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "weapons ammopack", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "weapons grenadier", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "weapons explode on death armormod#spawns projectile specified in globals.globals", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "ordnance markers visible", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "weapons ordnance reroll available", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "weapons resourceful#grenade probabilities defined in grenade_list.game_globals_grenade_list", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "weapons well equipped", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "ordnance disabled", &player_trait_bool_enum ),
		FIELD( _field_pad, "weapons_padding", 1 ),
		FIELD( _field_explanation, "initial weapons/equipment" ),
		FIELD( _field_string_id, "initial primary weapon" ),
		FIELD( _field_string_id, "initial secondary weapon" ),
		FIELD( _field_string_id, "initial equipment" ),
		FIELD( _field_string_id, "initial tactical package" ),
		FIELD( _field_string_id, "initial support upgrade" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(player_traits_movement_block, 1)
	{
		FIELD( _field_long_flags, "should apply trait", &player_traits_movement_float_flags ),
		FIELD( _field_real, "speed" ),
		FIELD( _field_real, "gravity multiplier" ),
		FIELD( _field_real, "jump multiplier" ),
		FIELD( _field_real, "turn speed multiplier" ),
		FIELD( _field_char_enum, "vehicle usage", &player_trait_vehicle_usage ),
		FIELD( _field_char_enum, "double jump", &player_trait_double_jump ),
		FIELD( _field_char_enum, "sprint usage", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "automatic momentum usage", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "vaulting enabled", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "stealthy", &player_trait_bool_enum ),
		FIELD( _field_pad, "grue", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(player_traits_appearance_block, 1)
	{
		FIELD( _field_char_enum, "active camo", &player_trait_active_camo ),
		FIELD( _field_char_enum, "waypoint", &player_trait_waypoint ),
		FIELD( _field_char_enum, "gamertag visible", &player_trait_waypoint ),
		FIELD( _field_char_enum, "aura", &player_trait_aura ),
		FIELD( _field_explanation, "death effect/attached effect" ),
		FIELD( _field_string_id, "death effect" ),
		FIELD( _field_string_id, "attached effect" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(player_traits_sensors_block, 1)
	{
		FIELD( _field_long_flags, "should apply trait", &player_traits_sensors_float_flags ),
		FIELD( _field_real, "motion tracker range" ),
		FIELD( _field_real, "nemesis duration:seconds" ),
		FIELD( _field_char_enum, "motion tracker", &player_trait_motion_tracker ),
		FIELD( _field_char_enum, "motion tracker while zoomed", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "directional damage indicator", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "vision mode", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "battle awareness", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "threat view", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "aural enhancement", &player_trait_bool_enum ),
		FIELD( _field_char_enum, "nemesis", &player_trait_bool_enum ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(game_engine_player_traits_list_block, 64)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "vitality traits", &player_traits_vitality_block_block ),
		FIELD( _field_block, "weapon traits", &player_traits_weapons_block_block ),
		FIELD( _field_block, "movement traits", &player_traits_movement_block_block ),
		FIELD( _field_block, "appearance traits", &player_traits_appearance_block_block ),
		FIELD( _field_block, "sensor traits", &player_traits_sensors_block_block ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

