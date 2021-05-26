#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define SOUND_CLASSES_STRUCT_DEFINITION_ID { 0x75FD0DA6, 0x09ED40AC, 0x89E9FCF7, 0x523A0B97 }
	TAG_BLOCK(
		sound_classes_block,
		"sound_classes_block",
		1,
		"s_sound_classes_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_CLASSES_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "sound classes", &sound_class_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_classes_group,
		SOUND_CLASSES_TAG,
		nullptr,
		INVALID_TAG,
		sound_classes_block );

	#define SOUND_CLASS_BLOCK_STRUCT_ID { 0xDECE1540, 0x806F499C, 0x88FCD3BC, 0x96250604 }
	TAG_BLOCK(
		sound_class_block,
		"sound_class_block",
		NUMBER_OF_SOUND_CLASSES,
		"sound_class_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND_CLASS_BLOCK_STRUCT_ID)
	{
		{ _field_short_integer, "max sounds per tag", "maximum number of sounds playing per individual sound tag" },
		{ _field_short_integer, "max sounds per object per tag", "maximum number of sounds per individual sound tag playing on an object", MAKE_OLD_NAMES("max sounds per object [1,16]") },
		{ _field_short_integer, "max sounds per class", "maximum number of sounds playing of this class. zero means ignore." },
		{ _field_short_integer, "max sounds per object per class", "maximum number of sounds of this class playing on an object. zero means ignore." },
		{ _field_long_integer, "preemption time", "replaces other instances after this many milliseconds", "ms" },
		{ _field_word_flags, "internal flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &sound_class_internal_flags_definition },
		{ _field_word_flags, "flags", &sound_class_external_flags_definition },
		{ _field_short_integer, "priority", "higher means more important" },
		{ _field_char_enum, "cache miss mode", FIELD_FLAG_READ_ONLY, &sound_class_cache_miss_mode_definition },
		{ _field_byte_flags, "bind to acoustics", &sound_class_acoustics_string_definition },
		{ _field_byte_flags, "suppress spatialization", &sound_class_suppress_spatialization_string_defintion },
		FIELD_PAD("sadf", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_EXPLANATION("air propagation", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "air reverb gain", "how much reverb applies to this sound class", "dB", MAKE_OLD_NAMES("reverb gain"), _field_id_decibels },
		{ _field_real, "air direct path gain", "how much goes to direct path (dry)", "dB", _field_id_decibels },
		{ _field_real, "air base obstruction" },
		{ _field_real, "air base occlusion" },
		FIELD_EXPLANATION("underwater propagation", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "underwater reverb gain", "how much reverb applies to this sound class", "dB", _field_id_decibels },
		{ _field_real, "underwater direct path gain", "how much goes to direct path (dry)", "dB", _field_id_decibels },
		{ _field_real, "underwater base obstruction" },
		{ _field_real, "underwater base occlusion" },
		{ _field_real, "override speaker gain", nullptr, "dB", _field_id_decibels },
		{ _field_struct, "distance parameters", &sound_distance_parameters_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_real_bounds, "gain bounds", nullptr, "dB", FIELD_FLAG_UNKNOWN3, _field_id_decibels },
		FIELD_EXPLANATION("lowpass wetmixes", nullptr, FIELD_FLAG_NONE, ""),
		FIELD_CUSTOM("equipment lowpass", "sets the lowpass wet mix when an equiment is active", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "equipment lowpass", "sets the lowpass wet mix when an equiment is active", "wetmix", MAKE_OLD_NAMES("equipment channel occlusion factor"), _field_id_slider_editor },
		FIELD_CUSTOM("environment forced lowpass", "sets the lowpass wet mix when an environment forced lowpass is active", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "environment forced lowpass", "sets the lowpass wet mix when an environment forced lowpass is active", "wetmix", MAKE_OLD_NAMES("forced lowpass wet mix"), _field_id_slider_editor },
		FIELD_CUSTOM("effect lowpass", "sets the lowpass wet mix when a lowpass effect is active", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "effect lowpass", "sets the lowpass wet mix when a lowpass effect is active", "wetmix", _field_id_slider_editor },
		FIELD_EXPLANATION("ducking", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "cutscene ducking", nullptr, "dB", _field_id_decibels },
		{ _field_real, "cutscene ducking fade in time", nullptr, "seconds" },
		{ _field_real, "cutscene ducking sustain time", "how long this lasts after the cutscene ends", "seconds" },
		{ _field_real, "cutscene ducking fade out time", nullptr, "seconds" },
		{ _field_real, "scripted dialog ducking", nullptr, "dB", _field_id_decibels },
		{ _field_real, "scripted dialog ducking fade in time", nullptr, "seconds" },
		{ _field_real, "scripted dialog ducking sustain time", "how long this lasts after the scripted dialog ends", "seconds" },
		{ _field_real, "scripted dialog ducking fade out time", nullptr, "seconds" },
		{ _field_real, "equipment channel ducking", nullptr, "dB", _field_id_decibels },
		{ _field_real, "equipment channel ducking fade in time", nullptr, "seconds" },
		{ _field_real, "equipment channel ducking sustain time", "how long this lasts after the equipment is turned off", "seconds" },
		{ _field_real, "equipment channel ducking fade out time", nullptr, "seconds" },
		{ _field_real, "between rounds ducking", nullptr, "dB", _field_id_decibels },
		{ _field_real, "between rounds ducking fade in time", nullptr, "seconds" },
		{ _field_real, "between rounds ducking sustain time", "how long this lasts after we get back in the game", "seconds" },
		{ _field_real, "between rounds ducking fade out time", nullptr, "seconds" },
		FIELD_EXPLANATION("misc", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "doppler factor" },
		{ _field_char_enum, "stereo playback type", &sound_class_stereo_playback_definition },
		FIELD_PAD("B", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "transmission multiplier" },
		{ _field_real, "transmission interpolation time", "default is 0.5 seconds", "seconds" },
		{ _field_long_integer, "xma compression level" },
		{ _field_real, "send to lfe gain", "When send (mono) to lfe is set, this is how much additional gain to apply", "dB", _field_id_decibels },
		{ _field_long_integer, "minimum facial animation delay", "setting this forces sounds of this class to be delayed while the facial animation resource loads.", "msecs" },
		{ _field_long_integer, "maximum facial animation delay", "setting this allows sounds of this class to be delayed while the facial animation resource loads.", "msecs" },
		{ _field_long_integer, "maximum facial animation blend", "setting this makes sounds blends in facial animation (will cut off at maximum facial animation delay).", "msecs" },
		{ _field_terminator }
	};

	STRINGS(sound_class_internal_flags_definition)
	{
		"valid",
		"is speech",
		"scripted",
		"stops with object",
		"valid xma compression level",
		"valid doppler factor",
		"valid obstruction factor",
		"multilingual",
		"don\'t strip languages",
		"valid underwater propagation",
		"valid suppress spatialization"
	};
	STRING_LIST(sound_class_internal_flags_definition, sound_class_internal_flags_definition_strings, _countof(sound_class_internal_flags_definition_strings));

	STRINGS(sound_class_external_flags_definition)
	{
		"plays during pause",
		"bypass default dsp effects{dry stereo mix}",
		"no object obstruction!",
		"use center speaker unspatialized",
		"send (mono) to lfe",
		"deterministic",
		"use huge transmission",
		"always use speakers",
		"don\'t strip from main menu",
		"ignore stereo headroom",
		"loop fade out is linear",
		"stop when object dies",
		"don\'t fade on game over",
		"don\'t promote priority by proximity"
	};
	STRING_LIST(sound_class_external_flags_definition, sound_class_external_flags_definition_strings, _countof(sound_class_external_flags_definition_strings));

	STRINGS(sound_class_cache_miss_mode_definition)
	{
		"discard",
		"postpone"
	};
	STRING_LIST(sound_class_cache_miss_mode_definition, sound_class_cache_miss_mode_definition_strings, _countof(sound_class_cache_miss_mode_definition_strings));

	STRINGS(sound_class_stereo_playback_definition)
	{
		"first person",
		"ambient"
	};
	STRING_LIST(sound_class_stereo_playback_definition, sound_class_stereo_playback_definition_strings, _countof(sound_class_stereo_playback_definition_strings));

	STRINGS(sound_class_acoustics_string_definition)
	{
		"outside",
		"inside"
	};
	STRING_LIST(sound_class_acoustics_string_definition, sound_class_acoustics_string_definition_strings, _countof(sound_class_acoustics_string_definition_strings));

	STRINGS(sound_class_suppress_spatialization_string_defintion)
	{
		"first person",
		"third person"
	};
	STRING_LIST(sound_class_suppress_spatialization_string_defintion, sound_class_suppress_spatialization_string_defintion_strings, _countof(sound_class_suppress_spatialization_string_defintion_strings));



} // namespace blofeld

