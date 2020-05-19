#pragma once

enum class eHaloArmor : long
{
	HR_Helmet_MarkVB_Base,
	HR_Helmet_MarkVB_UA,
	HR_Helmet_MarkVB_UAHUL,
	HR_Helmet_CQC_Base,
	HR_Helmet_CQC_CBRN,
	HR_Helmet_CQC_UAHUL,
	HR_Helmet_ODST_Base,
	HR_Helmet_ODST_UACNM,
	HR_Helmet_ODST_CBRNHUL,
	HR_Helmet_HAZOP_Base,
	HR_Helmet_HAZOP_CBRNHUL,
	HR_Helmet_HAZOP_CNMI,
	HR_Helmet_EOD_Base,
	HR_Helmet_EOD_CNM,
	HR_Helmet_EOD_UAHUL,
	HR_Helmet_Operator_Base,
	HR_Helmet_Operator_UAHUL,
	HR_Helmet_Operator_CNM,
	HR_Helmet_Grenadier_Base,
	HR_Helmet_Grenadier_UA,
	HR_Helmet_Grenadier_UAFC,
	HR_Helmet_AirAssault_Base,
	HR_Helmet_AirAssault_UACNM,
	HR_Helmet_AirAssault_FCI,
	HR_Helmet_Scout_Base,
	HR_Helmet_Scout_HURS,
	HR_Helmet_Scout_CBRNCNM,
	HR_Helmet_EVA_Base,
	HR_Helmet_EVA_CNM,
	HR_Helmet_EVA_UAHUL3,
	HR_Helmet_JFO_Base,
	HR_Helmet_JFO_HULI,
	HR_Helmet_JFO_UA,
	HR_Helmet_Commando_Base,
	HR_Helmet_Commando_CBRNCNM,
	HR_Helmet_Commando_UAFCI2,
	HR_Helmet_EVAC_Base,
	HR_Helmet_EVAC_CNM,
	HR_Helmet_EVAC_UAHUL3,
	HR_Helmet_MjolnirMKV_Base,
	HR_Helmet_MjolnirMKV_CNM,
	HR_Helmet_MjolnirMKV_UA,
	HR_Helmet_Pilot_Base,
	HR_Helmet_Pilot_HUL3,
	HR_Helmet_Pilot_UAHUL3,
	HR_Helmet_Pilot_Haunted,
	HR_Helmet_Recon_Base,
	HR_Helmet_Recon_HUL,
	HR_Helmet_Recon_UAHUL3,
	HR_Helmet_MjolnirMKVI_Base,
	HR_Helmet_MjolnirMKVI_FCI2,
	HR_Helmet_MjolnirMKVI_UAHULI,
	HR_Helmet_Gungnir_Base,
	HR_Helmet_Gungnir_HURS,
	HR_Helmet_Gungnir_CBRN,
	HR_Helmet_Security_Base,
	HR_Helmet_Security_UAHUL,
	HR_Helmet_Security_CBRNCNM,
	HR_Helmet_MilitaryPolice_Base,
	HR_Helmet_MilitaryPolice_CBRNHURS,
	HR_Helmet_MilitaryPolice_HURSCNM,
	HR_Helmet_CQB_Base,
	HR_Helmet_CQB_HURSCNM,
	HR_Helmet_CQB_UAHUL,

	HR_LeftShoulder_Default,
	HR_LeftShoulder_FJPARA,
	HR_LeftShoulder_HAZOP,
	HR_LeftShoulder_JFO,
	HR_LeftShoulder_Recon,
	HR_LeftShoulder_UAMultiThreat,
	HR_LeftShoulder_Jumpjet,
	HR_LeftShoulder_EVA,
	HR_LeftShoulder_Gungnir,
	HR_LeftShoulder_ODST,
	HR_LeftShoulder_UABaseSecurity,
	HR_LeftShoulder_CQC,
	HR_LeftShoulder_Operator,
	HR_LeftShoulder_Commando,
	HR_LeftShoulder_Grenadier,
	HR_LeftShoulder_Sniper,
	HR_LeftShoulder_MjolnirMarkV,
	HR_LeftShoulder_Security,

	HR_RightShoulder_Default,
	HR_RightShoulder_FJPARA,
	HR_RightShoulder_HAZOP,
	HR_RightShoulder_JFO,
	HR_RightShoulder_Recon,
	HR_RightShoulder_UAMultiThreat,
	HR_RightShoulder_Jumpjet,
	HR_RightShoulder_EVA,
	HR_RightShoulder_Gungnir,
	HR_RightShoulder_ODST,
	HR_RightShoulder_UABaseSecurity,
	HR_RightShoulder_CQC,
	HR_RightShoulder_Operator,
	HR_RightShoulder_Commando,
	HR_RightShoulder_Grenadier,
	HR_RightShoulder_Sniper,
	HR_RightShoulder_MjolnirMarkV,
	HR_RightShoulder_Security,

	HR_Chest_Default,
	HR_Chest_HPHalo,
	HR_Chest_UACounterAssault,
	HR_Chest_TacticalLRP,
	HR_Chest_UAODST,
	HR_Chest_TacticalRecon,
	HR_Chest_CollarGrenadier,
	HR_Chest_TacticalPatrol,
	HR_Chest_CollarBreacher,
	HR_Chest_AssaultSapper,
	HR_Chest_AssaultCommando,
	HR_Chest_HPParaFoil,
	HR_Chest_CollarGrenadierUA,
	HR_Chest_UABaseSecurityW,
	HR_Chest_CollarBreacherR,
	HR_Chest_HPParaFoilR,
	HR_Chest_AssaultSapperR,

	HR_Wrist_Default,
	HR_Wrist_UABuckler,
	HR_Wrist_UABracer,
	HR_Wrist_TacticalTACPAD,
	HR_Wrist_TacticalUGPS,
	HR_Wrist_AssaultBreacher,

	HR_Utility_Default,
	HR_Utility_UACHOBHAM,
	HR_Utility_TacticalHardcase,
	HR_Utility_UANXRA,
	HR_Utility_TacticalTraumaKit,
	HR_Utility_TacticalSoftcase,

	HR_VisorColor_Default,
	HR_VisorColor_Silver,
	HR_VisorColor_Blue,
	HR_VisorColor_Black,
	HR_VisorColor_Gold,

	HR_KneeGuards_Default,
	HR_KneeGuards_FJPARA,
	HR_KneeGuards_Gungnir,
	HR_KneeGuards_Grenadier,

	HR_ArmorEffect_Default,
	HR_ArmorEffect_BirthdayParty,
	HR_ArmorEffect_HeartAttack,
	HR_ArmorEffect_Pestilence,
	HR_ArmorEffect_InclementWeather,
	HR_ArmorEffect_Flames,
	HR_ArmorEffect_BlueFlames,

	HR_FirefightVoice_NobleSix,
	HR_FirefightVoice_JorgeS052,
	HR_FirefightVoice_JunS266,
	HR_FirefightVoice_EmileS239,
	HR_FirefightVoice_KatS320,
	HR_FirefightVoice_AuntieDotAI,
	HR_FirefightVoice_CarterS259,
	HR_FirefightVoice_GYSGTStacker,
	HR_FirefightVoice_GYSGTBuck,
	HR_FirefightVoice_SGTMAJJohnson,
	HR_FirefightVoice_CortanaAI,
	HR_FirefightVoice_JohnS117,

	HR_Spartan_Male,
	HR_Spartan_Female,

	HR_Elite_Minor,
	HR_Elite_SpecOps,
	HR_Elite_Ranger,
	HR_Elite_Ultra,
	HR_Elite_Zealot,
	HR_Elite_General,
	HR_Elite_FieldMarshall,
	HR_Elite_Officer,

	HR_Color_Steel,
	HR_Color_Silver,
	HR_Color_White,
	HR_Color_Brown,
	HR_Color_Tan,
	HR_Color_Khaki,
	HR_Color_Sage,
	HR_Color_Olive,
	HR_Color_Drab,
	HR_Color_Forest,
	HR_Color_Green,
	HR_Color_SeaFoam,
	HR_Color_Teal,
	HR_Color_Aqua,
	HR_Color_Cyan,
	HR_Color_Blue,
	HR_Color_Cobalt,
	HR_Color_Ice,
	HR_Color_Violet,
	HR_Color_Orchid,
	HR_Color_Lavender,
	HR_Color_Maroon,
	HR_Color_Brick,
	HR_Color_Rose,
	HR_Color_Rust,
	HR_Color_Coral,
	HR_Color_Peach,
	HR_Color_Gold,
	HR_Color_Yellow,
	HR_Color_Pale,

	HR_Chest_UABaseSecurity,
	HR_Chest_UAMultiThreat,
	HR_Chest_UAMultiThreatW,

	HR_Species_Spartan,
	HR_Species_Elite,

	H1_Color_1,
	H1_Color_2,
	H1_Color_3,
	H1_Color_4,
	H1_Color_5,
	H1_Color_6,
	H1_Color_7,
	H1_Color_8,
	H1_Color_9,
	H1_Color_10,
	H1_Color_11,
	H1_Color_12,
	H1_Color_13,
	H1_Color_14,
	H1_Color_15,
	H1_Color_16,
	H1_Color_17,
	H1_Color_18,

	H2_Color_1,
	H2_Color_2,
	H2_Color_3,
	H2_Color_4,
	H2_Color_5,
	H2_Color_6,
	H2_Color_7,
	H2_Color_8,
	H2_Color_9,
	H2_Color_10,
	H2_Color_11,
	H2_Color_12,
	H2_Color_13,
	H2_Color_14,
	H2_Color_15,
	H2_Color_16,
	H2_Color_17,
	H2_Color_18,

	H2A_Color_1,
	H2A_Color_2,
	H2A_Color_3,
	H2A_Color_4,
	H2A_Color_5,
	H2A_Color_6,
	H2A_Color_7,
	H2A_Color_8,
	H2A_Color_9,
	H2A_Color_10,
	H2A_Color_11,
	H2A_Color_12,
	H2A_Color_13,
	H2A_Color_14,
	H2A_Color_15,
	H2A_Color_16,
	H2A_Color_17,
	H2A_Color_18,
	H2A_Color_19,
	H2A_Color_22,
	H2A_Color_23,
	H2A_Color_24,
	H2A_Color_25,
	H2A_Color_26,
	H2A_Color_27,
	H2A_Color_28,
	H2A_Color_29,

	H2A_ARMOR_ELITE1,
	H2A_ARMOR_ELITE2,
	H2A_ARMOR_ELITE3,

	H2A_ARMOR0_MARKVI,
	H2A_ARMOR1_CENTURION,
	H2A_ARMOR_SPARTAN3,

	H3_ARMOR0_MARK_VI,
	H3_ARMOR1_CQB,
	H3_ARMOR2_EVA,
	H3_ARMOR3_RECON,
	H3_ARMOR4_HAYABUSA,
	H3_ARMOR5_EOD,
	H3_ARMOR6_SCOUT,
	H3_ARMOR7_ODST_CQB,
	H3_ARMOR9_MARK_V,
	H3_ARMOR10_ROGUE,
	H3_ARMOR11_FLAMING_HEAD,
	H3_ARMOR12_SECURITY,
	H3_ARMOR13_KATANA,
	H3_ARMOR14_COMBAT,
	H3_ARMOR15_ASSAULT,
	H3_ARMOR16_FLIGHT,
	H3_ARMOR17_ASCETIC,
	H3_ARMOR18_COMMANDO,

	H3_Color_1,
	H3_Color_2,
	H3_Color_3,
	H3_Color_4,
	H3_Color_5,
	H3_Color_6,
	H3_Color_7,
	H3_Color_8,
	H3_Color_9,
	H3_Color_10,
	H3_Color_11,
	H3_Color_12,
	H3_Color_13,
	H3_Color_14,
	H3_Color_15,
	H3_Color_16,
	H3_Color_17,
	H3_Color_18,
	H3_Color_19,
	H3_Color_20,
	H3_Color_21,
	H3_Color_22,
	H3_Color_23,
	H3_Color_24,
	H3_Color_25,
	H3_Color_26,
	H3_Color_27,
	H3_Color_28,
	H3_Color_29,

	kHaloArmorCount,
	kHaloArmorNone = -1
};

struct s_loadout_slot
{
	long tactical_package_index;
	long support_upgrade_index;
	long primary_weapon_index;
	long secondary_weapon_index;
	long primary_weapon_variant_index;
	long secondary_weapon_variant_index;
	long equipment_index;
	long grenade_index;
	wchar_t name[13];
};

struct s_game_keyboard_mouse_mapping
{
	int abstract_button;
	int virtual_key_codes[5];
};

struct RealPoint2D
{
	float X;
	float Y;
};

enum e_game_action : long
{
	_game_action_jump,
	_game_action_switch_grenade,
	_game_action_context_primary,
	_game_action_reload,
	_game_action_switch_weapon,
	_game_action_melee,
	_game_action_flashlight,
	_game_action_throw_grenade,
	_game_action_fire,
	_game_action_crouch,
	_game_action_zoom,
	_game_action_zoom_in,
	_game_action_zoom_out,
	_game_action_exchange_weapon,
	_game_action_trick,
	_game_action_brake,
	_game_action_ebrake,
	_game_action_sprint,
	_game_action_banshee_bomb,
	_game_action_forward,
	_game_action_backward,
	_game_action_left,
	_game_action_right,
	_game_action_lean_left,
	_game_action_lean_right,
	_game_action_start,
	_game_action_back,
	_game_action_show_scores,
	_game_action_accept,
	_game_action_cancel,
	_game_action_primary_vehicle_trick,
	_game_action_secondary_vehicle_trick,
	_game_action_magnify_zoom,
	_game_action_equipment,

	_game_action_fire_secondary,

	_game_action_lift_editor,
	_game_action_drop_editor,
	_game_action_grab_object_editor,
	_game_action_boost_editor,
	_game_action_crouch_editor,
	_game_action_delete_object_editor,
	_game_action_create_object_editor,
	_game_action_open_tool_menu_editor,
	_game_action_switch_player_mode_editor,
	_game_action_scope_zoom_editor,
	_game_action_player_lock_for_manipulation_editor,
	_game_action_show_hide_pannel_theater,
	_game_action_show_hide_interface_theater,
	_game_action_toggle_first_third_person_view_theater,
	_game_action_camera_focus_theater,
	_game_action_fast_forward_theater,
	_game_action_fast_rewind_theater,
	_game_action_stop_continue_playback_theater,
	_game_action_playback_speed_up_theater,
	_game_action_enter_free_camera_mode_theater,

	_game_action_movement_speed_up_theater,

	_game_action_panning_camera_theater,
	_game_action_camera_move_up_theater,
	_game_action_camera_move_down_theater,
	_game_action_dual_wield,
	_game_action_zoom_camera_theater,

	k_number_of_game_actions,

	k_number_of_game_actions_v1 = _game_action_equipment + 1,
	k_number_of_game_actions_v2 = _game_action_fire_secondary + 1,
	k_number_of_game_actions_v3 = _game_action_enter_free_camera_mode_theater + 1,
	k_number_of_game_actions_v4 = _game_action_movement_speed_up_theater + 1,
	k_number_of_game_actions_v5 = _game_action_zoom_camera_theater + 1,
};

template<size_t game_actions_count>
struct s_player_configuration_v1
{
	long subtitle_setting;
	long crosshair_location;
	long fov_setting;
	bool look_controls_inverted;
	bool vibration_disabled;
	bool impulse_triggers_disabled;
	bool arcraft_controls_inverted;
	bool auto_center_enabled;
	bool crouch_lock_enabled;
	bool clench_protection_enabled;
	bool use_female_voice;
	bool hold_to_zoom;
	char __padding0[3];
	long player_model_primary_color_index;
	long player_model_secondary_color_index;
	long player_model_tertiary_color_index;
	bool use_elite_model;
	char __padding1[3];
	long player_model_permutation;
	wchar_t service_tag[4];
	long online_medal_flasher;
	long vertical_look_sensitivity;
	long horizontal_look_sensitivity;
	long look_acceleration;
	float look_axial_dead_zone;
	float look_radial_dead_zone;
	float zoom_look_sensitivity_multiplier;
	float vehicle_look_sensitivity_multiplier;
	long button_preset;
	long stick_preset;
	long lefty_toggle;
	long flying_camera_turn_sensitivity;
	long flying_camera_panning;
	long flying_camera_speed;
	long flying_camera_thrust;
	long theater_turn_sensitivity;
	long theater_panning;
	long theater_speed;
	long theater_thrust;
	bool swap_triggers_and_bumpers;
	bool use_modern_aim_control;
	bool use_double_press_jump_to_jetpack;
	char __padding2;
	char enemy_player_name_color;
	char game_engine_timer;
	char __padding3[2];
	s_loadout_slot loadout_slots[5];
	char game_specific[256];
	float mouse_sensitivity;
	bool mouse_smoothing;
	bool mouse_acceleration;
	char __padding4[2];
	float mouse_acceleration_min_rate;
	float mouse_acceleration_max_accel;
	float mouse_acceleration_scale;
	float mouse_acceleration_exp;
	long keyboard_mouse_button_preset;
	s_game_keyboard_mouse_mapping game_keyboard_mouse_mappings[game_actions_count];
	float master_volume;
	float music_volume;
	float sfx_volume;
	char __padding5[20];
	long brightness;
};

template<size_t game_actions_count>
struct s_player_configuration_v2
{
	long subtitle_setting;
	long crosshair_location;
	long fov_setting;
	/* new in this version */ long vehicle_fov_setting;
	bool look_controls_inverted;
	/* new in this version */ bool mouse_look_controls_inverted;
	bool vibration_disabled;
	bool impulse_triggers_disabled;
	bool arcraft_controls_inverted;
	/* new in this version */ bool mouse_arcraft_controls_inverted;
	bool auto_center_enabled;
	bool crouch_lock_enabled;
	/* new in this version */ bool mk_crouch_lock_enabled;
	bool clench_protection_enabled;
	bool use_female_voice;
	bool hold_to_zoom;
	long player_model_primary_color_index;
	long player_model_secondary_color_index;
	long player_model_tertiary_color_index;
	bool use_elite_model;
	char __padding0[3];
	long player_model_permutation;
	/* new in this version */ eHaloArmor helmet_index;
	/* new in this version */ eHaloArmor left_shoulder_index;
	/* new in this version */ eHaloArmor right_shoulder_index;
	/* new in this version */ eHaloArmor chest_index;
	/* new in this version */ eHaloArmor wrist_index;
	/* new in this version */ eHaloArmor utility_index;
	/* new in this version */ eHaloArmor knee_guards_index;
	/* new in this version */ eHaloArmor visor_color_index;
	/* new in this version */ eHaloArmor spartan_armor_effect_index;
	/* new in this version */ eHaloArmor spartan_body_index;
	/* new in this version */ eHaloArmor elite_armor_index;
	/* new in this version */ eHaloArmor elite_armor_effect_index;
	/* new in this version */ eHaloArmor voice_index;
	/* new in this version */ eHaloArmor player_model_primary_color;
	/* new in this version */ eHaloArmor player_model_secondary_color;
	/* new in this version */ eHaloArmor player_model_tertiary_color;
	wchar_t service_tag[4];
	long online_medal_flasher;
	long vertical_look_sensitivity;
	long horizontal_look_sensitivity;
	long look_acceleration;
	float look_axial_dead_zone;
	float look_radial_dead_zone;
	float zoom_look_sensitivity_multiplier;
	float vehicle_look_sensitivity_multiplier;
	long button_preset;
	long stick_preset;
	long lefty_toggle;
	long flying_camera_turn_sensitivity;
	long flying_camera_panning;
	long flying_camera_speed;
	long flying_camera_thrust;
	long theater_turn_sensitivity;
	long theater_panning;
	long theater_speed;
	long theater_thrust;
	bool swap_triggers_and_bumpers;
	bool use_modern_aim_control;
	bool use_double_press_jump_to_jetpack;
	char __padding1;
	char enemy_player_name_color;
	char game_engine_timer;
	char __padding2[2];
	s_loadout_slot loadout_slots[5];
	char game_specific[256];
	float mouse_sensitivity;
	bool mouse_smoothing;
	bool mouse_acceleration;
	char __padding3[2];
	float mouse_acceleration_min_rate;
	float mouse_acceleration_max_accel;
	float mouse_acceleration_scale;
	float mouse_acceleration_exp;
	long keyboard_mouse_button_preset;
	s_game_keyboard_mouse_mapping game_keyboard_mouse_mappings[game_actions_count];
	float master_volume;
	float music_volume;
	float sfx_volume;
	char __padding4[16];
	long brightness;
};

template<size_t game_actions_count>
struct s_player_configuration_v4 : s_player_configuration_v2<game_actions_count>
{
	/* new in this version */ RealPoint2D weapon_display_offsets[5];
};

template<size_t game_actions_count>
struct s_player_configuration_v6
{
	long subtitle_setting;
	long crosshair_location;
	long fov_setting;
	long vehicle_fov_setting;
	bool look_controls_inverted;
	bool mouse_look_controls_inverted;
	bool vibration_disabled;
	bool impulse_triggers_disabled;
	bool arcraft_controls_inverted;
	bool mouse_arcraft_controls_inverted;
	bool auto_center_enabled;
	bool crouch_lock_enabled;
	bool mk_crouch_lock_enabled;
	bool clench_protection_enabled;
	bool use_female_voice;
	bool hold_to_zoom;
	long player_model_primary_color_index;
	long player_model_secondary_color_index;
	long player_model_tertiary_color_index;
	bool use_elite_model;
	char __padding0[3];
	long player_model_permutation;
	eHaloArmor helmet_index;
	eHaloArmor left_shoulder_index;
	eHaloArmor right_shoulder_index;
	eHaloArmor chest_index;
	eHaloArmor wrist_index;
	eHaloArmor utility_index;
	eHaloArmor knee_guards_index;
	eHaloArmor visor_color_index;
	eHaloArmor spartan_armor_effect_index;
	eHaloArmor spartan_body_index;
	eHaloArmor elite_armor_index;
	eHaloArmor elite_armor_effect_index;
	eHaloArmor voice_index;
	eHaloArmor player_model_primary_color;
	eHaloArmor player_model_secondary_color;
	eHaloArmor player_model_tertiary_color;
	wchar_t service_tag[4];
	long online_medal_flasher;
	long vertical_look_sensitivity;
	long horizontal_look_sensitivity;
	long look_acceleration;
	float look_axial_dead_zone;
	float look_radial_dead_zone;
	float zoom_look_sensitivity_multiplier;
	float vehicle_look_sensitivity_multiplier;
	long button_preset;
	long stick_preset;
	long lefty_toggle;
	long flying_camera_turn_sensitivity;
	long flying_camera_panning;
	long flying_camera_speed;
	long flying_camera_thrust;
	long theater_turn_sensitivity;
	long theater_panning;
	long theater_speed;
	long theater_thrust;
	/* new in this version */ char __unknown0[16];
	bool swap_triggers_and_bumpers;
	bool use_modern_aim_control;
	bool use_double_press_jump_to_jetpack;
	bool __padding1;
	char enemy_player_name_color;
	char game_engine_timer;
	char __padding2[2];
	s_loadout_slot loadout_slots[5];
	char game_specific[256];
	float mouse_sensitivity;
	bool mouse_smoothing;
	bool mouse_acceleration;
	char __padding3[2];
	float mouse_acceleration_min_rate;
	float mouse_acceleration_max_accel;
	float mouse_acceleration_scale;
	float mouse_acceleration_exp;
	long keyboard_mouse_button_preset;
	s_game_keyboard_mouse_mapping game_keyboard_mouse_mappings[game_actions_count];
	float master_volume;
	float music_volume;
	float sfx_volume;
	char __padding4[16];
	long brightness;
	RealPoint2D weapon_display_offsets[5];
};

using t_player_configuration_v1 = s_player_configuration_v1<k_number_of_game_actions_v1>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v1, 0x624);
using t_player_configuration_v2 = s_player_configuration_v2<k_number_of_game_actions_v1>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v2, 0x664);
using t_player_configuration_v3 = s_player_configuration_v2<k_number_of_game_actions_v2>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v3, 0x67C);
using t_player_configuration_v4 = s_player_configuration_v4<k_number_of_game_actions_v3>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v4, 0x884);
using t_player_configuration_v5 = s_player_configuration_v4<k_number_of_game_actions_v4>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v5, 0x89C);
using t_player_configuration_v6 = s_player_configuration_v6<k_number_of_game_actions_v5>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v6, 0x924);

enum e_player_configuration_version
{
	_player_configuration_version_1,
	_player_configuration_version_2,
	_player_configuration_version_3,
	_player_configuration_version_4,
	_player_configuration_version_5,
	_player_configuration_version_6,
};

class c_player_configuration
{
private:
	union
	{
		t_player_configuration_v1 player_configuration_v1;
		t_player_configuration_v2 player_configuration_v2;
		t_player_configuration_v3 player_configuration_v3;
		t_player_configuration_v4 player_configuration_v4;
		t_player_configuration_v5 player_configuration_v5;
		t_player_configuration_v6 player_configuration_v6;
	};
public:
	e_player_configuration_version const player_configuration_version;

	long& subtitle_setting;
	long& crosshair_location;
	long& fov_setting;
	long& vehicle_fov_setting;
	bool& look_controls_inverted;
	bool& mouse_look_controls_inverted;
	bool& vibration_disabled;
	bool& impulse_triggers_disabled;
	bool& arcraft_controls_inverted;
	bool& mouse_arcraft_controls_inverted;
	bool& auto_center_enabled;
	bool& crouch_lock_enabled;
	bool& mk_crouch_lock_enabled;
	bool& clench_protection_enabled;
	bool& use_female_voice;
	bool& hold_to_zoom;
	long& player_model_primary_color_index;
	long& player_model_secondary_color_index;
	long& player_model_tertiary_color_index;
	bool& use_elite_model;

	long& player_model_permutation;
	eHaloArmor& helmet_index;
	eHaloArmor& left_shoulder_index;
	eHaloArmor& right_shoulder_index;
	eHaloArmor& chest_index;
	eHaloArmor& wrist_index;
	eHaloArmor& utility_index;
	eHaloArmor& knee_guards_index;
	eHaloArmor& visor_color_index;
	eHaloArmor& spartan_armor_effect_index;
	eHaloArmor& spartan_body_index;
	eHaloArmor& elite_armor_index;
	eHaloArmor& elite_armor_effect_index;
	eHaloArmor& voice_index;
	eHaloArmor& player_model_primary_color;
	eHaloArmor& player_model_secondary_color;
	eHaloArmor& player_model_tertiary_color;

	wchar_t (&service_tag)[4];

	long& online_medal_flasher;
	long& vertical_look_sensitivity;
	long& horizontal_look_sensitivity;
	long& look_acceleration;
	float& look_axial_dead_zone;
	float& look_radial_dead_zone;
	float& zoom_look_sensitivity_multiplier;
	float& vehicle_look_sensitivity_multiplier;
	long& button_preset;
	long& stick_preset;
	long& lefty_toggle;
	long& flying_camera_turn_sensitivity;
	long& flying_camera_panning;
	long& flying_camera_speed;
	long& flying_camera_thrust;
	long& theater_turn_sensitivity;
	long& theater_panning;
	long& theater_speed;
	long& theater_thrust;

	char (&__unknown0)[16];

	bool& swap_triggers_and_bumpers;
	bool& use_modern_aim_control;
	bool& use_double_press_jump_to_jetpack;

	char& enemy_player_name_color;
	char& game_engine_timer;

	s_loadout_slot (&loadout_slots)[5];
	char (&game_specific)[256];
	float& mouse_sensitivity;
	bool& mouse_smoothing;
	bool& mouse_acceleration;

	float& mouse_acceleration_min_rate;
	float& mouse_acceleration_max_accel;
	float& mouse_acceleration_scale;
	float& mouse_acceleration_exp;
	long& keyboard_mouse_button_preset;
	//s_game_keyboard_mouse_mapping game_keyboard_mouse_mappings[k_number_of_game_actions_v5];
	float& master_volume;
	float& music_volume;
	float& sfx_volume;

	long& brightness;
	RealPoint2D (&weapon_display_offsets)[5];

private:

#define reference_getter(field_name) \
	decltype(&field_name) get_##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_1: return &player_configuration_v1.field_name; \
		case _player_configuration_version_2: return &player_configuration_v2.field_name; \
		case _player_configuration_version_3: return &player_configuration_v3.field_name; \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v2(field_name) \
	decltype(&field_name) get_##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_2: return &player_configuration_v2.field_name; \
		case _player_configuration_version_3: return &player_configuration_v3.field_name; \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v4(field_name) \
	decltype(&field_name) get_##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		} \
		return nullptr; \
	}

	reference_getter(subtitle_setting);
	reference_getter(crosshair_location);
	reference_getter(fov_setting);
	reference_getter_v2(vehicle_fov_setting);
	reference_getter(look_controls_inverted);
	reference_getter_v2(mouse_look_controls_inverted);
	reference_getter(vibration_disabled);
	reference_getter(impulse_triggers_disabled);
	reference_getter(arcraft_controls_inverted);
	reference_getter_v2(mouse_arcraft_controls_inverted);
	reference_getter(auto_center_enabled);
	reference_getter(crouch_lock_enabled);
	reference_getter_v2(mk_crouch_lock_enabled);
	reference_getter(clench_protection_enabled);
	reference_getter(use_female_voice);
	reference_getter(hold_to_zoom);
	reference_getter(player_model_primary_color_index);
	reference_getter(player_model_secondary_color_index);
	reference_getter(player_model_tertiary_color_index);
	reference_getter(use_elite_model);
	reference_getter(player_model_permutation);
	reference_getter_v2(helmet_index);
	reference_getter_v2(left_shoulder_index);
	reference_getter_v2(right_shoulder_index);
	reference_getter_v2(chest_index);
	reference_getter_v2(wrist_index);
	reference_getter_v2(utility_index);
	reference_getter_v2(knee_guards_index);
	reference_getter_v2(visor_color_index);
	reference_getter_v2(spartan_armor_effect_index);
	reference_getter_v2(spartan_body_index);
	reference_getter_v2(elite_armor_index);
	reference_getter_v2(elite_armor_effect_index);
	reference_getter_v2(voice_index);
	reference_getter_v2(player_model_primary_color);
	reference_getter_v2(player_model_secondary_color);
	reference_getter_v2(player_model_tertiary_color);
	reference_getter(service_tag);
	reference_getter(online_medal_flasher);
	reference_getter(vertical_look_sensitivity);
	reference_getter(horizontal_look_sensitivity);
	reference_getter(look_acceleration);
	reference_getter(look_axial_dead_zone);
	reference_getter(look_radial_dead_zone);
	reference_getter(zoom_look_sensitivity_multiplier);
	reference_getter(vehicle_look_sensitivity_multiplier);
	reference_getter(button_preset);
	reference_getter(stick_preset);
	reference_getter(lefty_toggle);
	reference_getter(flying_camera_turn_sensitivity);
	reference_getter(flying_camera_panning);
	reference_getter(flying_camera_speed);
	reference_getter(flying_camera_thrust);
	reference_getter(theater_turn_sensitivity);
	reference_getter(theater_panning);
	reference_getter(theater_speed);
	reference_getter(theater_thrust);
	//reference_getter_v6(__unknown0);
	reference_getter(swap_triggers_and_bumpers);
	reference_getter(use_modern_aim_control);
	reference_getter(use_double_press_jump_to_jetpack);
	reference_getter(enemy_player_name_color);
	reference_getter(game_engine_timer);
	reference_getter(loadout_slots);
	reference_getter(game_specific);
	reference_getter(mouse_sensitivity);
	reference_getter(mouse_smoothing);
	reference_getter(mouse_acceleration);
	reference_getter(mouse_acceleration_min_rate);
	reference_getter(mouse_acceleration_max_accel);
	reference_getter(mouse_acceleration_scale);
	reference_getter(mouse_acceleration_exp);
	reference_getter(keyboard_mouse_button_preset);
	reference_getter(master_volume);
	reference_getter(music_volume);
	reference_getter(sfx_volume);
	reference_getter(brightness);
	reference_getter_v4(weapon_display_offsets)

#undef reference_getter

	class c_virtual_player_configuration_game_keyboard_mouse_mapping_interface
	{
	public:
		c_virtual_player_configuration_game_keyboard_mouse_mapping_interface(c_player_configuration& parent) :
			parent(parent)
		{ }

		c_player_configuration& parent;

		s_game_keyboard_mouse_mapping& operator[](size_t game_action_index) const
		{
			switch (parent.player_configuration_version)
			{
			//case _player_configuration_version_1: return parent.player_configuration_v1.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_2: return parent.player_configuration_v2.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_3: return parent.player_configuration_v3.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_4: return parent.player_configuration_v4.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_5: return parent.player_configuration_v5.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_6: return parent.player_configuration_v6.game_keyboard_mouse_mappings[game_action_index];
			}
			throw;
		}
	};

public:
	//c_virtual_player_configuration_loadout_slot_interface loadout_slots;
	c_virtual_player_configuration_game_keyboard_mouse_mapping_interface game_keyboard_mouse_mappings;

	c_player_configuration(e_player_configuration_version player_configuration_version) :
		player_configuration_v1(),
		//player_configuration_v2(),
		//player_configuration_v3(),
		//player_configuration_v4(),
		//player_configuration_v5(),
		//player_configuration_v6(),

		player_configuration_version(player_configuration_version),

		subtitle_setting(*get_subtitle_setting()),
		crosshair_location(*get_crosshair_location()),
		fov_setting(*get_fov_setting()),
		vehicle_fov_setting(*get_vehicle_fov_setting()),
		look_controls_inverted(*get_look_controls_inverted()),
		mouse_look_controls_inverted(*get_mouse_look_controls_inverted()),
		vibration_disabled(*get_vibration_disabled()),
		impulse_triggers_disabled(*get_impulse_triggers_disabled()),
		arcraft_controls_inverted(*get_arcraft_controls_inverted()),
		mouse_arcraft_controls_inverted(*get_mouse_arcraft_controls_inverted()),
		auto_center_enabled(*get_auto_center_enabled()),
		crouch_lock_enabled(*get_crouch_lock_enabled()),
		mk_crouch_lock_enabled(*get_mk_crouch_lock_enabled()),
		clench_protection_enabled(*get_clench_protection_enabled()),
		use_female_voice(*get_use_female_voice()),
		hold_to_zoom(*get_hold_to_zoom()),
		player_model_primary_color_index(*get_player_model_primary_color_index()),
		player_model_secondary_color_index(*get_player_model_secondary_color_index()),
		player_model_tertiary_color_index(*get_player_model_tertiary_color_index()),
		use_elite_model(*get_use_elite_model()),
		player_model_permutation(*get_player_model_permutation()),
		helmet_index(*get_helmet_index()),
		left_shoulder_index(*get_left_shoulder_index()),
		right_shoulder_index(*get_right_shoulder_index()),
		chest_index(*get_chest_index()),
		wrist_index(*get_wrist_index()),
		utility_index(*get_utility_index()),
		knee_guards_index(*get_knee_guards_index()),
		visor_color_index(*get_visor_color_index()),
		spartan_armor_effect_index(*get_spartan_armor_effect_index()),
		spartan_body_index(*get_spartan_body_index()),
		elite_armor_index(*get_elite_armor_index()),
		elite_armor_effect_index(*get_elite_armor_effect_index()),
		voice_index(*get_voice_index()),
		player_model_primary_color(*get_player_model_primary_color()),
		player_model_secondary_color(*get_player_model_secondary_color()),
		player_model_tertiary_color(*get_player_model_tertiary_color()),
		service_tag(*get_service_tag()),
		online_medal_flasher(*get_online_medal_flasher()),
		vertical_look_sensitivity(*get_vertical_look_sensitivity()),
		horizontal_look_sensitivity(*get_horizontal_look_sensitivity()),
		look_acceleration(*get_look_acceleration()),
		look_axial_dead_zone(*get_look_axial_dead_zone()),
		look_radial_dead_zone(*get_look_radial_dead_zone()),
		zoom_look_sensitivity_multiplier(*get_zoom_look_sensitivity_multiplier()),
		vehicle_look_sensitivity_multiplier(*get_vehicle_look_sensitivity_multiplier()),
		button_preset(*get_button_preset()),
		stick_preset(*get_stick_preset()),
		lefty_toggle(*get_lefty_toggle()),
		flying_camera_turn_sensitivity(*get_flying_camera_turn_sensitivity()),
		flying_camera_panning(*get_flying_camera_panning()),
		flying_camera_speed(*get_flying_camera_speed()),
		flying_camera_thrust(*get_flying_camera_thrust()),
		theater_turn_sensitivity(*get_theater_turn_sensitivity()),
		theater_panning(*get_theater_panning()),
		theater_speed(*get_theater_speed()),
		theater_thrust(*get_theater_thrust()),
		__unknown0(player_configuration_v6.__unknown0),
		swap_triggers_and_bumpers(*get_swap_triggers_and_bumpers()),
		use_modern_aim_control(*get_use_modern_aim_control()),
		use_double_press_jump_to_jetpack(*get_use_double_press_jump_to_jetpack()),
		enemy_player_name_color(*get_enemy_player_name_color()),
		game_engine_timer(*get_game_engine_timer()),
		loadout_slots(*get_loadout_slots()),
		game_specific(*get_game_specific()),
		mouse_sensitivity(*get_mouse_sensitivity()),
		mouse_smoothing(*get_mouse_smoothing()),
		mouse_acceleration(*get_mouse_acceleration()),
		mouse_acceleration_min_rate(*get_mouse_acceleration_min_rate()),
		mouse_acceleration_max_accel(*get_mouse_acceleration_max_accel()),
		mouse_acceleration_scale(*get_mouse_acceleration_scale()),
		mouse_acceleration_exp(*get_mouse_acceleration_exp()),
		keyboard_mouse_button_preset(*get_keyboard_mouse_button_preset()),
		game_keyboard_mouse_mappings(*this),
		master_volume(*get_master_volume()),
		music_volume(*get_music_volume()),
		sfx_volume(*get_sfx_volume()),
		brightness(*get_brightness()),
		weapon_display_offsets(*get_weapon_display_offsets())
	{
		memset(&player_configuration_v1, 0, sizeof(player_configuration_v1));
		memset(&player_configuration_v2, 0, sizeof(player_configuration_v2));
		memset(&player_configuration_v3, 0, sizeof(player_configuration_v3));
		memset(&player_configuration_v4, 0, sizeof(player_configuration_v4));
		memset(&player_configuration_v5, 0, sizeof(player_configuration_v5));
		memset(&player_configuration_v6, 0, sizeof(player_configuration_v6));
	}
};
