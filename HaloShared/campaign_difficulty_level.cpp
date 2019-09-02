#include "haloshared-private-pch.h"

e_campaign_difficulty_level string_to_campaign_difficulty_level(const char* string)
{
	for (std::underlying_type<e_campaign_difficulty_level>::type i = _campaign_difficulty_level_easy; i < k_number_of_campaign_difficulty_levels; i++)
	{
		e_campaign_difficulty_level campaign_difficulty_level = static_cast<e_campaign_difficulty_level>(i);
		if (strcmp(string, campaign_difficulty_level_to_string(campaign_difficulty_level)) == 0)
		{
			return campaign_difficulty_level;
		}
	}
	return _campaign_difficulty_level_normal;
}

const char* campaign_difficulty_level_to_string(e_campaign_difficulty_level campaign_difficulty_level)
{
	switch (campaign_difficulty_level)
	{
	case _campaign_difficulty_level_easy:
		return "easy";
	case _campaign_difficulty_level_normal:
		return "normal";
	case _campaign_difficulty_level_heroic:
		return "heroic";
	case _campaign_difficulty_level_legendary:
		return "legendary";
	}
	return "<unknown>";
}