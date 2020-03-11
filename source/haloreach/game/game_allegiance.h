#pragma once

#include <cseries/cseries.h>
#include <tag_files/tag_groups.h>

/* ---------- types */

enum e_campaign_team
{
    _campaign_team_default,
    _campaign_team_player,
    _campaign_team_human,
    _campaign_team_covenant,
    _campaign_team_brute,
    _campaign_team_mule,
    _campaign_team_spare,
    _campaign_team_covenant_player,
    k_number_of_campaign_teams
};

/* ---------- globals */

extern s_enum_definition g_campaign_team_enum;
