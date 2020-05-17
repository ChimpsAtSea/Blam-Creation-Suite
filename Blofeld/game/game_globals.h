#pragma once

namespace blofeld
{

	extern const char* language_enum_strings[];
	extern s_string_list_definition language_enum;

	constexpr unsigned long GLOBALS_TAG = 'matg';

	extern s_tag_group globals_group;
	constexpr unsigned long PATCH_GLOBALS_TAG = 'patg';

	extern s_tag_group patch_globals_group;

	extern s_tag_block_definition globals_block_block;
	extern s_tag_block_definition patch_globals_block_block;
	extern s_tag_struct havok_cleanup_resources_block_block_struct;
	extern s_tag_block_definition havok_cleanup_resources_block_block;
	extern s_tag_struct sound_block$2_block_struct;
	extern s_tag_block_definition sound_block$2_block;
	extern s_tag_struct soft_ceiling_globals_block_block_struct;
	extern s_tag_block_definition soft_ceiling_globals_block_block;
	extern s_tag_struct cheat_weapons_block_block_struct;
	extern s_tag_block_definition cheat_weapons_block_block;
	extern s_tag_struct cheat_powerups_block_block_struct;
	extern s_tag_block_definition cheat_powerups_block_block;
	extern s_tag_struct multiplayer_color_block_block_struct;
	extern s_tag_block_definition multiplayer_color_block_block;
	extern s_tag_struct visor_color_block_block_struct;
	extern s_tag_block_definition visor_color_block_block;

	extern s_tag_struct globals_struct_definition_struct_definition; // tag group
	extern s_tag_struct patch_globals_struct_definition_struct_definition; // tag group
	extern s_tag_struct elite_specular_color_struct_struct_definition;

} // namespace blofeld

