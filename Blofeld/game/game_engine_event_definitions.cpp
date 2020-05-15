#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_engine_event, k_maximum_game_engine_event_responses)
{
	{ _field_string_id, "name{incident}^" },
	{ _field_char_enum, "audience^" },
	{ _field_pad, "pad0", 3 },
	{ _field_string_id, "display string#This string can use a bunch of neat tokens for substitution of runtime data (e.g. player names).  See an engineer for more info." },
	{ _field_char_enum, "required field" },
	{ _field_byte_flags, "excluded audience" },
	{ _field_char_enum, "splitscreen suppression" },
	{ _field_byte_flags, "flags" },
	{ _field_string_id, "primary string#This string can use a bunch of neat tokens for substitution of runtime data (e.g. player names).  See an engineer for more info." },
	{ _field_long_integer, "primary string duration:seconds" },
	{ _field_real, "sound delay (announcer only)#After we commit to playing this sound, wait this long to actually play it.  Used to control announcer cadence." },
	{ _field_struct, "default_sound" },
	{ _field_explanation, "SOUND PRIORITIZATION" },
	{ _field_string_id, "category_for_prioritization#which family does this response live in for announcer-spew-suppression\?  e.g. all multi-kills should use the same string_id here." },
	{ _field_long_integer, "sound priority#higher numbers mean more important" },
	{ _field_real, "priority_suppression_age_max_seconds:seconds#If a sound from this event has been queued for more than this long, it can\'t be suppressed anymore.  Higher values cause a shallower announcer queue for these sounds." },
	{ _field_explanation, "SOUND PAIR CULLING" },
	{ _field_string_id, "category_for_pair_culling#e.g. flag taken and flag dropped should use the same id here, while ball taken and ball dropped should use another shared id." },
	{ _field_long_integer, "pair_id#0 or 1, used to recognized matched pairs.  If both a 0 and a 1 are in the queue at the same time, and neither has started playing, both are removed." },
	{ _field_real, "delay_before_considering_sound_seconds:seconds#Used to keep a sound in the queue so later sounds can priority-suppress or pair-suppress it" },
	{ _field_block, "sound permutations", &sound_response_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_response_definition, 10)
{
	{ _field_struct, "sound_response_definition_struct" },
	{ _field_terminator },
};

} // namespace blofeld

