#include "opusframework-private-pch.h"

e_map_id string_to_map_id(const char* string)
{
	e_map_id map_id_list[] =
	{
		_map_id_mainmenu,
		_map_id_m05,
		_map_id_m10,
		_map_id_m20,
		_map_id_m30,
		_map_id_m35,
		_map_id_m45,
		_map_id_m50,
		_map_id_m52,
		_map_id_m60,
		_map_id_m70,
		_map_id_m70_a,
		_map_id_m70_bonus,
		_map_id_50_panopticon,
		_map_id_70_boneyard,
		_map_id_45_launch_station,
		_map_id_30_settlement,
		_map_id_52_ivory_tower,
		_map_id_35_island,
		_map_id_20_sword_slayer,
		_map_id_45_aftship,
		_map_id_dlc_slayer,
		_map_id_dlc_invasion,
		_map_id_dlc_medium,
		_map_id_condemned,
		_map_id_trainingpreserve,
		_map_id_cex_beaver_creek,
		_map_id_cex_damnation,
		_map_id_cex_timberland,
		_map_id_cex_prisoner,
		_map_id_cex_hangemhigh,
		_map_id_cex_headlong,
		_map_id_forge_halo,
		_map_id_ff50_park,
		_map_id_ff45_corvette,
		_map_id_ff20_courtyard,
		_map_id_ff60_icecave,
		_map_id_ff70_holdout,
		_map_id_ff60_ruins,
		_map_id_ff10_prototype,
		_map_id_ff30_waterfront,
		_map_id_ff_unearthed,
		_map_id_cex_ff_halo,
	};

	for (int i = 0; i < _countof(map_id_list); i++)
	{
		e_map_id map_id = map_id_list[i];
		const char* map_id_str = map_id_to_string(map_id);

		if (map_id_str != nullptr && (strcmp(string, map_id_str) == 0))
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
	case _map_id_mainmenu:
		return "mainmenu";
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
	return nullptr;
}

int map_id_to_engine_specific(e_map_id map_id)
{
	switch (map_id)
	{
	case _map_id_m05:
		return 5005;
	case _map_id_m10:
		return 5010;
	case _map_id_m20:
		return 5020;
	case _map_id_m30:
		return 5030;
	case _map_id_m35:
		return 5035;
	case _map_id_m45:
		return 5045;
	case _map_id_m50:
		return 5050;
	case _map_id_m52:
		return 5052;
	case _map_id_m60:
		return 5060;
	case _map_id_m70:
		return 5070;
	case _map_id_m70_a:
		return 5075;
	case _map_id_m70_bonus:
		return 5080;
	case _map_id_50_panopticon:
		return 1035;
	case _map_id_70_boneyard:
		return 1080;
	case _map_id_45_launch_station:
		return 1020;
	case _map_id_30_settlement:
		return 1055;
	case _map_id_52_ivory_tower:
		return 1150;
	case _map_id_35_island:
		return 1200;
	case _map_id_20_sword_slayer:
		return 1000;
	case _map_id_45_aftship:
		return 1040;
	case _map_id_dlc_slayer:
		return 2001;
	case _map_id_dlc_invasion:
		return 2002;
	case _map_id_dlc_medium:
		return 2004;
	case _map_id_condemned:
		return 1500;
	case _map_id_trainingpreserve:
		return 1510;
	case _map_id_cex_beaver_creek:
		return 10020;
	case _map_id_cex_damnation:
		return 10010;
	case _map_id_cex_timberland:
		return 10030;
	case _map_id_cex_prisoner:
		return 10070;
	case _map_id_cex_hangemhigh:
		return 10060;
	case _map_id_cex_headlong:
		return 10050;
	case _map_id_forge_halo:
		return 3006;
	case _map_id_ff50_park:
		return 7060;
	case _map_id_ff45_corvette:
		return 7110;
	case _map_id_ff20_courtyard:
		return 7020;
	case _map_id_ff60_icecave:
		return 7130;
	case _map_id_ff70_holdout:
		return 7080;
	case _map_id_ff60_ruins:
		return 7030;
	case _map_id_ff10_prototype:
		return 7000;
	case _map_id_ff30_waterfront:
		return 7040;
	case _map_id_ff_unearthed:
		return 7500;
	case _map_id_cex_ff_halo:
		return 10080;
	}
	return -1;
}
