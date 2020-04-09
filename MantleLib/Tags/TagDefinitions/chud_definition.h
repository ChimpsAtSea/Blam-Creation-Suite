#pragma once

struct nicename("chud_definition") tag_group('chdt') s_chud_definition_definition
{
	struct nicename("HUD Widgets") s_hud_widgets_definition
	{
		enum nicename("Special HUD Type") e_special_hud_type : uint8_t
		{
			/*nicename("Unspecial")*/ _special_hud_type_unspecial = 1ui8,
			/*nicename("Ammo")*/ _special_hud_type_ammo = 2ui8,
			/*nicename("Crosshair and Scope")*/ _special_hud_type_crosshair_and_scope = 3ui8,
			/*nicename("Unit Shield Meter")*/ _special_hud_type_unit_shield_meter = 4ui8,
			/*nicename("Grenades")*/ _special_hud_type_grenades = 5ui8,
			/*nicename("Gametype")*/ _special_hud_type_gametype = 6ui8,
			/*nicename("Motion Sensor")*/ _special_hud_type_motion_sensor = 7ui8,
			/*nicename("Unknown")*/ _special_hud_type_unknown = 8ui8,
			/*nicename("m70_bonus")*/ _special_hud_type_m70_bonus = 9ui8,
		};

		enum nicename("Import Input") e_import_input : uint16_t
		{
			/*nicename("Zero")*/ _import_input_zero = 1ui16,
			/*nicename("One")*/ _import_input_one = 2ui16,
			/*nicename("Unknown 2")*/ _import_input_unknown_2 = 3ui16,
			/*nicename("Unknown 3")*/ _import_input_unknown_3 = 4ui16,
			/*nicename("Unknown 4")*/ _import_input_unknown_4 = 5ui16,
			/*nicename("Time")*/ _import_input_time = 6ui16,
			/*nicename("Fade")*/ _import_input_fade = 7ui16,
			/*nicename("Unknown 7")*/ _import_input_unknown_7 = 8ui16,
			/*nicename("Unknown 8")*/ _import_input_unknown_8 = 9ui16,
			/*nicename("Unknown 9")*/ _import_input_unknown_9 = 10ui16,
			/*nicename("Unknown 10")*/ _import_input_unknown_10 = 11ui16,
			/*nicename("Unknown 11")*/ _import_input_unknown_11 = 12ui16,
			/*nicename("Unknown 12")*/ _import_input_unknown_12 = 13ui16,
			/*nicename("Unknown 13")*/ _import_input_unknown_13 = 14ui16,
			/*nicename("Unknown 14")*/ _import_input_unknown_14 = 15ui16,
			/*nicename("Unknown 15")*/ _import_input_unknown_15 = 16ui16,
			/*nicename("Unknown 16")*/ _import_input_unknown_16 = 17ui16,
			/*nicename("Unknown 17")*/ _import_input_unknown_17 = 18ui16,
			/*nicename("Unknown 18")*/ _import_input_unknown_18 = 19ui16,
			/*nicename("Unknown 19")*/ _import_input_unknown_19 = 20ui16,
			/*nicename("Unknown 20")*/ _import_input_unknown_20 = 21ui16,
			/*nicename("Saber Unknown 1")*/ _import_input_saber_unknown_1 = 22ui16,
			/*nicename("Vehicle Health Current Percentage")*/ _import_input_vehicle_health_current_percentage = 23ui16,
			/*nicename("Unit Health Current")*/ _import_input_unit_health_current = 24ui16,
			/*nicename("Unit Health")*/ _import_input_unit_health = 25ui16,
			/*nicename("Unit Shield Current")*/ _import_input_unit_shield_current = 26ui16,
			/*nicename("Unit 1x Overshield Current")*/ _import_input_unit_1x_overshield_current = 27ui16,
			/*nicename("Unit 2x Overshield Current")*/ _import_input_unit_2x_overshield_current = 28ui16,
			/*nicename("Unit 2x Overshield Current")*/ _import_input_unit_2x_overshield_current1 = 29ui16,
			/*nicename("Unit Shield")*/ _import_input_unit_shield = 30ui16,
			/*nicename("Unit 1x Overshield")*/ _import_input_unit_1x_overshield = 31ui16,
			/*nicename("Unit 2x Overshield")*/ _import_input_unit_2x_overshield = 32ui16,
			/*nicename("Unit 3x Overshield")*/ _import_input_unit_3x_overshield = 33ui16,
			/*nicename("Unit Shield Current Percentage")*/ _import_input_unit_shield_current_percentage = 34ui16,
			/*nicename("Vehicle Shield Current Percentage")*/ _import_input_vehicle_shield_current_percentage = 35ui16,
			/*nicename("Boost Energy Fraction")*/ _import_input_boost_energy_fraction = 36ui16,
			/*nicename("Unknown 36")*/ _import_input_unknown_36 = 37ui16,
			/*nicename("Aim Yaw")*/ _import_input_aim_yaw = 38ui16,
			/*nicename("Aim Pitch")*/ _import_input_aim_pitch = 39ui16,
			/*nicename("Saber Waypoint Distance")*/ _import_input_saber_waypoint_distance = 40ui16,
			/*nicename("Sensor Range")*/ _import_input_sensor_range = 41ui16,
			/*nicename("Unit Altitude 1")*/ _import_input_unit_altitude_1 = 42ui16,
			/*nicename("Unit Altitude 2")*/ _import_input_unit_altitude_2 = 43ui16,
			/*nicename("Unknown 43")*/ _import_input_unknown_43 = 44ui16,
			/*nicename("Softkill Timer")*/ _import_input_softkill_timer = 45ui16,
			/*nicename("Transient Credits")*/ _import_input_transient_credits = 46ui16,
			/*nicename("Unknown 46")*/ _import_input_unknown_46 = 47ui16,
			/*nicename("Clip Ammo Fraction")*/ _import_input_clip_ammo_fraction = 48ui16,
			/*nicename("Total Ammo Fraction")*/ _import_input_total_ammo_fraction = 49ui16,
			/*nicename("Pickup")*/ _import_input_pickup = 50ui16,
			/*nicename("Heat Fraction")*/ _import_input_heat_fraction = 51ui16,
			/*nicename("Airstrike Charge Fraction")*/ _import_input_airstrike_charge_fraction = 52ui16,
			/*nicename("Battery Fraction")*/ _import_input_battery_fraction = 53ui16,
			/*nicename("Unknown 53")*/ _import_input_unknown_53 = 54ui16,
			/*nicename("Unknown 54")*/ _import_input_unknown_54 = 55ui16,
			/*nicename("Weapon Error")*/ _import_input_weapon_error = 56ui16,
			/*nicename("Unknown Weapon Error")*/ _import_input_unknown_weapon_error = 57ui16,
			/*nicename("Unit Autoaimed")*/ _import_input_unit_autoaimed = 58ui16,
			/*nicename("Saber Waypoint Distance Current")*/ _import_input_saber_waypoint_distance_current = 59ui16,
			/*nicename("Airstrike Distance")*/ _import_input_airstrike_distance = 60ui16,
			/*nicename("Nav Point Airstrike")*/ _import_input_nav_point_airstrike = 61ui16,
			/*nicename("Airstrike Ammo")*/ _import_input_airstrike_ammo = 62ui16,
			/*nicename("Unknown 62")*/ _import_input_unknown_62 = 63ui16,
			/*nicename("Unknown 63")*/ _import_input_unknown_63 = 64ui16,
			/*nicename("Grenade Fraction")*/ _import_input_grenade_fraction = 65ui16,
			/*nicename("Unknown 65")*/ _import_input_unknown_65 = 66ui16,
			/*nicename("Charge Fraction")*/ _import_input_charge_fraction = 67ui16,
			/*nicename("Unknown 67")*/ _import_input_unknown_67 = 68ui16,
			/*nicename("Trigger Cooldown")*/ _import_input_trigger_cooldown = 69ui16,
			/*nicename("Trigger Remote Detonate Fraction")*/ _import_input_trigger_remote_detonate_fraction = 70ui16,
			/*nicename("Trigger Locked On")*/ _import_input_trigger_locked_on = 71ui16,
			/*nicename("Target Distance")*/ _import_input_target_distance = 72ui16,
			/*nicename("Target Elevation")*/ _import_input_target_elevation = 73ui16,
			/*nicename("Equipment Energy Fraction")*/ _import_input_equipment_energy_fraction = 74ui16,
			/*nicename("Unknown 74")*/ _import_input_unknown_74 = 75ui16,
			/*nicename("Unknown 75")*/ _import_input_unknown_75 = 76ui16,
			/*nicename("Unknown 76")*/ _import_input_unknown_76 = 77ui16,
			/*nicename("Unknown 77")*/ _import_input_unknown_77 = 78ui16,
			/*nicename("Unknown 78")*/ _import_input_unknown_78 = 79ui16,
			/*nicename("Unknown 79")*/ _import_input_unknown_79 = 80ui16,
			/*nicename("Medal Commendation")*/ _import_input_medal_commendation = 81ui16,
			/*nicename("Generator Health Current")*/ _import_input_generator_health_current = 82ui16,
			/*nicename("Generator Health")*/ _import_input_generator_health = 83ui16,
			/*nicename("Unknown 83")*/ _import_input_unknown_83 = 84ui16,
			/*nicename("Waypoint")*/ _import_input_waypoint = 85ui16,
			/*nicename("Unknown 85")*/ _import_input_unknown_85 = 86ui16,
			/*nicename("Unknown 86")*/ _import_input_unknown_86 = 87ui16,
			/*nicename("Waypoint Onscreen")*/ _import_input_waypoint_onscreen = 88ui16,
			/*nicename("Waypoint Offscreen")*/ _import_input_waypoint_offscreen = 89ui16,
			/*nicename("Gametype Plate")*/ _import_input_gametype_plate = 90ui16,
			/*nicename("Offense Defense")*/ _import_input_offense_defense = 91ui16,
			/*nicename("Metagame Time")*/ _import_input_metagame_time = 92ui16,
			/*nicename("Metagame Score Transient")*/ _import_input_metagame_score_transient = 93ui16,
			/*nicename("Metagame Score Player 1")*/ _import_input_metagame_score_player_1 = 94ui16,
			/*nicename("Unknown 94")*/ _import_input_unknown_94 = 95ui16,
			/*nicename("Unknown 95")*/ _import_input_unknown_95 = 96ui16,
			/*nicename("Unknown 96")*/ _import_input_unknown_96 = 97ui16,
			/*nicename("Unknown 97")*/ _import_input_unknown_97 = 98ui16,
			/*nicename("Unknown 98")*/ _import_input_unknown_98 = 99ui16,
			/*nicename("Unknown 99")*/ _import_input_unknown_99 = 100ui16,
			/*nicename("Survival Multiplier")*/ _import_input_survival_multiplier = 101ui16,
			/*nicename("Metagame Score Negative")*/ _import_input_metagame_score_negative = 102ui16,
			/*nicename("Survival Set")*/ _import_input_survival_set = 103ui16,
			/*nicename("Unknown 103")*/ _import_input_unknown_103 = 104ui16,
			/*nicename("Survival Waves Background")*/ _import_input_survival_waves_background = 105ui16,
			/*nicename("Survival Lives 1")*/ _import_input_survival_lives_1 = 106ui16,
			/*nicename("Survival Lives 2")*/ _import_input_survival_lives_2 = 107ui16,
			/*nicename("Survival Bonus Timer")*/ _import_input_survival_bonus_timer = 108ui16,
			/*nicename("Unknown 108")*/ _import_input_unknown_108 = 109ui16,
			/*nicename("Unknown 109")*/ _import_input_unknown_109 = 110ui16,
			/*nicename("Friendly Score")*/ _import_input_friendly_score = 111ui16,
			/*nicename("Enemy Score")*/ _import_input_enemy_score = 112ui16,
			/*nicename("Score To Win")*/ _import_input_score_to_win = 113ui16,
			/*nicename("Arming Fraction")*/ _import_input_arming_fraction = 114ui16,
			/*nicename("Posession Icon")*/ _import_input_posession_icon = 115ui16,
			/*nicename("Arming Unknown")*/ _import_input_arming_unknown = 116ui16,
			/*nicename("Omniwidget Icon")*/ _import_input_omniwidget_icon = 117ui16,
			/*nicename("Unknown 117")*/ _import_input_unknown_117 = 118ui16,
			/*nicename("Fireteam Health")*/ _import_input_fireteam_health = 119ui16,
			/*nicename("Unknown 119")*/ _import_input_unknown_119 = 120ui16,
			/*nicename("Unknown 120")*/ _import_input_unknown_120 = 121ui16,
			/*nicename("Unknown 121")*/ _import_input_unknown_121 = 122ui16,
			/*nicename("Fireteam Current Shield")*/ _import_input_fireteam_current_shield = 123ui16,
			/*nicename("Unknown 123")*/ _import_input_unknown_123 = 124ui16,
			/*nicename("Unknown 124")*/ _import_input_unknown_124 = 125ui16,
			/*nicename("Fireteam 1 Arming Fraction")*/ _import_input_fireteam_1_arming_fraction = 126ui16,
			/*nicename("Fireteam 2 Arming Fraction")*/ _import_input_fireteam_2_arming_fraction = 127ui16,
			/*nicename("Unknown 127")*/ _import_input_unknown_127 = 128ui16,
			/*nicename("Fireteam 1 Directional Arrow")*/ _import_input_fireteam_1_directional_arrow = 129ui16,
			/*nicename("Fireteam 2 Directional Arrow")*/ _import_input_fireteam_2_directional_arrow = 130ui16,
			/*nicename("Unknown 130")*/ _import_input_unknown_130 = 131ui16,
			/*nicename("Unknown 131")*/ _import_input_unknown_131 = 132ui16,
			/*nicename("Unknown 132")*/ _import_input_unknown_132 = 133ui16,
			/*nicename("Unknown 133")*/ _import_input_unknown_133 = 134ui16,
			/*nicename("Unknown 134")*/ _import_input_unknown_134 = 135ui16,
			/*nicename("Unknown 135")*/ _import_input_unknown_135 = 136ui16,
			/*nicename("Unknown 136")*/ _import_input_unknown_136 = 137ui16,
			/*nicename("Unknown 137")*/ _import_input_unknown_137 = 138ui16,
			/*nicename("Editor Budget")*/ _import_input_editor_budget = 139ui16,
			/*nicename("Editor Budget Cost")*/ _import_input_editor_budget_cost = 140ui16,
			/*nicename("Film Total Time")*/ _import_input_film_total_time = 141ui16,
			/*nicename("Film Current Time")*/ _import_input_film_current_time = 142ui16,
			/*nicename("Unknown 142")*/ _import_input_unknown_142 = 143ui16,
			/*nicename("Film Timeline Fraction 1")*/ _import_input_film_timeline_fraction_1 = 144ui16,
			/*nicename("Film Timeline Fraction 2")*/ _import_input_film_timeline_fraction_2 = 145ui16,
			/*nicename("Unknown 145")*/ _import_input_unknown_145 = 146ui16,
			/*nicename("Unknown 146")*/ _import_input_unknown_146 = 147ui16,
			/*nicename("NetDebug Latency")*/ _import_input_netdebug_latency = 148ui16,
			/*nicename("NetDebug Latency Quality")*/ _import_input_netdebug_latency_quality = 149ui16,
			/*nicename("NetDebug Host Quality")*/ _import_input_netdebug_host_quality = 150ui16,
			/*nicename("NetDebug Local Quality")*/ _import_input_netdebug_local_quality = 151ui16,
		};

		enum nicename("Import Range Input") e_import_range_input : uint16_t
		{
			/*nicename("Zero")*/ _import_range_input_zero = 1ui16,
			/*nicename("One")*/ _import_range_input_one = 2ui16,
			/*nicename("Unknown 2")*/ _import_range_input_unknown_2 = 3ui16,
			/*nicename("Unknown 3")*/ _import_range_input_unknown_3 = 4ui16,
			/*nicename("Unknown 4")*/ _import_range_input_unknown_4 = 5ui16,
			/*nicename("Time")*/ _import_range_input_time = 6ui16,
			/*nicename("Fade")*/ _import_range_input_fade = 7ui16,
			/*nicename("Unknown 7")*/ _import_range_input_unknown_7 = 8ui16,
			/*nicename("Unknown 8")*/ _import_range_input_unknown_8 = 9ui16,
			/*nicename("Unknown 9")*/ _import_range_input_unknown_9 = 10ui16,
			/*nicename("Unknown 10")*/ _import_range_input_unknown_10 = 11ui16,
			/*nicename("Unknown 11")*/ _import_range_input_unknown_11 = 12ui16,
			/*nicename("Unknown 12")*/ _import_range_input_unknown_12 = 13ui16,
			/*nicename("Unknown 13")*/ _import_range_input_unknown_13 = 14ui16,
			/*nicename("Unknown 14")*/ _import_range_input_unknown_14 = 15ui16,
			/*nicename("Unknown 15")*/ _import_range_input_unknown_15 = 16ui16,
			/*nicename("Unknown 16")*/ _import_range_input_unknown_16 = 17ui16,
			/*nicename("Unknown 17")*/ _import_range_input_unknown_17 = 18ui16,
			/*nicename("Unknown 18")*/ _import_range_input_unknown_18 = 19ui16,
			/*nicename("Unknown 19")*/ _import_range_input_unknown_19 = 20ui16,
			/*nicename("Unknown 20")*/ _import_range_input_unknown_20 = 21ui16,
			/*nicename("Saber Unknown 1")*/ _import_range_input_saber_unknown_1 = 22ui16,
			/*nicename("Vehicle Health Current Percentage")*/ _import_range_input_vehicle_health_current_percentage = 23ui16,
			/*nicename("Unit Health Current")*/ _import_range_input_unit_health_current = 24ui16,
			/*nicename("Unit Health")*/ _import_range_input_unit_health = 25ui16,
			/*nicename("Unit Shield Current")*/ _import_range_input_unit_shield_current = 26ui16,
			/*nicename("Unit 1x Overshield Current")*/ _import_range_input_unit_1x_overshield_current = 27ui16,
			/*nicename("Unit 2x Overshield Current")*/ _import_range_input_unit_2x_overshield_current = 28ui16,
			/*nicename("Unit 2x Overshield Current")*/ _import_range_input_unit_2x_overshield_current1 = 29ui16,
			/*nicename("Unit Shield")*/ _import_range_input_unit_shield = 30ui16,
			/*nicename("Unit 1x Overshield")*/ _import_range_input_unit_1x_overshield = 31ui16,
			/*nicename("Unit 2x Overshield")*/ _import_range_input_unit_2x_overshield = 32ui16,
			/*nicename("Unit 3x Overshield")*/ _import_range_input_unit_3x_overshield = 33ui16,
			/*nicename("Unit Shield Current Percentage")*/ _import_range_input_unit_shield_current_percentage = 34ui16,
			/*nicename("Vehicle Shield Current Percentage")*/ _import_range_input_vehicle_shield_current_percentage = 35ui16,
			/*nicename("Boost Energy Fraction")*/ _import_range_input_boost_energy_fraction = 36ui16,
			/*nicename("Unknown 36")*/ _import_range_input_unknown_36 = 37ui16,
			/*nicename("Aim Yaw")*/ _import_range_input_aim_yaw = 38ui16,
			/*nicename("Aim Pitch")*/ _import_range_input_aim_pitch = 39ui16,
			/*nicename("Saber Waypoint Distance")*/ _import_range_input_saber_waypoint_distance = 40ui16,
			/*nicename("Sensor Range")*/ _import_range_input_sensor_range = 41ui16,
			/*nicename("Unit Altitude 1")*/ _import_range_input_unit_altitude_1 = 42ui16,
			/*nicename("Unit Altitude 2")*/ _import_range_input_unit_altitude_2 = 43ui16,
			/*nicename("Unknown 43")*/ _import_range_input_unknown_43 = 44ui16,
			/*nicename("Softkill Timer")*/ _import_range_input_softkill_timer = 45ui16,
			/*nicename("Transient Credits")*/ _import_range_input_transient_credits = 46ui16,
			/*nicename("Unknown 46")*/ _import_range_input_unknown_46 = 47ui16,
			/*nicename("Clip Ammo Fraction")*/ _import_range_input_clip_ammo_fraction = 48ui16,
			/*nicename("Total Ammo Fraction")*/ _import_range_input_total_ammo_fraction = 49ui16,
			/*nicename("Pickup")*/ _import_range_input_pickup = 50ui16,
			/*nicename("Heat Fraction")*/ _import_range_input_heat_fraction = 51ui16,
			/*nicename("Airstrike Charge Fraction")*/ _import_range_input_airstrike_charge_fraction = 52ui16,
			/*nicename("Battery Fraction")*/ _import_range_input_battery_fraction = 53ui16,
			/*nicename("Unknown 53")*/ _import_range_input_unknown_53 = 54ui16,
			/*nicename("Unknown 54")*/ _import_range_input_unknown_54 = 55ui16,
			/*nicename("Weapon Error")*/ _import_range_input_weapon_error = 56ui16,
			/*nicename("Unknown Weapon Error")*/ _import_range_input_unknown_weapon_error = 57ui16,
			/*nicename("Unit Autoaimed")*/ _import_range_input_unit_autoaimed = 58ui16,
			/*nicename("Saber Waypoint Distance Current")*/ _import_range_input_saber_waypoint_distance_current = 59ui16,
			/*nicename("Airstrike Distance")*/ _import_range_input_airstrike_distance = 60ui16,
			/*nicename("Nav Point Airstrike")*/ _import_range_input_nav_point_airstrike = 61ui16,
			/*nicename("Airstrike Ammo")*/ _import_range_input_airstrike_ammo = 62ui16,
			/*nicename("Unknown 62")*/ _import_range_input_unknown_62 = 63ui16,
			/*nicename("Unknown 63")*/ _import_range_input_unknown_63 = 64ui16,
			/*nicename("Grenade Fraction")*/ _import_range_input_grenade_fraction = 65ui16,
			/*nicename("Unknown 65")*/ _import_range_input_unknown_65 = 66ui16,
			/*nicename("Charge Fraction")*/ _import_range_input_charge_fraction = 67ui16,
			/*nicename("Unknown 67")*/ _import_range_input_unknown_67 = 68ui16,
			/*nicename("Trigger Cooldown")*/ _import_range_input_trigger_cooldown = 69ui16,
			/*nicename("Trigger Remote Detonate Fraction")*/ _import_range_input_trigger_remote_detonate_fraction = 70ui16,
			/*nicename("Trigger Locked On")*/ _import_range_input_trigger_locked_on = 71ui16,
			/*nicename("Target Distance")*/ _import_range_input_target_distance = 72ui16,
			/*nicename("Target Elevation")*/ _import_range_input_target_elevation = 73ui16,
			/*nicename("Equipment Energy Fraction")*/ _import_range_input_equipment_energy_fraction = 74ui16,
			/*nicename("Unknown 74")*/ _import_range_input_unknown_74 = 75ui16,
			/*nicename("Unknown 75")*/ _import_range_input_unknown_75 = 76ui16,
			/*nicename("Unknown 76")*/ _import_range_input_unknown_76 = 77ui16,
			/*nicename("Unknown 77")*/ _import_range_input_unknown_77 = 78ui16,
			/*nicename("Unknown 78")*/ _import_range_input_unknown_78 = 79ui16,
			/*nicename("Unknown 79")*/ _import_range_input_unknown_79 = 80ui16,
			/*nicename("Medal Commendation")*/ _import_range_input_medal_commendation = 81ui16,
			/*nicename("Generator Health Current")*/ _import_range_input_generator_health_current = 82ui16,
			/*nicename("Generator Health")*/ _import_range_input_generator_health = 83ui16,
			/*nicename("Unknown 83")*/ _import_range_input_unknown_83 = 84ui16,
			/*nicename("Waypoint")*/ _import_range_input_waypoint = 85ui16,
			/*nicename("Unknown 85")*/ _import_range_input_unknown_85 = 86ui16,
			/*nicename("Unknown 86")*/ _import_range_input_unknown_86 = 87ui16,
			/*nicename("Waypoint Onscreen")*/ _import_range_input_waypoint_onscreen = 88ui16,
			/*nicename("Waypoint Offscreen")*/ _import_range_input_waypoint_offscreen = 89ui16,
			/*nicename("Gametype Plate")*/ _import_range_input_gametype_plate = 90ui16,
			/*nicename("Offense Defense")*/ _import_range_input_offense_defense = 91ui16,
			/*nicename("Metagame Time")*/ _import_range_input_metagame_time = 92ui16,
			/*nicename("Metagame Score Transient")*/ _import_range_input_metagame_score_transient = 93ui16,
			/*nicename("Metagame Score Player 1")*/ _import_range_input_metagame_score_player_1 = 94ui16,
			/*nicename("Unknown 94")*/ _import_range_input_unknown_94 = 95ui16,
			/*nicename("Unknown 95")*/ _import_range_input_unknown_95 = 96ui16,
			/*nicename("Unknown 96")*/ _import_range_input_unknown_96 = 97ui16,
			/*nicename("Unknown 97")*/ _import_range_input_unknown_97 = 98ui16,
			/*nicename("Unknown 98")*/ _import_range_input_unknown_98 = 99ui16,
			/*nicename("Unknown 99")*/ _import_range_input_unknown_99 = 100ui16,
			/*nicename("Survival Multiplier")*/ _import_range_input_survival_multiplier = 101ui16,
			/*nicename("Metagame Score Negative")*/ _import_range_input_metagame_score_negative = 102ui16,
			/*nicename("Survival Set")*/ _import_range_input_survival_set = 103ui16,
			/*nicename("Unknown 103")*/ _import_range_input_unknown_103 = 104ui16,
			/*nicename("Survival Waves Background")*/ _import_range_input_survival_waves_background = 105ui16,
			/*nicename("Survival Lives 1")*/ _import_range_input_survival_lives_1 = 106ui16,
			/*nicename("Survival Lives 2")*/ _import_range_input_survival_lives_2 = 107ui16,
			/*nicename("Survival Bonus Timer")*/ _import_range_input_survival_bonus_timer = 108ui16,
			/*nicename("Unknown 108")*/ _import_range_input_unknown_108 = 109ui16,
			/*nicename("Unknown 109")*/ _import_range_input_unknown_109 = 110ui16,
			/*nicename("Friendly Score")*/ _import_range_input_friendly_score = 111ui16,
			/*nicename("Enemy Score")*/ _import_range_input_enemy_score = 112ui16,
			/*nicename("Score To Win")*/ _import_range_input_score_to_win = 113ui16,
			/*nicename("Arming Fraction")*/ _import_range_input_arming_fraction = 114ui16,
			/*nicename("Posession Icon")*/ _import_range_input_posession_icon = 115ui16,
			/*nicename("Arming Unknown")*/ _import_range_input_arming_unknown = 116ui16,
			/*nicename("Omniwidget Icon")*/ _import_range_input_omniwidget_icon = 117ui16,
			/*nicename("Unknown 117")*/ _import_range_input_unknown_117 = 118ui16,
			/*nicename("Fireteam Health")*/ _import_range_input_fireteam_health = 119ui16,
			/*nicename("Unknown 119")*/ _import_range_input_unknown_119 = 120ui16,
			/*nicename("Unknown 120")*/ _import_range_input_unknown_120 = 121ui16,
			/*nicename("Unknown 121")*/ _import_range_input_unknown_121 = 122ui16,
			/*nicename("Fireteam Current Shield")*/ _import_range_input_fireteam_current_shield = 123ui16,
			/*nicename("Unknown 123")*/ _import_range_input_unknown_123 = 124ui16,
			/*nicename("Unknown 124")*/ _import_range_input_unknown_124 = 125ui16,
			/*nicename("Fireteam 1 Arming Fraction")*/ _import_range_input_fireteam_1_arming_fraction = 126ui16,
			/*nicename("Fireteam 2 Arming Fraction")*/ _import_range_input_fireteam_2_arming_fraction = 127ui16,
			/*nicename("Unknown 127")*/ _import_range_input_unknown_127 = 128ui16,
			/*nicename("Fireteam 1 Directional Arrow")*/ _import_range_input_fireteam_1_directional_arrow = 129ui16,
			/*nicename("Fireteam 2 Directional Arrow")*/ _import_range_input_fireteam_2_directional_arrow = 130ui16,
			/*nicename("Unknown 130")*/ _import_range_input_unknown_130 = 131ui16,
			/*nicename("Unknown 131")*/ _import_range_input_unknown_131 = 132ui16,
			/*nicename("Unknown 132")*/ _import_range_input_unknown_132 = 133ui16,
			/*nicename("Unknown 133")*/ _import_range_input_unknown_133 = 134ui16,
			/*nicename("Unknown 134")*/ _import_range_input_unknown_134 = 135ui16,
			/*nicename("Unknown 135")*/ _import_range_input_unknown_135 = 136ui16,
			/*nicename("Unknown 136")*/ _import_range_input_unknown_136 = 137ui16,
			/*nicename("Unknown 137")*/ _import_range_input_unknown_137 = 138ui16,
			/*nicename("Editor Budget")*/ _import_range_input_editor_budget = 139ui16,
			/*nicename("Editor Budget Cost")*/ _import_range_input_editor_budget_cost = 140ui16,
			/*nicename("Film Total Time")*/ _import_range_input_film_total_time = 141ui16,
			/*nicename("Film Current Time")*/ _import_range_input_film_current_time = 142ui16,
			/*nicename("Unknown 142")*/ _import_range_input_unknown_142 = 143ui16,
			/*nicename("Film Timeline Fraction 1")*/ _import_range_input_film_timeline_fraction_1 = 144ui16,
			/*nicename("Film Timeline Fraction 2")*/ _import_range_input_film_timeline_fraction_2 = 145ui16,
			/*nicename("Unknown 145")*/ _import_range_input_unknown_145 = 146ui16,
			/*nicename("Unknown 146")*/ _import_range_input_unknown_146 = 147ui16,
			/*nicename("NetDebug Latency")*/ _import_range_input_netdebug_latency = 148ui16,
			/*nicename("NetDebug Latency Quality")*/ _import_range_input_netdebug_latency_quality = 149ui16,
			/*nicename("NetDebug Host Quality")*/ _import_range_input_netdebug_host_quality = 150ui16,
			/*nicename("NetDebug Local Quality")*/ _import_range_input_netdebug_local_quality = 151ui16,
		};

		enum nicename("Second State-Block Starting Value") e_second_state_block_starting_value : uint8_t
		{
			/*nicename("Value 0")*/ _second_state_block_starting_value_value_0 = 1ui8,
			/*nicename("Value 1")*/ _second_state_block_starting_value_value_1 = 2ui8,
			/*nicename("Value 2")*/ _second_state_block_starting_value_value_2 = 3ui8,
			/*nicename("Value 3")*/ _second_state_block_starting_value_value_3 = 4ui8,
			/*nicename("Value 4")*/ _second_state_block_starting_value_value_4 = 5ui8,
			/*nicename("Value 5")*/ _second_state_block_starting_value_value_5 = 6ui8,
			/*nicename("Value 6")*/ _second_state_block_starting_value_value_6 = 7ui8,
			/*nicename("Value 7")*/ _second_state_block_starting_value_value_7 = 8ui8,
			/*nicename("Value 8")*/ _second_state_block_starting_value_value_8 = 9ui8,
			/*nicename("Value 9")*/ _second_state_block_starting_value_value_9 = 10ui8,
			/*nicename("Value 10")*/ _second_state_block_starting_value_value_10 = 11ui8,
			/*nicename("Value 11")*/ _second_state_block_starting_value_value_11 = 12ui8,
			/*nicename("Value 12")*/ _second_state_block_starting_value_value_12 = 13ui8,
		};

		enum nicename("Input Variable Triggers") b_input_variable_triggers : uint16_t /* bitfield */
		{
			/*nicename("Value 0")*/ _input_variable_triggers_value_0 = 1ui16 << 0ui16,
			/*nicename("Value 1")*/ _input_variable_triggers_value_1 = 1ui16 << 1ui16,
			/*nicename("Value 2")*/ _input_variable_triggers_value_2 = 1ui16 << 2ui16,
			/*nicename("Value 3")*/ _input_variable_triggers_value_3 = 1ui16 << 3ui16,
			/*nicename("Value 4")*/ _input_variable_triggers_value_4 = 1ui16 << 4ui16,
			/*nicename("Value 5")*/ _input_variable_triggers_value_5 = 1ui16 << 5ui16,
			/*nicename("Value 6")*/ _input_variable_triggers_value_6 = 1ui16 << 6ui16,
			/*nicename("Value 7")*/ _input_variable_triggers_value_7 = 1ui16 << 7ui16,
			/*nicename("Value 8")*/ _input_variable_triggers_value_8 = 1ui16 << 8ui16,
			/*nicename("Value 9")*/ _input_variable_triggers_value_9 = 1ui16 << 9ui16,
			/*nicename("Value 10")*/ _input_variable_triggers_value_10 = 1ui16 << 10ui16,
			/*nicename("Value 11")*/ _input_variable_triggers_value_11 = 1ui16 << 11ui16,
			/*nicename("Value 12")*/ _input_variable_triggers_value_12 = 1ui16 << 12ui16,
		};

		struct nicename("State Data") s_state_data_definition
		{
			struct nicename("'Yes' States") s_yes_states_definition
			{
				struct nicename("Triggers") s_triggers_definition
				{
					enum nicename("Flag") b_flag : uint8_t /* bitfield */
					{
						/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
					};

					b_flag nicename("Flag") flag;
					int8_t __unknown0;
					int8_t __unknown1;
					int8_t __unknown2;
					int32_t nicename("Trigger Index") trigger_index;
				};

				s_tag_block_definition<s_triggers_definition> nicename("Triggers") triggers_block;
			};

			struct nicename("Unknown States") s_unknown_states_definition
			{
				struct nicename("Triggers") s_triggers1_definition
				{
					enum nicename("Flag") b_flag : uint8_t /* bitfield */
					{
						/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
					};

					b_flag nicename("Flag") flag;
					int8_t __unknown0;
					int8_t __unknown1;
					int8_t __unknown2;
					int32_t nicename("Trigger Index") trigger_index;
				};

				s_tag_block_definition<s_triggers1_definition> nicename("Triggers") triggers_block;
			};

			struct nicename("'No' States") s_no_states_definition
			{
				struct nicename("Triggers") s_triggers2_definition
				{
					enum nicename("Flag") b_flag : uint8_t /* bitfield */
					{
						/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
					};

					b_flag nicename("Flag") flag;
					int8_t __unknown0;
					int8_t __unknown1;
					int8_t __unknown2;
					int32_t nicename("Trigger Index") trigger_index;
				};

				s_tag_block_definition<s_triggers2_definition> nicename("Triggers") triggers_block;
			};

			// State Data Note : The following blocks are import data.
			s_tag_block_definition<s_yes_states_definition> nicename("'Yes' States") yes_states_block;
			s_tag_block_definition<s_unknown_states_definition> nicename("Unknown States") unknown_states_block;
			s_tag_block_definition<s_no_states_definition> nicename("'No' States") no_states_block;
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
			Undefined32 __unknown4;
			Undefined32 __unknown5;
			Undefined32 __unknown6;
		};

		struct nicename("Placement Data") s_placement_data_definition
		{
			enum nicename("Anchor") e_anchor : uint8_t
			{
				/*nicename("Unknown")*/ _anchor_unknown = 1ui8,
				/*nicename("Top, Left")*/ _anchor_top_left = 2ui8,
				/*nicename("Top, Middle")*/ _anchor_top_middle = 3ui8,
				/*nicename("Top, Right")*/ _anchor_top_right = 4ui8,
				/*nicename("Center, Middle")*/ _anchor_center_middle = 5ui8,
				/*nicename("Bottom, Left")*/ _anchor_bottom_left = 6ui8,
				/*nicename("Bottom, Middle")*/ _anchor_bottom_middle = 7ui8,
				/*nicename("Bottom, Right")*/ _anchor_bottom_right = 8ui8,
				/*nicename("Motion Sensor")*/ _anchor_motion_sensor = 9ui8,
				/*nicename("Crosshair A")*/ _anchor_crosshair_a = 10ui8,
				/*nicename("Ability")*/ _anchor_ability = 11ui8,
				/*nicename("Weapon Left")*/ _anchor_weapon_left = 12ui8,
				/*nicename("Weapon Right")*/ _anchor_weapon_right = 13ui8,
				/*nicename("Health and Shield")*/ _anchor_health_and_shield = 14ui8,
				/*nicename("Unknown")*/ _anchor_unknown1 = 15ui8,
				/*nicename("Top, Left B")*/ _anchor_top_left_b = 16ui8,
				/*nicename("Unknown")*/ _anchor_unknown2 = 17ui8,
				/*nicename("Crosshair B")*/ _anchor_crosshair_b = 18ui8,
				/*nicename("Top, Left C")*/ _anchor_top_left_c = 19ui8,
				/*nicename("Top, Left D")*/ _anchor_top_left_d = 20ui8,
				/*nicename("Top, Left E")*/ _anchor_top_left_e = 21ui8,
				/*nicename("Crosshair B")*/ _anchor_crosshair_b1 = 22ui8,
				/*nicename("Top, Left F")*/ _anchor_top_left_f = 23ui8,
				/*nicename("Unknown")*/ _anchor_unknown3 = 24ui8,
				/*nicename("Top, Left G")*/ _anchor_top_left_g = 25ui8,
				/*nicename("Unknown")*/ _anchor_unknown4 = 26ui8,
				/*nicename("Top, Left F")*/ _anchor_top_left_f1 = 27ui8,
				/*nicename("Score")*/ _anchor_score = 28ui8,
				/*nicename("Score B")*/ _anchor_score_b = 29ui8,
				/*nicename("Score C")*/ _anchor_score_c = 30ui8,
				/*nicename("Score D")*/ _anchor_score_d = 31ui8,
				/*nicename("Score E")*/ _anchor_score_e = 32ui8,
				/*nicename("Score F")*/ _anchor_score_f = 33ui8,
				/*nicename("Score G")*/ _anchor_score_g = 34ui8,
				/*nicename("Unknown")*/ _anchor_unknown5 = 35ui8,
				/*nicename("Unknown")*/ _anchor_unknown6 = 36ui8,
				/*nicename("Unknown")*/ _anchor_unknown7 = 37ui8,
				/*nicename("Unknown")*/ _anchor_unknown8 = 38ui8,
				/*nicename("Unknown")*/ _anchor_unknown9 = 39ui8,
				/*nicename("Unknown")*/ _anchor_unknown10 = 40ui8,
			};

			enum b_unknown : uint8_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _unknown_bit_0 = 1ui8 << 0ui8,
				/*nicename("Bit 1")*/ _unknown_bit_1 = 1ui8 << 1ui8,
				/*nicename("Bit 2")*/ _unknown_bit_2 = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _unknown_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _unknown_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _unknown_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _unknown_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _unknown_bit_7 = 1ui8 << 7ui8,
			};

			b_unknown __unknown0;
			e_anchor nicename("Anchor") anchor;
			int16_t __unknown1;
			float nicename("Mirror Offset X") mirror_offset_x;
			float nicename("Mirror Offset Y") mirror_offset_y;
			float nicename("Offset X") offset_x;
			float nicename("Offset Y") offset_y;
			float nicename("Scale X") scale_x;
			float nicename("Scale Y") scale_y;
		};

		struct nicename("Animation Data") s_animation_data_definition
		{
			enum nicename("Animation 1 Function") e_animation_1_function : uint8_t
			{
				/*nicename("Default")*/ _animation_1_function_default = 1ui8,
				/*nicename("Use Input")*/ _animation_1_function_use_input = 2ui8,
				/*nicename("Use Range Input")*/ _animation_1_function_use_range_input = 3ui8,
				/*nicename("Zero")*/ _animation_1_function_zero = 4ui8,
			};

			enum nicename("Animation 2 Function") e_animation_2_function : uint8_t
			{
				/*nicename("Default")*/ _animation_2_function_default = 1ui8,
				/*nicename("Use Input")*/ _animation_2_function_use_input = 2ui8,
				/*nicename("Use Range Input")*/ _animation_2_function_use_range_input = 3ui8,
				/*nicename("Zero")*/ _animation_2_function_zero = 4ui8,
			};

			enum nicename("Animation 3 Function") e_animation_3_function : uint8_t
			{
				/*nicename("Default")*/ _animation_3_function_default = 1ui8,
				/*nicename("Use Input")*/ _animation_3_function_use_input = 2ui8,
				/*nicename("Use Range Input")*/ _animation_3_function_use_range_input = 3ui8,
				/*nicename("Zero")*/ _animation_3_function_zero = 4ui8,
			};

			enum nicename("Animation 4 Function") e_animation_4_function : uint8_t
			{
				/*nicename("Default")*/ _animation_4_function_default = 1ui8,
				/*nicename("Use Input")*/ _animation_4_function_use_input = 2ui8,
				/*nicename("Use Range Input")*/ _animation_4_function_use_range_input = 3ui8,
				/*nicename("Zero")*/ _animation_4_function_zero = 4ui8,
			};

			enum nicename("Animation 5 Function") e_animation_5_function : uint8_t
			{
				/*nicename("Default")*/ _animation_5_function_default = 1ui8,
				/*nicename("Use Input")*/ _animation_5_function_use_input = 2ui8,
				/*nicename("Use Range Input")*/ _animation_5_function_use_range_input = 3ui8,
				/*nicename("Zero")*/ _animation_5_function_zero = 4ui8,
			};

			enum nicename("Animation 1 Flags") b_animation_1_flags : uint8_t /* bitfield */
			{
				/*nicename("Reverse Frames")*/ _animation_1_flags_reverse_frames = 1ui8 << 0ui8,
			};

			enum nicename("Animation 2 Flags") b_animation_2_flags : uint8_t /* bitfield */
			{
				/*nicename("Reverse Frames")*/ _animation_2_flags_reverse_frames = 1ui8 << 0ui8,
			};

			enum nicename("Animation 3 Flags") b_animation_3_flags : uint8_t /* bitfield */
			{
				/*nicename("Reverse Frames")*/ _animation_3_flags_reverse_frames = 1ui8 << 0ui8,
			};

			enum nicename("Animation 4 Flags") b_animation_4_flags : uint8_t /* bitfield */
			{
				/*nicename("Reverse Frames")*/ _animation_4_flags_reverse_frames = 1ui8 << 0ui8,
			};

			enum nicename("Animation 5 Flags") b_animation_5_flags : uint8_t /* bitfield */
			{
				/*nicename("Reverse Frames")*/ _animation_5_flags_reverse_frames = 1ui8 << 0ui8,
			};

			b_animation_1_flags nicename("Animation 1 Flags") animation_1_flags;
			e_animation_1_function nicename("Animation 1 Function") animation_1_function;
			int16_t __unknown0;
			TagReference nicename("Animation 1") animation_1_reference;
			b_animation_2_flags nicename("Animation 2 Flags") animation_2_flags;
			e_animation_2_function nicename("Animation 2 Function") animation_2_function;
			int16_t __unknown1;
			TagReference nicename("Animation 2") animation_2_reference;
			b_animation_3_flags nicename("Animation 3 Flags") animation_3_flags;
			e_animation_3_function nicename("Animation 3 Function") animation_3_function;
			int16_t __unknown2;
			TagReference nicename("Animation 3") animation_3_reference;
			b_animation_4_flags nicename("Animation 4 Flags") animation_4_flags;
			e_animation_4_function nicename("Animation 4 Function") animation_4_function;
			int16_t __unknown3;
			TagReference nicename("Animation 4") animation_4_reference;
			b_animation_5_flags nicename("Animation 5 Flags") animation_5_flags;
			e_animation_5_function nicename("Animation 5 Function") animation_5_function;
			int16_t __unknown4;
			TagReference nicename("Animation 5") animation_5_reference;
		};

		struct nicename("Render Data") s_render_data_definition
		{
			enum nicename("Shader Index") e_shader_index : uint8_t
			{
				/*nicename("Cheap")*/ _shader_index_cheap = 1ui8,
				/*nicename("Simple")*/ _shader_index_simple = 2ui8,
				/*nicename("Meter")*/ _shader_index_meter = 3ui8,
				/*nicename("Text Simple")*/ _shader_index_text_simple = 4ui8,
				/*nicename("Meter Shield")*/ _shader_index_meter_shield = 5ui8,
				/*nicename("Meter Gradient")*/ _shader_index_meter_gradient = 6ui8,
				/*nicename("Crosshair")*/ _shader_index_crosshair = 7ui8,
				/*nicename("Directional Damage")*/ _shader_index_directional_damage = 8ui8,
				/*nicename("Solid")*/ _shader_index_solid = 9ui8,
				/*nicename("Sensor")*/ _shader_index_sensor = 10ui8,
				/*nicename("Meter Single Color")*/ _shader_index_meter_single_color = 11ui8,
				/*nicename("Navpoint")*/ _shader_index_navpoint = 12ui8,
				/*nicename("Medal")*/ _shader_index_medal = 13ui8,
				/*nicename("Texture Cam")*/ _shader_index_texture_cam = 14ui8,
				/*nicename("Meter Chapter")*/ _shader_index_meter_chapter = 15ui8,
				/*nicename("Meter Double Gradient")*/ _shader_index_meter_double_gradient = 16ui8,
				/*nicename("Meter Radial Gradient")*/ _shader_index_meter_radial_gradient = 17ui8,
				/*nicename("Turbulence")*/ _shader_index_turbulence = 18ui8,
				/*nicename("Emblem")*/ _shader_index_emblem = 19ui8,
				/*nicename("Directional Damage Apply")*/ _shader_index_directional_damage_apply = 20ui8,
				/*nicename("Damage Tracker")*/ _shader_index_damage_tracker = 21ui8,
			};

			enum nicename("Output Color a") e_output_color_a : uint16_t
			{
				/*nicename("Local a")*/ _output_color_a_local_a = 1ui16,
				/*nicename("Local b")*/ _output_color_a_local_b = 2ui16,
				/*nicename("Local c")*/ _output_color_a_local_c = 3ui16,
				/*nicename("Local d")*/ _output_color_a_local_d = 4ui16,
				/*nicename("Unknown 4")*/ _output_color_a_unknown_4 = 5ui16,
				/*nicename("Unknown 5")*/ _output_color_a_unknown_5 = 6ui16,
				/*nicename("Scoreboard Friendly")*/ _output_color_a_scoreboard_friendly = 7ui16,
				/*nicename("Scoreboard Enemy")*/ _output_color_a_scoreboard_enemy = 8ui16,
				/*nicename("Arming Team")*/ _output_color_a_arming_team = 9ui16,
				/*nicename("Metagame Player 1")*/ _output_color_a_metagame_player_1 = 10ui16,
				/*nicename("Metagame Player 2")*/ _output_color_a_metagame_player_2 = 11ui16,
				/*nicename("Metagame Player 3")*/ _output_color_a_metagame_player_3 = 12ui16,
				/*nicename("Metagame Player 4")*/ _output_color_a_metagame_player_4 = 13ui16,
				/*nicename("Unknown 13")*/ _output_color_a_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _output_color_a_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _output_color_a_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _output_color_a_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _output_color_a_unknown_17 = 18ui16,
				/*nicename("Global Dynamic 0")*/ _output_color_a_global_dynamic_0 = 19ui16,
				/*nicename("Global Dynamic 1")*/ _output_color_a_global_dynamic_1 = 20ui16,
				/*nicename("Global Dynamic 2")*/ _output_color_a_global_dynamic_2 = 21ui16,
				/*nicename("Global Dynamic 3")*/ _output_color_a_global_dynamic_3 = 22ui16,
				/*nicename("Global Dynamic 4")*/ _output_color_a_global_dynamic_4 = 23ui16,
				/*nicename("Global Dynamic 5")*/ _output_color_a_global_dynamic_5 = 24ui16,
				/*nicename("Global Dynamic 6")*/ _output_color_a_global_dynamic_6 = 25ui16,
				/*nicename("Global Dynamic 7")*/ _output_color_a_global_dynamic_7 = 26ui16,
				/*nicename("Global Dynamic 8")*/ _output_color_a_global_dynamic_8 = 27ui16,
				/*nicename("Global Dynamic 9")*/ _output_color_a_global_dynamic_9 = 28ui16,
				/*nicename("Global Dynamic 10")*/ _output_color_a_global_dynamic_10 = 29ui16,
				/*nicename("Global Dynamic 11")*/ _output_color_a_global_dynamic_11 = 30ui16,
				/*nicename("Global Dynamic 12")*/ _output_color_a_global_dynamic_12 = 31ui16,
				/*nicename("Global Dynamic 13")*/ _output_color_a_global_dynamic_13 = 32ui16,
				/*nicename("Global Dynamic 14")*/ _output_color_a_global_dynamic_14 = 33ui16,
				/*nicename("Global Dynamic 15")*/ _output_color_a_global_dynamic_15 = 34ui16,
				/*nicename("Global Dynamic 16")*/ _output_color_a_global_dynamic_16 = 35ui16,
				/*nicename("Global Dynamic 17")*/ _output_color_a_global_dynamic_17 = 36ui16,
				/*nicename("Global Dynamic 18")*/ _output_color_a_global_dynamic_18 = 37ui16,
				/*nicename("Global Dynamic 19")*/ _output_color_a_global_dynamic_19 = 38ui16,
				/*nicename("Global Dynamic 20")*/ _output_color_a_global_dynamic_20 = 39ui16,
				/*nicename("Global Dynamic 21")*/ _output_color_a_global_dynamic_21 = 40ui16,
				/*nicename("Global Dynamic 22")*/ _output_color_a_global_dynamic_22 = 41ui16,
				/*nicename("Global Dynamic 23")*/ _output_color_a_global_dynamic_23 = 42ui16,
				/*nicename("Global Dynamic 24")*/ _output_color_a_global_dynamic_24 = 43ui16,
				/*nicename("Global Dynamic 25")*/ _output_color_a_global_dynamic_25 = 44ui16,
				/*nicename("Global Dynamic 26")*/ _output_color_a_global_dynamic_26 = 45ui16,
				/*nicename("Global Dynamic 27")*/ _output_color_a_global_dynamic_27 = 46ui16,
				/*nicename("Global Dynamic 28")*/ _output_color_a_global_dynamic_28 = 47ui16,
				/*nicename("Global Dynamic 29")*/ _output_color_a_global_dynamic_29 = 48ui16,
				/*nicename("Global Dynamic 30")*/ _output_color_a_global_dynamic_30 = 49ui16,
				/*nicename("Global Dynamic 31")*/ _output_color_a_global_dynamic_31 = 50ui16,
				/*nicename("Global Dynamic 32")*/ _output_color_a_global_dynamic_32 = 51ui16,
				/*nicename("Global Dynamic 33")*/ _output_color_a_global_dynamic_33 = 52ui16,
				/*nicename("Global Dynamic 34")*/ _output_color_a_global_dynamic_34 = 53ui16,
				/*nicename("Global Dynamic 35")*/ _output_color_a_global_dynamic_35 = 54ui16,
				/*nicename("Global Dynamic 36")*/ _output_color_a_global_dynamic_36 = 55ui16,
				/*nicename("Global Dynamic 37")*/ _output_color_a_global_dynamic_37 = 56ui16,
				/*nicename("Global Dynamic 38")*/ _output_color_a_global_dynamic_38 = 57ui16,
				/*nicename("Global Dynamic 39")*/ _output_color_a_global_dynamic_39 = 58ui16,
				/*nicename("Global Dynamic 40")*/ _output_color_a_global_dynamic_40 = 59ui16,
				/*nicename("Global Dynamic 41")*/ _output_color_a_global_dynamic_41 = 60ui16,
				/*nicename("Global Dynamic 42")*/ _output_color_a_global_dynamic_42 = 61ui16,
			};

			enum nicename("Output Color b") e_output_color_b : uint16_t
			{
				/*nicename("Local a")*/ _output_color_b_local_a = 1ui16,
				/*nicename("Local b")*/ _output_color_b_local_b = 2ui16,
				/*nicename("Local c")*/ _output_color_b_local_c = 3ui16,
				/*nicename("Local d")*/ _output_color_b_local_d = 4ui16,
				/*nicename("Unknown 4")*/ _output_color_b_unknown_4 = 5ui16,
				/*nicename("Unknown 5")*/ _output_color_b_unknown_5 = 6ui16,
				/*nicename("Scoreboard Friendly")*/ _output_color_b_scoreboard_friendly = 7ui16,
				/*nicename("Scoreboard Enemy")*/ _output_color_b_scoreboard_enemy = 8ui16,
				/*nicename("Arming Team")*/ _output_color_b_arming_team = 9ui16,
				/*nicename("Metagame Player 1")*/ _output_color_b_metagame_player_1 = 10ui16,
				/*nicename("Metagame Player 2")*/ _output_color_b_metagame_player_2 = 11ui16,
				/*nicename("Metagame Player 3")*/ _output_color_b_metagame_player_3 = 12ui16,
				/*nicename("Metagame Player 4")*/ _output_color_b_metagame_player_4 = 13ui16,
				/*nicename("Unknown 13")*/ _output_color_b_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _output_color_b_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _output_color_b_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _output_color_b_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _output_color_b_unknown_17 = 18ui16,
				/*nicename("Global Dynamic 0")*/ _output_color_b_global_dynamic_0 = 19ui16,
				/*nicename("Global Dynamic 1")*/ _output_color_b_global_dynamic_1 = 20ui16,
				/*nicename("Global Dynamic 2")*/ _output_color_b_global_dynamic_2 = 21ui16,
				/*nicename("Global Dynamic 3")*/ _output_color_b_global_dynamic_3 = 22ui16,
				/*nicename("Global Dynamic 4")*/ _output_color_b_global_dynamic_4 = 23ui16,
				/*nicename("Global Dynamic 5")*/ _output_color_b_global_dynamic_5 = 24ui16,
				/*nicename("Global Dynamic 6")*/ _output_color_b_global_dynamic_6 = 25ui16,
				/*nicename("Global Dynamic 7")*/ _output_color_b_global_dynamic_7 = 26ui16,
				/*nicename("Global Dynamic 8")*/ _output_color_b_global_dynamic_8 = 27ui16,
				/*nicename("Global Dynamic 9")*/ _output_color_b_global_dynamic_9 = 28ui16,
				/*nicename("Global Dynamic 10")*/ _output_color_b_global_dynamic_10 = 29ui16,
				/*nicename("Global Dynamic 11")*/ _output_color_b_global_dynamic_11 = 30ui16,
				/*nicename("Global Dynamic 12")*/ _output_color_b_global_dynamic_12 = 31ui16,
				/*nicename("Global Dynamic 13")*/ _output_color_b_global_dynamic_13 = 32ui16,
				/*nicename("Global Dynamic 14")*/ _output_color_b_global_dynamic_14 = 33ui16,
				/*nicename("Global Dynamic 15")*/ _output_color_b_global_dynamic_15 = 34ui16,
				/*nicename("Global Dynamic 16")*/ _output_color_b_global_dynamic_16 = 35ui16,
				/*nicename("Global Dynamic 17")*/ _output_color_b_global_dynamic_17 = 36ui16,
				/*nicename("Global Dynamic 18")*/ _output_color_b_global_dynamic_18 = 37ui16,
				/*nicename("Global Dynamic 19")*/ _output_color_b_global_dynamic_19 = 38ui16,
				/*nicename("Global Dynamic 20")*/ _output_color_b_global_dynamic_20 = 39ui16,
				/*nicename("Global Dynamic 21")*/ _output_color_b_global_dynamic_21 = 40ui16,
				/*nicename("Global Dynamic 22")*/ _output_color_b_global_dynamic_22 = 41ui16,
				/*nicename("Global Dynamic 23")*/ _output_color_b_global_dynamic_23 = 42ui16,
				/*nicename("Global Dynamic 24")*/ _output_color_b_global_dynamic_24 = 43ui16,
				/*nicename("Global Dynamic 25")*/ _output_color_b_global_dynamic_25 = 44ui16,
				/*nicename("Global Dynamic 26")*/ _output_color_b_global_dynamic_26 = 45ui16,
				/*nicename("Global Dynamic 27")*/ _output_color_b_global_dynamic_27 = 46ui16,
				/*nicename("Global Dynamic 28")*/ _output_color_b_global_dynamic_28 = 47ui16,
				/*nicename("Global Dynamic 29")*/ _output_color_b_global_dynamic_29 = 48ui16,
				/*nicename("Global Dynamic 30")*/ _output_color_b_global_dynamic_30 = 49ui16,
				/*nicename("Global Dynamic 31")*/ _output_color_b_global_dynamic_31 = 50ui16,
				/*nicename("Global Dynamic 32")*/ _output_color_b_global_dynamic_32 = 51ui16,
				/*nicename("Global Dynamic 33")*/ _output_color_b_global_dynamic_33 = 52ui16,
				/*nicename("Global Dynamic 34")*/ _output_color_b_global_dynamic_34 = 53ui16,
				/*nicename("Global Dynamic 35")*/ _output_color_b_global_dynamic_35 = 54ui16,
				/*nicename("Global Dynamic 36")*/ _output_color_b_global_dynamic_36 = 55ui16,
				/*nicename("Global Dynamic 37")*/ _output_color_b_global_dynamic_37 = 56ui16,
				/*nicename("Global Dynamic 38")*/ _output_color_b_global_dynamic_38 = 57ui16,
				/*nicename("Global Dynamic 39")*/ _output_color_b_global_dynamic_39 = 58ui16,
				/*nicename("Global Dynamic 40")*/ _output_color_b_global_dynamic_40 = 59ui16,
				/*nicename("Global Dynamic 41")*/ _output_color_b_global_dynamic_41 = 60ui16,
				/*nicename("Global Dynamic 42")*/ _output_color_b_global_dynamic_42 = 61ui16,
			};

			enum nicename("Output Color c") e_output_color_c : uint16_t
			{
				/*nicename("Local a")*/ _output_color_c_local_a = 1ui16,
				/*nicename("Local b")*/ _output_color_c_local_b = 2ui16,
				/*nicename("Local c")*/ _output_color_c_local_c = 3ui16,
				/*nicename("Local d")*/ _output_color_c_local_d = 4ui16,
				/*nicename("Unknown 4")*/ _output_color_c_unknown_4 = 5ui16,
				/*nicename("Unknown 5")*/ _output_color_c_unknown_5 = 6ui16,
				/*nicename("Scoreboard Friendly")*/ _output_color_c_scoreboard_friendly = 7ui16,
				/*nicename("Scoreboard Enemy")*/ _output_color_c_scoreboard_enemy = 8ui16,
				/*nicename("Arming Team")*/ _output_color_c_arming_team = 9ui16,
				/*nicename("Metagame Player 1")*/ _output_color_c_metagame_player_1 = 10ui16,
				/*nicename("Metagame Player 2")*/ _output_color_c_metagame_player_2 = 11ui16,
				/*nicename("Metagame Player 3")*/ _output_color_c_metagame_player_3 = 12ui16,
				/*nicename("Metagame Player 4")*/ _output_color_c_metagame_player_4 = 13ui16,
				/*nicename("Unknown 13")*/ _output_color_c_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _output_color_c_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _output_color_c_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _output_color_c_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _output_color_c_unknown_17 = 18ui16,
				/*nicename("Global Dynamic 0")*/ _output_color_c_global_dynamic_0 = 19ui16,
				/*nicename("Global Dynamic 1")*/ _output_color_c_global_dynamic_1 = 20ui16,
				/*nicename("Global Dynamic 2")*/ _output_color_c_global_dynamic_2 = 21ui16,
				/*nicename("Global Dynamic 3")*/ _output_color_c_global_dynamic_3 = 22ui16,
				/*nicename("Global Dynamic 4")*/ _output_color_c_global_dynamic_4 = 23ui16,
				/*nicename("Global Dynamic 5")*/ _output_color_c_global_dynamic_5 = 24ui16,
				/*nicename("Global Dynamic 6")*/ _output_color_c_global_dynamic_6 = 25ui16,
				/*nicename("Global Dynamic 7")*/ _output_color_c_global_dynamic_7 = 26ui16,
				/*nicename("Global Dynamic 8")*/ _output_color_c_global_dynamic_8 = 27ui16,
				/*nicename("Global Dynamic 9")*/ _output_color_c_global_dynamic_9 = 28ui16,
				/*nicename("Global Dynamic 10")*/ _output_color_c_global_dynamic_10 = 29ui16,
				/*nicename("Global Dynamic 11")*/ _output_color_c_global_dynamic_11 = 30ui16,
				/*nicename("Global Dynamic 12")*/ _output_color_c_global_dynamic_12 = 31ui16,
				/*nicename("Global Dynamic 13")*/ _output_color_c_global_dynamic_13 = 32ui16,
				/*nicename("Global Dynamic 14")*/ _output_color_c_global_dynamic_14 = 33ui16,
				/*nicename("Global Dynamic 15")*/ _output_color_c_global_dynamic_15 = 34ui16,
				/*nicename("Global Dynamic 16")*/ _output_color_c_global_dynamic_16 = 35ui16,
				/*nicename("Global Dynamic 17")*/ _output_color_c_global_dynamic_17 = 36ui16,
				/*nicename("Global Dynamic 18")*/ _output_color_c_global_dynamic_18 = 37ui16,
				/*nicename("Global Dynamic 19")*/ _output_color_c_global_dynamic_19 = 38ui16,
				/*nicename("Global Dynamic 20")*/ _output_color_c_global_dynamic_20 = 39ui16,
				/*nicename("Global Dynamic 21")*/ _output_color_c_global_dynamic_21 = 40ui16,
				/*nicename("Global Dynamic 22")*/ _output_color_c_global_dynamic_22 = 41ui16,
				/*nicename("Global Dynamic 23")*/ _output_color_c_global_dynamic_23 = 42ui16,
				/*nicename("Global Dynamic 24")*/ _output_color_c_global_dynamic_24 = 43ui16,
				/*nicename("Global Dynamic 25")*/ _output_color_c_global_dynamic_25 = 44ui16,
				/*nicename("Global Dynamic 26")*/ _output_color_c_global_dynamic_26 = 45ui16,
				/*nicename("Global Dynamic 27")*/ _output_color_c_global_dynamic_27 = 46ui16,
				/*nicename("Global Dynamic 28")*/ _output_color_c_global_dynamic_28 = 47ui16,
				/*nicename("Global Dynamic 29")*/ _output_color_c_global_dynamic_29 = 48ui16,
				/*nicename("Global Dynamic 30")*/ _output_color_c_global_dynamic_30 = 49ui16,
				/*nicename("Global Dynamic 31")*/ _output_color_c_global_dynamic_31 = 50ui16,
				/*nicename("Global Dynamic 32")*/ _output_color_c_global_dynamic_32 = 51ui16,
				/*nicename("Global Dynamic 33")*/ _output_color_c_global_dynamic_33 = 52ui16,
				/*nicename("Global Dynamic 34")*/ _output_color_c_global_dynamic_34 = 53ui16,
				/*nicename("Global Dynamic 35")*/ _output_color_c_global_dynamic_35 = 54ui16,
				/*nicename("Global Dynamic 36")*/ _output_color_c_global_dynamic_36 = 55ui16,
				/*nicename("Global Dynamic 37")*/ _output_color_c_global_dynamic_37 = 56ui16,
				/*nicename("Global Dynamic 38")*/ _output_color_c_global_dynamic_38 = 57ui16,
				/*nicename("Global Dynamic 39")*/ _output_color_c_global_dynamic_39 = 58ui16,
				/*nicename("Global Dynamic 40")*/ _output_color_c_global_dynamic_40 = 59ui16,
				/*nicename("Global Dynamic 41")*/ _output_color_c_global_dynamic_41 = 60ui16,
				/*nicename("Global Dynamic 42")*/ _output_color_c_global_dynamic_42 = 61ui16,
			};

			enum nicename("Output Color d") e_output_color_d : uint16_t
			{
				/*nicename("Local a")*/ _output_color_d_local_a = 1ui16,
				/*nicename("Local b")*/ _output_color_d_local_b = 2ui16,
				/*nicename("Local c")*/ _output_color_d_local_c = 3ui16,
				/*nicename("Local d")*/ _output_color_d_local_d = 4ui16,
				/*nicename("Unknown 4")*/ _output_color_d_unknown_4 = 5ui16,
				/*nicename("Unknown 5")*/ _output_color_d_unknown_5 = 6ui16,
				/*nicename("Scoreboard Friendly")*/ _output_color_d_scoreboard_friendly = 7ui16,
				/*nicename("Scoreboard Enemy")*/ _output_color_d_scoreboard_enemy = 8ui16,
				/*nicename("Arming Team")*/ _output_color_d_arming_team = 9ui16,
				/*nicename("Metagame Player 1")*/ _output_color_d_metagame_player_1 = 10ui16,
				/*nicename("Metagame Player 2")*/ _output_color_d_metagame_player_2 = 11ui16,
				/*nicename("Metagame Player 3")*/ _output_color_d_metagame_player_3 = 12ui16,
				/*nicename("Metagame Player 4")*/ _output_color_d_metagame_player_4 = 13ui16,
				/*nicename("Unknown 13")*/ _output_color_d_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _output_color_d_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _output_color_d_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _output_color_d_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _output_color_d_unknown_17 = 18ui16,
				/*nicename("Global Dynamic 0")*/ _output_color_d_global_dynamic_0 = 19ui16,
				/*nicename("Global Dynamic 1")*/ _output_color_d_global_dynamic_1 = 20ui16,
				/*nicename("Global Dynamic 2")*/ _output_color_d_global_dynamic_2 = 21ui16,
				/*nicename("Global Dynamic 3")*/ _output_color_d_global_dynamic_3 = 22ui16,
				/*nicename("Global Dynamic 4")*/ _output_color_d_global_dynamic_4 = 23ui16,
				/*nicename("Global Dynamic 5")*/ _output_color_d_global_dynamic_5 = 24ui16,
				/*nicename("Global Dynamic 6")*/ _output_color_d_global_dynamic_6 = 25ui16,
				/*nicename("Global Dynamic 7")*/ _output_color_d_global_dynamic_7 = 26ui16,
				/*nicename("Global Dynamic 8")*/ _output_color_d_global_dynamic_8 = 27ui16,
				/*nicename("Global Dynamic 9")*/ _output_color_d_global_dynamic_9 = 28ui16,
				/*nicename("Global Dynamic 10")*/ _output_color_d_global_dynamic_10 = 29ui16,
				/*nicename("Global Dynamic 11")*/ _output_color_d_global_dynamic_11 = 30ui16,
				/*nicename("Global Dynamic 12")*/ _output_color_d_global_dynamic_12 = 31ui16,
				/*nicename("Global Dynamic 13")*/ _output_color_d_global_dynamic_13 = 32ui16,
				/*nicename("Global Dynamic 14")*/ _output_color_d_global_dynamic_14 = 33ui16,
				/*nicename("Global Dynamic 15")*/ _output_color_d_global_dynamic_15 = 34ui16,
				/*nicename("Global Dynamic 16")*/ _output_color_d_global_dynamic_16 = 35ui16,
				/*nicename("Global Dynamic 17")*/ _output_color_d_global_dynamic_17 = 36ui16,
				/*nicename("Global Dynamic 18")*/ _output_color_d_global_dynamic_18 = 37ui16,
				/*nicename("Global Dynamic 19")*/ _output_color_d_global_dynamic_19 = 38ui16,
				/*nicename("Global Dynamic 20")*/ _output_color_d_global_dynamic_20 = 39ui16,
				/*nicename("Global Dynamic 21")*/ _output_color_d_global_dynamic_21 = 40ui16,
				/*nicename("Global Dynamic 22")*/ _output_color_d_global_dynamic_22 = 41ui16,
				/*nicename("Global Dynamic 23")*/ _output_color_d_global_dynamic_23 = 42ui16,
				/*nicename("Global Dynamic 24")*/ _output_color_d_global_dynamic_24 = 43ui16,
				/*nicename("Global Dynamic 25")*/ _output_color_d_global_dynamic_25 = 44ui16,
				/*nicename("Global Dynamic 26")*/ _output_color_d_global_dynamic_26 = 45ui16,
				/*nicename("Global Dynamic 27")*/ _output_color_d_global_dynamic_27 = 46ui16,
				/*nicename("Global Dynamic 28")*/ _output_color_d_global_dynamic_28 = 47ui16,
				/*nicename("Global Dynamic 29")*/ _output_color_d_global_dynamic_29 = 48ui16,
				/*nicename("Global Dynamic 30")*/ _output_color_d_global_dynamic_30 = 49ui16,
				/*nicename("Global Dynamic 31")*/ _output_color_d_global_dynamic_31 = 50ui16,
				/*nicename("Global Dynamic 32")*/ _output_color_d_global_dynamic_32 = 51ui16,
				/*nicename("Global Dynamic 33")*/ _output_color_d_global_dynamic_33 = 52ui16,
				/*nicename("Global Dynamic 34")*/ _output_color_d_global_dynamic_34 = 53ui16,
				/*nicename("Global Dynamic 35")*/ _output_color_d_global_dynamic_35 = 54ui16,
				/*nicename("Global Dynamic 36")*/ _output_color_d_global_dynamic_36 = 55ui16,
				/*nicename("Global Dynamic 37")*/ _output_color_d_global_dynamic_37 = 56ui16,
				/*nicename("Global Dynamic 38")*/ _output_color_d_global_dynamic_38 = 57ui16,
				/*nicename("Global Dynamic 39")*/ _output_color_d_global_dynamic_39 = 58ui16,
				/*nicename("Global Dynamic 40")*/ _output_color_d_global_dynamic_40 = 59ui16,
				/*nicename("Global Dynamic 41")*/ _output_color_d_global_dynamic_41 = 60ui16,
				/*nicename("Global Dynamic 42")*/ _output_color_d_global_dynamic_42 = 61ui16,
			};

			enum nicename("Output Color e") e_output_color_e : uint16_t
			{
				/*nicename("Local a")*/ _output_color_e_local_a = 1ui16,
				/*nicename("Local b")*/ _output_color_e_local_b = 2ui16,
				/*nicename("Local c")*/ _output_color_e_local_c = 3ui16,
				/*nicename("Local d")*/ _output_color_e_local_d = 4ui16,
				/*nicename("Unknown 4")*/ _output_color_e_unknown_4 = 5ui16,
				/*nicename("Unknown 5")*/ _output_color_e_unknown_5 = 6ui16,
				/*nicename("Scoreboard Friendly")*/ _output_color_e_scoreboard_friendly = 7ui16,
				/*nicename("Scoreboard Enemy")*/ _output_color_e_scoreboard_enemy = 8ui16,
				/*nicename("Arming Team")*/ _output_color_e_arming_team = 9ui16,
				/*nicename("Metagame Player 1")*/ _output_color_e_metagame_player_1 = 10ui16,
				/*nicename("Metagame Player 2")*/ _output_color_e_metagame_player_2 = 11ui16,
				/*nicename("Metagame Player 3")*/ _output_color_e_metagame_player_3 = 12ui16,
				/*nicename("Metagame Player 4")*/ _output_color_e_metagame_player_4 = 13ui16,
				/*nicename("Unknown 13")*/ _output_color_e_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _output_color_e_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _output_color_e_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _output_color_e_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _output_color_e_unknown_17 = 18ui16,
				/*nicename("Global Dynamic 0")*/ _output_color_e_global_dynamic_0 = 19ui16,
				/*nicename("Global Dynamic 1")*/ _output_color_e_global_dynamic_1 = 20ui16,
				/*nicename("Global Dynamic 2")*/ _output_color_e_global_dynamic_2 = 21ui16,
				/*nicename("Global Dynamic 3")*/ _output_color_e_global_dynamic_3 = 22ui16,
				/*nicename("Global Dynamic 4")*/ _output_color_e_global_dynamic_4 = 23ui16,
				/*nicename("Global Dynamic 5")*/ _output_color_e_global_dynamic_5 = 24ui16,
				/*nicename("Global Dynamic 6")*/ _output_color_e_global_dynamic_6 = 25ui16,
				/*nicename("Global Dynamic 7")*/ _output_color_e_global_dynamic_7 = 26ui16,
				/*nicename("Global Dynamic 8")*/ _output_color_e_global_dynamic_8 = 27ui16,
				/*nicename("Global Dynamic 9")*/ _output_color_e_global_dynamic_9 = 28ui16,
				/*nicename("Global Dynamic 10")*/ _output_color_e_global_dynamic_10 = 29ui16,
				/*nicename("Global Dynamic 11")*/ _output_color_e_global_dynamic_11 = 30ui16,
				/*nicename("Global Dynamic 12")*/ _output_color_e_global_dynamic_12 = 31ui16,
				/*nicename("Global Dynamic 13")*/ _output_color_e_global_dynamic_13 = 32ui16,
				/*nicename("Global Dynamic 14")*/ _output_color_e_global_dynamic_14 = 33ui16,
				/*nicename("Global Dynamic 15")*/ _output_color_e_global_dynamic_15 = 34ui16,
				/*nicename("Global Dynamic 16")*/ _output_color_e_global_dynamic_16 = 35ui16,
				/*nicename("Global Dynamic 17")*/ _output_color_e_global_dynamic_17 = 36ui16,
				/*nicename("Global Dynamic 18")*/ _output_color_e_global_dynamic_18 = 37ui16,
				/*nicename("Global Dynamic 19")*/ _output_color_e_global_dynamic_19 = 38ui16,
				/*nicename("Global Dynamic 20")*/ _output_color_e_global_dynamic_20 = 39ui16,
				/*nicename("Global Dynamic 21")*/ _output_color_e_global_dynamic_21 = 40ui16,
				/*nicename("Global Dynamic 22")*/ _output_color_e_global_dynamic_22 = 41ui16,
				/*nicename("Global Dynamic 23")*/ _output_color_e_global_dynamic_23 = 42ui16,
				/*nicename("Global Dynamic 24")*/ _output_color_e_global_dynamic_24 = 43ui16,
				/*nicename("Global Dynamic 25")*/ _output_color_e_global_dynamic_25 = 44ui16,
				/*nicename("Global Dynamic 26")*/ _output_color_e_global_dynamic_26 = 45ui16,
				/*nicename("Global Dynamic 27")*/ _output_color_e_global_dynamic_27 = 46ui16,
				/*nicename("Global Dynamic 28")*/ _output_color_e_global_dynamic_28 = 47ui16,
				/*nicename("Global Dynamic 29")*/ _output_color_e_global_dynamic_29 = 48ui16,
				/*nicename("Global Dynamic 30")*/ _output_color_e_global_dynamic_30 = 49ui16,
				/*nicename("Global Dynamic 31")*/ _output_color_e_global_dynamic_31 = 50ui16,
				/*nicename("Global Dynamic 32")*/ _output_color_e_global_dynamic_32 = 51ui16,
				/*nicename("Global Dynamic 33")*/ _output_color_e_global_dynamic_33 = 52ui16,
				/*nicename("Global Dynamic 34")*/ _output_color_e_global_dynamic_34 = 53ui16,
				/*nicename("Global Dynamic 35")*/ _output_color_e_global_dynamic_35 = 54ui16,
				/*nicename("Global Dynamic 36")*/ _output_color_e_global_dynamic_36 = 55ui16,
				/*nicename("Global Dynamic 37")*/ _output_color_e_global_dynamic_37 = 56ui16,
				/*nicename("Global Dynamic 38")*/ _output_color_e_global_dynamic_38 = 57ui16,
				/*nicename("Global Dynamic 39")*/ _output_color_e_global_dynamic_39 = 58ui16,
				/*nicename("Global Dynamic 40")*/ _output_color_e_global_dynamic_40 = 59ui16,
				/*nicename("Global Dynamic 41")*/ _output_color_e_global_dynamic_41 = 60ui16,
				/*nicename("Global Dynamic 42")*/ _output_color_e_global_dynamic_42 = 61ui16,
			};

			enum nicename("Output Color f") e_output_color_f : uint16_t
			{
				/*nicename("Local a")*/ _output_color_f_local_a = 1ui16,
				/*nicename("Local b")*/ _output_color_f_local_b = 2ui16,
				/*nicename("Local c")*/ _output_color_f_local_c = 3ui16,
				/*nicename("Local d")*/ _output_color_f_local_d = 4ui16,
				/*nicename("Unknown 4")*/ _output_color_f_unknown_4 = 5ui16,
				/*nicename("Unknown 5")*/ _output_color_f_unknown_5 = 6ui16,
				/*nicename("Scoreboard Friendly")*/ _output_color_f_scoreboard_friendly = 7ui16,
				/*nicename("Scoreboard Enemy")*/ _output_color_f_scoreboard_enemy = 8ui16,
				/*nicename("Arming Team")*/ _output_color_f_arming_team = 9ui16,
				/*nicename("Metagame Player 1")*/ _output_color_f_metagame_player_1 = 10ui16,
				/*nicename("Metagame Player 2")*/ _output_color_f_metagame_player_2 = 11ui16,
				/*nicename("Metagame Player 3")*/ _output_color_f_metagame_player_3 = 12ui16,
				/*nicename("Metagame Player 4")*/ _output_color_f_metagame_player_4 = 13ui16,
				/*nicename("Unknown 13")*/ _output_color_f_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _output_color_f_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _output_color_f_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _output_color_f_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _output_color_f_unknown_17 = 18ui16,
				/*nicename("Global Dynamic 0")*/ _output_color_f_global_dynamic_0 = 19ui16,
				/*nicename("Global Dynamic 1")*/ _output_color_f_global_dynamic_1 = 20ui16,
				/*nicename("Global Dynamic 2")*/ _output_color_f_global_dynamic_2 = 21ui16,
				/*nicename("Global Dynamic 3")*/ _output_color_f_global_dynamic_3 = 22ui16,
				/*nicename("Global Dynamic 4")*/ _output_color_f_global_dynamic_4 = 23ui16,
				/*nicename("Global Dynamic 5")*/ _output_color_f_global_dynamic_5 = 24ui16,
				/*nicename("Global Dynamic 6")*/ _output_color_f_global_dynamic_6 = 25ui16,
				/*nicename("Global Dynamic 7")*/ _output_color_f_global_dynamic_7 = 26ui16,
				/*nicename("Global Dynamic 8")*/ _output_color_f_global_dynamic_8 = 27ui16,
				/*nicename("Global Dynamic 9")*/ _output_color_f_global_dynamic_9 = 28ui16,
				/*nicename("Global Dynamic 10")*/ _output_color_f_global_dynamic_10 = 29ui16,
				/*nicename("Global Dynamic 11")*/ _output_color_f_global_dynamic_11 = 30ui16,
				/*nicename("Global Dynamic 12")*/ _output_color_f_global_dynamic_12 = 31ui16,
				/*nicename("Global Dynamic 13")*/ _output_color_f_global_dynamic_13 = 32ui16,
				/*nicename("Global Dynamic 14")*/ _output_color_f_global_dynamic_14 = 33ui16,
				/*nicename("Global Dynamic 15")*/ _output_color_f_global_dynamic_15 = 34ui16,
				/*nicename("Global Dynamic 16")*/ _output_color_f_global_dynamic_16 = 35ui16,
				/*nicename("Global Dynamic 17")*/ _output_color_f_global_dynamic_17 = 36ui16,
				/*nicename("Global Dynamic 18")*/ _output_color_f_global_dynamic_18 = 37ui16,
				/*nicename("Global Dynamic 19")*/ _output_color_f_global_dynamic_19 = 38ui16,
				/*nicename("Global Dynamic 20")*/ _output_color_f_global_dynamic_20 = 39ui16,
				/*nicename("Global Dynamic 21")*/ _output_color_f_global_dynamic_21 = 40ui16,
				/*nicename("Global Dynamic 22")*/ _output_color_f_global_dynamic_22 = 41ui16,
				/*nicename("Global Dynamic 23")*/ _output_color_f_global_dynamic_23 = 42ui16,
				/*nicename("Global Dynamic 24")*/ _output_color_f_global_dynamic_24 = 43ui16,
				/*nicename("Global Dynamic 25")*/ _output_color_f_global_dynamic_25 = 44ui16,
				/*nicename("Global Dynamic 26")*/ _output_color_f_global_dynamic_26 = 45ui16,
				/*nicename("Global Dynamic 27")*/ _output_color_f_global_dynamic_27 = 46ui16,
				/*nicename("Global Dynamic 28")*/ _output_color_f_global_dynamic_28 = 47ui16,
				/*nicename("Global Dynamic 29")*/ _output_color_f_global_dynamic_29 = 48ui16,
				/*nicename("Global Dynamic 30")*/ _output_color_f_global_dynamic_30 = 49ui16,
				/*nicename("Global Dynamic 31")*/ _output_color_f_global_dynamic_31 = 50ui16,
				/*nicename("Global Dynamic 32")*/ _output_color_f_global_dynamic_32 = 51ui16,
				/*nicename("Global Dynamic 33")*/ _output_color_f_global_dynamic_33 = 52ui16,
				/*nicename("Global Dynamic 34")*/ _output_color_f_global_dynamic_34 = 53ui16,
				/*nicename("Global Dynamic 35")*/ _output_color_f_global_dynamic_35 = 54ui16,
				/*nicename("Global Dynamic 36")*/ _output_color_f_global_dynamic_36 = 55ui16,
				/*nicename("Global Dynamic 37")*/ _output_color_f_global_dynamic_37 = 56ui16,
				/*nicename("Global Dynamic 38")*/ _output_color_f_global_dynamic_38 = 57ui16,
				/*nicename("Global Dynamic 39")*/ _output_color_f_global_dynamic_39 = 58ui16,
				/*nicename("Global Dynamic 40")*/ _output_color_f_global_dynamic_40 = 59ui16,
				/*nicename("Global Dynamic 41")*/ _output_color_f_global_dynamic_41 = 60ui16,
				/*nicename("Global Dynamic 42")*/ _output_color_f_global_dynamic_42 = 61ui16,
			};

			enum nicename("Output Scalar a") e_output_scalar_a : uint16_t
			{
				/*nicename("Unknown 0")*/ _output_scalar_a_unknown_0 = 1ui16,
				/*nicename("Unknown 1")*/ _output_scalar_a_unknown_1 = 2ui16,
				/*nicename("Input")*/ _output_scalar_a_input = 3ui16,
				/*nicename("Range Input")*/ _output_scalar_a_range_input = 4ui16,
				/*nicename("Local a")*/ _output_scalar_a_local_a = 5ui16,
				/*nicename("Local b")*/ _output_scalar_a_local_b = 6ui16,
				/*nicename("Local c")*/ _output_scalar_a_local_c = 7ui16,
				/*nicename("Local d")*/ _output_scalar_a_local_d = 8ui16,
				/*nicename("Unknown 8")*/ _output_scalar_a_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _output_scalar_a_unknown_9 = 10ui16,
			};

			enum nicename("Output Scalar b") e_output_scalar_b : uint16_t
			{
				/*nicename("Unknown 0")*/ _output_scalar_b_unknown_0 = 1ui16,
				/*nicename("Unknown 1")*/ _output_scalar_b_unknown_1 = 2ui16,
				/*nicename("Input")*/ _output_scalar_b_input = 3ui16,
				/*nicename("Range Input")*/ _output_scalar_b_range_input = 4ui16,
				/*nicename("Local a")*/ _output_scalar_b_local_a = 5ui16,
				/*nicename("Local b")*/ _output_scalar_b_local_b = 6ui16,
				/*nicename("Local c")*/ _output_scalar_b_local_c = 7ui16,
				/*nicename("Local d")*/ _output_scalar_b_local_d = 8ui16,
				/*nicename("Unknown 8")*/ _output_scalar_b_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _output_scalar_b_unknown_9 = 10ui16,
			};

			enum nicename("Output Scalar c") e_output_scalar_c : uint16_t
			{
				/*nicename("Unknown 0")*/ _output_scalar_c_unknown_0 = 1ui16,
				/*nicename("Unknown 1")*/ _output_scalar_c_unknown_1 = 2ui16,
				/*nicename("Input")*/ _output_scalar_c_input = 3ui16,
				/*nicename("Range Input")*/ _output_scalar_c_range_input = 4ui16,
				/*nicename("Local a")*/ _output_scalar_c_local_a = 5ui16,
				/*nicename("Local b")*/ _output_scalar_c_local_b = 6ui16,
				/*nicename("Local c")*/ _output_scalar_c_local_c = 7ui16,
				/*nicename("Local d")*/ _output_scalar_c_local_d = 8ui16,
				/*nicename("Unknown 8")*/ _output_scalar_c_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _output_scalar_c_unknown_9 = 10ui16,
			};

			enum nicename("Output Scalar d") e_output_scalar_d : uint16_t
			{
				/*nicename("Unknown 0")*/ _output_scalar_d_unknown_0 = 1ui16,
				/*nicename("Unknown 1")*/ _output_scalar_d_unknown_1 = 2ui16,
				/*nicename("Input")*/ _output_scalar_d_input = 3ui16,
				/*nicename("Range Input")*/ _output_scalar_d_range_input = 4ui16,
				/*nicename("Local a")*/ _output_scalar_d_local_a = 5ui16,
				/*nicename("Local b")*/ _output_scalar_d_local_b = 6ui16,
				/*nicename("Local c")*/ _output_scalar_d_local_c = 7ui16,
				/*nicename("Local d")*/ _output_scalar_d_local_d = 8ui16,
				/*nicename("Unknown 8")*/ _output_scalar_d_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _output_scalar_d_unknown_9 = 10ui16,
			};

			enum nicename("Output Scalar e") e_output_scalar_e : uint16_t
			{
				/*nicename("Unknown 0")*/ _output_scalar_e_unknown_0 = 1ui16,
				/*nicename("Unknown 1")*/ _output_scalar_e_unknown_1 = 2ui16,
				/*nicename("Input")*/ _output_scalar_e_input = 3ui16,
				/*nicename("Range Input")*/ _output_scalar_e_range_input = 4ui16,
				/*nicename("Local a")*/ _output_scalar_e_local_a = 5ui16,
				/*nicename("Local b")*/ _output_scalar_e_local_b = 6ui16,
				/*nicename("Local c")*/ _output_scalar_e_local_c = 7ui16,
				/*nicename("Local d")*/ _output_scalar_e_local_d = 8ui16,
				/*nicename("Unknown 8")*/ _output_scalar_e_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _output_scalar_e_unknown_9 = 10ui16,
			};

			enum nicename("Output Scalar f") e_output_scalar_f : uint16_t
			{
				/*nicename("Unknown 0")*/ _output_scalar_f_unknown_0 = 1ui16,
				/*nicename("Unknown 1")*/ _output_scalar_f_unknown_1 = 2ui16,
				/*nicename("Input")*/ _output_scalar_f_input = 3ui16,
				/*nicename("Range Input")*/ _output_scalar_f_range_input = 4ui16,
				/*nicename("Local a")*/ _output_scalar_f_local_a = 5ui16,
				/*nicename("Local b")*/ _output_scalar_f_local_b = 6ui16,
				/*nicename("Local c")*/ _output_scalar_f_local_c = 7ui16,
				/*nicename("Local d")*/ _output_scalar_f_local_d = 8ui16,
				/*nicename("Unknown 8")*/ _output_scalar_f_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _output_scalar_f_unknown_9 = 10ui16,
			};

			e_shader_index nicename("Shader Index") shader_index;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			float nicename("Local Color Alpha a") local_color_alpha_a;
			colorf nicename("Local Color a") local_color_a;
			float nicename("Local Color Alpha b") local_color_alpha_b;
			colorf nicename("Local Color b") local_color_b;
			float nicename("Local Color Alpha c") local_color_alpha_c;
			colorf nicename("Local Color c") local_color_c;
			float nicename("Local Color Alpha d") local_color_alpha_d;
			colorf nicename("Local Color d") local_color_d;
			float nicename("Local Scalar a") local_scalar_a;
			float nicename("Local Scalar b") local_scalar_b;
			float nicename("Local Scalar c") local_scalar_c;
			float nicename("Local Scalar d") local_scalar_d;
			e_output_color_a nicename("Output Color a") output_color_a;
			e_output_color_b nicename("Output Color b") output_color_b;
			e_output_color_c nicename("Output Color c") output_color_c;
			e_output_color_d nicename("Output Color d") output_color_d;
			e_output_color_e nicename("Output Color e") output_color_e;
			e_output_color_f nicename("Output Color f") output_color_f;
			e_output_scalar_a nicename("Output Scalar a") output_scalar_a;
			e_output_scalar_b nicename("Output Scalar b") output_scalar_b;
			e_output_scalar_c nicename("Output Scalar c") output_scalar_c;
			e_output_scalar_d nicename("Output Scalar d") output_scalar_d;
			e_output_scalar_e nicename("Output Scalar e") output_scalar_e;
			e_output_scalar_f nicename("Output Scalar f") output_scalar_f;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
			int16_t __unknown5;
			int16_t __unknown6;
		};

		struct nicename("Datasource") s_datasource_definition
		{
			struct nicename("Unknown 6") s_unknown_6_definition
			{
				float __unknown0;
				float __unknown1;
				float __unknown2;
				float __unknown3;
			};

			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int16_t __unknown4;
			int16_t __unknown5;
			Undefined32 __unknown6;
			Undefined32 __unknown7;
			Undefined32 __unknown8;
			s_tag_block_definition<s_unknown_6_definition> nicename("Unknown 6") unknown_6_block;
		};

		struct nicename("Bitmap Widgets") s_bitmap_widgets_definition
		{
			enum nicename("Special HUD Type") e_special_hud_type : uint8_t
			{
				/*nicename("Unspecial")*/ _special_hud_type_unspecial = 1ui8,
				/*nicename("Ammo")*/ _special_hud_type_ammo = 2ui8,
				/*nicename("Crosshair and Scope")*/ _special_hud_type_crosshair_and_scope = 3ui8,
				/*nicename("Unit Shield Meter")*/ _special_hud_type_unit_shield_meter = 4ui8,
				/*nicename("Grenades")*/ _special_hud_type_grenades = 5ui8,
				/*nicename("Gametype")*/ _special_hud_type_gametype = 6ui8,
				/*nicename("Motion Sensor")*/ _special_hud_type_motion_sensor = 7ui8,
				/*nicename("Unknown")*/ _special_hud_type_unknown = 8ui8,
				/*nicename("m70_bonus")*/ _special_hud_type_m70_bonus = 9ui8,
			};

			enum nicename("Import Input") e_import_input : uint16_t
			{
				/*nicename("Zero")*/ _import_input_zero = 1ui16,
				/*nicename("One")*/ _import_input_one = 2ui16,
				/*nicename("Unknown 2")*/ _import_input_unknown_2 = 3ui16,
				/*nicename("Unknown 3")*/ _import_input_unknown_3 = 4ui16,
				/*nicename("Unknown 4")*/ _import_input_unknown_4 = 5ui16,
				/*nicename("Time")*/ _import_input_time = 6ui16,
				/*nicename("Fade")*/ _import_input_fade = 7ui16,
				/*nicename("Unknown 7")*/ _import_input_unknown_7 = 8ui16,
				/*nicename("Unknown 8")*/ _import_input_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _import_input_unknown_9 = 10ui16,
				/*nicename("Unknown 10")*/ _import_input_unknown_10 = 11ui16,
				/*nicename("Unknown 11")*/ _import_input_unknown_11 = 12ui16,
				/*nicename("Unknown 12")*/ _import_input_unknown_12 = 13ui16,
				/*nicename("Unknown 13")*/ _import_input_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _import_input_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _import_input_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _import_input_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _import_input_unknown_17 = 18ui16,
				/*nicename("Unknown 18")*/ _import_input_unknown_18 = 19ui16,
				/*nicename("Unknown 19")*/ _import_input_unknown_19 = 20ui16,
				/*nicename("Unknown 20")*/ _import_input_unknown_20 = 21ui16,
				/*nicename("Saber Unknown 1")*/ _import_input_saber_unknown_1 = 22ui16,
				/*nicename("Vehicle Health Current Percentage")*/ _import_input_vehicle_health_current_percentage = 23ui16,
				/*nicename("Unit Health Current")*/ _import_input_unit_health_current = 24ui16,
				/*nicename("Unit Health")*/ _import_input_unit_health = 25ui16,
				/*nicename("Unit Shield Current")*/ _import_input_unit_shield_current = 26ui16,
				/*nicename("Unit 1x Overshield Current")*/ _import_input_unit_1x_overshield_current = 27ui16,
				/*nicename("Unit 2x Overshield Current")*/ _import_input_unit_2x_overshield_current = 28ui16,
				/*nicename("Unit 2x Overshield Current")*/ _import_input_unit_2x_overshield_current1 = 29ui16,
				/*nicename("Unit Shield")*/ _import_input_unit_shield = 30ui16,
				/*nicename("Unit 1x Overshield")*/ _import_input_unit_1x_overshield = 31ui16,
				/*nicename("Unit 2x Overshield")*/ _import_input_unit_2x_overshield = 32ui16,
				/*nicename("Unit 3x Overshield")*/ _import_input_unit_3x_overshield = 33ui16,
				/*nicename("Unit Shield Current Percentage")*/ _import_input_unit_shield_current_percentage = 34ui16,
				/*nicename("Vehicle Shield Current Percentage")*/ _import_input_vehicle_shield_current_percentage = 35ui16,
				/*nicename("Boost Energy Fraction")*/ _import_input_boost_energy_fraction = 36ui16,
				/*nicename("Unknown 36")*/ _import_input_unknown_36 = 37ui16,
				/*nicename("Aim Yaw")*/ _import_input_aim_yaw = 38ui16,
				/*nicename("Aim Pitch")*/ _import_input_aim_pitch = 39ui16,
				/*nicename("Saber Waypoint Distance")*/ _import_input_saber_waypoint_distance = 40ui16,
				/*nicename("Sensor Range")*/ _import_input_sensor_range = 41ui16,
				/*nicename("Unit Altitude 1")*/ _import_input_unit_altitude_1 = 42ui16,
				/*nicename("Unit Altitude 2")*/ _import_input_unit_altitude_2 = 43ui16,
				/*nicename("Unknown 43")*/ _import_input_unknown_43 = 44ui16,
				/*nicename("Softkill Timer")*/ _import_input_softkill_timer = 45ui16,
				/*nicename("Transient Credits")*/ _import_input_transient_credits = 46ui16,
				/*nicename("Unknown 46")*/ _import_input_unknown_46 = 47ui16,
				/*nicename("Clip Ammo Fraction")*/ _import_input_clip_ammo_fraction = 48ui16,
				/*nicename("Total Ammo Fraction")*/ _import_input_total_ammo_fraction = 49ui16,
				/*nicename("Pickup")*/ _import_input_pickup = 50ui16,
				/*nicename("Heat Fraction")*/ _import_input_heat_fraction = 51ui16,
				/*nicename("Airstrike Charge Fraction")*/ _import_input_airstrike_charge_fraction = 52ui16,
				/*nicename("Battery Fraction")*/ _import_input_battery_fraction = 53ui16,
				/*nicename("Unknown 53")*/ _import_input_unknown_53 = 54ui16,
				/*nicename("Unknown 54")*/ _import_input_unknown_54 = 55ui16,
				/*nicename("Weapon Error")*/ _import_input_weapon_error = 56ui16,
				/*nicename("Unknown Weapon Error")*/ _import_input_unknown_weapon_error = 57ui16,
				/*nicename("Unit Autoaimed")*/ _import_input_unit_autoaimed = 58ui16,
				/*nicename("Saber Waypoint Distance Current")*/ _import_input_saber_waypoint_distance_current = 59ui16,
				/*nicename("Airstrike Distance")*/ _import_input_airstrike_distance = 60ui16,
				/*nicename("Nav Point Airstrike")*/ _import_input_nav_point_airstrike = 61ui16,
				/*nicename("Airstrike Ammo")*/ _import_input_airstrike_ammo = 62ui16,
				/*nicename("Unknown 62")*/ _import_input_unknown_62 = 63ui16,
				/*nicename("Unknown 63")*/ _import_input_unknown_63 = 64ui16,
				/*nicename("Grenade Fraction")*/ _import_input_grenade_fraction = 65ui16,
				/*nicename("Unknown 65")*/ _import_input_unknown_65 = 66ui16,
				/*nicename("Charge Fraction")*/ _import_input_charge_fraction = 67ui16,
				/*nicename("Unknown 67")*/ _import_input_unknown_67 = 68ui16,
				/*nicename("Trigger Cooldown")*/ _import_input_trigger_cooldown = 69ui16,
				/*nicename("Trigger Remote Detonate Fraction")*/ _import_input_trigger_remote_detonate_fraction = 70ui16,
				/*nicename("Trigger Locked On")*/ _import_input_trigger_locked_on = 71ui16,
				/*nicename("Target Distance")*/ _import_input_target_distance = 72ui16,
				/*nicename("Target Elevation")*/ _import_input_target_elevation = 73ui16,
				/*nicename("Equipment Energy Fraction")*/ _import_input_equipment_energy_fraction = 74ui16,
				/*nicename("Unknown 74")*/ _import_input_unknown_74 = 75ui16,
				/*nicename("Unknown 75")*/ _import_input_unknown_75 = 76ui16,
				/*nicename("Unknown 76")*/ _import_input_unknown_76 = 77ui16,
				/*nicename("Unknown 77")*/ _import_input_unknown_77 = 78ui16,
				/*nicename("Unknown 78")*/ _import_input_unknown_78 = 79ui16,
				/*nicename("Unknown 79")*/ _import_input_unknown_79 = 80ui16,
				/*nicename("Medal Commendation")*/ _import_input_medal_commendation = 81ui16,
				/*nicename("Generator Health Current")*/ _import_input_generator_health_current = 82ui16,
				/*nicename("Generator Health")*/ _import_input_generator_health = 83ui16,
				/*nicename("Unknown 83")*/ _import_input_unknown_83 = 84ui16,
				/*nicename("Waypoint")*/ _import_input_waypoint = 85ui16,
				/*nicename("Unknown 85")*/ _import_input_unknown_85 = 86ui16,
				/*nicename("Unknown 86")*/ _import_input_unknown_86 = 87ui16,
				/*nicename("Waypoint Onscreen")*/ _import_input_waypoint_onscreen = 88ui16,
				/*nicename("Waypoint Offscreen")*/ _import_input_waypoint_offscreen = 89ui16,
				/*nicename("Gametype Plate")*/ _import_input_gametype_plate = 90ui16,
				/*nicename("Offense Defense")*/ _import_input_offense_defense = 91ui16,
				/*nicename("Metagame Time")*/ _import_input_metagame_time = 92ui16,
				/*nicename("Metagame Score Transient")*/ _import_input_metagame_score_transient = 93ui16,
				/*nicename("Metagame Score Player 1")*/ _import_input_metagame_score_player_1 = 94ui16,
				/*nicename("Unknown 94")*/ _import_input_unknown_94 = 95ui16,
				/*nicename("Unknown 95")*/ _import_input_unknown_95 = 96ui16,
				/*nicename("Unknown 96")*/ _import_input_unknown_96 = 97ui16,
				/*nicename("Unknown 97")*/ _import_input_unknown_97 = 98ui16,
				/*nicename("Unknown 98")*/ _import_input_unknown_98 = 99ui16,
				/*nicename("Unknown 99")*/ _import_input_unknown_99 = 100ui16,
				/*nicename("Survival Multiplier")*/ _import_input_survival_multiplier = 101ui16,
				/*nicename("Metagame Score Negative")*/ _import_input_metagame_score_negative = 102ui16,
				/*nicename("Survival Set")*/ _import_input_survival_set = 103ui16,
				/*nicename("Unknown 103")*/ _import_input_unknown_103 = 104ui16,
				/*nicename("Survival Waves Background")*/ _import_input_survival_waves_background = 105ui16,
				/*nicename("Survival Lives 1")*/ _import_input_survival_lives_1 = 106ui16,
				/*nicename("Survival Lives 2")*/ _import_input_survival_lives_2 = 107ui16,
				/*nicename("Survival Bonus Timer")*/ _import_input_survival_bonus_timer = 108ui16,
				/*nicename("Unknown 108")*/ _import_input_unknown_108 = 109ui16,
				/*nicename("Unknown 109")*/ _import_input_unknown_109 = 110ui16,
				/*nicename("Friendly Score")*/ _import_input_friendly_score = 111ui16,
				/*nicename("Enemy Score")*/ _import_input_enemy_score = 112ui16,
				/*nicename("Score To Win")*/ _import_input_score_to_win = 113ui16,
				/*nicename("Arming Fraction")*/ _import_input_arming_fraction = 114ui16,
				/*nicename("Posession Icon")*/ _import_input_posession_icon = 115ui16,
				/*nicename("Arming Unknown")*/ _import_input_arming_unknown = 116ui16,
				/*nicename("Omniwidget Icon")*/ _import_input_omniwidget_icon = 117ui16,
				/*nicename("Unknown 117")*/ _import_input_unknown_117 = 118ui16,
				/*nicename("Fireteam Health")*/ _import_input_fireteam_health = 119ui16,
				/*nicename("Unknown 119")*/ _import_input_unknown_119 = 120ui16,
				/*nicename("Unknown 120")*/ _import_input_unknown_120 = 121ui16,
				/*nicename("Unknown 121")*/ _import_input_unknown_121 = 122ui16,
				/*nicename("Fireteam Current Shield")*/ _import_input_fireteam_current_shield = 123ui16,
				/*nicename("Unknown 123")*/ _import_input_unknown_123 = 124ui16,
				/*nicename("Unknown 124")*/ _import_input_unknown_124 = 125ui16,
				/*nicename("Fireteam 1 Arming Fraction")*/ _import_input_fireteam_1_arming_fraction = 126ui16,
				/*nicename("Fireteam 2 Arming Fraction")*/ _import_input_fireteam_2_arming_fraction = 127ui16,
				/*nicename("Unknown 127")*/ _import_input_unknown_127 = 128ui16,
				/*nicename("Fireteam 1 Directional Arrow")*/ _import_input_fireteam_1_directional_arrow = 129ui16,
				/*nicename("Fireteam 2 Directional Arrow")*/ _import_input_fireteam_2_directional_arrow = 130ui16,
				/*nicename("Unknown 130")*/ _import_input_unknown_130 = 131ui16,
				/*nicename("Unknown 131")*/ _import_input_unknown_131 = 132ui16,
				/*nicename("Unknown 132")*/ _import_input_unknown_132 = 133ui16,
				/*nicename("Unknown 133")*/ _import_input_unknown_133 = 134ui16,
				/*nicename("Unknown 134")*/ _import_input_unknown_134 = 135ui16,
				/*nicename("Unknown 135")*/ _import_input_unknown_135 = 136ui16,
				/*nicename("Unknown 136")*/ _import_input_unknown_136 = 137ui16,
				/*nicename("Unknown 137")*/ _import_input_unknown_137 = 138ui16,
				/*nicename("Editor Budget")*/ _import_input_editor_budget = 139ui16,
				/*nicename("Editor Budget Cost")*/ _import_input_editor_budget_cost = 140ui16,
				/*nicename("Film Total Time")*/ _import_input_film_total_time = 141ui16,
				/*nicename("Film Current Time")*/ _import_input_film_current_time = 142ui16,
				/*nicename("Unknown 142")*/ _import_input_unknown_142 = 143ui16,
				/*nicename("Film Timeline Fraction 1")*/ _import_input_film_timeline_fraction_1 = 144ui16,
				/*nicename("Film Timeline Fraction 2")*/ _import_input_film_timeline_fraction_2 = 145ui16,
				/*nicename("Unknown 145")*/ _import_input_unknown_145 = 146ui16,
				/*nicename("Unknown 146")*/ _import_input_unknown_146 = 147ui16,
				/*nicename("NetDebug Latency")*/ _import_input_netdebug_latency = 148ui16,
				/*nicename("NetDebug Latency Quality")*/ _import_input_netdebug_latency_quality = 149ui16,
				/*nicename("NetDebug Host Quality")*/ _import_input_netdebug_host_quality = 150ui16,
				/*nicename("NetDebug Local Quality")*/ _import_input_netdebug_local_quality = 151ui16,
			};

			enum nicename("Import Range Input") e_import_range_input : uint16_t
			{
				/*nicename("Zero")*/ _import_range_input_zero = 1ui16,
				/*nicename("One")*/ _import_range_input_one = 2ui16,
				/*nicename("Unknown 2")*/ _import_range_input_unknown_2 = 3ui16,
				/*nicename("Unknown 3")*/ _import_range_input_unknown_3 = 4ui16,
				/*nicename("Unknown 4")*/ _import_range_input_unknown_4 = 5ui16,
				/*nicename("Time")*/ _import_range_input_time = 6ui16,
				/*nicename("Fade")*/ _import_range_input_fade = 7ui16,
				/*nicename("Unknown 7")*/ _import_range_input_unknown_7 = 8ui16,
				/*nicename("Unknown 8")*/ _import_range_input_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _import_range_input_unknown_9 = 10ui16,
				/*nicename("Unknown 10")*/ _import_range_input_unknown_10 = 11ui16,
				/*nicename("Unknown 11")*/ _import_range_input_unknown_11 = 12ui16,
				/*nicename("Unknown 12")*/ _import_range_input_unknown_12 = 13ui16,
				/*nicename("Unknown 13")*/ _import_range_input_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _import_range_input_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _import_range_input_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _import_range_input_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _import_range_input_unknown_17 = 18ui16,
				/*nicename("Unknown 18")*/ _import_range_input_unknown_18 = 19ui16,
				/*nicename("Unknown 19")*/ _import_range_input_unknown_19 = 20ui16,
				/*nicename("Unknown 20")*/ _import_range_input_unknown_20 = 21ui16,
				/*nicename("Saber Unknown 1")*/ _import_range_input_saber_unknown_1 = 22ui16,
				/*nicename("Vehicle Health Current Percentage")*/ _import_range_input_vehicle_health_current_percentage = 23ui16,
				/*nicename("Unit Health Current")*/ _import_range_input_unit_health_current = 24ui16,
				/*nicename("Unit Health")*/ _import_range_input_unit_health = 25ui16,
				/*nicename("Unit Shield Current")*/ _import_range_input_unit_shield_current = 26ui16,
				/*nicename("Unit 1x Overshield Current")*/ _import_range_input_unit_1x_overshield_current = 27ui16,
				/*nicename("Unit 2x Overshield Current")*/ _import_range_input_unit_2x_overshield_current = 28ui16,
				/*nicename("Unit 2x Overshield Current")*/ _import_range_input_unit_2x_overshield_current1 = 29ui16,
				/*nicename("Unit Shield")*/ _import_range_input_unit_shield = 30ui16,
				/*nicename("Unit 1x Overshield")*/ _import_range_input_unit_1x_overshield = 31ui16,
				/*nicename("Unit 2x Overshield")*/ _import_range_input_unit_2x_overshield = 32ui16,
				/*nicename("Unit 3x Overshield")*/ _import_range_input_unit_3x_overshield = 33ui16,
				/*nicename("Unit Shield Current Percentage")*/ _import_range_input_unit_shield_current_percentage = 34ui16,
				/*nicename("Vehicle Shield Current Percentage")*/ _import_range_input_vehicle_shield_current_percentage = 35ui16,
				/*nicename("Boost Energy Fraction")*/ _import_range_input_boost_energy_fraction = 36ui16,
				/*nicename("Unknown 36")*/ _import_range_input_unknown_36 = 37ui16,
				/*nicename("Aim Yaw")*/ _import_range_input_aim_yaw = 38ui16,
				/*nicename("Aim Pitch")*/ _import_range_input_aim_pitch = 39ui16,
				/*nicename("Saber Waypoint Distance")*/ _import_range_input_saber_waypoint_distance = 40ui16,
				/*nicename("Sensor Range")*/ _import_range_input_sensor_range = 41ui16,
				/*nicename("Unit Altitude 1")*/ _import_range_input_unit_altitude_1 = 42ui16,
				/*nicename("Unit Altitude 2")*/ _import_range_input_unit_altitude_2 = 43ui16,
				/*nicename("Unknown 43")*/ _import_range_input_unknown_43 = 44ui16,
				/*nicename("Softkill Timer")*/ _import_range_input_softkill_timer = 45ui16,
				/*nicename("Transient Credits")*/ _import_range_input_transient_credits = 46ui16,
				/*nicename("Unknown 46")*/ _import_range_input_unknown_46 = 47ui16,
				/*nicename("Clip Ammo Fraction")*/ _import_range_input_clip_ammo_fraction = 48ui16,
				/*nicename("Total Ammo Fraction")*/ _import_range_input_total_ammo_fraction = 49ui16,
				/*nicename("Pickup")*/ _import_range_input_pickup = 50ui16,
				/*nicename("Heat Fraction")*/ _import_range_input_heat_fraction = 51ui16,
				/*nicename("Airstrike Charge Fraction")*/ _import_range_input_airstrike_charge_fraction = 52ui16,
				/*nicename("Battery Fraction")*/ _import_range_input_battery_fraction = 53ui16,
				/*nicename("Unknown 53")*/ _import_range_input_unknown_53 = 54ui16,
				/*nicename("Unknown 54")*/ _import_range_input_unknown_54 = 55ui16,
				/*nicename("Weapon Error")*/ _import_range_input_weapon_error = 56ui16,
				/*nicename("Unknown Weapon Error")*/ _import_range_input_unknown_weapon_error = 57ui16,
				/*nicename("Unit Autoaimed")*/ _import_range_input_unit_autoaimed = 58ui16,
				/*nicename("Saber Waypoint Distance Current")*/ _import_range_input_saber_waypoint_distance_current = 59ui16,
				/*nicename("Airstrike Distance")*/ _import_range_input_airstrike_distance = 60ui16,
				/*nicename("Nav Point Airstrike")*/ _import_range_input_nav_point_airstrike = 61ui16,
				/*nicename("Airstrike Ammo")*/ _import_range_input_airstrike_ammo = 62ui16,
				/*nicename("Unknown 62")*/ _import_range_input_unknown_62 = 63ui16,
				/*nicename("Unknown 63")*/ _import_range_input_unknown_63 = 64ui16,
				/*nicename("Grenade Fraction")*/ _import_range_input_grenade_fraction = 65ui16,
				/*nicename("Unknown 65")*/ _import_range_input_unknown_65 = 66ui16,
				/*nicename("Charge Fraction")*/ _import_range_input_charge_fraction = 67ui16,
				/*nicename("Unknown 67")*/ _import_range_input_unknown_67 = 68ui16,
				/*nicename("Trigger Cooldown")*/ _import_range_input_trigger_cooldown = 69ui16,
				/*nicename("Trigger Remote Detonate Fraction")*/ _import_range_input_trigger_remote_detonate_fraction = 70ui16,
				/*nicename("Trigger Locked On")*/ _import_range_input_trigger_locked_on = 71ui16,
				/*nicename("Target Distance")*/ _import_range_input_target_distance = 72ui16,
				/*nicename("Target Elevation")*/ _import_range_input_target_elevation = 73ui16,
				/*nicename("Equipment Energy Fraction")*/ _import_range_input_equipment_energy_fraction = 74ui16,
				/*nicename("Unknown 74")*/ _import_range_input_unknown_74 = 75ui16,
				/*nicename("Unknown 75")*/ _import_range_input_unknown_75 = 76ui16,
				/*nicename("Unknown 76")*/ _import_range_input_unknown_76 = 77ui16,
				/*nicename("Unknown 77")*/ _import_range_input_unknown_77 = 78ui16,
				/*nicename("Unknown 78")*/ _import_range_input_unknown_78 = 79ui16,
				/*nicename("Unknown 79")*/ _import_range_input_unknown_79 = 80ui16,
				/*nicename("Medal Commendation")*/ _import_range_input_medal_commendation = 81ui16,
				/*nicename("Generator Health Current")*/ _import_range_input_generator_health_current = 82ui16,
				/*nicename("Generator Health")*/ _import_range_input_generator_health = 83ui16,
				/*nicename("Unknown 83")*/ _import_range_input_unknown_83 = 84ui16,
				/*nicename("Waypoint")*/ _import_range_input_waypoint = 85ui16,
				/*nicename("Unknown 85")*/ _import_range_input_unknown_85 = 86ui16,
				/*nicename("Unknown 86")*/ _import_range_input_unknown_86 = 87ui16,
				/*nicename("Waypoint Onscreen")*/ _import_range_input_waypoint_onscreen = 88ui16,
				/*nicename("Waypoint Offscreen")*/ _import_range_input_waypoint_offscreen = 89ui16,
				/*nicename("Gametype Plate")*/ _import_range_input_gametype_plate = 90ui16,
				/*nicename("Offense Defense")*/ _import_range_input_offense_defense = 91ui16,
				/*nicename("Metagame Time")*/ _import_range_input_metagame_time = 92ui16,
				/*nicename("Metagame Score Transient")*/ _import_range_input_metagame_score_transient = 93ui16,
				/*nicename("Metagame Score Player 1")*/ _import_range_input_metagame_score_player_1 = 94ui16,
				/*nicename("Unknown 94")*/ _import_range_input_unknown_94 = 95ui16,
				/*nicename("Unknown 95")*/ _import_range_input_unknown_95 = 96ui16,
				/*nicename("Unknown 96")*/ _import_range_input_unknown_96 = 97ui16,
				/*nicename("Unknown 97")*/ _import_range_input_unknown_97 = 98ui16,
				/*nicename("Unknown 98")*/ _import_range_input_unknown_98 = 99ui16,
				/*nicename("Unknown 99")*/ _import_range_input_unknown_99 = 100ui16,
				/*nicename("Survival Multiplier")*/ _import_range_input_survival_multiplier = 101ui16,
				/*nicename("Metagame Score Negative")*/ _import_range_input_metagame_score_negative = 102ui16,
				/*nicename("Survival Set")*/ _import_range_input_survival_set = 103ui16,
				/*nicename("Unknown 103")*/ _import_range_input_unknown_103 = 104ui16,
				/*nicename("Survival Waves Background")*/ _import_range_input_survival_waves_background = 105ui16,
				/*nicename("Survival Lives 1")*/ _import_range_input_survival_lives_1 = 106ui16,
				/*nicename("Survival Lives 2")*/ _import_range_input_survival_lives_2 = 107ui16,
				/*nicename("Survival Bonus Timer")*/ _import_range_input_survival_bonus_timer = 108ui16,
				/*nicename("Unknown 108")*/ _import_range_input_unknown_108 = 109ui16,
				/*nicename("Unknown 109")*/ _import_range_input_unknown_109 = 110ui16,
				/*nicename("Friendly Score")*/ _import_range_input_friendly_score = 111ui16,
				/*nicename("Enemy Score")*/ _import_range_input_enemy_score = 112ui16,
				/*nicename("Score To Win")*/ _import_range_input_score_to_win = 113ui16,
				/*nicename("Arming Fraction")*/ _import_range_input_arming_fraction = 114ui16,
				/*nicename("Posession Icon")*/ _import_range_input_posession_icon = 115ui16,
				/*nicename("Arming Unknown")*/ _import_range_input_arming_unknown = 116ui16,
				/*nicename("Omniwidget Icon")*/ _import_range_input_omniwidget_icon = 117ui16,
				/*nicename("Unknown 117")*/ _import_range_input_unknown_117 = 118ui16,
				/*nicename("Fireteam Health")*/ _import_range_input_fireteam_health = 119ui16,
				/*nicename("Unknown 119")*/ _import_range_input_unknown_119 = 120ui16,
				/*nicename("Unknown 120")*/ _import_range_input_unknown_120 = 121ui16,
				/*nicename("Unknown 121")*/ _import_range_input_unknown_121 = 122ui16,
				/*nicename("Fireteam Current Shield")*/ _import_range_input_fireteam_current_shield = 123ui16,
				/*nicename("Unknown 123")*/ _import_range_input_unknown_123 = 124ui16,
				/*nicename("Unknown 124")*/ _import_range_input_unknown_124 = 125ui16,
				/*nicename("Fireteam 1 Arming Fraction")*/ _import_range_input_fireteam_1_arming_fraction = 126ui16,
				/*nicename("Fireteam 2 Arming Fraction")*/ _import_range_input_fireteam_2_arming_fraction = 127ui16,
				/*nicename("Unknown 127")*/ _import_range_input_unknown_127 = 128ui16,
				/*nicename("Fireteam 1 Directional Arrow")*/ _import_range_input_fireteam_1_directional_arrow = 129ui16,
				/*nicename("Fireteam 2 Directional Arrow")*/ _import_range_input_fireteam_2_directional_arrow = 130ui16,
				/*nicename("Unknown 130")*/ _import_range_input_unknown_130 = 131ui16,
				/*nicename("Unknown 131")*/ _import_range_input_unknown_131 = 132ui16,
				/*nicename("Unknown 132")*/ _import_range_input_unknown_132 = 133ui16,
				/*nicename("Unknown 133")*/ _import_range_input_unknown_133 = 134ui16,
				/*nicename("Unknown 134")*/ _import_range_input_unknown_134 = 135ui16,
				/*nicename("Unknown 135")*/ _import_range_input_unknown_135 = 136ui16,
				/*nicename("Unknown 136")*/ _import_range_input_unknown_136 = 137ui16,
				/*nicename("Unknown 137")*/ _import_range_input_unknown_137 = 138ui16,
				/*nicename("Editor Budget")*/ _import_range_input_editor_budget = 139ui16,
				/*nicename("Editor Budget Cost")*/ _import_range_input_editor_budget_cost = 140ui16,
				/*nicename("Film Total Time")*/ _import_range_input_film_total_time = 141ui16,
				/*nicename("Film Current Time")*/ _import_range_input_film_current_time = 142ui16,
				/*nicename("Unknown 142")*/ _import_range_input_unknown_142 = 143ui16,
				/*nicename("Film Timeline Fraction 1")*/ _import_range_input_film_timeline_fraction_1 = 144ui16,
				/*nicename("Film Timeline Fraction 2")*/ _import_range_input_film_timeline_fraction_2 = 145ui16,
				/*nicename("Unknown 145")*/ _import_range_input_unknown_145 = 146ui16,
				/*nicename("Unknown 146")*/ _import_range_input_unknown_146 = 147ui16,
				/*nicename("NetDebug Latency")*/ _import_range_input_netdebug_latency = 148ui16,
				/*nicename("NetDebug Latency Quality")*/ _import_range_input_netdebug_latency_quality = 149ui16,
				/*nicename("NetDebug Host Quality")*/ _import_range_input_netdebug_host_quality = 150ui16,
				/*nicename("NetDebug Local Quality")*/ _import_range_input_netdebug_local_quality = 151ui16,
			};

			enum nicename("Flags") b_flags : uint32_t /* bitfield */
			{
				/*nicename("Mirror Horizontally")*/ _flags_mirror_horizontally = 1ui32 << 0ui32,
				/*nicename("Mirror Vertically")*/ _flags_mirror_vertically = 1ui32 << 1ui32,
				/*nicename("Stretch Edges")*/ _flags_stretch_edges = 1ui32 << 2ui32,
				/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
				/*nicename("Enable Texture Cam")*/ _flags_enable_texture_cam = 1ui32 << 4ui32,
				/*nicename("Looping")*/ _flags_looping = 1ui32 << 5ui32,
				/*nicename("Posession Icon")*/ _flags_posession_icon = 1ui32 << 6ui32,
				/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
				/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
			};

			struct nicename("State Data") s_state_data1_definition
			{
				struct nicename("'Yes' States") s_yes_states1_definition
				{
					struct nicename("Triggers") s_triggers3_definition
					{
						enum nicename("Flag") b_flag : uint8_t /* bitfield */
						{
							/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
						};

						b_flag nicename("Flag") flag;
						int8_t __unknown0;
						int8_t __unknown1;
						int8_t __unknown2;
						int32_t nicename("Trigger Index") trigger_index;
					};

					s_tag_block_definition<s_triggers3_definition> nicename("Triggers") triggers_block;
				};

				struct nicename("Unknown States") s_unknown_states1_definition
				{
					struct nicename("Triggers") s_triggers4_definition
					{
						enum nicename("Flag") b_flag : uint8_t /* bitfield */
						{
							/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
						};

						b_flag nicename("Flag") flag;
						int8_t __unknown0;
						int8_t __unknown1;
						int8_t __unknown2;
						int32_t nicename("Trigger Index") trigger_index;
					};

					s_tag_block_definition<s_triggers4_definition> nicename("Triggers") triggers_block;
				};

				struct nicename("'No' States") s_no_states1_definition
				{
					struct nicename("Triggers") s_triggers5_definition
					{
						enum nicename("Flag") b_flag : uint8_t /* bitfield */
						{
							/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
						};

						b_flag nicename("Flag") flag;
						int8_t __unknown0;
						int8_t __unknown1;
						int8_t __unknown2;
						int32_t nicename("Trigger Index") trigger_index;
					};

					s_tag_block_definition<s_triggers5_definition> nicename("Triggers") triggers_block;
				};

				// State Data Note : The following blocks are import data.
				s_tag_block_definition<s_yes_states1_definition> nicename("'Yes' States") yes_states_block;
				s_tag_block_definition<s_unknown_states1_definition> nicename("Unknown States") unknown_states_block;
				s_tag_block_definition<s_no_states1_definition> nicename("'No' States") no_states_block;
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t __unknown2;
				int16_t __unknown3;
				Undefined32 __unknown4;
				Undefined32 __unknown5;
				Undefined32 __unknown6;
			};

			struct nicename("Placement Data") s_placement_data1_definition
			{
				enum nicename("Anchor") e_anchor : uint8_t
				{
					/*nicename("Unknown")*/ _anchor_unknown = 1ui8,
					/*nicename("Top, Left")*/ _anchor_top_left = 2ui8,
					/*nicename("Top, Middle")*/ _anchor_top_middle = 3ui8,
					/*nicename("Top, Right")*/ _anchor_top_right = 4ui8,
					/*nicename("Center, Middle")*/ _anchor_center_middle = 5ui8,
					/*nicename("Bottom, Left")*/ _anchor_bottom_left = 6ui8,
					/*nicename("Bottom, Middle")*/ _anchor_bottom_middle = 7ui8,
					/*nicename("Bottom, Right")*/ _anchor_bottom_right = 8ui8,
					/*nicename("Motion Sensor")*/ _anchor_motion_sensor = 9ui8,
					/*nicename("Crosshair A")*/ _anchor_crosshair_a = 10ui8,
					/*nicename("Ability")*/ _anchor_ability = 11ui8,
					/*nicename("Weapon Left")*/ _anchor_weapon_left = 12ui8,
					/*nicename("Weapon Right")*/ _anchor_weapon_right = 13ui8,
					/*nicename("Health and Shield")*/ _anchor_health_and_shield = 14ui8,
					/*nicename("Unknown")*/ _anchor_unknown1 = 15ui8,
					/*nicename("Top, Left B")*/ _anchor_top_left_b = 16ui8,
					/*nicename("Unknown")*/ _anchor_unknown2 = 17ui8,
					/*nicename("Crosshair B")*/ _anchor_crosshair_b = 18ui8,
					/*nicename("Top, Left C")*/ _anchor_top_left_c = 19ui8,
					/*nicename("Top, Left D")*/ _anchor_top_left_d = 20ui8,
					/*nicename("Top, Left E")*/ _anchor_top_left_e = 21ui8,
					/*nicename("Crosshair B")*/ _anchor_crosshair_b1 = 22ui8,
					/*nicename("Top, Left F")*/ _anchor_top_left_f = 23ui8,
					/*nicename("Unknown")*/ _anchor_unknown3 = 24ui8,
					/*nicename("Top, Left G")*/ _anchor_top_left_g = 25ui8,
					/*nicename("Unknown")*/ _anchor_unknown4 = 26ui8,
					/*nicename("Top, Left F")*/ _anchor_top_left_f1 = 27ui8,
					/*nicename("Score")*/ _anchor_score = 28ui8,
					/*nicename("Score B")*/ _anchor_score_b = 29ui8,
					/*nicename("Score C")*/ _anchor_score_c = 30ui8,
					/*nicename("Score D")*/ _anchor_score_d = 31ui8,
					/*nicename("Score E")*/ _anchor_score_e = 32ui8,
					/*nicename("Score F")*/ _anchor_score_f = 33ui8,
					/*nicename("Score G")*/ _anchor_score_g = 34ui8,
					/*nicename("Unknown")*/ _anchor_unknown5 = 35ui8,
					/*nicename("Unknown")*/ _anchor_unknown6 = 36ui8,
					/*nicename("Unknown")*/ _anchor_unknown7 = 37ui8,
					/*nicename("Unknown")*/ _anchor_unknown8 = 38ui8,
					/*nicename("Unknown")*/ _anchor_unknown9 = 39ui8,
					/*nicename("Unknown")*/ _anchor_unknown10 = 40ui8,
				};

				enum b_unknown : uint8_t /* bitfield */
				{
					/*nicename("Bit 0")*/ _unknown_bit_0 = 1ui8 << 0ui8,
					/*nicename("Bit 1")*/ _unknown_bit_1 = 1ui8 << 1ui8,
					/*nicename("Bit 2")*/ _unknown_bit_2 = 1ui8 << 2ui8,
					/*nicename("Bit 3")*/ _unknown_bit_3 = 1ui8 << 3ui8,
					/*nicename("Bit 4")*/ _unknown_bit_4 = 1ui8 << 4ui8,
					/*nicename("Bit 5")*/ _unknown_bit_5 = 1ui8 << 5ui8,
					/*nicename("Bit 6")*/ _unknown_bit_6 = 1ui8 << 6ui8,
					/*nicename("Bit 7")*/ _unknown_bit_7 = 1ui8 << 7ui8,
				};

				b_unknown __unknown0;
				e_anchor nicename("Anchor") anchor;
				int16_t __unknown1;
				float nicename("Mirror Offset X") mirror_offset_x;
				float nicename("Mirror Offset Y") mirror_offset_y;
				float nicename("Offset X") offset_x;
				float nicename("Offset Y") offset_y;
				float nicename("Scale X") scale_x;
				float nicename("Scale Y") scale_y;
			};

			struct nicename("Animation Data") s_animation_data1_definition
			{
				enum nicename("Animation 1 Function") e_animation_1_function : uint8_t
				{
					/*nicename("Default")*/ _animation_1_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_1_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_1_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_1_function_zero = 4ui8,
				};

				enum nicename("Animation 2 Function") e_animation_2_function : uint8_t
				{
					/*nicename("Default")*/ _animation_2_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_2_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_2_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_2_function_zero = 4ui8,
				};

				enum nicename("Animation 3 Function") e_animation_3_function : uint8_t
				{
					/*nicename("Default")*/ _animation_3_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_3_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_3_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_3_function_zero = 4ui8,
				};

				enum nicename("Animation 4 Function") e_animation_4_function : uint8_t
				{
					/*nicename("Default")*/ _animation_4_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_4_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_4_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_4_function_zero = 4ui8,
				};

				enum nicename("Animation 5 Function") e_animation_5_function : uint8_t
				{
					/*nicename("Default")*/ _animation_5_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_5_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_5_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_5_function_zero = 4ui8,
				};

				enum nicename("Animation 1 Flags") b_animation_1_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_1_flags_reverse_frames = 1ui8 << 0ui8,
				};

				enum nicename("Animation 2 Flags") b_animation_2_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_2_flags_reverse_frames = 1ui8 << 0ui8,
				};

				enum nicename("Animation 3 Flags") b_animation_3_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_3_flags_reverse_frames = 1ui8 << 0ui8,
				};

				enum nicename("Animation 4 Flags") b_animation_4_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_4_flags_reverse_frames = 1ui8 << 0ui8,
				};

				enum nicename("Animation 5 Flags") b_animation_5_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_5_flags_reverse_frames = 1ui8 << 0ui8,
				};

				b_animation_1_flags nicename("Animation 1 Flags") animation_1_flags;
				e_animation_1_function nicename("Animation 1 Function") animation_1_function;
				int16_t __unknown0;
				TagReference nicename("Animation 1") animation_1_reference;
				b_animation_2_flags nicename("Animation 2 Flags") animation_2_flags;
				e_animation_2_function nicename("Animation 2 Function") animation_2_function;
				int16_t __unknown1;
				TagReference nicename("Animation 2") animation_2_reference;
				b_animation_3_flags nicename("Animation 3 Flags") animation_3_flags;
				e_animation_3_function nicename("Animation 3 Function") animation_3_function;
				int16_t __unknown2;
				TagReference nicename("Animation 3") animation_3_reference;
				b_animation_4_flags nicename("Animation 4 Flags") animation_4_flags;
				e_animation_4_function nicename("Animation 4 Function") animation_4_function;
				int16_t __unknown3;
				TagReference nicename("Animation 4") animation_4_reference;
				b_animation_5_flags nicename("Animation 5 Flags") animation_5_flags;
				e_animation_5_function nicename("Animation 5 Function") animation_5_function;
				int16_t __unknown4;
				TagReference nicename("Animation 5") animation_5_reference;
			};

			struct nicename("Render Data") s_render_data1_definition
			{
				enum nicename("Shader Index") e_shader_index : uint8_t
				{
					/*nicename("Cheap")*/ _shader_index_cheap = 1ui8,
					/*nicename("Simple")*/ _shader_index_simple = 2ui8,
					/*nicename("Meter")*/ _shader_index_meter = 3ui8,
					/*nicename("Text Simple")*/ _shader_index_text_simple = 4ui8,
					/*nicename("Meter Shield")*/ _shader_index_meter_shield = 5ui8,
					/*nicename("Meter Gradient")*/ _shader_index_meter_gradient = 6ui8,
					/*nicename("Crosshair")*/ _shader_index_crosshair = 7ui8,
					/*nicename("Directional Damage")*/ _shader_index_directional_damage = 8ui8,
					/*nicename("Solid")*/ _shader_index_solid = 9ui8,
					/*nicename("Sensor")*/ _shader_index_sensor = 10ui8,
					/*nicename("Meter Single Color")*/ _shader_index_meter_single_color = 11ui8,
					/*nicename("Navpoint")*/ _shader_index_navpoint = 12ui8,
					/*nicename("Medal")*/ _shader_index_medal = 13ui8,
					/*nicename("Texture Cam")*/ _shader_index_texture_cam = 14ui8,
					/*nicename("Meter Chapter")*/ _shader_index_meter_chapter = 15ui8,
					/*nicename("Meter Double Gradient")*/ _shader_index_meter_double_gradient = 16ui8,
					/*nicename("Meter Radial Gradient")*/ _shader_index_meter_radial_gradient = 17ui8,
					/*nicename("Turbulence")*/ _shader_index_turbulence = 18ui8,
					/*nicename("Emblem")*/ _shader_index_emblem = 19ui8,
					/*nicename("Directional Damage Apply")*/ _shader_index_directional_damage_apply = 20ui8,
					/*nicename("Damage Tracker")*/ _shader_index_damage_tracker = 21ui8,
				};

				enum nicename("Output Color a") e_output_color_a : uint16_t
				{
					/*nicename("Local a")*/ _output_color_a_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_a_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_a_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_a_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_a_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_a_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_a_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_a_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_a_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_a_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_a_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_a_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_a_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_a_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_a_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_a_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_a_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_a_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_a_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_a_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_a_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_a_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_a_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_a_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_a_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_a_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_a_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_a_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_a_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_a_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_a_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_a_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_a_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_a_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_a_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_a_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_a_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_a_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_a_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_a_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_a_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_a_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_a_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_a_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_a_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_a_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_a_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_a_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_a_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_a_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_a_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_a_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_a_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_a_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_a_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_a_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_a_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_a_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_a_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_a_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_a_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color b") e_output_color_b : uint16_t
				{
					/*nicename("Local a")*/ _output_color_b_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_b_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_b_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_b_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_b_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_b_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_b_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_b_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_b_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_b_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_b_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_b_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_b_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_b_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_b_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_b_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_b_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_b_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_b_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_b_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_b_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_b_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_b_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_b_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_b_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_b_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_b_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_b_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_b_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_b_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_b_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_b_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_b_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_b_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_b_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_b_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_b_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_b_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_b_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_b_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_b_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_b_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_b_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_b_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_b_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_b_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_b_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_b_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_b_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_b_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_b_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_b_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_b_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_b_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_b_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_b_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_b_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_b_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_b_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_b_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_b_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color c") e_output_color_c : uint16_t
				{
					/*nicename("Local a")*/ _output_color_c_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_c_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_c_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_c_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_c_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_c_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_c_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_c_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_c_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_c_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_c_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_c_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_c_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_c_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_c_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_c_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_c_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_c_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_c_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_c_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_c_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_c_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_c_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_c_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_c_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_c_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_c_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_c_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_c_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_c_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_c_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_c_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_c_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_c_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_c_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_c_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_c_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_c_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_c_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_c_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_c_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_c_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_c_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_c_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_c_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_c_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_c_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_c_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_c_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_c_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_c_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_c_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_c_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_c_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_c_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_c_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_c_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_c_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_c_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_c_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_c_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color d") e_output_color_d : uint16_t
				{
					/*nicename("Local a")*/ _output_color_d_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_d_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_d_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_d_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_d_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_d_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_d_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_d_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_d_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_d_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_d_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_d_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_d_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_d_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_d_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_d_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_d_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_d_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_d_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_d_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_d_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_d_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_d_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_d_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_d_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_d_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_d_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_d_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_d_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_d_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_d_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_d_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_d_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_d_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_d_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_d_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_d_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_d_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_d_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_d_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_d_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_d_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_d_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_d_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_d_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_d_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_d_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_d_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_d_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_d_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_d_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_d_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_d_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_d_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_d_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_d_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_d_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_d_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_d_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_d_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_d_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color e") e_output_color_e : uint16_t
				{
					/*nicename("Local a")*/ _output_color_e_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_e_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_e_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_e_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_e_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_e_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_e_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_e_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_e_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_e_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_e_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_e_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_e_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_e_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_e_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_e_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_e_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_e_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_e_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_e_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_e_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_e_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_e_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_e_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_e_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_e_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_e_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_e_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_e_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_e_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_e_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_e_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_e_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_e_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_e_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_e_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_e_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_e_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_e_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_e_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_e_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_e_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_e_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_e_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_e_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_e_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_e_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_e_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_e_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_e_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_e_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_e_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_e_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_e_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_e_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_e_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_e_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_e_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_e_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_e_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_e_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color f") e_output_color_f : uint16_t
				{
					/*nicename("Local a")*/ _output_color_f_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_f_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_f_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_f_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_f_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_f_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_f_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_f_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_f_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_f_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_f_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_f_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_f_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_f_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_f_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_f_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_f_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_f_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_f_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_f_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_f_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_f_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_f_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_f_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_f_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_f_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_f_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_f_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_f_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_f_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_f_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_f_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_f_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_f_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_f_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_f_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_f_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_f_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_f_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_f_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_f_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_f_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_f_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_f_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_f_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_f_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_f_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_f_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_f_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_f_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_f_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_f_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_f_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_f_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_f_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_f_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_f_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_f_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_f_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_f_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_f_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Scalar a") e_output_scalar_a : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_a_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_a_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_a_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_a_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_a_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_a_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_a_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_a_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_a_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_a_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar b") e_output_scalar_b : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_b_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_b_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_b_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_b_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_b_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_b_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_b_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_b_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_b_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_b_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar c") e_output_scalar_c : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_c_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_c_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_c_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_c_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_c_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_c_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_c_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_c_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_c_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_c_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar d") e_output_scalar_d : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_d_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_d_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_d_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_d_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_d_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_d_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_d_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_d_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_d_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_d_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar e") e_output_scalar_e : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_e_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_e_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_e_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_e_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_e_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_e_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_e_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_e_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_e_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_e_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar f") e_output_scalar_f : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_f_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_f_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_f_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_f_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_f_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_f_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_f_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_f_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_f_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_f_unknown_9 = 10ui16,
				};

				e_shader_index nicename("Shader Index") shader_index;
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				float nicename("Local Color Alpha a") local_color_alpha_a;
				colorf nicename("Local Color a") local_color_a;
				float nicename("Local Color Alpha b") local_color_alpha_b;
				colorf nicename("Local Color b") local_color_b;
				float nicename("Local Color Alpha c") local_color_alpha_c;
				colorf nicename("Local Color c") local_color_c;
				float nicename("Local Color Alpha d") local_color_alpha_d;
				colorf nicename("Local Color d") local_color_d;
				float nicename("Local Scalar a") local_scalar_a;
				float nicename("Local Scalar b") local_scalar_b;
				float nicename("Local Scalar c") local_scalar_c;
				float nicename("Local Scalar d") local_scalar_d;
				e_output_color_a nicename("Output Color a") output_color_a;
				e_output_color_b nicename("Output Color b") output_color_b;
				e_output_color_c nicename("Output Color c") output_color_c;
				e_output_color_d nicename("Output Color d") output_color_d;
				e_output_color_e nicename("Output Color e") output_color_e;
				e_output_color_f nicename("Output Color f") output_color_f;
				e_output_scalar_a nicename("Output Scalar a") output_scalar_a;
				e_output_scalar_b nicename("Output Scalar b") output_scalar_b;
				e_output_scalar_c nicename("Output Scalar c") output_scalar_c;
				e_output_scalar_d nicename("Output Scalar d") output_scalar_d;
				e_output_scalar_e nicename("Output Scalar e") output_scalar_e;
				e_output_scalar_f nicename("Output Scalar f") output_scalar_f;
				Undefined32 __unknown3;
				Undefined32 __unknown4;
				int16_t __unknown5;
				int16_t __unknown6;
			};

			DEPRECATED_string_id nicename("Name") name;
			e_special_hud_type nicename("Special HUD Type") special_hud_type;
			uint8_t __unknown0;
			uint8_t __unknown1;
			uint8_t __unknown2;
			e_import_input nicename("Import Input") import_input;
			e_import_range_input nicename("Import Range Input") import_range_input;
			TagReference nicename("State Data Template") state_data_template_reference;
			s_tag_block_definition<s_state_data1_definition> nicename("State Data") state_data_block;
			TagReference nicename("Placement Data Template") placement_data_template_reference;
			s_tag_block_definition<s_placement_data1_definition> nicename("Placement Data") placement_data_block;
			TagReference nicename("Animation Data Template") animation_data_template_reference;
			s_tag_block_definition<s_animation_data1_definition> nicename("Animation Data") animation_data_block;
			TagReference nicename("Render Data Template") render_data_template_reference;
			s_tag_block_definition<s_render_data1_definition> nicename("Render Data") render_data_block;
			b_flags nicename("Flags") flags;
			TagReference nicename("Bitmap") bitmap_reference;
			uint8_t nicename("Bitmap Sprite Index") bitmap_sprite_index;
			uint8_t __unknown3;
			uint8_t __unknown4;
			uint8_t __unknown5;
			Undefined32 __unknown6;
			Undefined32 __unknown7;
		};

		struct nicename("Text Widgets") s_text_widgets_definition
		{
			enum nicename("Special HUD Type") e_special_hud_type : uint8_t
			{
				/*nicename("Unspecial")*/ _special_hud_type_unspecial = 1ui8,
				/*nicename("Ammo")*/ _special_hud_type_ammo = 2ui8,
				/*nicename("Crosshair and Scope")*/ _special_hud_type_crosshair_and_scope = 3ui8,
				/*nicename("Unit Shield Meter")*/ _special_hud_type_unit_shield_meter = 4ui8,
				/*nicename("Grenades")*/ _special_hud_type_grenades = 5ui8,
				/*nicename("Gametype")*/ _special_hud_type_gametype = 6ui8,
				/*nicename("Motion Sensor")*/ _special_hud_type_motion_sensor = 7ui8,
				/*nicename("Unknown")*/ _special_hud_type_unknown = 8ui8,
				/*nicename("m70_bonus")*/ _special_hud_type_m70_bonus = 9ui8,
			};

			enum nicename("Import Input") e_import_input : uint16_t
			{
				/*nicename("Zero")*/ _import_input_zero = 1ui16,
				/*nicename("One")*/ _import_input_one = 2ui16,
				/*nicename("Unknown 2")*/ _import_input_unknown_2 = 3ui16,
				/*nicename("Unknown 3")*/ _import_input_unknown_3 = 4ui16,
				/*nicename("Unknown 4")*/ _import_input_unknown_4 = 5ui16,
				/*nicename("Time")*/ _import_input_time = 6ui16,
				/*nicename("Fade")*/ _import_input_fade = 7ui16,
				/*nicename("Unknown 7")*/ _import_input_unknown_7 = 8ui16,
				/*nicename("Unknown 8")*/ _import_input_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _import_input_unknown_9 = 10ui16,
				/*nicename("Unknown 10")*/ _import_input_unknown_10 = 11ui16,
				/*nicename("Unknown 11")*/ _import_input_unknown_11 = 12ui16,
				/*nicename("Unknown 12")*/ _import_input_unknown_12 = 13ui16,
				/*nicename("Unknown 13")*/ _import_input_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _import_input_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _import_input_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _import_input_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _import_input_unknown_17 = 18ui16,
				/*nicename("Unknown 18")*/ _import_input_unknown_18 = 19ui16,
				/*nicename("Unknown 19")*/ _import_input_unknown_19 = 20ui16,
				/*nicename("Unknown 20")*/ _import_input_unknown_20 = 21ui16,
				/*nicename("Saber Unknown 1")*/ _import_input_saber_unknown_1 = 22ui16,
				/*nicename("Vehicle Health Current Percentage")*/ _import_input_vehicle_health_current_percentage = 23ui16,
				/*nicename("Unit Health Current")*/ _import_input_unit_health_current = 24ui16,
				/*nicename("Unit Health")*/ _import_input_unit_health = 25ui16,
				/*nicename("Unit Shield Current")*/ _import_input_unit_shield_current = 26ui16,
				/*nicename("Unit 1x Overshield Current")*/ _import_input_unit_1x_overshield_current = 27ui16,
				/*nicename("Unit 2x Overshield Current")*/ _import_input_unit_2x_overshield_current = 28ui16,
				/*nicename("Unit 2x Overshield Current")*/ _import_input_unit_2x_overshield_current1 = 29ui16,
				/*nicename("Unit Shield")*/ _import_input_unit_shield = 30ui16,
				/*nicename("Unit 1x Overshield")*/ _import_input_unit_1x_overshield = 31ui16,
				/*nicename("Unit 2x Overshield")*/ _import_input_unit_2x_overshield = 32ui16,
				/*nicename("Unit 3x Overshield")*/ _import_input_unit_3x_overshield = 33ui16,
				/*nicename("Unit Shield Current Percentage")*/ _import_input_unit_shield_current_percentage = 34ui16,
				/*nicename("Vehicle Shield Current Percentage")*/ _import_input_vehicle_shield_current_percentage = 35ui16,
				/*nicename("Boost Energy Fraction")*/ _import_input_boost_energy_fraction = 36ui16,
				/*nicename("Unknown 36")*/ _import_input_unknown_36 = 37ui16,
				/*nicename("Aim Yaw")*/ _import_input_aim_yaw = 38ui16,
				/*nicename("Aim Pitch")*/ _import_input_aim_pitch = 39ui16,
				/*nicename("Saber Waypoint Distance")*/ _import_input_saber_waypoint_distance = 40ui16,
				/*nicename("Sensor Range")*/ _import_input_sensor_range = 41ui16,
				/*nicename("Unit Altitude 1")*/ _import_input_unit_altitude_1 = 42ui16,
				/*nicename("Unit Altitude 2")*/ _import_input_unit_altitude_2 = 43ui16,
				/*nicename("Unknown 43")*/ _import_input_unknown_43 = 44ui16,
				/*nicename("Softkill Timer")*/ _import_input_softkill_timer = 45ui16,
				/*nicename("Transient Credits")*/ _import_input_transient_credits = 46ui16,
				/*nicename("Unknown 46")*/ _import_input_unknown_46 = 47ui16,
				/*nicename("Clip Ammo Fraction")*/ _import_input_clip_ammo_fraction = 48ui16,
				/*nicename("Total Ammo Fraction")*/ _import_input_total_ammo_fraction = 49ui16,
				/*nicename("Pickup")*/ _import_input_pickup = 50ui16,
				/*nicename("Heat Fraction")*/ _import_input_heat_fraction = 51ui16,
				/*nicename("Airstrike Charge Fraction")*/ _import_input_airstrike_charge_fraction = 52ui16,
				/*nicename("Battery Fraction")*/ _import_input_battery_fraction = 53ui16,
				/*nicename("Unknown 53")*/ _import_input_unknown_53 = 54ui16,
				/*nicename("Unknown 54")*/ _import_input_unknown_54 = 55ui16,
				/*nicename("Weapon Error")*/ _import_input_weapon_error = 56ui16,
				/*nicename("Unknown Weapon Error")*/ _import_input_unknown_weapon_error = 57ui16,
				/*nicename("Unit Autoaimed")*/ _import_input_unit_autoaimed = 58ui16,
				/*nicename("Saber Waypoint Distance Current")*/ _import_input_saber_waypoint_distance_current = 59ui16,
				/*nicename("Airstrike Distance")*/ _import_input_airstrike_distance = 60ui16,
				/*nicename("Nav Point Airstrike")*/ _import_input_nav_point_airstrike = 61ui16,
				/*nicename("Airstrike Ammo")*/ _import_input_airstrike_ammo = 62ui16,
				/*nicename("Unknown 62")*/ _import_input_unknown_62 = 63ui16,
				/*nicename("Unknown 63")*/ _import_input_unknown_63 = 64ui16,
				/*nicename("Grenade Fraction")*/ _import_input_grenade_fraction = 65ui16,
				/*nicename("Unknown 65")*/ _import_input_unknown_65 = 66ui16,
				/*nicename("Charge Fraction")*/ _import_input_charge_fraction = 67ui16,
				/*nicename("Unknown 67")*/ _import_input_unknown_67 = 68ui16,
				/*nicename("Trigger Cooldown")*/ _import_input_trigger_cooldown = 69ui16,
				/*nicename("Trigger Remote Detonate Fraction")*/ _import_input_trigger_remote_detonate_fraction = 70ui16,
				/*nicename("Trigger Locked On")*/ _import_input_trigger_locked_on = 71ui16,
				/*nicename("Target Distance")*/ _import_input_target_distance = 72ui16,
				/*nicename("Target Elevation")*/ _import_input_target_elevation = 73ui16,
				/*nicename("Equipment Energy Fraction")*/ _import_input_equipment_energy_fraction = 74ui16,
				/*nicename("Unknown 74")*/ _import_input_unknown_74 = 75ui16,
				/*nicename("Unknown 75")*/ _import_input_unknown_75 = 76ui16,
				/*nicename("Unknown 76")*/ _import_input_unknown_76 = 77ui16,
				/*nicename("Unknown 77")*/ _import_input_unknown_77 = 78ui16,
				/*nicename("Unknown 78")*/ _import_input_unknown_78 = 79ui16,
				/*nicename("Unknown 79")*/ _import_input_unknown_79 = 80ui16,
				/*nicename("Medal Commendation")*/ _import_input_medal_commendation = 81ui16,
				/*nicename("Generator Health Current")*/ _import_input_generator_health_current = 82ui16,
				/*nicename("Generator Health")*/ _import_input_generator_health = 83ui16,
				/*nicename("Unknown 83")*/ _import_input_unknown_83 = 84ui16,
				/*nicename("Waypoint")*/ _import_input_waypoint = 85ui16,
				/*nicename("Unknown 85")*/ _import_input_unknown_85 = 86ui16,
				/*nicename("Unknown 86")*/ _import_input_unknown_86 = 87ui16,
				/*nicename("Waypoint Onscreen")*/ _import_input_waypoint_onscreen = 88ui16,
				/*nicename("Waypoint Offscreen")*/ _import_input_waypoint_offscreen = 89ui16,
				/*nicename("Gametype Plate")*/ _import_input_gametype_plate = 90ui16,
				/*nicename("Offense Defense")*/ _import_input_offense_defense = 91ui16,
				/*nicename("Metagame Time")*/ _import_input_metagame_time = 92ui16,
				/*nicename("Metagame Score Transient")*/ _import_input_metagame_score_transient = 93ui16,
				/*nicename("Metagame Score Player 1")*/ _import_input_metagame_score_player_1 = 94ui16,
				/*nicename("Unknown 94")*/ _import_input_unknown_94 = 95ui16,
				/*nicename("Unknown 95")*/ _import_input_unknown_95 = 96ui16,
				/*nicename("Unknown 96")*/ _import_input_unknown_96 = 97ui16,
				/*nicename("Unknown 97")*/ _import_input_unknown_97 = 98ui16,
				/*nicename("Unknown 98")*/ _import_input_unknown_98 = 99ui16,
				/*nicename("Unknown 99")*/ _import_input_unknown_99 = 100ui16,
				/*nicename("Survival Multiplier")*/ _import_input_survival_multiplier = 101ui16,
				/*nicename("Metagame Score Negative")*/ _import_input_metagame_score_negative = 102ui16,
				/*nicename("Survival Set")*/ _import_input_survival_set = 103ui16,
				/*nicename("Unknown 103")*/ _import_input_unknown_103 = 104ui16,
				/*nicename("Survival Waves Background")*/ _import_input_survival_waves_background = 105ui16,
				/*nicename("Survival Lives 1")*/ _import_input_survival_lives_1 = 106ui16,
				/*nicename("Survival Lives 2")*/ _import_input_survival_lives_2 = 107ui16,
				/*nicename("Survival Bonus Timer")*/ _import_input_survival_bonus_timer = 108ui16,
				/*nicename("Unknown 108")*/ _import_input_unknown_108 = 109ui16,
				/*nicename("Unknown 109")*/ _import_input_unknown_109 = 110ui16,
				/*nicename("Friendly Score")*/ _import_input_friendly_score = 111ui16,
				/*nicename("Enemy Score")*/ _import_input_enemy_score = 112ui16,
				/*nicename("Score To Win")*/ _import_input_score_to_win = 113ui16,
				/*nicename("Arming Fraction")*/ _import_input_arming_fraction = 114ui16,
				/*nicename("Posession Icon")*/ _import_input_posession_icon = 115ui16,
				/*nicename("Arming Unknown")*/ _import_input_arming_unknown = 116ui16,
				/*nicename("Omniwidget Icon")*/ _import_input_omniwidget_icon = 117ui16,
				/*nicename("Unknown 117")*/ _import_input_unknown_117 = 118ui16,
				/*nicename("Fireteam Health")*/ _import_input_fireteam_health = 119ui16,
				/*nicename("Unknown 119")*/ _import_input_unknown_119 = 120ui16,
				/*nicename("Unknown 120")*/ _import_input_unknown_120 = 121ui16,
				/*nicename("Unknown 121")*/ _import_input_unknown_121 = 122ui16,
				/*nicename("Fireteam Current Shield")*/ _import_input_fireteam_current_shield = 123ui16,
				/*nicename("Unknown 123")*/ _import_input_unknown_123 = 124ui16,
				/*nicename("Unknown 124")*/ _import_input_unknown_124 = 125ui16,
				/*nicename("Fireteam 1 Arming Fraction")*/ _import_input_fireteam_1_arming_fraction = 126ui16,
				/*nicename("Fireteam 2 Arming Fraction")*/ _import_input_fireteam_2_arming_fraction = 127ui16,
				/*nicename("Unknown 127")*/ _import_input_unknown_127 = 128ui16,
				/*nicename("Fireteam 1 Directional Arrow")*/ _import_input_fireteam_1_directional_arrow = 129ui16,
				/*nicename("Fireteam 2 Directional Arrow")*/ _import_input_fireteam_2_directional_arrow = 130ui16,
				/*nicename("Unknown 130")*/ _import_input_unknown_130 = 131ui16,
				/*nicename("Unknown 131")*/ _import_input_unknown_131 = 132ui16,
				/*nicename("Unknown 132")*/ _import_input_unknown_132 = 133ui16,
				/*nicename("Unknown 133")*/ _import_input_unknown_133 = 134ui16,
				/*nicename("Unknown 134")*/ _import_input_unknown_134 = 135ui16,
				/*nicename("Unknown 135")*/ _import_input_unknown_135 = 136ui16,
				/*nicename("Unknown 136")*/ _import_input_unknown_136 = 137ui16,
				/*nicename("Unknown 137")*/ _import_input_unknown_137 = 138ui16,
				/*nicename("Editor Budget")*/ _import_input_editor_budget = 139ui16,
				/*nicename("Editor Budget Cost")*/ _import_input_editor_budget_cost = 140ui16,
				/*nicename("Film Total Time")*/ _import_input_film_total_time = 141ui16,
				/*nicename("Film Current Time")*/ _import_input_film_current_time = 142ui16,
				/*nicename("Unknown 142")*/ _import_input_unknown_142 = 143ui16,
				/*nicename("Film Timeline Fraction 1")*/ _import_input_film_timeline_fraction_1 = 144ui16,
				/*nicename("Film Timeline Fraction 2")*/ _import_input_film_timeline_fraction_2 = 145ui16,
				/*nicename("Unknown 145")*/ _import_input_unknown_145 = 146ui16,
				/*nicename("Unknown 146")*/ _import_input_unknown_146 = 147ui16,
				/*nicename("NetDebug Latency")*/ _import_input_netdebug_latency = 148ui16,
				/*nicename("NetDebug Latency Quality")*/ _import_input_netdebug_latency_quality = 149ui16,
				/*nicename("NetDebug Host Quality")*/ _import_input_netdebug_host_quality = 150ui16,
				/*nicename("NetDebug Local Quality")*/ _import_input_netdebug_local_quality = 151ui16,
			};

			enum nicename("Import Range Input") e_import_range_input : uint16_t
			{
				/*nicename("Zero")*/ _import_range_input_zero = 1ui16,
				/*nicename("One")*/ _import_range_input_one = 2ui16,
				/*nicename("Unknown 2")*/ _import_range_input_unknown_2 = 3ui16,
				/*nicename("Unknown 3")*/ _import_range_input_unknown_3 = 4ui16,
				/*nicename("Unknown 4")*/ _import_range_input_unknown_4 = 5ui16,
				/*nicename("Time")*/ _import_range_input_time = 6ui16,
				/*nicename("Fade")*/ _import_range_input_fade = 7ui16,
				/*nicename("Unknown 7")*/ _import_range_input_unknown_7 = 8ui16,
				/*nicename("Unknown 8")*/ _import_range_input_unknown_8 = 9ui16,
				/*nicename("Unknown 9")*/ _import_range_input_unknown_9 = 10ui16,
				/*nicename("Unknown 10")*/ _import_range_input_unknown_10 = 11ui16,
				/*nicename("Unknown 11")*/ _import_range_input_unknown_11 = 12ui16,
				/*nicename("Unknown 12")*/ _import_range_input_unknown_12 = 13ui16,
				/*nicename("Unknown 13")*/ _import_range_input_unknown_13 = 14ui16,
				/*nicename("Unknown 14")*/ _import_range_input_unknown_14 = 15ui16,
				/*nicename("Unknown 15")*/ _import_range_input_unknown_15 = 16ui16,
				/*nicename("Unknown 16")*/ _import_range_input_unknown_16 = 17ui16,
				/*nicename("Unknown 17")*/ _import_range_input_unknown_17 = 18ui16,
				/*nicename("Unknown 18")*/ _import_range_input_unknown_18 = 19ui16,
				/*nicename("Unknown 19")*/ _import_range_input_unknown_19 = 20ui16,
				/*nicename("Unknown 20")*/ _import_range_input_unknown_20 = 21ui16,
				/*nicename("Saber Unknown 1")*/ _import_range_input_saber_unknown_1 = 22ui16,
				/*nicename("Vehicle Health Current Percentage")*/ _import_range_input_vehicle_health_current_percentage = 23ui16,
				/*nicename("Unit Health Current")*/ _import_range_input_unit_health_current = 24ui16,
				/*nicename("Unit Health")*/ _import_range_input_unit_health = 25ui16,
				/*nicename("Unit Shield Current")*/ _import_range_input_unit_shield_current = 26ui16,
				/*nicename("Unit 1x Overshield Current")*/ _import_range_input_unit_1x_overshield_current = 27ui16,
				/*nicename("Unit 2x Overshield Current")*/ _import_range_input_unit_2x_overshield_current = 28ui16,
				/*nicename("Unit 2x Overshield Current")*/ _import_range_input_unit_2x_overshield_current1 = 29ui16,
				/*nicename("Unit Shield")*/ _import_range_input_unit_shield = 30ui16,
				/*nicename("Unit 1x Overshield")*/ _import_range_input_unit_1x_overshield = 31ui16,
				/*nicename("Unit 2x Overshield")*/ _import_range_input_unit_2x_overshield = 32ui16,
				/*nicename("Unit 3x Overshield")*/ _import_range_input_unit_3x_overshield = 33ui16,
				/*nicename("Unit Shield Current Percentage")*/ _import_range_input_unit_shield_current_percentage = 34ui16,
				/*nicename("Vehicle Shield Current Percentage")*/ _import_range_input_vehicle_shield_current_percentage = 35ui16,
				/*nicename("Boost Energy Fraction")*/ _import_range_input_boost_energy_fraction = 36ui16,
				/*nicename("Unknown 36")*/ _import_range_input_unknown_36 = 37ui16,
				/*nicename("Aim Yaw")*/ _import_range_input_aim_yaw = 38ui16,
				/*nicename("Aim Pitch")*/ _import_range_input_aim_pitch = 39ui16,
				/*nicename("Saber Waypoint Distance")*/ _import_range_input_saber_waypoint_distance = 40ui16,
				/*nicename("Sensor Range")*/ _import_range_input_sensor_range = 41ui16,
				/*nicename("Unit Altitude 1")*/ _import_range_input_unit_altitude_1 = 42ui16,
				/*nicename("Unit Altitude 2")*/ _import_range_input_unit_altitude_2 = 43ui16,
				/*nicename("Unknown 43")*/ _import_range_input_unknown_43 = 44ui16,
				/*nicename("Softkill Timer")*/ _import_range_input_softkill_timer = 45ui16,
				/*nicename("Transient Credits")*/ _import_range_input_transient_credits = 46ui16,
				/*nicename("Unknown 46")*/ _import_range_input_unknown_46 = 47ui16,
				/*nicename("Clip Ammo Fraction")*/ _import_range_input_clip_ammo_fraction = 48ui16,
				/*nicename("Total Ammo Fraction")*/ _import_range_input_total_ammo_fraction = 49ui16,
				/*nicename("Pickup")*/ _import_range_input_pickup = 50ui16,
				/*nicename("Heat Fraction")*/ _import_range_input_heat_fraction = 51ui16,
				/*nicename("Airstrike Charge Fraction")*/ _import_range_input_airstrike_charge_fraction = 52ui16,
				/*nicename("Battery Fraction")*/ _import_range_input_battery_fraction = 53ui16,
				/*nicename("Unknown 53")*/ _import_range_input_unknown_53 = 54ui16,
				/*nicename("Unknown 54")*/ _import_range_input_unknown_54 = 55ui16,
				/*nicename("Weapon Error")*/ _import_range_input_weapon_error = 56ui16,
				/*nicename("Unknown Weapon Error")*/ _import_range_input_unknown_weapon_error = 57ui16,
				/*nicename("Unit Autoaimed")*/ _import_range_input_unit_autoaimed = 58ui16,
				/*nicename("Saber Waypoint Distance Current")*/ _import_range_input_saber_waypoint_distance_current = 59ui16,
				/*nicename("Airstrike Distance")*/ _import_range_input_airstrike_distance = 60ui16,
				/*nicename("Nav Point Airstrike")*/ _import_range_input_nav_point_airstrike = 61ui16,
				/*nicename("Airstrike Ammo")*/ _import_range_input_airstrike_ammo = 62ui16,
				/*nicename("Unknown 62")*/ _import_range_input_unknown_62 = 63ui16,
				/*nicename("Unknown 63")*/ _import_range_input_unknown_63 = 64ui16,
				/*nicename("Grenade Fraction")*/ _import_range_input_grenade_fraction = 65ui16,
				/*nicename("Unknown 65")*/ _import_range_input_unknown_65 = 66ui16,
				/*nicename("Charge Fraction")*/ _import_range_input_charge_fraction = 67ui16,
				/*nicename("Unknown 67")*/ _import_range_input_unknown_67 = 68ui16,
				/*nicename("Trigger Cooldown")*/ _import_range_input_trigger_cooldown = 69ui16,
				/*nicename("Trigger Remote Detonate Fraction")*/ _import_range_input_trigger_remote_detonate_fraction = 70ui16,
				/*nicename("Trigger Locked On")*/ _import_range_input_trigger_locked_on = 71ui16,
				/*nicename("Target Distance")*/ _import_range_input_target_distance = 72ui16,
				/*nicename("Target Elevation")*/ _import_range_input_target_elevation = 73ui16,
				/*nicename("Equipment Energy Fraction")*/ _import_range_input_equipment_energy_fraction = 74ui16,
				/*nicename("Unknown 74")*/ _import_range_input_unknown_74 = 75ui16,
				/*nicename("Unknown 75")*/ _import_range_input_unknown_75 = 76ui16,
				/*nicename("Unknown 76")*/ _import_range_input_unknown_76 = 77ui16,
				/*nicename("Unknown 77")*/ _import_range_input_unknown_77 = 78ui16,
				/*nicename("Unknown 78")*/ _import_range_input_unknown_78 = 79ui16,
				/*nicename("Unknown 79")*/ _import_range_input_unknown_79 = 80ui16,
				/*nicename("Medal Commendation")*/ _import_range_input_medal_commendation = 81ui16,
				/*nicename("Generator Health Current")*/ _import_range_input_generator_health_current = 82ui16,
				/*nicename("Generator Health")*/ _import_range_input_generator_health = 83ui16,
				/*nicename("Unknown 83")*/ _import_range_input_unknown_83 = 84ui16,
				/*nicename("Waypoint")*/ _import_range_input_waypoint = 85ui16,
				/*nicename("Unknown 85")*/ _import_range_input_unknown_85 = 86ui16,
				/*nicename("Unknown 86")*/ _import_range_input_unknown_86 = 87ui16,
				/*nicename("Waypoint Onscreen")*/ _import_range_input_waypoint_onscreen = 88ui16,
				/*nicename("Waypoint Offscreen")*/ _import_range_input_waypoint_offscreen = 89ui16,
				/*nicename("Gametype Plate")*/ _import_range_input_gametype_plate = 90ui16,
				/*nicename("Offense Defense")*/ _import_range_input_offense_defense = 91ui16,
				/*nicename("Metagame Time")*/ _import_range_input_metagame_time = 92ui16,
				/*nicename("Metagame Score Transient")*/ _import_range_input_metagame_score_transient = 93ui16,
				/*nicename("Metagame Score Player 1")*/ _import_range_input_metagame_score_player_1 = 94ui16,
				/*nicename("Unknown 94")*/ _import_range_input_unknown_94 = 95ui16,
				/*nicename("Unknown 95")*/ _import_range_input_unknown_95 = 96ui16,
				/*nicename("Unknown 96")*/ _import_range_input_unknown_96 = 97ui16,
				/*nicename("Unknown 97")*/ _import_range_input_unknown_97 = 98ui16,
				/*nicename("Unknown 98")*/ _import_range_input_unknown_98 = 99ui16,
				/*nicename("Unknown 99")*/ _import_range_input_unknown_99 = 100ui16,
				/*nicename("Survival Multiplier")*/ _import_range_input_survival_multiplier = 101ui16,
				/*nicename("Metagame Score Negative")*/ _import_range_input_metagame_score_negative = 102ui16,
				/*nicename("Survival Set")*/ _import_range_input_survival_set = 103ui16,
				/*nicename("Unknown 103")*/ _import_range_input_unknown_103 = 104ui16,
				/*nicename("Survival Waves Background")*/ _import_range_input_survival_waves_background = 105ui16,
				/*nicename("Survival Lives 1")*/ _import_range_input_survival_lives_1 = 106ui16,
				/*nicename("Survival Lives 2")*/ _import_range_input_survival_lives_2 = 107ui16,
				/*nicename("Survival Bonus Timer")*/ _import_range_input_survival_bonus_timer = 108ui16,
				/*nicename("Unknown 108")*/ _import_range_input_unknown_108 = 109ui16,
				/*nicename("Unknown 109")*/ _import_range_input_unknown_109 = 110ui16,
				/*nicename("Friendly Score")*/ _import_range_input_friendly_score = 111ui16,
				/*nicename("Enemy Score")*/ _import_range_input_enemy_score = 112ui16,
				/*nicename("Score To Win")*/ _import_range_input_score_to_win = 113ui16,
				/*nicename("Arming Fraction")*/ _import_range_input_arming_fraction = 114ui16,
				/*nicename("Posession Icon")*/ _import_range_input_posession_icon = 115ui16,
				/*nicename("Arming Unknown")*/ _import_range_input_arming_unknown = 116ui16,
				/*nicename("Omniwidget Icon")*/ _import_range_input_omniwidget_icon = 117ui16,
				/*nicename("Unknown 117")*/ _import_range_input_unknown_117 = 118ui16,
				/*nicename("Fireteam Health")*/ _import_range_input_fireteam_health = 119ui16,
				/*nicename("Unknown 119")*/ _import_range_input_unknown_119 = 120ui16,
				/*nicename("Unknown 120")*/ _import_range_input_unknown_120 = 121ui16,
				/*nicename("Unknown 121")*/ _import_range_input_unknown_121 = 122ui16,
				/*nicename("Fireteam Current Shield")*/ _import_range_input_fireteam_current_shield = 123ui16,
				/*nicename("Unknown 123")*/ _import_range_input_unknown_123 = 124ui16,
				/*nicename("Unknown 124")*/ _import_range_input_unknown_124 = 125ui16,
				/*nicename("Fireteam 1 Arming Fraction")*/ _import_range_input_fireteam_1_arming_fraction = 126ui16,
				/*nicename("Fireteam 2 Arming Fraction")*/ _import_range_input_fireteam_2_arming_fraction = 127ui16,
				/*nicename("Unknown 127")*/ _import_range_input_unknown_127 = 128ui16,
				/*nicename("Fireteam 1 Directional Arrow")*/ _import_range_input_fireteam_1_directional_arrow = 129ui16,
				/*nicename("Fireteam 2 Directional Arrow")*/ _import_range_input_fireteam_2_directional_arrow = 130ui16,
				/*nicename("Unknown 130")*/ _import_range_input_unknown_130 = 131ui16,
				/*nicename("Unknown 131")*/ _import_range_input_unknown_131 = 132ui16,
				/*nicename("Unknown 132")*/ _import_range_input_unknown_132 = 133ui16,
				/*nicename("Unknown 133")*/ _import_range_input_unknown_133 = 134ui16,
				/*nicename("Unknown 134")*/ _import_range_input_unknown_134 = 135ui16,
				/*nicename("Unknown 135")*/ _import_range_input_unknown_135 = 136ui16,
				/*nicename("Unknown 136")*/ _import_range_input_unknown_136 = 137ui16,
				/*nicename("Unknown 137")*/ _import_range_input_unknown_137 = 138ui16,
				/*nicename("Editor Budget")*/ _import_range_input_editor_budget = 139ui16,
				/*nicename("Editor Budget Cost")*/ _import_range_input_editor_budget_cost = 140ui16,
				/*nicename("Film Total Time")*/ _import_range_input_film_total_time = 141ui16,
				/*nicename("Film Current Time")*/ _import_range_input_film_current_time = 142ui16,
				/*nicename("Unknown 142")*/ _import_range_input_unknown_142 = 143ui16,
				/*nicename("Film Timeline Fraction 1")*/ _import_range_input_film_timeline_fraction_1 = 144ui16,
				/*nicename("Film Timeline Fraction 2")*/ _import_range_input_film_timeline_fraction_2 = 145ui16,
				/*nicename("Unknown 145")*/ _import_range_input_unknown_145 = 146ui16,
				/*nicename("Unknown 146")*/ _import_range_input_unknown_146 = 147ui16,
				/*nicename("NetDebug Latency")*/ _import_range_input_netdebug_latency = 148ui16,
				/*nicename("NetDebug Latency Quality")*/ _import_range_input_netdebug_latency_quality = 149ui16,
				/*nicename("NetDebug Host Quality")*/ _import_range_input_netdebug_host_quality = 150ui16,
				/*nicename("NetDebug Local Quality")*/ _import_range_input_netdebug_local_quality = 151ui16,
			};

			enum nicename("Font") e_font : uint16_t
			{
				/*nicename("Fixedsys, 9")*/ _font_fixedsys_9 = 1ui16,
				/*nicename("TV Nord Condensed, 18")*/ _font_tv_nord_condensed_18 = 2ui16,
				/*nicename("TV Nord Condensed, Bold, 24")*/ _font_tv_nord_condensed_bold_24 = 3ui16,
				/*nicename("TV Nord Condensed, Bold, 42")*/ _font_tv_nord_condensed_bold_42 = 4ui16,
				/*nicename("TV Nord Condensed, Bold, 30")*/ _font_tv_nord_condensed_bold_30 = 5ui16,
				/*nicename("Eurostile Lt Demi, 13")*/ _font_eurostile_lt_demi_13 = 6ui16,
				/*nicename("TV Nord Hud, 15")*/ _font_tv_nord_hud_15 = 7ui16,
				/*nicename("TV Nord Condensed, 16")*/ _font_tv_nord_condensed_16 = 8ui16,
				/*nicename("Eurostile Lt Demi, 18")*/ _font_eurostile_lt_demi_18 = 9ui16,
				/*nicename("TV Nord Condensed, 15")*/ _font_tv_nord_condensed_15 = 10ui16,
				/*nicename("TV Nord Condensed, 17")*/ _font_tv_nord_condensed_17 = 11ui16,
			};

			enum nicename("Flags") b_flags : uint16_t /* bitfield */
			{
				/*nicename("String Is A Number")*/ _flags_string_is_a_number = 1ui16 << 0ui16,
				/*nicename("Force 2-Digit")*/ _flags_force_2_digit = 1ui16 << 1ui16,
				/*nicename("Force 3-Digit")*/ _flags_force_3_digit = 1ui16 << 2ui16,
				/*nicename("'+' Prefix")*/ _flags__prefix = 1ui16 << 3ui16,
				/*nicename("'m' Suffix")*/ _flags_m_suffix = 1ui16 << 4ui16,
				/*nicename("Tenths Decimal")*/ _flags_tenths_decimal = 1ui16 << 5ui16,
				/*nicename("Hundredths Decimal")*/ _flags_hundredths_decimal = 1ui16 << 6ui16,
				/*nicename("Thousandths Decimal")*/ _flags_thousandths_decimal = 1ui16 << 7ui16,
				/*nicename("Hundred Thousandths Decimal")*/ _flags_hundred_thousandths_decimal = 1ui16 << 8ui16,
				/*nicename("Only A Number")*/ _flags_only_a_number = 1ui16 << 9ui16,
				/*nicename("'x' Suffix")*/ _flags_x_suffix = 1ui16 << 10ui16,
				/*nicename("In Brackets")*/ _flags_in_brackets = 1ui16 << 11ui16,
				/*nicename("Time Format S:MS")*/ _flags_time_format_sms = 1ui16 << 12ui16,
				/*nicename("Time Format H:M:S")*/ _flags_time_format_hms = 1ui16 << 13ui16,
				/*nicename("Money Format")*/ _flags_money_format = 1ui16 << 14ui16,
				/*nicename("'-' Prefix")*/ _flags___prefix = 1ui16 << 15ui16,
			};

			struct nicename("State Data") s_state_data2_definition
			{
				struct nicename("'Yes' States") s_yes_states2_definition
				{
					struct nicename("Triggers") s_triggers6_definition
					{
						enum nicename("Flag") b_flag : uint8_t /* bitfield */
						{
							/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
						};

						b_flag nicename("Flag") flag;
						int8_t __unknown0;
						int8_t __unknown1;
						int8_t __unknown2;
						int32_t nicename("Trigger Index") trigger_index;
					};

					s_tag_block_definition<s_triggers6_definition> nicename("Triggers") triggers_block;
				};

				struct nicename("Unknown States") s_unknown_states2_definition
				{
					struct nicename("Triggers") s_triggers7_definition
					{
						enum nicename("Flag") b_flag : uint8_t /* bitfield */
						{
							/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
						};

						b_flag nicename("Flag") flag;
						int8_t __unknown0;
						int8_t __unknown1;
						int8_t __unknown2;
						int32_t nicename("Trigger Index") trigger_index;
					};

					s_tag_block_definition<s_triggers7_definition> nicename("Triggers") triggers_block;
				};

				struct nicename("'No' States") s_no_states2_definition
				{
					struct nicename("Triggers") s_triggers8_definition
					{
						enum nicename("Flag") b_flag : uint8_t /* bitfield */
						{
							/*nicename("Input Variable")*/ _flag_input_variable = 1ui8 << 0ui8,
						};

						b_flag nicename("Flag") flag;
						int8_t __unknown0;
						int8_t __unknown1;
						int8_t __unknown2;
						int32_t nicename("Trigger Index") trigger_index;
					};

					s_tag_block_definition<s_triggers8_definition> nicename("Triggers") triggers_block;
				};

				// State Data Note : The following blocks are import data.
				s_tag_block_definition<s_yes_states2_definition> nicename("'Yes' States") yes_states_block;
				s_tag_block_definition<s_unknown_states2_definition> nicename("Unknown States") unknown_states_block;
				s_tag_block_definition<s_no_states2_definition> nicename("'No' States") no_states_block;
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t __unknown2;
				int16_t __unknown3;
				Undefined32 __unknown4;
				Undefined32 __unknown5;
				Undefined32 __unknown6;
			};

			struct nicename("Placement Data") s_placement_data2_definition
			{
				enum nicename("Anchor") e_anchor : uint8_t
				{
					/*nicename("Unknown")*/ _anchor_unknown = 1ui8,
					/*nicename("Top, Left")*/ _anchor_top_left = 2ui8,
					/*nicename("Top, Middle")*/ _anchor_top_middle = 3ui8,
					/*nicename("Top, Right")*/ _anchor_top_right = 4ui8,
					/*nicename("Center, Middle")*/ _anchor_center_middle = 5ui8,
					/*nicename("Bottom, Left")*/ _anchor_bottom_left = 6ui8,
					/*nicename("Bottom, Middle")*/ _anchor_bottom_middle = 7ui8,
					/*nicename("Bottom, Right")*/ _anchor_bottom_right = 8ui8,
					/*nicename("Motion Sensor")*/ _anchor_motion_sensor = 9ui8,
					/*nicename("Crosshair A")*/ _anchor_crosshair_a = 10ui8,
					/*nicename("Ability")*/ _anchor_ability = 11ui8,
					/*nicename("Weapon Left")*/ _anchor_weapon_left = 12ui8,
					/*nicename("Weapon Right")*/ _anchor_weapon_right = 13ui8,
					/*nicename("Health and Shield")*/ _anchor_health_and_shield = 14ui8,
					/*nicename("Unknown")*/ _anchor_unknown1 = 15ui8,
					/*nicename("Top, Left B")*/ _anchor_top_left_b = 16ui8,
					/*nicename("Unknown")*/ _anchor_unknown2 = 17ui8,
					/*nicename("Crosshair B")*/ _anchor_crosshair_b = 18ui8,
					/*nicename("Top, Left C")*/ _anchor_top_left_c = 19ui8,
					/*nicename("Top, Left D")*/ _anchor_top_left_d = 20ui8,
					/*nicename("Top, Left E")*/ _anchor_top_left_e = 21ui8,
					/*nicename("Crosshair B")*/ _anchor_crosshair_b1 = 22ui8,
					/*nicename("Top, Left F")*/ _anchor_top_left_f = 23ui8,
					/*nicename("Unknown")*/ _anchor_unknown3 = 24ui8,
					/*nicename("Top, Left G")*/ _anchor_top_left_g = 25ui8,
					/*nicename("Unknown")*/ _anchor_unknown4 = 26ui8,
					/*nicename("Top, Left F")*/ _anchor_top_left_f1 = 27ui8,
					/*nicename("Score")*/ _anchor_score = 28ui8,
					/*nicename("Score B")*/ _anchor_score_b = 29ui8,
					/*nicename("Score C")*/ _anchor_score_c = 30ui8,
					/*nicename("Score D")*/ _anchor_score_d = 31ui8,
					/*nicename("Score E")*/ _anchor_score_e = 32ui8,
					/*nicename("Score F")*/ _anchor_score_f = 33ui8,
					/*nicename("Score G")*/ _anchor_score_g = 34ui8,
					/*nicename("Unknown")*/ _anchor_unknown5 = 35ui8,
					/*nicename("Unknown")*/ _anchor_unknown6 = 36ui8,
					/*nicename("Unknown")*/ _anchor_unknown7 = 37ui8,
					/*nicename("Unknown")*/ _anchor_unknown8 = 38ui8,
					/*nicename("Unknown")*/ _anchor_unknown9 = 39ui8,
					/*nicename("Unknown")*/ _anchor_unknown10 = 40ui8,
				};

				enum b_unknown : uint8_t /* bitfield */
				{
					/*nicename("Bit 0")*/ _unknown_bit_0 = 1ui8 << 0ui8,
					/*nicename("Bit 1")*/ _unknown_bit_1 = 1ui8 << 1ui8,
					/*nicename("Bit 2")*/ _unknown_bit_2 = 1ui8 << 2ui8,
					/*nicename("Bit 3")*/ _unknown_bit_3 = 1ui8 << 3ui8,
					/*nicename("Bit 4")*/ _unknown_bit_4 = 1ui8 << 4ui8,
					/*nicename("Bit 5")*/ _unknown_bit_5 = 1ui8 << 5ui8,
					/*nicename("Bit 6")*/ _unknown_bit_6 = 1ui8 << 6ui8,
					/*nicename("Bit 7")*/ _unknown_bit_7 = 1ui8 << 7ui8,
				};

				b_unknown __unknown0;
				e_anchor nicename("Anchor") anchor;
				int16_t __unknown1;
				float nicename("Mirror Offset X") mirror_offset_x;
				float nicename("Mirror Offset Y") mirror_offset_y;
				float nicename("Offset X") offset_x;
				float nicename("Offset Y") offset_y;
				float nicename("Scale X") scale_x;
				float nicename("Scale Y") scale_y;
			};

			struct nicename("Animation Data") s_animation_data2_definition
			{
				enum nicename("Animation 1 Function") e_animation_1_function : uint8_t
				{
					/*nicename("Default")*/ _animation_1_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_1_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_1_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_1_function_zero = 4ui8,
				};

				enum nicename("Animation 2 Function") e_animation_2_function : uint8_t
				{
					/*nicename("Default")*/ _animation_2_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_2_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_2_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_2_function_zero = 4ui8,
				};

				enum nicename("Animation 3 Function") e_animation_3_function : uint8_t
				{
					/*nicename("Default")*/ _animation_3_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_3_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_3_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_3_function_zero = 4ui8,
				};

				enum nicename("Animation 4 Function") e_animation_4_function : uint8_t
				{
					/*nicename("Default")*/ _animation_4_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_4_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_4_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_4_function_zero = 4ui8,
				};

				enum nicename("Animation 5 Function") e_animation_5_function : uint8_t
				{
					/*nicename("Default")*/ _animation_5_function_default = 1ui8,
					/*nicename("Use Input")*/ _animation_5_function_use_input = 2ui8,
					/*nicename("Use Range Input")*/ _animation_5_function_use_range_input = 3ui8,
					/*nicename("Zero")*/ _animation_5_function_zero = 4ui8,
				};

				enum nicename("Animation 1 Flags") b_animation_1_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_1_flags_reverse_frames = 1ui8 << 0ui8,
				};

				enum nicename("Animation 2 Flags") b_animation_2_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_2_flags_reverse_frames = 1ui8 << 0ui8,
				};

				enum nicename("Animation 3 Flags") b_animation_3_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_3_flags_reverse_frames = 1ui8 << 0ui8,
				};

				enum nicename("Animation 4 Flags") b_animation_4_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_4_flags_reverse_frames = 1ui8 << 0ui8,
				};

				enum nicename("Animation 5 Flags") b_animation_5_flags : uint8_t /* bitfield */
				{
					/*nicename("Reverse Frames")*/ _animation_5_flags_reverse_frames = 1ui8 << 0ui8,
				};

				b_animation_1_flags nicename("Animation 1 Flags") animation_1_flags;
				e_animation_1_function nicename("Animation 1 Function") animation_1_function;
				int16_t __unknown0;
				TagReference nicename("Animation 1") animation_1_reference;
				b_animation_2_flags nicename("Animation 2 Flags") animation_2_flags;
				e_animation_2_function nicename("Animation 2 Function") animation_2_function;
				int16_t __unknown1;
				TagReference nicename("Animation 2") animation_2_reference;
				b_animation_3_flags nicename("Animation 3 Flags") animation_3_flags;
				e_animation_3_function nicename("Animation 3 Function") animation_3_function;
				int16_t __unknown2;
				TagReference nicename("Animation 3") animation_3_reference;
				b_animation_4_flags nicename("Animation 4 Flags") animation_4_flags;
				e_animation_4_function nicename("Animation 4 Function") animation_4_function;
				int16_t __unknown3;
				TagReference nicename("Animation 4") animation_4_reference;
				b_animation_5_flags nicename("Animation 5 Flags") animation_5_flags;
				e_animation_5_function nicename("Animation 5 Function") animation_5_function;
				int16_t __unknown4;
				TagReference nicename("Animation 5") animation_5_reference;
			};

			struct nicename("Render Data") s_render_data2_definition
			{
				enum nicename("Shader Index") e_shader_index : uint8_t
				{
					/*nicename("Cheap")*/ _shader_index_cheap = 1ui8,
					/*nicename("Simple")*/ _shader_index_simple = 2ui8,
					/*nicename("Meter")*/ _shader_index_meter = 3ui8,
					/*nicename("Text Simple")*/ _shader_index_text_simple = 4ui8,
					/*nicename("Meter Shield")*/ _shader_index_meter_shield = 5ui8,
					/*nicename("Meter Gradient")*/ _shader_index_meter_gradient = 6ui8,
					/*nicename("Crosshair")*/ _shader_index_crosshair = 7ui8,
					/*nicename("Directional Damage")*/ _shader_index_directional_damage = 8ui8,
					/*nicename("Solid")*/ _shader_index_solid = 9ui8,
					/*nicename("Sensor")*/ _shader_index_sensor = 10ui8,
					/*nicename("Meter Single Color")*/ _shader_index_meter_single_color = 11ui8,
					/*nicename("Navpoint")*/ _shader_index_navpoint = 12ui8,
					/*nicename("Medal")*/ _shader_index_medal = 13ui8,
					/*nicename("Texture Cam")*/ _shader_index_texture_cam = 14ui8,
					/*nicename("Meter Chapter")*/ _shader_index_meter_chapter = 15ui8,
					/*nicename("Meter Double Gradient")*/ _shader_index_meter_double_gradient = 16ui8,
					/*nicename("Meter Radial Gradient")*/ _shader_index_meter_radial_gradient = 17ui8,
					/*nicename("Turbulence")*/ _shader_index_turbulence = 18ui8,
					/*nicename("Emblem")*/ _shader_index_emblem = 19ui8,
					/*nicename("Directional Damage Apply")*/ _shader_index_directional_damage_apply = 20ui8,
					/*nicename("Damage Tracker")*/ _shader_index_damage_tracker = 21ui8,
				};

				enum nicename("Output Color a") e_output_color_a : uint16_t
				{
					/*nicename("Local a")*/ _output_color_a_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_a_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_a_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_a_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_a_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_a_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_a_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_a_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_a_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_a_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_a_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_a_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_a_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_a_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_a_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_a_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_a_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_a_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_a_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_a_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_a_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_a_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_a_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_a_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_a_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_a_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_a_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_a_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_a_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_a_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_a_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_a_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_a_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_a_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_a_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_a_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_a_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_a_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_a_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_a_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_a_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_a_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_a_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_a_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_a_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_a_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_a_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_a_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_a_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_a_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_a_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_a_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_a_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_a_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_a_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_a_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_a_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_a_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_a_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_a_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_a_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color b") e_output_color_b : uint16_t
				{
					/*nicename("Local a")*/ _output_color_b_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_b_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_b_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_b_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_b_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_b_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_b_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_b_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_b_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_b_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_b_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_b_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_b_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_b_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_b_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_b_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_b_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_b_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_b_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_b_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_b_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_b_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_b_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_b_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_b_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_b_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_b_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_b_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_b_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_b_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_b_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_b_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_b_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_b_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_b_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_b_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_b_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_b_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_b_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_b_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_b_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_b_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_b_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_b_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_b_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_b_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_b_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_b_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_b_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_b_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_b_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_b_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_b_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_b_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_b_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_b_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_b_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_b_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_b_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_b_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_b_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color c") e_output_color_c : uint16_t
				{
					/*nicename("Local a")*/ _output_color_c_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_c_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_c_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_c_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_c_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_c_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_c_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_c_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_c_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_c_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_c_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_c_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_c_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_c_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_c_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_c_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_c_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_c_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_c_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_c_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_c_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_c_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_c_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_c_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_c_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_c_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_c_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_c_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_c_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_c_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_c_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_c_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_c_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_c_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_c_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_c_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_c_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_c_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_c_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_c_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_c_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_c_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_c_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_c_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_c_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_c_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_c_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_c_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_c_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_c_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_c_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_c_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_c_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_c_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_c_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_c_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_c_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_c_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_c_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_c_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_c_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color d") e_output_color_d : uint16_t
				{
					/*nicename("Local a")*/ _output_color_d_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_d_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_d_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_d_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_d_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_d_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_d_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_d_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_d_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_d_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_d_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_d_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_d_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_d_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_d_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_d_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_d_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_d_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_d_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_d_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_d_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_d_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_d_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_d_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_d_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_d_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_d_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_d_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_d_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_d_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_d_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_d_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_d_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_d_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_d_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_d_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_d_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_d_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_d_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_d_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_d_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_d_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_d_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_d_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_d_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_d_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_d_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_d_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_d_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_d_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_d_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_d_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_d_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_d_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_d_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_d_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_d_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_d_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_d_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_d_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_d_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color e") e_output_color_e : uint16_t
				{
					/*nicename("Local a")*/ _output_color_e_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_e_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_e_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_e_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_e_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_e_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_e_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_e_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_e_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_e_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_e_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_e_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_e_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_e_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_e_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_e_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_e_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_e_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_e_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_e_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_e_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_e_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_e_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_e_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_e_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_e_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_e_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_e_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_e_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_e_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_e_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_e_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_e_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_e_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_e_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_e_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_e_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_e_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_e_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_e_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_e_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_e_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_e_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_e_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_e_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_e_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_e_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_e_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_e_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_e_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_e_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_e_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_e_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_e_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_e_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_e_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_e_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_e_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_e_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_e_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_e_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Color f") e_output_color_f : uint16_t
				{
					/*nicename("Local a")*/ _output_color_f_local_a = 1ui16,
					/*nicename("Local b")*/ _output_color_f_local_b = 2ui16,
					/*nicename("Local c")*/ _output_color_f_local_c = 3ui16,
					/*nicename("Local d")*/ _output_color_f_local_d = 4ui16,
					/*nicename("Unknown 4")*/ _output_color_f_unknown_4 = 5ui16,
					/*nicename("Unknown 5")*/ _output_color_f_unknown_5 = 6ui16,
					/*nicename("Scoreboard Friendly")*/ _output_color_f_scoreboard_friendly = 7ui16,
					/*nicename("Scoreboard Enemy")*/ _output_color_f_scoreboard_enemy = 8ui16,
					/*nicename("Arming Team")*/ _output_color_f_arming_team = 9ui16,
					/*nicename("Metagame Player 1")*/ _output_color_f_metagame_player_1 = 10ui16,
					/*nicename("Metagame Player 2")*/ _output_color_f_metagame_player_2 = 11ui16,
					/*nicename("Metagame Player 3")*/ _output_color_f_metagame_player_3 = 12ui16,
					/*nicename("Metagame Player 4")*/ _output_color_f_metagame_player_4 = 13ui16,
					/*nicename("Unknown 13")*/ _output_color_f_unknown_13 = 14ui16,
					/*nicename("Unknown 14")*/ _output_color_f_unknown_14 = 15ui16,
					/*nicename("Unknown 15")*/ _output_color_f_unknown_15 = 16ui16,
					/*nicename("Unknown 16")*/ _output_color_f_unknown_16 = 17ui16,
					/*nicename("Unknown 17")*/ _output_color_f_unknown_17 = 18ui16,
					/*nicename("Global Dynamic 0")*/ _output_color_f_global_dynamic_0 = 19ui16,
					/*nicename("Global Dynamic 1")*/ _output_color_f_global_dynamic_1 = 20ui16,
					/*nicename("Global Dynamic 2")*/ _output_color_f_global_dynamic_2 = 21ui16,
					/*nicename("Global Dynamic 3")*/ _output_color_f_global_dynamic_3 = 22ui16,
					/*nicename("Global Dynamic 4")*/ _output_color_f_global_dynamic_4 = 23ui16,
					/*nicename("Global Dynamic 5")*/ _output_color_f_global_dynamic_5 = 24ui16,
					/*nicename("Global Dynamic 6")*/ _output_color_f_global_dynamic_6 = 25ui16,
					/*nicename("Global Dynamic 7")*/ _output_color_f_global_dynamic_7 = 26ui16,
					/*nicename("Global Dynamic 8")*/ _output_color_f_global_dynamic_8 = 27ui16,
					/*nicename("Global Dynamic 9")*/ _output_color_f_global_dynamic_9 = 28ui16,
					/*nicename("Global Dynamic 10")*/ _output_color_f_global_dynamic_10 = 29ui16,
					/*nicename("Global Dynamic 11")*/ _output_color_f_global_dynamic_11 = 30ui16,
					/*nicename("Global Dynamic 12")*/ _output_color_f_global_dynamic_12 = 31ui16,
					/*nicename("Global Dynamic 13")*/ _output_color_f_global_dynamic_13 = 32ui16,
					/*nicename("Global Dynamic 14")*/ _output_color_f_global_dynamic_14 = 33ui16,
					/*nicename("Global Dynamic 15")*/ _output_color_f_global_dynamic_15 = 34ui16,
					/*nicename("Global Dynamic 16")*/ _output_color_f_global_dynamic_16 = 35ui16,
					/*nicename("Global Dynamic 17")*/ _output_color_f_global_dynamic_17 = 36ui16,
					/*nicename("Global Dynamic 18")*/ _output_color_f_global_dynamic_18 = 37ui16,
					/*nicename("Global Dynamic 19")*/ _output_color_f_global_dynamic_19 = 38ui16,
					/*nicename("Global Dynamic 20")*/ _output_color_f_global_dynamic_20 = 39ui16,
					/*nicename("Global Dynamic 21")*/ _output_color_f_global_dynamic_21 = 40ui16,
					/*nicename("Global Dynamic 22")*/ _output_color_f_global_dynamic_22 = 41ui16,
					/*nicename("Global Dynamic 23")*/ _output_color_f_global_dynamic_23 = 42ui16,
					/*nicename("Global Dynamic 24")*/ _output_color_f_global_dynamic_24 = 43ui16,
					/*nicename("Global Dynamic 25")*/ _output_color_f_global_dynamic_25 = 44ui16,
					/*nicename("Global Dynamic 26")*/ _output_color_f_global_dynamic_26 = 45ui16,
					/*nicename("Global Dynamic 27")*/ _output_color_f_global_dynamic_27 = 46ui16,
					/*nicename("Global Dynamic 28")*/ _output_color_f_global_dynamic_28 = 47ui16,
					/*nicename("Global Dynamic 29")*/ _output_color_f_global_dynamic_29 = 48ui16,
					/*nicename("Global Dynamic 30")*/ _output_color_f_global_dynamic_30 = 49ui16,
					/*nicename("Global Dynamic 31")*/ _output_color_f_global_dynamic_31 = 50ui16,
					/*nicename("Global Dynamic 32")*/ _output_color_f_global_dynamic_32 = 51ui16,
					/*nicename("Global Dynamic 33")*/ _output_color_f_global_dynamic_33 = 52ui16,
					/*nicename("Global Dynamic 34")*/ _output_color_f_global_dynamic_34 = 53ui16,
					/*nicename("Global Dynamic 35")*/ _output_color_f_global_dynamic_35 = 54ui16,
					/*nicename("Global Dynamic 36")*/ _output_color_f_global_dynamic_36 = 55ui16,
					/*nicename("Global Dynamic 37")*/ _output_color_f_global_dynamic_37 = 56ui16,
					/*nicename("Global Dynamic 38")*/ _output_color_f_global_dynamic_38 = 57ui16,
					/*nicename("Global Dynamic 39")*/ _output_color_f_global_dynamic_39 = 58ui16,
					/*nicename("Global Dynamic 40")*/ _output_color_f_global_dynamic_40 = 59ui16,
					/*nicename("Global Dynamic 41")*/ _output_color_f_global_dynamic_41 = 60ui16,
					/*nicename("Global Dynamic 42")*/ _output_color_f_global_dynamic_42 = 61ui16,
				};

				enum nicename("Output Scalar a") e_output_scalar_a : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_a_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_a_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_a_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_a_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_a_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_a_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_a_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_a_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_a_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_a_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar b") e_output_scalar_b : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_b_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_b_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_b_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_b_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_b_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_b_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_b_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_b_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_b_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_b_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar c") e_output_scalar_c : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_c_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_c_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_c_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_c_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_c_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_c_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_c_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_c_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_c_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_c_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar d") e_output_scalar_d : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_d_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_d_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_d_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_d_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_d_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_d_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_d_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_d_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_d_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_d_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar e") e_output_scalar_e : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_e_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_e_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_e_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_e_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_e_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_e_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_e_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_e_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_e_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_e_unknown_9 = 10ui16,
				};

				enum nicename("Output Scalar f") e_output_scalar_f : uint16_t
				{
					/*nicename("Unknown 0")*/ _output_scalar_f_unknown_0 = 1ui16,
					/*nicename("Unknown 1")*/ _output_scalar_f_unknown_1 = 2ui16,
					/*nicename("Input")*/ _output_scalar_f_input = 3ui16,
					/*nicename("Range Input")*/ _output_scalar_f_range_input = 4ui16,
					/*nicename("Local a")*/ _output_scalar_f_local_a = 5ui16,
					/*nicename("Local b")*/ _output_scalar_f_local_b = 6ui16,
					/*nicename("Local c")*/ _output_scalar_f_local_c = 7ui16,
					/*nicename("Local d")*/ _output_scalar_f_local_d = 8ui16,
					/*nicename("Unknown 8")*/ _output_scalar_f_unknown_8 = 9ui16,
					/*nicename("Unknown 9")*/ _output_scalar_f_unknown_9 = 10ui16,
				};

				e_shader_index nicename("Shader Index") shader_index;
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				float nicename("Local Color Alpha a") local_color_alpha_a;
				colorf nicename("Local Color a") local_color_a;
				float nicename("Local Color Alpha b") local_color_alpha_b;
				colorf nicename("Local Color b") local_color_b;
				float nicename("Local Color Alpha c") local_color_alpha_c;
				colorf nicename("Local Color c") local_color_c;
				float nicename("Local Color Alpha d") local_color_alpha_d;
				colorf nicename("Local Color d") local_color_d;
				float nicename("Local Scalar a") local_scalar_a;
				float nicename("Local Scalar b") local_scalar_b;
				float nicename("Local Scalar c") local_scalar_c;
				float nicename("Local Scalar d") local_scalar_d;
				e_output_color_a nicename("Output Color a") output_color_a;
				e_output_color_b nicename("Output Color b") output_color_b;
				e_output_color_c nicename("Output Color c") output_color_c;
				e_output_color_d nicename("Output Color d") output_color_d;
				e_output_color_e nicename("Output Color e") output_color_e;
				e_output_color_f nicename("Output Color f") output_color_f;
				e_output_scalar_a nicename("Output Scalar a") output_scalar_a;
				e_output_scalar_b nicename("Output Scalar b") output_scalar_b;
				e_output_scalar_c nicename("Output Scalar c") output_scalar_c;
				e_output_scalar_d nicename("Output Scalar d") output_scalar_d;
				e_output_scalar_e nicename("Output Scalar e") output_scalar_e;
				e_output_scalar_f nicename("Output Scalar f") output_scalar_f;
				Undefined32 __unknown3;
				Undefined32 __unknown4;
				int16_t __unknown5;
				int16_t __unknown6;
			};

			DEPRECATED_string_id nicename("Name") name;
			e_special_hud_type nicename("Special HUD Type") special_hud_type;
			uint8_t __unknown0;
			uint8_t __unknown1;
			uint8_t __unknown2;
			e_import_input nicename("Import Input") import_input;
			e_import_range_input nicename("Import Range Input") import_range_input;
			TagReference nicename("State Data Template") state_data_template_reference;
			s_tag_block_definition<s_state_data2_definition> nicename("State Data") state_data_block;
			TagReference nicename("Placement Data Template") placement_data_template_reference;
			s_tag_block_definition<s_placement_data2_definition> nicename("Placement Data") placement_data_block;
			TagReference nicename("Animation Data Template") animation_data_template_reference;
			s_tag_block_definition<s_animation_data2_definition> nicename("Animation Data") animation_data_block;
			TagReference nicename("Render Data Template") render_data_template_reference;
			s_tag_block_definition<s_render_data2_definition> nicename("Render Data") render_data_block;
			b_flags nicename("Flags") flags;
			e_font nicename("Font") font;
			DEPRECATED_string_id nicename("String") string;
		};

		DEPRECATED_string_id nicename("Name") name;
		e_special_hud_type nicename("Special HUD Type") special_hud_type;
		uint8_t __unknown0;
		uint8_t __unknown1;
		uint8_t __unknown2;
		e_import_input nicename("Import Input") import_input;
		e_import_range_input nicename("Import Range Input") import_range_input;
		TagReference nicename("State Data Template") state_data_template_reference;
		s_tag_block_definition<s_state_data_definition> nicename("State Data") state_data_block;
		TagReference nicename("Placement Data Template") placement_data_template_reference;
		s_tag_block_definition<s_placement_data_definition> nicename("Placement Data") placement_data_block;
		TagReference nicename("Animation Data Template") animation_data_template_reference;
		s_tag_block_definition<s_animation_data_definition> nicename("Animation Data") animation_data_block;
		TagReference nicename("Render Data Template") render_data_template_reference;
		s_tag_block_definition<s_render_data_definition> nicename("Render Data") render_data_block;
		TagReference nicename("Datasource Template") datasource_template_reference;
		s_tag_block_definition<s_datasource_definition> nicename("Datasource") datasource_block;
		s_tag_block_definition<s_bitmap_widgets_definition> nicename("Bitmap Widgets") bitmap_widgets_block;
		s_tag_block_definition<s_text_widgets_definition> nicename("Text Widgets") text_widgets_block;
		int32_t __unknown3;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t __unknown6;
		int16_t __unknown7;
		// Block Starting Value :  Since the states values are dynamic, this enum is used to determine where the next "X States" data starts, even if the block was empty.
		e_second_state_block_starting_value nicename("Second State-Block Starting Value") second_state_block_starting_value;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		// Input Variable Triggers : Since the states values are dynamic, these bits are used to determine where the triggers that have the "Input Variable" flag checked are.
		b_input_variable_triggers nicename("Input Variable Triggers") input_variable_triggers1;
		/* Compiled States (HUD Widgets) : Uses this format:
		   
		   -States (Yes, No) Count ("Unknown" States not used here!)
		   Then for every States count:
		   -Triggers Count
		   Then for every Triggers count:
		   -Trigger Index
		   
		   Repeats for both States blocks. Use a 0 if the block is null.
		   It is currently unknown what the criteria is for more than one "X States" index.
		   Check existing tags for examples, good luck. */
		int16_t nicename("0") _0;
		int16_t nicename("1") _1;
		int16_t nicename("2") _2;
		int16_t nicename("3") _3;
		int16_t nicename("4") _4;
		int16_t nicename("5") _5;
		int16_t nicename("6") _6;
		int16_t nicename("7") _7;
		int16_t nicename("8") _8;
		int16_t nicename("9") _9;
		int16_t nicename("10") _10;
		int16_t nicename("11") _11;
		int16_t nicename("12") _12;
	};

	struct nicename("Compiled Widget Data") s_compiled_widget_data_definition
	{
		enum nicename("Special HUD Type") e_special_hud_type : uint8_t
		{
			/*nicename("Unspecial")*/ _special_hud_type_unspecial = 1ui8,
			/*nicename("Ammo")*/ _special_hud_type_ammo = 2ui8,
			/*nicename("Crosshair and Scope")*/ _special_hud_type_crosshair_and_scope = 3ui8,
			/*nicename("Unit Shield Meter")*/ _special_hud_type_unit_shield_meter = 4ui8,
			/*nicename("Grenades")*/ _special_hud_type_grenades = 5ui8,
			/*nicename("Gametype")*/ _special_hud_type_gametype = 6ui8,
			/*nicename("Motion Sensor")*/ _special_hud_type_motion_sensor = 7ui8,
			/*nicename("Unknown")*/ _special_hud_type_unknown = 8ui8,
			/*nicename("m70_bonus")*/ _special_hud_type_m70_bonus = 9ui8,
		};

		enum nicename("Input") e_input : uint16_t
		{
			/*nicename("Zero")*/ _input_zero = 1ui16,
			/*nicename("One")*/ _input_one = 2ui16,
			/*nicename("Unknown 2")*/ _input_unknown_2 = 3ui16,
			/*nicename("Unknown 3")*/ _input_unknown_3 = 4ui16,
			/*nicename("Unknown 4")*/ _input_unknown_4 = 5ui16,
			/*nicename("Time")*/ _input_time = 6ui16,
			/*nicename("Fade")*/ _input_fade = 7ui16,
			/*nicename("Unknown 7")*/ _input_unknown_7 = 8ui16,
			/*nicename("Unknown 8")*/ _input_unknown_8 = 9ui16,
			/*nicename("Unknown 9")*/ _input_unknown_9 = 10ui16,
			/*nicename("Unknown 10")*/ _input_unknown_10 = 11ui16,
			/*nicename("Unknown 11")*/ _input_unknown_11 = 12ui16,
			/*nicename("Unknown 12")*/ _input_unknown_12 = 13ui16,
			/*nicename("Unknown 13")*/ _input_unknown_13 = 14ui16,
			/*nicename("Unknown 14")*/ _input_unknown_14 = 15ui16,
			/*nicename("Unknown 15")*/ _input_unknown_15 = 16ui16,
			/*nicename("Unknown 16")*/ _input_unknown_16 = 17ui16,
			/*nicename("Unknown 17")*/ _input_unknown_17 = 18ui16,
			/*nicename("Unknown 18")*/ _input_unknown_18 = 19ui16,
			/*nicename("Unknown 19")*/ _input_unknown_19 = 20ui16,
			/*nicename("Unknown 20")*/ _input_unknown_20 = 21ui16,
			/*nicename("Saber Unknown 1")*/ _input_saber_unknown_1 = 22ui16,
			/*nicename("Vehicle Health Current Percentage")*/ _input_vehicle_health_current_percentage = 23ui16,
			/*nicename("Unit Health Current")*/ _input_unit_health_current = 24ui16,
			/*nicename("Unit Health")*/ _input_unit_health = 25ui16,
			/*nicename("Unit Shield Current")*/ _input_unit_shield_current = 26ui16,
			/*nicename("Unit 1x Overshield Current")*/ _input_unit_1x_overshield_current = 27ui16,
			/*nicename("Unit 2x Overshield Current")*/ _input_unit_2x_overshield_current = 28ui16,
			/*nicename("Unit 2x Overshield Current")*/ _input_unit_2x_overshield_current1 = 29ui16,
			/*nicename("Unit Shield")*/ _input_unit_shield = 30ui16,
			/*nicename("Unit 1x Overshield")*/ _input_unit_1x_overshield = 31ui16,
			/*nicename("Unit 2x Overshield")*/ _input_unit_2x_overshield = 32ui16,
			/*nicename("Unit 3x Overshield")*/ _input_unit_3x_overshield = 33ui16,
			/*nicename("Unit Shield Current Percentage")*/ _input_unit_shield_current_percentage = 34ui16,
			/*nicename("Vehicle Shield Current Percentage")*/ _input_vehicle_shield_current_percentage = 35ui16,
			/*nicename("Boost Energy Fraction")*/ _input_boost_energy_fraction = 36ui16,
			/*nicename("Unknown 36")*/ _input_unknown_36 = 37ui16,
			/*nicename("Aim Yaw")*/ _input_aim_yaw = 38ui16,
			/*nicename("Aim Pitch")*/ _input_aim_pitch = 39ui16,
			/*nicename("Saber Waypoint Distance")*/ _input_saber_waypoint_distance = 40ui16,
			/*nicename("Sensor Range")*/ _input_sensor_range = 41ui16,
			/*nicename("Unit Altitude 1")*/ _input_unit_altitude_1 = 42ui16,
			/*nicename("Unit Altitude 2")*/ _input_unit_altitude_2 = 43ui16,
			/*nicename("Unknown 43")*/ _input_unknown_43 = 44ui16,
			/*nicename("Softkill Timer")*/ _input_softkill_timer = 45ui16,
			/*nicename("Transient Credits")*/ _input_transient_credits = 46ui16,
			/*nicename("Unknown 46")*/ _input_unknown_46 = 47ui16,
			/*nicename("Clip Ammo Fraction")*/ _input_clip_ammo_fraction = 48ui16,
			/*nicename("Total Ammo Fraction")*/ _input_total_ammo_fraction = 49ui16,
			/*nicename("Pickup")*/ _input_pickup = 50ui16,
			/*nicename("Heat Fraction")*/ _input_heat_fraction = 51ui16,
			/*nicename("Airstrike Charge Fraction")*/ _input_airstrike_charge_fraction = 52ui16,
			/*nicename("Battery Fraction")*/ _input_battery_fraction = 53ui16,
			/*nicename("Unknown 53")*/ _input_unknown_53 = 54ui16,
			/*nicename("Unknown 54")*/ _input_unknown_54 = 55ui16,
			/*nicename("Weapon Error")*/ _input_weapon_error = 56ui16,
			/*nicename("Unknown Weapon Error")*/ _input_unknown_weapon_error = 57ui16,
			/*nicename("Unit Autoaimed")*/ _input_unit_autoaimed = 58ui16,
			/*nicename("Saber Waypoint Distance Current")*/ _input_saber_waypoint_distance_current = 59ui16,
			/*nicename("Airstrike Distance")*/ _input_airstrike_distance = 60ui16,
			/*nicename("Nav Point Airstrike")*/ _input_nav_point_airstrike = 61ui16,
			/*nicename("Airstrike Ammo")*/ _input_airstrike_ammo = 62ui16,
			/*nicename("Unknown 62")*/ _input_unknown_62 = 63ui16,
			/*nicename("Unknown 63")*/ _input_unknown_63 = 64ui16,
			/*nicename("Grenade Fraction")*/ _input_grenade_fraction = 65ui16,
			/*nicename("Unknown 65")*/ _input_unknown_65 = 66ui16,
			/*nicename("Charge Fraction")*/ _input_charge_fraction = 67ui16,
			/*nicename("Unknown 67")*/ _input_unknown_67 = 68ui16,
			/*nicename("Trigger Cooldown")*/ _input_trigger_cooldown = 69ui16,
			/*nicename("Trigger Remote Detonate Fraction")*/ _input_trigger_remote_detonate_fraction = 70ui16,
			/*nicename("Trigger Locked On")*/ _input_trigger_locked_on = 71ui16,
			/*nicename("Target Distance")*/ _input_target_distance = 72ui16,
			/*nicename("Target Elevation")*/ _input_target_elevation = 73ui16,
			/*nicename("Equipment Energy Fraction")*/ _input_equipment_energy_fraction = 74ui16,
			/*nicename("Unknown 74")*/ _input_unknown_74 = 75ui16,
			/*nicename("Unknown 75")*/ _input_unknown_75 = 76ui16,
			/*nicename("Unknown 76")*/ _input_unknown_76 = 77ui16,
			/*nicename("Unknown 77")*/ _input_unknown_77 = 78ui16,
			/*nicename("Unknown 78")*/ _input_unknown_78 = 79ui16,
			/*nicename("Unknown 79")*/ _input_unknown_79 = 80ui16,
			/*nicename("Medal Commendation")*/ _input_medal_commendation = 81ui16,
			/*nicename("Generator Health Current")*/ _input_generator_health_current = 82ui16,
			/*nicename("Generator Health")*/ _input_generator_health = 83ui16,
			/*nicename("Unknown 83")*/ _input_unknown_83 = 84ui16,
			/*nicename("Waypoint")*/ _input_waypoint = 85ui16,
			/*nicename("Unknown 85")*/ _input_unknown_85 = 86ui16,
			/*nicename("Unknown 86")*/ _input_unknown_86 = 87ui16,
			/*nicename("Waypoint Onscreen")*/ _input_waypoint_onscreen = 88ui16,
			/*nicename("Waypoint Offscreen")*/ _input_waypoint_offscreen = 89ui16,
			/*nicename("Gametype Plate")*/ _input_gametype_plate = 90ui16,
			/*nicename("Offense Defense")*/ _input_offense_defense = 91ui16,
			/*nicename("Metagame Time")*/ _input_metagame_time = 92ui16,
			/*nicename("Metagame Score Transient")*/ _input_metagame_score_transient = 93ui16,
			/*nicename("Metagame Score Player 1")*/ _input_metagame_score_player_1 = 94ui16,
			/*nicename("Unknown 94")*/ _input_unknown_94 = 95ui16,
			/*nicename("Unknown 95")*/ _input_unknown_95 = 96ui16,
			/*nicename("Unknown 96")*/ _input_unknown_96 = 97ui16,
			/*nicename("Unknown 97")*/ _input_unknown_97 = 98ui16,
			/*nicename("Unknown 98")*/ _input_unknown_98 = 99ui16,
			/*nicename("Unknown 99")*/ _input_unknown_99 = 100ui16,
			/*nicename("Survival Multiplier")*/ _input_survival_multiplier = 101ui16,
			/*nicename("Metagame Score Negative")*/ _input_metagame_score_negative = 102ui16,
			/*nicename("Survival Set")*/ _input_survival_set = 103ui16,
			/*nicename("Unknown 103")*/ _input_unknown_103 = 104ui16,
			/*nicename("Survival Waves Background")*/ _input_survival_waves_background = 105ui16,
			/*nicename("Survival Lives 1")*/ _input_survival_lives_1 = 106ui16,
			/*nicename("Survival Lives 2")*/ _input_survival_lives_2 = 107ui16,
			/*nicename("Survival Bonus Timer")*/ _input_survival_bonus_timer = 108ui16,
			/*nicename("Unknown 108")*/ _input_unknown_108 = 109ui16,
			/*nicename("Unknown 109")*/ _input_unknown_109 = 110ui16,
			/*nicename("Friendly Score")*/ _input_friendly_score = 111ui16,
			/*nicename("Enemy Score")*/ _input_enemy_score = 112ui16,
			/*nicename("Score To Win")*/ _input_score_to_win = 113ui16,
			/*nicename("Arming Fraction")*/ _input_arming_fraction = 114ui16,
			/*nicename("Posession Icon")*/ _input_posession_icon = 115ui16,
			/*nicename("Arming Unknown")*/ _input_arming_unknown = 116ui16,
			/*nicename("Omniwidget Icon")*/ _input_omniwidget_icon = 117ui16,
			/*nicename("Unknown 117")*/ _input_unknown_117 = 118ui16,
			/*nicename("Fireteam Health")*/ _input_fireteam_health = 119ui16,
			/*nicename("Unknown 119")*/ _input_unknown_119 = 120ui16,
			/*nicename("Unknown 120")*/ _input_unknown_120 = 121ui16,
			/*nicename("Unknown 121")*/ _input_unknown_121 = 122ui16,
			/*nicename("Fireteam Current Shield")*/ _input_fireteam_current_shield = 123ui16,
			/*nicename("Unknown 123")*/ _input_unknown_123 = 124ui16,
			/*nicename("Unknown 124")*/ _input_unknown_124 = 125ui16,
			/*nicename("Fireteam 1 Arming Fraction")*/ _input_fireteam_1_arming_fraction = 126ui16,
			/*nicename("Fireteam 2 Arming Fraction")*/ _input_fireteam_2_arming_fraction = 127ui16,
			/*nicename("Unknown 127")*/ _input_unknown_127 = 128ui16,
			/*nicename("Fireteam 1 Directional Arrow")*/ _input_fireteam_1_directional_arrow = 129ui16,
			/*nicename("Fireteam 2 Directional Arrow")*/ _input_fireteam_2_directional_arrow = 130ui16,
			/*nicename("Unknown 130")*/ _input_unknown_130 = 131ui16,
			/*nicename("Unknown 131")*/ _input_unknown_131 = 132ui16,
			/*nicename("Unknown 132")*/ _input_unknown_132 = 133ui16,
			/*nicename("Unknown 133")*/ _input_unknown_133 = 134ui16,
			/*nicename("Unknown 134")*/ _input_unknown_134 = 135ui16,
			/*nicename("Unknown 135")*/ _input_unknown_135 = 136ui16,
			/*nicename("Unknown 136")*/ _input_unknown_136 = 137ui16,
			/*nicename("Unknown 137")*/ _input_unknown_137 = 138ui16,
			/*nicename("Editor Budget")*/ _input_editor_budget = 139ui16,
			/*nicename("Editor Budget Cost")*/ _input_editor_budget_cost = 140ui16,
			/*nicename("Film Total Time")*/ _input_film_total_time = 141ui16,
			/*nicename("Film Current Time")*/ _input_film_current_time = 142ui16,
			/*nicename("Unknown 142")*/ _input_unknown_142 = 143ui16,
			/*nicename("Film Timeline Fraction 1")*/ _input_film_timeline_fraction_1 = 144ui16,
			/*nicename("Film Timeline Fraction 2")*/ _input_film_timeline_fraction_2 = 145ui16,
			/*nicename("Unknown 145")*/ _input_unknown_145 = 146ui16,
			/*nicename("Unknown 146")*/ _input_unknown_146 = 147ui16,
			/*nicename("NetDebug Latency")*/ _input_netdebug_latency = 148ui16,
			/*nicename("NetDebug Latency Quality")*/ _input_netdebug_latency_quality = 149ui16,
			/*nicename("NetDebug Host Quality")*/ _input_netdebug_host_quality = 150ui16,
			/*nicename("NetDebug Local Quality")*/ _input_netdebug_local_quality = 151ui16,
		};

		enum nicename("Range Input") e_range_input : uint16_t
		{
			/*nicename("Zero")*/ _range_input_zero = 1ui16,
			/*nicename("One")*/ _range_input_one = 2ui16,
			/*nicename("Unknown 2")*/ _range_input_unknown_2 = 3ui16,
			/*nicename("Unknown 3")*/ _range_input_unknown_3 = 4ui16,
			/*nicename("Unknown 4")*/ _range_input_unknown_4 = 5ui16,
			/*nicename("Time")*/ _range_input_time = 6ui16,
			/*nicename("Fade")*/ _range_input_fade = 7ui16,
			/*nicename("Unknown 7")*/ _range_input_unknown_7 = 8ui16,
			/*nicename("Unknown 8")*/ _range_input_unknown_8 = 9ui16,
			/*nicename("Unknown 9")*/ _range_input_unknown_9 = 10ui16,
			/*nicename("Unknown 10")*/ _range_input_unknown_10 = 11ui16,
			/*nicename("Unknown 11")*/ _range_input_unknown_11 = 12ui16,
			/*nicename("Unknown 12")*/ _range_input_unknown_12 = 13ui16,
			/*nicename("Unknown 13")*/ _range_input_unknown_13 = 14ui16,
			/*nicename("Unknown 14")*/ _range_input_unknown_14 = 15ui16,
			/*nicename("Unknown 15")*/ _range_input_unknown_15 = 16ui16,
			/*nicename("Unknown 16")*/ _range_input_unknown_16 = 17ui16,
			/*nicename("Unknown 17")*/ _range_input_unknown_17 = 18ui16,
			/*nicename("Unknown 18")*/ _range_input_unknown_18 = 19ui16,
			/*nicename("Unknown 19")*/ _range_input_unknown_19 = 20ui16,
			/*nicename("Unknown 20")*/ _range_input_unknown_20 = 21ui16,
			/*nicename("Saber Unknown 1")*/ _range_input_saber_unknown_1 = 22ui16,
			/*nicename("Vehicle Health Current Percentage")*/ _range_input_vehicle_health_current_percentage = 23ui16,
			/*nicename("Unit Health Current")*/ _range_input_unit_health_current = 24ui16,
			/*nicename("Unit Health")*/ _range_input_unit_health = 25ui16,
			/*nicename("Unit Shield Current")*/ _range_input_unit_shield_current = 26ui16,
			/*nicename("Unit 1x Overshield Current")*/ _range_input_unit_1x_overshield_current = 27ui16,
			/*nicename("Unit 2x Overshield Current")*/ _range_input_unit_2x_overshield_current = 28ui16,
			/*nicename("Unit 2x Overshield Current")*/ _range_input_unit_2x_overshield_current1 = 29ui16,
			/*nicename("Unit Shield")*/ _range_input_unit_shield = 30ui16,
			/*nicename("Unit 1x Overshield")*/ _range_input_unit_1x_overshield = 31ui16,
			/*nicename("Unit 2x Overshield")*/ _range_input_unit_2x_overshield = 32ui16,
			/*nicename("Unit 3x Overshield")*/ _range_input_unit_3x_overshield = 33ui16,
			/*nicename("Unit Shield Current Percentage")*/ _range_input_unit_shield_current_percentage = 34ui16,
			/*nicename("Vehicle Shield Current Percentage")*/ _range_input_vehicle_shield_current_percentage = 35ui16,
			/*nicename("Boost Energy Fraction")*/ _range_input_boost_energy_fraction = 36ui16,
			/*nicename("Unknown 36")*/ _range_input_unknown_36 = 37ui16,
			/*nicename("Aim Yaw")*/ _range_input_aim_yaw = 38ui16,
			/*nicename("Aim Pitch")*/ _range_input_aim_pitch = 39ui16,
			/*nicename("Saber Waypoint Distance")*/ _range_input_saber_waypoint_distance = 40ui16,
			/*nicename("Sensor Range")*/ _range_input_sensor_range = 41ui16,
			/*nicename("Unit Altitude 1")*/ _range_input_unit_altitude_1 = 42ui16,
			/*nicename("Unit Altitude 2")*/ _range_input_unit_altitude_2 = 43ui16,
			/*nicename("Unknown 43")*/ _range_input_unknown_43 = 44ui16,
			/*nicename("Softkill Timer")*/ _range_input_softkill_timer = 45ui16,
			/*nicename("Transient Credits")*/ _range_input_transient_credits = 46ui16,
			/*nicename("Unknown 46")*/ _range_input_unknown_46 = 47ui16,
			/*nicename("Clip Ammo Fraction")*/ _range_input_clip_ammo_fraction = 48ui16,
			/*nicename("Total Ammo Fraction")*/ _range_input_total_ammo_fraction = 49ui16,
			/*nicename("Pickup")*/ _range_input_pickup = 50ui16,
			/*nicename("Heat Fraction")*/ _range_input_heat_fraction = 51ui16,
			/*nicename("Airstrike Charge Fraction")*/ _range_input_airstrike_charge_fraction = 52ui16,
			/*nicename("Battery Fraction")*/ _range_input_battery_fraction = 53ui16,
			/*nicename("Unknown 53")*/ _range_input_unknown_53 = 54ui16,
			/*nicename("Unknown 54")*/ _range_input_unknown_54 = 55ui16,
			/*nicename("Weapon Error")*/ _range_input_weapon_error = 56ui16,
			/*nicename("Unknown Weapon Error")*/ _range_input_unknown_weapon_error = 57ui16,
			/*nicename("Unit Autoaimed")*/ _range_input_unit_autoaimed = 58ui16,
			/*nicename("Saber Waypoint Distance Current")*/ _range_input_saber_waypoint_distance_current = 59ui16,
			/*nicename("Airstrike Distance")*/ _range_input_airstrike_distance = 60ui16,
			/*nicename("Nav Point Airstrike")*/ _range_input_nav_point_airstrike = 61ui16,
			/*nicename("Airstrike Ammo")*/ _range_input_airstrike_ammo = 62ui16,
			/*nicename("Unknown 62")*/ _range_input_unknown_62 = 63ui16,
			/*nicename("Unknown 63")*/ _range_input_unknown_63 = 64ui16,
			/*nicename("Grenade Fraction")*/ _range_input_grenade_fraction = 65ui16,
			/*nicename("Unknown 65")*/ _range_input_unknown_65 = 66ui16,
			/*nicename("Charge Fraction")*/ _range_input_charge_fraction = 67ui16,
			/*nicename("Unknown 67")*/ _range_input_unknown_67 = 68ui16,
			/*nicename("Trigger Cooldown")*/ _range_input_trigger_cooldown = 69ui16,
			/*nicename("Trigger Remote Detonate Fraction")*/ _range_input_trigger_remote_detonate_fraction = 70ui16,
			/*nicename("Trigger Locked On")*/ _range_input_trigger_locked_on = 71ui16,
			/*nicename("Target Distance")*/ _range_input_target_distance = 72ui16,
			/*nicename("Target Elevation")*/ _range_input_target_elevation = 73ui16,
			/*nicename("Equipment Energy Fraction")*/ _range_input_equipment_energy_fraction = 74ui16,
			/*nicename("Unknown 74")*/ _range_input_unknown_74 = 75ui16,
			/*nicename("Unknown 75")*/ _range_input_unknown_75 = 76ui16,
			/*nicename("Unknown 76")*/ _range_input_unknown_76 = 77ui16,
			/*nicename("Unknown 77")*/ _range_input_unknown_77 = 78ui16,
			/*nicename("Unknown 78")*/ _range_input_unknown_78 = 79ui16,
			/*nicename("Unknown 79")*/ _range_input_unknown_79 = 80ui16,
			/*nicename("Medal Commendation")*/ _range_input_medal_commendation = 81ui16,
			/*nicename("Generator Health Current")*/ _range_input_generator_health_current = 82ui16,
			/*nicename("Generator Health")*/ _range_input_generator_health = 83ui16,
			/*nicename("Unknown 83")*/ _range_input_unknown_83 = 84ui16,
			/*nicename("Waypoint")*/ _range_input_waypoint = 85ui16,
			/*nicename("Unknown 85")*/ _range_input_unknown_85 = 86ui16,
			/*nicename("Unknown 86")*/ _range_input_unknown_86 = 87ui16,
			/*nicename("Waypoint Onscreen")*/ _range_input_waypoint_onscreen = 88ui16,
			/*nicename("Waypoint Offscreen")*/ _range_input_waypoint_offscreen = 89ui16,
			/*nicename("Gametype Plate")*/ _range_input_gametype_plate = 90ui16,
			/*nicename("Offense Defense")*/ _range_input_offense_defense = 91ui16,
			/*nicename("Metagame Time")*/ _range_input_metagame_time = 92ui16,
			/*nicename("Metagame Score Transient")*/ _range_input_metagame_score_transient = 93ui16,
			/*nicename("Metagame Score Player 1")*/ _range_input_metagame_score_player_1 = 94ui16,
			/*nicename("Unknown 94")*/ _range_input_unknown_94 = 95ui16,
			/*nicename("Unknown 95")*/ _range_input_unknown_95 = 96ui16,
			/*nicename("Unknown 96")*/ _range_input_unknown_96 = 97ui16,
			/*nicename("Unknown 97")*/ _range_input_unknown_97 = 98ui16,
			/*nicename("Unknown 98")*/ _range_input_unknown_98 = 99ui16,
			/*nicename("Unknown 99")*/ _range_input_unknown_99 = 100ui16,
			/*nicename("Survival Multiplier")*/ _range_input_survival_multiplier = 101ui16,
			/*nicename("Metagame Score Negative")*/ _range_input_metagame_score_negative = 102ui16,
			/*nicename("Survival Set")*/ _range_input_survival_set = 103ui16,
			/*nicename("Unknown 103")*/ _range_input_unknown_103 = 104ui16,
			/*nicename("Survival Waves Background")*/ _range_input_survival_waves_background = 105ui16,
			/*nicename("Survival Lives 1")*/ _range_input_survival_lives_1 = 106ui16,
			/*nicename("Survival Lives 2")*/ _range_input_survival_lives_2 = 107ui16,
			/*nicename("Survival Bonus Timer")*/ _range_input_survival_bonus_timer = 108ui16,
			/*nicename("Unknown 108")*/ _range_input_unknown_108 = 109ui16,
			/*nicename("Unknown 109")*/ _range_input_unknown_109 = 110ui16,
			/*nicename("Friendly Score")*/ _range_input_friendly_score = 111ui16,
			/*nicename("Enemy Score")*/ _range_input_enemy_score = 112ui16,
			/*nicename("Score To Win")*/ _range_input_score_to_win = 113ui16,
			/*nicename("Arming Fraction")*/ _range_input_arming_fraction = 114ui16,
			/*nicename("Posession Icon")*/ _range_input_posession_icon = 115ui16,
			/*nicename("Arming Unknown")*/ _range_input_arming_unknown = 116ui16,
			/*nicename("Omniwidget Icon")*/ _range_input_omniwidget_icon = 117ui16,
			/*nicename("Unknown 117")*/ _range_input_unknown_117 = 118ui16,
			/*nicename("Fireteam Health")*/ _range_input_fireteam_health = 119ui16,
			/*nicename("Unknown 119")*/ _range_input_unknown_119 = 120ui16,
			/*nicename("Unknown 120")*/ _range_input_unknown_120 = 121ui16,
			/*nicename("Unknown 121")*/ _range_input_unknown_121 = 122ui16,
			/*nicename("Fireteam Current Shield")*/ _range_input_fireteam_current_shield = 123ui16,
			/*nicename("Unknown 123")*/ _range_input_unknown_123 = 124ui16,
			/*nicename("Unknown 124")*/ _range_input_unknown_124 = 125ui16,
			/*nicename("Fireteam 1 Arming Fraction")*/ _range_input_fireteam_1_arming_fraction = 126ui16,
			/*nicename("Fireteam 2 Arming Fraction")*/ _range_input_fireteam_2_arming_fraction = 127ui16,
			/*nicename("Unknown 127")*/ _range_input_unknown_127 = 128ui16,
			/*nicename("Fireteam 1 Directional Arrow")*/ _range_input_fireteam_1_directional_arrow = 129ui16,
			/*nicename("Fireteam 2 Directional Arrow")*/ _range_input_fireteam_2_directional_arrow = 130ui16,
			/*nicename("Unknown 130")*/ _range_input_unknown_130 = 131ui16,
			/*nicename("Unknown 131")*/ _range_input_unknown_131 = 132ui16,
			/*nicename("Unknown 132")*/ _range_input_unknown_132 = 133ui16,
			/*nicename("Unknown 133")*/ _range_input_unknown_133 = 134ui16,
			/*nicename("Unknown 134")*/ _range_input_unknown_134 = 135ui16,
			/*nicename("Unknown 135")*/ _range_input_unknown_135 = 136ui16,
			/*nicename("Unknown 136")*/ _range_input_unknown_136 = 137ui16,
			/*nicename("Unknown 137")*/ _range_input_unknown_137 = 138ui16,
			/*nicename("Editor Budget")*/ _range_input_editor_budget = 139ui16,
			/*nicename("Editor Budget Cost")*/ _range_input_editor_budget_cost = 140ui16,
			/*nicename("Film Total Time")*/ _range_input_film_total_time = 141ui16,
			/*nicename("Film Current Time")*/ _range_input_film_current_time = 142ui16,
			/*nicename("Unknown 142")*/ _range_input_unknown_142 = 143ui16,
			/*nicename("Film Timeline Fraction 1")*/ _range_input_film_timeline_fraction_1 = 144ui16,
			/*nicename("Film Timeline Fraction 2")*/ _range_input_film_timeline_fraction_2 = 145ui16,
			/*nicename("Unknown 145")*/ _range_input_unknown_145 = 146ui16,
			/*nicename("Unknown 146")*/ _range_input_unknown_146 = 147ui16,
			/*nicename("NetDebug Latency")*/ _range_input_netdebug_latency = 148ui16,
			/*nicename("NetDebug Latency Quality")*/ _range_input_netdebug_latency_quality = 149ui16,
			/*nicename("NetDebug Host Quality")*/ _range_input_netdebug_host_quality = 150ui16,
			/*nicename("NetDebug Local Quality")*/ _range_input_netdebug_local_quality = 151ui16,
		};

		enum nicename("Second State-Block Start Value") e_second_state_block_start_value : uint8_t
		{
			/*nicename("Value 0")*/ _second_state_block_start_value_value_0 = 1ui8,
			/*nicename("Value 1")*/ _second_state_block_start_value_value_1 = 2ui8,
			/*nicename("Value 2")*/ _second_state_block_start_value_value_2 = 3ui8,
			/*nicename("Value 3")*/ _second_state_block_start_value_value_3 = 4ui8,
			/*nicename("Value 4")*/ _second_state_block_start_value_value_4 = 5ui8,
			/*nicename("Value 5")*/ _second_state_block_start_value_value_5 = 6ui8,
			/*nicename("Value 6")*/ _second_state_block_start_value_value_6 = 7ui8,
			/*nicename("Value 7")*/ _second_state_block_start_value_value_7 = 8ui8,
			/*nicename("Value 8")*/ _second_state_block_start_value_value_8 = 9ui8,
			/*nicename("Value 9")*/ _second_state_block_start_value_value_9 = 10ui8,
			/*nicename("Value 10")*/ _second_state_block_start_value_value_10 = 11ui8,
			/*nicename("Value 11")*/ _second_state_block_start_value_value_11 = 12ui8,
			/*nicename("Value 12")*/ _second_state_block_start_value_value_12 = 13ui8,
			/*nicename("Value 13")*/ _second_state_block_start_value_value_13 = 14ui8,
			/*nicename("Value 14")*/ _second_state_block_start_value_value_14 = 15ui8,
			/*nicename("Value 15")*/ _second_state_block_start_value_value_15 = 16ui8,
			/*nicename("Value 16")*/ _second_state_block_start_value_value_16 = 17ui8,
			/*nicename("Value 17")*/ _second_state_block_start_value_value_17 = 18ui8,
			/*nicename("Value 18")*/ _second_state_block_start_value_value_18 = 19ui8,
			/*nicename("Value 19")*/ _second_state_block_start_value_value_19 = 20ui8,
			/*nicename("Value 20")*/ _second_state_block_start_value_value_20 = 21ui8,
			/*nicename("Value 21")*/ _second_state_block_start_value_value_21 = 22ui8,
			/*nicename("Value 22")*/ _second_state_block_start_value_value_22 = 23ui8,
			/*nicename("Value 23")*/ _second_state_block_start_value_value_23 = 24ui8,
			/*nicename("Value 24")*/ _second_state_block_start_value_value_24 = 25ui8,
			/*nicename("Value 25")*/ _second_state_block_start_value_value_25 = 26ui8,
			/*nicename("Value 26")*/ _second_state_block_start_value_value_26 = 27ui8,
			/*nicename("Value 27")*/ _second_state_block_start_value_value_27 = 28ui8,
			/*nicename("Value 28")*/ _second_state_block_start_value_value_28 = 29ui8,
		};

		enum nicename("Third State-Block Start Value") e_third_state_block_start_value : uint8_t
		{
			/*nicename("Value 0")*/ _third_state_block_start_value_value_0 = 1ui8,
			/*nicename("Value 1")*/ _third_state_block_start_value_value_1 = 2ui8,
			/*nicename("Value 2")*/ _third_state_block_start_value_value_2 = 3ui8,
			/*nicename("Value 3")*/ _third_state_block_start_value_value_3 = 4ui8,
			/*nicename("Value 4")*/ _third_state_block_start_value_value_4 = 5ui8,
			/*nicename("Value 5")*/ _third_state_block_start_value_value_5 = 6ui8,
			/*nicename("Value 6")*/ _third_state_block_start_value_value_6 = 7ui8,
			/*nicename("Value 7")*/ _third_state_block_start_value_value_7 = 8ui8,
			/*nicename("Value 8")*/ _third_state_block_start_value_value_8 = 9ui8,
			/*nicename("Value 9")*/ _third_state_block_start_value_value_9 = 10ui8,
			/*nicename("Value 10")*/ _third_state_block_start_value_value_10 = 11ui8,
			/*nicename("Value 11")*/ _third_state_block_start_value_value_11 = 12ui8,
			/*nicename("Value 12")*/ _third_state_block_start_value_value_12 = 13ui8,
			/*nicename("Value 13")*/ _third_state_block_start_value_value_13 = 14ui8,
			/*nicename("Value 14")*/ _third_state_block_start_value_value_14 = 15ui8,
			/*nicename("Value 15")*/ _third_state_block_start_value_value_15 = 16ui8,
			/*nicename("Value 16")*/ _third_state_block_start_value_value_16 = 17ui8,
			/*nicename("Value 17")*/ _third_state_block_start_value_value_17 = 18ui8,
			/*nicename("Value 18")*/ _third_state_block_start_value_value_18 = 19ui8,
			/*nicename("Value 19")*/ _third_state_block_start_value_value_19 = 20ui8,
			/*nicename("Value 20")*/ _third_state_block_start_value_value_20 = 21ui8,
			/*nicename("Value 21")*/ _third_state_block_start_value_value_21 = 22ui8,
			/*nicename("Value 22")*/ _third_state_block_start_value_value_22 = 23ui8,
			/*nicename("Value 23")*/ _third_state_block_start_value_value_23 = 24ui8,
			/*nicename("Value 24")*/ _third_state_block_start_value_value_24 = 25ui8,
			/*nicename("Value 25")*/ _third_state_block_start_value_value_25 = 26ui8,
			/*nicename("Value 26")*/ _third_state_block_start_value_value_26 = 27ui8,
			/*nicename("Value 27")*/ _third_state_block_start_value_value_27 = 28ui8,
			/*nicename("Value 28")*/ _third_state_block_start_value_value_28 = 29ui8,
		};

		enum nicename("Input Variable Triggers") b_input_variable_triggers : uint32_t /* bitfield */
		{
			/*nicename("Value 0")*/ _input_variable_triggers_value_0 = 1ui32 << 0ui32,
			/*nicename("Value 1")*/ _input_variable_triggers_value_1 = 1ui32 << 1ui32,
			/*nicename("Value 2")*/ _input_variable_triggers_value_2 = 1ui32 << 2ui32,
			/*nicename("Value 3")*/ _input_variable_triggers_value_3 = 1ui32 << 3ui32,
			/*nicename("Value 4")*/ _input_variable_triggers_value_4 = 1ui32 << 4ui32,
			/*nicename("Value 5")*/ _input_variable_triggers_value_5 = 1ui32 << 5ui32,
			/*nicename("Value 6")*/ _input_variable_triggers_value_6 = 1ui32 << 6ui32,
			/*nicename("Value 7")*/ _input_variable_triggers_value_7 = 1ui32 << 7ui32,
			/*nicename("Value 8")*/ _input_variable_triggers_value_8 = 1ui32 << 8ui32,
			/*nicename("Value 9")*/ _input_variable_triggers_value_9 = 1ui32 << 9ui32,
			/*nicename("Value 10")*/ _input_variable_triggers_value_10 = 1ui32 << 10ui32,
			/*nicename("Value 11")*/ _input_variable_triggers_value_11 = 1ui32 << 11ui32,
			/*nicename("Value 12")*/ _input_variable_triggers_value_12 = 1ui32 << 12ui32,
			/*nicename("Value 13")*/ _input_variable_triggers_value_13 = 1ui32 << 13ui32,
			/*nicename("Value 14")*/ _input_variable_triggers_value_14 = 1ui32 << 14ui32,
			/*nicename("Value 15")*/ _input_variable_triggers_value_15 = 1ui32 << 15ui32,
			/*nicename("Value 16")*/ _input_variable_triggers_value_16 = 1ui32 << 16ui32,
			/*nicename("Value 17")*/ _input_variable_triggers_value_17 = 1ui32 << 17ui32,
			/*nicename("Value 18")*/ _input_variable_triggers_value_18 = 1ui32 << 18ui32,
			/*nicename("Value 19")*/ _input_variable_triggers_value_19 = 1ui32 << 19ui32,
			/*nicename("Value 20")*/ _input_variable_triggers_value_20 = 1ui32 << 20ui32,
			/*nicename("Value 21")*/ _input_variable_triggers_value_21 = 1ui32 << 21ui32,
			/*nicename("Value 22")*/ _input_variable_triggers_value_22 = 1ui32 << 22ui32,
			/*nicename("Value 23")*/ _input_variable_triggers_value_23 = 1ui32 << 23ui32,
			/*nicename("Value 24")*/ _input_variable_triggers_value_24 = 1ui32 << 24ui32,
			/*nicename("Value 25")*/ _input_variable_triggers_value_25 = 1ui32 << 25ui32,
			/*nicename("Value 26")*/ _input_variable_triggers_value_26 = 1ui32 << 26ui32,
			/*nicename("Value 27")*/ _input_variable_triggers_value_27 = 1ui32 << 27ui32,
			/*nicename("Value 28")*/ _input_variable_triggers_value_28 = 1ui32 << 28ui32,
		};

		e_special_hud_type nicename("Special HUD Type") special_hud_type;
		uint8_t __unknown0;
		uint8_t __unknown1;
		uint8_t __unknown2;
		float nicename("Animation 1 Frame Count") animation_1_frame_count;
		float nicename("Animation 2 Frame Count") animation_2_frame_count;
		float nicename("Animation 3 Frame Count") animation_3_frame_count;
		float nicename("Animation 4 Frame Count") animation_4_frame_count;
		float nicename("Animation 5 Frame Count") animation_5_frame_count;
		e_input nicename("Input") input;
		e_range_input nicename("Range Input") range_input;
		// Input Variable Triggers : Since the states values are dynamic, these bits are used to determine where the triggers that have the "Input Variable" flag checked are.
		b_input_variable_triggers nicename("Input Variable Triggers") input_variable_triggers1;
		// Block Starting Value :  Since the states values are dynamic, this enum is used to determine where the next "X States" data starts, even if the block was empty.
		e_second_state_block_start_value nicename("Second State-Block Start Value") second_state_block_start_value;
		e_third_state_block_start_value nicename("Third State-Block Start Value") third_state_block_start_value;
		/* Compiled States (Bitmap/Text Widgets) : Uses this format:
		   
		   -States (Yes, Unknown, No) Count
		   Then for every States count:
		   -Triggers Count
		   Then for every Triggers count:
		   -Trigger Index
		   
		   Repeats for all 3 States blocks. Use a 0 if the block is null.
		   It is currently unknown what the criteria is for more than one "X States" index.
		   Check existing tags for examples, good luck. */
		int16_t nicename("0") _0;
		int16_t nicename("1") _1;
		int16_t nicename("2") _2;
		int16_t nicename("3") _3;
		int16_t nicename("4") _4;
		int16_t nicename("5") _5;
		int16_t nicename("6") _6;
		int16_t nicename("7") _7;
		int16_t nicename("8") _8;
		int16_t nicename("9") _9;
		int16_t nicename("10") _10;
		int16_t nicename("11") _11;
		int16_t nicename("12") _12;
		int16_t nicename("13") _13;
		int16_t nicename("14") _14;
		int16_t nicename("15") _15;
		int16_t nicename("16") _16;
		int16_t nicename("17") _17;
		int16_t nicename("18") _18;
		int16_t nicename("19") _19;
		int16_t nicename("20") _20;
		int16_t nicename("21") _21;
		int16_t nicename("22") _22;
		int16_t nicename("23") _23;
		int16_t nicename("24") _24;
		int16_t nicename("25") _25;
		int16_t nicename("26") _26;
		int16_t nicename("27") _27;
		int16_t nicename("28") _28;
	};

	/* Reach HUDs Are Annoying : The inputs are not defined where they were for Halo 3, but instead are in the "Compiled Widget Data" block at the bottom, along with the 3 blocks within "State Data".
	   
	   ...Unless the State Data block is part of HUD Widgets not Bitmap/Text Widgets, which THOSE states are defined at the bottom of the HUD Widgets block.
	   
	   There is no outright index for Compiled Widget Data so use the Import Inputs/States and counting (Bitmap and Text Widgets only!) to find it.
	   
	   Mapping the Trigger indexes will take time. There is a block at the bottom of CHGD with an unsorted list of triggers with a vague category, which has been sorted into a comment about the block.
	   
	   As for Placement Data, each index likely refers to each "HUD Attributes" index in CHGD to change depending on resolution. */
	// Render Data Shader Index : While represented as an enum, it is actually an index to the "HUD Shaders" block in CHGD
	s_tag_block_definition<s_hud_widgets_definition> nicename("HUD Widgets") hud_widgets_block;
	int32_t nicename("Low Clip Cutoff") low_clip_cutoff;
	int32_t nicename("Low Ammo Cutoff") low_ammo_cutoff;
	int32_t nicename("Age Cutoff") age_cutoff;
	int32_t nicename("Sword Age Cutoff") sword_age_cutoff;
	s_tag_block_definition<s_compiled_widget_data_definition> nicename("Compiled Widget Data") compiled_widget_data_block;
};

