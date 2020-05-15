#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(default_stimulus_suppressor, 4)
{
	{ _field_string_id, "stimulus^" },
	{ _field_terminator },
};

TAG_BLOCK(vocalization_definitions, 500)
{
	{ _field_string_id, "vocalization^" },
	{ _field_short_block_index, "parent index*" },
	{ _field_enum, "priority" },
	{ _field_long_flags, "flags" },
	{ _field_enum, "glance behavior#how does the speaker of this vocalization direct his gaze\?" },
	{ _field_enum, "glance recipient behavior#how does someone who hears me behave\?" },
	{ _field_enum, "perception type" },
	{ _field_enum, "max combat status" },
	{ _field_enum, "animation impulse" },
	{ _field_short_integer, "proxy dialogue index" },
	{ _field_real, "sound repetition delay:minutes#Minimum delay time between playing the same permutation" },
	{ _field_real, "allowable queue delay:seconds#How long to wait to actually start the vocalization" },
	{ _field_real, "pre voc. delay:seconds#How long to wait to actually start the vocalization" },
	{ _field_real, "notification delay:seconds#How long into the vocalization the AI should be notified" },
	{ _field_real, "post voc. delay:seconds#How long speech is suppressed in the speaking unit after vocalizing" },
	{ _field_real, "repeat delay:seconds#How long before the same vocalization can be repeated" },
	{ _field_real, "weight:[0-1]#Inherent weight of this vocalization" },
	{ _field_real, "speaker freeze time#speaker won\'t move for the given amount of time" },
	{ _field_real, "listener freeze time#listener won\'t move for the given amount of time (from start of vocalization)" },
	{ _field_enum, "speaker emotion" },
	{ _field_enum, "listener emotion" },
	{ _field_real, "player speaker skip fraction" },
	{ _field_real, "player skip fraction" },
	{ _field_real, "flood skip fraction" },
	{ _field_real, "skip fraction" },
	{ _field_short_integer, "mission min value#The lowest mission id that we play this line in" },
	{ _field_short_integer, "mission max value#The highest mission id that we play this line in" },
	{ _field_string_id, "Sample line" },
	{ _field_block, "reponses", &response_block },
	{ _field_terminator },
};

TAG_BLOCK(response, 20)
{
	{ _field_string_id, "vocalization name" },
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "vocalization index*" },
	{ _field_enum, "response type" },
	{ _field_short_integer, "dialogue index (import)*" },
	{ _field_terminator },
};

TAG_BLOCK(vocalization_patterns, 1000)
{
	{ _field_enum, "dialogue type" },
	{ _field_short_integer, "vocalization index" },
	{ _field_string_id, "vocalization name" },
	{ _field_enum, "speaker type" },
	{ _field_enum, "listener/target#who/what am I speaking to/of\?" },
	{ _field_enum, "hostility#The relationship between the subject and the cause" },
	{ _field_word_flags, "flags" },
	{ _field_explanation, "Cause" },
	{ _field_enum, "cause actor type" },
	{ _field_enum, "cause type" },
	{ _field_string_id, "cause ai type name" },
	{ _field_string_id, "cause equipment type name" },
	{ _field_explanation, "Speaker" },
	{ _field_enum, "speaker object type" },
	{ _field_enum, "speaker behavior" },
	{ _field_enum, "danger level#Speaker must have danger level of at least this much" },
	{ _field_char_enum, "speaker/subject position" },
	{ _field_char_enum, "speaker/cause position" },
	{ _field_long_flags, "Conditions" },
	{ _field_explanation, "Matching" },
	{ _field_enum, "spatial relation#with respect to the subject, the cause is ..." },
	{ _field_enum, "damage type" },
	{ _field_enum, "game type" },
	{ _field_explanation, "Subject" },
	{ _field_enum, "subject actor type" },
	{ _field_enum, "subject type" },
	{ _field_pad, "post-subject-type-pad", 2 },
	{ _field_string_id, "subject ai type name" },
	{ _field_terminator },
};

TAG_BLOCK(dialogue_data, k_dialogue_type_count)
{
	{ _field_short_integer, "start index (postprocess)*" },
	{ _field_short_integer, "length (postprocess)*" },
	{ _field_terminator },
};

TAG_BLOCK(involuntary_data, 100)
{
	{ _field_short_integer, "involuntary vocalization index*" },
	{ _field_pad, "JXIFX", 2 },
	{ _field_terminator },
};

TAG_BLOCK(predicted_data, 32)
{
	{ _field_long_integer, "predicted vocalization index*" },
	{ _field_terminator },
};

TAG_GROUP(ai_dialogue_globals, AI_DIALOGUE_GLOBALS_TAG)
{
	{ _field_explanation, "Global timing" },
	{ _field_real_bounds, "strike delay bounds:secs" },
	{ _field_real, "remind delay:secs" },
	{ _field_real, "cover curse chance" },
	{ _field_explanation, "Player look settings" },
	{ _field_real, "player look max distance:wu#defaults to 10 wu" },
	{ _field_real, "player look:secs#defaults to 3 secs" },
	{ _field_real, "player look long time:secs#defaults to 15 secs" },
	{ _field_explanation, "Spartan nearby search distance" },
	{ _field_real, "spartan nearby search distance:wu#defaults to 7 wu" },
	{ _field_explanation, "Face friendly player distance" },
	{ _field_real, "face friendly player distance:wu#0: disable facing behavior" },
	{ _field_explanation, "Space dialogue effect" },
	{ _field_string_id, "space dialogue effect#used for dialog lines started by a pattern with \"speaker in space\" set" },
	{ _field_explanation, "Default stimulus suppressors" },
	{ _field_block, "default stimulus suppressors", &default_stimulus_suppressor_block },
	{ _field_explanation, "Imported Data. Don\'t touch me." },
	{ _field_block, "vocalizations", &vocalization_definitions_block },
	{ _field_block, "patterns", &vocalization_patterns_block },
	{ _field_pad, "WWKMVLL", 12 },
	{ _field_block, "dialogue data", &dialogue_data_block },
	{ _field_block, "involuntary data", &involuntary_data_block },
	{ _field_block, "predicted vocalizations", &predicted_data_block },
	{ _field_terminator },
};

} // namespace blofeld

