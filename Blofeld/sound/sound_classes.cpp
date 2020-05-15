#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_class, NUMBER_OF_SOUND_CLASSES)
{
	{ _field_short_integer, "max sounds per tag [1,16]#maximum number of sounds playing per individual sound tag" },
	{ _field_short_integer, "max sounds per object per tag [1,16]{max sounds per object [1,16]}#maximum number of sounds per individual sound tag playing on an object" },
	{ _field_short_integer, "max sounds per class [0,16]#maximum number of sounds playing of this class. zero means ignore." },
	{ _field_short_integer, "max sounds per object per class [0,16]#maximum number of sounds of this class playing on an object. zero means ignore." },
	{ _field_long_integer, "preemption time:ms#replaces other instances after this many milliseconds" },
	{ _field_word_flags, "internal flags!*" },
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "priority#higher means more important" },
	{ _field_char_enum, "cache miss mode*" },
	{ _field_byte_flags, "bind to acoustics" },
	{ _field_byte_flags, "suppress spatialization" },
	{ _field_pad, "sadf", 3 },
	{ _field_explanation, "air propagation" },
	{ _field_real, "air reverb gain{reverb gain}:dB#how much reverb applies to this sound class" },
	{ _field_real, "air direct path gain:dB#how much goes to direct path (dry)" },
	{ _field_real, "air base obstruction" },
	{ _field_real, "air base occlusion" },
	{ _field_explanation, "underwater propagation" },
	{ _field_real, "underwater reverb gain:dB#how much reverb applies to this sound class" },
	{ _field_real, "underwater direct path gain:dB#how much goes to direct path (dry)" },
	{ _field_real, "underwater base obstruction" },
	{ _field_real, "underwater base occlusion" },
	{ _field_real, "override speaker gain:dB" },
	{ _field_struct, "distance parameters" },
	{ _field_custom },
	{ _field_real_bounds, "gain bounds:dB~" },
	{ _field_explanation, "lowpass wetmixes" },
	{ _field_custom, "equipment lowpass{equipment channel occlusion factor}:wetmix#sets the lowpass wet mix when an equiment is active" },
	{ _field_real, "equipment lowpass{equipment channel occlusion factor}:wetmix#sets the lowpass wet mix when an equiment is active" },
	{ _field_custom, "environment forced lowpass{forced lowpass wet mix}:wetmix#sets the lowpass wet mix when an environment forced lowpass is active" },
	{ _field_real, "environment forced lowpass{forced lowpass wet mix}:wetmix#sets the lowpass wet mix when an environment forced lowpass is active" },
	{ _field_custom, "effect lowpass:wetmix#sets the lowpass wet mix when a lowpass effect is active" },
	{ _field_real, "effect lowpass:wetmix#sets the lowpass wet mix when a lowpass effect is active" },
	{ _field_explanation, "ducking" },
	{ _field_real, "cutscene ducking:dB" },
	{ _field_real, "cutscene ducking fade in time:seconds" },
	{ _field_real, "cutscene ducking sustain time:seconds#how long this lasts after the cutscene ends" },
	{ _field_real, "cutscene ducking fade out time:seconds" },
	{ _field_real, "scripted dialog ducking:dB" },
	{ _field_real, "scripted dialog ducking fade in time:seconds" },
	{ _field_real, "scripted dialog ducking sustain time:seconds#how long this lasts after the scripted dialog ends" },
	{ _field_real, "scripted dialog ducking fade out time:seconds" },
	{ _field_real, "equipment channel ducking:dB" },
	{ _field_real, "equipment channel ducking fade in time:seconds" },
	{ _field_real, "equipment channel ducking sustain time:seconds#how long this lasts after the equipment is turned off" },
	{ _field_real, "equipment channel ducking fade out time:seconds" },
	{ _field_real, "between rounds ducking:dB" },
	{ _field_real, "between rounds ducking fade in time:seconds" },
	{ _field_real, "between rounds ducking sustain time:seconds#how long this lasts after we get back in the game" },
	{ _field_real, "between rounds ducking fade out time:seconds" },
	{ _field_explanation, "misc" },
	{ _field_real, "doppler factor" },
	{ _field_char_enum, "stereo playback type" },
	{ _field_pad, "B", 3 },
	{ _field_real, "transmission multiplier" },
	{ _field_real, "transmission interpolation time:seconds#default is 0.5 seconds" },
	{ _field_long_integer, "xma compression level" },
	{ _field_real, "send to lfe gain:dB#When send (mono) to lfe is set, this is how much additional gain to apply" },
	{ _field_long_integer, "minimum facial animation delay:msecs#setting this forces sounds of this class to be delayed while the facial animation resource loads." },
	{ _field_long_integer, "maximum facial animation delay:msecs#setting this allows sounds of this class to be delayed while the facial animation resource loads." },
	{ _field_long_integer, "maximum facial animation blend:msecs#setting this makes sounds blends in facial animation (will cut off at maximum facial animation delay)." },
	{ _field_terminator },
};

TAG_GROUP(sound_classes, SOUND_CLASSES_TAG)
{
	{ _field_block, "sound classes", &sound_class_block },
	{ _field_terminator },
};

} // namespace blofeld

