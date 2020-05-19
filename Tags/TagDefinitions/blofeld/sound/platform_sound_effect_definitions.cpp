#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(sound_effect_collection, SOUND_EFFECT_COLLECTION_TAG)
	{
		{ _field_block, "sound effects", &platform_sound_playback_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(platform_sound_playback_lowpass_block, 1)
	{
		{ _field_real, "attack:seconds" },
		{ _field_real, "release:seconds" },
		{ _field_struct, "settings", &global_sound_lowpass_block_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(platform_sound_playback_component_block, k_maximum_number_of_platform_sound_playback_components)
	{
		{ _field_tag_reference, "sound^", &global_sound_and_looping_sound_reference },
		{ _field_real, "gain:dB#additional attenuation to sound" },
		{ _field_long_flags, "flags", &platform_sound_playback_component_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(platform_sound_playback_block, 128)
	{
		{ _field_string_id, "name^" },
		{ _field_struct, "playback", &platform_sound_playback_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(platform_sound_playback_struct)
	{
		{ _field_long_flags, "flags", &platform_sound_effect_flags_definition },
		{ _field_tag_reference, "radio effect", &global_sound_radio_settings_reference },
		{ _field_tag_reference, "Start event", &global_sound_reference },
		{ _field_tag_reference, "End event", &global_sound_reference },
		{ _field_tag_reference, "Immediate stop event#Must clear the effect without any transition - used for exiting levels, etc", &global_sound_reference },
		{ _field_block, "lowpass effect", &platform_sound_playback_lowpass_block_block },
		{ _field_block, "sound components", &platform_sound_playback_component_block_block },
		{ _field_terminator }
	};

	STRINGS(platform_sound_playback_component_flags)
	{
		"don\'t play at start",
		"play on stop",
		"play alternate",
		"sync with origin looping sound"
	};
	STRING_LIST(platform_sound_playback_component_flags, platform_sound_playback_component_flags_strings, _countof(platform_sound_playback_component_flags_strings));

	STRINGS(platform_sound_effect_flags_definition)
	{
		"turn off in splitscreen",
		"only turn on in first person"
	};
	STRING_LIST(platform_sound_effect_flags_definition, platform_sound_effect_flags_definition_strings, _countof(platform_sound_effect_flags_definition_strings));

} // namespace blofeld

