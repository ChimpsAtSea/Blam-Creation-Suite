#include "gameframework-private-pch.h"

#pragma warning(disable:4244)
#pragma warning(disable:4305)
#define write_control_to_config(field_name) { \
	if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(bool).hash_code()) \
	{ \
		c_settings::write_boolean(_settings_section_player_configuration, STRINGIFY(##field_name), player_configuration.##field_name); \
	} \
	else if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(float).hash_code()) \
	{ \
		c_settings::write_float(_settings_section_player_configuration, STRINGIFY(##field_name), player_configuration.##field_name); \
	} \
	else if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(int).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(char).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(short).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(long).hash_code()) \
	{ \
		c_settings::write_integer(_settings_section_player_configuration, STRINGIFY(##field_name), player_configuration.##field_name); \
	} \
}

#define read_control_from_config(field_name, default_value) { \
	if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(bool).hash_code()) \
	{ \
		player_configuration.##field_name = c_settings::read_boolean(_settings_section_player_configuration, STRINGIFY(##field_name), default_value); \
	} \
	else if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(float).hash_code()) \
	{ \
		player_configuration.##field_name = c_settings::read_float(_settings_section_player_configuration, STRINGIFY(##field_name), default_value); \
	} \
	else if (typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(int).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(char).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(short).hash_code() || \
	typeid(decltype(player_configuration.##field_name)).hash_code() == typeid(long).hash_code()) \
	{ \
		player_configuration.##field_name = c_settings::read_integer(_settings_section_player_configuration, STRINGIFY(##field_name), default_value); \
	} \
}

#define write_custom_key_mapping_to_config(abstract_button_index, custom_key_mappings) { \
	std::string custom_key_mapping_for_write##abstract_button_index(STRINGIFY(##custom_key_mappings)); \
	custom_key_mapping_for_write##abstract_button_index.append("[").append(std::to_string(##abstract_button_index)).append("]."); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(AbstractButton)).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].AbstractButton); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[0])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[0]); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[1])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[1]); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[2])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[2]); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[3])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[3]); \
	c_settings::write_integer(_settings_section_player_configuration, (custom_key_mapping_for_write##abstract_button_index + STRINGIFY(VirtualKeyCodes[4])).c_str(), player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[4]); \
}

#define read_custom_key_mapping_from_config(abstract_button_index, custom_key_mappings, custom_key_mapping) { \
	std::string custom_key_mapping_for_read##abstract_button_index(STRINGIFY(##custom_key_mappings)); \
	custom_key_mapping_for_read##abstract_button_index.append("[").append(std::to_string(##abstract_button_index)).append("]."); \
	player_configuration.##custom_key_mappings[abstract_button_index].AbstractButton = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(AbstractButton)).c_str(), custom_key_mapping.AbstractButton); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[0] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[0])).c_str(), custom_key_mapping.VirtualKeyCodes[0]); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[1] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[1])).c_str(), custom_key_mapping.VirtualKeyCodes[1]); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[2] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[2])).c_str(), custom_key_mapping.VirtualKeyCodes[2]); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[3] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[3])).c_str(), custom_key_mapping.VirtualKeyCodes[3]); \
	player_configuration.##custom_key_mappings[abstract_button_index].VirtualKeyCodes[4] = c_settings::read_integer(_settings_section_player_configuration, (custom_key_mapping_for_read##abstract_button_index + STRINGIFY(VirtualKeyCodes[4])).c_str(), custom_key_mapping.VirtualKeyCodes[4]); \
}

void save_player_configuration_to_file(c_player_configuration& player_configuration)
{
	write_control_to_config(SubtitleSetting);
	write_control_to_config(CrosshairLocation);
	write_control_to_config(FOVSetting);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
		write_control_to_config(VehicleFOVSetting);

	write_control_to_config(LookControlsInverted);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
		write_control_to_config(MouseLookControlsInverted);

	write_control_to_config(VibrationDisabled);
	write_control_to_config(ImpulseTriggersDisabled);
	write_control_to_config(AircraftControlsInverted);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
		write_control_to_config(MouseAircraftControlsInverted);

	write_control_to_config(AutoCenterEnabled);
	write_control_to_config(CrouchLockEnabled);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
		write_control_to_config(MKCrouchLockEnabled);

	write_control_to_config(ClenchProtectionEnabled);
	write_control_to_config(UseFemaleVoice);
	write_control_to_config(HoldToZoom);
	write_control_to_config(PlayerModelPrimaryColorIndex);
	write_control_to_config(PlayerModelSecondaryColorIndex);
	write_control_to_config(PlayerModelTertiaryColorIndex);
	write_control_to_config(UseEliteModel);
	write_control_to_config(LockMaxAspectRatio);

	if (player_configuration.player_configuration_version >= _player_configuration_version_7)
		write_control_to_config(UsersSkinsEnabled);

	write_control_to_config(PlayerModelPermutation);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
	{
		write_control_to_config(HelmetIndex);
		write_control_to_config(LeftShoulderIndex);
		write_control_to_config(RightShoulderIndex);
		write_control_to_config(ChestIndex);
		write_control_to_config(WristIndex);
		write_control_to_config(UtilityIndex);
	}

	if (player_configuration.player_configuration_version >= _player_configuration_version_7)
	{
		write_control_to_config(ArmsIndex);
		write_control_to_config(LegsIndex);
	}

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
	{
		write_control_to_config(PaintSchemeIndex);
		write_control_to_config(VisorColorIndex);
		write_control_to_config(SpartanArmorEffectIndex);
		write_control_to_config(SpartanBodyIndex);
		write_control_to_config(EliteArmorIndex);
		write_control_to_config(EliteArmorEffectIndex);
	}

	if (player_configuration.player_configuration_version >= _player_configuration_version_7)
	{
		write_control_to_config(EliteHelmetIndex);
		write_control_to_config(EliteLeftShoulderIndex);
		write_control_to_config(EliteRightShoulderIndex);
		write_control_to_config(EliteChestIndex);
		write_control_to_config(MaybeEliteWristIndex);
		write_control_to_config(MaybeEliteUtilityIndex);
		write_control_to_config(EliteArmsIndex);
		write_control_to_config(EliteLegsIndex);
	}

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
	{
		write_control_to_config(VoiceIndex);
		write_control_to_config(PlayerModelPrimaryColor);
		write_control_to_config(PlayerModelSecondaryColor);
		write_control_to_config(PlayerModelTertiaryColor);
	}

	c_settings::write_wstring(_settings_section_player_configuration, "ServiceTag", player_configuration.ServiceTag);

	write_control_to_config(OnlineMedalFlasher);
	write_control_to_config(VerticalLookSensitivity);
	write_control_to_config(HorizontalLookSensitivity);
	write_control_to_config(LookAcceleration);
	write_control_to_config(LookAxialDeadZone);
	write_control_to_config(LookRadialDeadZone);
	write_control_to_config(ZoomLookSensitivityMultiplier);
	write_control_to_config(VehicleLookSensitivityMultiplier);
	write_control_to_config(ButtonPreset);
	write_control_to_config(StickPreset);
	write_control_to_config(LeftyToggle);
	write_control_to_config(FlyingCameraTurnSensitivity);
	write_control_to_config(FlyingCameraPanning);
	write_control_to_config(FlyingCameraSpeed);
	write_control_to_config(FlyingCameraThrust);
	write_control_to_config(TheaterTurnSensitivity);
	write_control_to_config(TheaterPanning);
	write_control_to_config(TheaterSpeed);
	write_control_to_config(TheaterThrust);
	write_control_to_config(SwapTriggersAndBumpers);
	write_control_to_config(UseModernAimControl);
	write_control_to_config(UseDoublePressJumpToJetpack);
	write_control_to_config(EnemyPlayerNameColor);
	write_control_to_config(GameEngineTimer);
	write_control_to_config(MouseSensitivity);
	write_control_to_config(MouseSmoothing);
	write_control_to_config(MouseAcceleration);
	write_control_to_config(MouseAccelerationMinRate);
	write_control_to_config(MouseAccelerationMaxAccel);
	write_control_to_config(MouseAccelerationScale);
	write_control_to_config(MouseAccelerationExp);
	write_control_to_config(KeyboardMouseButtonPreset);
	write_control_to_config(MasterVolume);
	write_control_to_config(MusicVolume);
	write_control_to_config(SfxVolume);
	write_control_to_config(Brightness);

	for (long abstract_button_index = 0; abstract_button_index < player_configuration.abstract_button_count; abstract_button_index++)
	{
		write_custom_key_mapping_to_config(abstract_button_index, CustomKeyboardMouseMappings);
	}
}

void load_player_configuration_from_file(c_player_configuration& player_configuration, e_build build, e_engine_type engine_type)
{
	read_control_from_config(SubtitleSetting, 0l);
	read_control_from_config(CrosshairLocation, 0l);
	read_control_from_config(FOVSetting, 90l);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
		read_control_from_config(VehicleFOVSetting, 90l);

	read_control_from_config(LookControlsInverted, false);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
		read_control_from_config(MouseLookControlsInverted, false);

	read_control_from_config(VibrationDisabled, false);
	read_control_from_config(ImpulseTriggersDisabled, false);
	read_control_from_config(AircraftControlsInverted, false);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
		read_control_from_config(MouseAircraftControlsInverted, false);

	read_control_from_config(AutoCenterEnabled, false);
	read_control_from_config(CrouchLockEnabled, false);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
		read_control_from_config(MKCrouchLockEnabled, false);

	read_control_from_config(ClenchProtectionEnabled, false);
	read_control_from_config(UseFemaleVoice, false);
	read_control_from_config(HoldToZoom, true);
	read_control_from_config(PlayerModelPrimaryColorIndex, 0l);
	read_control_from_config(PlayerModelSecondaryColorIndex, 0l);
	read_control_from_config(PlayerModelTertiaryColorIndex, 0l);
	read_control_from_config(UseEliteModel, false);
	read_control_from_config(LockMaxAspectRatio, false);

	if (player_configuration.player_configuration_version >= _player_configuration_version_7)
		read_control_from_config(UsersSkinsEnabled, false);

	read_control_from_config(PlayerModelPermutation, 0l);

	if (player_configuration.player_configuration_version >= _player_configuration_version_2)
	{
		switch (engine_type)
		{
		case _engine_type_haloreach:
			read_control_from_config(HelmetIndex, (long)e_customization_item_v1::HR_Helmet_EOD_Base);
			read_control_from_config(LeftShoulderIndex, (long)e_customization_item_v1::HR_LeftShoulder_Gungnir);
			read_control_from_config(RightShoulderIndex, (long)e_customization_item_v1::HR_RightShoulder_EVA);
			read_control_from_config(ChestIndex, (long)e_customization_item_v1::HR_Chest_UABaseSecurityW);
			read_control_from_config(WristIndex, (long)e_customization_item_v1::HR_Wrist_Default);
			read_control_from_config(UtilityIndex, (long)e_customization_item_v1::HR_Utility_Default);
			read_control_from_config(PaintSchemeIndex, (long)e_customization_item_v1::HR_KneeGuards_FJPARA);
			read_control_from_config(VisorColorIndex, (long)e_customization_item_v1::HR_VisorColor_Blue);
			read_control_from_config(SpartanArmorEffectIndex, (long)e_customization_item_v1::HR_ArmorEffect_BlueFlames);
			read_control_from_config(SpartanBodyIndex, (long)e_customization_item_v1::HR_Spartan_Female);
			read_control_from_config(EliteArmorIndex, (long)e_customization_item_v1::HR_Elite_FieldMarshall);
			read_control_from_config(EliteArmorEffectIndex, (long)e_customization_item_v1::HR_ArmorEffect_Pestilence);
			read_control_from_config(VoiceIndex, (long)e_customization_item_v1::HR_FirefightVoice_JohnS117);
			read_control_from_config(PlayerModelPrimaryColor, (long)e_customization_item_v1::HR_Color_Brick);
			read_control_from_config(PlayerModelSecondaryColor, (long)e_customization_item_v1::HR_Color_Cyan);
			read_control_from_config(PlayerModelTertiaryColor, (long)e_customization_item_v1::HR_Color_Cyan);
			break;
		case _engine_type_halo1:
			read_control_from_config(HelmetIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(LeftShoulderIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(RightShoulderIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(ChestIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(WristIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(UtilityIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(PaintSchemeIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(VisorColorIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(SpartanArmorEffectIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(SpartanBodyIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(EliteArmorIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(EliteArmorEffectIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(VoiceIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(PlayerModelPrimaryColor, (long)e_customization_item_v1::H1_Color_1);
			read_control_from_config(PlayerModelSecondaryColor, (long)e_customization_item_v1::H1_Color_1);
			read_control_from_config(PlayerModelTertiaryColor, (long)e_customization_item_v1::H1_Color_1);
			break;
		case _engine_type_groundhog:
			read_control_from_config(HelmetIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(LeftShoulderIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(RightShoulderIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(ChestIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(WristIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(UtilityIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(PaintSchemeIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(VisorColorIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(SpartanArmorEffectIndex, (long)e_customization_item_v1::H2A_ARMOR0_MARKVI);
			read_control_from_config(SpartanBodyIndex, (long)e_customization_item_v1::HR_Spartan_Female);
			read_control_from_config(EliteArmorIndex, (long)e_customization_item_v1::H2A_ARMOR_ELITE1);
			read_control_from_config(EliteArmorEffectIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(VoiceIndex, (long)e_customization_item_v1::k_customization_item_none);
			read_control_from_config(PlayerModelPrimaryColor, (long)e_customization_item_v1::H2A_Color_1);
			read_control_from_config(PlayerModelSecondaryColor, (long)e_customization_item_v1::H2A_Color_1);
			read_control_from_config(PlayerModelTertiaryColor, (long)e_customization_item_v1::H2A_Color_1);
			break;
		}
	}

	c_settings::read_wstring(_settings_section_player_configuration, "ServiceTag", player_configuration.ServiceTag, 4, L"117");

	read_control_from_config(OnlineMedalFlasher, 0l);
	read_control_from_config(VerticalLookSensitivity, 1.0f);
	read_control_from_config(HorizontalLookSensitivity, 1.0f);
	read_control_from_config(LookAcceleration, 0l);
	read_control_from_config(LookAxialDeadZone, 0.0f);
	read_control_from_config(LookRadialDeadZone, 0.0f);
	read_control_from_config(ZoomLookSensitivityMultiplier, 0.0f);
	read_control_from_config(VehicleLookSensitivityMultiplier, 0.0f);
	read_control_from_config(ButtonPreset, 0l);
	read_control_from_config(StickPreset, 0l);
	read_control_from_config(LeftyToggle, 0l);
	read_control_from_config(FlyingCameraTurnSensitivity, 0l);
	read_control_from_config(FlyingCameraPanning, 0l);
	read_control_from_config(FlyingCameraSpeed, 0l);
	read_control_from_config(FlyingCameraThrust, 0l);
	read_control_from_config(TheaterTurnSensitivity, 0l);
	read_control_from_config(TheaterPanning, 0l);
	read_control_from_config(TheaterSpeed, 0l);
	read_control_from_config(TheaterThrust, 0l);
	read_control_from_config(SwapTriggersAndBumpers, false);
	read_control_from_config(UseModernAimControl, false);
	read_control_from_config(UseDoublePressJumpToJetpack, true);
	read_control_from_config(EnemyPlayerNameColor, 0i8);
	read_control_from_config(GameEngineTimer, 0i8);
	read_control_from_config(MouseSensitivity, 0.0f);
	read_control_from_config(MouseSmoothing, false);
	read_control_from_config(MouseAcceleration, false);
	read_control_from_config(MouseAccelerationMinRate, 0.0f);
	read_control_from_config(MouseAccelerationMaxAccel, 0.0f);
	read_control_from_config(MouseAccelerationScale, 0.0f);
	read_control_from_config(MouseAccelerationExp, 0.0f);
	read_control_from_config(KeyboardMouseButtonPreset, 0l);
	read_control_from_config(MasterVolume, 60.0f);
	read_control_from_config(MusicVolume, 20.0f);
	read_control_from_config(SfxVolume, 80.0f);
	read_control_from_config(Brightness, 0l);

	s_custom_key_mapping CustomKeyboardMouseMappings[k_number_of_abstract_buttons] = {};

	for (long i = 0; i < k_number_of_abstract_buttons; i++)
	{
		CustomKeyboardMouseMappings[i].AbstractButton = i;
	}

	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v1)
	{
		CustomKeyboardMouseMappings[_abstract_button_jump_v1].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_switch_grenade_v1].VirtualKeyCodes[0] = 'G';
		CustomKeyboardMouseMappings[_abstract_button_context_primary_v1].VirtualKeyCodes[0] = 'E';
		CustomKeyboardMouseMappings[_abstract_button_reload_v1].VirtualKeyCodes[0] = 'R';
		CustomKeyboardMouseMappings[_abstract_button_switch_weapon_v1].VirtualKeyCodes[0] = 'C';
		CustomKeyboardMouseMappings[_abstract_button_melee_v1].VirtualKeyCodes[0] = 'V';
		CustomKeyboardMouseMappings[_abstract_button_flashlight_v1].VirtualKeyCodes[0] = '4';
		CustomKeyboardMouseMappings[_abstract_button_throw_grenade_v1].VirtualKeyCodes[0] = 'F';
		CustomKeyboardMouseMappings[_abstract_button_fire_v1].VirtualKeyCodes[0] = VK_LBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_crouch_v1].VirtualKeyCodes[0] = VK_LCONTROL;
		CustomKeyboardMouseMappings[_abstract_button_zoom_v1].VirtualKeyCodes[0] = VK_RBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_zoom_in_v1].VirtualKeyCodes[0] = 'Z';
		CustomKeyboardMouseMappings[_abstract_button_zoom_out_v1].VirtualKeyCodes[0] = 'X';
		CustomKeyboardMouseMappings[_abstract_button_exchange_weapon_v1].VirtualKeyCodes[0] = 'E';
		CustomKeyboardMouseMappings[_abstract_button_trick_v1].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_brake_v1].VirtualKeyCodes[0] = VK_LSHIFT;
		CustomKeyboardMouseMappings[_abstract_button_ebrake_v1].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_sprint_v1].VirtualKeyCodes[0] = VK_LSHIFT;
		CustomKeyboardMouseMappings[_abstract_button_banshee_bomb_v1].VirtualKeyCodes[0] = 'F';
		CustomKeyboardMouseMappings[_abstract_button_forward_v1].VirtualKeyCodes[0] = 'W';
		CustomKeyboardMouseMappings[_abstract_button_backward_v1].VirtualKeyCodes[0] = 'S';
		CustomKeyboardMouseMappings[_abstract_button_left_v1].VirtualKeyCodes[0] = 'A';
		CustomKeyboardMouseMappings[_abstract_button_right_v1].VirtualKeyCodes[0] = 'D';
		CustomKeyboardMouseMappings[_abstract_button_lean_left_v1].VirtualKeyCodes[0] = '8';
		CustomKeyboardMouseMappings[_abstract_button_lean_right_v1].VirtualKeyCodes[0] = '9';
		CustomKeyboardMouseMappings[_abstract_button_start_v1].VirtualKeyCodes[0] = '7';
		CustomKeyboardMouseMappings[_abstract_button_back_v1].VirtualKeyCodes[0] = VK_TAB;
		CustomKeyboardMouseMappings[_abstract_button_show_scores_v1].VirtualKeyCodes[0] = VK_TAB;
		CustomKeyboardMouseMappings[_abstract_button_accept_v1].VirtualKeyCodes[0] = '5';
		CustomKeyboardMouseMappings[_abstract_button_cancel_v1].VirtualKeyCodes[0] = '6';
		CustomKeyboardMouseMappings[_abstract_button_primary_vehicle_trick_v1].VirtualKeyCodes[0] = VK_LCONTROL;
		CustomKeyboardMouseMappings[_abstract_button_secondary_vehicle_trick_v1].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_magnify_zoom_v1].VirtualKeyCodes[0] = 'Z';
		CustomKeyboardMouseMappings[_abstract_button_equipment_v1].VirtualKeyCodes[0] = VK_LSHIFT;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v2)
	{
		CustomKeyboardMouseMappings[_abstract_button_fire_secondary_v2].VirtualKeyCodes[0] = VK_LSHIFT;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v3)
	{
		CustomKeyboardMouseMappings[_abstract_button_lift_editor_v3].VirtualKeyCodes[0] = 'R';
		CustomKeyboardMouseMappings[_abstract_button_drop_editor_v3].VirtualKeyCodes[0] = 'F';
		CustomKeyboardMouseMappings[_abstract_button_grab_object_editor_v3].VirtualKeyCodes[0] = VK_LBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_boost_editor_v3].VirtualKeyCodes[0] = VK_LSHIFT;
		CustomKeyboardMouseMappings[_abstract_button_crouch_editor_v3].VirtualKeyCodes[0] = VK_LCONTROL;
		CustomKeyboardMouseMappings[_abstract_button_delete_object_editor_v3].VirtualKeyCodes[0] = VK_DELETE;
		CustomKeyboardMouseMappings[_abstract_button_create_object_editor_v3].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_open_tool_menu_editor_v3].VirtualKeyCodes[0] = 'X';
		CustomKeyboardMouseMappings[_abstract_button_switch_player_mode_editor_v3].VirtualKeyCodes[0] = VK_UP;
		CustomKeyboardMouseMappings[_abstract_button_scope_zoom_editor_v3].VirtualKeyCodes[0] = VK_RBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_player_lock_for_manipulation_editor_v3].VirtualKeyCodes[0] = VK_LMENU;
		CustomKeyboardMouseMappings[_abstract_button_show_hide_pannel_theater_v3].VirtualKeyCodes[0] = 'X';
		CustomKeyboardMouseMappings[_abstract_button_show_hide_interface_theater_v3].VirtualKeyCodes[0] = 'Z';
		CustomKeyboardMouseMappings[_abstract_button_toggle_first_third_person_view_theater_v3].VirtualKeyCodes[0] = 'C';
		CustomKeyboardMouseMappings[_abstract_button_camera_focus_theater_v3].VirtualKeyCodes[0] = VK_RBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_fast_forward_theater_v3].VirtualKeyCodes[0] = VK_RIGHT;
		CustomKeyboardMouseMappings[_abstract_button_fast_rewind_theater_v3].VirtualKeyCodes[0] = VK_LEFT;
		CustomKeyboardMouseMappings[_abstract_button_stop_continue_playback_theater_v3].VirtualKeyCodes[0] = VK_RETURN;
		CustomKeyboardMouseMappings[_abstract_button_playback_speed_up_theater_v3].VirtualKeyCodes[0] = VK_LMENU;
		CustomKeyboardMouseMappings[_abstract_button_enter_free_camera_mode_theater_v3].VirtualKeyCodes[0] = VK_SPACE;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v4)
	{
		CustomKeyboardMouseMappings[_abstract_button_movement_speed_up_theater_v4].VirtualKeyCodes[0] = VK_LSHIFT;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v5)
	{
		CustomKeyboardMouseMappings[_abstract_button_panning_camera_theater_v5].VirtualKeyCodes[0] = VK_OEM_RESET;
		CustomKeyboardMouseMappings[_abstract_button_camera_move_up_theater_v5].VirtualKeyCodes[0] = 'Q';
		CustomKeyboardMouseMappings[_abstract_button_camera_move_down_theater_v5].VirtualKeyCodes[0] = 'E';
		CustomKeyboardMouseMappings[_abstract_button_dual_wield_v5].VirtualKeyCodes[0] = 'Q';
		CustomKeyboardMouseMappings[_abstract_button_zoom_camera_theater_v5].VirtualKeyCodes[0] = VK_OEM_RESET;
	}
	if (player_configuration.abstract_button_count >= k_number_of_abstract_buttons_v6)
	{
		CustomKeyboardMouseMappings[_abstract_button_toggle_rotation_axes_editor_v6].VirtualKeyCodes[0] = 'O';
		CustomKeyboardMouseMappings[_abstract_button_show_hide_pannel_theater_v6].VirtualKeyCodes[0] = 'X';
		CustomKeyboardMouseMappings[_abstract_button_show_hide_interface_theater_v6].VirtualKeyCodes[0] = 'Z';
		CustomKeyboardMouseMappings[_abstract_button_toggle_first_third_person_view_theater_v6].VirtualKeyCodes[0] = 'C';
		CustomKeyboardMouseMappings[_abstract_button_camera_focus_theater_v6].VirtualKeyCodes[0] = VK_RBUTTON;
		CustomKeyboardMouseMappings[_abstract_button_fast_forward_theater_v6].VirtualKeyCodes[0] = VK_RIGHT;
		CustomKeyboardMouseMappings[_abstract_button_fast_rewind_theater_v6].VirtualKeyCodes[0] = VK_LEFT;
		CustomKeyboardMouseMappings[_abstract_button_stop_continue_playback_theater_v6].VirtualKeyCodes[0] = VK_RETURN;
		CustomKeyboardMouseMappings[_abstract_button_playback_speed_up_theater_v6].VirtualKeyCodes[0] = VK_LMENU;
		CustomKeyboardMouseMappings[_abstract_button_enter_free_camera_mode_theater_v6].VirtualKeyCodes[0] = VK_SPACE;
		CustomKeyboardMouseMappings[_abstract_button_movement_speed_up_theater_v6].VirtualKeyCodes[0] = VK_LSHIFT;
		CustomKeyboardMouseMappings[_abstract_button_panning_camera_theater_v6].VirtualKeyCodes[0] = VK_OEM_RESET;
		CustomKeyboardMouseMappings[_abstract_button_camera_move_up_theater_v6].VirtualKeyCodes[0] = 'Q';
		CustomKeyboardMouseMappings[_abstract_button_camera_move_down_theater_v6].VirtualKeyCodes[0] = 'E';
		CustomKeyboardMouseMappings[_abstract_button_dual_wield_v6].VirtualKeyCodes[0] = 'Q';
		CustomKeyboardMouseMappings[_abstract_button_zoom_camera_theater_v6].VirtualKeyCodes[0] = VK_OEM_RESET;
	}

	for (long abstract_button_index = 0; abstract_button_index < player_configuration.abstract_button_count; abstract_button_index++)
	{
		read_custom_key_mapping_from_config(abstract_button_index, CustomKeyboardMouseMappings, CustomKeyboardMouseMappings[abstract_button_index]);
	}
}

#undef read_control_from_config
#undef write_control_to_config
#undef read_custom_key_mapping_from_config
#undef write_custom_key_mapping_to_config
#pragma warning(default:4244)
#pragma warning(default:4305)