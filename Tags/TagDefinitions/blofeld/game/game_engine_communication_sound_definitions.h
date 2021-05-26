#pragma once

namespace blofeld
{



	constexpr unsigned long COMMUNICATION_SOUNDS_TAG = 'coms';
	extern s_tag_group communication_sounds_group; // communication_sounds_block


	extern s_tag_block_definition communication_sounds_block;

	extern s_tag_struct_definition communication_sounds_struct_definition; // tag group

	extern s_tag_reference_definition global_sound_reference;
	extern s_tag_reference_definition global_sound_and_looping_sound_reference;
	extern s_tag_reference_definition global_soundbank_reference;
	extern s_tag_reference_definition global_looping_sound_reference;
	extern s_tag_reference_definition global_force_sound_only_reference;
	extern s_tag_reference_definition global_sound_effect_collection_reference;
	extern s_tag_reference_definition global_communication_sound_group_reference;



} // namespace blofeld

