#pragma once

namespace blofeld
{



	constexpr unsigned long LOADOUT_GLOBALS_DEFINITION_TAG = 'lgtd';
	extern s_tag_group loadout_globals_definition_group; // loadout_globals_definition_block


	extern s_tag_block_definition loadout_globals_definition_block;
	extern s_tag_block_definition game_engine_loadout_options_block;
	extern s_tag_struct_definition game_engine_loadout_options_block_struct_definition; // game_engine_loadout_options_block
	extern s_tag_block_definition game_engine_loadout_palette_entry_block;
	extern s_tag_struct_definition game_engine_loadout_palette_entry_block_struct_definition; // game_engine_loadout_palette_entry_block
	extern s_tag_block_definition loadout_definition_block;
	extern s_tag_block_definition loadout_palette_definition_block;
	extern s_tag_struct_definition loadout_palette_definition_block_struct_definition; // loadout_palette_definition_block
	extern s_tag_block_definition loadout_index_block;
	extern s_tag_struct_definition loadout_index_block_struct_definition; // loadout_index_block
	extern s_tag_block_definition loadout_name_block;
	extern s_tag_struct_definition loadout_name_block_struct_definition; // loadout_name_block
	extern s_tag_block_definition custom_loadout_defaults_block;

	extern s_tag_struct_definition loadout_globals_definition_struct_definition; // tag group
	extern s_tag_struct_definition loadout_definition_struct;

	extern s_string_list_definition loadout_flags_definition;

	extern s_tag_reference_definition global_loadout_globals_reference;



} // namespace blofeld

