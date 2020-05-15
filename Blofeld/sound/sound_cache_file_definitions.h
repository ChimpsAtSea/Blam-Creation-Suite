#pragma once

namespace blofeld
{

extern s_tag_block sound_gestalt_codec_block;
extern s_tag_block sound_gestalt_playback_block;
extern s_tag_block sound_gestalt_scale_block;
extern s_tag_block sound_gestalt_import_names_block;
extern s_tag_block sound_gestalt_pitch_range_parameters_block;
extern s_tag_block sound_gestalt_pitch_ranges_block;
extern s_tag_block sound_gestalt_permutations_block;
extern s_tag_block sound_gestalt_permutation_languages_block;
extern s_tag_block sound_gestalt_custom_playback_block;
extern s_tag_block sound_gestalt_runtime_permutation_bit_vector_block;
extern s_tag_block sound_gestalt_promotions_block;
extern s_tag_block sound_gestalt_facial_animation_block;
extern s_tag_block sound_gestalt_layer_markers_block;

constexpr unsigned long CACHE_FILE_SOUND_TAG = '$#!+';

extern s_tag_block cache_file_sound_block;
extern s_tag_group cache_file_sound_group;
constexpr unsigned long SOUND_CACHE_FILE_GESTALT_TAG = 'ugh!';

extern s_tag_block sound_cache_file_gestalt_block;
extern s_tag_group sound_cache_file_gestalt_group;
} // namespace blofeld

