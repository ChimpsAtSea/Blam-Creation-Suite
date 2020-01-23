#pragma once

struct nicename("Survival Mode Globals") group('smdt') s_survival_mode_globals_definition
{
	struct nicename("Waves") s_wave_block_definition;
	struct nicename("State Responses") s_state_respons_block_definition;
	struct nicename("Firefight Voices") s_firefight_voice_block_definition;
	struct nicename("Team Colors") s_team_color_block_definition;

	Undefined32 __unknown; 
	TagReference nicename("In Game Strings") in_game_strings_reference; 
	TagReference nicename("Timer Sound") timer_sound_reference; 
	TagReference nicename("Timer Sound Zero") timer_sound_zero_reference; 
	TagReference nicename("Survival Spawning Globals") survival_spawning_globals_reference; 
	s_tag_block_definition<s_wave_block_definition> nicename("Waves") waves_block; 
	s_tag_block_definition<s_state_respons_block_definition> nicename("State Responses") state_responses_block; 
	s_tag_block_definition<s_firefight_voice_block_definition> nicename("Firefight Voices") firefight_voices_block; 
	s_tag_block_definition<s_team_color_block_definition> nicename("Team Colors") team_colors_block; 
	Undefined32 __unknown2; 
	Undefined32 __unknown3; 

	struct nicename("wave") s_wave_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Wave") wave_reference; 
	};

	struct nicename("state_respons") s_state_respons_block_definition
	{
		uint16_t nicename("Flags") flags; 
		int16_t __unknown; 
		int16_t nicename("State") state; 
		int16_t __unknown2; 
		string_id nicename("Free for All Message") free_for_all_message; 
		string_id nicename("Team Message") team_message; 
		TagReference __unknown3_reference; 
		Undefined32 __unknown4; 
	};

	struct nicename("firefight_voice") s_firefight_voice_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Dialogue Male") dialogue_male_reference; 
		TagReference nicename("Dialogue Female") dialogue_female_reference; 
		Undefined32 __unknown; 
		TagReference nicename("Sound Preview Male") sound_preview_male_reference; 
		TagReference nicename("Sound Preview Female") sound_preview_female_reference; 
	};

	struct nicename("team_color") s_team_color_block_definition
	{
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
	};
};
