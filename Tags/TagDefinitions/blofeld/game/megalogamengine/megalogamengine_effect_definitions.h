#pragma once

namespace blofeld
{



	constexpr unsigned long MULTIPLAYEREFFECTS_TAG = 'mgee';
	extern s_tag_group multiplayerEffects_group; // multiplayerEffects_block


	extern s_tag_block_definition multiplayerEffects_block;
	extern s_tag_block_definition multiplayerEffectsBlock_block;
	extern s_tag_struct_definition multiplayerEffectsBlock_block_struct_definition; // multiplayerEffectsBlock_block

	extern s_tag_struct_definition multiplayerEffects_struct_definition; // tag group

	extern s_tag_reference_definition global_multiplayer_effect_group_reference;



} // namespace blofeld

