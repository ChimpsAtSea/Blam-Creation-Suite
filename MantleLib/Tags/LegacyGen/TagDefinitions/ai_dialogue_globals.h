#pragma once

struct nicename("ai_dialogue_globals") tag_group('adlg') s_ai_dialogue_globals_definition
{
	struct nicename("Unknown 0") s_unknown_0_definition
	{
		string_id_legacy __unknown0;
	};

	struct nicename("Vocalizations") s_vocalizations_definition
	{
		enum nicename("Perception Type") e_perception_type : uint16_t
		{
			/*nicename("None")*/ _perception_type_none = 0ui16,
			/*nicename("Speaker")*/ _perception_type_speaker = 1ui16,
			/*nicename("Listener")*/ _perception_type_listener = 2ui16,
		};

		enum nicename("Flags") b_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Responses") s_responses_definition
		{
			enum nicename("Flags") b_flags : uint16_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _flags_bit_0 = 1ui16 << 0ui16,
				/*nicename("Bit 1")*/ _flags_bit_1 = 1ui16 << 1ui16,
				/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
				/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
				/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
				/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
				/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
				/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
				/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
				/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
				/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
				/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
				/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
				/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
				/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
				/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
			};

			string_id_legacy nicename("Vocalization Name") vocalization_name;
			b_flags nicename("Flags") flags;
			int16_t nicename("Vocalization Index") vocalization_index;
			int16_t nicename("Response Type") response_type;
			int16_t nicename("Import Dialogue Index") import_dialogue_index;
		};

		string_id_legacy nicename("Vocalization") vocalization;
		int16_t nicename("Parent Index") parent_index;
		int16_t nicename("Priority") priority;
		b_flags nicename("Flags") flags;
		int16_t nicename("Glance Behavior") glance_behavior;
		int16_t nicename("Glance Recipient") glance_recipient;
		e_perception_type nicename("Perception Type") perception_type;
		int16_t nicename("Max Combat Status") max_combat_status;
		int16_t nicename("Animation Impulse") animation_impulse;
		int16_t nicename("Overlap Priority") overlap_priority;
		float nicename("Sound Repetition Delay") sound_repetition_delay;
		float nicename("Allowable Queue Delay") allowable_queue_delay;
		float nicename("Pre Vocalization Delay") pre_vocalization_delay;
		float nicename("Notification Delay") notification_delay;
		float nicename("Post Vocalization Delay") post_vocalization_delay;
		float nicename("Repeat Delay") repeat_delay;
		float nicename("Weight") weight;
		float nicename("Speaker Freeze Time") speaker_freeze_time;
		float nicename("Listener Freeze Time") listener_freeze_time;
		int16_t nicename("Speaker Emotion") speaker_emotion;
		int16_t nicename("Listener Emotion") listener_emotion;
		float nicename("Skip Fraction1") skip_fraction1;
		float nicename("Skip Fraction2") skip_fraction2;
		float nicename("Skip Fraction3") skip_fraction3;
		float nicename("Skip Fraction4") skip_fraction4;
		s_undefined32_legacy __unknown0;
		string_id_legacy nicename("Sample Line") sample_line;
		s_tag_block_legacy<s_responses_definition> nicename("Responses") responses_block;
	};

	struct nicename("Patterns") s_patterns_definition
	{
		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags_bit_0 = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		enum b_unknown : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _unknown_bit_0 = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _unknown_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _unknown_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _unknown_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _unknown_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _unknown_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _unknown_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _unknown_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _unknown_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _unknown_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _unknown_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _unknown_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _unknown_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _unknown_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _unknown_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _unknown_bit_15 = 1ui16 << 15ui16,
		};

		int16_t nicename("Dialog Type") dialog_type;
		int16_t nicename("Vocalizations Index") vocalizations_index;
		string_id_legacy nicename("Vocalization Name") vocalization_name;
		int16_t nicename("Speaker Type") speaker_type;
		b_flags nicename("Flags") flags;
		int16_t nicename("Hostility") hostility;
		b_unknown __unknown0;
		int16_t __unknown1;
		int16_t nicename("Cause Type") cause_type;
		string_id_legacy nicename("Cause AI Type name") cause_ai_type_name;
		string_id_legacy nicename("Equipment") equipment;
		int32_t __unknown2;
		int16_t __unknown3;
		int16_t __unknown4;
		int32_t __unknown5;
		int16_t nicename("Spacial Relationship") spacial_relationship;
		int16_t __unknown6;
		int16_t __unknown7;
		int16_t __unknown8;
		int16_t nicename("Subject Type") subject_type;
		int16_t __unknown9;
		string_id_legacy nicename("Subject AI Type Name") subject_ai_type_name;
	};

	struct nicename("Dialog Data") s_dialog_data_definition
	{
		int16_t nicename("Start Index") start_index;
		int16_t nicename("Length") length;
	};

	struct nicename("Involuntary Data") s_involuntary_data_definition
	{
		int16_t nicename("Involuntary Vocalization Index") involuntary_vocalization_index;
		int16_t __unknown0;
	};

	struct nicename("Unknown 5") s_unknown_5_definition
	{
		int32_t __unknown0;
	};

	float __unknown0;
	float __unknown1;
	float __unknown2;
	float __unknown3;
	s_undefined32_legacy __unknown4;
	s_undefined32_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	float __unknown8;
	string_id_legacy nicename("Radio Effect") radio_effect;
	s_tag_block_legacy<s_unknown_0_definition> nicename("Unknown 0") unknown_0_block;
	s_tag_block_legacy<s_vocalizations_definition> nicename("Vocalizations") vocalizations_block;
	s_tag_block_legacy<s_patterns_definition> nicename("Patterns") patterns_block;
	s_undefined32_legacy __unknown9;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	s_tag_block_legacy<s_dialog_data_definition> nicename("Dialog Data") dialog_data_block;
	s_tag_block_legacy<s_involuntary_data_definition> nicename("Involuntary Data") involuntary_data_block;
	s_tag_block_legacy<s_unknown_5_definition> nicename("Unknown 5") unknown_5_block;
};

