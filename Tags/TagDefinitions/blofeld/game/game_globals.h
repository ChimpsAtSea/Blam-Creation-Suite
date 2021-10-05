#pragma once

namespace blofeld
{



	constexpr unsigned long GLOBALS_TAG = 'matg';
	extern s_tag_group globals_group; // globals_block

	constexpr unsigned long PATCH_GLOBALS_TAG = 'patg';
	extern s_tag_group patch_globals_group; // patch_globals_block


	extern s_tag_block_definition globals_block;
	extern s_tag_block_definition patch_globals_block;
	extern s_tag_block_definition havok_cleanup_resources_block;
	extern s_tag_struct_definition havok_cleanup_resources_block_struct_definition; // havok_cleanup_resources_block
	extern s_tag_block_definition sound_block$2_block;
	extern s_tag_struct_definition sound_block$2_block_struct_definition; // sound_block$2_block
	extern s_tag_block_definition soft_ceiling_globals_block;
	extern s_tag_struct_definition soft_ceiling_globals_block_struct_definition; // soft_ceiling_globals_block
	extern s_tag_block_definition cheat_weapons_block;
	extern s_tag_struct_definition cheat_weapons_block_struct_definition; // cheat_weapons_block
	extern s_tag_block_definition cheat_powerups_block;
	extern s_tag_struct_definition cheat_powerups_block_struct_definition; // cheat_powerups_block
	extern s_tag_block_definition multiplayer_color_block;
	extern s_tag_struct_definition multiplayer_color_block_struct_definition; // multiplayer_color_block
	extern s_tag_block_definition visor_color_block;
	extern s_tag_struct_definition visor_color_block_struct_definition; // visor_color_block

	extern s_tag_struct_definition grenade_globals_block_struct_definition;
	extern s_tag_block_definition grenade_globals_block;

	extern s_tag_struct_definition globals_struct_definition; // tag group
	extern s_tag_struct_definition patch_globals_struct_definition; // tag group
	extern s_tag_struct_definition elite_specular_color_struct;

	extern s_string_list_definition language_enum;




} // namespace blofeld

