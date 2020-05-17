#pragma once

namespace blofeld
{

	constexpr unsigned long GAME_GLOBALS_GRENADE_LIST_TAG = 'gggl';

	extern s_tag_group game_globals_grenade_list_group;

	extern s_tag_struct_definition GameGlobalsGrenadeBlock_block_struct;
	extern s_tag_block_definition GameGlobalsGrenadeBlock_block;
	extern s_tag_block_definition game_globals_grenade_list_block_block;


	extern s_tag_struct_definition game_globals_grenade_list_struct_definition_struct_definition; // tag group

	extern const char* global_grenade_type_enum_strings[];
	extern s_string_list_definition global_grenade_type_enum;

} // namespace blofeld

