#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(ai_dialogue_globals, AI_DIALOGUE_GLOBALS_TAG, ai_dialogue_globals_block_block );

TAG_BLOCK_FROM_STRUCT(ai_dialogue_globals_block, 1, ai_dialogue_globals_struct_definition_struct_definition );

TAG_BLOCK(default_stimulus_suppressor_block, 4)
{
	FIELD( _field_string_id, "stimulus^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vocalization_definitions_block, 500)
{
	FIELD( _field_string_id, "vocalization^" ),
	FIELD( _field_short_block_index, "parent index*" ),
	FIELD( _field_enum, "priority" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_enum, "glance behavior#how does the speaker of this vocalization direct his gaze\?" ),
	FIELD( _field_enum, "glance recipient behavior#how does someone who hears me behave\?" ),
	FIELD( _field_enum, "perception type" ),
	FIELD( _field_enum, "max combat status" ),
	FIELD( _field_enum, "animation impulse" ),
	FIELD( _field_short_integer, "proxy dialogue index" ),
	FIELD( _field_real, "sound repetition delay:minutes#Minimum delay time between playing the same permutation" ),
	FIELD( _field_real, "allowable queue delay:seconds#How long to wait to actually start the vocalization" ),
	FIELD( _field_real, "pre voc. delay:seconds#How long to wait to actually start the vocalization" ),
	FIELD( _field_real, "notification delay:seconds#How long into the vocalization the AI should be notified" ),
	FIELD( _field_real, "post voc. delay:seconds#How long speech is suppressed in the speaking unit after vocalizing" ),
	FIELD( _field_real, "repeat delay:seconds#How long before the same vocalization can be repeated" ),
	FIELD( _field_real, "weight:[0-1]#Inherent weight of this vocalization" ),
	FIELD( _field_real, "speaker freeze time#speaker won\'t move for the given amount of time" ),
	FIELD( _field_real, "listener freeze time#listener won\'t move for the given amount of time (from start of vocalization)" ),
	FIELD( _field_enum, "speaker emotion" ),
	FIELD( _field_enum, "listener emotion" ),
	FIELD( _field_real, "player speaker skip fraction" ),
	FIELD( _field_real, "player skip fraction" ),
	FIELD( _field_real, "flood skip fraction" ),
	FIELD( _field_real, "skip fraction" ),
	FIELD( _field_short_integer, "mission min value#The lowest mission id that we play this line in" ),
	FIELD( _field_short_integer, "mission max value#The highest mission id that we play this line in" ),
	FIELD( _field_string_id, "Sample line" ),
	FIELD( _field_block, "reponses", &response_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(response_block, 20)
{
	FIELD( _field_string_id, "vocalization name" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_integer, "vocalization index*" ),
	FIELD( _field_enum, "response type" ),
	FIELD( _field_short_integer, "dialogue index (import)*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vocalization_patterns_block, 1000)
{
	FIELD( _field_enum, "dialogue type" ),
	FIELD( _field_short_integer, "vocalization index" ),
	FIELD( _field_string_id, "vocalization name" ),
	FIELD( _field_enum, "speaker type" ),
	FIELD( _field_enum, "listener/target#who/what am I speaking to/of\?" ),
	FIELD( _field_enum, "hostility#The relationship between the subject and the cause" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_explanation, "Cause" ),
	FIELD( _field_enum, "cause actor type" ),
	FIELD( _field_enum, "cause type" ),
	FIELD( _field_string_id, "cause ai type name" ),
	FIELD( _field_string_id, "cause equipment type name" ),
	FIELD( _field_explanation, "Speaker" ),
	FIELD( _field_enum, "speaker object type" ),
	FIELD( _field_enum, "speaker behavior" ),
	FIELD( _field_enum, "danger level#Speaker must have danger level of at least this much" ),
	FIELD( _field_char_enum, "speaker/subject position" ),
	FIELD( _field_char_enum, "speaker/cause position" ),
	FIELD( _field_long_flags, "Conditions" ),
	FIELD( _field_explanation, "Matching" ),
	FIELD( _field_enum, "spatial relation#with respect to the subject, the cause is ..." ),
	FIELD( _field_enum, "damage type" ),
	FIELD( _field_enum, "game type" ),
	FIELD( _field_explanation, "Subject" ),
	FIELD( _field_enum, "subject actor type" ),
	FIELD( _field_enum, "subject type" ),
	FIELD( _field_pad, "post-subject-type-pad", 2 ),
	FIELD( _field_string_id, "subject ai type name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(dialogue_data_block, k_dialogue_type_count)
{
	FIELD( _field_short_integer, "start index (postprocess)*" ),
	FIELD( _field_short_integer, "length (postprocess)*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(involuntary_data_block, 100)
{
	FIELD( _field_short_integer, "involuntary vocalization index*" ),
	FIELD( _field_pad, "JXIFX", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(predicted_data_block, 32)
{
	FIELD( _field_long_integer, "predicted vocalization index*" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(ai_dialogue_globals_struct_definition)
{
	FIELD( _field_explanation, "Global timing" ),
	FIELD( _field_real_bounds, "strike delay bounds:secs" ),
	FIELD( _field_real, "remind delay:secs" ),
	FIELD( _field_real, "cover curse chance" ),
	FIELD( _field_explanation, "Player look settings" ),
	FIELD( _field_real, "player look max distance:wu#defaults to 10 wu" ),
	FIELD( _field_real, "player look:secs#defaults to 3 secs" ),
	FIELD( _field_real, "player look long time:secs#defaults to 15 secs" ),
	FIELD( _field_explanation, "Spartan nearby search distance" ),
	FIELD( _field_real, "spartan nearby search distance:wu#defaults to 7 wu" ),
	FIELD( _field_explanation, "Face friendly player distance" ),
	FIELD( _field_real, "face friendly player distance:wu#0: disable facing behavior" ),
	FIELD( _field_explanation, "Space dialogue effect" ),
	FIELD( _field_string_id, "space dialogue effect#used for dialog lines started by a pattern with \"speaker in space\" set" ),
	FIELD( _field_explanation, "Default stimulus suppressors" ),
	FIELD( _field_block, "default stimulus suppressors", &default_stimulus_suppressor_block_block ),
	FIELD( _field_explanation, "Imported Data. Don\'t touch me." ),
	FIELD( _field_block, "vocalizations", &vocalization_definitions_block_block ),
	FIELD( _field_block, "patterns", &vocalization_patterns_block_block ),
	FIELD( _field_pad, "WWKMVLL", 12 ),
	FIELD( _field_block, "dialogue data", &dialogue_data_block_block ),
	FIELD( _field_block, "involuntary data", &involuntary_data_block_block ),
	FIELD( _field_block, "predicted vocalizations", &predicted_data_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

