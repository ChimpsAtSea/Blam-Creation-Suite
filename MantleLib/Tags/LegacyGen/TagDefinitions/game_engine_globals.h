#pragma once

struct nicename("game_engine_globals") tag_group('gegl') s_game_engine_globals_definition
{
	struct nicename("Engine Events") s_engine_events_definition
	{
		enum nicename("Audience") e_audience : uint8_t
		{
			/*nicename("Cause Player")*/ _audience_cause_player = 1ui8,
			/*nicename("Cause Team")*/ _audience_cause_team = 2ui8,
			/*nicename("Effect Player")*/ _audience_effect_player = 3ui8,
			/*nicename("Effect Team")*/ _audience_effect_team = 4ui8,
			/*nicename("All")*/ _audience_all = 5ui8,
		};

		enum nicename("Sound Flags") b_sound_flags : uint8_t /* bitfield */
		{
			/*nicename("Announcer Sound")*/ _sound_flags_announcer_sound = 1ui8 << 0ui8,
		};

		string_id_legacy nicename("Event") event;
		e_audience nicename("Audience") audience;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		string_id_legacy nicename("Display String") display_string;
		int16_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		string_id_legacy nicename("Primary String") primary_string;
		int32_t nicename("Primary String Duration") primary_string_duration;
		float nicename("Sound Delay (Announcer Only)") sound_delay_announcer_only;
		b_sound_flags nicename("Sound Flags") sound_flags;
		int8_t __unknown6;
		int8_t __unknown7;
		int8_t __unknown8;
		s_tag_reference_legacy nicename("Sound") sound_reference;
		s_undefined32_legacy __unknown9;
		int32_t __unknown10;
		int32_t __unknown11;
		float __unknown12;
		string_id_legacy __unknown13;
		int32_t __unknown14;
		float __unknown15;
		s_undefined32_legacy nicename("block here") block_here;
		s_undefined32_legacy nicename("block here") block_here1;
		s_undefined32_legacy nicename("block here") block_here2;
	};

	s_tag_reference_legacy nicename("Engine Settings") engine_settings_reference;
	s_tag_reference_legacy nicename("In Game Strings") in_game_strings_reference;
	s_tag_block_legacy<s_engine_events_definition> nicename("Engine Events") engine_events_block;
};

