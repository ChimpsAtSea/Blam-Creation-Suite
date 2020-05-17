#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(game_engine_event_flags_definition, 2)
	{
		OPTION("always play sound#used for respawn ticks and final tick in halo 3"),
		OPTION("always play sound in mp#so you can make multi kill sounds never be suppressed in MP"),
	};

	TAG_ENUM(game_engine_event_audience_enum_definition, 5)
	{
		OPTION("cause player"),
		OPTION("cause team"),
		OPTION("effect player"),
		OPTION("effect team"),
		OPTION("all"),
	};

	TAG_ENUM(game_engine_event_input_enum_definition, 5)
	{
		OPTION("NONE"),
		OPTION("cause player"),
		OPTION("cause team"),
		OPTION("effect player"),
		OPTION("effect team"),
	};

	TAG_ENUM(game_engine_event_splitscreen_suppression_enum_definition, 5)
	{
		OPTION("NONE"),
		OPTION("Suppress Audio"),
		OPTION("Suppress Audio if Overlapping"),
		OPTION("Suppress Text"),
		OPTION("Suppress Audio and Text"),
	};

	TAG_ENUM(game_engine_sound_response_flags_definition, 1)
	{
		OPTION("announcer sound"),
	};

	TAG_BLOCK(game_engine_event_block, k_maximum_game_engine_event_responses)
	{
		FIELD( _field_string_id, "name{incident}^" ),
		FIELD( _field_char_enum, "audience^", &game_engine_event_audience_enum_definition ),
		FIELD( _field_pad, "pad0", 3 ),
		FIELD( _field_string_id, "display string#This string can use a bunch of neat tokens for substitution of runtime data (e.g. player names).  See an engineer for more info." ),
		FIELD( _field_char_enum, "required field", &game_engine_event_input_enum_definition ),
		FIELD( _field_byte_flags, "excluded audience", &game_engine_event_input_enum_definition ),
		FIELD( _field_char_enum, "splitscreen suppression", &game_engine_event_splitscreen_suppression_enum_definition ),
		FIELD( _field_byte_flags, "flags", &game_engine_event_flags_definition ),
		FIELD( _field_string_id, "primary string#This string can use a bunch of neat tokens for substitution of runtime data (e.g. player names).  See an engineer for more info." ),
		FIELD( _field_long_integer, "primary string duration:seconds" ),
		FIELD( _field_real, "sound delay (announcer only)#After we commit to playing this sound, wait this long to actually play it.  Used to control announcer cadence." ),
		FIELD( _field_struct, "default_sound", &sound_response_definition_struct_struct_definition ),
		FIELD( _field_explanation, "SOUND PRIORITIZATION" ),
		FIELD( _field_string_id, "category_for_prioritization#which family does this response live in for announcer-spew-suppression\?  e.g. all multi-kills should use the same string_id here." ),
		FIELD( _field_long_integer, "sound priority#higher numbers mean more important" ),
		FIELD( _field_real, "priority_suppression_age_max_seconds:seconds#If a sound from this event has been queued for more than this long, it can\'t be suppressed anymore.  Higher values cause a shallower announcer queue for these sounds." ),
		FIELD( _field_explanation, "SOUND PAIR CULLING" ),
		FIELD( _field_string_id, "category_for_pair_culling#e.g. flag taken and flag dropped should use the same id here, while ball taken and ball dropped should use another shared id." ),
		FIELD( _field_long_integer, "pair_id#0 or 1, used to recognized matched pairs.  If both a 0 and a 1 are in the queue at the same time, and neither has started playing, both are removed." ),
		FIELD( _field_real, "delay_before_considering_sound_seconds:seconds#Used to keep a sound in the queue so later sounds can priority-suppress or pair-suppress it" ),
		FIELD( _field_block, "sound permutations", &sound_response_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(sound_response_definition_block, 10)
	{
		FIELD( _field_struct, "sound_response_definition_struct", &sound_response_definition_struct_struct_definition ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(sound_response_definition_struct)
{
		FIELD( _field_byte_flags, "sound flags", &game_engine_sound_response_flags_definition ),
		FIELD( _field_pad, "AGQD", 3 ),
		FIELD( _field_tag_reference, "sound{english sound}^" ),
		FIELD( _field_real, "probability#Ignored for the default sound - used for sound permutation block entries only." ),
		FIELD( _field_terminator )
};

} // namespace blofeld

