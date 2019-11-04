#pragma once

enum e_map_id : int
{
	// TODO: add other games

	// reach
	_map_id_m05 = 178,
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

	k_number_of_map_ids
};

extern e_map_id string_to_map_id(const char* string);
extern const char* map_id_to_string(e_map_id map_id);
extern int map_id_to_engine_specific(e_map_id map_id);