#pragma once

enum e_map_id : uint32_t
{
	_map_id_halo1_pillar_of_autumn = 0,
	_map_id_halo1_halo,
	_map_id_halo1_truth_and_reconciliation,
	_map_id_halo1_silent_cartographer,
	_map_id_halo1_assault_on_the_control_room,
	_map_id_halo1_343_guilty_spark,
	_map_id_halo1_the_library,
	_map_id_halo1_two_betrayals,
	_map_id_halo1_keyes,
	_map_id_halo1_the_maw,
	_map_id_halo1_battle_creek,
	_map_id_halo1_sidewinder,
	_map_id_halo1_damnation,
	_map_id_halo1_rat_race,
	_map_id_halo1_prisoner,
	_map_id_halo1_hang_em_high,
	_map_id_halo1_chill_out,
	_map_id_halo1_derelict,
	_map_id_halo1_boarding_action,
	_map_id_halo1_chiron,
	_map_id_halo1_blood_gulch,
	_map_id_halo1_wizard,
	_map_id_halo1_longest,
	_map_id_halo1_death_island,
	_map_id_halo1_danger_canyon,
	_map_id_halo1_infinity,
	_map_id_halo1_timberland,
	_map_id_halo1_ice_fields,
	_map_id_halo1_gephyrophobia,
	_map_id_halo2_the_heretic,
	_map_id_halo2_the_armory,
	_map_id_halo2_cairo_station,
	_map_id_halo2_outskirts,
	_map_id_halo2_metropolis,
	_map_id_halo2_the_arbiter,
	_map_id_halo2_the_oracle,
	_map_id_halo2_delta_halo,
	_map_id_halo2_regret,
	_map_id_halo2_sacred_icon,
	_map_id_halo2_quarantine_zone,
	_map_id_halo2_gravemind,
	_map_id_halo2_uprising,
	_map_id_halo2_high_charity,
	_map_id_halo2_the_great_journey,
	_map_id_halo2_lockout,
	_map_id_halo2_ascension,
	_map_id_halo2_midship,
	_map_id_halo2_ivory_tower,
	_map_id_halo2_beaver_creek,
	_map_id_halo2_burial_mounds,
	_map_id_halo2_colossus,
	_map_id_halo2_zanzibar,
	_map_id_halo2_coagulation,
	_map_id_halo2_headlong,
	_map_id_halo2_waterworks,
	_map_id_halo2_foundation,
	_map_id_halo2_containment,
	_map_id_halo2_warlock,
	_map_id_halo2_sanctuary,
	_map_id_halo2_turf,
	_map_id_halo2_backwash,
	_map_id_halo2_elongation,
	_map_id_halo2_gemini,
	_map_id_halo2_relic,
	_map_id_halo2_terminal,
	_map_id_halo2_desolation,
	_map_id_halo2_tombstone,
	_map_id_halo2_district,
	_map_id_halo2_uplift,
	_map_id_halo3_arrival,
	_map_id_halo3_sierra_117,
	_map_id_halo3_crows_nest,
	_map_id_halo3_tsavo_highway,
	_map_id_halo3_the_storm,
	_map_id_halo3_floodgate,
	_map_id_halo3_the_ark,
	_map_id_halo3_the_covenant,
	_map_id_halo3_cortana,
	_map_id_halo3_halo,
	_map_id_halo3_construct,
	_map_id_halo3_epitaph,
	_map_id_halo3_guardian,
	_map_id_halo3_high_ground,
	_map_id_halo3_isolation,
	_map_id_halo3_last_resort,
	_map_id_halo3_narrows,
	_map_id_halo3_sandtrap,
	_map_id_halo3_snowbound,
	_map_id_halo3_the_pit,
	_map_id_halo3_valhalla,
	_map_id_halo3_foundry,
	_map_id_halo3_rats_nest,
	_map_id_halo3_standoff,
	_map_id_halo3_avalanche,
	_map_id_halo3_blackout,
	_map_id_halo3_ghost_town,
	_map_id_halo3_cold_storage,
	_map_id_halo3_assembly,
	_map_id_halo3_orbital,
	_map_id_halo3_sandbox,
	_map_id_halo3_citadel,
	_map_id_halo3_heretic,
	_map_id_halo3_longshore,
	_map_id_halo4_prologue,
	_map_id_halo4_dawn,
	_map_id_halo4_requiem,
	_map_id_halo4_forerunner,
	_map_id_halo4_infinity,
	_map_id_halo4_reclaimer,
	_map_id_halo4_shutdown,
	_map_id_halo4_composer,
	_map_id_halo4_midnight,
	_map_id_halo4_epilogue,
	_map_id_halo4_multiplayer_first_DONOTUSE_OR_REMOVE,
	_map_id_halo4_adrift,
	_map_id_halo4_abandon,
	_map_id_halo4_complex,
	_map_id_halo4_exile,
	_map_id_halo4_haven,
	_map_id_halo4_longbow,
	_map_id_halo4_meltdown,
	_map_id_halo4_ragnarok,
	_map_id_halo4_solace,
	_map_id_halo4_vortex,
	_map_id_halo4_ravine,
	_map_id_halo4_impact,
	_map_id_halo4_erosion,
	_map_id_halo4_forge_island,
	_map_id_halo4_wreckage,
	_map_id_halo4_harvest,
	_map_id_halo4_shatter,
	_map_id_halo4_landfall,
	_map_id_halo4_monolith,
	_map_id_halo4_skyline,
	_map_id_halo4_daybreak,
	_map_id_halo4_outcast,
	_map_id_halo4_perdition,
	_map_id_halo4_pitfall,
	_map_id_halo4_vertigo,
	_map_id_halo4_spartan_ops_first_DONOTUSE_OR_REMOVE,
	_map_id_halo4_ff_chopperbowl,
	_map_id_halo4_ff_sniperalley,
	_map_id_halo4_ff_fortsw,
	_map_id_halo4_ff_temple,
	_map_id_halo4_ff_scurve,
	_map_id_halo4_ff_courtyard,
	_map_id_halo4_ff_complex,
	_map_id_halo4_ff_valhalla,
	_map_id_halo4_ff_factory,
	_map_id_halo4_ff_mezzanie,
	_map_id_halo4_ff_caverns,
	_map_id_halo4_ff_vortex,
	_map_id_halo4_ff_breach,
	_map_id_halo4_ff_hillside,
	_map_id_halo4_ff_engine,
	_map_id_groundhog_lockout,
	_map_id_groundhog_ascension,
	_map_id_groundhog_zanzibar,
	_map_id_groundhog_coagulation,
	_map_id_groundhog_warlock,
	_map_id_groundhog_sanctuary,
	_map_id_groundhog_forge_skybox01,
	_map_id_groundhog_forge_skybox02,
	_map_id_groundhog_forge_skybox03,
	_map_id_halo3_extracredit_first_DONOTUSE_OR_REMOVE,
	_map_id_halo3_epilogue,
	_map_id_halo3odst_prepare_to_drop,
	_map_id_halo3odst_mombasa_streets,
	_map_id_halo3odst_tayari_plaza,
	_map_id_halo3odst_uplift_reserve,
	_map_id_halo3odst_kizingo_boulevard,
	_map_id_halo3odst_oni_alpha_site,
	_map_id_halo3odst_nmpd_hq,
	_map_id_halo3odst_kikowani_station,
	_map_id_halo3odst_data_hive,
	_map_id_halo3odst_coastal_highway,
	_map_id_halo3odst_epilogue,
	_map_id_groundhog_relic,
	_map_id_haloreach_noble_actual,
	_map_id_haloreach_winter_contingency,
	_map_id_haloreach_oni_sword_base,
	_map_id_haloreach_nightfall,
	_map_id_haloreach_tip_of_the_spear,
	_map_id_haloreach_long_night_of_solace,
	_map_id_haloreach_exodus,
	_map_id_haloreach_new_alexandria,
	_map_id_haloreach_the_package,
	_map_id_haloreach_the_pillar_of_autumn,
	_map_id_haloreach_the_pillar_of_autumn_credits,
	_map_id_haloreach_lone_wolf,
	_map_id_haloreach_boardwalk,
	_map_id_haloreach_boneyard,
	_map_id_haloreach_countdown,
	_map_id_haloreach_powerhouse,
	_map_id_haloreach_reflection,
	_map_id_haloreach_spire,
	_map_id_haloreach_sword_base,
	_map_id_haloreach_zealot,
	_map_id_haloreach_anchor_9,
	_map_id_haloreach_breakpoint,
	_map_id_haloreach_tempest,
	_map_id_haloreach_condemned,
	_map_id_haloreach_highlands,
	_map_id_haloreach_battle_canyon,
	_map_id_haloreach_penance,
	_map_id_haloreach_ridgeline,
	_map_id_haloreach_solitary,
	_map_id_haloreach_high_noon,
	_map_id_haloreach_breakneck,
	_map_id_haloreach_forge_world,
	_map_id_haloreach_beachhead,
	_map_id_haloreach_corvette,
	_map_id_haloreach_courtyard,
	_map_id_haloreach_glacier,
	_map_id_haloreach_holdout,
	_map_id_haloreach_outpost,
	_map_id_haloreach_overlook,
	_map_id_haloreach_waterfront,
	_map_id_haloreach_unearthed,
	_map_id_haloreach_installation_04,

	k_number_of_map_ids,
	_map_id_none = ~0u,
	_map_id_mainmenu = 0x10231971,
};

constexpr const char* map_id_to_string(e_map_id map_id)
{
	switch (map_id)
	{
	case _map_id_halo1_pillar_of_autumn:						return "_map_id_halo1_pillar_of_autumn";
	case _map_id_halo1_halo:									return "_map_id_halo1_halo";
	case _map_id_halo1_truth_and_reconciliation:				return "_map_id_halo1_truth_and_reconciliation";
	case _map_id_halo1_silent_cartographer:						return "_map_id_halo1_silent_cartographer";
	case _map_id_halo1_assault_on_the_control_room:				return "_map_id_halo1_assault_on_the_control_room";
	case _map_id_halo1_343_guilty_spark:						return "_map_id_halo1_343_guilty_spark";
	case _map_id_halo1_the_library:								return "_map_id_halo1_the_library";
	case _map_id_halo1_two_betrayals:							return "_map_id_halo1_two_betrayals";
	case _map_id_halo1_keyes:									return "_map_id_halo1_keyes";
	case _map_id_halo1_the_maw:									return "_map_id_halo1_the_maw";
	case _map_id_halo1_battle_creek:							return "_map_id_halo1_battle_creek";
	case _map_id_halo1_sidewinder:								return "_map_id_halo1_sidewinder";
	case _map_id_halo1_damnation:								return "_map_id_halo1_damnation";
	case _map_id_halo1_rat_race:								return "_map_id_halo1_rat_race";
	case _map_id_halo1_prisoner:								return "_map_id_halo1_prisoner";
	case _map_id_halo1_hang_em_high:							return "_map_id_halo1_hang_em_high";
	case _map_id_halo1_chill_out:								return "_map_id_halo1_chill_out";
	case _map_id_halo1_derelict:								return "_map_id_halo1_derelict";
	case _map_id_halo1_boarding_action:							return "_map_id_halo1_boarding_action";
	case _map_id_halo1_chiron:									return "_map_id_halo1_chiron";
	case _map_id_halo1_blood_gulch:								return "_map_id_halo1_blood_gulch";
	case _map_id_halo1_wizard:									return "_map_id_halo1_wizard";
	case _map_id_halo1_longest:									return "_map_id_halo1_longest";
	case _map_id_halo1_death_island:							return "_map_id_halo1_death_island";
	case _map_id_halo1_danger_canyon:							return "_map_id_halo1_danger_canyon";
	case _map_id_halo1_infinity:								return "_map_id_halo1_infinity";
	case _map_id_halo1_timberland:								return "_map_id_halo1_timberland";
	case _map_id_halo1_ice_fields:								return "_map_id_halo1_ice_fields";
	case _map_id_halo1_gephyrophobia:							return "_map_id_halo1_gephyrophobia";
	case _map_id_halo2_the_heretic:								return "_map_id_halo2_the_heretic";
	case _map_id_halo2_the_armory:								return "_map_id_halo2_the_armory";
	case _map_id_halo2_cairo_station:							return "_map_id_halo2_cairo_station";
	case _map_id_halo2_outskirts:								return "_map_id_halo2_outskirts";
	case _map_id_halo2_metropolis:								return "_map_id_halo2_metropolis";
	case _map_id_halo2_the_arbiter:								return "_map_id_halo2_the_arbiter";
	case _map_id_halo2_the_oracle:								return "_map_id_halo2_the_oracle";
	case _map_id_halo2_delta_halo:								return "_map_id_halo2_delta_halo";
	case _map_id_halo2_regret:									return "_map_id_halo2_regret";
	case _map_id_halo2_sacred_icon:								return "_map_id_halo2_sacred_icon";
	case _map_id_halo2_quarantine_zone:							return "_map_id_halo2_quarantine_zone";
	case _map_id_halo2_gravemind:								return "_map_id_halo2_gravemind";
	case _map_id_halo2_uprising:								return "_map_id_halo2_uprising";
	case _map_id_halo2_high_charity:							return "_map_id_halo2_high_charity";
	case _map_id_halo2_the_great_journey:						return "_map_id_halo2_the_great_journey";
	case _map_id_halo2_lockout:									return "_map_id_halo2_lockout";
	case _map_id_halo2_ascension:								return "_map_id_halo2_ascension";
	case _map_id_halo2_midship:									return "_map_id_halo2_midship";
	case _map_id_halo2_ivory_tower:								return "_map_id_halo2_ivory_tower";
	case _map_id_halo2_beaver_creek:							return "_map_id_halo2_beaver_creek";
	case _map_id_halo2_burial_mounds:							return "_map_id_halo2_burial_mounds";
	case _map_id_halo2_colossus:								return "_map_id_halo2_colossus";
	case _map_id_halo2_zanzibar:								return "_map_id_halo2_zanzibar";
	case _map_id_halo2_coagulation:								return "_map_id_halo2_coagulation";
	case _map_id_halo2_headlong:								return "_map_id_halo2_headlong";
	case _map_id_halo2_waterworks:								return "_map_id_halo2_waterworks";
	case _map_id_halo2_foundation:								return "_map_id_halo2_foundation";
	case _map_id_halo2_containment:								return "_map_id_halo2_containment";
	case _map_id_halo2_warlock:									return "_map_id_halo2_warlock";
	case _map_id_halo2_sanctuary:								return "_map_id_halo2_sanctuary";
	case _map_id_halo2_turf:									return "_map_id_halo2_turf";
	case _map_id_halo2_backwash:								return "_map_id_halo2_backwash";
	case _map_id_halo2_elongation:								return "_map_id_halo2_elongation";
	case _map_id_halo2_gemini:									return "_map_id_halo2_gemini";
	case _map_id_halo2_relic:									return "_map_id_halo2_relic";
	case _map_id_halo2_terminal:								return "_map_id_halo2_terminal";
	case _map_id_halo2_desolation:								return "_map_id_halo2_desolation";
	case _map_id_halo2_tombstone:								return "_map_id_halo2_tombstone";
	case _map_id_halo2_district:								return "_map_id_halo2_district";
	case _map_id_halo2_uplift:									return "_map_id_halo2_uplift";
	case _map_id_halo3_arrival:									return "_map_id_halo3_arrival";
	case _map_id_halo3_sierra_117:								return "_map_id_halo3_sierra_117";
	case _map_id_halo3_crows_nest:								return "_map_id_halo3_crows_nest";
	case _map_id_halo3_tsavo_highway:							return "_map_id_halo3_tsavo_highway";
	case _map_id_halo3_the_storm:								return "_map_id_halo3_the_storm";
	case _map_id_halo3_floodgate:								return "_map_id_halo3_floodgate";
	case _map_id_halo3_the_ark:									return "_map_id_halo3_the_ark";
	case _map_id_halo3_the_covenant:							return "_map_id_halo3_the_covenant";
	case _map_id_halo3_cortana:									return "_map_id_halo3_cortana";
	case _map_id_halo3_halo:									return "_map_id_halo3_halo";
	case _map_id_halo3_construct:								return "_map_id_halo3_construct";
	case _map_id_halo3_epitaph:									return "_map_id_halo3_epitaph";
	case _map_id_halo3_guardian:								return "_map_id_halo3_guardian";
	case _map_id_halo3_high_ground:								return "_map_id_halo3_high_ground";
	case _map_id_halo3_isolation:								return "_map_id_halo3_isolation";
	case _map_id_halo3_last_resort:								return "_map_id_halo3_last_resort";
	case _map_id_halo3_narrows:									return "_map_id_halo3_narrows";
	case _map_id_halo3_sandtrap:								return "_map_id_halo3_sandtrap";
	case _map_id_halo3_snowbound:								return "_map_id_halo3_snowbound";
	case _map_id_halo3_the_pit:									return "_map_id_halo3_the_pit";
	case _map_id_halo3_valhalla:								return "_map_id_halo3_valhalla";
	case _map_id_halo3_foundry:									return "_map_id_halo3_foundry";
	case _map_id_halo3_rats_nest:								return "_map_id_halo3_rats_nest";
	case _map_id_halo3_standoff:								return "_map_id_halo3_standoff";
	case _map_id_halo3_avalanche:								return "_map_id_halo3_avalanche";
	case _map_id_halo3_blackout:								return "_map_id_halo3_blackout";
	case _map_id_halo3_ghost_town:								return "_map_id_halo3_ghost_town";
	case _map_id_halo3_cold_storage:							return "_map_id_halo3_cold_storage";
	case _map_id_halo3_assembly:								return "_map_id_halo3_assembly";
	case _map_id_halo3_orbital:									return "_map_id_halo3_orbital";
	case _map_id_halo3_sandbox:									return "_map_id_halo3_sandbox";
	case _map_id_halo3_citadel:									return "_map_id_halo3_citadel";
	case _map_id_halo3_heretic:									return "_map_id_halo3_heretic";
	case _map_id_halo3_longshore:								return "_map_id_halo3_longshore";
	case _map_id_halo4_prologue:								return "_map_id_halo4_prologue";
	case _map_id_halo4_dawn:									return "_map_id_halo4_dawn";
	case _map_id_halo4_requiem:									return "_map_id_halo4_requiem";
	case _map_id_halo4_forerunner:								return "_map_id_halo4_forerunner";
	case _map_id_halo4_infinity:								return "_map_id_halo4_infinity";
	case _map_id_halo4_reclaimer:								return "_map_id_halo4_reclaimer";
	case _map_id_halo4_shutdown:								return "_map_id_halo4_shutdown";
	case _map_id_halo4_composer:								return "_map_id_halo4_composer";
	case _map_id_halo4_midnight:								return "_map_id_halo4_midnight";
	case _map_id_halo4_epilogue:								return "_map_id_halo4_epilogue";
	case _map_id_halo4_multiplayer_first_DONOTUSE_OR_REMOVE:	return "_map_id_halo4_multiplayer_first_DONOTUSE_OR_REMOVE";
	case _map_id_halo4_adrift:									return "_map_id_halo4_adrift";
	case _map_id_halo4_abandon:									return "_map_id_halo4_abandon";
	case _map_id_halo4_complex:									return "_map_id_halo4_complex";
	case _map_id_halo4_exile:									return "_map_id_halo4_exile";
	case _map_id_halo4_haven:									return "_map_id_halo4_haven";
	case _map_id_halo4_longbow:									return "_map_id_halo4_longbow";
	case _map_id_halo4_meltdown:								return "_map_id_halo4_meltdown";
	case _map_id_halo4_ragnarok:								return "_map_id_halo4_ragnarok";
	case _map_id_halo4_solace:									return "_map_id_halo4_solace";
	case _map_id_halo4_vortex:									return "_map_id_halo4_vortex";
	case _map_id_halo4_ravine:									return "_map_id_halo4_ravine";
	case _map_id_halo4_impact:									return "_map_id_halo4_impact";
	case _map_id_halo4_erosion:									return "_map_id_halo4_erosion";
	case _map_id_halo4_forge_island:							return "_map_id_halo4_forge_island";
	case _map_id_halo4_wreckage:								return "_map_id_halo4_wreckage";
	case _map_id_halo4_harvest:									return "_map_id_halo4_harvest";
	case _map_id_halo4_shatter:									return "_map_id_halo4_shatter";
	case _map_id_halo4_landfall:								return "_map_id_halo4_landfall";
	case _map_id_halo4_monolith:								return "_map_id_halo4_monolith";
	case _map_id_halo4_skyline:									return "_map_id_halo4_skyline";
	case _map_id_halo4_daybreak:								return "_map_id_halo4_daybreak";
	case _map_id_halo4_outcast:									return "_map_id_halo4_outcast";
	case _map_id_halo4_perdition:								return "_map_id_halo4_perdition";
	case _map_id_halo4_pitfall:									return "_map_id_halo4_pitfall";
	case _map_id_halo4_vertigo:									return "_map_id_halo4_vertigo";
	case _map_id_halo4_spartan_ops_first_DONOTUSE_OR_REMOVE:	return "_map_id_halo4_spartan_ops_first_DONOTUSE_OR_REMOVE";
	case _map_id_halo4_ff_chopperbowl:							return "_map_id_halo4_ff_chopperbowl";
	case _map_id_halo4_ff_sniperalley:							return "_map_id_halo4_ff_sniperalley";
	case _map_id_halo4_ff_fortsw:								return "_map_id_halo4_ff_fortsw";
	case _map_id_halo4_ff_temple:								return "_map_id_halo4_ff_temple";
	case _map_id_halo4_ff_scurve:								return "_map_id_halo4_ff_scurve";
	case _map_id_halo4_ff_courtyard:							return "_map_id_halo4_ff_courtyard";
	case _map_id_halo4_ff_complex:								return "_map_id_halo4_ff_complex";
	case _map_id_halo4_ff_valhalla:								return "_map_id_halo4_ff_valhalla";
	case _map_id_halo4_ff_factory:								return "_map_id_halo4_ff_factory";
	case _map_id_halo4_ff_mezzanie:								return "_map_id_halo4_ff_mezzanie";
	case _map_id_halo4_ff_caverns:								return "_map_id_halo4_ff_caverns";
	case _map_id_halo4_ff_vortex:								return "_map_id_halo4_ff_vortex";
	case _map_id_halo4_ff_breach:								return "_map_id_halo4_ff_breach";
	case _map_id_halo4_ff_hillside:								return "_map_id_halo4_ff_hillside";
	case _map_id_halo4_ff_engine:								return "_map_id_halo4_ff_engine";
	case _map_id_groundhog_lockout:								return "_map_id_groundhog_lockout";
	case _map_id_groundhog_ascension:							return "_map_id_groundhog_ascension";
	case _map_id_groundhog_zanzibar:							return "_map_id_groundhog_zanzibar";
	case _map_id_groundhog_coagulation:							return "_map_id_groundhog_coagulation";
	case _map_id_groundhog_warlock:								return "_map_id_groundhog_warlock";
	case _map_id_groundhog_sanctuary:							return "_map_id_groundhog_sanctuary";
	case _map_id_groundhog_forge_skybox01:						return "_map_id_groundhog_forge_skybox01";
	case _map_id_groundhog_forge_skybox02:						return "_map_id_groundhog_forge_skybox02";
	case _map_id_groundhog_forge_skybox03:						return "_map_id_groundhog_forge_skybox03";
	case _map_id_halo3_extracredit_first_DONOTUSE_OR_REMOVE:	return "_map_id_halo3_extracredit_first_DONOTUSE_OR_REMOVE";
	case _map_id_halo3_epilogue:								return "_map_id_halo3_epilogue";
	case _map_id_halo3odst_prepare_to_drop:						return "_map_id_halo3odst_prepare_to_drop";
	case _map_id_halo3odst_mombasa_streets:						return "_map_id_halo3odst_mombasa_streets";
	case _map_id_halo3odst_tayari_plaza:						return "_map_id_halo3odst_tayari_plaza";
	case _map_id_halo3odst_uplift_reserve:						return "_map_id_halo3odst_uplift_reserve";
	case _map_id_halo3odst_kizingo_boulevard:					return "_map_id_halo3odst_kizingo_boulevard";
	case _map_id_halo3odst_oni_alpha_site:						return "_map_id_halo3odst_oni_alpha_site";
	case _map_id_halo3odst_nmpd_hq:								return "_map_id_halo3odst_nmpd_hq";
	case _map_id_halo3odst_kikowani_station:					return "_map_id_halo3odst_kikowani_station";
	case _map_id_halo3odst_data_hive:							return "_map_id_halo3odst_data_hive";
	case _map_id_halo3odst_coastal_highway:						return "_map_id_halo3odst_coastal_highway";
	case _map_id_halo3odst_epilogue:							return "_map_id_halo3odst_epilogue";
	case _map_id_groundhog_relic:								return "_map_id_groundhog_relic";
	case _map_id_haloreach_noble_actual:						return "_map_id_haloreach_noble_actual";
	case _map_id_haloreach_winter_contingency:					return "_map_id_haloreach_winter_contingency";
	case _map_id_haloreach_oni_sword_base:						return "_map_id_haloreach_oni_sword_base";
	case _map_id_haloreach_nightfall:							return "_map_id_haloreach_nightfall";
	case _map_id_haloreach_tip_of_the_spear:					return "_map_id_haloreach_tip_of_the_spear";
	case _map_id_haloreach_long_night_of_solace:				return "_map_id_haloreach_long_night_of_solace";
	case _map_id_haloreach_exodus:								return "_map_id_haloreach_exodus";
	case _map_id_haloreach_new_alexandria:						return "_map_id_haloreach_new_alexandria";
	case _map_id_haloreach_the_package:							return "_map_id_haloreach_the_package";
	case _map_id_haloreach_the_pillar_of_autumn:				return "_map_id_haloreach_the_pillar_of_autumn";
	case _map_id_haloreach_the_pillar_of_autumn_credits:		return "_map_id_haloreach_the_pillar_of_autumn_credits";
	case _map_id_haloreach_lone_wolf:							return "_map_id_haloreach_lone_wolf";
	case _map_id_haloreach_boardwalk:							return "_map_id_haloreach_boardwalk";
	case _map_id_haloreach_boneyard:							return "_map_id_haloreach_boneyard";
	case _map_id_haloreach_countdown:							return "_map_id_haloreach_countdown";
	case _map_id_haloreach_powerhouse:							return "_map_id_haloreach_powerhouse";
	case _map_id_haloreach_reflection:							return "_map_id_haloreach_reflection";
	case _map_id_haloreach_spire:								return "_map_id_haloreach_spire";
	case _map_id_haloreach_sword_base:							return "_map_id_haloreach_sword_base";
	case _map_id_haloreach_zealot:								return "_map_id_haloreach_zealot";
	case _map_id_haloreach_anchor_9:							return "_map_id_haloreach_anchor_9";
	case _map_id_haloreach_breakpoint:							return "_map_id_haloreach_breakpoint";
	case _map_id_haloreach_tempest:								return "_map_id_haloreach_tempest";
	case _map_id_haloreach_condemned:							return "_map_id_haloreach_condemned";
	case _map_id_haloreach_highlands:							return "_map_id_haloreach_highlands";
	case _map_id_haloreach_battle_canyon:						return "_map_id_haloreach_battle_canyon";
	case _map_id_haloreach_penance:								return "_map_id_haloreach_penance";
	case _map_id_haloreach_ridgeline:							return "_map_id_haloreach_ridgeline";
	case _map_id_haloreach_solitary:							return "_map_id_haloreach_solitary";
	case _map_id_haloreach_high_noon:							return "_map_id_haloreach_high_noon";
	case _map_id_haloreach_breakneck:							return "_map_id_haloreach_breakneck";
	case _map_id_haloreach_forge_world:							return "_map_id_haloreach_forge_world";
	case _map_id_haloreach_beachhead:							return "_map_id_haloreach_beachhead";
	case _map_id_haloreach_corvette:							return "_map_id_haloreach_corvette";
	case _map_id_haloreach_courtyard:							return "_map_id_haloreach_courtyard";
	case _map_id_haloreach_glacier:								return "_map_id_haloreach_glacier";
	case _map_id_haloreach_holdout:								return "_map_id_haloreach_holdout";
	case _map_id_haloreach_outpost:								return "_map_id_haloreach_outpost";
	case _map_id_haloreach_overlook:							return "_map_id_haloreach_overlook";
	case _map_id_haloreach_waterfront:							return "_map_id_haloreach_waterfront";
	case _map_id_haloreach_unearthed:							return "_map_id_haloreach_unearthed";
	case _map_id_haloreach_installation_04:						return "_map_id_haloreach_installation_04";
	case _map_id_mainmenu:										return "_map_id_mainmenu";
	case _map_id_none:											return "_map_id_none";
	}
	return nullptr;
}

static inline e_map_id string_to_map_id(const char* map_id_string)
{
	if (strcmp(map_id_string, map_id_to_string(_map_id_mainmenu)))
	{
		return _map_id_mainmenu;
	}

	for (underlying(e_map_id) current_map_id = 0; current_map_id < k_number_of_map_ids; current_map_id++)
	{
		const char* current_map_id_string = map_id_to_string(static_cast<e_map_id>(current_map_id));

		if (strcmp(current_map_id_string, map_id_string) == 0)
		{
			return static_cast<e_map_id>(current_map_id);
		}
	}
	return _map_id_none;
}

// #TODO: move this some `e_engine_type` is available
long map_id_to_engine_type(e_map_id map_id);

// #TODO: move this some `e_mcc_game_mode` is available
long map_id_to_game_mode(e_map_id map_id);
