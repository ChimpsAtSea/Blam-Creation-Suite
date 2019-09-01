#include "haloreach-private-pch.h"

e_map_id string_to_map_id(const char* string)
{
	for (std::underlying_type<e_map_id>::type i = _map_id_m05; i < k_number_of_map_ids; i++)
	{
		e_map_id map_id = static_cast<e_map_id>(i);
		if (strcmp(string, map_id_to_string(map_id)) == 0)
		{
			return map_id;
		}
	}
	return _map_id_ff45_corvette;
}

const char* map_id_to_string(e_map_id map_id)
{
	switch (map_id)
	{
	case _map_id_m05:
		return "m05";
	case _map_id_m10:
		return "m10";
	case _map_id_m20:
		return "m20";
	case _map_id_m30:
		return "m30";
	case _map_id_m35:
		return "m35";
	case _map_id_m45:
		return "m45";
	case _map_id_m50:
		return "m50";
	case _map_id_m52:
		return "m52";
	case _map_id_m60:
		return "m60";
	case _map_id_m70:
		return "m70";
	case _map_id_m70_a:
		return "m70_a";
	case _map_id_m70_bonus:
		return "m70_bonus";
	case _map_id_50_panopticon:
		return "50_panopticon";
	case _map_id_70_boneyard:
		return "70_boneyard";
	case _map_id_45_launch_station:
		return "45_launch_station";
	case _map_id_30_settlement:
		return "30_settlement";
	case _map_id_52_ivory_tower:
		return "52_ivory_tower";
	case _map_id_35_island:
		return "35_island";
	case _map_id_20_sword_slayer:
		return "20_sword_slayer";
	case _map_id_45_aftship:
		return "45_aftship";
	case _map_id_dlc_slayer:
		return "dlc_slayer";
	case _map_id_dlc_invasion:
		return "dlc_invasion";
	case _map_id_dlc_medium:
		return "dlc_medium";
	case _map_id_condemned:
		return "condemned";
	case _map_id_trainingpreserve:
		return "trainingpreserve";
	case _map_id_cex_beaver_creek:
		return "cex_beaver_creek";
	case _map_id_cex_damnation:
		return "cex_damnation";
	case _map_id_cex_timberland:
		return "cex_timberland";
	case _map_id_cex_prisoner:
		return "cex_prisoner";
	case _map_id_cex_hangemhigh:
		return "cex_hangemhigh";
	case _map_id_cex_headlong:
		return "cex_headlong";
	case _map_id_forge_halo:
		return "forge_halo";
	case _map_id_ff50_park:
		return "ff50_park";
	case _map_id_ff45_corvette:
		return "ff45_corvette";
	case _map_id_ff20_courtyard:
		return "ff20_courtyard";
	case _map_id_ff60_icecave:
		return "ff60_icecave";
	case _map_id_ff70_holdout:
		return "ff70_holdout";
	case _map_id_ff60_ruins:
		return "ff60_ruins";
	case _map_id_ff10_prototype:
		return "ff10_prototype";
	case _map_id_ff30_waterfront:
		return "ff30_waterfront";
	case _map_id_ff_unearthed:
		return "ff_unearthed";
	case _map_id_cex_ff_halo:
		return "cex_ff_halo";
	}
	return "<unknown>";
}
