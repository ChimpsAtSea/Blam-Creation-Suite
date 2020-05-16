#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(sound_classes, SOUND_CLASSES_TAG)
{
	FIELD( _field_block, "sound classes", &sound_class_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_class_block, NUMBER_OF_SOUND_CLASSES)
{
	FIELD( _field_short_integer, "max sounds per tag [1,16]#maximum number of sounds playing per individual sound tag" ),
	FIELD( _field_short_integer, "max sounds per object per tag [1,16]{max sounds per object [1,16]}#maximum number of sounds per individual sound tag playing on an object" ),
	FIELD( _field_short_integer, "max sounds per class [0,16]#maximum number of sounds playing of this class. zero means ignore." ),
	FIELD( _field_short_integer, "max sounds per object per class [0,16]#maximum number of sounds of this class playing on an object. zero means ignore." ),
	FIELD( _field_long_integer, "preemption time:ms#replaces other instances after this many milliseconds" ),
	FIELD( _field_word_flags, "internal flags!*" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_integer, "priority#higher means more important" ),
	FIELD( _field_char_enum, "cache miss mode*" ),
	FIELD( _field_byte_flags, "bind to acoustics" ),
	FIELD( _field_byte_flags, "suppress spatialization" ),
	FIELD( _field_pad, "sadf", 3 ),
	FIELD( _field_explanation, "air propagation" ),
	FIELD( _field_real, "air reverb gain{reverb gain}:dB#how much reverb applies to this sound class" ),
	FIELD( _field_real, "air direct path gain:dB#how much goes to direct path (dry)" ),
	FIELD( _field_real, "air base obstruction" ),
	FIELD( _field_real, "air base occlusion" ),
	FIELD( _field_explanation, "underwater propagation" ),
	FIELD( _field_real, "underwater reverb gain:dB#how much reverb applies to this sound class" ),
	FIELD( _field_real, "underwater direct path gain:dB#how much goes to direct path (dry)" ),
	FIELD( _field_real, "underwater base obstruction" ),
	FIELD( _field_real, "underwater base occlusion" ),
	FIELD( _field_real, "override speaker gain:dB" ),
	FIELD( _field_struct, "distance parameters", &sound_distance_parameters_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_real_bounds, "gain bounds:dB~" ),
	FIELD( _field_explanation, "lowpass wetmixes" ),
	FIELD( _field_custom, "equipment lowpass{equipment channel occlusion factor}:wetmix#sets the lowpass wet mix when an equiment is active" ),
	FIELD( _field_real, "equipment lowpass{equipment channel occlusion factor}:wetmix#sets the lowpass wet mix when an equiment is active" ),
	FIELD( _field_custom, "environment forced lowpass{forced lowpass wet mix}:wetmix#sets the lowpass wet mix when an environment forced lowpass is active" ),
	FIELD( _field_real, "environment forced lowpass{forced lowpass wet mix}:wetmix#sets the lowpass wet mix when an environment forced lowpass is active" ),
	FIELD( _field_custom, "effect lowpass:wetmix#sets the lowpass wet mix when a lowpass effect is active" ),
	FIELD( _field_real, "effect lowpass:wetmix#sets the lowpass wet mix when a lowpass effect is active" ),
	FIELD( _field_explanation, "ducking" ),
	FIELD( _field_real, "cutscene ducking:dB" ),
	FIELD( _field_real, "cutscene ducking fade in time:seconds" ),
	FIELD( _field_real, "cutscene ducking sustain time:seconds#how long this lasts after the cutscene ends" ),
	FIELD( _field_real, "cutscene ducking fade out time:seconds" ),
	FIELD( _field_real, "scripted dialog ducking:dB" ),
	FIELD( _field_real, "scripted dialog ducking fade in time:seconds" ),
	FIELD( _field_real, "scripted dialog ducking sustain time:seconds#how long this lasts after the scripted dialog ends" ),
	FIELD( _field_real, "scripted dialog ducking fade out time:seconds" ),
	FIELD( _field_real, "equipment channel ducking:dB" ),
	FIELD( _field_real, "equipment channel ducking fade in time:seconds" ),
	FIELD( _field_real, "equipment channel ducking sustain time:seconds#how long this lasts after the equipment is turned off" ),
	FIELD( _field_real, "equipment channel ducking fade out time:seconds" ),
	FIELD( _field_real, "between rounds ducking:dB" ),
	FIELD( _field_real, "between rounds ducking fade in time:seconds" ),
	FIELD( _field_real, "between rounds ducking sustain time:seconds#how long this lasts after we get back in the game" ),
	FIELD( _field_real, "between rounds ducking fade out time:seconds" ),
	FIELD( _field_explanation, "misc" ),
	FIELD( _field_real, "doppler factor" ),
	FIELD( _field_char_enum, "stereo playback type" ),
	FIELD( _field_pad, "B", 3 ),
	FIELD( _field_real, "transmission multiplier" ),
	FIELD( _field_real, "transmission interpolation time:seconds#default is 0.5 seconds" ),
	FIELD( _field_long_integer, "xma compression level" ),
	FIELD( _field_real, "send to lfe gain:dB#When send (mono) to lfe is set, this is how much additional gain to apply" ),
	FIELD( _field_long_integer, "minimum facial animation delay:msecs#setting this forces sounds of this class to be delayed while the facial animation resource loads." ),
	FIELD( _field_long_integer, "maximum facial animation delay:msecs#setting this allows sounds of this class to be delayed while the facial animation resource loads." ),
	FIELD( _field_long_integer, "maximum facial animation blend:msecs#setting this makes sounds blends in facial animation (will cut off at maximum facial animation delay)." ),
	FIELD( _field_terminator )
};

} // namespace blofeld

