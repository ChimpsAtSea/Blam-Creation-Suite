#pragma once

enum e_damage_reporting_type : uint32_t
{
	_damage_reporting_type_invalid,
	_damage_reporting_type_known_guardians,
	_damage_reporting_type_scripting,
	_damage_reporting_type_ai_suicide,
	_damage_reporting_type_forerunner_smg,
	_damage_reporting_type_spread_gun,
	_damage_reporting_type_forerunner_rifle,
	_damage_reporting_type_forerunner_sniper,
	_damage_reporting_type_bishop_beam,
	_damage_reporting_type_bolt_pistol,
	_damage_reporting_type_pulse_grenade,
	_damage_reporting_type_incineration_launcher,
	_damage_reporting_type_magnum_pistol,
	_damage_reporting_type_assault_rifle,
	_damage_reporting_type_marksman_rifle,
	_damage_reporting_type_shotgun,
	_damage_reporting_type_battle_rifle,
	_damage_reporting_type_sniper_rifle,
	_damage_reporting_type_rocket_launcher,
	_damage_reporting_type_spartan_laser,
	_damage_reporting_type_frag_grenade,
	_damage_reporting_type_sticky_grenade_launcher,
	_damage_reporting_type_light_machine_gun,
	_damage_reporting_type_rail_gun,
	_damage_reporting_type_plasma_pistol,
	_damage_reporting_type_needler,
	_damage_reporting_type_gravity_hammer,
	_damage_reporting_type_energy_blade,
	_damage_reporting_type_plasma_grenade,
	_damage_reporting_type_carbine,
	_damage_reporting_type_beam_rifle,
	_damage_reporting_type_assault_carbine,
	_damage_reporting_type_concussion_rifle,
	_damage_reporting_type_fuel_rod_cannon,
	_damage_reporting_type_ghost,
	_damage_reporting_type_revenant_driver,
	_damage_reporting_type_revenant_gunner,
	_damage_reporting_type_wraith,
	_damage_reporting_type_wraith_antiinfantry,
	_damage_reporting_type_banshee,
	_damage_reporting_type_banshee_bomb,
	_damage_reporting_type_seraph,
	_damage_reporting_type_revenant_deux_driver,
	_damage_reporting_type_revenant_deux_gunner,
	_damage_reporting_type_lich_driver,
	_damage_reporting_type_lich_gunner,
	_damage_reporting_type_mongoose,
	_damage_reporting_type_warthog_driver,
	_damage_reporting_type_warthog_gunner,
	_damage_reporting_type_warthog_gunner_gauss,
	_damage_reporting_type_warthog_gunner_rocket,
	_damage_reporting_type_scorpion,
	_damage_reporting_type_scorpion_gunner,
	_damage_reporting_type_falcon_driver,
	_damage_reporting_type_falcon_gunner,
	_damage_reporting_type_wasp_driver,
	_damage_reporting_type_wasp_gunner,
	_damage_reporting_type_wasp_gunner_heavy,
	_damage_reporting_type_mech_melee,
	_damage_reporting_type_mech_chaingun,
	_damage_reporting_type_mech_cannon,
	_damage_reporting_type_mech_rocket,
	_damage_reporting_type_broadsword,
	_damage_reporting_type_broadsword_missile,
	_damage_reporting_type_tortoise_driver,
	_damage_reporting_type_tortoise_gunner,
	_damage_reporting_type_MAC_cannon,
	_damage_reporting_type_target_designator,
	_damage_reporting_type_drop_pod,
	_damage_reporting_type_cruise_missile,
	_damage_reporting_type_portable_shield,
	_damage_reporting_type_personal_auto_turret,
	_damage_reporting_type_thruster_pack,
	_damage_reporting_type_falling_damage,
	_damage_reporting_type_collision_damage,
	_damage_reporting_type_melee,
	_damage_reporting_type_explosion,
	_damage_reporting_type_fire,
	_damage_reporting_type_birthday_party_explosion,
	_damage_reporting_type_flag,
	_damage_reporting_type_bomb,
	_damage_reporting_type_bomb_explosion,
	_damage_reporting_type_ball,
	_damage_reporting_type_teleporter,
	_damage_reporting_type_transfer_damage,
	_damage_reporting_type_armor_lock_crush,
	_damage_reporting_type_human_turret,
	_damage_reporting_type_plasma_cannon,
	_damage_reporting_type_plasma_mortar,
	_damage_reporting_type_plasma_turret,
	_damage_reporting_type_shade_turret,
	_damage_reporting_type_forerunner_turret,
	_damage_reporting_type_tank,
	_damage_reporting_type_chopper,
	_damage_reporting_type_hornet,
	_damage_reporting_type_mantis,
	_damage_reporting_type_ctf_magnum_pistol,
	_damage_reporting_type_flood_prongs,
	_damage_reporting_type_plasma_rifle,
	_damage_reporting_type_brute_plasma_rifle,
	_damage_reporting_type_flak_cannon,
	_damage_reporting_type_brute_shot,
	_damage_reporting_type_disintegrator,
	_damage_reporting_type_sentinel_beam,
	_damage_reporting_type_spectre_driver,
	_damage_reporting_type_spectre_gunner,
	_damage_reporting_type_smg,
	_damage_reporting_type_flamethrower,
	_damage_reporting_type_smg_s,
	_damage_reporting_type_gungoose_gun,
	_damage_reporting_type_hornet_gun,
	_damage_reporting_type_hornet_rocket,
	_damage_reporting_type_excavator,
	_damage_reporting_type_spike_rifle,
	_damage_reporting_type_missle_launcher,
	_damage_reporting_type_sentinal_gun,
	_damage_reporting_type_claymore_grenade,
	_damage_reporting_type_firebomb_grenade,
	_damage_reporting_type_mauler,
	_damage_reporting_type_sentinel_rpg,
	_damage_reporting_type_proximity_mine,
	_damage_reporting_type_elephant_turret,
	_damage_reporting_type_mammoth_turret,
	_damage_reporting_type_pelican,
	_damage_reporting_type_grenade_launcher,
	_damage_reporting_type_plasma_repeater,
	_damage_reporting_type_needle_rifle,
	_damage_reporting_type_plasma_launcher,
	_damage_reporting_type_focus_rifle,
	_damage_reporting_type_airstrike,
	_damage_reporting_type_golf_club,
	_damage_reporting_type_sabre,
	k_number_of_damage_reporting_types
};

constexpr const char* damage_reporting_type_to_string(e_damage_reporting_type damage_reporting_type)
{
	switch (damage_reporting_type)
	{
	case _damage_reporting_type_invalid:					return "_damage_reporting_type_invalid";
	case _damage_reporting_type_known_guardians:			return "_damage_reporting_type_known_guardians";
	case _damage_reporting_type_scripting:					return "_damage_reporting_type_scripting";
	case _damage_reporting_type_ai_suicide:					return "_damage_reporting_type_ai_suicide";
	case _damage_reporting_type_forerunner_smg:				return "_damage_reporting_type_forerunner_smg";
	case _damage_reporting_type_spread_gun:					return "_damage_reporting_type_spread_gun";
	case _damage_reporting_type_forerunner_rifle:			return "_damage_reporting_type_forerunner_rifle";
	case _damage_reporting_type_forerunner_sniper:			return "_damage_reporting_type_forerunner_sniper";
	case _damage_reporting_type_bishop_beam:				return "_damage_reporting_type_bishop_beam";
	case _damage_reporting_type_bolt_pistol:				return "_damage_reporting_type_bolt_pistol";
	case _damage_reporting_type_pulse_grenade:				return "_damage_reporting_type_pulse_grenade";
	case _damage_reporting_type_incineration_launcher:		return "_damage_reporting_type_incineration_launcher";
	case _damage_reporting_type_magnum_pistol:				return "_damage_reporting_type_magnum_pistol";
	case _damage_reporting_type_assault_rifle:				return "_damage_reporting_type_assault_rifle";
	case _damage_reporting_type_marksman_rifle:				return "_damage_reporting_type_marksman_rifle";
	case _damage_reporting_type_shotgun:					return "_damage_reporting_type_shotgun";
	case _damage_reporting_type_battle_rifle:				return "_damage_reporting_type_battle_rifle";
	case _damage_reporting_type_sniper_rifle:				return "_damage_reporting_type_sniper_rifle";
	case _damage_reporting_type_rocket_launcher:			return "_damage_reporting_type_rocket_launcher";
	case _damage_reporting_type_spartan_laser:				return "_damage_reporting_type_spartan_laser";
	case _damage_reporting_type_frag_grenade:				return "_damage_reporting_type_frag_grenade";
	case _damage_reporting_type_sticky_grenade_launcher:	return "_damage_reporting_type_sticky_grenade_launcher";
	case _damage_reporting_type_light_machine_gun:			return "_damage_reporting_type_light_machine_gun";
	case _damage_reporting_type_rail_gun:					return "_damage_reporting_type_rail_gun";
	case _damage_reporting_type_plasma_pistol:				return "_damage_reporting_type_plasma_pistol";
	case _damage_reporting_type_needler:					return "_damage_reporting_type_needler";
	case _damage_reporting_type_gravity_hammer:				return "_damage_reporting_type_gravity_hammer";
	case _damage_reporting_type_energy_blade:				return "_damage_reporting_type_energy_blade";
	case _damage_reporting_type_plasma_grenade:				return "_damage_reporting_type_plasma_grenade";
	case _damage_reporting_type_carbine:					return "_damage_reporting_type_carbine";
	case _damage_reporting_type_beam_rifle:					return "_damage_reporting_type_beam_rifle";
	case _damage_reporting_type_assault_carbine:			return "_damage_reporting_type_assault_carbine";
	case _damage_reporting_type_concussion_rifle:			return "_damage_reporting_type_concussion_rifle";
	case _damage_reporting_type_fuel_rod_cannon:			return "_damage_reporting_type_fuel_rod_cannon";
	case _damage_reporting_type_ghost:						return "_damage_reporting_type_ghost";
	case _damage_reporting_type_revenant_driver:			return "_damage_reporting_type_revenant_driver";
	case _damage_reporting_type_revenant_gunner:			return "_damage_reporting_type_revenant_gunner";
	case _damage_reporting_type_wraith:						return "_damage_reporting_type_wraith";
	case _damage_reporting_type_wraith_antiinfantry:		return "_damage_reporting_type_wraith_antiinfantry";
	case _damage_reporting_type_banshee:					return "_damage_reporting_type_banshee";
	case _damage_reporting_type_banshee_bomb:				return "_damage_reporting_type_banshee_bomb";
	case _damage_reporting_type_seraph:						return "_damage_reporting_type_seraph";
	case _damage_reporting_type_revenant_deux_driver:		return "_damage_reporting_type_revenant_deux_driver";
	case _damage_reporting_type_revenant_deux_gunner:		return "_damage_reporting_type_revenant_deux_gunner";
	case _damage_reporting_type_lich_driver:				return "_damage_reporting_type_lich_driver";
	case _damage_reporting_type_lich_gunner:				return "_damage_reporting_type_lich_gunner";
	case _damage_reporting_type_mongoose:					return "_damage_reporting_type_mongoose";
	case _damage_reporting_type_warthog_driver:				return "_damage_reporting_type_warthog_driver";
	case _damage_reporting_type_warthog_gunner:				return "_damage_reporting_type_warthog_gunner";
	case _damage_reporting_type_warthog_gunner_gauss:		return "_damage_reporting_type_warthog_gunner_gauss";
	case _damage_reporting_type_warthog_gunner_rocket:		return "_damage_reporting_type_warthog_gunner_rocket";
	case _damage_reporting_type_scorpion:					return "_damage_reporting_type_scorpion";
	case _damage_reporting_type_scorpion_gunner:			return "_damage_reporting_type_scorpion_gunner";
	case _damage_reporting_type_falcon_driver:				return "_damage_reporting_type_falcon_driver";
	case _damage_reporting_type_falcon_gunner:				return "_damage_reporting_type_falcon_gunner";
	case _damage_reporting_type_wasp_driver:				return "_damage_reporting_type_wasp_driver";
	case _damage_reporting_type_wasp_gunner:				return "_damage_reporting_type_wasp_gunner";
	case _damage_reporting_type_wasp_gunner_heavy:			return "_damage_reporting_type_wasp_gunner_heavy";
	case _damage_reporting_type_mech_melee:					return "_damage_reporting_type_mech_melee";
	case _damage_reporting_type_mech_chaingun:				return "_damage_reporting_type_mech_chaingun";
	case _damage_reporting_type_mech_cannon:				return "_damage_reporting_type_mech_cannon";
	case _damage_reporting_type_mech_rocket:				return "_damage_reporting_type_mech_rocket";
	case _damage_reporting_type_broadsword:					return "_damage_reporting_type_broadsword";
	case _damage_reporting_type_broadsword_missile:			return "_damage_reporting_type_broadsword_missile";
	case _damage_reporting_type_tortoise_driver:			return "_damage_reporting_type_tortoise_driver";
	case _damage_reporting_type_tortoise_gunner:			return "_damage_reporting_type_tortoise_gunner";
	case _damage_reporting_type_MAC_cannon:					return "_damage_reporting_type_MAC_cannon";
	case _damage_reporting_type_target_designator:			return "_damage_reporting_type_target_designator";
	case _damage_reporting_type_drop_pod:					return "_damage_reporting_type_drop_pod";
	case _damage_reporting_type_cruise_missile:				return "_damage_reporting_type_cruise_missile";
	case _damage_reporting_type_portable_shield:			return "_damage_reporting_type_portable_shield";
	case _damage_reporting_type_personal_auto_turret:		return "_damage_reporting_type_personal_auto_turret";
	case _damage_reporting_type_thruster_pack:				return "_damage_reporting_type_thruster_pack";
	case _damage_reporting_type_falling_damage:				return "_damage_reporting_type_falling_damage";
	case _damage_reporting_type_collision_damage:			return "_damage_reporting_type_collision_damage";
	case _damage_reporting_type_melee:						return "_damage_reporting_type_melee";
	case _damage_reporting_type_explosion:					return "_damage_reporting_type_explosion";
	case _damage_reporting_type_fire:						return "_damage_reporting_type_fire";
	case _damage_reporting_type_birthday_party_explosion:	return "_damage_reporting_type_birthday_party_explosion";
	case _damage_reporting_type_flag:						return "_damage_reporting_type_flag";
	case _damage_reporting_type_bomb:						return "_damage_reporting_type_bomb";
	case _damage_reporting_type_bomb_explosion:				return "_damage_reporting_type_bomb_explosion";
	case _damage_reporting_type_ball:						return "_damage_reporting_type_ball";
	case _damage_reporting_type_teleporter:					return "_damage_reporting_type_teleporter";
	case _damage_reporting_type_transfer_damage:			return "_damage_reporting_type_transfer_damage";
	case _damage_reporting_type_armor_lock_crush:			return "_damage_reporting_type_armor_lock_crush";
	case _damage_reporting_type_human_turret:				return "_damage_reporting_type_human_turret";
	case _damage_reporting_type_plasma_cannon:				return "_damage_reporting_type_plasma_cannon";
	case _damage_reporting_type_plasma_mortar:				return "_damage_reporting_type_plasma_mortar";
	case _damage_reporting_type_plasma_turret:				return "_damage_reporting_type_plasma_turret";
	case _damage_reporting_type_shade_turret:				return "_damage_reporting_type_shade_turret";
	case _damage_reporting_type_forerunner_turret:			return "_damage_reporting_type_forerunner_turret";
	case _damage_reporting_type_tank:						return "_damage_reporting_type_tank";
	case _damage_reporting_type_chopper:					return "_damage_reporting_type_chopper";
	case _damage_reporting_type_hornet:						return "_damage_reporting_type_hornet";
	case _damage_reporting_type_mantis:						return "_damage_reporting_type_mantis";
	case _damage_reporting_type_ctf_magnum_pistol:			return "_damage_reporting_type_ctf_magnum_pistol";
	case _damage_reporting_type_flood_prongs:				return "_damage_reporting_type_flood_prongs";
	case _damage_reporting_type_plasma_rifle:				return "_damage_reporting_type_plasma_rifle";
	case _damage_reporting_type_brute_plasma_rifle:			return "_damage_reporting_type_brute_plasma_rifle";
	case _damage_reporting_type_flak_cannon:				return "_damage_reporting_type_flak_cannon";
	case _damage_reporting_type_brute_shot:					return "_damage_reporting_type_brute_shot";
	case _damage_reporting_type_disintegrator:				return "_damage_reporting_type_disintegrator";
	case _damage_reporting_type_sentinel_beam:				return "_damage_reporting_type_sentinel_beam";
	case _damage_reporting_type_spectre_driver:				return "_damage_reporting_type_spectre_driver";
	case _damage_reporting_type_spectre_gunner:				return "_damage_reporting_type_spectre_gunner";
	case _damage_reporting_type_smg:						return "_damage_reporting_type_smg";
	case _damage_reporting_type_flamethrower:				return "_damage_reporting_type_flamethrower";
	case _damage_reporting_type_smg_s:						return "_damage_reporting_type_smg_s";
	case _damage_reporting_type_gungoose_gun:				return "_damage_reporting_type_gungoose_gun";
	case _damage_reporting_type_hornet_gun:					return "_damage_reporting_type_hornet_gun";
	case _damage_reporting_type_hornet_rocket:				return "_damage_reporting_type_hornet_rocket";
	case _damage_reporting_type_excavator:					return "_damage_reporting_type_excavator";
	case _damage_reporting_type_spike_rifle:				return "_damage_reporting_type_spike_rifle";
	case _damage_reporting_type_missle_launcher:			return "_damage_reporting_type_missle_launcher";
	case _damage_reporting_type_sentinal_gun:				return "_damage_reporting_type_sentinal_gun";
	case _damage_reporting_type_claymore_grenade:			return "_damage_reporting_type_claymore_grenade";
	case _damage_reporting_type_firebomb_grenade:			return "_damage_reporting_type_firebomb_grenade";
	case _damage_reporting_type_mauler:						return "_damage_reporting_type_mauler";
	case _damage_reporting_type_sentinel_rpg:				return "_damage_reporting_type_sentinel_rpg";
	case _damage_reporting_type_proximity_mine:				return "_damage_reporting_type_proximity_mine";
	case _damage_reporting_type_elephant_turret:			return "_damage_reporting_type_elephant_turret";
	case _damage_reporting_type_mammoth_turret:				return "_damage_reporting_type_mammoth_turret";
	case _damage_reporting_type_pelican:					return "_damage_reporting_type_pelican";
	case _damage_reporting_type_grenade_launcher:			return "_damage_reporting_type_grenade_launcher";
	case _damage_reporting_type_plasma_repeater:			return "_damage_reporting_type_plasma_repeater";
	case _damage_reporting_type_needle_rifle:				return "_damage_reporting_type_needle_rifle";
	case _damage_reporting_type_plasma_launcher:			return "_damage_reporting_type_plasma_launcher";
	case _damage_reporting_type_focus_rifle:				return "_damage_reporting_type_focus_rifle";
	case _damage_reporting_type_airstrike:					return "_damage_reporting_type_airstrike";
	case _damage_reporting_type_golf_club:					return "_damage_reporting_type_golf_club";
	case _damage_reporting_type_sabre:						return "_damage_reporting_type_sabre";
	}
	return nullptr;
}

static inline e_damage_reporting_type string_to_damage_reporting_type(const char* string)
{
	for (underlying(e_damage_reporting_type) current_damage_reporting_type = 0; current_damage_reporting_type < k_number_of_damage_reporting_types; current_damage_reporting_type++)
	{
		const char* current_damage_reporting_type_string = damage_reporting_type_to_string(static_cast<e_damage_reporting_type>(current_damage_reporting_type));

		if (strcmp(current_damage_reporting_type_string, string) == 0)
		{
			return static_cast<e_damage_reporting_type>(current_damage_reporting_type);
		}
	}
	return _damage_reporting_type_invalid;
}
