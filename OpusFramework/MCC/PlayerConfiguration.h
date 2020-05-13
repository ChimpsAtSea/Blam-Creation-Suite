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

struct LoadoutSlot
{
	long TacticalPackageIndex;
	long SupportUpgradeIndex;
	long PrimaryWeaponIndex;
	long SecondaryWeaponIndex;
	long PrimaryWeaponVariantIndex;
	long SecondaryWeaponVariantIndex;
	long EquipmentIndex;
	long GrenadeIndex;
	wchar_t Name[13];
};

struct GameKeyboardMouseMapping
{
	int AbstractButton;
	int VirtualKeyCodes[5];
};

struct RealPoint2D
{
	float X;
	float Y;
};

enum GameAction : long
{
	Jump,
	SwitchGrenade,
	ContextPrimary,
	Reload,
	SwitchWeapon,
	Melee,
	Flashlight,
	ThrowGrenade,
	Fire,
	Crouch,
	Zoom,
	ZoomIn,
	ZoomOut,
	ExchangeWeapon,
	Trick,
	Brake,
	Ebrake,
	Sprint,
	BansheeBomb,
	Forward,
	Backward,
	Left,
	Right,
	LeanLeft,
	LeanRight,
	Start,
	Back,
	ShowScores,
	Accept,
	Cancel,
	PrimaryVehicleTrick,
	SecondaryVehicleTrick,
	MagnifyZoom,
	Equipment,

	FireSecondary,

	LiftEditor,
	DropEditor,
	GrabObjectEditor,
	BoostEditor,
	CrouchEditor,
	DeleteObjectEditor,
	CreateObjectEditor,
	OpenToolMenuEditor,
	SwitchPlayerModeEditor,
	ScopeZoomEditor,
	PlayerLockForManipulationEditor,
	ShowHidePannelTheater,
	ShowHideInterfaceTheater,
	ToggleFirstThirdPersonViewTheater,
	CameraFocusTheater,
	FastForwardTheater,
	FastRewindTheater,
	StopContinuePlaybackTheater,
	PlaybackSpeedUpTheater,
	EnterFreeCameraModeTheater,

	MovementSpeedUpTheater,

	PanningCameraTheater,
	CameraMoveUpTheater,
	CameraMoveDownTheater,
	DualWield,
	ZoomCameraTheater,

	Count,

	GameActionV1_Count = Equipment + 1,
	GameActionV2_Count = FireSecondary + 1,
	GameActionV3_Count = EnterFreeCameraModeTheater + 1,
	GameActionV4_Count = MovementSpeedUpTheater + 1,
	GameActionV5_Count = ZoomCameraTheater + 1,
};

template<size_t k_number_of_game_actions>
struct s_player_configuration_v1
{
	long SubtitleSetting;
	long CrosshairLocation;
	long FOVSetting;
	bool LookControlsInverted;
	bool VibrationDisabled;
	bool ImpulseTriggersDisabled;
	bool AircraftControlsInverted;
	bool AutoCenterEnabled;
	bool CrouchLockEnabled;
	bool ClenchProtectionEnabled;
	bool UseFemaleVoice;
	bool HoldToZoom;
	char __padding0[3];
	long PlayerModelPrimaryColorIndex;
	long PlayerModelSecondaryColorIndex;
	long PlayerModelTertiaryColorIndex;
	bool UseEliteModel;
	char __padding1[3];
	long PlayerModelPermutation;
	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	long VerticalLookSensitivity;
	long HorizontalLookSensitivity;
	long LookAcceleration;
	float LookAxialDeadZone;
	float LookRadialDeadZone;
	float ZoomLookSensitivityMultiplier;
	float VehicleLookSensitivityMultiplier;
	long ButtonPreset;
	long StickPreset;
	long LeftyToggle;
	long FlyingCameraTurnSensitivity;
	long FlyingCameraPanning;
	long FlyingCameraSpeed;
	long FlyingCameraThrust;
	long TheaterTurnSensitivity;
	long TheaterPanning;
	long TheaterSpeed;
	long TheaterThrust;
	bool SwapTriggersAndBumpers;
	bool UseModernAimControl;
	bool UseDoublePressJumpToJetpack;
	char __padding2;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding3[2];
	LoadoutSlot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding4[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	GameKeyboardMouseMapping GameKeyboardMouseMappings[k_number_of_game_actions];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding5[20];
	long Brightness;
};

template<size_t k_number_of_game_actions>
struct s_player_configuration_v2
{
	long SubtitleSetting;
	long CrosshairLocation;
	long FOVSetting;
	/* new in this version */ long VehicleFOVSetting;
	bool LookControlsInverted;
	/* new in this version */ bool MouseLookControlsInverted;
	bool VibrationDisabled;
	bool ImpulseTriggersDisabled;
	bool AircraftControlsInverted;
	/* new in this version */ bool MouseAircraftControlsInverted;
	bool AutoCenterEnabled;
	bool CrouchLockEnabled;
	/* new in this version */ bool MKCrouchLockEnabled;
	bool ClenchProtectionEnabled;
	bool UseFemaleVoice;
	bool HoldToZoom;
	long PlayerModelPrimaryColorIndex;
	long PlayerModelSecondaryColorIndex;
	long PlayerModelTertiaryColorIndex;
	bool UseEliteModel;
	char __padding0[3];
	long PlayerModelPermutation;
	/* new in this version */ eHaloArmor HelmetIndex;
	/* new in this version */ eHaloArmor LeftShoulderIndex;
	/* new in this version */ eHaloArmor RightShoulderIndex;
	/* new in this version */ eHaloArmor ChestIndex;
	/* new in this version */ eHaloArmor WristIndex;
	/* new in this version */ eHaloArmor UtilityIndex;
	/* new in this version */ eHaloArmor KneeGuardsIndex;
	/* new in this version */ eHaloArmor VisorColorIndex;
	/* new in this version */ eHaloArmor SpartanArmorEffectIndex;
	/* new in this version */ eHaloArmor SpartanBodyIndex;
	/* new in this version */ eHaloArmor EliteArmorIndex;
	/* new in this version */ eHaloArmor EliteArmorEffectIndex;
	/* new in this version */ eHaloArmor VoiceIndex;
	/* new in this version */ eHaloArmor PlayerModelPrimaryColor;
	/* new in this version */ eHaloArmor PlayerModelSecondaryColor;
	/* new in this version */ eHaloArmor PlayerModelTertiaryColor;
	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	long VerticalLookSensitivity;
	long HorizontalLookSensitivity;
	long LookAcceleration;
	float LookAxialDeadZone;
	float LookRadialDeadZone;
	float ZoomLookSensitivityMultiplier;
	float VehicleLookSensitivityMultiplier;
	long ButtonPreset;
	long StickPreset;
	long LeftyToggle;
	long FlyingCameraTurnSensitivity;
	long FlyingCameraPanning;
	long FlyingCameraSpeed;
	long FlyingCameraThrust;
	long TheaterTurnSensitivity;
	long TheaterPanning;
	long TheaterSpeed;
	long TheaterThrust;
	bool SwapTriggersAndBumpers;
	bool UseModernAimControl;
	bool UseDoublePressJumpToJetpack;
	char __padding1;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding2[2];
	LoadoutSlot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding3[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	GameKeyboardMouseMapping GameKeyboardMouseMappings[k_number_of_game_actions];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding4[16];
	long Brightness;
};

template<size_t k_number_of_game_actions>
struct s_player_configuration_v4 : s_player_configuration_v2<k_number_of_game_actions>
{
	/* new in this version */ RealPoint2D WeaponDisplayOffsets[5];
};

template<size_t k_number_of_game_actions>
struct s_player_configuration_v6
{
	long SubtitleSetting;
	long CrosshairLocation;
	long FOVSetting;
	long VehicleFOVSetting;
	bool LookControlsInverted;
	bool MouseLookControlsInverted;
	bool VibrationDisabled;
	bool ImpulseTriggersDisabled;
	bool AircraftControlsInverted;
	bool MouseAircraftControlsInverted;
	bool AutoCenterEnabled;
	bool CrouchLockEnabled;
	bool MKCrouchLockEnabled;
	bool ClenchProtectionEnabled;
	bool UseFemaleVoice;
	bool HoldToZoom;
	long PlayerModelPrimaryColorIndex;
	long PlayerModelSecondaryColorIndex;
	long PlayerModelTertiaryColorIndex;
	bool UseEliteModel;
	char __padding0[3];
	long PlayerModelPermutation;
	eHaloArmor HelmetIndex;
	eHaloArmor LeftShoulderIndex;
	eHaloArmor RightShoulderIndex;
	eHaloArmor ChestIndex;
	eHaloArmor WristIndex;
	eHaloArmor UtilityIndex;
	eHaloArmor KneeGuardsIndex;
	eHaloArmor VisorColorIndex;
	eHaloArmor SpartanArmorEffectIndex;
	eHaloArmor SpartanBodyIndex;
	eHaloArmor EliteArmorIndex;
	eHaloArmor EliteArmorEffectIndex;
	eHaloArmor VoiceIndex;
	eHaloArmor PlayerModelPrimaryColor;
	eHaloArmor PlayerModelSecondaryColor;
	eHaloArmor PlayerModelTertiaryColor;
	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	long VerticalLookSensitivity;
	long HorizontalLookSensitivity;
	long LookAcceleration;
	float LookAxialDeadZone;
	float LookRadialDeadZone;
	float ZoomLookSensitivityMultiplier;
	float VehicleLookSensitivityMultiplier;
	long ButtonPreset;
	long StickPreset;
	long LeftyToggle;
	long FlyingCameraTurnSensitivity;
	long FlyingCameraPanning;
	long FlyingCameraSpeed;
	long FlyingCameraThrust;
	long TheaterTurnSensitivity;
	long TheaterPanning;
	long TheaterSpeed;
	long TheaterThrust;
	/* new in this version */ char __unknown0[16];
	bool SwapTriggersAndBumpers;
	bool UseModernAimControl;
	bool UseDoublePressJumpToJetpack;
	bool __padding1;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding2[2];
	LoadoutSlot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding3[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	GameKeyboardMouseMapping GameKeyboardMouseMappings[k_number_of_game_actions];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding4[16];
	long Brightness;
	RealPoint2D WeaponDisplayOffsets[5];
};

using PlayerConfigurationV1 = s_player_configuration_v1<GameActionV1_Count>;
CHECK_STRUCTURE_SIZE(PlayerConfigurationV1, 0x624);
using PlayerConfigurationV2 = s_player_configuration_v2<GameActionV1_Count>;
CHECK_STRUCTURE_SIZE(PlayerConfigurationV2, 0x664);
using PlayerConfigurationV3 = s_player_configuration_v2<GameActionV2_Count>;
CHECK_STRUCTURE_SIZE(PlayerConfigurationV3, 0x67C);
using PlayerConfigurationV4 = s_player_configuration_v4<GameActionV3_Count>;
CHECK_STRUCTURE_SIZE(PlayerConfigurationV4, 0x884);
using PlayerConfigurationV5 = s_player_configuration_v4<GameActionV4_Count>;
CHECK_STRUCTURE_SIZE(PlayerConfigurationV5, 0x89C);
using PlayerConfigurationV6 = s_player_configuration_v6<GameActionV5_Count>;
CHECK_STRUCTURE_SIZE(PlayerConfigurationV6, 0x924);

//using PlayerConfiguration = PlayerConfigurationV6; // TODO: replace this with `class PlayerConfiguration_` when ready

enum e_player_configuration_version
{
	_player_configuration_version_1,
	_player_configuration_version_2,
	_player_configuration_version_3,
	_player_configuration_version_4,
	_player_configuration_version_5,
	_player_configuration_version_6,
};

class PlayerConfiguration
{
private:
	union
	{
		PlayerConfigurationV1 player_configuration_v1;
		PlayerConfigurationV2 player_configuration_v2;
		PlayerConfigurationV3 player_configuration_v3;
		PlayerConfigurationV4 player_configuration_v4;
		PlayerConfigurationV5 player_configuration_v5;
		PlayerConfigurationV6 player_configuration_v6;
	};
public:
	e_player_configuration_version const player_configuration_version;

	long& SubtitleSetting;
	long& CrosshairLocation;
	long& FOVSetting;
	long& VehicleFOVSetting;
	bool& LookControlsInverted;
	bool& MouseLookControlsInverted;
	bool& VibrationDisabled;
	bool& ImpulseTriggersDisabled;
	bool& AircraftControlsInverted;
	bool& MouseAircraftControlsInverted;
	bool& AutoCenterEnabled;
	bool& CrouchLockEnabled;
	bool& MKCrouchLockEnabled;
	bool& ClenchProtectionEnabled;
	bool& UseFemaleVoice;
	bool& HoldToZoom;
	long& PlayerModelPrimaryColorIndex;
	long& PlayerModelSecondaryColorIndex;
	long& PlayerModelTertiaryColorIndex;
	bool& UseEliteModel;

	long& PlayerModelPermutation;
	eHaloArmor& HelmetIndex;
	eHaloArmor& LeftShoulderIndex;
	eHaloArmor& RightShoulderIndex;
	eHaloArmor& ChestIndex;
	eHaloArmor& WristIndex;
	eHaloArmor& UtilityIndex;
	eHaloArmor& KneeGuardsIndex;
	eHaloArmor& VisorColorIndex;
	eHaloArmor& SpartanArmorEffectIndex;
	eHaloArmor& SpartanBodyIndex;
	eHaloArmor& EliteArmorIndex;
	eHaloArmor& EliteArmorEffectIndex;
	eHaloArmor& VoiceIndex;
	eHaloArmor& PlayerModelPrimaryColor;
	eHaloArmor& PlayerModelSecondaryColor;
	eHaloArmor& PlayerModelTertiaryColor;

	wchar_t (&ServiceTag)[4];

	long& OnlineMedalFlasher;
	long& VerticalLookSensitivity;
	long& HorizontalLookSensitivity;
	long& LookAcceleration;
	float& LookAxialDeadZone;
	float& LookRadialDeadZone;
	float& ZoomLookSensitivityMultiplier;
	float& VehicleLookSensitivityMultiplier;
	long& ButtonPreset;
	long& StickPreset;
	long& LeftyToggle;
	long& FlyingCameraTurnSensitivity;
	long& FlyingCameraPanning;
	long& FlyingCameraSpeed;
	long& FlyingCameraThrust;
	long& TheaterTurnSensitivity;
	long& TheaterPanning;
	long& TheaterSpeed;
	long& TheaterThrust;

	char (&__unknown0)[16];

	bool& SwapTriggersAndBumpers;
	bool& UseModernAimControl;
	bool& UseDoublePressJumpToJetpack;

	char& EnemyPlayerNameColor;
	char& GameEngineTimer;

	LoadoutSlot (&LoadoutSlots)[5];
	char (&GameSpecific)[256];
	float& MouseSensitivity;
	bool& MouseSmoothing;
	bool& MouseAcceleration;

	float& MouseAccelerationMinRate;
	float& MouseAccelerationMaxAccel;
	float& MouseAccelerationScale;
	float& MouseAccelerationExp;
	long& KeyboardMouseButtonPreset;
	//GameKeyboardMouseMapping GameKeyboardMouseMappings[GameActionV5_Count];
	float& MasterVolume;
	float& MusicVolume;
	float& SfxVolume;

	long& Brightness;
	RealPoint2D (&WeaponDisplayOffsets)[5];

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

	reference_getter(SubtitleSetting);
	reference_getter(CrosshairLocation);
	reference_getter(FOVSetting);
	reference_getter_v2(VehicleFOVSetting);
	reference_getter(LookControlsInverted);
	reference_getter_v2(MouseLookControlsInverted);
	reference_getter(VibrationDisabled);
	reference_getter(ImpulseTriggersDisabled);
	reference_getter(AircraftControlsInverted);
	reference_getter_v2(MouseAircraftControlsInverted);
	reference_getter(AutoCenterEnabled);
	reference_getter(CrouchLockEnabled);
	reference_getter_v2(MKCrouchLockEnabled);
	reference_getter(ClenchProtectionEnabled);
	reference_getter(UseFemaleVoice);
	reference_getter(HoldToZoom);
	reference_getter(PlayerModelPrimaryColorIndex);
	reference_getter(PlayerModelSecondaryColorIndex);
	reference_getter(PlayerModelTertiaryColorIndex);
	reference_getter(UseEliteModel);
	reference_getter(PlayerModelPermutation);
	reference_getter_v2(HelmetIndex);
	reference_getter_v2(LeftShoulderIndex);
	reference_getter_v2(RightShoulderIndex);
	reference_getter_v2(ChestIndex);
	reference_getter_v2(WristIndex);
	reference_getter_v2(UtilityIndex);
	reference_getter_v2(KneeGuardsIndex);
	reference_getter_v2(VisorColorIndex);
	reference_getter_v2(SpartanArmorEffectIndex);
	reference_getter_v2(SpartanBodyIndex);
	reference_getter_v2(EliteArmorIndex);
	reference_getter_v2(EliteArmorEffectIndex);
	reference_getter_v2(VoiceIndex);
	reference_getter_v2(PlayerModelPrimaryColor);
	reference_getter_v2(PlayerModelSecondaryColor);
	reference_getter_v2(PlayerModelTertiaryColor);
	reference_getter(ServiceTag);
	reference_getter(OnlineMedalFlasher);
	reference_getter(VerticalLookSensitivity);
	reference_getter(HorizontalLookSensitivity);
	reference_getter(LookAcceleration);
	reference_getter(LookAxialDeadZone);
	reference_getter(LookRadialDeadZone);
	reference_getter(ZoomLookSensitivityMultiplier);
	reference_getter(VehicleLookSensitivityMultiplier);
	reference_getter(ButtonPreset);
	reference_getter(StickPreset);
	reference_getter(LeftyToggle);
	reference_getter(FlyingCameraTurnSensitivity);
	reference_getter(FlyingCameraPanning);
	reference_getter(FlyingCameraSpeed);
	reference_getter(FlyingCameraThrust);
	reference_getter(TheaterTurnSensitivity);
	reference_getter(TheaterPanning);
	reference_getter(TheaterSpeed);
	reference_getter(TheaterThrust);
	//reference_getter_v6(__unknown0);
	reference_getter(SwapTriggersAndBumpers);
	reference_getter(UseModernAimControl);
	reference_getter(UseDoublePressJumpToJetpack);
	reference_getter(EnemyPlayerNameColor);
	reference_getter(GameEngineTimer);
	reference_getter(LoadoutSlots);
	reference_getter(GameSpecific);
	reference_getter(MouseSensitivity);
	reference_getter(MouseSmoothing);
	reference_getter(MouseAcceleration);
	reference_getter(MouseAccelerationMinRate);
	reference_getter(MouseAccelerationMaxAccel);
	reference_getter(MouseAccelerationScale);
	reference_getter(MouseAccelerationExp);
	reference_getter(KeyboardMouseButtonPreset);
	reference_getter(MasterVolume);
	reference_getter(MusicVolume);
	reference_getter(SfxVolume);
	reference_getter(Brightness);
	reference_getter_v4(WeaponDisplayOffsets)

#undef reference_getter

	class c_virtual_player_configuration_game_keyboard_mouse_mapping_interface
	{
	public:
		c_virtual_player_configuration_game_keyboard_mouse_mapping_interface(PlayerConfiguration& parent) :
			parent(parent)
		{ }

		PlayerConfiguration& parent;

		GameKeyboardMouseMapping& operator[](size_t game_action_index) const
		{
			switch (parent.player_configuration_version)
			{
			//case _player_configuration_version_1: return parent.player_configuration_v1.GameKeyboardMouseMappings[game_action_index];
			case _player_configuration_version_2: return parent.player_configuration_v2.GameKeyboardMouseMappings[game_action_index];
			case _player_configuration_version_3: return parent.player_configuration_v3.GameKeyboardMouseMappings[game_action_index];
			case _player_configuration_version_4: return parent.player_configuration_v4.GameKeyboardMouseMappings[game_action_index];
			case _player_configuration_version_5: return parent.player_configuration_v5.GameKeyboardMouseMappings[game_action_index];
			case _player_configuration_version_6: return parent.player_configuration_v6.GameKeyboardMouseMappings[game_action_index];
			}
			throw;
		}
	};

public:
	//c_virtual_player_configuration_loadout_slot_interface LoadoutSlots;
	c_virtual_player_configuration_game_keyboard_mouse_mapping_interface GameKeyboardMouseMappings;

	PlayerConfiguration(e_player_configuration_version player_configuration_version) :
		player_configuration_v1(),
		//player_configuration_v2(),
		//player_configuration_v3(),
		//player_configuration_v4(),
		//player_configuration_v5(),
		//player_configuration_v6(),

		player_configuration_version(player_configuration_version),

		SubtitleSetting(*get_SubtitleSetting()),
		CrosshairLocation(*get_CrosshairLocation()),
		FOVSetting(*get_FOVSetting()),
		VehicleFOVSetting(*get_VehicleFOVSetting()),
		LookControlsInverted(*get_LookControlsInverted()),
		MouseLookControlsInverted(*get_MouseLookControlsInverted()),
		VibrationDisabled(*get_VibrationDisabled()),
		ImpulseTriggersDisabled(*get_ImpulseTriggersDisabled()),
		AircraftControlsInverted(*get_AircraftControlsInverted()),
		MouseAircraftControlsInverted(*get_MouseAircraftControlsInverted()),
		AutoCenterEnabled(*get_AutoCenterEnabled()),
		CrouchLockEnabled(*get_CrouchLockEnabled()),
		MKCrouchLockEnabled(*get_MKCrouchLockEnabled()),
		ClenchProtectionEnabled(*get_ClenchProtectionEnabled()),
		UseFemaleVoice(*get_UseFemaleVoice()),
		HoldToZoom(*get_HoldToZoom()),
		PlayerModelPrimaryColorIndex(*get_PlayerModelPrimaryColorIndex()),
		PlayerModelSecondaryColorIndex(*get_PlayerModelSecondaryColorIndex()),
		PlayerModelTertiaryColorIndex(*get_PlayerModelTertiaryColorIndex()),
		UseEliteModel(*get_UseEliteModel()),
		PlayerModelPermutation(*get_PlayerModelPermutation()),
		HelmetIndex(*get_HelmetIndex()),
		LeftShoulderIndex(*get_LeftShoulderIndex()),
		RightShoulderIndex(*get_RightShoulderIndex()),
		ChestIndex(*get_ChestIndex()),
		WristIndex(*get_WristIndex()),
		UtilityIndex(*get_UtilityIndex()),
		KneeGuardsIndex(*get_KneeGuardsIndex()),
		VisorColorIndex(*get_VisorColorIndex()),
		SpartanArmorEffectIndex(*get_SpartanArmorEffectIndex()),
		SpartanBodyIndex(*get_SpartanBodyIndex()),
		EliteArmorIndex(*get_EliteArmorIndex()),
		EliteArmorEffectIndex(*get_EliteArmorEffectIndex()),
		VoiceIndex(*get_VoiceIndex()),
		PlayerModelPrimaryColor(*get_PlayerModelPrimaryColor()),
		PlayerModelSecondaryColor(*get_PlayerModelSecondaryColor()),
		PlayerModelTertiaryColor(*get_PlayerModelTertiaryColor()),
		ServiceTag(*get_ServiceTag()),
		OnlineMedalFlasher(*get_OnlineMedalFlasher()),
		VerticalLookSensitivity(*get_VerticalLookSensitivity()),
		HorizontalLookSensitivity(*get_HorizontalLookSensitivity()),
		LookAcceleration(*get_LookAcceleration()),
		LookAxialDeadZone(*get_LookAxialDeadZone()),
		LookRadialDeadZone(*get_LookRadialDeadZone()),
		ZoomLookSensitivityMultiplier(*get_ZoomLookSensitivityMultiplier()),
		VehicleLookSensitivityMultiplier(*get_VehicleLookSensitivityMultiplier()),
		ButtonPreset(*get_ButtonPreset()),
		StickPreset(*get_StickPreset()),
		LeftyToggle(*get_LeftyToggle()),
		FlyingCameraTurnSensitivity(*get_FlyingCameraTurnSensitivity()),
		FlyingCameraPanning(*get_FlyingCameraPanning()),
		FlyingCameraSpeed(*get_FlyingCameraSpeed()),
		FlyingCameraThrust(*get_FlyingCameraThrust()),
		TheaterTurnSensitivity(*get_TheaterTurnSensitivity()),
		TheaterPanning(*get_TheaterPanning()),
		TheaterSpeed(*get_TheaterSpeed()),
		TheaterThrust(*get_TheaterThrust()),
		__unknown0(player_configuration_v6.__unknown0),
		SwapTriggersAndBumpers(*get_SwapTriggersAndBumpers()),
		UseModernAimControl(*get_UseModernAimControl()),
		UseDoublePressJumpToJetpack(*get_UseDoublePressJumpToJetpack()),
		EnemyPlayerNameColor(*get_EnemyPlayerNameColor()),
		GameEngineTimer(*get_GameEngineTimer()),
		LoadoutSlots(*get_LoadoutSlots()),
		GameSpecific(*get_GameSpecific()),
		MouseSensitivity(*get_MouseSensitivity()),
		MouseSmoothing(*get_MouseSmoothing()),
		MouseAcceleration(*get_MouseAcceleration()),
		MouseAccelerationMinRate(*get_MouseAccelerationMinRate()),
		MouseAccelerationMaxAccel(*get_MouseAccelerationMaxAccel()),
		MouseAccelerationScale(*get_MouseAccelerationScale()),
		MouseAccelerationExp(*get_MouseAccelerationExp()),
		KeyboardMouseButtonPreset(*get_KeyboardMouseButtonPreset()),
		GameKeyboardMouseMappings(*this),
		MasterVolume(*get_MasterVolume()),
		MusicVolume(*get_MusicVolume()),
		SfxVolume(*get_SfxVolume()),
		Brightness(*get_Brightness()),
		WeaponDisplayOffsets(*get_WeaponDisplayOffsets())
	{
		memset(&player_configuration_v1, 0, sizeof(player_configuration_v1));
		memset(&player_configuration_v2, 0, sizeof(player_configuration_v2));
		memset(&player_configuration_v3, 0, sizeof(player_configuration_v3));
		memset(&player_configuration_v4, 0, sizeof(player_configuration_v4));
		memset(&player_configuration_v5, 0, sizeof(player_configuration_v5));
		memset(&player_configuration_v6, 0, sizeof(player_configuration_v6));
	}
};
