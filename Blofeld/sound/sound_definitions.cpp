#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(StreamingPackBlockFlags, 2)
	{
		OPTION("Language pack"),
		OPTION("Sound bank pack"),
	};

	TAG_ENUM(sound_definition_flags, 13)
	{
		OPTION("fit to adpcm blocksize"),
		OPTION("always spatialize#always play as 3d sound, even in first person"),
		OPTION("never obstruct#disable occlusion/obstruction for this sound"),
		OPTION("internal don\'t touch!"),
		OPTION("facial animation data stripped!"),
		OPTION("use huge sound transmission"),
		OPTION("link count to owner unit"),
		OPTION("pitch range is language"),
		OPTION("don\'t use sound class speaker flag"),
		OPTION("don\'t use lipsync data"),
		OPTION("instant sound propagation"),
		OPTION("fake spatialization with distance"),
		OPTION("play permutations in order#picks the first permutation randomly"),
	};

	TAG_ENUM(SoundEventDefinitionFlags, 18)
	{
		OPTION("never obstruct#disable occlusion/obstruction for this sound"),
		OPTION("use huge sound transmission"),
		OPTION("link count to owner unit"),
		OPTION("don\'t use lipsync data"),
		OPTION("instant sound propagation"),
		OPTION("optional player sound event!*"),
		OPTION("fallback sound event!*"),
		OPTION("has lipsync data"),
		OPTION("is deterministic"),
		OPTION("is external source"),
		OPTION("override external source event"),
		OPTION("use don\'t play time!"),
		OPTION("delay start if sound bank not loaded"),
		OPTION("use fallback only for DVD"),
		OPTION("has subtitle!*"),
		OPTION("ignore node transform#use this if you\'re getting wacky spatialization (such as scorpion cannon)"),
		OPTION("radio combo voice"),
		OPTION("cinematic allow tails to play out"),
	};

	TAG_ENUM(sound_import_flags, 4)
	{
		OPTION("duplicate directory name"),
		OPTION("cut to block size"),
		OPTION("use markers"),
		OPTION("use layer markers"),
	};

	TAG_ENUM(sound_pitch_range_internal_xsync_flags, 1)
	{
		OPTION("processed language permutations"),
	};

	TAG_ENUM(sound_compression_enum, 8)
	{
		OPTION("none (big endian)"),
		OPTION("xbox adpcm"),
		OPTION("ima adpcm"),
		OPTION("none (little endian)"),
		OPTION("wma"),
		OPTION("none (endian agnostic)"),
		OPTION("xma"),
		OPTION("xma v2.0"),
	};

	TAG_ENUM(sound_encoding_enum, 5)
	{
		OPTION("mono"),
		OPTION("stereo"),
		OPTION("quad"),
		OPTION("5.1"),
		OPTION("codec"),
	};

	TAG_ENUM(sound_sample_rate_enum, 3)
	{
		OPTION("22kHz"),
		OPTION("44kHz"),
		OPTION("32kHz"),
	};

	TAG_ENUM(sound_effects_enum, 4)
	{
		OPTION("none"),
		OPTION("output front speakers"),
		OPTION("output rear speakers"),
		OPTION("output center speakers"),
	};

	TAG_ENUM(sound_import_type_enum, 4)
	{
		OPTION("unknown"),
		OPTION("single-shot"),
		OPTION("single-layer"),
		OPTION("multi-layer"),
	};

	TAG_ENUM(sound_class_enum, 71)
	{
		OPTION("projectile_impact"),
		OPTION("projectile_detonation"),
		OPTION("projectile_flyby"),
		OPTION("projectile_detonation_lod"),
		OPTION("weapon_fire"),
		OPTION("weapon_ready"),
		OPTION("weapon_reload"),
		OPTION("weapon_empty"),
		OPTION("weapon_charge"),
		OPTION("weapon_overheat"),
		OPTION("weapon_idle"),
		OPTION("weapon_melee"),
		OPTION("weapon_animation"),
		OPTION("object_impacts"),
		OPTION("particle_impacts"),
		OPTION("weapon_fire_lod"),
		OPTION("water_transitions"),
		OPTION("lowpass_effects"),
		OPTION("unit_footsteps"),
		OPTION("unit_dialog"),
		OPTION("unit_animation"),
		OPTION("unit_unused!"),
		OPTION("vehicle_collision"),
		OPTION("vehicle_engine"),
		OPTION("vehicle_animation"),
		OPTION("vehicle_engine_lod"),
		OPTION("device_door"),
		OPTION("device_unused0!"),
		OPTION("device_machinery"),
		OPTION("device_stationary"),
		OPTION("device_unused1!"),
		OPTION("device_unused2!"),
		OPTION("music"),
		OPTION("ambient_nature"),
		OPTION("ambient_machinery"),
		OPTION("ambient_stationary"),
		OPTION("huge_ass"),
		OPTION("object_looping"),
		OPTION("cinematic_music"),
		OPTION("unknown_unused0!"),
		OPTION("unknown_unused1!"),
		OPTION("ambient_flock"),
		OPTION("no_pad"),
		OPTION("no_pad_stationary"),
		OPTION("equipment_effect"),
		OPTION("mission_dialog"),
		OPTION("cinematic_dialog"),
		OPTION("scripted_cinematic_foley"),
		OPTION("game_event"),
		OPTION("ui"),
		OPTION("test"),
		OPTION("multiplayer_dialog"),
		OPTION("ambient_nature_details"),
		OPTION("ambient_machinery_details"),
		OPTION("inside_surround_tail"),
		OPTION("outside_surround_tail"),
		OPTION("vehicle_detonation"),
		OPTION("ambient_detonation"),
		OPTION("first_person_inside"),
		OPTION("first_person_outside"),
		OPTION("first_person_anywhere"),
		OPTION("space_projectile_detonation"),
		OPTION("space_projectile_flyby"),
		OPTION("space_vehicle_engine"),
		OPTION("space_weapon_fire"),
		OPTION("player_voice_team"),
		OPTION("player_voice_proxy"),
		OPTION("projectile_impact_postpone"),
		OPTION("unit_footsteps_postpone"),
		OPTION("weapon_ready_third_person"),
		OPTION("ui_music"),
	};

	TAG_ENUM(sound_language_enum_definition, 17)
	{
		OPTION("english"),
		OPTION("japanese"),
		OPTION("german"),
		OPTION("french"),
		OPTION("spanish"),
		OPTION("mexican spanish"),
		OPTION("italian"),
		OPTION("korean"),
		OPTION("chinese-traditional"),
		OPTION("chinese-simplified"),
		OPTION("portuguese"),
		OPTION("polish"),
		OPTION("russian"),
		OPTION("danish"),
		OPTION("finnish"),
		OPTION("dutch"),
		OPTION("norwegian"),
	};

	TAG_ENUM(facial_animation_track_enum_definition, 34)
	{
		OPTION("Silence"),
		OPTION("Eat"),
		OPTION("Earth"),
		OPTION("If"),
		OPTION("Ox"),
		OPTION("Oat"),
		OPTION("Wet"),
		OPTION("Size"),
		OPTION("Church"),
		OPTION("Fave"),
		OPTION("Though"),
		OPTION("Told"),
		OPTION("Bump"),
		OPTION("New"),
		OPTION("Roar"),
		OPTION("Cage"),
		OPTION("Eyebrow_Raise"),
		OPTION("Blink"),
		OPTION("Orientation_Head_Pitch"),
		OPTION("Orientation_Head_Roll"),
		OPTION("Orientation_Head_Yaw"),
		OPTION("Emphasis_Head_Pitch"),
		OPTION("Emphasis_Head_Roll"),
		OPTION("Emphasis_Head_Yaw"),
		OPTION("Gaze_Eye_Pitch"),
		OPTION("Gaze_Eye_Yaw"),
		OPTION("happy"),
		OPTION("sad"),
		OPTION("angry"),
		OPTION("disgusted"),
		OPTION("scared"),
		OPTION("surprised"),
		OPTION("pain"),
		OPTION("shout"),
	};

	TAG_ENUM_EMPTY(sound_permutation_flags, 0);

	TAG_ENUM(sound_permutation_external_flags, 1)
	{
		OPTION("don\'t play in dvd build"),
	};

	TAG_ENUM(sound_override_location_flags_definition, 3)
	{
		OPTION("override azimuth"),
		OPTION("override 3d gain"),
		OPTION("override speaker gain"),
	};

	TAG_ENUM(sound_xsync_flags, 2)
	{
		OPTION("processed language times"),
		OPTION("optimized facial animation"),
	};

	TAG_ENUM(SpeechEventInfoFlags, 10)
	{
		OPTION("Campaign Only"),
		OPTION("Exclude from certain missions"),
		OPTION("Exclude from M10"),
		OPTION("Exclude from M20"),
		OPTION("Exclude from M30"),
		OPTION("Exclude from M40"),
		OPTION("Exclude from M60"),
		OPTION("Exclude from M70"),
		OPTION("Exclude from M80"),
		OPTION("Exclude from M90"),
	};

	TAG_ENUM(SoundBankDefinitionFlags, 6)
	{
		OPTION("Don\'t use FP bank in split-screen#don\'t use the high quality first person bank in split-screen"),
		OPTION("Deterministic#Bank contains deterministic sounds (voices)"),
		OPTION("Stream off DVD only#Files will not be played off HD, only DVD (for music, etc)"),
		OPTION("Can delay start#Can delay start time for a short period waiting for bank to load"),
		OPTION("Don\'t load for player#Use this if there\'s a special player bank that\'s loaded by other means (ie weapon, vehicle)."),
		OPTION("Ground forces sound bank#Don\'t load this bank if player is in a vehicle (ie bipeds, footsteps)"),
	};

	TAG_GROUP(soundbank, SOUNDBANK_TAG)
	{
		FIELD( _field_long_flags, "flags", &SoundBankDefinitionFlags ),
		FIELD( _field_long_flags, "import flags!", &sound_import_flags ),
		FIELD( _field_long_flags, "xsync flags!", &sound_xsync_flags ),
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
		FIELD( _field_long_flags, "flags", &SoundEventDefinitionFlags ),
		FIELD( _field_long_flags, "import flags!", &sound_import_flags ),
		FIELD( _field_long_flags, "xsync flags!", &sound_xsync_flags ),
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
		FIELD( _field_long_flags, "flags", &sound_definition_flags ),
		FIELD( _field_long_flags, "import flags!", &sound_import_flags ),
		FIELD( _field_long_flags, "xsync flags!", &sound_xsync_flags ),
		FIELD( _field_char_enum, "class", &sound_class_enum ),
		FIELD( _field_char_enum, "sample rate*", &sound_sample_rate_enum ),
		FIELD( _field_char_integer, "override xma compression:[1-100]" ),
		FIELD( _field_char_enum, "import type*", &sound_import_type_enum ),
		FIELD( _field_struct, "playback", &sound_playback_parameters_struct_struct_definition ),
		FIELD( _field_struct, "scale", &sound_scale_modifiers_struct_struct_definition ),
		FIELD( _field_explanation, "sub priority" ),
		FIELD( _field_real, "sub priority" ),
		FIELD( _field_explanation, "import properties" ),
		FIELD( _field_char_enum, "encoding*", &sound_encoding_enum ),
		FIELD( _field_char_enum, "compression*", &sound_compression_enum ),
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
		FIELD( _field_long_flags, "flags", &sound_definition_flags ),
		FIELD( _field_long_flags, "import flags!", &sound_import_flags ),
		FIELD( _field_long_flags, "xsync flags!", &sound_xsync_flags ),
		FIELD( _field_char_enum, "class", &sound_class_enum ),
		FIELD( _field_char_enum, "sample rate*", &sound_sample_rate_enum ),
		FIELD( _field_char_integer, "override xma compression:[1-100]" ),
		FIELD( _field_char_enum, "import type*", &sound_import_type_enum ),
		FIELD( _field_struct, "playback", &sound_playback_parameters_struct_struct_definition ),
		FIELD( _field_struct, "scale", &sound_scale_modifiers_struct_struct_definition ),
		FIELD( _field_explanation, "sub priority" ),
		FIELD( _field_real, "sub priority" ),
		FIELD( _field_explanation, "import properties" ),
		FIELD( _field_char_enum, "encoding*", &sound_encoding_enum ),
		FIELD( _field_char_enum, "compression*", &sound_compression_enum ),
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
		FIELD( _field_long_flags, "flags", &StreamingPackBlockFlags ),
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
		FIELD( _field_long_enum, "language", &sound_language_enum_definition ),
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
		FIELD( _field_byte_flags, "xsync flags!", &sound_pitch_range_internal_xsync_flags ),
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
		FIELD( _field_word_flags, "permutation flags", &sound_permutation_external_flags ),
		FIELD( _field_word_flags, "flags!*", &sound_permutation_flags ),
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
		FIELD( _field_enum, "compression*", &sound_compression_enum ),
		FIELD( _field_char_enum, "language*", &sound_language_enum_definition ),
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
		FIELD( _field_long_flags, "flags", &SpeechEventInfoFlags ),
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
		FIELD( _field_long_flags, "flags", &sound_override_location_flags_definition ),
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

