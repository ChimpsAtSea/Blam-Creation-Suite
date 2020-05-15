#pragma once

namespace blofeld
{

extern s_tag_block sound_globals_block;
extern s_tag_block StreamingPackBlock_block;
extern s_tag_block campaign_unspatialized_sounds_block;
extern s_tag_block SoundBankBlock_block;
extern s_tag_block soundLipSyncInfoBlock_block;
extern s_tag_block deterministicSpeechEventBlock_block;
extern s_tag_block facial_animation_language_block;
extern s_tag_block sound_pitch_range_block;
extern s_tag_block sound_permutations_block;
extern s_tag_block sound_permutation_languages_block;
extern s_tag_block sound_permutation_chunk_block;
extern s_tag_block sound_platform_sound_playback_block;
extern s_tag_block sound_extra_info_block;
extern s_tag_block sound_definition_language_permutation_info_block;
extern s_tag_block sound_permutation_raw_info_block;
extern s_tag_block sound_permutation_marker_block;
extern s_tag_block sound_xma2_seek_table_block;
extern s_tag_block sound_pitch_range_distances_block;

constexpr unsigned long SOUNDBANK_TAG = 'sbnk';

extern s_tag_block soundbank_block;
extern s_tag_group soundbank_group;
constexpr unsigned long SOUND_GLOBAL_PROPAGATION_TAG = 'sgp!';

extern s_tag_block sound_global_propagation_block;
extern s_tag_group sound_global_propagation_group;
constexpr unsigned long SOUND_TAG = 'snd!';

extern s_tag_block sound_block;
extern s_tag_group sound_group;
constexpr unsigned long SOUND_OLD_TAG = 'sndo';

extern s_tag_block sound_old_block;
extern s_tag_group sound_old_group;
constexpr unsigned long SOUND2_TAG = 'sndx';

extern s_tag_block sound2_block;
extern s_tag_group sound2_group;
constexpr unsigned long SOUND_MIX_TAG = 'snmx';

extern s_tag_block sound_mix_block;
extern s_tag_group sound_mix_group;
constexpr unsigned long SOUND_DIALOGUE_CONSTANTS_TAG = 'spk!';

extern s_tag_block sound_dialogue_constants_block;
extern s_tag_group sound_dialogue_constants_group;
} // namespace blofeld

