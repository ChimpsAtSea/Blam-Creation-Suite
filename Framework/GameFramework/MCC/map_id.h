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

template<typename string_type, bool pretty_string>
constexpr string_type get_enum_string(e_map_id map_id)
{
	enum_string_ex(string_type, pretty_string, map_id, _map_id_mainmenu, "Mainmenu");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_none, "None");

	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_pillar_of_autumn, "Pillar of Autumn");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_halo, "Halo");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_truth_and_reconciliation, "Truth and Reconciliation");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_silent_cartographer, "Silent Cartographer");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_assault_on_the_control_room, "Assault on the Control Room");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_343_guilty_spark, "343 Guilty Spark");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_the_library, "The Library");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_two_betrayals, "Two Betrayals");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_keyes, "Keyes");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_the_maw, "The Maw");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_battle_creek, "Battle Creek");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_sidewinder, "Sidewinder");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_damnation, "Damnation");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_rat_race, "Rat Race");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_prisoner, "Prisoner");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_hang_em_high, "Hang 'em High");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_chill_out, "Chill Out");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_derelict, "Derelict");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_boarding_action, "Boarding Action");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_chiron, "Chiron");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_blood_gulch, "Blood Gulch");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_wizard, "Wizard");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_longest, "Longest");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_death_island, "Death Island");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_danger_canyon, "Danger Canyon");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_infinity, "Infinity");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_timberland, "Timberland");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_ice_fields, "Ice Fields");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo1_gephyrophobia, "Gephyrophobia");

	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_the_heretic, "The Heretic");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_the_armory, "The Armory");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_cairo_station, "Cairo Station");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_outskirts, "Outskirts");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_metropolis, "Metropolis");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_the_arbiter, "The Arbiter");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_the_oracle, "The Oracle");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_delta_halo, "Delta Halo");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_regret, "Regret");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_sacred_icon, "Sacred Icon");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_quarantine_zone, "Quarantine Zone");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_gravemind, "Gravemind");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_uprising, "Uprising");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_high_charity, "High Charity");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_the_great_journey, "The Great Journey");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_lockout, "Lockout");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_ascension, "Ascension");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_midship, "Midship");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_ivory_tower, "Ivory Tower");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_beaver_creek, "Beaver Creek");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_burial_mounds, "Burial Mounds");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_colossus, "Colossus");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_zanzibar, "Zanzibar");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_coagulation, "Coagulation");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_headlong, "Headlong");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_waterworks, "Waterworks");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_foundation, "Foundation");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_containment, "Containment");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_warlock, "Warlock");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_sanctuary, "Sanctuary");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_turf, "Turf");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_backwash, "Backwash");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_elongation, "Elongation");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_gemini, "Gemini");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_relic, "Relic");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_terminal, "Terminal");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_desolation, "Desolation");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_tombstone, "Tombstone");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_district, "District");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo2_uplift, "Uplift");

	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_arrival, "Arrival");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_sierra_117, "Sierra 117");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_crows_nest, "Crows Nest");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_tsavo_highway, "Tsavo Highway");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_the_storm, "The Storm");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_floodgate, "Floodgate");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_the_ark, "The Ark");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_the_covenant, "The Covenant");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_cortana, "Cortana");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_halo, "Calo");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_extracredit_first_DONOTUSE_OR_REMOVE, "Extracredit First DONOTUSE_OR_REMOVE");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_epilogue, "Epilogue");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_construct, "Construct");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_epitaph, "Epitaph");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_guardian, "Guardian");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_high_ground, "High Ground");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_isolation, "Isolation");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_last_resort, "Last Resort");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_narrows, "Narrows");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_sandtrap, "Sandtrap");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_snowbound, "Snowbound");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_the_pit, "The Pit");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_valhalla, "Valhalla");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_foundry, "Foundry");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_rats_nest, "Rat's Nest");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_standoff, "Standoff");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_avalanche, "Avalanche");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_blackout, "Blackout");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_ghost_town, "Ghost Town");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_cold_storage, "Cold Storage");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_assembly, "Assembly");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_orbital, "Orbital");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_sandbox, "Sandbox");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_citadel, "Citadel");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_heretic, "Heretic");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3_longshore, "Longshore");

	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_prepare_to_drop, "Prepare to Drop");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_mombasa_streets, "Mombasa Streets");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_tayari_plaza, "Tayari Plaza");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_uplift_reserve, "Uplift Reserve");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_kizingo_boulevard, "Kizingo Boulevard");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_oni_alpha_site, "Oni Alpha Site");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_nmpd_hq, "NMPD HQ");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_kikowani_station, "Kikowani Station");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_data_hive, "Data Hive");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_coastal_highway, "Coastal Highway");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo3odst_epilogue, "Epilogue");

	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_noble_actual, "Noble Actual");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_winter_contingency, "Winter Contingency");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_oni_sword_base, "Oni Sword Base");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_nightfall, "Nightfall");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_tip_of_the_spear, "Tip of the Spear");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_long_night_of_solace, "Long Night of Solace");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_exodus, "Exodus");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_new_alexandria, "New Alexandria");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_the_package, "The Package");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_the_pillar_of_autumn, "The Pillar of Autumn");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_the_pillar_of_autumn_credits, "The Pillar of Autumn Credits");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_lone_wolf, "Lone Wolf");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_boardwalk, "Boardwalk");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_boneyard, "Boneyard");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_countdown, "Countdown");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_powerhouse, "Powerhouse");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_reflection, "Reflection");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_spire, "Spire");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_sword_base, "Sword Base");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_zealot, "Zealot");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_anchor_9, "Anchor 9");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_breakpoint, "Breakpoint");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_tempest, "Tempest");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_condemned, "Condemned");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_highlands, "Highlands");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_battle_canyon, "Battle Canyon");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_penance, "Penance");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_ridgeline, "Ridgeline");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_solitary, "Solitary");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_high_noon, "Nigh Noon");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_breakneck, "Breakneck");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_forge_world, "Forge World");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_beachhead, "Beachhead");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_corvette, "Corvette");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_courtyard, "Courtyard");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_glacier, "Glacier");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_holdout, "Holdout");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_outpost, "Outpost");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_overlook, "Overlook");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_waterfront, "Waterfront");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_unearthed, "Unearthed");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_haloreach_installation_04, "Installation 04");

	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_prologue, "Prologue");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_dawn, "Dawn");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_requiem, "Requiem");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_forerunner, "Forerunner");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_infinity, "Infinity");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_reclaimer, "reclaimer");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_shutdown, "Shutdown");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_composer, "Composer");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_midnight, "Midnight");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_epilogue, "Epilogue");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_multiplayer_first_DONOTUSE_OR_REMOVE, "Multiplayer First DONOTUSE_OR_REMOVE");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_adrift, "Adrift");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_abandon, "Abandon");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_complex, "Vomplex");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_exile, "Exile");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_haven, "Haven");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_longbow, "Longbow");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_meltdown, "Meltdown");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ragnarok, "Ragnarok");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_solace, "Solace");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_vortex, "Vortex");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ravine, "Ravine");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_impact, "Impact");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_erosion, "Erosion");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_forge_island, "Forge Island");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_wreckage, "Wreckage");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_harvest, "Harvest");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_shatter, "Shatter");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_landfall, "Landfall");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_monolith, "Monolith");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_skyline, "Skyline");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_daybreak, "Daybreak");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_outcast, "Outcast");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_perdition, "Perdition");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_pitfall, "Pitfall");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_vertigo, "Vertigo");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_spartan_ops_first_DONOTUSE_OR_REMOVE, "Spartan Ops First DONOTUSE_OR_REMOVE");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_chopperbowl, "Chopperbowl");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_sniperalley, "Sniperalley");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_fortsw, "Fortsw");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_temple, "Temple");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_scurve, "Scurve");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_courtyard, "Courtyard");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_complex, "Complex");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_valhalla, "Valhalla");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_factory, "Factory");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_mezzanie, "Mezzanie");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_caverns, "Caverns");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_vortex, "Vortex");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_breach, "Breach");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_hillside, "Hillside");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_halo4_ff_engine, "Engine");

	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_lockout, "Lockout");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_ascension, "Ascension");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_zanzibar, "Zanzibar");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_coagulation, "Coagulation");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_warlock, "Warlock");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_sanctuary, "Sanctuary");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_forge_skybox01, "Forge Skybox01");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_forge_skybox02, "Forge Skybox02");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_forge_skybox03, "Forge Skybox03");
	enum_string_ex(string_type, pretty_string, map_id, _map_id_groundhog_relic, "Relic");
	return nullptr;
}

static inline e_map_id string_to_map_id(const char* map_id_string)
{
	if (strcmp(map_id_string, get_enum_string<const char*>(_map_id_mainmenu)))
	{
		return _map_id_mainmenu;
	}

	for (underlying(e_map_id) current_map_id = 0; current_map_id < k_number_of_map_ids; current_map_id++)
	{
		const char* current_map_id_string = get_enum_string<const char*>(static_cast<e_map_id>(current_map_id));

		if (strcmp(current_map_id_string, map_id_string) == 0)
		{
			return static_cast<e_map_id>(current_map_id);
		}
	}
	return _map_id_none;
}

e_engine_type map_id_to_engine_type(e_map_id map_id);
e_mcc_game_mode map_id_to_game_mode(e_map_id map_id);
std::vector<signed int>& map_id_to_available_insertion_points(long map_id, bool is_firefight);