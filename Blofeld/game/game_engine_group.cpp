#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(GameEngineFirefightVariantTag, GAMEENGINEFIREFIGHTVARIANTTAG_TAG)
{
	FIELD( _field_struct, "variant", &gameEngineFirefightVariantDefinition_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP_FROM_BLOCK(game_engine_globals, GAME_ENGINE_GLOBALS_TAG, game_engine_globals_block_block )

TAG_GROUP_FROM_BLOCK(game_engine_settings_definition, GAME_ENGINE_SETTINGS_DEFINITION_TAG, game_engine_settings_definition_block_block )

TAG_BLOCK_FROM_STRUCT(game_engine_globals_block, 1, game_engine_globals_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(game_engine_settings_definition_block, 1, game_engine_settings_definition_struct_definition_struct_definition );

TAG_BLOCK(game_engine_miscellaneous_options_block, 1)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_char_integer, "early victory win count" ),
	FIELD( _field_char_integer, "round time limit:minutes" ),
	FIELD( _field_char_integer, "number of rounds" ),
	FIELD( _field_char_enum, "mosh difficulty level" ),
	FIELD( _field_byte_integer, "overshield deplete time" ),
	FIELD( _field_pad, "RXXH", 1 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_prototype_options_block, 1)
{
	FIELD( _field_char_integer, "prototype mode" ),
	FIELD( _field_char_integer, "promethean energy kill percent" ),
	FIELD( _field_char_integer, "promethean energy time percent" ),
	FIELD( _field_char_integer, "promethean energy medal percent" ),
	FIELD( _field_char_integer, "promethean duration" ),
	FIELD( _field_char_integer, "class color override" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_respawn_options_block, 1)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_char_integer, "lives per round" ),
	FIELD( _field_char_integer, "team lives per round" ),
	FIELD( _field_char_integer, "min respawn time:seconds" ),
	FIELD( _field_char_integer, "respawn time:seconds" ),
	FIELD( _field_char_integer, "suicide penalty:seconds" ),
	FIELD( _field_char_integer, "betrayal penalty:seconds" ),
	FIELD( _field_char_integer, "respawn growth:seconds" ),
	FIELD( _field_pad, "EOTOTRXV", 3 ),
	FIELD( _field_string_id, "respawn player traits name" ),
	FIELD( _field_char_integer, "initial loadout selection time:seconds#delay before spawning in at start of round" ),
	FIELD( _field_char_integer, "respawn player traits duration:seconds" ),
	FIELD( _field_pad, "woman bound for glory, why you leaving me again\?", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_social_options_block, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_map_override_options_block, 1)
{
	FIELD( _field_string_id, "player traits name" ),
	FIELD( _field_string_id, "weapon set name" ),
	FIELD( _field_string_id, "vehicle set name" ),
	FIELD( _field_string_id, "equipment set name" ),
	FIELD( _field_string_id, "red powerup traits name" ),
	FIELD( _field_string_id, "blue powerup traits name" ),
	FIELD( _field_string_id, "yellow powerup traits name" ),
	FIELD( _field_string_id, "custom powerup traits name" ),
	FIELD( _field_char_integer, "red powerup duration:seconds" ),
	FIELD( _field_char_integer, "blue powerup duration:seconds" ),
	FIELD( _field_char_integer, "yellow powerup duration:seconds" ),
	FIELD( _field_char_integer, "custom powerup duration:seconds" ),
	FIELD( _field_string_id, "red powerup secondary traits name" ),
	FIELD( _field_string_id, "blue powerup secondary traits name" ),
	FIELD( _field_string_id, "yellow powerup secondary traits name" ),
	FIELD( _field_string_id, "custom powerup secondary traits name" ),
	FIELD( _field_char_integer, "red powerup secondary duration:seconds" ),
	FIELD( _field_char_integer, "blue powerup secondary duration:seconds" ),
	FIELD( _field_char_integer, "yellow powerup secondary duration:seconds" ),
	FIELD( _field_char_integer, "custom powerup secondary duration:seconds" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_team_options_block, 1)
{
	FIELD( _field_char_enum, "model override type" ),
	FIELD( _field_char_enum, "designator switch type" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_array, "teams" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gameEngineOrdnanceOptionsBlock, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(GameEngineFirefightPlayerGoalPropertiesBlock, k_firefightMaxPlayerGoals)
{
	FIELD( _field_char_enum, "Player Goal" ),
	FIELD( _field_char_integer, "Lives" ),
	FIELD( _field_char_integer, "Time Limit#minutes" ),
	FIELD( _field_byte_flags, "Wave Difficulty" ),
	FIELD( _field_block, "Firefight Waves", &GameEngineFirefightWavePropertiesBlock_block ),
	FIELD( _field_long_flags, "Player Goal Flags" ),
	FIELD( _field_string_id, "spartan player traits" ),
	FIELD( _field_string_id, "ai traits" ),
	FIELD( _field_string, "Start Event" ),
	FIELD( _field_string, "End Event" ),
	FIELD( _field_long_flags, "skulls^{primary skulls}" ),
	FIELD( _field_char_integer, "objective 1" ),
	FIELD( _field_char_integer, "objective 2" ),
	FIELD( _field_char_integer, "objective 3" ),
	FIELD( _field_char_integer, "objective 4" ),
	FIELD( _field_char_integer, "User Data" ),
	FIELD( _field_char_integer, "start location folder" ),
	FIELD( _field_pad, "BLAH", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(GameEngineFirefightWavePropertiesBlock, k_firefightWavesPerGoal)
{
	FIELD( _field_string_id, "squad type^#survival_mode_get_wave_squad" ),
	FIELD( _field_char_enum, "Delivery type" ),
	FIELD( _field_char_integer, "AI allowed before next wave spawns" ),
	FIELD( _field_char_integer, "Enemies Left Before HUD Marking" ),
	FIELD( _field_char_integer, "Wave Type" ),
	FIELD( _field_char_integer, "Weapon to drop" ),
	FIELD( _field_char_integer, "Vehicle to drop" ),
	FIELD( _field_char_integer, "Squad 1" ),
	FIELD( _field_char_integer, "Squad 2" ),
	FIELD( _field_string, "Start Event" ),
	FIELD( _field_string, "End Event" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_ai_traits_list_block, 64)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_struct, "ai traits", &game_engine_ai_traits_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_sandbox_variant_block, 32)
{
	FIELD( _field_string_id, "localizable name^" ),
	FIELD( _field_string_id, "localizable description" ),
	FIELD( _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block_block ),
	FIELD( _field_block, "prototype options", &game_engine_prototype_options_block_block ),
	FIELD( _field_block, "respawn options", &game_engine_respawn_options_block_block ),
	FIELD( _field_block, "social options", &game_engine_social_options_block_block ),
	FIELD( _field_block, "map override options", &game_engine_map_override_options_block_block ),
	FIELD( _field_block, "team options", &game_engine_team_options_block_block ),
	FIELD( _field_block, "loadout options", &game_engine_loadout_options_block_block ),
	FIELD( _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_enum, "edit mode" ),
	FIELD( _field_enum, "respawn time" ),
	FIELD( _field_string_id, "all players traits" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_survival_variant_block, 32)
{
	FIELD( _field_string_id, "localizable name^" ),
	FIELD( _field_string_id, "localizable description" ),
	FIELD( _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block_block ),
	FIELD( _field_block, "prototype options", &game_engine_prototype_options_block_block ),
	FIELD( _field_block, "respawn options", &game_engine_respawn_options_block_block ),
	FIELD( _field_block, "social options", &game_engine_social_options_block_block ),
	FIELD( _field_block, "map override options", &game_engine_map_override_options_block_block ),
	FIELD( _field_block, "team options", &game_engine_team_options_block_block ),
	FIELD( _field_block, "loadout options", &game_engine_loadout_options_block_block ),
	FIELD( _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_enum, "game difficulty" ),
	FIELD( _field_pad, "SDFHJREN", 2 ),
	FIELD( _field_char_integer, "set count#survival_mode_get_set_count, -1 to loop last, -2 to loop last 3, -3 to loop all" ),
	FIELD( _field_char_integer, "bonus lives awarded#survival_mode_get_bonus_lives_awarded" ),
	FIELD( _field_short_integer, "bonus target#survival_mode_get_bonus_target" ),
	FIELD( _field_short_integer, "spartan lives on elite death" ),
	FIELD( _field_short_integer, "extra life score target" ),
	FIELD( _field_short_integer, "shared team life count" ),
	FIELD( _field_short_integer, "elite life count" ),
	FIELD( _field_short_integer, "maximum lives" ),
	FIELD( _field_short_integer, "generator count" ),
	FIELD( _field_string_id, "spartan player traits" ),
	FIELD( _field_string_id, "elite player traits" ),
	FIELD( _field_string_id, "ai traits" ),
	FIELD( _field_block, "elite respawn options", &game_engine_respawn_options_block_block ),
	FIELD( _field_block, "set properties", &game_engine_survival_set_properties_block_block ),
	FIELD( _field_block, "round properties", &game_engine_survival_round_properties_block_block ),
	FIELD( _field_custom, "bonus round" ),
	FIELD( _field_struct, "bonus round properties", &game_engine_survival_bonus_wave_properties_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_block, "custom skulls", &game_engine_survival_custom_skull_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_survival_set_properties_block, 10)
{
	FIELD( _field_long_flags, "skulls^{primary skulls}" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_survival_round_properties_block, k_survival_full_rounds_per_set)
{
	FIELD( _field_long_flags, "skulls^{primary skulls}" ),
	FIELD( _field_custom, "initial wave" ),
	FIELD( _field_struct, "initial waves", &game_engine_survival_wave_properties_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "primary wave" ),
	FIELD( _field_struct, "primary waves", &game_engine_survival_wave_properties_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "boss wave" ),
	FIELD( _field_struct, "boss waves", &game_engine_survival_wave_properties_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(survival_wave_squad_block, k_maximum_survival_possible_wave_squads)
{
	FIELD( _field_string_id, "squad type^#survival_mode_get_wave_squad" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_survival_custom_skull_block, k_maximum_survival_custom_skulls)
{
	FIELD( _field_string_id, "spartan player traits" ),
	FIELD( _field_string_id, "elite player traits" ),
	FIELD( _field_string_id, "ai traits" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(GameEngineFirefightVariantShellBlock, 128)
{
	FIELD( _field_tag_reference, "variant" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_campaign_variant_block, 32)
{
	FIELD( _field_string_id, "localizable name^" ),
	FIELD( _field_string_id, "localizable description" ),
	FIELD( _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block_block ),
	FIELD( _field_block, "prototype options", &game_engine_prototype_options_block_block ),
	FIELD( _field_block, "respawn options", &game_engine_respawn_options_block_block ),
	FIELD( _field_block, "social options", &game_engine_social_options_block_block ),
	FIELD( _field_block, "map override options", &game_engine_map_override_options_block_block ),
	FIELD( _field_block, "team options", &game_engine_team_options_block_block ),
	FIELD( _field_block, "loadout options", &game_engine_loadout_options_block_block ),
	FIELD( _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_engine_globals_struct_definition)
{
	FIELD( _field_tag_reference, "game engine settings" ),
	FIELD( _field_tag_reference, "game engine text" ),
	FIELD( _field_block, "game engine event response list", &game_engine_event_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_engine_settings_definition_struct_definition)
{
	FIELD( _field_explanation, "Game Engine Settings" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_block, "player traits", &game_engine_player_traits_list_block_block ),
	FIELD( _field_block, "ai traits", &game_engine_ai_traits_list_block_block ),
	FIELD( _field_block, "sandbox variants", &game_engine_sandbox_variant_block_block ),
	FIELD( _field_block, "survival variants", &game_engine_survival_variant_block_block ),
	FIELD( _field_block, "new firefight variants{firefight variants new}", &GameEngineFirefightVariantShellBlock_block ),
	FIELD( _field_block, "campaign variants", &game_engine_campaign_variant_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(gameEngineFirefightVariantDefinition)
{
	FIELD( _field_string_id, "localizable name^" ),
	FIELD( _field_string_id, "localizable description" ),
	FIELD( _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block_block ),
	FIELD( _field_block, "prototype options", &game_engine_prototype_options_block_block ),
	FIELD( _field_block, "respawn options", &game_engine_respawn_options_block_block ),
	FIELD( _field_block, "social options", &game_engine_social_options_block_block ),
	FIELD( _field_block, "map override options", &game_engine_map_override_options_block_block ),
	FIELD( _field_block, "team options", &game_engine_team_options_block_block ),
	FIELD( _field_block, "loadout options", &game_engine_loadout_options_block_block ),
	FIELD( _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block ),
	FIELD( _field_long_integer, "mission_id" ),
	FIELD( _field_char_enum, "game difficulty" ),
	FIELD( _field_byte_flags, "firefight variant flags" ),
	FIELD( _field_short_integer, "shared team life count" ),
	FIELD( _field_short_integer, "maximum lives" ),
	FIELD( _field_char_integer, "Starting Crate 1" ),
	FIELD( _field_char_integer, "Starting Crate 2" ),
	FIELD( _field_char_integer, "Starting Crate 3" ),
	FIELD( _field_char_integer, "Starting Crate 4" ),
	FIELD( _field_char_integer, "Starting Crate 5" ),
	FIELD( _field_char_integer, "Starting Crate 6" ),
	FIELD( _field_char_integer, "Starting Crate 7" ),
	FIELD( _field_char_integer, "Starting Crate 8" ),
	FIELD( _field_char_integer, "Starting Crate 9" ),
	FIELD( _field_char_integer, "Starting Crate 10" ),
	FIELD( _field_char_integer, "Starting Crate 11" ),
	FIELD( _field_char_integer, "Starting Crate 12" ),
	FIELD( _field_char_integer, "Starting Crate 13" ),
	FIELD( _field_char_integer, "Starting Crate 14" ),
	FIELD( _field_string, "Variant Event#This event is always set for script" ),
	FIELD( _field_block, "Midnight Player Goal Properties", &GameEngineFirefightPlayerGoalPropertiesBlock_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_engine_survival_wave_properties_struct)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_enum, "wave selection type" ),
	FIELD( _field_pad, "VJKNMFEN", 2 ),
	FIELD( _field_block, "wave squads", &survival_wave_squad_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_engine_ai_traits_struct)
{
	FIELD( _field_char_enum, "vision traits" ),
	FIELD( _field_char_enum, "sound traits" ),
	FIELD( _field_char_enum, "luck traits" ),
	FIELD( _field_char_enum, "weapon traits" ),
	FIELD( _field_char_enum, "grenade traits" ),
	FIELD( _field_char_enum, "drop equipment on death" ),
	FIELD( _field_char_enum, "assassination immunity" ),
	FIELD( _field_char_enum, "headshot immunity" ),
	FIELD( _field_char_enum, "damage resistance percentage" ),
	FIELD( _field_char_enum, "damage modifier percentage" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_engine_survival_bonus_wave_properties_struct)
{
	FIELD( _field_long_flags, "skulls^{primary skulls}" ),
	FIELD( _field_short_integer, "duration:s" ),
	FIELD( _field_pad, "CLKJSDF", 2 ),
	FIELD( _field_struct, "base properties", &game_engine_survival_wave_properties_struct_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

