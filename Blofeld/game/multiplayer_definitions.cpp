#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(requisition_special_buy_enum, 12)
	{
		OPTION("none"),
		OPTION("airstrike!"),
		OPTION("mac cannon"),
		OPTION("magnetic ammo"),
		OPTION("laser ammo"),
		OPTION("explosive ammo"),
		OPTION("normal ammo"),
		OPTION("friendly ai light infantry"),
		OPTION("friendly ai heavy infantry"),
		OPTION("friendly ai light vehicle"),
		OPTION("friendly ai heavy vehicle"),
		OPTION("friendly ai flyer"),
	};

	TAG_ENUM(emblemInfoFlags, 3)
	{
		OPTION("alternate foreground channel off"),
		OPTION("flip foreground"),
		OPTION("flip background"),
	};

	TAG_ENUM(playerColorEnum, 32)
	{
		OPTION("player color 0"),
		OPTION("player color 1"),
		OPTION("player color 2"),
		OPTION("player color 3"),
		OPTION("player color 4"),
		OPTION("player color 5"),
		OPTION("player color 6"),
		OPTION("player color 7"),
		OPTION("player color 8"),
		OPTION("player color 9"),
		OPTION("player color 10"),
		OPTION("player color 11"),
		OPTION("player color 12"),
		OPTION("player color 13"),
		OPTION("player color 14"),
		OPTION("player color 15"),
		OPTION("player color 16"),
		OPTION("player color 17"),
		OPTION("player color 18"),
		OPTION("player color 19"),
		OPTION("player color 20"),
		OPTION("player color 21"),
		OPTION("player color 22"),
		OPTION("player color 23"),
		OPTION("player color 24"),
		OPTION("player color 25"),
		OPTION("player color 26"),
		OPTION("player color 27"),
		OPTION("player color 28"),
		OPTION("player color 29"),
		OPTION("player color 30"),
		OPTION("player color 31"),
	};

	TAG_ENUM(game_engine_status_enum_definition, 32)
	{
		OPTION("waiting for space to clear"),
		OPTION("observing"),
		OPTION("respawning soon"),
		OPTION("sitting out"),
		OPTION("out of lives"),
		OPTION("playing (winning)"),
		OPTION("playing (tied)"),
		OPTION("playing (losing)"),
		OPTION("game over (won)"),
		OPTION("game over (tied)"),
		OPTION("game over (lost)"),
		OPTION("game over (you lost, but game tied)"),
		OPTION("you have flag"),
		OPTION("enemy has flag"),
		OPTION("flag not home"),
		OPTION("carrying oddball"),
		OPTION("you are juggy"),
		OPTION("you control hill"),
		OPTION("switching sides soon"),
		OPTION("player recently started"),
		OPTION("you have bomb"),
		OPTION("flag contested"),
		OPTION("bomb contested"),
		OPTION("limited lives left (multiple)"),
		OPTION("limited lives left (single)"),
		OPTION("limited lives left (final)"),
		OPTION("playing (winning, unlimited)"),
		OPTION("playing (tied, unlimited)"),
		OPTION("playing (losing, unlimited)"),
		OPTION("waiting to spawn"),
		OPTION("waiting for game start"),
		OPTION("blank"),
	};

	TAG_ENUM(game_engine_status_flags_definition, 1)
	{
		OPTION("unused"),
	};

	TAG_GROUP_FROM_BLOCK(multiplayer_globals, MULTIPLAYER_GLOBALS_TAG, multiplayer_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(multiplayer_globals_block, 1, multiplayer_globals_struct_definition_struct_definition );

	TAG_BLOCK(spawn_influence_weight_falloff_function_block, 1)
	{
		FIELD( _field_struct, "function", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(multiplayer_universal_block, 1)
	{
		FIELD( _field_tag_reference, "random player names" ),
		FIELD( _field_tag_reference, "team names" ),
		FIELD( _field_block, "teams", &teamDefinitionBlock_block ),
		FIELD( _field_tag_reference, "multiplayer text" ),
		FIELD( _field_tag_reference, "sandbox text" ),
		FIELD( _field_tag_reference, "sandbox object properties values" ),
		FIELD( _field_tag_reference, "effects" ),
		FIELD( _field_block, "multiplayer roles", &global_team_role_block_block ),
		FIELD( _field_block, "requisition constants", &requisition_constants_block_block ),
		FIELD( _field_block, "player starting profile", &scenario_profiles_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(teamDefinitionBlock, k_multiplayer_team_game_team_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_real_rgb_color, "primary color" ),
		FIELD( _field_real_rgb_color, "secondary color" ),
		FIELD( _field_custom, "- Emblem Data" ),
		FIELD( _field_byte_integer, "foreground emblem index" ),
		FIELD( _field_byte_integer, "background emblem index" ),
		FIELD( _field_byte_flags, "info flags", &emblemInfoFlags ),
		FIELD( _field_char_enum, "primary color index", &playerColorEnum ),
		FIELD( _field_char_enum, "secondary color index", &playerColorEnum ),
		FIELD( _field_char_enum, "background color index", &playerColorEnum ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(requisition_constants_block, 1)
	{
		FIELD( _field_real, "FTL bonus fraction#multiplier to apply to money earned by minions to also give to the fireteam leader" ),
		FIELD( _field_explanation, "AWARD AMOUNTS" ),
		FIELD( _field_long_integer, "Kill" ),
		FIELD( _field_long_integer, "Assist" ),
		FIELD( _field_long_integer, "Fire team leader kill" ),
		FIELD( _field_long_integer, "vehicle kill#Default, only applies if the vehicle doesn\'t have a custom award amount in the scenario requisition palette." ),
		FIELD( _field_long_integer, "objective destroyed#awarded to entire team" ),
		FIELD( _field_long_integer, "objective armed#awarded to entire team" ),
		FIELD( _field_long_integer, "objective disarmed#awarded to entire team" ),
		FIELD( _field_long_integer, "objective defending#awarded every 3 seconds to any individuals near secondary defensive objectives" ),
		FIELD( _field_long_integer, "neutral territory owned#awarded every 3 seconds to entire team that owns BFG" ),
		FIELD( _field_long_integer, "served as reinforcement target#awarded to a reinforcement target when a teammate spawns on him (to encourage cooperation)" ),
		FIELD( _field_long_integer, "uberassault gun captured#awarded on gaining ownership of a gun to every member of the new owning team" ),
		FIELD( _field_long_integer, "uberassault gun owned#awarded every 3 seconds to the entire team that owns this gun.  Money from multiple guns stacks (so if you own all 3, you\'ll get 3x this money every 3 seconds)." ),
		FIELD( _field_explanation, "PENALTY AMOUNTS" ),
		FIELD( _field_long_integer, "Betrayed a teammate" ),
		FIELD( _field_explanation, "FIRE TEAM TIER KILL REQUIREMENTS" ),
		FIELD( _field_long_integer, "Bronze kill minimum" ),
		FIELD( _field_long_integer, "Silver kill minimum" ),
		FIELD( _field_long_integer, "Gold kill minimum" ),
		FIELD( _field_explanation, "FIRE TEAM TIER BONUS MULTIPLIERS" ),
		FIELD( _field_real, "Bronze multiplier" ),
		FIELD( _field_real, "Silver multiplier" ),
		FIELD( _field_real, "Gold multiplier" ),
		FIELD( _field_explanation, "FIRE TEAM TIER TIME REQUIREMENT" ),
		FIELD( _field_long_integer, "Bronze advancement time" ),
		FIELD( _field_long_integer, "Silver advancement time" ),
		FIELD( _field_long_integer, "Gold advancement time" ),
		FIELD( _field_block, "Requisition palette", &requisition_palette_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(requisition_palette_block, k_infinity_requisition_palette_maximum_count)
	{
		FIELD( _field_explanation, "CUSTOM APPS" ),
		FIELD( _field_tag_reference, "name" ),
		FIELD( _field_string_id, "display_name^" ),
		FIELD( _field_long_enum, "special_buy", &requisition_special_buy_enum ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(multiplayer_runtime_block, 1)
	{
		FIELD( _field_tag_reference, "editor biped" ),
		FIELD( _field_tag_reference, "editor helper" ),
		FIELD( _field_tag_reference, "flag" ),
		FIELD( _field_tag_reference, "ball" ),
		FIELD( _field_tag_reference, "assault bomb" ),
		FIELD( _field_tag_reference, "vip influence area" ),
		FIELD( _field_tag_reference, "in game text" ),
		FIELD( _field_block, "sounds", &sounds_block_block ),
		FIELD( _field_block, "looping sounds", &looping_sounds_block_block ),
		FIELD( _field_tag_reference, "megalo sounds{english}" ),
		FIELD( _field_tag_reference, "communication sounds{comm english}" ),
		FIELD( _field_long_integer, "maximum frag count" ),
		FIELD( _field_long_integer, "maximum plasma count" ),
		FIELD( _field_block, "multiplayer constants", &multiplayer_constants_block_block ),
		FIELD( _field_block, "state responses", &game_engine_status_response_block_block ),
		FIELD( _field_tag_reference, "scoreboard emblem bitmap" ),
		FIELD( _field_tag_reference, "scoreboard dead emblem bitmap" ),
		FIELD( _field_tag_reference, "hill shader" ),
		FIELD( _field_tag_reference, "default_biped_simulation_interpolation" ),
		FIELD( _field_tag_reference, "default_vehicle_simulation_interpolation" ),
		FIELD( _field_tag_reference, "default_crate_simulation_interpolation" ),
		FIELD( _field_tag_reference, "default_item_simulation_interpolation" ),
		FIELD( _field_tag_reference, "default_projectile_simulation_interpolation" ),
		FIELD( _field_tag_reference, "default_object_simulation_interpolation" ),
		FIELD( _field_tag_reference, "co-op spawning globals" ),
		FIELD( _field_tag_reference, "megalo string_id table" ),
		FIELD( _field_tag_reference, "killcam parameters# Used for non projectile killcams." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(sounds_block, k_maximum_multiplayer_sounds)
	{
		FIELD( _field_tag_reference, "sound^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(looping_sounds_block, k_maximum_multiplayer_sounds)
	{
		FIELD( _field_tag_reference, "looping sound^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(multiplayer_constants_block, 1)
	{
		FIELD( _field_explanation, "PLAYER SPAWN INFLUENCERS" ),
		FIELD( _field_tag_reference, "Default Spawn Settings" ),
		FIELD( _field_explanation, "MORE MP CONSTANTS" ),
		FIELD( _field_real, "teleporter recharge time:seconds" ),
		FIELD( _field_tag_reference, "sandbox effect" ),
		FIELD( _field_string_id, "blocked teleporter string" ),
		FIELD( _field_explanation, "RESPAWN STRINGS" ),
		FIELD( _field_string_id, "voluntary respawn control instructions" ),
		FIELD( _field_string_id, "spawn allowed default respawn" ),
		FIELD( _field_string_id, "spawn at player allowed looking at self" ),
		FIELD( _field_string_id, "spawn at player allowed looking at target" ),
		FIELD( _field_string_id, "spawn at player allowed looking at potential target" ),
		FIELD( _field_string_id, "spawn at territory allowed looking at target" ),
		FIELD( _field_string_id, "spawn at territory allowed looking at potential target" ),
		FIELD( _field_string_id, "you are out of lives" ),
		FIELD( _field_string_id, "invalid spawn target selected" ),
		FIELD( _field_string_id, "targetted player enemies nearby" ),
		FIELD( _field_string_id, "targetted player unfriendly team" ),
		FIELD( _field_string_id, "targetted player dead" ),
		FIELD( _field_string_id, "targetted player in combat" ),
		FIELD( _field_string_id, "targetted player too far from owned flag" ),
		FIELD( _field_string_id, "no available netpoints" ),
		FIELD( _field_string_id, "targetted netpoint contested" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(game_engine_status_response_block, k_maximum_status_response_count)
	{
		FIELD( _field_word_flags, "flags", &game_engine_status_flags_definition ),
		FIELD( _field_pad, "FAW", 2 ),
		FIELD( _field_enum, "state^", &game_engine_status_enum_definition ),
		FIELD( _field_pad, "BNYFIDDGX", 2 ),
		FIELD( _field_string_id, "ffa message" ),
		FIELD( _field_string_id, "team message" ),
		FIELD( _field_tag_reference, "unused!" ),
		FIELD( _field_pad, "GTL", 4 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(multiplayer_color_block$3, 32)
	{
		FIELD( _field_real_rgb_color, "color" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(multiplayer_globals_struct_definition)
{
		FIELD( _field_block, "universal", &multiplayer_universal_block_block ),
		FIELD( _field_block, "runtime", &multiplayer_runtime_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

