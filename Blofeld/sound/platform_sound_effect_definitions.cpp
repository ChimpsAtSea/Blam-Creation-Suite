#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(platform_sound_playback_component_flags, 4)
	{
		OPTION("don\'t play at start"),
		OPTION("play on stop"),
		OPTION("play alternate"),
		OPTION("sync with origin looping sound"),
	};

	TAG_ENUM(platform_sound_effect_flags_definition, 2)
	{
		OPTION("turn off in splitscreen"),
		OPTION("only turn on in first person"),
	};

	TAG_GROUP(sound_effect_collection, SOUND_EFFECT_COLLECTION_TAG)
	{
		FIELD( _field_block, "sound effects", &platform_sound_playback_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(platform_sound_playback_block, 128)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_struct, "playback", &platform_sound_playback_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(platform_sound_playback_lowpass_block, 1)
	{
		FIELD( _field_real, "attack:seconds" ),
		FIELD( _field_real, "release:seconds" ),
		FIELD( _field_struct, "settings", &global_sound_lowpass_block_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(platform_sound_playback_component_block, k_maximum_number_of_platform_sound_playback_components)
	{
		FIELD( _field_tag_reference, "sound^" ),
		FIELD( _field_real, "gain:dB#additional attenuation to sound" ),
		FIELD( _field_long_flags, "flags", &platform_sound_playback_component_flags ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(platform_sound_playback_struct)
{
		FIELD( _field_long_flags, "flags", &platform_sound_effect_flags_definition ),
		FIELD( _field_tag_reference, "radio effect" ),
		FIELD( _field_tag_reference, "Start event" ),
		FIELD( _field_tag_reference, "End event" ),
		FIELD( _field_tag_reference, "Immediate stop event#Must clear the effect without any transition - used for exiting levels, etc" ),
		FIELD( _field_block, "lowpass effect", &platform_sound_playback_lowpass_block_block ),
		FIELD( _field_block, "sound components", &platform_sound_playback_component_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

