#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_gestalt_codec, SHORT_MAX)
{
	{ _field_char_enum, "sample rate*" },
	{ _field_char_enum, "encoding*" },
	{ _field_char_enum, "compression*" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_playback, SHORT_MAX)
{
	{ _field_struct, "playback!" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_scale, SHORT_MAX)
{
	{ _field_struct, "scale!" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_import_names, SHORT_MAX)
{
	{ _field_string_id, "import name^" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_pitch_range_parameters, SHORT_MAX)
{
	{ _field_short_integer, "natural pitch:cents" },
	{ _field_short_integer, "PAD" },
	{ _field_short_bounds, "bend bounds:cents#the range of pitches that will be represented using this sample." },
	{ _field_short_bounds, "max gain pitch bounds:cents" },
	{ _field_short_bounds, "playback pitch bounds:cents" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_pitch_ranges, SHORT_MAX)
{
	{ _field_short_block_index, "name^" },
	{ _field_short_block_index, "parameters" },
	{ _field_short_integer, "encoded permutation data" },
	{ _field_short_integer, "first runtime permutation flag index~" },
	{ _field_long_integer, "encoded first permutation and counts" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_permutations, k_maximum_sound_cache_file_gestalt_permutations)
{
	{ _field_short_block_index, "name^" },
	{ _field_short_integer, "encoded skip fraction" },
	{ _field_long_integer, "uncompressed sample count" },
	{ _field_long_integer, "first chunk index" },
	{ _field_short_integer, "chunk count" },
	{ _field_char_integer, "encoded gain:dB" },
	{ _field_char_integer, "permutation info index" },
	{ _field_word_integer, "first layer marker index" },
	{ _field_word_integer, "layer marker count" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_permutation_languages, k_maximum_sound_cache_file_gestalt_permutation_languages)
{
	{ _field_long_integer, "permutation index" },
	{ _field_long_integer, "english uncompressed sample count" },
	{ _field_long_integer, "english first chunk index" },
	{ _field_long_integer, "english chunk count" },
	{ _field_long_integer, "japanese uncompressed sample count" },
	{ _field_long_integer, "japanese first chunk index" },
	{ _field_long_integer, "japanese chunk count" },
	{ _field_long_integer, "german uncompressed sample count" },
	{ _field_long_integer, "german first chunk index" },
	{ _field_long_integer, "german chunk count" },
	{ _field_long_integer, "french uncompressed sample count" },
	{ _field_long_integer, "french first chunk index" },
	{ _field_long_integer, "french chunk count" },
	{ _field_long_integer, "spanish uncompressed sample count" },
	{ _field_long_integer, "spanish first chunk index" },
	{ _field_long_integer, "spanish chunk count" },
	{ _field_long_integer, "mexican_spanish uncompressed sample count" },
	{ _field_long_integer, "mexican_spanish first chunk index" },
	{ _field_long_integer, "mexican_spanish chunk count" },
	{ _field_long_integer, "italian uncompressed sample count" },
	{ _field_long_integer, "italian first chunk index" },
	{ _field_long_integer, "italian chunk count" },
	{ _field_long_integer, "korean uncompressed sample count" },
	{ _field_long_integer, "korean first chunk index" },
	{ _field_long_integer, "korean chunk count" },
	{ _field_long_integer, "traditional_chinese uncompressed sample count" },
	{ _field_long_integer, "traditional_chinese first chunk index" },
	{ _field_long_integer, "traditional_chinese chunk count" },
	{ _field_long_integer, "simplified_chinese uncompressed sample count" },
	{ _field_long_integer, "simplified_chinese first chunk index" },
	{ _field_long_integer, "simplified_chinese chunk count" },
	{ _field_long_integer, "portuguese uncompressed sample count" },
	{ _field_long_integer, "portuguese first chunk index" },
	{ _field_long_integer, "portuguese chunk count" },
	{ _field_long_integer, "polish uncompressed sample count" },
	{ _field_long_integer, "polish first chunk index" },
	{ _field_long_integer, "polish chunk count" },
	{ _field_long_integer, "russian uncompressed sample count" },
	{ _field_long_integer, "russian first chunk index" },
	{ _field_long_integer, "russian chunk count" },
	{ _field_long_integer, "danish uncompressed sample count" },
	{ _field_long_integer, "danish first chunk index" },
	{ _field_long_integer, "danish chunk count" },
	{ _field_long_integer, "finnish uncompressed sample count" },
	{ _field_long_integer, "finnish first chunk index" },
	{ _field_long_integer, "finnish chunk count" },
	{ _field_long_integer, "dutch uncompressed sample count" },
	{ _field_long_integer, "dutch first chunk index" },
	{ _field_long_integer, "dutch chunk count" },
	{ _field_long_integer, "norwegian uncompressed sample count" },
	{ _field_long_integer, "norwegian first chunk index" },
	{ _field_long_integer, "norwegian chunk count" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_custom_playback, SHORT_MAX)
{
	{ _field_struct, "playback definition" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_runtime_permutation_bit_vector, SHORT_MAX)
{
	{ _field_char_integer, "runtime permutation bit vector~!" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_promotions, 127 + 1)
{
	{ _field_struct, "runtime promotion storage~!" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_facial_animation, SHORT_MAX)
{
	{ _field_pageable, "facial animation resource" },
	{ _field_terminator },
};

TAG_BLOCK(sound_gestalt_layer_markers, SHORT_MAX)
{
	{ _field_long_integer, "sample offset" },
	{ _field_terminator },
};

TAG_GROUP(cache_file_sound, CACHE_FILE_SOUND_TAG)
{
	{ _field_word_flags, "flags" },
	{ _field_char_enum, "sound class*" },
	{ _field_char_integer, "pitch range count" },
	{ _field_short_integer, "codec index" },
	{ _field_short_integer, "first pitch range index" },
	{ _field_short_integer, "first language duration pitch range index" },
	{ _field_short_integer, "runtime gestalt index storage~" },
	{ _field_short_integer, "sub priority" },
	{ _field_short_integer, "playback index" },
	{ _field_short_integer, "scale index" },
	{ _field_char_integer, "promotion index" },
	{ _field_char_integer, "custom playback index" },
	{ _field_short_integer, "extra info index" },
	{ _field_pad, "pad", 2 },
	{ _field_long_integer, "maximum play time:ms" },
	{ _field_pageable, "sound data resource" },
	{ _field_terminator },
};

TAG_GROUP(sound_cache_file_gestalt, SOUND_CACHE_FILE_GESTALT_TAG)
{
	{ _field_block, "codecs", &sound_gestalt_codec_block },
	{ _field_block, "playbacks", &sound_gestalt_playback_block },
	{ _field_block, "scales", &sound_gestalt_scale_block },
	{ _field_block, "import names", &sound_gestalt_import_names_block },
	{ _field_block, "pitch range distances", &sound_pitch_range_distances_block },
	{ _field_block, "pitch range parameters", &sound_gestalt_pitch_range_parameters_block },
	{ _field_block, "pitch ranges", &sound_gestalt_pitch_ranges_block },
	{ _field_block, "permutations", &sound_gestalt_permutations_block },
	{ _field_block, "permutation languages", &sound_gestalt_permutation_languages_block },
	{ _field_block, "custom playbacks", &sound_gestalt_custom_playback_block },
	{ _field_block, "language durations", &sound_language_info_block },
	{ _field_block, "runtime permutation flags", &sound_gestalt_runtime_permutation_bit_vector_block },
	{ _field_data, "naive sample data" },
	{ _field_long_integer, "no one listens to me" },
	{ _field_long_integer, "but now I\'m used to it" },
	{ _field_block, "chunks", &sound_permutation_chunk_block },
	{ _field_block, "promotions", &sound_gestalt_promotions_block },
	{ _field_block, "facial animations", &sound_gestalt_facial_animation_block },
	{ _field_block, "layer markers", &sound_gestalt_layer_markers_block },
	{ _field_terminator },
};

} // namespace blofeld

