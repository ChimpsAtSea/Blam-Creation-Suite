#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_globals, 1)
{
	FIELD( _field_tag_reference, "sound classes" ),
	FIELD( _field_tag_reference, "sound effects" ),
	FIELD( _field_tag_reference, "sound mix" ),
	FIELD( _field_tag_reference, "sound combat dialogue constants" ),
	FIELD( _field_tag_reference, "sound propagation" ),
	FIELD( _field_tag_reference, "Init sound bank#Init sound bank for WWise." ),
	FIELD( _field_tag_reference, "Global sound bank#Global sound bank for WWise." ),
	FIELD( _field_tag_reference, "Extra sound bank#The other sound bank for WWise." ),
	FIELD( _field_tag_reference, "Campaign sound bank#Extra sound bank for WWise - only loaded for Campaign." ),
	FIELD( _field_tag_reference, "Multiplayer sound bank#Extra sound bank for WWise - only loaded for MP - PVP." ),
	FIELD( _field_block, "Streaming pack files", &StreamingPackBlock_block ),
	FIELD( _field_block, "un-spatialized campaign sounds", &campaign_unspatialized_sounds_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(StreamingPackBlock, k_maximum_streaming_packs)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string, "Streaming pck file#Name of the stream pack file" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_unspatialized_sounds, k_maximum_campaign_unspatialized_sounds)
{
	FIELD( _field_tag_reference, "sound^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(SoundBankBlock, k_maximumSoundBanksPerTag)
{
	FIELD( _field_string_id, "Sound bank name#Name of the main sound bank." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(soundLipSyncInfoBlock, 1)
{
	FIELD( _field_long_integer, "number of usable facial animations" ),
	FIELD( _field_block, "deterministic event info", &deterministicSpeechEventBlock_block ),
	FIELD( _field_block, "facial animation resource languages", &facial_animation_language_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(deterministicSpeechEventBlock, MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "voice file path" ),
	FIELD( _field_real, "event duration" ),
	FIELD( _field_real, "skip fraction#Percent this file will be skipped when picked. 0 is always, 0.99 is almost never" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(facial_animation_language, k_language_count)
{
	FIELD( _field_pageable, "facial animation resource" ),
	FIELD( _field_long_enum, "language" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_pitch_range, MAXIMUM_PITCH_RANGES_PER_SOUND)
{
	FIELD( _field_string_id, "name*#the name of the imported pitch range directory" ),
	FIELD( _field_explanation, "pitch control" ),
	FIELD( _field_short_integer, "natural pitch:cents#the apparent pitch when these samples are played at their recorded pitch." ),
	FIELD( _field_pad, "KCTSDWPP~", 2 ),
	FIELD( _field_short_bounds, "bend bounds:cents#the range of pitches that will be represented using this sample." ),
	FIELD( _field_short_bounds, "full volume bounds!:cents#the range of pitches that map to full gain." ),
	FIELD( _field_short_bounds, "playback bend bounds:cents#the actual pitch will be clamped to this" ),
	FIELD( _field_struct, "distance parameters" ),
	FIELD( _field_pad, "YAMTVB~", 4 ),
	FIELD( _field_char_integer, "runtime usable permutation count!" ),
	FIELD( _field_byte_flags, "xsync flags!" ),
	FIELD( _field_pad, "asdf", 2 ),
	FIELD( _field_block, "permutations*#permutations represent equivalent variations of this sound.", &sound_permutations_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutations, MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "name*^#name of the file from which this sample was imported" ),
	FIELD( _field_custom ),
	FIELD( _field_real_fraction, "skip fraction#fraction of requests to play this permutation that are ignored (a different permutation is selected.)" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "gain:dB#additional attenuation when played" ),
	FIELD( _field_custom_short_block_index, "raw info!" ),
	FIELD( _field_short_block_index, "play fraction type!" ),
	FIELD( _field_short_bounds, "mission range#first and last mission ids this permutation can play in (zero values are ignored)" ),
	FIELD( _field_word_flags, "permutation flags" ),
	FIELD( _field_word_flags, "flags!*" ),
	FIELD( _field_block, "languages!", &sound_permutation_languages_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutation_languages, k_language_count)
{
	FIELD( _field_long_integer, "uncompressed sample count" ),
	FIELD( _field_block, "chunks", &sound_permutation_chunk_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutation_chunk, UNSIGNED_SHORT_MAX*4)
{
	FIELD( _field_long_integer, "file offset*" ),
	FIELD( _field_long_integer, "encoded size and flags~!" ),
	FIELD( _field_long_block_index, "cache index~!" ),
	FIELD( _field_long_integer, "xma2_source_buffer_sample_start*" ),
	FIELD( _field_long_integer, "xma2_source_buffer_sample_end*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_platform_sound_playback, 1)
{
	FIELD( _field_struct, "playback definition" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_extra_info, 1)
{
	FIELD( _field_block, "language permutation info", &sound_definition_language_permutation_info_block ),
	FIELD( _field_block, "facial animation resource languages", &facial_animation_language_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_definition_language_permutation_info, MAXIMUM_PITCH_RANGES_PER_SOUND*MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE*2)
{
	FIELD( _field_block, "raw info block", &sound_permutation_raw_info_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutation_raw_info, 2*k_language_count)
{
	FIELD( _field_string_id, "skip fraction name" ),
	FIELD( _field_data, "samples!#sampled sound data" ),
	FIELD( _field_block, "markers!", &sound_permutation_marker_block ),
	FIELD( _field_block, "layer markers!", &sound_permutation_marker_block ),
	FIELD( _field_block, "xma2 seek table!", &sound_xma2_seek_table_block ),
	FIELD( _field_enum, "compression*" ),
	FIELD( _field_char_enum, "language*" ),
	FIELD( _field_pad, "ZHDGBHWS", 1 ),
	FIELD( _field_long_integer, "sample count!" ),
	FIELD( _field_long_integer, "resource sample offset!" ),
	FIELD( _field_long_integer, "resource sample size!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutation_marker, MAXIMUM_MARKERS_PER_PERMUTATION)
{
	FIELD( _field_long_integer, "marker id*" ),
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_long_integer, "sample offset*" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_xma2_seek_table, MAXIMUM_SOUND_DATA_SIZE/k_kilo)
{
	FIELD( _field_long_integer, "block relative sample start*" ),
	FIELD( _field_long_integer, "block relative sample end" ),
	FIELD( _field_long_integer, "starting sample index*" ),
	FIELD( _field_long_integer, "ending sample index*" ),
	FIELD( _field_long_integer, "starting xma2 offset*" ),
	FIELD( _field_long_integer, "ending xma2 offset*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_pitch_range_distances, SHORT_MAX)
{
	FIELD( _field_explanation, "attenuation distances" ),
	FIELD( _field_real, "don\'t obstruct distance:world units#don\'t obstruct below this distance" ),
	FIELD( _field_real, "don\'t play distance:world units#don\'t play below this distance" ),
	FIELD( _field_real, "attack distance:world units#start playing at full volume at this distance" ),
	FIELD( _field_real, "minimum distance:world units#start attenuating at this distance" ),
	FIELD( _field_real, "sustain begin distance:world units#set attenuation to sustain db at this distance" ),
	FIELD( _field_real, "sustain end distance:world units#continue attenuating to silence at this distance" ),
	FIELD( _field_real, "maximum distance:world units#the distance beyond which this sound is no longer audible" ),
	FIELD( _field_real, "sustain db:dB#the amount of attenuation between sustain begin and end" ),
	FIELD( _field_terminator )
};

TAG_GROUP(soundbank, SOUNDBANK_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "import flags!" ),
	FIELD( _field_long_flags, "xsync flags!" ),
	FIELD( _field_block, "Sound bank list#List of names of soundbanks. If more than one, one will be randomly chosen at load", &SoundBankBlock_block ),
	FIELD( _field_long_integer, "Bank priority#the importance of this bank over others. 1 is highest priority (ie will bump all others)" ),
	FIELD( _field_long_integer, "Bank unique ID" ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound_global_propagation, SOUND_GLOBAL_PROPAGATION_TAG)
{
	FIELD( _field_explanation, "underwater propagation globals" ),
	FIELD( _field_struct, "underwater propagation" ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound, SOUND_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "import flags!" ),
	FIELD( _field_long_flags, "xsync flags!" ),
	FIELD( _field_string_id, "Event Name#Sound event name." ),
	FIELD( _field_string_id, "Player Event Name#Optional sound event name for player only." ),
	FIELD( _field_string_id, "Fallback Event Name#Fallback sound event if the others don\'t play - should be an a guaranteed bank." ),
	FIELD( _field_real, "Max Radius" ),
	FIELD( _field_real, "Max Duration#Max duration of this event. Enter manually for now - will auto-fill later." ),
	FIELD( _field_real, "Don\'t play time.#Time the event will not retrigger for (global)" ),
	FIELD( _field_long_integer, "Hidden runtime info index!" ),
	FIELD( _field_tag_reference, "Sound bank#Reference to the sound bank tag this event is in. Can be empty." ),
	FIELD( _field_block, "lipsync info", &soundLipSyncInfoBlock_block ),
	FIELD( _field_long_integer, "deterministic flag index" ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound_old, SOUND_OLD_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "import flags!" ),
	FIELD( _field_long_flags, "xsync flags!" ),
	FIELD( _field_char_enum, "class" ),
	FIELD( _field_char_enum, "sample rate*" ),
	FIELD( _field_char_integer, "override xma compression:[1-100]" ),
	FIELD( _field_char_enum, "import type*" ),
	FIELD( _field_struct, "playback" ),
	FIELD( _field_struct, "scale" ),
	FIELD( _field_explanation, "sub priority" ),
	FIELD( _field_real, "sub priority" ),
	FIELD( _field_explanation, "import properties" ),
	FIELD( _field_char_enum, "encoding*" ),
	FIELD( _field_char_enum, "compression*" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_struct, "promotion" ),
	FIELD( _field_pad, "runtime pad~", 4 ),
	FIELD( _field_block, "pitch ranges*#pitch ranges allow multiple samples to represent the same sound at different pitches", &sound_pitch_range_block ),
	FIELD( _field_block, "platform parameters", &sound_platform_sound_playback_block ),
	FIELD( _field_pageable, "sound data resource" ),
	FIELD( _field_block, "extra info!", &sound_extra_info_block ),
	FIELD( _field_block, "language info!", &sound_language_info_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound2, SOUND2_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "import flags!" ),
	FIELD( _field_long_flags, "xsync flags!" ),
	FIELD( _field_char_enum, "class" ),
	FIELD( _field_char_enum, "sample rate*" ),
	FIELD( _field_char_integer, "override xma compression:[1-100]" ),
	FIELD( _field_char_enum, "import type*" ),
	FIELD( _field_struct, "playback" ),
	FIELD( _field_struct, "scale" ),
	FIELD( _field_explanation, "sub priority" ),
	FIELD( _field_real, "sub priority" ),
	FIELD( _field_explanation, "import properties" ),
	FIELD( _field_char_enum, "encoding*" ),
	FIELD( _field_char_enum, "compression*" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_struct, "promotion" ),
	FIELD( _field_pad, "runtime pad~", 4 ),
	FIELD( _field_block, "pitch ranges*#pitch ranges allow multiple samples to represent the same sound at different pitches", &sound_pitch_range_block ),
	FIELD( _field_block, "platform parameters", &sound_platform_sound_playback_block ),
	FIELD( _field_pageable, "sound data resource" ),
	FIELD( _field_block, "extra info!", &sound_extra_info_block ),
	FIELD( _field_block, "language info!", &sound_language_info_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound_mix, SOUND_MIX_TAG)
{
	FIELD( _field_struct, "default transmission settings" ),
	FIELD( _field_explanation, "first person left side mix" ),
	FIELD( _field_struct, "first person left side mix" ),
	FIELD( _field_explanation, "first person middle mix" ),
	FIELD( _field_struct, "first person middle mix" ),
	FIELD( _field_explanation, "first person right side mix" ),
	FIELD( _field_struct, "first person right side mix" ),
	FIELD( _field_explanation, "first person surround mix" ),
	FIELD( _field_struct, "first person surround mix" ),
	FIELD( _field_explanation, "ambient surround mix" ),
	FIELD( _field_struct, "ambient surround mix" ),
	FIELD( _field_explanation, "global mix" ),
	FIELD( _field_struct, "global mix" ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound_dialogue_constants, SOUND_DIALOGUE_CONSTANTS_TAG)
{
	FIELD( _field_explanation, "named playing fractions" ),
	FIELD( _field_real, "almost never" ),
	FIELD( _field_real, "rarely" ),
	FIELD( _field_real, "somewhat" ),
	FIELD( _field_real, "often" ),
	FIELD( _field_pad, "VBEZIIDOF", 24 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

