#pragma once

enum e_campaign_metagame_bucket_type : uint32_t
{
	_campaign_metagame_bucket_type_brute,
	_campaign_metagame_bucket_type_grunt,
	_campaign_metagame_bucket_type_jackel,
	_campaign_metagame_bucket_type_skirmisher,
	_campaign_metagame_bucket_type_marine,
	_campaign_metagame_bucket_type_spartan,
	_campaign_metagame_bucket_type_bugger,
	_campaign_metagame_bucket_type_hunter,
	_campaign_metagame_bucket_type_flood_infection,
	_campaign_metagame_bucket_type_flood_carrier,
	_campaign_metagame_bucket_type_flood_combat,
	_campaign_metagame_bucket_type_flood_pure,
	_campaign_metagame_bucket_type_sentinel,
	_campaign_metagame_bucket_type_elite,
	_campaign_metagame_bucket_type_engineer,
	_campaign_metagame_bucket_type_mule,
	_campaign_metagame_bucket_type_turret,
	_campaign_metagame_bucket_type_mongoose,
	_campaign_metagame_bucket_type_warthog,
	_campaign_metagame_bucket_type_scorpion,
	_campaign_metagame_bucket_type_hornet,
	_campaign_metagame_bucket_type_pelican,
	_campaign_metagame_bucket_type_revenant,
	_campaign_metagame_bucket_type_seraph,
	_campaign_metagame_bucket_type_shade,
	_campaign_metagame_bucket_type_watchtower,
	_campaign_metagame_bucket_type_ghost,
	_campaign_metagame_bucket_type_chopper,
	_campaign_metagame_bucket_type_mauler,
	_campaign_metagame_bucket_type_wraith,
	_campaign_metagame_bucket_type_banshee,
	_campaign_metagame_bucket_type_phantom,
	_campaign_metagame_bucket_type_scarab,
	_campaign_metagame_bucket_type_guntower,
	_campaign_metagame_bucket_type_tuning_fork,
	_campaign_metagame_bucket_type_broadsword,
	_campaign_metagame_bucket_type_mammoth,
	_campaign_metagame_bucket_type_lich,
	_campaign_metagame_bucket_type_mantis,
	_campaign_metagame_bucket_type_wasp,
	_campaign_metagame_bucket_type_phaeton,
	_campaign_metagame_bucket_type_bishop,
	_campaign_metagame_bucket_type_knight,
	_campaign_metagame_bucket_type_pawn,
	_campaign_metagame_bucket_type_engineer_recharge_station,
	_campaign_metagame_bucket_type_pelican_chin_gun,
	_campaign_metagame_bucket_type_sabre,
	_campaign_metagame_bucket_type_space_banshee,
	_campaign_metagame_bucket_type_falcon,
	k_number_of_campaign_metagame_bucket_types,
	k_invalid_campaign_metagame_bucket_type = ~0u
};

constexpr const char* campaign_metagame_bucket_type_to_string(e_campaign_metagame_bucket_type campaign_metagame_bucket_type)
{
	switch (campaign_metagame_bucket_type)
	{
	case _campaign_metagame_bucket_type_brute:						return "_campaign_metagame_bucket_type_brute";
	case _campaign_metagame_bucket_type_grunt:						return "_campaign_metagame_bucket_type_grunt";
	case _campaign_metagame_bucket_type_jackel:						return "_campaign_metagame_bucket_type_jackel";
	case _campaign_metagame_bucket_type_skirmisher:					return "_campaign_metagame_bucket_type_skirmisher";
	case _campaign_metagame_bucket_type_marine:						return "_campaign_metagame_bucket_type_marine";
	case _campaign_metagame_bucket_type_spartan:					return "_campaign_metagame_bucket_type_spartan";
	case _campaign_metagame_bucket_type_bugger:						return "_campaign_metagame_bucket_type_bugger";
	case _campaign_metagame_bucket_type_hunter:						return "_campaign_metagame_bucket_type_hunter";
	case _campaign_metagame_bucket_type_flood_infection:			return "_campaign_metagame_bucket_type_flood_infection";
	case _campaign_metagame_bucket_type_flood_carrier:				return "_campaign_metagame_bucket_type_flood_carrier";
	case _campaign_metagame_bucket_type_flood_combat:				return "_campaign_metagame_bucket_type_flood_combat";
	case _campaign_metagame_bucket_type_flood_pure:					return "_campaign_metagame_bucket_type_flood_pure";
	case _campaign_metagame_bucket_type_sentinel:					return "_campaign_metagame_bucket_type_sentinel";
	case _campaign_metagame_bucket_type_elite:						return "_campaign_metagame_bucket_type_elite";
	case _campaign_metagame_bucket_type_engineer:					return "_campaign_metagame_bucket_type_engineer";
	case _campaign_metagame_bucket_type_mule:						return "_campaign_metagame_bucket_type_mule";
	case _campaign_metagame_bucket_type_turret:						return "_campaign_metagame_bucket_type_turret";
	case _campaign_metagame_bucket_type_mongoose:					return "_campaign_metagame_bucket_type_mongoose";
	case _campaign_metagame_bucket_type_warthog:					return "_campaign_metagame_bucket_type_warthog";
	case _campaign_metagame_bucket_type_scorpion:					return "_campaign_metagame_bucket_type_scorpion";
	case _campaign_metagame_bucket_type_hornet:						return "_campaign_metagame_bucket_type_hornet";
	case _campaign_metagame_bucket_type_pelican:					return "_campaign_metagame_bucket_type_pelican";
	case _campaign_metagame_bucket_type_revenant:					return "_campaign_metagame_bucket_type_revenant";
	case _campaign_metagame_bucket_type_seraph:						return "_campaign_metagame_bucket_type_seraph";
	case _campaign_metagame_bucket_type_shade:						return "_campaign_metagame_bucket_type_shade";
	case _campaign_metagame_bucket_type_watchtower:					return "_campaign_metagame_bucket_type_watchtower";
	case _campaign_metagame_bucket_type_ghost:						return "_campaign_metagame_bucket_type_ghost";
	case _campaign_metagame_bucket_type_chopper:					return "_campaign_metagame_bucket_type_chopper";
	case _campaign_metagame_bucket_type_mauler:						return "_campaign_metagame_bucket_type_mauler";
	case _campaign_metagame_bucket_type_wraith:						return "_campaign_metagame_bucket_type_wraith";
	case _campaign_metagame_bucket_type_banshee:					return "_campaign_metagame_bucket_type_banshee";
	case _campaign_metagame_bucket_type_phantom:					return "_campaign_metagame_bucket_type_phantom";
	case _campaign_metagame_bucket_type_scarab:						return "_campaign_metagame_bucket_type_scarab";
	case _campaign_metagame_bucket_type_guntower:					return "_campaign_metagame_bucket_type_guntower";
	case _campaign_metagame_bucket_type_tuning_fork:				return "_campaign_metagame_bucket_type_tuning_fork";
	case _campaign_metagame_bucket_type_broadsword:					return "_campaign_metagame_bucket_type_broadsword";
	case _campaign_metagame_bucket_type_mammoth:					return "_campaign_metagame_bucket_type_mammoth";
	case _campaign_metagame_bucket_type_lich:						return "_campaign_metagame_bucket_type_lich";
	case _campaign_metagame_bucket_type_mantis:						return "_campaign_metagame_bucket_type_mantis";
	case _campaign_metagame_bucket_type_wasp:						return "_campaign_metagame_bucket_type_wasp";
	case _campaign_metagame_bucket_type_phaeton:					return "_campaign_metagame_bucket_type_phaeton";
	case _campaign_metagame_bucket_type_bishop:						return "_campaign_metagame_bucket_type_bishop";
	case _campaign_metagame_bucket_type_knight:						return "_campaign_metagame_bucket_type_knight";
	case _campaign_metagame_bucket_type_pawn:						return "_campaign_metagame_bucket_type_pawn";
	case _campaign_metagame_bucket_type_engineer_recharge_station:	return "_campaign_metagame_bucket_type_engineer_recharge_station";
	case _campaign_metagame_bucket_type_pelican_chin_gun:			return "_campaign_metagame_bucket_type_pelican_chin_gun";
	case _campaign_metagame_bucket_type_sabre:						return "_campaign_metagame_bucket_type_sabre";
	case _campaign_metagame_bucket_type_space_banshee:				return "_campaign_metagame_bucket_type_space_banshee";
	case _campaign_metagame_bucket_type_falcon:						return "_campaign_metagame_bucket_type_falcon";
	}
	return nullptr;
}

static inline e_campaign_metagame_bucket_type string_to_campaign_metagame_bucket_type(const char* campaign_metagame_bucket_type_string)
{
	for (underlying(e_campaign_metagame_bucket_type) current_campaign_metagame_bucket_type = 0; current_campaign_metagame_bucket_type < k_number_of_campaign_metagame_bucket_types; current_campaign_metagame_bucket_type++)
	{
		const char* current_campaign_metagame_bucket_type_string = campaign_metagame_bucket_type_to_string(static_cast<e_campaign_metagame_bucket_type>(current_campaign_metagame_bucket_type));

		if (strcmp(current_campaign_metagame_bucket_type_string, campaign_metagame_bucket_type_string) == 0)
		{
			return static_cast<e_campaign_metagame_bucket_type>(current_campaign_metagame_bucket_type);
		}
	}
	return k_invalid_campaign_metagame_bucket_type;
}
