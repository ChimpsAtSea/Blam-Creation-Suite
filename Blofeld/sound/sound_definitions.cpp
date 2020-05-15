#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_globals, 1)
{
	{ _field_tag_reference, "sound classes" },
	{ _field_tag_reference, "sound effects" },
	{ _field_tag_reference, "sound mix" },
	{ _field_tag_reference, "sound combat dialogue constants" },
	{ _field_tag_reference, "sound propagation" },
	{ _field_tag_reference, "Init sound bank#Init sound bank for WWise." },
	{ _field_tag_reference, "Global sound bank#Global sound bank for WWise." },
	{ _field_tag_reference, "Extra sound bank#The other sound bank for WWise." },
	{ _field_tag_reference, "Campaign sound bank#Extra sound bank for WWise - only loaded for Campaign." },
	{ _field_tag_reference, "Multiplayer sound bank#Extra sound bank for WWise - only loaded for MP - PVP." },
	{ _field_block, "Streaming pack files", &StreamingPackBlock_block },
	{ _field_block, "un-spatialized campaign sounds", &campaign_unspatialized_sounds_block },
	{ _field_terminator },
};

TAG_BLOCK(StreamingPackBlock, k_maximum_streaming_packs)
{
	{ _field_long_flags, "flags" },
	{ _field_string, "Streaming pck file#Name of the stream pack file" },
	{ _field_terminator },
};

TAG_BLOCK(campaign_unspatialized_sounds, k_maximum_campaign_unspatialized_sounds)
{
	{ _field_tag_reference, "sound^" },
	{ _field_terminator },
};

TAG_BLOCK(SoundBankBlock, k_maximumSoundBanksPerTag)
{
	{ _field_string_id, "Sound bank name#Name of the main sound bank." },
	{ _field_terminator },
};

TAG_BLOCK(soundLipSyncInfoBlock, 1)
{
	{ _field_long_integer, "number of usable facial animations" },
	{ _field_block, "deterministic event info", &deterministicSpeechEventBlock_block },
	{ _field_block, "facial animation resource languages", &facial_animation_language_block },
	{ _field_terminator },
};

TAG_BLOCK(deterministicSpeechEventBlock, MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE)
{
	{ _field_long_flags, "flags" },
	{ _field_string_id, "voice file path" },
	{ _field_real, "event duration" },
	{ _field_real, "skip fraction#Percent this file will be skipped when picked. 0 is always, 0.99 is almost never" },
	{ _field_terminator },
};

TAG_BLOCK(facial_animation_language, k_language_count)
{
	{ _field_pageable, "facial animation resource" },
	{ _field_long_enum, "language" },
	{ _field_terminator },
};

TAG_BLOCK(sound_pitch_range, MAXIMUM_PITCH_RANGES_PER_SOUND)
{
	{ _field_string_id, "name*#the name of the imported pitch range directory" },
	{ _field_explanation, "pitch control" },
	{ _field_short_integer, "natural pitch:cents#the apparent pitch when these samples are played at their recorded pitch." },
	{ _field_pad, "KCTSDWPP~", 2 },
	{ _field_short_bounds, "bend bounds:cents#the range of pitches that will be represented using this sample." },
	{ _field_short_bounds, "full volume bounds!:cents#the range of pitches that map to full gain." },
	{ _field_short_bounds, "playback bend bounds:cents#the actual pitch will be clamped to this" },
	{ _field_struct, "distance parameters" },
	{ _field_pad, "YAMTVB~", 4 },
	{ _field_char_integer, "runtime usable permutation count!" },
	{ _field_byte_flags, "xsync flags!" },
	{ _field_pad, "asdf", 2 },
	{ _field_block, "permutations*#permutations represent equivalent variations of this sound.", &sound_permutations_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_permutations, MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE)
{
	{ _field_custom },
	{ _field_string_id, "name*^#name of the file from which this sample was imported" },
	{ _field_custom },
	{ _field_real_fraction, "skip fraction#fraction of requests to play this permutation that are ignored (a different permutation is selected.)" },
	{ _field_custom },
	{ _field_real, "gain:dB#additional attenuation when played" },
	{ _field_custom_short_block_index, "raw info!" },
	{ _field_short_block_index, "play fraction type!" },
	{ _field_short_bounds, "mission range#first and last mission ids this permutation can play in (zero values are ignored)" },
	{ _field_word_flags, "permutation flags" },
	{ _field_word_flags, "flags!*" },
	{ _field_block, "languages!", &sound_permutation_languages_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_permutation_languages, k_language_count)
{
	{ _field_long_integer, "uncompressed sample count" },
	{ _field_block, "chunks", &sound_permutation_chunk_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_permutation_chunk, UNSIGNED_SHORT_MAX*4)
{
	{ _field_long_integer, "file offset*" },
	{ _field_long_integer, "encoded size and flags~!" },
	{ _field_long_block_index, "cache index~!" },
	{ _field_long_integer, "xma2_source_buffer_sample_start*" },
	{ _field_long_integer, "xma2_source_buffer_sample_end*" },
	{ _field_terminator },
};

TAG_BLOCK(sound_platform_sound_playback, 1)
{
	{ _field_struct, "playback definition" },
	{ _field_terminator },
};

TAG_BLOCK(sound_extra_info, 1)
{
	{ _field_block, "language permutation info", &sound_definition_language_permutation_info_block },
	{ _field_block, "facial animation resource languages", &facial_animation_language_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_definition_language_permutation_info, MAXIMUM_PITCH_RANGES_PER_SOUND*MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE*2)
{
	{ _field_block, "raw info block", &sound_permutation_raw_info_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_permutation_raw_info, 2*k_language_count)
{
	{ _field_string_id, "skip fraction name" },
	{ _field_data, "samples!#sampled sound data" },
	{ _field_block, "markers!", &sound_permutation_marker_block },
	{ _field_block, "layer markers!", &sound_permutation_marker_block },
	{ _field_block, "xma2 seek table!", &sound_xma2_seek_table_block },
	{ _field_enum, "compression*" },
	{ _field_char_enum, "language*" },
	{ _field_pad, "ZHDGBHWS", 1 },
	{ _field_long_integer, "sample count!" },
	{ _field_long_integer, "resource sample offset!" },
	{ _field_long_integer, "resource sample size!" },
	{ _field_terminator },
};

TAG_BLOCK(sound_permutation_marker, MAXIMUM_MARKERS_PER_PERMUTATION)
{
	{ _field_long_integer, "marker id*" },
	{ _field_string_id, "name^*" },
	{ _field_long_integer, "sample offset*" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(sound_xma2_seek_table, MAXIMUM_SOUND_DATA_SIZE/k_kilo)
{
	{ _field_long_integer, "block relative sample start*" },
	{ _field_long_integer, "block relative sample end" },
	{ _field_long_integer, "starting sample index*" },
	{ _field_long_integer, "ending sample index*" },
	{ _field_long_integer, "starting xma2 offset*" },
	{ _field_long_integer, "ending xma2 offset*" },
	{ _field_terminator },
};

TAG_BLOCK(sound_pitch_range_distances, SHORT_MAX)
{
	{ _field_explanation, "attenuation distances" },
	{ _field_real, "don\'t obstruct distance:world units#don\'t obstruct below this distance" },
	{ _field_real, "don\'t play distance:world units#don\'t play below this distance" },
	{ _field_real, "attack distance:world units#start playing at full volume at this distance" },
	{ _field_real, "minimum distance:world units#start attenuating at this distance" },
	{ _field_real, "sustain begin distance:world units#set attenuation to sustain db at this distance" },
	{ _field_real, "sustain end distance:world units#continue attenuating to silence at this distance" },
	{ _field_real, "maximum distance:world units#the distance beyond which this sound is no longer audible" },
	{ _field_real, "sustain db:dB#the amount of attenuation between sustain begin and end" },
	{ _field_terminator },
};

TAG_GROUP(soundbank, SOUNDBANK_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_long_flags, "import flags!" },
	{ _field_long_flags, "xsync flags!" },
	{ _field_block, "Sound bank list#List of names of soundbanks. If more than one, one will be randomly chosen at load", &SoundBankBlock_block },
	{ _field_long_integer, "Bank priority#the importance of this bank over others. 1 is highest priority (ie will bump all others)" },
	{ _field_long_integer, "Bank unique ID" },
	{ _field_terminator },
};

TAG_GROUP(sound_global_propagation, SOUND_GLOBAL_PROPAGATION_TAG)
{
	{ _field_explanation, "underwater propagation globals" },
	{ _field_struct, "underwater propagation" },
	{ _field_terminator },
};

TAG_GROUP(sound, SOUND_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_long_flags, "import flags!" },
	{ _field_long_flags, "xsync flags!" },
	{ _field_string_id, "Event Name#Sound event name." },
	{ _field_string_id, "Player Event Name#Optional sound event name for player only." },
	{ _field_string_id, "Fallback Event Name#Fallback sound event if the others don\'t play - should be an a guaranteed bank." },
	{ _field_real, "Max Radius" },
	{ _field_real, "Max Duration#Max duration of this event. Enter manually for now - will auto-fill later." },
	{ _field_real, "Don\'t play time.#Time the event will not retrigger for (global)" },
	{ _field_long_integer, "Hidden runtime info index!" },
	{ _field_tag_reference, "Sound bank#Reference to the sound bank tag this event is in. Can be empty." },
	{ _field_block, "lipsync info", &soundLipSyncInfoBlock_block },
	{ _field_long_integer, "deterministic flag index" },
	{ _field_terminator },
};

TAG_GROUP(sound_old, SOUND_OLD_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_long_flags, "import flags!" },
	{ _field_long_flags, "xsync flags!" },
	{ _field_char_enum, "class" },
	{ _field_char_enum, "sample rate*" },
	{ _field_char_integer, "override xma compression:[1-100]" },
	{ _field_char_enum, "import type*" },
	{ _field_struct, "playback" },
	{ _field_struct, "scale" },
	{ _field_explanation, "sub priority" },
	{ _field_real, "sub priority" },
	{ _field_explanation, "import properties" },
	{ _field_char_enum, "encoding*" },
	{ _field_char_enum, "compression*" },
	{ _field_pad, "pad", 2 },
	{ _field_struct, "promotion" },
	{ _field_pad, "runtime pad~", 4 },
	{ _field_block, "pitch ranges*#pitch ranges allow multiple samples to represent the same sound at different pitches", &sound_pitch_range_block },
	{ _field_block, "platform parameters", &sound_platform_sound_playback_block },
	{ _field_pageable, "sound data resource" },
	{ _field_block, "extra info!", &sound_extra_info_block },
	{ _field_block, "language info!", &sound_language_info_block },
	{ _field_terminator },
};

TAG_GROUP(sound2, SOUND2_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_long_flags, "import flags!" },
	{ _field_long_flags, "xsync flags!" },
	{ _field_char_enum, "class" },
	{ _field_char_enum, "sample rate*" },
	{ _field_char_integer, "override xma compression:[1-100]" },
	{ _field_char_enum, "import type*" },
	{ _field_struct, "playback" },
	{ _field_struct, "scale" },
	{ _field_explanation, "sub priority" },
	{ _field_real, "sub priority" },
	{ _field_explanation, "import properties" },
	{ _field_char_enum, "encoding*" },
	{ _field_char_enum, "compression*" },
	{ _field_pad, "pad", 2 },
	{ _field_struct, "promotion" },
	{ _field_pad, "runtime pad~", 4 },
	{ _field_block, "pitch ranges*#pitch ranges allow multiple samples to represent the same sound at different pitches", &sound_pitch_range_block },
	{ _field_block, "platform parameters", &sound_platform_sound_playback_block },
	{ _field_pageable, "sound data resource" },
	{ _field_block, "extra info!", &sound_extra_info_block },
	{ _field_block, "language info!", &sound_language_info_block },
	{ _field_terminator },
};

TAG_GROUP(sound_mix, SOUND_MIX_TAG)
{
	{ _field_struct, "default transmission settings" },
	{ _field_explanation, "first person left side mix" },
	{ _field_struct, "first person left side mix" },
	{ _field_explanation, "first person middle mix" },
	{ _field_struct, "first person middle mix" },
	{ _field_explanation, "first person right side mix" },
	{ _field_struct, "first person right side mix" },
	{ _field_explanation, "first person surround mix" },
	{ _field_struct, "first person surround mix" },
	{ _field_explanation, "ambient surround mix" },
	{ _field_struct, "ambient surround mix" },
	{ _field_explanation, "global mix" },
	{ _field_struct, "global mix" },
	{ _field_terminator },
};

TAG_GROUP(sound_dialogue_constants, SOUND_DIALOGUE_CONSTANTS_TAG)
{
	{ _field_explanation, "named playing fractions" },
	{ _field_real, "almost never" },
	{ _field_real, "rarely" },
	{ _field_real, "somewhat" },
	{ _field_real, "often" },
	{ _field_pad, "VBEZIIDOF", 24 },
	{ _field_terminator },
};

} // namespace blofeld

