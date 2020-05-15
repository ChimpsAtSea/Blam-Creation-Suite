#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(multiplayer_universal, 1)
{
	{ _field_tag_reference, "random player names" },
	{ _field_tag_reference, "team names" },
	{ _field_block, "teams", &teamDefinitionBlock_block },
	{ _field_tag_reference, "multiplayer text" },
	{ _field_tag_reference, "sandbox text" },
	{ _field_tag_reference, "sandbox object properties values" },
	{ _field_tag_reference, "effects" },
	{ _field_block, "multiplayer roles", &global_team_role_block },
	{ _field_block, "requisition constants", &requisition_constants_block },
	{ _field_block, "player starting profile", &scenario_profiles_block },
	{ _field_terminator },
};

TAG_BLOCK(teamDefinitionBlock, k_multiplayer_team_game_team_count)
{
	{ _field_string_id, "name^" },
	{ _field_real_rgb_color, "primary color" },
	{ _field_real_rgb_color, "secondary color" },
	{ _field_custom, "- Emblem Data" },
	{ _field_byte_integer, "foreground emblem index" },
	{ _field_byte_integer, "background emblem index" },
	{ _field_byte_flags, "info flags" },
	{ _field_char_enum, "primary color index" },
	{ _field_char_enum, "secondary color index" },
	{ _field_char_enum, "background color index" },
	{ _field_pad, "pad", 2 },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(requisition_constants, 1)
{
	{ _field_real, "FTL bonus fraction#multiplier to apply to money earned by minions to also give to the fireteam leader" },
	{ _field_explanation, "AWARD AMOUNTS" },
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
	{ _field_explanation, "PENALTY AMOUNTS" },
	{ _field_long_integer, "Betrayed a teammate" },
	{ _field_explanation, "FIRE TEAM TIER KILL REQUIREMENTS" },
	{ _field_long_integer, "Bronze kill minimum" },
	{ _field_long_integer, "Silver kill minimum" },
	{ _field_long_integer, "Gold kill minimum" },
	{ _field_explanation, "FIRE TEAM TIER BONUS MULTIPLIERS" },
	{ _field_real, "Bronze multiplier" },
	{ _field_real, "Silver multiplier" },
	{ _field_real, "Gold multiplier" },
	{ _field_explanation, "FIRE TEAM TIER TIME REQUIREMENT" },
	{ _field_long_integer, "Bronze advancement time" },
	{ _field_long_integer, "Silver advancement time" },
	{ _field_long_integer, "Gold advancement time" },
	{ _field_block, "Requisition palette", &requisition_palette_block },
	{ _field_terminator },
};

TAG_BLOCK(requisition_palette, k_infinity_requisition_palette_maximum_count)
{
	{ _field_explanation, "CUSTOM APPS" },
	{ _field_tag_reference, "name" },
	{ _field_string_id, "display_name^" },
	{ _field_long_enum, "special_buy" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_runtime, 1)
{
	{ _field_tag_reference, "editor biped" },
	{ _field_tag_reference, "editor helper" },
	{ _field_tag_reference, "flag" },
	{ _field_tag_reference, "ball" },
	{ _field_tag_reference, "assault bomb" },
	{ _field_tag_reference, "vip influence area" },
	{ _field_tag_reference, "in game text" },
	{ _field_block, "sounds", &sounds_block },
	{ _field_block, "looping sounds", &looping_sounds_block },
	{ _field_tag_reference, "megalo sounds{english}" },
	{ _field_tag_reference, "communication sounds{comm english}" },
	{ _field_long_integer, "maximum frag count" },
	{ _field_long_integer, "maximum plasma count" },
	{ _field_block, "multiplayer constants", &multiplayer_constants_block },
	{ _field_block, "state responses", &game_engine_status_response_block },
	{ _field_tag_reference, "scoreboard emblem bitmap" },
	{ _field_tag_reference, "scoreboard dead emblem bitmap" },
	{ _field_tag_reference, "hill shader" },
	{ _field_tag_reference, "default_biped_simulation_interpolation" },
	{ _field_tag_reference, "default_vehicle_simulation_interpolation" },
	{ _field_tag_reference, "default_crate_simulation_interpolation" },
	{ _field_tag_reference, "default_item_simulation_interpolation" },
	{ _field_tag_reference, "default_projectile_simulation_interpolation" },
	{ _field_tag_reference, "default_object_simulation_interpolation" },
	{ _field_tag_reference, "co-op spawning globals" },
	{ _field_tag_reference, "megalo string_id table" },
	{ _field_tag_reference, "killcam parameters# Used for non projectile killcams." },
	{ _field_terminator },
};

TAG_BLOCK(sounds, k_maximum_multiplayer_sounds)
{
	{ _field_tag_reference, "sound^" },
	{ _field_terminator },
};

TAG_BLOCK(looping_sounds, k_maximum_multiplayer_sounds)
{
	{ _field_tag_reference, "looping sound^" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_constants, 1)
{
	{ _field_explanation, "PLAYER SPAWN INFLUENCERS" },
	{ _field_tag_reference, "Default Spawn Settings" },
	{ _field_explanation, "MORE MP CONSTANTS" },
	{ _field_real, "teleporter recharge time:seconds" },
	{ _field_tag_reference, "sandbox effect" },
	{ _field_string_id, "blocked teleporter string" },
	{ _field_explanation, "RESPAWN STRINGS" },
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
	{ _field_terminator },
};

TAG_BLOCK(game_engine_status_response, k_maximum_status_response_count)
{
	{ _field_word_flags, "flags" },
	{ _field_pad, "FAW", 2 },
	{ _field_enum, "state^" },
	{ _field_pad, "BNYFIDDGX", 2 },
	{ _field_string_id, "ffa message" },
	{ _field_string_id, "team message" },
	{ _field_tag_reference, "unused!" },
	{ _field_pad, "GTL", 4 },
	{ _field_terminator },
};

TAG_BLOCK(spawn_influence_weight_falloff_function, 1)
{
	{ _field_struct, "function" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_color$2, 32)
{
	{ _field_real_rgb_color, "color" },
	{ _field_terminator },
};

TAG_GROUP(multiplayer_globals, MULTIPLAYER_GLOBALS_TAG)
{
	{ _field_block, "universal", &multiplayer_universal_block },
	{ _field_block, "runtime", &multiplayer_runtime_block },
	{ _field_terminator },
};

} // namespace blofeld

