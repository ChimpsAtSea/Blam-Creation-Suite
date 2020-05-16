#include <blofeld-private-pch.h>

namespace blofeld
{

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
	FIELD( _field_struct, "underwater propagation", &sound_propagation_definition_struct_struct_definition ),
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
	FIELD( _field_struct, "playback", &sound_playback_parameters_struct_struct_definition ),
	FIELD( _field_struct, "scale", &sound_scale_modifiers_struct_struct_definition ),
	FIELD( _field_explanation, "sub priority" ),
	FIELD( _field_real, "sub priority" ),
	FIELD( _field_explanation, "import properties" ),
	FIELD( _field_char_enum, "encoding*" ),
	FIELD( _field_char_enum, "compression*" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_struct, "promotion", &sound_promotion_parameters_struct_struct_definition ),
	FIELD( _field_pad, "runtime pad~", 4 ),
	FIELD( _field_block, "pitch ranges*#pitch ranges allow multiple samples to represent the same sound at different pitches", &sound_pitch_range_block_block ),
	FIELD( _field_block, "platform parameters", &sound_platform_sound_playback_block_block ),
	FIELD( _field_pageable, "sound data resource" ),
	FIELD( _field_block, "extra info!", &sound_extra_info_block_block ),
	FIELD( _field_block, "language info!", &sound_language_info_block_block ),
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
	FIELD( _field_struct, "playback", &sound_playback_parameters_struct_struct_definition ),
	FIELD( _field_struct, "scale", &sound_scale_modifiers_struct_struct_definition ),
	FIELD( _field_explanation, "sub priority" ),
	FIELD( _field_real, "sub priority" ),
	FIELD( _field_explanation, "import properties" ),
	FIELD( _field_char_enum, "encoding*" ),
	FIELD( _field_char_enum, "compression*" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_struct, "promotion", &sound_promotion_parameters_struct_struct_definition ),
	FIELD( _field_pad, "runtime pad~", 4 ),
	FIELD( _field_block, "pitch ranges*#pitch ranges allow multiple samples to represent the same sound at different pitches", &sound_pitch_range_block_block ),
	FIELD( _field_block, "platform parameters", &sound_platform_sound_playback_block_block ),
	FIELD( _field_pageable, "sound data resource" ),
	FIELD( _field_block, "extra info!", &sound_extra_info_block_block ),
	FIELD( _field_block, "language info!", &sound_language_info_block_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound_mix, SOUND_MIX_TAG)
{
	FIELD( _field_struct, "default transmission settings", &sound_transmission_definition_struct_struct_definition ),
	FIELD( _field_explanation, "first person left side mix" ),
	FIELD( _field_struct, "first person left side mix", &sound_stereo_mix_struct_struct_definition ),
	FIELD( _field_explanation, "first person middle mix" ),
	FIELD( _field_struct, "first person middle mix", &sound_stereo_mix_struct_struct_definition ),
	FIELD( _field_explanation, "first person right side mix" ),
	FIELD( _field_struct, "first person right side mix", &sound_stereo_mix_struct_struct_definition ),
	FIELD( _field_explanation, "first person surround mix" ),
	FIELD( _field_struct, "first person surround mix", &sound_surround_mix_struct_struct_definition ),
	FIELD( _field_explanation, "ambient surround mix" ),
	FIELD( _field_struct, "ambient surround mix", &sound_surround_mix_struct_struct_definition ),
	FIELD( _field_explanation, "global mix" ),
	FIELD( _field_struct, "global mix", &sound_global_mix_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP_FROM_BLOCK(sound_dialogue_constants, SOUND_DIALOGUE_CONSTANTS_TAG, sound_dialogue_constants_block_block );

TAG_BLOCK_FROM_STRUCT(sound_dialogue_constants_block, 1, sound_dialogue_constants_struct_definition_struct_definition );

TAG_BLOCK(sound_globals_block, 1)
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
	FIELD( _field_block, "un-spatialized campaign sounds", &campaign_unspatialized_sounds_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(StreamingPackBlock, k_maximum_streaming_packs)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string, "Streaming pck file#Name of the stream pack file" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_unspatialized_sounds_block, k_maximum_campaign_unspatialized_sounds)
{
	FIELD( _field_tag_reference, "sound^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(SoundBankBlock, k_maximumSoundBanksPerTag)
{
	FIELD( _field_string_id, "Sound bank name#Name of the main sound bank." ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(soundLipSyncInfoBlock, 1, soundLipSyncInfoBlock_struct_struct_definition );

TAG_BLOCK_FROM_STRUCT(deterministicSpeechEventBlock, MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE, deterministicSpeechEventBlock_struct_struct_definition );

TAG_BLOCK(facial_animation_language_block, k_language_count)
{
	FIELD( _field_pageable, "facial animation resource" ),
	FIELD( _field_long_enum, "language" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_promotion_rule_block, k_maximum_promotion_rules_per_sound)
{
	FIELD( _field_short_block_index, "pitch range^" ),
	FIELD( _field_short_integer, "maximum playing count" ),
	FIELD( _field_real, "suppression time:seconds#time from when first permutation plays to when another sound from an equal or lower promotion can play" ),
	FIELD( _field_long_integer, "runtime rollover time!" ),
	FIELD( _field_long_integer, "impulse promotion time!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_promotion_runtime_timer_block, k_maximum_promotion_rules_per_sound)
{
	FIELD( _field_long_integer, "timer storage~!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_pitch_range_block, MAXIMUM_PITCH_RANGES_PER_SOUND)
{
	FIELD( _field_string_id, "name*#the name of the imported pitch range directory" ),
	FIELD( _field_explanation, "pitch control" ),
	FIELD( _field_short_integer, "natural pitch:cents#the apparent pitch when these samples are played at their recorded pitch." ),
	FIELD( _field_pad, "KCTSDWPP~", 2 ),
	FIELD( _field_short_bounds, "bend bounds:cents#the range of pitches that will be represented using this sample." ),
	FIELD( _field_short_bounds, "full volume bounds!:cents#the range of pitches that map to full gain." ),
	FIELD( _field_short_bounds, "playback bend bounds:cents#the actual pitch will be clamped to this" ),
	FIELD( _field_struct, "distance parameters", &sound_distance_parameters_struct_struct_definition ),
	FIELD( _field_pad, "YAMTVB~", 4 ),
	FIELD( _field_char_integer, "runtime usable permutation count!" ),
	FIELD( _field_byte_flags, "xsync flags!" ),
	FIELD( _field_pad, "asdf", 2 ),
	FIELD( _field_block, "permutations*#permutations represent equivalent variations of this sound.", &sound_permutations_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutations_block, MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE)
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
	FIELD( _field_block, "languages!", &sound_permutation_languages_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutation_languages_block, k_language_count)
{
	FIELD( _field_long_integer, "uncompressed sample count" ),
	FIELD( _field_block, "chunks", &sound_permutation_chunk_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutation_chunk_block, UNSIGNED_SHORT_MAX*4)
{
	FIELD( _field_long_integer, "file offset*" ),
	FIELD( _field_long_integer, "encoded size and flags~!" ),
	FIELD( _field_long_block_index, "cache index~!" ),
	FIELD( _field_long_integer, "xma2_source_buffer_sample_start*" ),
	FIELD( _field_long_integer, "xma2_source_buffer_sample_end*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_platform_sound_playback_block, 1)
{
	FIELD( _field_struct, "playback definition", &platform_sound_playback_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_extra_info_block, 1)
{
	FIELD( _field_block, "language permutation info", &sound_definition_language_permutation_info_block_block ),
	FIELD( _field_block, "facial animation resource languages", &facial_animation_language_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_definition_language_permutation_info_block, MAXIMUM_PITCH_RANGES_PER_SOUND*MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE*2)
{
	FIELD( _field_block, "raw info block", &sound_permutation_raw_info_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutation_raw_info_block, 2*k_language_count)
{
	FIELD( _field_string_id, "skip fraction name" ),
	FIELD( _field_data, "samples!#sampled sound data" ),
	FIELD( _field_block, "markers!", &sound_permutation_marker_block_block ),
	FIELD( _field_block, "layer markers!", &sound_permutation_marker_block_block ),
	FIELD( _field_block, "xma2 seek table!", &sound_xma2_seek_table_block_block ),
	FIELD( _field_enum, "compression*" ),
	FIELD( _field_char_enum, "language*" ),
	FIELD( _field_pad, "ZHDGBHWS", 1 ),
	FIELD( _field_long_integer, "sample count!" ),
	FIELD( _field_long_integer, "resource sample offset!" ),
	FIELD( _field_long_integer, "resource sample size!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_permutation_marker_block, MAXIMUM_MARKERS_PER_PERMUTATION)
{
	FIELD( _field_long_integer, "marker id*" ),
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_long_integer, "sample offset*" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_xma2_seek_table_block, MAXIMUM_SOUND_DATA_SIZE/k_kilo)
{
	FIELD( _field_long_integer, "block relative sample start*" ),
	FIELD( _field_long_integer, "block relative sample end" ),
	FIELD( _field_long_integer, "starting sample index*" ),
	FIELD( _field_long_integer, "ending sample index*" ),
	FIELD( _field_long_integer, "starting xma2 offset*" ),
	FIELD( _field_long_integer, "ending xma2 offset*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(sound_pitch_range_distances_block, SHORT_MAX, sound_distance_parameters_struct_struct_definition );

TAG_STRUCT(sound_dialogue_constants_struct_definition)
{
	FIELD( _field_explanation, "named playing fractions" ),
	FIELD( _field_real, "almost never" ),
	FIELD( _field_real, "rarely" ),
	FIELD( _field_real, "somewhat" ),
	FIELD( _field_real, "often" ),
	FIELD( _field_pad, "VBEZIIDOF", 24 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_distance_parameters_struct)
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

TAG_STRUCT(sound_propagation_definition_struct)
{
	FIELD( _field_tag_reference, "sound environment" ),
	FIELD( _field_tag_reference, "background sound" ),
	FIELD( _field_real, "background sound gain#scale for fog background sound:dB" ),
	FIELD( _field_real, "environment ducking#scales the surrounding background sound by this much:dB" ),
	FIELD( _field_tag_reference, "entry sound" ),
	FIELD( _field_tag_reference, "exit sound" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(soundLipSyncInfoBlock_struct)
{
	FIELD( _field_long_integer, "number of usable facial animations" ),
	FIELD( _field_block, "deterministic event info", &deterministicSpeechEventBlock_block ),
	FIELD( _field_block, "facial animation resource languages", &facial_animation_language_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(deterministicSpeechEventBlock_struct)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "voice file path" ),
	FIELD( _field_real, "event duration" ),
	FIELD( _field_real, "skip fraction#Percent this file will be skipped when picked. 0 is always, 0.99 is almost never" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_playback_parameters_struct)
{
	FIELD( _field_long_integer, "internal flags!" ),
	FIELD( _field_real_fraction, "skip fraction#fraction of requests to play this sound that will be ignored (0 means always play.)" ),
	FIELD( _field_real, "maximum bend per second:cents" ),
	FIELD( _field_struct, "distance parameters{.}", &sound_distance_parameters_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom ),
	FIELD( _field_explanation, "randomization" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "gain base:dB#sound\'s random gain will start here" ),
	FIELD( _field_real, "gain variance:dB#sound\'s gain will be randomly modulated within this range" ),
	FIELD( _field_short_bounds, "random pitch bounds:cents#the sound\'s pitch will be modulated randomly within this range." ),
	FIELD( _field_explanation, "directional sounds" ),
	FIELD( _field_angle, "inner cone angle:degrees#within the cone defined by this angle and the sound\'s direction, the sound plays with a gain of 1.0." ),
	FIELD( _field_angle, "outer cone angle:degrees#outside the cone defined by this angle and the sound\'s direction, the sound plays with a gain of OUTER CONE GAIN. (0 means the sound does not attenuate with direction.)" ),
	FIELD( _field_real, "outer cone gain:dB#the gain to use when the sound is directed away from the listener" ),
	FIELD( _field_explanation, "scripted location override" ),
	FIELD( _field_custom ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_angle, "azimuth" ),
	FIELD( _field_real, "positional gain:dB" ),
	FIELD( _field_real, "first person gain:dB" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_scale_modifiers_struct)
{
	FIELD( _field_explanation, "scale modifiers" ),
	FIELD( _field_real_bounds, "gain modifier:dB" ),
	FIELD( _field_short_bounds, "pitch modifier:cents" ),
	FIELD( _field_real_fraction_bounds, "skip fraction modifier" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_promotion_parameters_struct)
{
	FIELD( _field_block, "promotion rules", &sound_promotion_rule_block_block ),
	FIELD( _field_block, "runtime timers!", &sound_promotion_runtime_timer_block_block ),
	FIELD( _field_long_integer, "runtime active promotion index!" ),
	FIELD( _field_long_integer, "runtime last promotion time!" ),
	FIELD( _field_long_integer, "runtime suppression timeout!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_transmission_definition_struct)
{
	FIELD( _field_explanation, "default obstruction settings" ),
	FIELD( _field_struct, "obstruction settings", &global_sound_lowpass_block_struct_definition ),
	FIELD( _field_explanation, "default occlusion settings" ),
	FIELD( _field_struct, "occlusion settings", &global_sound_lowpass_block_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_stereo_mix_struct)
{
	FIELD( _field_real, "left stereo gain:dB" ),
	FIELD( _field_real, "right stereo gain:dB" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_surround_mix_struct)
{
	FIELD( _field_real, "front speaker gain:dB" ),
	FIELD( _field_real, "rear speaker gain:dB" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_global_mix_struct)
{
	FIELD( _field_real, "mono unspatialized gain:dB" ),
	FIELD( _field_real, "stereo to 3d gain:dB" ),
	FIELD( _field_real, "rear surround to front stereo gain:dB" ),
	FIELD( _field_explanation, "surround center mix" ),
	FIELD( _field_struct, "surround center mix", &sound_center_mix_struct_struct_definition ),
	FIELD( _field_explanation, "stereo center mix" ),
	FIELD( _field_struct, "stereo center mix", &sound_center_mix_struct_struct_definition ),
	FIELD( _field_explanation, "radio surround center mix" ),
	FIELD( _field_struct, "radio surround center mix", &sound_center_mix_struct_struct_definition ),
	FIELD( _field_explanation, "radio stereo center mix" ),
	FIELD( _field_struct, "radio stereo center mix", &sound_center_mix_struct_struct_definition ),
	FIELD( _field_explanation, "more sound lovin\'" ),
	FIELD( _field_real, "stereo unspatialized gain:dB" ),
	FIELD( _field_real, "quad route to lfe gain:dB" ),
	FIELD( _field_explanation, "last minute values" ),
	FIELD( _field_real, "solo player fade out delay: seconds" ),
	FIELD( _field_real, "solo player fade out time: seconds" ),
	FIELD( _field_real, "solo player fade in time: seconds" ),
	FIELD( _field_real, "game music fade out time: seconds" ),
	FIELD( _field_explanation, "debugging stuff" ),
	FIELD( _field_tag_reference, "play on unplayable sound" ),
	FIELD( _field_real, "left/right bleed:[0 = no bleed, 1 = swap left/right, 0.5 = mono" ),
	FIELD( _field_real, "remote voice boost: output= (1 + boost)*input" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_center_mix_struct)
{
	FIELD( _field_real, "front speaker gain:dB" ),
	FIELD( _field_real, "center speaker gain:dB" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

