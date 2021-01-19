#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(multiplayer_globals, MULTIPLAYER_GLOBALS_TAG, multiplayer_globals_block_block );

	V5_TAG_BLOCK(spawn_influence_weight_falloff_function_block, 1)
	{
		{ _field_struct, "function", &scalar_function_named_struct_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(teamDefinitionBlock, k_multiplayer_team_game_team_count)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_real_rgb_color, "color" },

		{ _field_version_greater, _engine_type_haloreach, 12 },
		{ _field_string_id, "name^" },
		{ _field_real_rgb_color, "primary color" },
		{ _field_real_rgb_color, "secondary color" },
		{ _field_custom, "- Emblem Data" },
		{ _field_byte_integer, "foreground emblem index" },
		{ _field_byte_integer, "background emblem index" },
		{ _field_byte_flags, "info flags", &emblemInfoFlags },
		{ _field_char_enum, "primary color index", &playerColorEnum },
		{ _field_char_enum, "secondary color index", &playerColorEnum },
		{ _field_char_enum, "background color index", &playerColorEnum },
		{ _field_pad, "pad", 2 },
		{ _field_custom },

		{ _field_terminator }
	};

	V5_TAG_BLOCK(requisition_palette_block, k_infinity_requisition_palette_maximum_count)
	{
		{ _field_explanation, "CUSTOM APPS", "If you want the award to be a custom app, point at globals/custom_app_globals, and match one of the names from that tag for \"display_name\"" },
		{ _field_tag_reference, "name", &requisition_palette_block_name_reference },
		{ _field_string_id, "display_name^" },
		{ _field_long_enum, "special_buy", &requisition_special_buy_enum },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(requisition_constants_block, 1)
	{
		{ _field_real, "FTL bonus fraction#multiplier to apply to money earned by minions to also give to the fireteam leader" },
		{ _field_explanation, "AWARD AMOUNTS", "These are requisition award amounts for various thing players can get money for" },
		{ _field_long_integer, "Kill" },
		{ _field_long_integer, "Assist" },
		{ _field_long_integer, "Fire team leader kill" },
		{ _field_long_integer, "vehicle kill#Default, only applies if the vehicle doesn\'t have a custom award amount in the scenario requisition palette." },
		{ _field_long_integer, "objective destroyed#awarded to entire team" },
		{ _field_long_integer, "objective armed#awarded to entire team" },
		{ _field_long_integer, "objective disarmed#awarded to entire team" },
		{ _field_long_integer, "objective defending#awarded every 3 seconds to any individuals near secondary defensive objectives" },
		{ _field_long_integer, "neutral territory owned#awarded every 3 seconds to entire team that owns BFG" },
		{ _field_long_integer, "served as reinforcement target#awarded to a reinforcement target when a teammate spawns on him (to encourage cooperation)" },
		{ _field_long_integer, "uberassault gun captured#awarded on gaining ownership of a gun to every member of the new owning team" },
		{ _field_long_integer, "uberassault gun owned#awarded every 3 seconds to the entire team that owns this gun.  Money from multiple guns stacks (so if you own all 3, you\'ll get 3x this money every 3 seconds)." },
		{ _field_explanation, "PENALTY AMOUNTS", "Requisition penalties for various discouraged actions" },
		{ _field_long_integer, "Betrayed a teammate" },
		{ _field_explanation, "FIRE TEAM TIER KILL REQUIREMENTS", "Number of kills a fireteam must have to reach each fire team tier" },
		{ _field_long_integer, "Bronze kill minimum" },
		{ _field_long_integer, "Silver kill minimum" },
		{ _field_long_integer, "Gold kill minimum" },
		{ _field_explanation, "FIRE TEAM TIER BONUS MULTIPLIERS", "Applied to money earned from biped kills and assists" },
		{ _field_real, "Bronze multiplier" },
		{ _field_real, "Silver multiplier" },
		{ _field_real, "Gold multiplier" },
		{ _field_explanation, "FIRE TEAM TIER TIME REQUIREMENT", "Game time in seconds after which everyone is promoted to at least this tier" },
		{ _field_long_integer, "Bronze advancement time" },
		{ _field_long_integer, "Silver advancement time" },
		{ _field_long_integer, "Gold advancement time" },
		{ _field_block, "Requisition palette", &requisition_palette_block_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_universal_block, 1)
	{
		{ _field_tag_reference, "random player names", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "team names", &global_multilingual_unicode_string_list_reference },
		{ _field_block, "teams", &teamDefinitionBlock_block },
		{ _field_tag_reference, "multiplayer text", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "sandbox text", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "sandbox object properties values", &g_sandbox_object_properties_interface_reference },

		{ _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_tag_reference, "effects", &global_multiplayer_effect_group_reference },
		{ _field_block, "multiplayer roles", &global_team_role_block_block },
		{ _field_block, "requisition constants", &requisition_constants_block_block },
		{ _field_block, "player starting profile", &scenario_profiles_block_block },

		{ _field_terminator }
	};

	V5_TAG_BLOCK(sounds_block, k_maximum_multiplayer_sounds)
	{
		{ _field_tag_reference, "sound^", &global_sound_reference },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(looping_sounds_block, k_maximum_multiplayer_sounds)
	{
		{ _field_tag_reference, "looping sound^", &global_looping_sound_reference },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(multiplayer_constants_unknown_struct)
	{
		{ _field_real, "unknown0" },
		{ _field_real, "unknown4" },
		{ _field_real, "unknown8" },
		{ _field_real, "unknownC" },
		{ _field_real, "unknown10" },
		{ _field_real, "unknown14" },
		{ _field_real, "unknown18" },
		{ _field_real, "unknown1C" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_constants_weapon_block, 65536)
	{
		{ _field_tag_reference, "weapon", &weapon_reference },
		{ _field_real, "unknown0" },
		{ _field_real, "unknown4" },
		{ _field_real, "unknown8" },
		{ _field_real, "unknownC" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_constants_vehicle_block, 65536)
	{
		{ _field_tag_reference, "vehicle", &vehicle_reference },
		{ _field_real, "unknown0" },
		{ _field_real, "unknown4" },
		{ _field_real, "unknown8" },
		{ _field_real, "unknownC" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_constants_projectile_block, 65536)
	{
		{ _field_tag_reference, "projectile", &projectile_reference },
		{ _field_real, "unknown0" },
		{ _field_real, "unknown4" },
		{ _field_real, "unknown8" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_constants_block, 1)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 14 },
		{ _field_struct, "unknown0", &multiplayer_constants_unknown_struct_struct_definition },
		{ _field_struct, "unknown1", &multiplayer_constants_unknown_struct_struct_definition },
		{ _field_struct, "unknown2", &multiplayer_constants_unknown_struct_struct_definition },
		{ _field_struct, "unknown3", &multiplayer_constants_unknown_struct_struct_definition },
		{ _field_struct, "unknown4", &multiplayer_constants_unknown_struct_struct_definition },
		{ _field_struct, "unknown5", &multiplayer_constants_unknown_struct_struct_definition },
		{ _field_real, "unknownC0" },
		{ _field_block, "weapons", &multiplayer_constants_weapon_block_block },
		{ _field_block, "vehicles", &multiplayer_constants_vehicle_block_block },
		{ _field_block, "projectiles", &multiplayer_constants_projectile_block_block },
		{ _field_real, "unknownE8" },
		{ _field_real, "unknownE4" },
		{ _field_real, "unknownE4" },
		{ _field_real, "unknownE4" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_explanation, "PLAYER SPAWN INFLUENCERS", "These are the default spawn influencer settings which can be overridden by scenario tags" },
		{ _field_tag_reference, "Default Spawn Settings", &g_spawnSettingsReference },

		{ _field_explanation, "MORE MP CONSTANTS", "More old Halo2 stuff follows..." },
		{ _field_real, "teleporter recharge time:seconds" },
		{ _field_tag_reference, "sandbox effect", &global_effect_reference },
		{ _field_string_id, "blocked teleporter string" },
		{ _field_explanation, "RESPAWN STRINGS", "These are used for respawn status message displays\nThe text comes from the in-game-text multiplayer message strings list tag\nin the multiplayer runtime globals block above" },
		{ _field_string_id, "voluntary respawn control instructions" },
		{ _field_string_id, "spawn allowed default respawn" },
		{ _field_string_id, "spawn at player allowed looking at self" },
		{ _field_string_id, "spawn at player allowed looking at target" },
		{ _field_string_id, "spawn at player allowed looking at potential target" },
		{ _field_string_id, "spawn at territory allowed looking at target" },
		{ _field_string_id, "spawn at territory allowed looking at potential target" },
		{ _field_string_id, "you are out of lives" },
		{ _field_string_id, "invalid spawn target selected" },
		{ _field_string_id, "targetted player enemies nearby" },
		{ _field_string_id, "targetted player unfriendly team" },
		{ _field_string_id, "targetted player dead" },
		{ _field_string_id, "targetted player in combat" },
		{ _field_string_id, "targetted player too far from owned flag" },
		{ _field_string_id, "no available netpoints" },
		{ _field_string_id, "targetted netpoint contested" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(game_engine_status_response_block, k_maximum_status_response_count)
	{
		{ _field_word_flags, "flags", &game_engine_status_flags_definition },
		{ _field_pad, "FAW", 2 },
		{ _field_enum, "state^", &game_engine_status_enum_definition },
		{ _field_pad, "BNYFIDDGX", 2 },
		{ _field_string_id, "ffa message" },
		{ _field_string_id, "team message" },
		{ _field_tag_reference, "unused!", &g_non_traversed_reference_definition },
		{ _field_pad, "GTL", 4 },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_unknown_block, 65536)
	{
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_runtime_block, 1)
	{
		{ _field_tag_reference, "editor biped", &unit_reference$4 },
		{ _field_tag_reference, "editor helper", &object_reference$7 },
		{ _field_tag_reference, "flag", &global_item_reference },
		{ _field_tag_reference, "ball", &global_item_reference },
		{ _field_tag_reference, "assault bomb", &global_item_reference },
		{ _field_tag_reference, "vip influence area", &object_reference$7 },
		{ _field_tag_reference, "in game text", &global_multilingual_unicode_string_list_reference },
		{ _field_block, "sounds", &sounds_block_block },
		{ _field_block, "looping sounds", &looping_sounds_block_block },
		{ _field_tag_reference, "megalo sounds{english}", &global_megalogamengine_sound_group_reference },
		{ _field_tag_reference, "communication sounds{comm english}", &global_communication_sound_group_reference },
		{ _field_long_integer, "maximum frag count" },
		{ _field_long_integer, "maximum plasma count" },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "unknown", &multiplayer_unknown_block_block },

		{ _field_block, "multiplayer constants", &multiplayer_constants_block_block },
		{ _field_block, "state responses", &game_engine_status_response_block_block },
		{ _field_tag_reference, "scoreboard emblem bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "scoreboard dead emblem bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "hill shader", &multiplayer_runtime_block_hill_shader_reference },

		{ _field_version_less_or_equal, _engine_type_haloreach, 5 },
		{ _field_tag_reference, "null intro hud", &chud_reference },
		{ _field_tag_reference, "sandbox intro hud", &chud_reference },
		{ _field_tag_reference, "megalo intro hud", &chud_reference },
		{ _field_tag_reference, "campaign intro hud", &chud_reference },
		{ _field_tag_reference, "survival intro hud", &chud_reference },

		{ _field_tag_reference, "default_biped_simulation_interpolation", &global_simulation_interpolation_reference },
		{ _field_tag_reference, "default_vehicle_simulation_interpolation", &global_simulation_interpolation_reference },
		{ _field_tag_reference, "default_crate_simulation_interpolation", &global_simulation_interpolation_reference },
		{ _field_tag_reference, "default_item_simulation_interpolation", &global_simulation_interpolation_reference },
		{ _field_tag_reference, "default_projectile_simulation_interpolation", &global_simulation_interpolation_reference },
		{ _field_tag_reference, "default_object_simulation_interpolation", &global_simulation_interpolation_reference },
		{ _field_tag_reference, "co-op spawning globals", &global_coop_spawning_globals_reference },
		{ _field_tag_reference, "megalo string_id table", &global_megalo_string_id_table_reference },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_tag_reference, "killcam parameters# Used for non projectile killcams.", &Tag::Reference<struct KillCamCameraParameterDefinition>::s_defaultDefinition },

		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(multiplayer_globals_block, 1, multiplayer_globals_struct_definition_struct_definition );

	V5_TAG_BLOCK(multiplayer_color_block$3, 32)
	{
		{ _field_real_rgb_color, "color" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(multiplayer_globals_struct_definition)
	{
		{ _field_block, "universal", &multiplayer_universal_block_block },
		{ _field_block, "runtime", &multiplayer_runtime_block_block },
		{ _field_terminator }
	};

	STRINGS(requisition_special_buy_enum)
	{
		"none",
		"airstrike!",
		"mac cannon",
		"magnetic ammo",
		"laser ammo",
		"explosive ammo",
		"normal ammo",
		"friendly ai light infantry",
		"friendly ai heavy infantry",
		"friendly ai light vehicle",
		"friendly ai heavy vehicle",
		"friendly ai flyer"
	};
	STRING_LIST(requisition_special_buy_enum, requisition_special_buy_enum_strings, _countof(requisition_special_buy_enum_strings));

	STRINGS(emblemInfoFlags)
	{
		"alternate foreground channel off",
		"flip foreground",
		"flip background"
	};
	STRING_LIST(emblemInfoFlags, emblemInfoFlags_strings, _countof(emblemInfoFlags_strings));

	STRINGS(playerColorEnum)
	{
		"player color 0",
		"player color 1",
		"player color 2",
		"player color 3",
		"player color 4",
		"player color 5",
		"player color 6",
		"player color 7",
		"player color 8",
		"player color 9",
		"player color 10",
		"player color 11",
		"player color 12",
		"player color 13",
		"player color 14",
		"player color 15",
		"player color 16",
		"player color 17",
		"player color 18",
		"player color 19",
		"player color 20",
		"player color 21",
		"player color 22",
		"player color 23",
		"player color 24",
		"player color 25",
		"player color 26",
		"player color 27",
		"player color 28",
		"player color 29",
		"player color 30",
		"player color 31"
	};
	STRING_LIST(playerColorEnum, playerColorEnum_strings, _countof(playerColorEnum_strings));

	STRINGS(game_engine_status_enum_definition)
	{
		"waiting for space to clear",
		"observing",
		"respawning soon",
		"sitting out",
		"out of lives",
		"playing (winning)",
		"playing (tied)",
		"playing (losing)",
		"game over (won)",
		"game over (tied)",
		"game over (lost)",
		"game over (you lost, but game tied)",
		"you have flag",
		"enemy has flag",
		"flag not home",
		"carrying oddball",
		"you are juggy",
		"you control hill",
		"switching sides soon",
		"player recently started",
		"you have bomb",
		"flag contested",
		"bomb contested",
		"limited lives left (multiple)",
		"limited lives left (single)",
		"limited lives left (final)",
		"playing (winning, unlimited)",
		"playing (tied, unlimited)",
		"playing (losing, unlimited)",
		"waiting to spawn",
		"waiting for game start",
		"blank"
	};
	STRING_LIST(game_engine_status_enum_definition, game_engine_status_enum_definition_strings, _countof(game_engine_status_enum_definition_strings));

	STRINGS(game_engine_status_flags_definition)
	{
		"unused"
	};
	STRING_LIST(game_engine_status_flags_definition, game_engine_status_flags_definition_strings, _countof(game_engine_status_flags_definition_strings));

} // namespace blofeld

