#pragma once

namespace blofeld
{



	constexpr unsigned long LOAD_SCREEN_TAG = 'ldsc';
	extern s_tag_group load_screen_group; // loadScreenBlock_block


	extern s_tag_block_definition loadScreenBlock_block;
	extern s_tag_struct_definition loadScreenBlock_block_struct_definition; // loadScreenBlock_block
	extern s_tag_block_definition vertexBlock_block;
	extern s_tag_struct_definition vertexBlock_block_struct_definition; // vertexBlock_block


	extern s_string_list_definition loadscreenFlags;

	extern s_tag_reference_definition global_loadscreen_reference;



} // namespace blofeld

