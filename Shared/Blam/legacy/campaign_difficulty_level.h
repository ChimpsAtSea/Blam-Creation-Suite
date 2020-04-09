#pragma once

//enum e_campaign_difficulty_level : uint32_t
//{
//	_campaign_difficulty_level_easy = 0,
//	_campaign_difficulty_level_normal,
//	_campaign_difficulty_level_hard,
//	_campaign_difficulty_level_impossible,
//	k_number_of_campaign_difficulty_levels,
//};

constexpr const char* campaign_difficulty_level_to_string(e_campaign_difficulty_level campaign_difficulty_level)
{
	switch (campaign_difficulty_level)
	{
	case _campaign_difficulty_level_easy: return "_campaign_difficulty_level_easy";
	case _campaign_difficulty_level_normal: return "_campaign_difficulty_level_normal";
	case _campaign_difficulty_level_heroic: return "_campaign_difficulty_level_heroic";
	case _campaign_difficulty_level_legendary: return "_campaign_difficulty_level_legendary";
	}
	return nullptr;
}

constexpr const char* campaign_difficulty_level_to_local_string(e_campaign_difficulty_level campaign_difficulty_level)
{
	switch (campaign_difficulty_level)
	{
	case _campaign_difficulty_level_easy:			return "Easy";
	case _campaign_difficulty_level_normal:			return "Normal";
	case _campaign_difficulty_level_heroic:			return "Heroic";
	case _campaign_difficulty_level_legendary:		return "Legendary";
	}
	return nullptr;
}

static inline e_campaign_difficulty_level string_to_campaign_difficulty_level(const char* campaign_difficulty_level_string)
{
	for (underlying(e_campaign_difficulty_level) current_campaign_difficulty_level = 0; current_campaign_difficulty_level < k_number_of_campaign_difficulty_levels; current_campaign_difficulty_level++)
	{
		const char* current_campaign_difficulty_level_string = campaign_difficulty_level_to_string(static_cast<e_campaign_difficulty_level>(current_campaign_difficulty_level));

		if (strcmp(current_campaign_difficulty_level_string, campaign_difficulty_level_string) == 0)
		{
			return static_cast<e_campaign_difficulty_level>(current_campaign_difficulty_level);
		}
	}
	return _campaign_difficulty_level_normal;
}
