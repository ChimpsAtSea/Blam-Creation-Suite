#pragma once
enum e_campaign_difficulty_level : int
{
	_campaign_difficulty_level_easy,
	_campaign_difficulty_level_normal,
	_campaign_difficulty_level_heroic,
	_campaign_difficulty_level_legendary,

	k_number_of_campaign_difficulty_levels,
};

extern e_campaign_difficulty_level string_to_campaign_difficulty_level(const char* string);
extern const char* campaign_difficulty_level_to_string(e_campaign_difficulty_level campaign_difficulty_level);

