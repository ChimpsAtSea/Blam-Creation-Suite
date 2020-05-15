#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_engine_ai_traits_list, 64)
{
	{ _field_string_id, "name^" },
	{ _field_struct, "ai traits" },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_sandbox_variant, 32)
{
	{ _field_string_id, "localizable name^" },
	{ _field_string_id, "localizable description" },
	{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block },
	{ _field_block, "prototype options", &game_engine_prototype_options_block },
	{ _field_block, "respawn options", &game_engine_respawn_options_block },
	{ _field_block, "social options", &game_engine_social_options_block },
	{ _field_block, "map override options", &game_engine_map_override_options_block },
	{ _field_block, "team options", &game_engine_team_options_block },
	{ _field_block, "loadout options", &game_engine_loadout_options_block },
	{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
	{ _field_long_flags, "flags" },
	{ _field_enum, "edit mode" },
	{ _field_enum, "respawn time" },
	{ _field_string_id, "all players traits" },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_miscellaneous_options, 1)
{
	{ _field_word_flags, "flags" },
	{ _field_char_integer, "early victory win count" },
	{ _field_char_integer, "round time limit:minutes" },
	{ _field_char_integer, "number of rounds" },
	{ _field_char_enum, "mosh difficulty level" },
	{ _field_byte_integer, "overshield deplete time" },
	{ _field_pad, "RXXH", 1 },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_prototype_options, 1)
{
	{ _field_char_integer, "prototype mode" },
	{ _field_char_integer, "promethean energy kill percent" },
	{ _field_char_integer, "promethean energy time percent" },
	{ _field_char_integer, "promethean energy medal percent" },
	{ _field_char_integer, "promethean duration" },
	{ _field_char_integer, "class color override" },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_respawn_options, 1)
{
	{ _field_word_flags, "flags" },
	{ _field_char_integer, "lives per round" },
	{ _field_char_integer, "team lives per round" },
	{ _field_char_integer, "min respawn time:seconds" },
	{ _field_char_integer, "respawn time:seconds" },
	{ _field_char_integer, "suicide penalty:seconds" },
	{ _field_char_integer, "betrayal penalty:seconds" },
	{ _field_char_integer, "respawn growth:seconds" },
	{ _field_pad, "EOTOTRXV", 3 },
	{ _field_string_id, "respawn player traits name" },
	{ _field_char_integer, "initial loadout selection time:seconds#delay before spawning in at start of round" },
	{ _field_char_integer, "respawn player traits duration:seconds" },
	{ _field_pad, "woman bound for glory, why you leaving me again\?", 2 },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_social_options, 1)
{
	{ _field_long_flags, "flags" },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_map_override_options, 1)
{
	{ _field_string_id, "player traits name" },
	{ _field_string_id, "weapon set name" },
	{ _field_string_id, "vehicle set name" },
	{ _field_string_id, "equipment set name" },
	{ _field_string_id, "red powerup traits name" },
	{ _field_string_id, "blue powerup traits name" },
	{ _field_string_id, "yellow powerup traits name" },
	{ _field_string_id, "custom powerup traits name" },
	{ _field_char_integer, "red powerup duration:seconds" },
	{ _field_char_integer, "blue powerup duration:seconds" },
	{ _field_char_integer, "yellow powerup duration:seconds" },
	{ _field_char_integer, "custom powerup duration:seconds" },
	{ _field_string_id, "red powerup secondary traits name" },
	{ _field_string_id, "blue powerup secondary traits name" },
	{ _field_string_id, "yellow powerup secondary traits name" },
	{ _field_string_id, "custom powerup secondary traits name" },
	{ _field_char_integer, "red powerup secondary duration:seconds" },
	{ _field_char_integer, "blue powerup secondary duration:seconds" },
	{ _field_char_integer, "yellow powerup secondary duration:seconds" },
	{ _field_char_integer, "custom powerup secondary duration:seconds" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "pad", 3 },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_team_options, 1)
{
	{ _field_char_enum, "model override type" },
	{ _field_char_enum, "designator switch type" },
	{ _field_pad, "pad", 2 },
	{ _field_array, "teams" },
	{ _field_terminator },
};

TAG_BLOCK(gameEngineOrdnanceOptionsBlock, 1)
{
	{ _field_byte_flags, "flags" },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_survival_variant, 32)
{
	{ _field_string_id, "localizable name^" },
	{ _field_string_id, "localizable description" },
	{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block },
	{ _field_block, "prototype options", &game_engine_prototype_options_block },
	{ _field_block, "respawn options", &game_engine_respawn_options_block },
	{ _field_block, "social options", &game_engine_social_options_block },
	{ _field_block, "map override options", &game_engine_map_override_options_block },
	{ _field_block, "team options", &game_engine_team_options_block },
	{ _field_block, "loadout options", &game_engine_loadout_options_block },
	{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "game difficulty" },
	{ _field_pad, "SDFHJREN", 2 },
	{ _field_char_integer, "set count#survival_mode_get_set_count, -1 to loop last, -2 to loop last 3, -3 to loop all" },
	{ _field_char_integer, "bonus lives awarded#survival_mode_get_bonus_lives_awarded" },
	{ _field_short_integer, "bonus target#survival_mode_get_bonus_target" },
	{ _field_short_integer, "spartan lives on elite death" },
	{ _field_short_integer, "extra life score target" },
	{ _field_short_integer, "shared team life count" },
	{ _field_short_integer, "elite life count" },
	{ _field_short_integer, "maximum lives" },
	{ _field_short_integer, "generator count" },
	{ _field_string_id, "spartan player traits" },
	{ _field_string_id, "elite player traits" },
	{ _field_string_id, "ai traits" },
	{ _field_block, "elite respawn options", &game_engine_respawn_options_block },
	{ _field_block, "set properties", &game_engine_survival_set_properties_block },
	{ _field_block, "round properties", &game_engine_survival_round_properties_block },
	{ _field_custom, "bonus round" },
	{ _field_struct, "bonus round properties" },
	{ _field_custom },
	{ _field_block, "custom skulls", &game_engine_survival_custom_skull_block },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_survival_set_properties, 10)
{
	{ _field_long_flags, "skulls^{primary skulls}" },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_survival_round_properties, k_survival_full_rounds_per_set)
{
	{ _field_long_flags, "skulls^{primary skulls}" },
	{ _field_custom, "initial wave" },
	{ _field_struct, "initial waves" },
	{ _field_custom },
	{ _field_custom, "primary wave" },
	{ _field_struct, "primary waves" },
	{ _field_custom },
	{ _field_custom, "boss wave" },
	{ _field_struct, "boss waves" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_survival_custom_skull, k_maximum_survival_custom_skulls)
{
	{ _field_string_id, "spartan player traits" },
	{ _field_string_id, "elite player traits" },
	{ _field_string_id, "ai traits" },
	{ _field_terminator },
};

TAG_BLOCK(GameEngineFirefightVariantShellBlock, 128)
{
	{ _field_tag_reference, "variant" },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_campaign_variant, 32)
{
	{ _field_string_id, "localizable name^" },
	{ _field_string_id, "localizable description" },
	{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block },
	{ _field_block, "prototype options", &game_engine_prototype_options_block },
	{ _field_block, "respawn options", &game_engine_respawn_options_block },
	{ _field_block, "social options", &game_engine_social_options_block },
	{ _field_block, "map override options", &game_engine_map_override_options_block },
	{ _field_block, "team options", &game_engine_team_options_block },
	{ _field_block, "loadout options", &game_engine_loadout_options_block },
	{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
	{ _field_terminator },
};

TAG_GROUP(GameEngineFirefightVariantTag, GAMEENGINEFIREFIGHTVARIANTTAG_TAG)
{
	{ _field_struct, "variant" },
	{ _field_terminator },
};

TAG_GROUP(game_engine_globals, GAME_ENGINE_GLOBALS_TAG)
{
	{ _field_tag_reference, "game engine settings" },
	{ _field_tag_reference, "game engine text" },
	{ _field_block, "game engine event response list", &game_engine_event_block },
	{ _field_terminator },
};

TAG_GROUP(game_engine_settings_definition, GAME_ENGINE_SETTINGS_DEFINITION_TAG)
{
	{ _field_explanation, "Game Engine Settings" },
	{ _field_long_flags, "flags" },
	{ _field_block, "player traits", &game_engine_player_traits_list_block },
	{ _field_block, "ai traits", &game_engine_ai_traits_list_block },
	{ _field_block, "sandbox variants", &game_engine_sandbox_variant_block },
	{ _field_block, "survival variants", &game_engine_survival_variant_block },
	{ _field_block, "new firefight variants{firefight variants new}", &GameEngineFirefightVariantShellBlock_block },
	{ _field_block, "campaign variants", &game_engine_campaign_variant_block },
	{ _field_terminator },
};

} // namespace blofeld

