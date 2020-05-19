#pragma once

struct nicename("death_program_selector") tag_group('bdpd') s_death_program_selector_definition_legacy
{
	struct nicename("Death Programs") s_death_programs_definition_legacy
	{
		enum nicename("Death Type") e_death_type : uint32_t
		{
			/*nicename("Weapon Standard")*/ _death_type_weapon_standard = 0ui32,
			/*nicename("Weapon Headshot")*/ _death_type_weapon_headshot = 1ui32,
			/*nicename("Melee")*/ _death_type_melee = 2ui32,
			/*nicename("Vehicle")*/ _death_type_vehicle = 3ui32,
			/*nicename("Assassination")*/ _death_type_assassination = 4ui32,
		};

		struct nicename("Damages") s_damages_definition_legacy
		{
			enum nicename("Damage Type") e_damage_type : uint32_t
			{
				/*nicename("Guardians (Unknown)")*/ _damage_type_guardians_unknown = 0ui32,
				/*nicename("Guardians")*/ _damage_type_guardians = 1ui32,
				/*nicename("Guardians (Scripting)")*/ _damage_type_guardians_scripting = 2ui32,
				/*nicename("Suicide")*/ _damage_type_suicide = 3ui32,
				/*nicename("Magnum")*/ _damage_type_magnum = 4ui32,
				/*nicename("Assault Rifle")*/ _damage_type_assault_rifle = 5ui32,
				/*nicename("DMR")*/ _damage_type_dmr = 6ui32,
				/*nicename("Shotgun")*/ _damage_type_shotgun = 7ui32,
				/*nicename("Sniper Rifle")*/ _damage_type_sniper_rifle = 8ui32,
				/*nicename("Rocket Launcher")*/ _damage_type_rocket_launcher = 9ui32,
				/*nicename("Spartan Laser")*/ _damage_type_spartan_laser = 10ui32,
				/*nicename("Frag Grenade")*/ _damage_type_frag_grenade = 11ui32,
				/*nicename("Grenade Launcher")*/ _damage_type_grenade_launcher = 12ui32,
				/*nicename("Plasma Pistol")*/ _damage_type_plasma_pistol = 13ui32,
				/*nicename("Needler")*/ _damage_type_needler = 14ui32,
				/*nicename("Plasma Rifle")*/ _damage_type_plasma_rifle = 15ui32,
				/*nicename("Plasma Repeater")*/ _damage_type_plasma_repeater = 16ui32,
				/*nicename("Needle Rifle")*/ _damage_type_needle_rifle = 17ui32,
				/*nicename("Spiker")*/ _damage_type_spiker = 18ui32,
				/*nicename("Plasma Launcher")*/ _damage_type_plasma_launcher = 19ui32,
				/*nicename("Gravity Hammer")*/ _damage_type_gravity_hammer = 20ui32,
				/*nicename("Energy Sword")*/ _damage_type_energy_sword = 21ui32,
				/*nicename("Plasma Grenade")*/ _damage_type_plasma_grenade = 22ui32,
				/*nicename("Concussion Rifle")*/ _damage_type_concussion_rifle = 23ui32,
				/*nicename("Ghost")*/ _damage_type_ghost = 24ui32,
				/*nicename("Revenant")*/ _damage_type_revenant = 25ui32,
				/*nicename("Revenant Gunner")*/ _damage_type_revenant_gunner = 26ui32,
				/*nicename("Wraith")*/ _damage_type_wraith = 27ui32,
				/*nicename("Wraith Turret")*/ _damage_type_wraith_turret = 28ui32,
				/*nicename("Banshee")*/ _damage_type_banshee = 29ui32,
				/*nicename("Banshee Bomb")*/ _damage_type_banshee_bomb = 30ui32,
				/*nicename("Seraph")*/ _damage_type_seraph = 31ui32,
				/*nicename("Mongoose")*/ _damage_type_mongoose = 32ui32,
				/*nicename("Warthog")*/ _damage_type_warthog = 33ui32,
				/*nicename("Warthog Chaingun")*/ _damage_type_warthog_chaingun = 34ui32,
				/*nicename("Warthog Gauss")*/ _damage_type_warthog_gauss = 35ui32,
				/*nicename("Warthog Rocket")*/ _damage_type_warthog_rocket = 36ui32,
				/*nicename("Scorpion")*/ _damage_type_scorpion = 37ui32,
				/*nicename("Scorpion Turret")*/ _damage_type_scorpion_turret = 38ui32,
				/*nicename("Falcon")*/ _damage_type_falcon = 39ui32,
				/*nicename("Falcon Gunner")*/ _damage_type_falcon_gunner = 40ui32,
				/*nicename("Falling")*/ _damage_type_falling = 41ui32,
				/*nicename("Collision")*/ _damage_type_collision = 42ui32,
				/*nicename("Melee")*/ _damage_type_melee = 43ui32,
				/*nicename("Explosion")*/ _damage_type_explosion = 44ui32,
				/*nicename("Birthday Explosion")*/ _damage_type_birthday_explosion = 45ui32,
				/*nicename("Flag")*/ _damage_type_flag = 46ui32,
				/*nicename("Bomb")*/ _damage_type_bomb = 47ui32,
				/*nicename("Bomb Explosion")*/ _damage_type_bomb_explosion = 48ui32,
				/*nicename("Ball")*/ _damage_type_ball = 49ui32,
				/*nicename("Teleporter")*/ _damage_type_teleporter = 50ui32,
				/*nicename("Transfer Damage")*/ _damage_type_transfer_damage = 51ui32,
				/*nicename("Armor Lock")*/ _damage_type_armor_lock = 52ui32,
				/*nicename("Target Locator")*/ _damage_type_target_locator = 53ui32,
				/*nicename("Human Turret")*/ _damage_type_human_turret = 54ui32,
				/*nicename("Plasma Cannon")*/ _damage_type_plasma_cannon = 55ui32,
				/*nicename("Plasma Mortar")*/ _damage_type_plasma_mortar = 56ui32,
				/*nicename("Plasma Turret")*/ _damage_type_plasma_turret = 57ui32,
				/*nicename("Shade Turret")*/ _damage_type_shade_turret = 58ui32,
				/*nicename("Sabre")*/ _damage_type_sabre = 59ui32,
				/*nicename("SMG")*/ _damage_type_smg = 60ui32,
				/*nicename("Carbine")*/ _damage_type_carbine = 61ui32,
				/*nicename("Battle Rifle")*/ _damage_type_battle_rifle = 62ui32,
				/*nicename("Focus Rifle")*/ _damage_type_focus_rifle = 63ui32,
				/*nicename("Fuel Rod")*/ _damage_type_fuel_rod = 64ui32,
				/*nicename("Missile Pod")*/ _damage_type_missile_pod = 65ui32,
				/*nicename("Brute Shot")*/ _damage_type_brute_shot = 66ui32,
				/*nicename("Flamethrower")*/ _damage_type_flamethrower = 67ui32,
				/*nicename("Sentinel Gun")*/ _damage_type_sentinel_gun = 68ui32,
				/*nicename("Spike Grenade")*/ _damage_type_spike_grenade = 69ui32,
				/*nicename("Firebomb Grenade")*/ _damage_type_firebomb_grenade = 70ui32,
				/*nicename("Elephant Turret")*/ _damage_type_elephant_turret = 71ui32,
				/*nicename("Spectre")*/ _damage_type_spectre = 72ui32,
				/*nicename("Spectre Gunner")*/ _damage_type_spectre_gunner = 73ui32,
				/*nicename("Tank")*/ _damage_type_tank = 74ui32,
				/*nicename("Chopper")*/ _damage_type_chopper = 75ui32,
				/*nicename("Falcon")*/ _damage_type_falcon1 = 76ui32,
				/*nicename("Mantis")*/ _damage_type_mantis = 77ui32,
				/*nicename("Prowler")*/ _damage_type_prowler = 78ui32,
				/*nicename("Sentinel Beam")*/ _damage_type_sentinel_beam = 79ui32,
				/*nicename("Sentinel RPG")*/ _damage_type_sentinel_rpg = 80ui32,
				/*nicename("Tripmine")*/ _damage_type_tripmine = 81ui32,
			};

			struct nicename("Cases") s_cases_definition_legacy
			{
				enum nicename("Program Type") e_program_type : uint32_t
				{
					/*nicename("Animate Then Ragdoll")*/ _program_type_animate_then_ragdoll = 0ui32,
					/*nicename("Default Ragdoll Program")*/ _program_type_default_ragdoll_program = 1ui32,
					/*nicename("Headshot Ragdoll Program")*/ _program_type_headshot_ragdoll_program = 2ui32,
					/*nicename("Melee Ragdoll Program")*/ _program_type_melee_ragdoll_program = 3ui32,
				};

				float nicename("Animated Length") animated_length;
				e_program_type nicename("Program Type") program_type;
				float nicename("Acceleration") acceleration;
				string_id_legacy nicename("Name") name;
			};

			e_damage_type nicename("Damage Type") damage_type;
			s_tag_block_legacy<s_cases_definition_legacy> nicename("Cases") cases_block;
		};

		e_death_type nicename("Death Type") death_type;
		s_tag_block_legacy<s_damages_definition_legacy> nicename("Damages") damages_block;
	};

	s_tag_reference_legacy nicename("Parent") parent_reference;
	s_tag_block_legacy<s_death_programs_definition_legacy> nicename("Death Programs") death_programs_block;
};

