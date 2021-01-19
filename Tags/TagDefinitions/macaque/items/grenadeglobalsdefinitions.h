#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long GAME_GLOBALS_GRENADE_LIST_TAG = 'gggl';
	extern s_tag_group game_globals_grenade_list_group; // game_globals_grenade_list_block


	extern s_tag_block_definition game_globals_grenade_list_block;
	extern s_tag_block_definition GameGlobalsGrenadeBlock_block;
	extern s_tag_struct_definition GameGlobalsGrenadeBlock_block_struct_definition; // GameGlobalsGrenadeBlock_block

	extern s_tag_struct_definition game_globals_grenade_list_struct_definition; // tag group

	extern c_versioned_string_list global_grenade_type_enum_strings;
	extern s_string_list_definition global_grenade_type_enum;


} // namespace macaque

} // namespace blofeld

