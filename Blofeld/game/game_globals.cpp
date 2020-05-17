#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(language_enum, 17)
	{
		OPTION("english"),
		OPTION("japanese"),
		OPTION("german"),
		OPTION("french"),
		OPTION("spanish"),
		OPTION("mexican spanish"),
		OPTION("italian"),
		OPTION("korean"),
		OPTION("chinese-traditional"),
		OPTION("chinese-simplified"),
		OPTION("portuguese"),
		OPTION("polish"),
		OPTION("russian"),
		OPTION("danish"),
		OPTION("finnish"),
		OPTION("dutch"),
		OPTION("norwegian"),
	};

	TAG_GROUP_FROM_BLOCK(globals, GLOBALS_TAG, globals_block_block );

	TAG_GROUP_FROM_BLOCK(patch_globals, PATCH_GLOBALS_TAG, patch_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(globals_block, 1, globals_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(patch_globals_block, 1, patch_globals_struct_definition_struct_definition );

	TAG_BLOCK(havok_cleanup_resources_block, 1)
	{
		FIELD( _field_tag_reference, "object cleanup effect" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(sound_block$2, NUMBER_OF_GLOBAL_SOUNDS)
	{
		FIELD( _field_tag_reference, "sound (OBSOLETE)" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(soft_ceiling_globals_block, 1)
	{
		FIELD( _field_real, "biped spring constant" ),
		FIELD( _field_real, "biped normal damping" ),
		FIELD( _field_real, "biped tangent damping" ),
		FIELD( _field_real, "biped min tangent damp velocity" ),
		FIELD( _field_real, "vehicle spring constant" ),
		FIELD( _field_real, "vehicle normal damping" ),
		FIELD( _field_real, "vehicle tangent damping" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cheat_weapons_block, 20)
	{
		FIELD( _field_tag_reference, "weapon^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cheat_powerups_block, 20)
	{
		FIELD( _field_tag_reference, "powerup^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(multiplayer_color_block, k_player_color_index_count)
	{
		FIELD( _field_real_rgb_color, "color" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(visor_color_block, 32)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_real_rgb_color, "tertiary color" ),
		FIELD( _field_real_rgb_color, "quaternary color" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(globals_struct_definition)
{
		FIELD( _field_pad, "YJLTWDSL", 172 ),
		FIELD( _field_long_enum, "language", &language_enum ),
		FIELD( _field_block, "havok cleanup resources", &havok_cleanup_resources_block_block ),
		FIELD( _field_block, "sound globals", &sound_globals_block_block ),
		FIELD( _field_explanation, "AI globals" ),
		FIELD( _field_block, "DEPRECATED{ai globals}*!", &ai_globals_data_block_block ),
		FIELD( _field_tag_reference, "ai globals ref" ),
		FIELD( _field_block, "damage table", &game_globals_damage_block_block ),
		FIELD( _field_block, "sounds", &sound_block$2_block ),
		FIELD( _field_block, "camera", &camera_block_block ),
		FIELD( _field_block, "controller input", &controller_input_block_block ),
		FIELD( _field_block, "player control", &player_control_block_block ),
		FIELD( _field_block, "default player traits", &game_engine_player_traits_block_block ),
		FIELD( _field_block, "difficulty", &difficulty_block_block ),
		FIELD( _field_block, "co-op difficulty", &coop_difficulty_block_block ),
		FIELD( _field_block, "soft ceilings", &soft_ceiling_globals_block_block ),
		FIELD( _field_block, "interface tags", &interface_tag_references_block ),
		FIELD( _field_block, "@weapon list (update _weapon_list enum in game_globals.h)", &cheat_weapons_block_block ),
		FIELD( _field_block, "@cheat powerups", &cheat_powerups_block_block ),
		FIELD( _field_block, "@player information", &player_information_block_block ),
		FIELD( _field_block, "@player representation", &player_representation_block_block ),
		FIELD( _field_block, "damage{falling damage}", &damage_globals_block_block ),
		FIELD( _field_block, "shield boost", &shield_boost_block_block ),
		FIELD( _field_block, "materials", &materials_block_block ),
		FIELD( _field_block, "profile colors", &multiplayer_color_block_block ),
		FIELD( _field_block, "emblem colors", &multiplayer_color_block_block ),
		FIELD( _field_block, "visor colors", &visor_color_block_block ),
		FIELD( _field_custom, "Elite specular colors" ),
		FIELD( _field_struct, "elite specular color", &elite_specular_color_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_tag_reference, "forge globals" ),
		FIELD( _field_tag_reference, "game engine globals" ),
		FIELD( _field_tag_reference, "multiplayer globals" ),
		FIELD( _field_tag_reference, "survival_mode globals" ),
		FIELD( _field_tag_reference, "firefight globals" ),
		FIELD( _field_tag_reference, "global multiplayer object type list" ),
		FIELD( _field_tag_reference, "custom app globals" ),
		FIELD( _field_tag_reference, "grenades" ),
		FIELD( _field_tag_reference, "ordnances" ),
		FIELD( _field_tag_reference, "silent assist" ),
		FIELD( _field_block, "cinematics globals", &cinematics_globals_block_block ),
		FIELD( _field_block, "campaign metagame globals", &campaign_metagame_globals_block_block ),
		FIELD( _field_tag_reference, "game medal globals" ),
		FIELD( _field_struct, "language pack1!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack2!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack3!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack4!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack5!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack6!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack7!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack8!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack9!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack10!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack11!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack12!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack13!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack14!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack15!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack16!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack17!", &language_pack_definition_struct_definition ),
		FIELD( _field_explanation, "Rasterizer globals" ),
		FIELD( _field_tag_reference, "rasterizer_globals_ref" ),
		FIELD( _field_explanation, "Default camera fx settings" ),
		FIELD( _field_tag_reference, "default camera fx settings" ),
		FIELD( _field_explanation, "Default wind settings" ),
		FIELD( _field_tag_reference, "default wind settings" ),
		FIELD( _field_explanation, "Weather globals" ),
		FIELD( _field_tag_reference, "weather globals" ),
		FIELD( _field_explanation, "Default collision damage" ),
		FIELD( _field_tag_reference, "collision damage effect" ),
		FIELD( _field_tag_reference, "collision damage" ),
		FIELD( _field_explanation, "global material types" ),
		FIELD( _field_string_id, "global water material#the default value for what material type water is" ),
		FIELD( _field_string_id, "global air material#the default value for what material type air is" ),
		FIELD( _field_short_integer, "global water material type!" ),
		FIELD( _field_short_integer, "global air material type!" ),
		FIELD( _field_tag_reference, "effect globals" ),
		FIELD( _field_tag_reference, "havok collision filter" ),
		FIELD( _field_tag_reference, "default item grounded friction" ),
		FIELD( _field_block, "active camo", &active_camo_globals_block_block ),
		FIELD( _field_tag_reference, "incident global properties" ),
		FIELD( _field_tag_reference, "player grade globals" ),
		FIELD( _field_tag_reference, "enlistment globals" ),
		FIELD( _field_tag_reference, "player model customization globals" ),
		FIELD( _field_tag_reference, "loadout globals" ),
		FIELD( _field_tag_reference, "challenge globals" ),
		FIELD( _field_tag_reference, "game completion rewards globals" ),
		FIELD( _field_tag_reference, "game achievements" ),
		FIELD( _field_tag_reference, "game avatar awards" ),
		FIELD( _field_tag_reference, "game performance thortles default" ),
		FIELD( _field_tag_reference, "armormod globals" ),
		FIELD( _field_tag_reference, "progression globals" ),
		FIELD( _field_block, "garbage collection", &garbage_collection_block_block ),
		FIELD( _field_block, "camera impulse", &global_camera_impulse_block_block ),
		FIELD( _field_block, "runtime materials*!", &runtime_materials_block_block ),
		FIELD( _field_block, "Hologram Lighting", &hologramLightingGlobalsBlock_block ),
		FIELD( _field_tag_reference, "Narrative globals" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(patch_globals_struct_definition)
{
		FIELD( _field_struct, "language pack1!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack2!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack3!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack4!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack5!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack6!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack7!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack8!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack9!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack10!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack11!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack12!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack13!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack14!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack15!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack16!", &language_pack_definition_struct_definition ),
		FIELD( _field_struct, "language pack17!", &language_pack_definition_struct_definition ),
		FIELD( _field_terminator )
};

TAG_STRUCT(elite_specular_color_struct)
{
		FIELD( _field_real_rgb_color, "tertiary color" ),
		FIELD( _field_real_rgb_color, "quaternary color" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

