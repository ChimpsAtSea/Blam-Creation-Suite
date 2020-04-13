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

struct PlayerConfiguration
{
	/* 0x0 */	long SubtitleSetting;
	/* 0x4 */	long CrosshairLocation;
	/* 0x8 */	long FOVSetting;
	/* 0xC */	long VehicleFOVSetting;
	/* 0x10 */	bool LookControlsInverted;
	/* 0x11 */	bool MouseLookControlsInverted;
	/* 0x12 */	bool VibrationDisabled;
	/* 0x13 */	bool ImpulseTriggersDisabled;
	/* 0x14 */	bool AircraftControlsInverted;
	/* 0x15 */	bool MouseAircraftControlsInverted;
	/* 0x16 */	bool AutoCenterEnabled;
	/* 0x17 */	bool CrouchLockEnabled;
	/* 0x18 */	bool MKCrouchLockEnabled;
	/* 0x19 */	bool ClenchProtectionEnabled;
	/* 0x1A */	bool UseFemaleVoice;
	/* 0x1B */	bool HoldToZoom;
	/* 0x1C */	long PlayerModelPrimaryColorIndex;
	/* 0x20 */	long PlayerModelSecondaryColorIndex;
	/* 0x24 */	long PlayerModelTertiaryColorIndex;
	/* 0x28 */	bool UseEliteModel;
	/* 0x29 */	char __padding29[3];
	/* 0x2C */	long PlayerModelPermutation;
	/* 0x30 */	eHaloArmor HelmetIndex;
	/* 0x34 */	eHaloArmor LeftShoulderIndex;
	/* 0x38 */	eHaloArmor RightShoulderIndex;
	/* 0x3C */	eHaloArmor ChestIndex;
	/* 0x40 */	eHaloArmor WristIndex;
	/* 0x44 */	eHaloArmor UtilityIndex;
	/* 0x48 */	eHaloArmor KneeGuardsIndex;
	/* 0x4C */	eHaloArmor VisorColorIndex;
	/* 0x50 */	eHaloArmor SpartanArmorEffectIndex;
	/* 0x54 */	eHaloArmor SpartanBodyIndex;
	/* 0x58 */	eHaloArmor EliteArmorIndex;
	/* 0x5C */	eHaloArmor EliteArmorEffectIndex;
	/* 0x60 */	eHaloArmor VoiceIndex;
	/* 0x64 */	eHaloArmor PlayerModelPrimaryColor;
	/* 0x68 */	eHaloArmor PlayerModelSecondaryColor;
	/* 0x6C */	eHaloArmor PlayerModelTertiaryColor;
	/* 0x70 */	wchar_t ServiceTag[4];
	/* 0x78 */	long OnlineMedalFlasher;
	/* 0x7C */	long VerticalLookSensitivity;
	/* 0x80 */	long HorizontalLookSensitivity;
	/* 0x84 */	long LookAcceleration;
	/* 0x88 */	float LookAxialDeadZone;
	/* 0x8C */	float LookRadialDeadZone;
	/* 0x90 */	float ZoomLookSensitivityMultiplier;
	/* 0x94 */	float VehicleLookSensitivityMultiplier;
	/* 0x98 */	long ButtonPreset;
	/* 0x9C */	long StickPreset;
	/* 0xA0 */	long LeftyToggle;
	/* 0xA4 */	long FlyingCameraTurnSensitivity;
	/* 0xA8 */	long FlyingCameraPanning;
	/* 0xAC */	long FlyingCameraSpeed;
	/* 0xB0 */	long FlyingCameraThrust;
	/* 0xB4 */	long TheaterTurnSensitivity;
	/* 0xB8 */	long TheaterPanning;
	/* 0xBC */	long TheaterSpeed;
	/* 0xC0 */	long TheaterThrust;
	/* 0xC4 */	bool SwapTriggersAndBumpers;
	/* 0xC5 */	bool UseModernAimControl;
	/* 0xC6 */	bool UseDoublePressJumpToJetpack;
	/* 0xC7 */	char __paddingC7;
	/* 0xC8 */	char EnemyPlayerNameColor;
	/* 0xC9 */	char GameEngineTimer;
	/* 0xCA */	char __paddingCA[2];
	/* 0xCC */	LoadoutSlot Loadouts[5];
	/* 0x1F8 */	char GameSpecific[256];
	/* 0x2F8 */	float MouseSensitivity;
	/* 0x2FC */	bool MouseSmoothing;
	/* 0x2FD */	bool MouseAcceleration;
	/* 0x2FE */	char __padding2FE[2];
	/* 0x300 */	float MouseAccelerationMinRate;
	/* 0x304 */	float MouseAccelerationMaxAccel;
	/* 0x308 */	float MouseAccelerationScale;
	/* 0x30C */	float MouseAccelerationExp;
	/* 0x310 */	long KeyboardMouseButtonPreset;
	/* 0x314 */	GameKeyboardMouseMapping GameKeyboardMouseMappings[56];
	/* 0x854 */	float MasterVolume;
	/* 0x858 */	float MusicVolume;
	/* 0x85C */	float SfxVolume;
	/* 0x860 */	char __unknown860[16];
	/* 0x870 */	long Brightness;
	/* 0x874 */	RealPoint2D WeaponDisplayOffset[5];
};
CHECK_STRUCTURE_SIZE(PlayerConfiguration, 0x89C);


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

	Count
};