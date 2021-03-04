#include <gameframework-private-pch.h>

e_engine_type map_id_to_engine_type(e_map_id map_id)
{
	switch (map_id)
	{
	case _map_id_haloreach_noble_actual:
	case _map_id_haloreach_winter_contingency:
	case _map_id_haloreach_oni_sword_base:
	case _map_id_haloreach_nightfall:
	case _map_id_haloreach_tip_of_the_spear:
	case _map_id_haloreach_long_night_of_solace:
	case _map_id_haloreach_exodus:
	case _map_id_haloreach_new_alexandria:
	case _map_id_haloreach_the_package:
	case _map_id_haloreach_the_pillar_of_autumn:
	case _map_id_haloreach_the_pillar_of_autumn_credits:
	case _map_id_haloreach_lone_wolf:
	case _map_id_haloreach_boardwalk:
	case _map_id_haloreach_boneyard:
	case _map_id_haloreach_countdown:
	case _map_id_haloreach_powerhouse:
	case _map_id_haloreach_reflection:
	case _map_id_haloreach_spire:
	case _map_id_haloreach_sword_base:
	case _map_id_haloreach_zealot:
	case _map_id_haloreach_anchor_9:
	case _map_id_haloreach_breakpoint:
	case _map_id_haloreach_tempest:
	case _map_id_haloreach_condemned:
	case _map_id_haloreach_highlands:
	case _map_id_haloreach_battle_canyon:
	case _map_id_haloreach_penance:
	case _map_id_haloreach_ridgeline:
	case _map_id_haloreach_solitary:
	case _map_id_haloreach_high_noon:
	case _map_id_haloreach_breakneck:
	case _map_id_haloreach_forge_world:
	case _map_id_haloreach_beachhead:
	case _map_id_haloreach_corvette:
	case _map_id_haloreach_courtyard:
	case _map_id_haloreach_glacier:
	case _map_id_haloreach_holdout:
	case _map_id_haloreach_outpost:
	case _map_id_haloreach_overlook:
	case _map_id_haloreach_waterfront:
	case _map_id_haloreach_unearthed:
	case _map_id_haloreach_installation_04:
		return _engine_type_haloreach;

	case _map_id_halo1_pillar_of_autumn:
	case _map_id_halo1_halo:
	case _map_id_halo1_truth_and_reconciliation:
	case _map_id_halo1_silent_cartographer:
	case _map_id_halo1_assault_on_the_control_room:
	case _map_id_halo1_343_guilty_spark:
	case _map_id_halo1_the_library:
	case _map_id_halo1_two_betrayals:
	case _map_id_halo1_keyes:
	case _map_id_halo1_the_maw:
	case _map_id_halo1_battle_creek:
	case _map_id_halo1_sidewinder:
	case _map_id_halo1_damnation:
	case _map_id_halo1_rat_race:
	case _map_id_halo1_prisoner:
	case _map_id_halo1_hang_em_high:
	case _map_id_halo1_chill_out:
	case _map_id_halo1_derelict:
	case _map_id_halo1_boarding_action:
	case _map_id_halo1_chiron:
	case _map_id_halo1_blood_gulch:
	case _map_id_halo1_wizard:
	case _map_id_halo1_longest:
	case _map_id_halo1_death_island:
	case _map_id_halo1_danger_canyon:
	case _map_id_halo1_infinity:
	case _map_id_halo1_timberland:
	case _map_id_halo1_ice_fields:
	case _map_id_halo1_gephyrophobia:
		return _engine_type_halo1;

	case _map_id_halo2_the_heretic:
	case _map_id_halo2_the_armory:
	case _map_id_halo2_cairo_station:
	case _map_id_halo2_outskirts:
	case _map_id_halo2_metropolis:
	case _map_id_halo2_the_arbiter:
	case _map_id_halo2_the_oracle:
	case _map_id_halo2_delta_halo:
	case _map_id_halo2_regret:
	case _map_id_halo2_sacred_icon:
	case _map_id_halo2_quarantine_zone:
	case _map_id_halo2_gravemind:
	case _map_id_halo2_uprising:
	case _map_id_halo2_high_charity:
	case _map_id_halo2_the_great_journey:
	case _map_id_halo2_lockout:
	case _map_id_halo2_ascension:
	case _map_id_halo2_midship:
	case _map_id_halo2_ivory_tower:
	case _map_id_halo2_beaver_creek:
	case _map_id_halo2_burial_mounds:
	case _map_id_halo2_colossus:
	case _map_id_halo2_zanzibar:
	case _map_id_halo2_coagulation:
	case _map_id_halo2_headlong:
	case _map_id_halo2_waterworks:
	case _map_id_halo2_foundation:
	case _map_id_halo2_containment:
	case _map_id_halo2_warlock:
	case _map_id_halo2_sanctuary:
	case _map_id_halo2_turf:
	case _map_id_halo2_backwash:
	case _map_id_halo2_elongation:
	case _map_id_halo2_gemini:
	case _map_id_halo2_relic:
	case _map_id_halo2_terminal:
	case _map_id_halo2_desolation:
	case _map_id_halo2_tombstone:
	case _map_id_halo2_district:
	case _map_id_halo2_uplift:
		return _engine_type_halo2;

	case _map_id_halo3_arrival:
	case _map_id_halo3_sierra_117:
	case _map_id_halo3_crows_nest:
	case _map_id_halo3_tsavo_highway:
	case _map_id_halo3_the_storm:
	case _map_id_halo3_floodgate:
	case _map_id_halo3_the_ark:
	case _map_id_halo3_the_covenant:
	case _map_id_halo3_cortana:
	case _map_id_halo3_halo:
	case _map_id_halo3_epilogue:
	case _map_id_halo3_construct:
	case _map_id_halo3_epitaph:
	case _map_id_halo3_guardian:
	case _map_id_halo3_high_ground:
	case _map_id_halo3_isolation:
	case _map_id_halo3_last_resort:
	case _map_id_halo3_narrows:
	case _map_id_halo3_sandtrap:
	case _map_id_halo3_snowbound:
	case _map_id_halo3_the_pit:
	case _map_id_halo3_valhalla:
	case _map_id_halo3_foundry:
	case _map_id_halo3_rats_nest:
	case _map_id_halo3_standoff:
	case _map_id_halo3_avalanche:
	case _map_id_halo3_blackout:
	case _map_id_halo3_ghost_town:
	case _map_id_halo3_cold_storage:
	case _map_id_halo3_assembly:
	case _map_id_halo3_orbital:
	case _map_id_halo3_sandbox:
	case _map_id_halo3_citadel:
	case _map_id_halo3_heretic:
	case _map_id_halo3_longshore:
		return _engine_type_halo3;

	case _map_id_halo3odst_prepare_to_drop:
	case _map_id_halo3odst_mombasa_streets:
	case _map_id_halo3odst_tayari_plaza:
	case _map_id_halo3odst_uplift_reserve:
	case _map_id_halo3odst_kizingo_boulevard:
	case _map_id_halo3odst_oni_alpha_site:
	case _map_id_halo3odst_nmpd_hq:
	case _map_id_halo3odst_kikowani_station:
	case _map_id_halo3odst_data_hive:
	case _map_id_halo3odst_coastal_highway:
	case _map_id_halo3odst_epilogue:
		return _engine_type_halo3odst;

	case _map_id_halo4_prologue:
	case _map_id_halo4_dawn:
	case _map_id_halo4_requiem:
	case _map_id_halo4_forerunner:
	case _map_id_halo4_infinity:
	case _map_id_halo4_reclaimer:
	case _map_id_halo4_shutdown:
	case _map_id_halo4_composer:
	case _map_id_halo4_midnight:
	case _map_id_halo4_epilogue:
	case _map_id_halo4_adrift:
	case _map_id_halo4_abandon:
	case _map_id_halo4_complex:
	case _map_id_halo4_exile:
	case _map_id_halo4_haven:
	case _map_id_halo4_longbow:
	case _map_id_halo4_meltdown:
	case _map_id_halo4_ragnarok:
	case _map_id_halo4_solace:
	case _map_id_halo4_vortex:
	case _map_id_halo4_ravine:
	case _map_id_halo4_impact:
	case _map_id_halo4_erosion:
	case _map_id_halo4_forge_island:
	case _map_id_halo4_wreckage:
	case _map_id_halo4_harvest:
	case _map_id_halo4_shatter:
	case _map_id_halo4_landfall:
	case _map_id_halo4_monolith:
	case _map_id_halo4_skyline:
	case _map_id_halo4_daybreak:
	case _map_id_halo4_outcast:
	case _map_id_halo4_perdition:
	case _map_id_halo4_pitfall:
	case _map_id_halo4_vertigo:
	case _map_id_halo4_ff_chopperbowl:
	case _map_id_halo4_ff_sniperalley:
	case _map_id_halo4_ff_fortsw:
	case _map_id_halo4_ff_temple:
	case _map_id_halo4_ff_scurve:
	case _map_id_halo4_ff_courtyard:
	case _map_id_halo4_ff_complex:
	case _map_id_halo4_ff_valhalla:
	case _map_id_halo4_ff_factory:
	case _map_id_halo4_ff_mezzanie:
	case _map_id_halo4_ff_caverns:
	case _map_id_halo4_ff_vortex:
	case _map_id_halo4_ff_breach:
	case _map_id_halo4_ff_hillside:
	case _map_id_halo4_ff_engine:
		return _engine_type_halo4;

	case _map_id_groundhog_lockout:
	case _map_id_groundhog_ascension:
	case _map_id_groundhog_zanzibar:
	case _map_id_groundhog_coagulation:
	case _map_id_groundhog_warlock:
	case _map_id_groundhog_sanctuary:
	case _map_id_groundhog_forge_skybox01:
	case _map_id_groundhog_forge_skybox02:
	case _map_id_groundhog_forge_skybox03:
	case _map_id_groundhog_relic:
		return _engine_type_groundhog;
	}

	return _engine_type_not_set;
}

e_mcc_game_mode map_id_to_game_mode(e_map_id map_id)
{
	switch (map_id)
	{
	case _map_id_haloreach_noble_actual:
	case _map_id_haloreach_winter_contingency:
	case _map_id_haloreach_oni_sword_base:
	case _map_id_haloreach_nightfall:
	case _map_id_haloreach_tip_of_the_spear:
	case _map_id_haloreach_long_night_of_solace:
	case _map_id_haloreach_exodus:
	case _map_id_haloreach_new_alexandria:
	case _map_id_haloreach_the_package:
	case _map_id_haloreach_the_pillar_of_autumn:
	case _map_id_haloreach_the_pillar_of_autumn_credits:
	case _map_id_haloreach_lone_wolf:
	case _map_id_halo1_pillar_of_autumn:
	case _map_id_halo1_halo:
	case _map_id_halo1_truth_and_reconciliation:
	case _map_id_halo1_silent_cartographer:
	case _map_id_halo1_assault_on_the_control_room:
	case _map_id_halo1_343_guilty_spark:
	case _map_id_halo1_the_library:
	case _map_id_halo1_two_betrayals:
	case _map_id_halo1_keyes:
	case _map_id_halo1_the_maw:
	case _map_id_halo2_the_heretic:
	case _map_id_halo2_the_armory:
	case _map_id_halo2_cairo_station:
	case _map_id_halo2_outskirts:
	case _map_id_halo2_metropolis:
	case _map_id_halo2_the_arbiter:
	case _map_id_halo2_the_oracle:
	case _map_id_halo2_delta_halo:
	case _map_id_halo2_regret:
	case _map_id_halo2_sacred_icon:
	case _map_id_halo2_quarantine_zone:
	case _map_id_halo2_gravemind:
	case _map_id_halo2_uprising:
	case _map_id_halo2_high_charity:
	case _map_id_halo2_the_great_journey:
	case _map_id_halo3_arrival:
	case _map_id_halo3_sierra_117:
	case _map_id_halo3_crows_nest:
	case _map_id_halo3_tsavo_highway:
	case _map_id_halo3_the_storm:
	case _map_id_halo3_floodgate:
	case _map_id_halo3_the_ark:
	case _map_id_halo3_the_covenant:
	case _map_id_halo3_cortana:
	case _map_id_halo3_halo:
	case _map_id_halo3_epilogue:
	case _map_id_halo3odst_prepare_to_drop:
	case _map_id_halo3odst_mombasa_streets:
	case _map_id_halo3odst_tayari_plaza:
	case _map_id_halo3odst_uplift_reserve:
	case _map_id_halo3odst_kizingo_boulevard:
	case _map_id_halo3odst_oni_alpha_site:
	case _map_id_halo3odst_nmpd_hq:
	case _map_id_halo3odst_kikowani_station:
	case _map_id_halo3odst_data_hive:
	case _map_id_halo3odst_coastal_highway:
	case _map_id_halo3odst_epilogue:
	case _map_id_halo4_prologue:
	case _map_id_halo4_dawn:
	case _map_id_halo4_requiem:
	case _map_id_halo4_forerunner:
	case _map_id_halo4_infinity:
	case _map_id_halo4_reclaimer:
	case _map_id_halo4_shutdown:
	case _map_id_halo4_composer:
	case _map_id_halo4_midnight:
	case _map_id_halo4_epilogue:
		return _mcc_game_mode_campaign;

	case _map_id_halo4_ff_chopperbowl:
	case _map_id_halo4_ff_sniperalley:
	case _map_id_halo4_ff_fortsw:
	case _map_id_halo4_ff_temple:
	case _map_id_halo4_ff_scurve:
	case _map_id_halo4_ff_courtyard:
	case _map_id_halo4_ff_complex:
	case _map_id_halo4_ff_valhalla:
	case _map_id_halo4_ff_factory:
	case _map_id_halo4_ff_mezzanie:
	case _map_id_halo4_ff_caverns:
	case _map_id_halo4_ff_vortex:
	case _map_id_halo4_ff_breach:
	case _map_id_halo4_ff_hillside:
	case _map_id_halo4_ff_engine:
		return _mcc_game_mode_spartan_ops;

	case _map_id_halo1_battle_creek:
	case _map_id_halo1_sidewinder:
	case _map_id_halo1_damnation:
	case _map_id_halo1_rat_race:
	case _map_id_halo1_prisoner:
	case _map_id_halo1_hang_em_high:
	case _map_id_halo1_chill_out:
	case _map_id_halo1_derelict:
	case _map_id_halo1_boarding_action:
	case _map_id_halo1_chiron:
	case _map_id_halo1_blood_gulch:
	case _map_id_halo1_wizard:
	case _map_id_halo1_longest:
	case _map_id_halo1_death_island:
	case _map_id_halo1_danger_canyon:
	case _map_id_halo1_infinity:
	case _map_id_halo1_timberland:
	case _map_id_halo1_ice_fields:
	case _map_id_halo1_gephyrophobia:
	case _map_id_halo2_lockout:
	case _map_id_halo2_ascension:
	case _map_id_halo2_midship:
	case _map_id_halo2_ivory_tower:
	case _map_id_halo2_beaver_creek:
	case _map_id_halo2_burial_mounds:
	case _map_id_halo2_colossus:
	case _map_id_halo2_zanzibar:
	case _map_id_halo2_coagulation:
	case _map_id_halo2_headlong:
	case _map_id_halo2_waterworks:
	case _map_id_halo2_foundation:
	case _map_id_halo2_containment:
	case _map_id_halo2_warlock:
	case _map_id_halo2_sanctuary:
	case _map_id_halo2_turf:
	case _map_id_halo2_backwash:
	case _map_id_halo2_elongation:
	case _map_id_halo2_gemini:
	case _map_id_halo2_relic:
	case _map_id_halo2_terminal:
	case _map_id_halo2_desolation:
	case _map_id_halo2_tombstone:
	case _map_id_halo2_district:
	case _map_id_halo2_uplift:
	case _map_id_halo3_construct:
	case _map_id_halo3_epitaph:
	case _map_id_halo3_guardian:
	case _map_id_halo3_high_ground:
	case _map_id_halo3_isolation:
	case _map_id_halo3_last_resort:
	case _map_id_halo3_narrows:
	case _map_id_halo3_sandtrap:
	case _map_id_halo3_snowbound:
	case _map_id_halo3_the_pit:
	case _map_id_halo3_valhalla:
	case _map_id_halo3_foundry:
	case _map_id_halo3_rats_nest:
	case _map_id_halo3_standoff:
	case _map_id_halo3_avalanche:
	case _map_id_halo3_blackout:
	case _map_id_halo3_ghost_town:
	case _map_id_halo3_cold_storage:
	case _map_id_halo3_assembly:
	case _map_id_halo3_orbital:
	case _map_id_halo3_sandbox:
	case _map_id_halo3_citadel:
	case _map_id_halo3_heretic:
	case _map_id_halo3_longshore:
	case _map_id_haloreach_boardwalk:
	case _map_id_haloreach_boneyard:
	case _map_id_haloreach_countdown:
	case _map_id_haloreach_powerhouse:
	case _map_id_haloreach_reflection:
	case _map_id_haloreach_spire:
	case _map_id_haloreach_sword_base:
	case _map_id_haloreach_zealot:
	case _map_id_haloreach_anchor_9:
	case _map_id_haloreach_breakpoint:
	case _map_id_haloreach_tempest:
	case _map_id_haloreach_condemned:
	case _map_id_haloreach_highlands:
	case _map_id_haloreach_battle_canyon:
	case _map_id_haloreach_penance:
	case _map_id_haloreach_ridgeline:
	case _map_id_haloreach_solitary:
	case _map_id_haloreach_high_noon:
	case _map_id_haloreach_breakneck:
	case _map_id_haloreach_forge_world:
	case _map_id_haloreach_unearthed:
	case _map_id_haloreach_installation_04:
	case _map_id_halo4_adrift:
	case _map_id_halo4_abandon:
	case _map_id_halo4_complex:
	case _map_id_halo4_exile:
	case _map_id_halo4_haven:
	case _map_id_halo4_longbow:
	case _map_id_halo4_meltdown:
	case _map_id_halo4_ragnarok:
	case _map_id_halo4_solace:
	case _map_id_halo4_vortex:
	case _map_id_halo4_ravine:
	case _map_id_halo4_impact:
	case _map_id_halo4_erosion:
	case _map_id_halo4_forge_island:
	case _map_id_halo4_wreckage:
	case _map_id_halo4_harvest:
	case _map_id_halo4_shatter:
	case _map_id_halo4_landfall:
	case _map_id_halo4_monolith:
	case _map_id_halo4_skyline:
	case _map_id_halo4_daybreak:
	case _map_id_halo4_outcast:
	case _map_id_halo4_perdition:
	case _map_id_halo4_pitfall:
	case _map_id_halo4_vertigo:
	case _map_id_groundhog_lockout:
	case _map_id_groundhog_ascension:
	case _map_id_groundhog_zanzibar:
	case _map_id_groundhog_coagulation:
	case _map_id_groundhog_warlock:
	case _map_id_groundhog_sanctuary:
	case _map_id_groundhog_forge_skybox01:
	case _map_id_groundhog_forge_skybox02:
	case _map_id_groundhog_forge_skybox03:
	case _map_id_groundhog_relic:
		return _mcc_game_mode_multiplayer;

	case _map_id_mainmenu:
		return _mcc_game_mode_ui_shell;

	case _map_id_haloreach_beachhead:
	case _map_id_haloreach_corvette:
	case _map_id_haloreach_courtyard:
	case _map_id_haloreach_glacier:
	case _map_id_haloreach_holdout:
	case _map_id_haloreach_outpost:
	case _map_id_haloreach_overlook:
	case _map_id_haloreach_waterfront:
		return _mcc_game_mode_firefight;
	}

	return _mcc_game_mode_none;
}

std::vector<signed int>& map_id_to_available_insertion_points(long map_id, bool is_firefight)
{
	static std::vector<signed int> vec;
	if (!vec.empty()) vec.clear();

	if (is_firefight)
	{
		switch (map_id)
		{
		case _map_id_halo3odst_mombasa_streets: vec = { 7, 8 };
		case _map_id_halo3odst_tayari_plaza:
		case _map_id_halo3odst_uplift_reserve: vec = { 4 };
		case _map_id_halo3odst_kizingo_boulevard: vec = { 5, 6 };
		case _map_id_halo3odst_oni_alpha_site: vec = { 4, 5 };
		case _map_id_halo3odst_nmpd_hq: vec = { 5 };
		case _map_id_halo3odst_data_hive: vec = { 6 };
		case _map_id_halo3odst_coastal_highway: vec = { 7 };
		}
	}
	else
	{
		switch (map_id)
		{
		case _map_id_halo3_arrival:
		case _map_id_halo3_epilogue: vec = { };
		case _map_id_halo3_tsavo_highway:
		case _map_id_halo3_the_storm:
		case _map_id_halo3_floodgate:
		case _map_id_halo3_cortana:
		case _map_id_halo3_halo: vec = { 0, 1 };
		case _map_id_halo3_crows_nest:
		case _map_id_halo3_the_ark:
		case _map_id_halo3_the_covenant: vec = { 0, 1, 2 };

		case _map_id_halo3odst_prepare_to_drop:
		case _map_id_halo3odst_epilogue: vec = { };
		case _map_id_halo3odst_mombasa_streets: vec = { 0, 1, 2, 3, 4, 5, 6, 7 };
		case _map_id_halo3odst_tayari_plaza:
		case _map_id_halo3odst_uplift_reserve:
		case _map_id_halo3odst_oni_alpha_site:
		case _map_id_halo3odst_kikowani_station: vec = { 0, 1, 2, 3 };
		case _map_id_halo3odst_kizingo_boulevard:
		case _map_id_halo3odst_nmpd_hq: vec = { 0, 1, 2, 3, 4 };
		case _map_id_halo3odst_data_hive: vec = { 0, 1, 2, 3, 4, 5 };
		case _map_id_halo3odst_coastal_highway: vec = { 0, 1, 2, 3, 4, 5, 6 };

		case _map_id_haloreach_noble_actual:
		case _map_id_haloreach_new_alexandria:
		case _map_id_haloreach_the_pillar_of_autumn_credits: vec = { };
		case _map_id_haloreach_winter_contingency: vec = { 0, 3, 4 };
		case _map_id_haloreach_oni_sword_base:
		case _map_id_haloreach_nightfall:
		case _map_id_haloreach_long_night_of_solace:
		case _map_id_haloreach_exodus: vec = { 0, 1, 2 };
		case _map_id_haloreach_tip_of_the_spear:
		case _map_id_haloreach_the_pillar_of_autumn: vec = { 0, 2, 4 };
		case _map_id_haloreach_the_package: vec = { 0, 4, 7 };
		case _map_id_haloreach_lone_wolf: vec = { 0 };

		case _map_id_halo4_prologue:
		case _map_id_halo4_epilogue: vec = { };
		case _map_id_halo4_dawn: vec = { 0, 1 };
		case _map_id_halo4_requiem: vec = { 0, 5 };
		case _map_id_halo4_forerunner: vec = { 0, 2, 5, 9 };
		case _map_id_halo4_infinity: vec = { 0, 3, 6 };
		case _map_id_halo4_reclaimer:
		case _map_id_halo4_composer: vec = { 0, 7 };
		case _map_id_halo4_shutdown: vec = { 0, 3, 4, 5 };
		case _map_id_halo4_midnight: vec = { 0, 1, 2 };
		}
	}

	return vec;
};

static BCS_RESULT get_map_id_string_impl(e_map_id map_id, bool pretty_name, const char** result)
{
	if (result == nullptr)
	{
		return BCS_E_INVALID_ARGUMENT;
	}

#define map_id_string_pair(map_id, pretty_name) case map_id: *result = (pretty_name ? (#map_id) : (pretty_name)); return BCS_S_OK;
	switch (map_id)
	{
		map_id_string_pair(_map_id_mainmenu, "Mainmenu");
		map_id_string_pair(_map_id_none, "None");

		map_id_string_pair(_map_id_halo1_pillar_of_autumn, "Pillar of Autumn");
		map_id_string_pair(_map_id_halo1_halo, "Halo");
		map_id_string_pair(_map_id_halo1_truth_and_reconciliation, "Truth and Reconciliation");
		map_id_string_pair(_map_id_halo1_silent_cartographer, "Silent Cartographer");
		map_id_string_pair(_map_id_halo1_assault_on_the_control_room, "Assault on the Control Room");
		map_id_string_pair(_map_id_halo1_343_guilty_spark, "343 Guilty Spark");
		map_id_string_pair(_map_id_halo1_the_library, "The Library");
		map_id_string_pair(_map_id_halo1_two_betrayals, "Two Betrayals");
		map_id_string_pair(_map_id_halo1_keyes, "Keyes");
		map_id_string_pair(_map_id_halo1_the_maw, "The Maw");
		map_id_string_pair(_map_id_halo1_battle_creek, "Battle Creek");
		map_id_string_pair(_map_id_halo1_sidewinder, "Sidewinder");
		map_id_string_pair(_map_id_halo1_damnation, "Damnation");
		map_id_string_pair(_map_id_halo1_rat_race, "Rat Race");
		map_id_string_pair(_map_id_halo1_prisoner, "Prisoner");
		map_id_string_pair(_map_id_halo1_hang_em_high, "Hang 'em High");
		map_id_string_pair(_map_id_halo1_chill_out, "Chill Out");
		map_id_string_pair(_map_id_halo1_derelict, "Derelict");
		map_id_string_pair(_map_id_halo1_boarding_action, "Boarding Action");
		map_id_string_pair(_map_id_halo1_chiron, "Chiron");
		map_id_string_pair(_map_id_halo1_blood_gulch, "Blood Gulch");
		map_id_string_pair(_map_id_halo1_wizard, "Wizard");
		map_id_string_pair(_map_id_halo1_longest, "Longest");
		map_id_string_pair(_map_id_halo1_death_island, "Death Island");
		map_id_string_pair(_map_id_halo1_danger_canyon, "Danger Canyon");
		map_id_string_pair(_map_id_halo1_infinity, "Infinity");
		map_id_string_pair(_map_id_halo1_timberland, "Timberland");
		map_id_string_pair(_map_id_halo1_ice_fields, "Ice Fields");
		map_id_string_pair(_map_id_halo1_gephyrophobia, "Gephyrophobia");

		map_id_string_pair(_map_id_halo2_the_heretic, "The Heretic");
		map_id_string_pair(_map_id_halo2_the_armory, "The Armory");
		map_id_string_pair(_map_id_halo2_cairo_station, "Cairo Station");
		map_id_string_pair(_map_id_halo2_outskirts, "Outskirts");
		map_id_string_pair(_map_id_halo2_metropolis, "Metropolis");
		map_id_string_pair(_map_id_halo2_the_arbiter, "The Arbiter");
		map_id_string_pair(_map_id_halo2_the_oracle, "The Oracle");
		map_id_string_pair(_map_id_halo2_delta_halo, "Delta Halo");
		map_id_string_pair(_map_id_halo2_regret, "Regret");
		map_id_string_pair(_map_id_halo2_sacred_icon, "Sacred Icon");
		map_id_string_pair(_map_id_halo2_quarantine_zone, "Quarantine Zone");
		map_id_string_pair(_map_id_halo2_gravemind, "Gravemind");
		map_id_string_pair(_map_id_halo2_uprising, "Uprising");
		map_id_string_pair(_map_id_halo2_high_charity, "High Charity");
		map_id_string_pair(_map_id_halo2_the_great_journey, "The Great Journey");
		map_id_string_pair(_map_id_halo2_lockout, "Lockout");
		map_id_string_pair(_map_id_halo2_ascension, "Ascension");
		map_id_string_pair(_map_id_halo2_midship, "Midship");
		map_id_string_pair(_map_id_halo2_ivory_tower, "Ivory Tower");
		map_id_string_pair(_map_id_halo2_beaver_creek, "Beaver Creek");
		map_id_string_pair(_map_id_halo2_burial_mounds, "Burial Mounds");
		map_id_string_pair(_map_id_halo2_colossus, "Colossus");
		map_id_string_pair(_map_id_halo2_zanzibar, "Zanzibar");
		map_id_string_pair(_map_id_halo2_coagulation, "Coagulation");
		map_id_string_pair(_map_id_halo2_headlong, "Headlong");
		map_id_string_pair(_map_id_halo2_waterworks, "Waterworks");
		map_id_string_pair(_map_id_halo2_foundation, "Foundation");
		map_id_string_pair(_map_id_halo2_containment, "Containment");
		map_id_string_pair(_map_id_halo2_warlock, "Warlock");
		map_id_string_pair(_map_id_halo2_sanctuary, "Sanctuary");
		map_id_string_pair(_map_id_halo2_turf, "Turf");
		map_id_string_pair(_map_id_halo2_backwash, "Backwash");
		map_id_string_pair(_map_id_halo2_elongation, "Elongation");
		map_id_string_pair(_map_id_halo2_gemini, "Gemini");
		map_id_string_pair(_map_id_halo2_relic, "Relic");
		map_id_string_pair(_map_id_halo2_terminal, "Terminal");
		map_id_string_pair(_map_id_halo2_desolation, "Desolation");
		map_id_string_pair(_map_id_halo2_tombstone, "Tombstone");
		map_id_string_pair(_map_id_halo2_district, "District");
		map_id_string_pair(_map_id_halo2_uplift, "Uplift");

		map_id_string_pair(_map_id_halo3_arrival, "Arrival");
		map_id_string_pair(_map_id_halo3_sierra_117, "Sierra 117");
		map_id_string_pair(_map_id_halo3_crows_nest, "Crows Nest");
		map_id_string_pair(_map_id_halo3_tsavo_highway, "Tsavo Highway");
		map_id_string_pair(_map_id_halo3_the_storm, "The Storm");
		map_id_string_pair(_map_id_halo3_floodgate, "Floodgate");
		map_id_string_pair(_map_id_halo3_the_ark, "The Ark");
		map_id_string_pair(_map_id_halo3_the_covenant, "The Covenant");
		map_id_string_pair(_map_id_halo3_cortana, "Cortana");
		map_id_string_pair(_map_id_halo3_halo, "Halo");
		map_id_string_pair(_map_id_halo3_extracredit_first_DONOTUSE_OR_REMOVE, "Extracredit First DONOTUSE_OR_REMOVE");
		map_id_string_pair(_map_id_halo3_epilogue, "Epilogue");
		map_id_string_pair(_map_id_halo3_construct, "Construct");
		map_id_string_pair(_map_id_halo3_epitaph, "Epitaph");
		map_id_string_pair(_map_id_halo3_guardian, "Guardian");
		map_id_string_pair(_map_id_halo3_high_ground, "High Ground");
		map_id_string_pair(_map_id_halo3_isolation, "Isolation");
		map_id_string_pair(_map_id_halo3_last_resort, "Last Resort");
		map_id_string_pair(_map_id_halo3_narrows, "Narrows");
		map_id_string_pair(_map_id_halo3_sandtrap, "Sandtrap");
		map_id_string_pair(_map_id_halo3_snowbound, "Snowbound");
		map_id_string_pair(_map_id_halo3_the_pit, "The Pit");
		map_id_string_pair(_map_id_halo3_valhalla, "Valhalla");
		map_id_string_pair(_map_id_halo3_foundry, "Foundry");
		map_id_string_pair(_map_id_halo3_rats_nest, "Rat's Nest");
		map_id_string_pair(_map_id_halo3_standoff, "Standoff");
		map_id_string_pair(_map_id_halo3_avalanche, "Avalanche");
		map_id_string_pair(_map_id_halo3_blackout, "Blackout");
		map_id_string_pair(_map_id_halo3_ghost_town, "Ghost Town");
		map_id_string_pair(_map_id_halo3_cold_storage, "Cold Storage");
		map_id_string_pair(_map_id_halo3_assembly, "Assembly");
		map_id_string_pair(_map_id_halo3_orbital, "Orbital");
		map_id_string_pair(_map_id_halo3_sandbox, "Sandbox");
		map_id_string_pair(_map_id_halo3_citadel, "Citadel");
		map_id_string_pair(_map_id_halo3_heretic, "Heretic");
		map_id_string_pair(_map_id_halo3_longshore, "Longshore");

		map_id_string_pair(_map_id_halo3odst_prepare_to_drop, "Prepare to Drop");
		map_id_string_pair(_map_id_halo3odst_mombasa_streets, "Mombasa Streets");
		map_id_string_pair(_map_id_halo3odst_tayari_plaza, "Tayari Plaza");
		map_id_string_pair(_map_id_halo3odst_uplift_reserve, "Uplift Reserve");
		map_id_string_pair(_map_id_halo3odst_kizingo_boulevard, "Kizingo Boulevard");
		map_id_string_pair(_map_id_halo3odst_oni_alpha_site, "Oni Alpha Site");
		map_id_string_pair(_map_id_halo3odst_nmpd_hq, "NMPD HQ");
		map_id_string_pair(_map_id_halo3odst_kikowani_station, "Kikowani Station");
		map_id_string_pair(_map_id_halo3odst_data_hive, "Data Hive");
		map_id_string_pair(_map_id_halo3odst_coastal_highway, "Coastal Highway");
		map_id_string_pair(_map_id_halo3odst_epilogue, "Epilogue");

		map_id_string_pair(_map_id_haloreach_noble_actual, "Noble Actual");
		map_id_string_pair(_map_id_haloreach_winter_contingency, "Winter Contingency");
		map_id_string_pair(_map_id_haloreach_oni_sword_base, "Oni Sword Base");
		map_id_string_pair(_map_id_haloreach_nightfall, "Nightfall");
		map_id_string_pair(_map_id_haloreach_tip_of_the_spear, "Tip of the Spear");
		map_id_string_pair(_map_id_haloreach_long_night_of_solace, "Long Night of Solace");
		map_id_string_pair(_map_id_haloreach_exodus, "Exodus");
		map_id_string_pair(_map_id_haloreach_new_alexandria, "New Alexandria");
		map_id_string_pair(_map_id_haloreach_the_package, "The Package");
		map_id_string_pair(_map_id_haloreach_the_pillar_of_autumn, "The Pillar of Autumn");
		map_id_string_pair(_map_id_haloreach_the_pillar_of_autumn_credits, "The Pillar of Autumn Credits");
		map_id_string_pair(_map_id_haloreach_lone_wolf, "Lone Wolf");
		map_id_string_pair(_map_id_haloreach_boardwalk, "Boardwalk");
		map_id_string_pair(_map_id_haloreach_boneyard, "Boneyard");
		map_id_string_pair(_map_id_haloreach_countdown, "Countdown");
		map_id_string_pair(_map_id_haloreach_powerhouse, "Powerhouse");
		map_id_string_pair(_map_id_haloreach_reflection, "Reflection");
		map_id_string_pair(_map_id_haloreach_spire, "Spire");
		map_id_string_pair(_map_id_haloreach_sword_base, "Sword Base");
		map_id_string_pair(_map_id_haloreach_zealot, "Zealot");
		map_id_string_pair(_map_id_haloreach_anchor_9, "Anchor 9");
		map_id_string_pair(_map_id_haloreach_breakpoint, "Breakpoint");
		map_id_string_pair(_map_id_haloreach_tempest, "Tempest");
		map_id_string_pair(_map_id_haloreach_condemned, "Condemned");
		map_id_string_pair(_map_id_haloreach_highlands, "Highlands");
		map_id_string_pair(_map_id_haloreach_battle_canyon, "Battle Canyon");
		map_id_string_pair(_map_id_haloreach_penance, "Penance");
		map_id_string_pair(_map_id_haloreach_ridgeline, "Ridgeline");
		map_id_string_pair(_map_id_haloreach_solitary, "Solitary");
		map_id_string_pair(_map_id_haloreach_high_noon, "Nigh Noon");
		map_id_string_pair(_map_id_haloreach_breakneck, "Breakneck");
		map_id_string_pair(_map_id_haloreach_forge_world, "Forge World");
		map_id_string_pair(_map_id_haloreach_beachhead, "Beachhead");
		map_id_string_pair(_map_id_haloreach_corvette, "Corvette");
		map_id_string_pair(_map_id_haloreach_courtyard, "Courtyard");
		map_id_string_pair(_map_id_haloreach_glacier, "Glacier");
		map_id_string_pair(_map_id_haloreach_holdout, "Holdout");
		map_id_string_pair(_map_id_haloreach_outpost, "Outpost");
		map_id_string_pair(_map_id_haloreach_overlook, "Overlook");
		map_id_string_pair(_map_id_haloreach_waterfront, "Waterfront");
		map_id_string_pair(_map_id_haloreach_unearthed, "Unearthed");
		map_id_string_pair(_map_id_haloreach_installation_04, "Installation 04");

		map_id_string_pair(_map_id_halo4_prologue, "Prologue");
		map_id_string_pair(_map_id_halo4_dawn, "Dawn");
		map_id_string_pair(_map_id_halo4_requiem, "Requiem");
		map_id_string_pair(_map_id_halo4_forerunner, "Forerunner");
		map_id_string_pair(_map_id_halo4_infinity, "Infinity");
		map_id_string_pair(_map_id_halo4_reclaimer, "Reclaimer");
		map_id_string_pair(_map_id_halo4_shutdown, "Shutdown");
		map_id_string_pair(_map_id_halo4_composer, "Composer");
		map_id_string_pair(_map_id_halo4_midnight, "Midnight");
		map_id_string_pair(_map_id_halo4_epilogue, "Epilogue");
		map_id_string_pair(_map_id_halo4_multiplayer_first_DONOTUSE_OR_REMOVE, "Multiplayer First DONOTUSE_OR_REMOVE");
		map_id_string_pair(_map_id_halo4_adrift, "Adrift");
		map_id_string_pair(_map_id_halo4_abandon, "Abandon");
		map_id_string_pair(_map_id_halo4_complex, "Vomplex");
		map_id_string_pair(_map_id_halo4_exile, "Exile");
		map_id_string_pair(_map_id_halo4_haven, "Haven");
		map_id_string_pair(_map_id_halo4_longbow, "Longbow");
		map_id_string_pair(_map_id_halo4_meltdown, "Meltdown");
		map_id_string_pair(_map_id_halo4_ragnarok, "Ragnarok");
		map_id_string_pair(_map_id_halo4_solace, "Solace");
		map_id_string_pair(_map_id_halo4_vortex, "Vortex");
		map_id_string_pair(_map_id_halo4_ravine, "Ravine");
		map_id_string_pair(_map_id_halo4_impact, "Impact");
		map_id_string_pair(_map_id_halo4_erosion, "Erosion");
		map_id_string_pair(_map_id_halo4_forge_island, "Forge Island");
		map_id_string_pair(_map_id_halo4_wreckage, "Wreckage");
		map_id_string_pair(_map_id_halo4_harvest, "Harvest");
		map_id_string_pair(_map_id_halo4_shatter, "Shatter");
		map_id_string_pair(_map_id_halo4_landfall, "Landfall");
		map_id_string_pair(_map_id_halo4_monolith, "Monolith");
		map_id_string_pair(_map_id_halo4_skyline, "Skyline");
		map_id_string_pair(_map_id_halo4_daybreak, "Daybreak");
		map_id_string_pair(_map_id_halo4_outcast, "Outcast");
		map_id_string_pair(_map_id_halo4_perdition, "Perdition");
		map_id_string_pair(_map_id_halo4_pitfall, "Pitfall");
		map_id_string_pair(_map_id_halo4_vertigo, "Vertigo");
		map_id_string_pair(_map_id_halo4_spartan_ops_first_DONOTUSE_OR_REMOVE, "Spartan Ops First DONOTUSE_OR_REMOVE");
		map_id_string_pair(_map_id_halo4_ff_chopperbowl, "Chopperbowl");
		map_id_string_pair(_map_id_halo4_ff_sniperalley, "Sniperalley");
		map_id_string_pair(_map_id_halo4_ff_fortsw, "Fortsw");
		map_id_string_pair(_map_id_halo4_ff_temple, "Temple");
		map_id_string_pair(_map_id_halo4_ff_scurve, "Scurve");
		map_id_string_pair(_map_id_halo4_ff_courtyard, "Courtyard");
		map_id_string_pair(_map_id_halo4_ff_complex, "Complex");
		map_id_string_pair(_map_id_halo4_ff_valhalla, "Valhalla");
		map_id_string_pair(_map_id_halo4_ff_factory, "Factory");
		map_id_string_pair(_map_id_halo4_ff_mezzanie, "Mezzanie");
		map_id_string_pair(_map_id_halo4_ff_caverns, "Caverns");
		map_id_string_pair(_map_id_halo4_ff_vortex, "Vortex");
		map_id_string_pair(_map_id_halo4_ff_breach, "Breach");
		map_id_string_pair(_map_id_halo4_ff_hillside, "Hillside");
		map_id_string_pair(_map_id_halo4_ff_engine, "Engine");

		map_id_string_pair(_map_id_groundhog_lockout, "Lockout");
		map_id_string_pair(_map_id_groundhog_ascension, "Ascension");
		map_id_string_pair(_map_id_groundhog_zanzibar, "Zanzibar");
		map_id_string_pair(_map_id_groundhog_coagulation, "Coagulation");
		map_id_string_pair(_map_id_groundhog_warlock, "Warlock");
		map_id_string_pair(_map_id_groundhog_sanctuary, "Sanctuary");
		map_id_string_pair(_map_id_groundhog_forge_skybox01, "Forge Skybox01");
		map_id_string_pair(_map_id_groundhog_forge_skybox02, "Forge Skybox02");
		map_id_string_pair(_map_id_groundhog_forge_skybox03, "Forge Skybox03");
		map_id_string_pair(_map_id_groundhog_relic, "Relic");
	}
#undef platform_type_string_pair

	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT get_map_id_pretty_string(e_map_id map_id, const char** result)
{
	return get_map_id_string_impl(map_id, true, result);
}

BCS_RESULT get_map_id_string(e_map_id map_id, const char** result)
{
	return get_map_id_string_impl(map_id, false, result);
}
