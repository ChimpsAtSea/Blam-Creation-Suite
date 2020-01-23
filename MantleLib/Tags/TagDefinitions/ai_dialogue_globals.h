#pragma once

struct nicename("Ai Dialogue Globals") group('adlg') s_ai_dialogue_globals_definition
{
	struct s_unknown_0_block_definition;
	struct nicename("Vocalizations") s_vocalization_block_definition;
	struct nicename("Patterns") s_pattern_block_definition;
	struct nicename("Dialog Data") s_dialog_datum_block_definition;
	struct nicename("Involuntary Data") s_involuntary_datum_block_definition;
	struct s_unknown_5_block_definition;

	float __unknown; 
	float __unknown2; 
	float __unknown3; 
	float __unknown4; 
	Unknown32 __unknown5; 
	Unknown32 __unknown6; 
	Unknown32 __unknown7; 
	Unknown32 __unknown8; 
	float __unknown9; 
	string_id nicename("Radio Effect") radio_effect; 
	s_tag_block_definition<s_unknown_0_block_definition> __unknown_0_block; 
	s_tag_block_definition<s_vocalization_block_definition> nicename("Vocalizations") vocalizations_block; 
	s_tag_block_definition<s_pattern_block_definition> nicename("Patterns") patterns_block; 
	Unknown32 __unknown10; 
	Unknown32 __unknown11; 
	Unknown32 __unknown12; 
	s_tag_block_definition<s_dialog_datum_block_definition> nicename("Dialog Data") dialog_data_block; 
	s_tag_block_definition<s_involuntary_datum_block_definition> nicename("Involuntary Data") involuntary_data_block; 
	s_tag_block_definition<s_unknown_5_block_definition> __unknown_5_block; 

	struct s_unknown_0_block_definition
	{
		string_id __unknown; 
	};

	struct nicename("vocalization") s_vocalization_block_definition
	{
		struct nicename("Responses") s_respons_block_definition;

		string_id nicename("Vocalization") vocalization; 
		signed short nicename("Parent Index") parent_index; 
		signed short nicename("Priority") priority; 
		signed int nicename("Flags") flags; 
		signed short nicename("Glance Behavior") glance_behavior; 
		signed short nicename("Glance Recipient") glance_recipient; 
		signed short nicename("Perception Type") perception_type; 
		signed short nicename("Max Combat Status") max_combat_status; 
		signed short nicename("Animation Impulse") animation_impulse; 
		signed short nicename("Overlap Priority") overlap_priority; 
		float nicename("Sound Repetition Delay") sound_repetition_delay; 
		float nicename("Allowable Queue Delay") allowable_queue_delay; 
		float nicename("Pre Vocalization Delay") pre_vocalization_delay; 
		float nicename("Notification Delay") notification_delay; 
		float nicename("Post Vocalization Delay") post_vocalization_delay; 
		float nicename("Repeat Delay") repeat_delay; 
		float nicename("Weight") weight; 
		float nicename("Speaker Freeze Time") speaker_freeze_time; 
		float nicename("Listener Freeze Time") listener_freeze_time; 
		signed short nicename("Speaker Emotion") speaker_emotion; 
		signed short nicename("Listener Emotion") listener_emotion; 
		float nicename("Skip Fraction1") skip_fraction1; 
		float nicename("Skip Fraction2") skip_fraction2; 
		float nicename("Skip Fraction3") skip_fraction3; 
		float nicename("Skip Fraction4") skip_fraction4; 
		Unknown32 __unknown; 
		string_id nicename("Sample Line") sample_line; 
		s_tag_block_definition<s_respons_block_definition> nicename("Responses") responses_block; 

		struct nicename("respons") s_respons_block_definition
		{
			string_id nicename("Vocalization Name") vocalization_name; 
			unsigned short nicename("Flags") flags; 
			signed short nicename("Vocalization Index") vocalization_index; 
			signed short nicename("Response Type") response_type; 
			signed short nicename("Import Dialogue Index") import_dialogue_index; 
		};
	};

	struct nicename("pattern") s_pattern_block_definition
	{
		signed short nicename("Dialog Type") dialog_type; 
		signed short nicename("Vocalizations Index") vocalizations_index; 
		string_id nicename("Vocalization Name") vocalization_name; 
		signed short nicename("Speaker Type") speaker_type; 
		unsigned short nicename("Flags") flags; 
		signed short nicename("Hostility") hostility; 
		unsigned short __unknown; 
		signed short __unknown2; 
		signed short nicename("Cause Type") cause_type; 
		string_id nicename("Cause AI Type name") cause_ai_type_name; 
		string_id nicename("Equipment") equipment; 
		signed int __unknown3; 
		signed short __unknown4; 
		signed short __unknown5; 
		signed int __unknown6; 
		signed short nicename("Spacial Relationship") spacial_relationship; 
		signed short __unknown7; 
		signed short __unknown8; 
		signed short __unknown9; 
		signed short nicename("Subject Type") subject_type; 
		signed short __unknown10; 
		string_id nicename("Subject AI Type Name") subject_ai_type_name; 
	};

	struct nicename("dialog_datum") s_dialog_datum_block_definition
	{
		signed short nicename("Start Index") start_index; 
		signed short nicename("Length") length; 
	};

	struct nicename("involuntary_datum") s_involuntary_datum_block_definition
	{
		signed short nicename("Involuntary Vocalization Index") involuntary_vocalization_index; 
		signed short __unknown; 
	};

	struct s_unknown_5_block_definition
	{
		signed int __unknown; 
	};
};
