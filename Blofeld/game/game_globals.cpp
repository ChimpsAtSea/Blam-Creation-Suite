#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(havok_cleanup_resources, 1)
{
	{ _field_tag_reference, "object cleanup effect" },
	{ _field_terminator },
};

TAG_BLOCK(sound$2, NUMBER_OF_GLOBAL_SOUNDS)
{
	{ _field_tag_reference, "sound (OBSOLETE)" },
	{ _field_terminator },
};

TAG_BLOCK(soft_ceiling_globals, 1)
{
	{ _field_real, "biped spring constant" },
	{ _field_real, "biped normal damping" },
	{ _field_real, "biped tangent damping" },
	{ _field_real, "biped min tangent damp velocity" },
	{ _field_real, "vehicle spring constant" },
	{ _field_real, "vehicle normal damping" },
	{ _field_real, "vehicle tangent damping" },
	{ _field_terminator },
};

TAG_BLOCK(cheat_weapons, 20)
{
	{ _field_tag_reference, "weapon^" },
	{ _field_terminator },
};

TAG_BLOCK(cheat_powerups, 20)
{
	{ _field_tag_reference, "powerup^" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_color, k_player_color_index_count)
{
	{ _field_real_rgb_color, "color" },
	{ _field_terminator },
};

TAG_BLOCK(visor_color, 32)
{
	{ _field_string_id, "name^" },
	{ _field_real_rgb_color, "tertiary color" },
	{ _field_real_rgb_color, "quaternary color" },
	{ _field_terminator },
};

TAG_GROUP(globals, GLOBALS_TAG)
{
	{ _field_pad, "YJLTWDSL", 172 },
	{ _field_long_enum, "language" },
	{ _field_block, "havok cleanup resources", &havok_cleanup_resources_block },
	{ _field_block, "sound globals", &sound_globals_block },
	{ _field_explanation, "AI globals" },
	{ _field_block, "DEPRECATED{ai globals}*!", &ai_globals_data_block },
	{ _field_tag_reference, "ai globals ref" },
	{ _field_block, "damage table", &game_globals_damage_block },
	{ _field_block, "sounds", &sound$2_block },
	{ _field_block, "camera", &camera_block },
	{ _field_block, "controller input", &controller_input_block },
	{ _field_block, "player control", &player_control_block },
	{ _field_block, "default player traits", &game_engine_player_traits_block },
	{ _field_block, "difficulty", &difficulty_block },
	{ _field_block, "co-op difficulty", &coop_difficulty_block },
	{ _field_block, "soft ceilings", &soft_ceiling_globals_block },
	{ _field_block, "interface tags", &interface_tag_references_block },
	{ _field_block, "@weapon list (update _weapon_list enum in game_globals.h)", &cheat_weapons_block },
	{ _field_block, "@cheat powerups", &cheat_powerups_block },
	{ _field_block, "@player information", &player_information_block },
	{ _field_block, "@player representation", &player_representation_block },
	{ _field_block, "damage{falling damage}", &damage_globals_block },
	{ _field_block, "shield boost", &shield_boost_block },
	{ _field_block, "materials", &materials_block },
	{ _field_block, "profile colors", &multiplayer_color_block },
	{ _field_block, "emblem colors", &multiplayer_color_block },
	{ _field_block, "visor colors", &visor_color_block },
	{ _field_custom, "Elite specular colors" },
	{ _field_struct, "elite specular color" },
	{ _field_custom },
	{ _field_tag_reference, "forge globals" },
	{ _field_tag_reference, "game engine globals" },
	{ _field_tag_reference, "multiplayer globals" },
	{ _field_tag_reference, "survival_mode globals" },
	{ _field_tag_reference, "firefight globals" },
	{ _field_tag_reference, "global multiplayer object type list" },
	{ _field_tag_reference, "custom app globals" },
	{ _field_tag_reference, "grenades" },
	{ _field_tag_reference, "ordnances" },
	{ _field_tag_reference, "silent assist" },
	{ _field_block, "cinematics globals", &cinematics_globals_block },
	{ _field_block, "campaign metagame globals", &campaign_metagame_globals_block },
	{ _field_tag_reference, "game medal globals" },
	{ _field_struct, "language pack1!" },
	{ _field_struct, "language pack2!" },
	{ _field_struct, "language pack3!" },
	{ _field_struct, "language pack4!" },
	{ _field_struct, "language pack5!" },
	{ _field_struct, "language pack6!" },
	{ _field_struct, "language pack7!" },
	{ _field_struct, "language pack8!" },
	{ _field_struct, "language pack9!" },
	{ _field_struct, "language pack10!" },
	{ _field_struct, "language pack11!" },
	{ _field_struct, "language pack12!" },
	{ _field_struct, "language pack13!" },
	{ _field_struct, "language pack14!" },
	{ _field_struct, "language pack15!" },
	{ _field_struct, "language pack16!" },
	{ _field_struct, "language pack17!" },
	{ _field_explanation, "Rasterizer globals" },
	{ _field_tag_reference, "rasterizer_globals_ref" },
	{ _field_explanation, "Default camera fx settings" },
	{ _field_tag_reference, "default camera fx settings" },
	{ _field_explanation, "Default wind settings" },
	{ _field_tag_reference, "default wind settings" },
	{ _field_explanation, "Weather globals" },
	{ _field_tag_reference, "weather globals" },
	{ _field_explanation, "Default collision damage" },
	{ _field_tag_reference, "collision damage effect" },
	{ _field_tag_reference, "collision damage" },
	{ _field_explanation, "global material types" },
	{ _field_string_id, "global water material#the default value for what material type water is" },
	{ _field_string_id, "global air material#the default value for what material type air is" },
	{ _field_short_integer, "global water material type!" },
	{ _field_short_integer, "global air material type!" },
	{ _field_tag_reference, "effect globals" },
	{ _field_tag_reference, "havok collision filter" },
	{ _field_tag_reference, "default item grounded friction" },
	{ _field_block, "active camo", &active_camo_globals_block },
	{ _field_tag_reference, "incident global properties" },
	{ _field_tag_reference, "player grade globals" },
	{ _field_tag_reference, "enlistment globals" },
	{ _field_tag_reference, "player model customization globals" },
	{ _field_tag_reference, "loadout globals" },
	{ _field_tag_reference, "challenge globals" },
	{ _field_tag_reference, "game completion rewards globals" },
	{ _field_tag_reference, "game achievements" },
	{ _field_tag_reference, "game avatar awards" },
	{ _field_tag_reference, "game performance thortles default" },
	{ _field_tag_reference, "armormod globals" },
	{ _field_tag_reference, "progression globals" },
	{ _field_block, "garbage collection", &garbage_collection_block },
	{ _field_block, "camera impulse", &global_camera_impulse_block },
	{ _field_block, "runtime materials*!", &runtime_materials_block },
	{ _field_block, "Hologram Lighting", &hologramLightingGlobalsBlock_block },
	{ _field_tag_reference, "Narrative globals" },
	{ _field_terminator },
};

TAG_GROUP(patch_globals, PATCH_GLOBALS_TAG)
{
	{ _field_struct, "language pack1!" },
	{ _field_struct, "language pack2!" },
	{ _field_struct, "language pack3!" },
	{ _field_struct, "language pack4!" },
	{ _field_struct, "language pack5!" },
	{ _field_struct, "language pack6!" },
	{ _field_struct, "language pack7!" },
	{ _field_struct, "language pack8!" },
	{ _field_struct, "language pack9!" },
	{ _field_struct, "language pack10!" },
	{ _field_struct, "language pack11!" },
	{ _field_struct, "language pack12!" },
	{ _field_struct, "language pack13!" },
	{ _field_struct, "language pack14!" },
	{ _field_struct, "language pack15!" },
	{ _field_struct, "language pack16!" },
	{ _field_struct, "language pack17!" },
	{ _field_terminator },
};

} // namespace blofeld

