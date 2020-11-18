#pragma once

enum class e_customization_item_v1 : long long
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

	k_customization_item_count,
	k_customization_item_none = -1
};

enum class e_customization_item_v2 : long long
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
	H2A_Color_20,
	H2A_Color_21,
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

	H3_CHEST_BUNGIE,
	H3_CHEST_CQB,
	H3_CHEST_EOD,
	H3_CHEST_EVA,
	H3_CHEST_HAYABUSA,
	H3_CHEST_KATANA,
	H3_CHEST_MARK_VI,
	H3_CHEST_RECON,
	H3_CHEST_SCOUT,

	H3_HELMET_CQB,
	H3_HELMET_EOD,
	H3_HELMET_EVA,
	H3_HELMET_HAYABUSA,
	H3_HELMET_MARK_V,
	H3_HELMET_MARK_VI,
	H3_HELMET_RECON,
	H3_HELMET_ROGUE,
	H3_HELMET_SECURITY,
	H3_HELMET_ODST,
	H3_HELMET_SCOUT,

	H3_LEFT_SHOULDER_CQB,
	H3_LEFT_SHOULDER_EOD,
	H3_LEFT_SHOULDER_EVA,
	H3_LEFT_SHOULDER_HAYABUSA,
	H3_LEFT_SHOULDER_MARK_VI,
	H3_LEFT_SHOULDER_RECON,
	H3_LEFT_SHOULDER_SCOUT,
	H3_LEFT_SHOULDER_SECURITY,

	H3_RIGHT_SHOULDER_CQB,
	H3_RIGHT_SHOULDER_EOD,
	H3_RIGHT_SHOULDER_EVA,
	H3_RIGHT_SHOULDER_HAYABUSA,
	H3_RIGHT_SHOULDER_MARK_VI,
	H3_RIGHT_SHOULDER_RECON,
	H3_RIGHT_SHOULDER_SCOUT,
	H3_RIGHT_SHOULDER_SECURITY,

	H3_chest_ASCETIC,
	H3_helmet_ASCETIC,
	H3_leftShoulder_ASCETIC,
	H3_rightShoulder_ASCETIC,

	H3_chest_ASSAULT,
	H3_helmet_ASSAULT,
	H3_leftShoulder_ASSAULT,
	H3_rightShoulder_ASSAULT,

	H3_helmet_COMBAT,
	H3_leftShoulder_COMBAT,
	H3_rightShoulder_COMBAT,

	H3_chest_COMMANDO,
	H3_helmet_COMMANDO,
	H3_leftShoulder_COMMANDO,
	H3_rightShoulder_COMMANDO,

	H3_chest_FLIGHT,
	H3_helmet_FLIGHT,
	H3_leftShoulder_FLIGHT,
	H3_rightShoulder_FLIGHT,

	H3_COLOR0_STEEL,
	H3_COLOR1_SILVER,
	H3_COLOR2_WHITE,
	H3_COLOR3_RED,
	H3_COLOR4_MAUVE,
	H3_COLOR5_SALMON,
	H3_COLOR6_ORANGE,
	H3_COLOR7_CORAL,
	H3_COLOR8_PEACH,
	H3_COLOR9_GOLD,
	H3_COLOR10_YELLOW,
	H3_COLOR11_PALE,
	H3_COLOR12_SAGE,
	H3_COLOR13_GREEN,
	H3_COLOR14_OLIVE,
	H3_COLOR15_TEAL,
	H3_COLOR16_AQUA,
	H3_COLOR17_CYAN,
	H3_COLOR18_BLUE,
	H3_COLOR19_COBALT,
	H3_COLOR20_SAPHIRE,
	H3_COLOR21_VIOLET,
	H3_COLOR22_ORCHID,
	H3_COLOR23_LAVENDER,
	H3_COLOR24_CRIMSON,
	H3_COLOR25_RUBINE,
	H3_COLOR26_PINK,
	H3_COLOR27_BROWN,
	H3_COLOR28_TAN,
	H3_COLOR29_KHAKI,

	ODST_DUTCH,
	ODST_JOHNSON,
	ODST_MICKEY,
	ODST_RECON,
	ODST_ROMEO,
	ODST_SERGEANT,

	H4_Helmet_Default,
	H4_Helmet_Warrior,
	H4_Helmet_Scout,
	H4_Helmet_Soldier,
	H4_Helmet_Recon,
	H4_Helmet_Breather,
	H4_Helmet_EOD,
	H4_Helmet_Scientist,
	H4_Helmet_Demo,
	H4_Helmet_Orbital,
	H4_Helmet_AirAssault,
	H4_Helmet_Cyclops,
	H4_Helmet_ECM,
	H4_Helmet_Gungnir,
	H4_Helmet_Mongoose,
	H4_Helmet_Optimus,
	H4_Helmet_Triclops,
	H4_Helmet_Unicorn,
	H4_Helmet_Budokan,
	H4_Helmet_Utility,
	H4_Helmet_Pilot,
	H4_Helmet_Stealth,
	H4_Helmet_Commando,
	H4_Helmet_Ninja,
	H4_Helmet_Iron,
	H4_Helmet_Ranger,
	H4_Helmet_Boxhead,
	H4_Helmet_EVA,
	H4_Helmet_Engineer,
	H4_Helmet_Stalker,
	H4_Helmet_Rogue,
	H4_Helmet_Tracker,
	H4_Helmet_Mjolnir,
	H4_Helmet_Gungnir2,
	H4_Helmet_01,
	H4_Helmet_02,
	H4_Helmet_03,
	H4_Helmet_04,
	H4_Helmet_Gungnir_Alt,

	H4_Chest_Default,
	H4_Chest_Warrior,
	H4_Chest_Scout,
	H4_Chest_Soldier,
	H4_Chest_Recon,
	H4_Chest_Breather,
	H4_Chest_EOD,
	H4_Chest_Scientist,
	H4_Chest_Demo,
	H4_Chest_Orbital,
	H4_Chest_AirAssault,
	H4_Chest_Cyclops,
	H4_Chest_ECM,
	H4_Chest_Gungnir,
	H4_Chest_Mongoose,
	H4_Chest_Optimus,
	H4_Chest_Triclops,
	H4_Chest_Unicorn,
	H4_Chest_Budokan,
	H4_Chest_Utility,
	H4_Chest_Pilot,
	H4_Chest_Stealth,
	H4_Chest_Commando,
	H4_Chest_Ninja,
	H4_Chest_Iron,
	H4_Chest_Ranger,
	H4_Chest_Boxhead,
	H4_Chest_EVA,
	H4_Chest_Engineer,
	H4_Chest_Stalker,
	H4_Chest_Mjolnir,
	H4_Chest_Rogue,
	H4_Chest_Tracker,
	H4_Chest_Gungnir2,
	H4_Chest_Gungnir_Alt,

	H4_LeftShoulder_Default,
	H4_LeftShoulder_Warrior,
	H4_LeftShoulder_Scout,
	H4_LeftShoulder_Soldier,
	H4_LeftShoulder_Recon,
	H4_LeftShoulder_Breather,
	H4_LeftShoulder_EOD,
	H4_LeftShoulder_Scientist,
	H4_LeftShoulder_Demo,
	H4_LeftShoulder_Orbital,
	H4_LeftShoulder_AirAssault,
	H4_LeftShoulder_Cyclops,
	H4_LeftShoulder_ECM,
	H4_LeftShoulder_Gungnir,
	H4_LeftShoulder_Mongoose,
	H4_LeftShoulder_Optimus,
	H4_LeftShoulder_Triclops,
	H4_LeftShoulder_Unicorn,
	H4_LeftShoulder_Budokan,
	H4_LeftShoulder_Utility,
	H4_LeftShoulder_Pilot,
	H4_LeftShoulder_Stealth,
	H4_LeftShoulder_Commando,
	H4_LeftShoulder_Ninja,
	H4_LeftShoulder_Iron,
	H4_LeftShoulder_Ranger,
	H4_LeftShoulder_Boxhead,
	H4_LeftShoulder_EVA,
	H4_LeftShoulder_Engineer,
	H4_LeftShoulder_Stalker,
	H4_LeftShoulder_Mjolnir,
	H4_LeftShoulder_Rogue,
	H4_LeftShoulder_Tracker,
	H4_LeftShoulder_Gungnir2,
	H4_LeftShoulder_Gungnir_Alt,

	H4_RightShoulder_Default,
	H4_RightShoulder_Warrior,
	H4_RightShoulder_Scout,
	H4_RightShoulder_Soldier,
	H4_RightShoulder_Recon,
	H4_RightShoulder_Breather,
	H4_RightShoulder_EOD,
	H4_RightShoulder_Scientist,
	H4_RightShoulder_Demo,
	H4_RightShoulder_Orbital,
	H4_RightShoulder_AirAssault,
	H4_RightShoulder_Cyclops,
	H4_RightShoulder_ECM,
	H4_RightShoulder_Gungnir,
	H4_RightShoulder_Mongoose,
	H4_RightShoulder_Optimus,
	H4_RightShoulder_Triclops,
	H4_RightShoulder_Unicorn,
	H4_RightShoulder_Budokan,
	H4_RightShoulder_Utility,
	H4_RightShoulder_Pilot,
	H4_RightShoulder_Stealth,
	H4_RightShoulder_Commando,
	H4_RightShoulder_Ninja,
	H4_RightShoulder_Iron,
	H4_RightShoulder_Ranger,
	H4_RightShoulder_Boxhead,
	H4_RightShoulder_EVA,
	H4_RightShoulder_Engineer,
	H4_RightShoulder_Stalker,
	H4_RightShoulder_Mjolnir,
	H4_RightShoulder_Rogue,
	H4_RightShoulder_Tracker,
	H4_RightShoulder_Gungnir2,
	H4_RightShoulder_Gungnir_Alt,

	H4_Arms_Warrior,
	H4_Arms_Scout,
	H4_Arms_Orbital,
	H4_Arms_Unicorn,
	H4_Arms_Budokan,
	H4_Arms_Pilot,
	H4_Arms_Stealth,
	H4_Arms_Ninja,
	H4_Arms_Mjolnir,
	H4_Arms_Budokan_Alt,

	H4_Legs_Default,
	H4_Legs_Warrior,
	H4_Legs_Scout,
	H4_Legs_ECM,
	H4_Legs_Unicorn,
	H4_Legs_Utility,
	H4_Legs_Stealth,
	H4_Legs_Ninja,
	H4_Legs_Mjolnir,
	H4_Legs_Utility_Alt,

	H4_Male,
	H4_Female,

	H4_Color0_Steel,
	H4_Color1_Silver,
	H4_Color2_White,
	H4_Color3_Brown,
	H4_Color4_Tan,
	H4_Color5_Khaki,
	H4_Color6_Sage,
	H4_Color7_Olive,
	H4_Color8_Drab,
	H4_Color9_Forest,
	H4_Color10_Green,
	H4_Color11_SeaFoam,
	H4_Color12_Teal,
	H4_Color13_Aqua,
	H4_Color14_Cyan,
	H4_Color15_Blue,
	H4_Color16_Cobalt,
	H4_Color17_Ice,
	H4_Color18_Violet,
	H4_Color19_Orchid,
	H4_Color20_Lavender,
	H4_Color21_Maroon,
	H4_Color22_Brick,
	H4_Color23_Rose,
	H4_Color24_Rust,
	H4_Color25_Coral,
	H4_Color26_Peach,
	H4_Color27_Gold,
	H4_Color28_Yellow,

	H1S2_WEAPONSKIN_ASSAULTRIFLEGOLDEN,
	H1S2_WEAPONSKIN_ASSAULTRIFLEDESERT,

	H1S2_VISORCOLOR_BRONZE,
	H1S2_VISORCOLOR_DARKBLUE,
	H1S2_VISORCOLOR_DARKGREEN,
	H1S2_VISORCOLOR_DARKORANGE,
	H1S2_VISORCOLOR_DARKPURPLE,
	H1S2_VISORCOLOR_DARKRED,
	H1S2_VISORCOLOR_DARKYELLOW,
	H1S2_VISORCOLOR_GREEN,
	H1S2_VISORCOLOR_GROOVY,
	H1S2_VISORCOLOR_ONYX,
	H1S2_VISORCOLOR_ORANGE,
	H1S2_VISORCOLOR_PASTELBLUE,
	H1S2_VISORCOLOR_PASTELGREEN,
	H1S2_VISORCOLOR_PASTELORANGE,
	H1S2_VISORCOLOR_PASTELPURPLE,
	H1S2_VISORCOLOR_PASTELRED,
	H1S2_VISORCOLOR_PASTELYELLOW,
	H1S2_VISORCOLOR_PEARLBLUE,
	H1S2_VISORCOLOR_PEARLGREEN,
	H1S2_VISORCOLOR_PEARLORANGE,
	H1S2_VISORCOLOR_PEARLPURPLE,
	H1S2_VISORCOLOR_PEARLRED,
	H1S2_VISORCOLOR_PEARLYELLOW,
	H1S2_VISORCOLOR_PLATINUM,
	H1S2_VISORCOLOR_PURPLE,
	H1S2_VISORCOLOR_RED,
	H1S2_VISORCOLOR_SILVER,
	H1S2_VISORCOLOR_SPECTRUM,
	H1S2_VISORCOLOR_YELLOW,

	k_customization_item_count,
	k_customization_item_none = -1
};

enum class e_customization_item_v3 : long long
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

	H1S2_WS_PISTOL_DEFAULT,
	H1S2_WS_PISTOL_GOLDEN,
	H1S2_WS_PISTOL_WOODLAND,
	H1S2_WS_PISTOL_DESERT,
	H1S2_WS_PISTOL_GREATJOURNEY,
	H1S2_WS_PISTOL_BLACKCHERRY,
	H1S2_WS_PISTOL_HAZARDPAY,
	H1S2_WS_PISTOL_TOYSOLDIER,
	H1S2_WS_ASSAULTRIFLE_DEFAULT,
	H1S2_WS_ASSAULTRIFLE_GOLDEN,
	H1S2_WS_ASSAULTRIFLE_WOODLAND,
	H1S2_WS_ASSAULTRIFLE_DESERT,
	H1S2_WS_ASSAULTRIFLE_GREATJOURNEY,
	H1S2_WS_ASSAULTRIFLE_CORROSION,
	H1S2_WS_ASSAULTRIFLE_SQUIRT,
	H1S2_WS_ASSAULTRIFLE_LUCKYSHOT,
	H1S2_WS_PLASMAPISTOL_DEFAULT,
	H1S2_WS_PLASMAPISTOL_ULTRA,
	H1S2_WS_PLASMAPISTOL_BRUTAL,
	H1S2_WS_PLASMAPISTOL_SCHISM,
	H1S2_WS_PLASMAPISTOL_ZEALOT,
	H1S2_WS_PLASMARIFLE_DEFAULT,
	H1S2_WS_PLASMARIFLE_ULTRA,
	H1S2_WS_PLASMARIFLE_BRUTAL,
	H1S2_WS_PLASMARIFLE_SCHISM,
	H1S2_WS_PLASMARIFLE_ZEALOT,
	H1S2_WS_ROCKETLAUNCHER_DEFAULT,
	H1S2_WS_ROCKETLAUNCHER_HUNTERSBLOOD,
	H1S2_WS_ROCKETLAUNCHER_CORROSION,
	H1S2_WS_ROCKETLAUNCHER_DESERT,
	H1S2_WS_SNIPERRIFLE_DEFAULT,
	H1S2_WS_SNIPERRIFLE_GOLDEN,
	H1S2_WS_SNIPERRIFLE_WOODLAND,
	H1S2_WS_SNIPERRIFLE_DESERT,
	H1S2_WS_SNIPERRIFLE_GREATJOURNEY,
	H1S2_WS_SNIPERRIFLE_AVALANCHE,
	H1S2_WS_SHOTGUN_DEFAULT,
	H1S2_WS_SHOTGUN_GOLDEN,
	H1S2_WS_SHOTGUN_WOODLAND,
	H1S2_WS_SHOTGUN_DESERT,
	H1S2_WS_SHOTGUN_GREATJOURNEY,
	H1S2_WS_SHOTGUN_HUNTERSBLOOD,
	H1S2_WS_NEEDLER_DEFAULT,
	H1S2_WS_NEEDLER_ULTRA,
	H1S2_WS_NEEDLER_BRUTAL,
	H1S2_WS_NEEDLER_SCHISM,
	H1S2_WS_NEEDLER_ZEALOT,
	H1S2_WS_FLAMETHROWER_DEFAULT,
	H1S2_WS_FLAMETHROWER_DEARJOHN,
	H1S2_WS_FLAMETHROWER_WHITEHOT,
	H1S2_WS_FLAMETHROWER_HOTPEPPER,
	H1S2_WS_FUELRODGUN_DEFAULT,
	H1S2_WS_FUELRODGUN_ULTRA,
	H1S2_WS_FUELRODGUN_BRUTAL,
	H1S2_WS_FUELRODGUN_HERETIC,
	H1S2_WS_FUELRODGUN_ZEALOT,

	H1S2_VS_WARTHOG_DEFAULT,
	H1S2_VS_WARTHOG_HOTROD,
	H1S2_VS_WARTHOG_PARKRANGER,
	H1S2_VS_WARTHOG_RALLYHOG,
	H1S2_VS_ROCKETWARTHOG_DEFAULT,
	H1S2_VS_ROCKETWARTHOG_SUPERSTAR,
	H1S2_VS_ROCKETWARTHOG_SHARK,
	H1S2_VS_ROCKETWARTHOG_CLEVERGIRL,
	H1S2_VS_GHOST_DEFAULT,
	H1S2_VS_GHOST_BRUTAL,
	H1S2_VS_GHOST_SCHISM,
	H1S2_VS_GHOST_ZEALOT,
	H1S2_VS_GHOST_ULTRA,
	H1S2_VS_SCORPION_DEFAULT,
	H1S2_VS_SCORPION_BENGAL,
	H1S2_VS_SCORPION_GRIMREAPER,
	H1S2_VS_SCORPION_ARCTIC,
	H1S2_VS_SCORPION_THEPACKAGE,
	H1S2_VS_BANSHEE_DEFAULT,
	H1S2_VS_BANSHEE_BRUTAL,
	H1S2_VS_BANSHEE_SCHISM,
	H1S2_VS_BANSHEE_ZEALOT,
	H1S2_VS_BANSHEE_ULTRA,

	H1S2_VISOR_DEFAULT,
	H1S2_VISOR_BRONZE,
	H1S2_VISOR_SILVER,
	H1S2_VISOR_PLATINUM,
	H1S2_VISOR_OBSIDIAN,
	H1S2_VISOR_TRIPPY,
	H1S2_VISOR_RAINBOW,
	H1S2_VISOR_PURPLE_PASTEL,
	H1S2_VISOR_BLUE_PASTEL,
	H1S2_VISOR_GREEN_PASTEL,
	H1S2_VISOR_YELLOW_PASTEL,
	H1S2_VISOR_ORANGE_PASTEL,
	H1S2_VISOR_RED_PASTEL,
	H1S2_VISOR_DARK_PURPLE,
	H1S2_VISOR_DARK_BLUE,
	H1S2_VISOR_DARK_GREEN,
	H1S2_VISOR_DARK_YELLOW,
	H1S2_VISOR_DARK_ORANGE,
	H1S2_VISOR_DARK_RED,
	H1S2_VISOR_PURPLE,
	H1S2_VISOR_BLUE,
	H1S2_VISOR_GREEN,
	H1S2_VISOR_YELLOW,
	H1S2_VISOR_ORANGE,
	H1S2_VISOR_RED,
	H1S2_VISOR_PEARL_PURPLE,
	H1S2_VISOR_PEARL_BLUE,
	H1S2_VISOR_PEARL_GREEN,
	H1S2_VISOR_PEARL_YELLOW,
	H1S2_VISOR_PEARL_ORANGE,
	H1S2_VISOR_PEARL_RED,

	REFLECTION_BRUTAL,
	REFLECTION_SCHISM,
	REFLECTION_ULTRA,
	REFLECTION_ZEALOT,

	H1S2_WS_PISTOL_DEFAULT_MULTIPURPOSE,
	H1S2_WS_PISTOL_GOLDEN_MULTIPURPOSE,
	H1S2_WS_PISTOL_WOODLAND_MULTIPURPOSE,
	H1S2_WS_PISTOL_DESERT_MULTIPURPOSE,
	H1S2_WS_PISTOL_GREATJOURNEY_MULTIPURPOSE,
	H1S2_WS_PISTOL_BLACKCHERRY_MULTIPURPOSE,
	H1S2_WS_PISTOL_HAZARDPAY_MULTIPURPOSE,
	H1S2_WS_PISTOL_TOYSOLDIER_MULTIPURPOSE,

	H1S2_VS_SCORPION_BENGAL_MULTIPURPOSE,
	H1S2_VS_SCORPION_GRIMREAPER_MULTIPURPOSE,
	H1S2_VS_SCORPION_ARCTIC_MULTIPURPOSE,
	H1S2_VS_SCORPION_THEPACKAGE_MULTIPURPOSE,

	H1S2_WS_FUELRODGUN_FP_DEFAULT,
	H1S2_WS_FUELRODGUN_FP_ULTRA,
	H1S2_WS_FUELRODGUN_FP_BRUTAL,
	H1S2_WS_FUELRODGUN_FP_HERETIC,
	H1S2_WS_FUELRODGUN_FP_ZEALOT,

	H1S2_VS_WARTHOG_TIRES_HOTROD,
	H1S2_VS_WARTHOG_TIRES_PARKRANGER,
	H1S2_VS_WARTHOG_TIRES_RALLYHOG,

	H1S2_VS_ROCKETWARTHOG_TIRES_SUPERSTAR,
	H1S2_VS_ROCKETWARTHOG_TIRES_SHARK,
	H1S2_VS_ROCKETWARTHOG_TIRES_CLEVERGIRL,

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
	H2A_Color_20,
	H2A_Color_21,
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

	Voice_Female,
	Voice_Male,

	H3_CHEST_BUNGIE,
	H3_CHEST_CQB,
	H3_CHEST_EOD,
	H3_CHEST_EVA,
	H3_CHEST_HAYABUSA,
	H3_CHEST_KATANA,
	H3_CHEST_MARK_VI,
	H3_CHEST_RECON,
	H3_CHEST_SCOUT,

	H3_HELMET_CQB,
	H3_HELMET_EOD,
	H3_HELMET_EVA,
	H3_HELMET_HAYABUSA,
	H3_HELMET_MARK_V,
	H3_HELMET_MARK_VI,
	H3_HELMET_RECON,
	H3_HELMET_ROGUE,
	H3_HELMET_SECURITY,
	H3_HELMET_ODST,
	H3_HELMET_SCOUT,

	H3_LEFTSHOULDER_CQB,
	H3_LEFTSHOULDER_EOD,
	H3_LEFTSHOULDER_EVA,
	H3_LEFTSHOULDER_HAYABUSA,
	H3_LEFTSHOULDER_MARK_VI,
	H3_LEFTSHOULDER_RECON,
	H3_LEFTSHOULDER_SCOUT,
	H3_LEFTSHOULDER_SECURITY,

	H3_RIGHTSHOULDER_CQB,
	H3_RIGHTSHOULDER_EOD,
	H3_RIGHTSHOULDER_EVA,
	H3_RIGHTSHOULDER_HAYABUSA,
	H3_RIGHTSHOULDER_MARK_VI,
	H3_RIGHTSHOULDER_RECON,
	H3_RIGHTSHOULDER_SCOUT,
	H3_RIGHTSHOULDER_SECURITY,

	H3_chest_ASCETIC,
	H3_helmet_ASCETIC,
	H3_leftShoulder_ASCETIC,
	H3_rightShoulder_ASCETIC,

	H3_chest_ASSAULT,
	H3_helmet_ASSAULT,
	H3_leftShoulder_ASSAULT,
	H3_rightShoulder_ASSAULT,

	H3_helmet_COMBAT,
	H3_leftShoulder_COMBAT,
	H3_rightShoulder_COMBAT,

	H3_chest_COMMANDO,
	H3_helmet_COMMANDO,
	H3_leftShoulder_COMMANDO,
	H3_rightShoulder_COMMANDO,

	H3_chest_FLIGHT,
	H3_helmet_FLIGHT,
	H3_leftShoulder_FLIGHT,
	H3_rightShoulder_FLIGHT,

	H3_COLOR0_STEEL,
	H3_COLOR1_SILVER,
	H3_COLOR2_WHITE,
	H3_COLOR3_RED,
	H3_COLOR4_MAUVE,
	H3_COLOR5_SALMON,
	H3_COLOR6_ORANGE,
	H3_COLOR7_CORAL,
	H3_COLOR8_PEACH,
	H3_COLOR9_GOLD,
	H3_COLOR10_YELLOW,
	H3_COLOR11_PALE,
	H3_COLOR12_SAGE,
	H3_COLOR13_GREEN,
	H3_COLOR14_OLIVE,
	H3_COLOR15_TEAL,
	H3_COLOR16_AQUA,
	H3_COLOR17_CYAN,
	H3_COLOR18_BLUE,
	H3_COLOR19_COBALT,
	H3_COLOR20_SAPHIRE,
	H3_COLOR21_VIOLET,
	H3_COLOR22_ORCHID,
	H3_COLOR23_LAVENDER,
	H3_COLOR24_CRIMSON,
	H3_COLOR25_RUBINE,
	H3_COLOR26_PINK,
	H3_COLOR27_BROWN,
	H3_COLOR28_TAN,
	H3_COLOR29_KHAKI,

	ODST_DUTCH,
	ODST_JOHNSON,
	ODST_MICKEY,
	ODST_RECON,
	ODST_ROMEO,
	ODST_SERGEANT,

	H4_Helmet_Default,
	H4_Helmet_Warrior,
	H4_Helmet_Scout,
	H4_Helmet_Soldier,
	H4_Helmet_Recon,
	H4_Helmet_Breather,
	H4_Helmet_EOD,
	H4_Helmet_Scientist,
	H4_Helmet_Demo,
	H4_Helmet_Orbital,
	H4_Helmet_AirAssault,
	H4_Helmet_Cyclops,
	H4_Helmet_ECM,
	H4_Helmet_Gungnir,
	H4_Helmet_Mongoose,
	H4_Helmet_Optimus,
	H4_Helmet_Triclops,
	H4_Helmet_Unicorn,
	H4_Helmet_Budokan,
	H4_Helmet_Utility,
	H4_Helmet_Pilot,
	H4_Helmet_Stealth,
	H4_Helmet_Commando,
	H4_Helmet_Ninja,
	H4_Helmet_Iron,
	H4_Helmet_Ranger,
	H4_Helmet_Boxhead,
	H4_Helmet_EVA,
	H4_Helmet_Engineer,
	H4_Helmet_Stalker,
	H4_Helmet_Rogue,
	H4_Helmet_Tracker,
	H4_Helmet_Mjolnir,
	H4_Helmet_Gungnir2,
	H4_Helmet_01,
	H4_Helmet_02,
	H4_Helmet_03,
	H4_Helmet_04,

	H4_Helmet_Gungnir_Alt,
	H4_Chest_Default,
	H4_Chest_Warrior,
	H4_Chest_Scout,
	H4_Chest_Soldier,
	H4_Chest_Recon,
	H4_Chest_Breather,
	H4_Chest_EOD,
	H4_Chest_Scientist,
	H4_Chest_Demo,
	H4_Chest_Orbital,
	H4_Chest_AirAssault,
	H4_Chest_Cyclops,
	H4_Chest_ECM,
	H4_Chest_Gungnir,
	H4_Chest_Mongoose,
	H4_Chest_Optimus,
	H4_Chest_Triclops,
	H4_Chest_Unicorn,
	H4_Chest_Budokan,
	H4_Chest_Utility,
	H4_Chest_Pilot,
	H4_Chest_Stealth,
	H4_Chest_Commando,
	H4_Chest_Ninja,
	H4_Chest_Iron,
	H4_Chest_Ranger,
	H4_Chest_Boxhead,
	H4_Chest_EVA,
	H4_Chest_Engineer,
	H4_Chest_Stalker,
	H4_Chest_Mjolnir,
	H4_Chest_Rogue,
	H4_Chest_Tracker,
	H4_Chest_Gungnir2,
	H4_Chest_Gungnir_Alt,

	H4_LeftShoulder_Default,
	H4_LeftShoulder_Warrior,
	H4_LeftShoulder_Scout,
	H4_LeftShoulder_Soldier,
	H4_LeftShoulder_Recon,
	H4_LeftShoulder_Breather,
	H4_LeftShoulder_EOD,
	H4_LeftShoulder_Scientist,
	H4_LeftShoulder_Demo,
	H4_LeftShoulder_Orbital,
	H4_LeftShoulder_AirAssault,
	H4_LeftShoulder_Cyclops,
	H4_LeftShoulder_ECM,
	H4_LeftShoulder_Gungnir,
	H4_LeftShoulder_Mongoose,
	H4_LeftShoulder_Optimus,
	H4_LeftShoulder_Triclops,
	H4_LeftShoulder_Unicorn,
	H4_LeftShoulder_Budokan,
	H4_LeftShoulder_Utility,
	H4_LeftShoulder_Pilot,
	H4_LeftShoulder_Stealth,
	H4_LeftShoulder_Commando,
	H4_LeftShoulder_Ninja,
	H4_LeftShoulder_Iron,
	H4_LeftShoulder_Ranger,
	H4_LeftShoulder_Boxhead,
	H4_LeftShoulder_EVA,
	H4_LeftShoulder_Engineer,
	H4_LeftShoulder_Stalker,
	H4_LeftShoulder_Mjolnir,
	H4_LeftShoulder_Rogue,
	H4_LeftShoulder_Tracker,
	H4_LeftShoulder_Gungnir2,
	H4_LeftShoulder_Gungnir_Alt,

	H4_RightShoulder_Default,
	H4_RightShoulder_Warrior,
	H4_RightShoulder_Scout,
	H4_RightShoulder_Soldier,
	H4_RightShoulder_Recon,
	H4_RightShoulder_Breather,
	H4_RightShoulder_EOD,
	H4_RightShoulder_Scientist,
	H4_RightShoulder_Demo,
	H4_RightShoulder_Orbital,
	H4_RightShoulder_AirAssault,
	H4_RightShoulder_Cyclops,
	H4_RightShoulder_ECM,
	H4_RightShoulder_Gungnir,
	H4_RightShoulder_Mongoose,
	H4_RightShoulder_Optimus,
	H4_RightShoulder_Triclops,
	H4_RightShoulder_Unicorn,
	H4_RightShoulder_Budokan,
	H4_RightShoulder_Utility,
	H4_RightShoulder_Pilot,
	H4_RightShoulder_Stealth,
	H4_RightShoulder_Commando,
	H4_RightShoulder_Ninja,
	H4_RightShoulder_Iron,
	H4_RightShoulder_Ranger,
	H4_RightShoulder_Boxhead,
	H4_RightShoulder_EVA,
	H4_RightShoulder_Engineer,
	H4_RightShoulder_Stalker,
	H4_RightShoulder_Mjolnir,
	H4_RightShoulder_Rogue,
	H4_RightShoulder_Tracker,
	H4_RightShoulder_Gungnir2,
	H4_RightShoulder_Gungnir_Alt,

	H4_Arms_Warrior,
	H4_Arms_Scout,
	H4_Arms_Orbital,
	H4_Arms_Unicorn,
	H4_Arms_Budokan,
	H4_Arms_Pilot,
	H4_Arms_Stealth,
	H4_Arms_Ninja,
	H4_Arms_Mjolnir,
	H4_Arms_Budokan_Alt,
	H4_Legs_Default,
	H4_Legs_Warrior,
	H4_Legs_Scout,
	H4_Legs_ECM,
	H4_Legs_Unicorn,
	H4_Legs_Utility,
	H4_Legs_Stealth,
	H4_Legs_Ninja,
	H4_Legs_Mjolnir,
	H4_Legs_Utility_Alt,

	H4_Male,
	H4_Female,

	H4_Color0_Steel,
	H4_Color1_Silver,
	H4_Color2_White,
	H4_Color3_Brown,
	H4_Color4_Tan,
	H4_Color5_Khaki,
	H4_Color6_Sage,
	H4_Color7_Olive,
	H4_Color8_Drab,
	H4_Color9_Forest,
	H4_Color10_Green,
	H4_Color11_SeaFoam,
	H4_Color12_Teal,
	H4_Color13_Aqua,
	H4_Color14_Cyan,
	H4_Color15_Blue,
	H4_Color16_Cobalt,
	H4_Color17_Ice,
	H4_Color18_Violet,
	H4_Color19_Orchid,
	H4_Color20_Lavender,
	H4_Color21_Maroon,
	H4_Color22_Brick,
	H4_Color23_Rose,
	H4_Color24_Rust,
	H4_Color25_Coral,
	H4_Color26_Peach,
	H4_Color27_Gold,
	H4_Color28_Yellow,

	k_customization_item_count,
	k_customization_item_none = -1
};

enum class e_customization_item_v4 : long long
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

	H1S2_WS_PISTOL_DEFAULT,
	H1S2_WS_PISTOL_GOLDEN,
	H1S2_WS_PISTOL_WOODLAND,
	H1S2_WS_PISTOL_DESERT,
	H1S2_WS_PISTOL_GREATJOURNEY,
	H1S2_WS_PISTOL_BLACKCHERRY,
	H1S2_WS_PISTOL_HAZARDPAY,
	H1S2_WS_PISTOL_TOYSOLDIER,
	H1S2_WS_ASSAULTRIFLE_DEFAULT,
	H1S2_WS_ASSAULTRIFLE_GOLDEN,
	H1S2_WS_ASSAULTRIFLE_WOODLAND,
	H1S2_WS_ASSAULTRIFLE_DESERT,
	H1S2_WS_ASSAULTRIFLE_GREATJOURNEY,
	H1S2_WS_ASSAULTRIFLE_CORROSION,
	H1S2_WS_ASSAULTRIFLE_SQUIRT,
	H1S2_WS_ASSAULTRIFLE_LUCKYSHOT,
	H1S2_WS_PLASMAPISTOL_DEFAULT,
	H1S2_WS_PLASMAPISTOL_ULTRA,
	H1S2_WS_PLASMAPISTOL_BRUTAL,
	H1S2_WS_PLASMAPISTOL_SCHISM,
	H1S2_WS_PLASMAPISTOL_ZEALOT,
	H1S2_WS_PLASMARIFLE_DEFAULT,
	H1S2_WS_PLASMARIFLE_ULTRA,
	H1S2_WS_PLASMARIFLE_BRUTAL,
	H1S2_WS_PLASMARIFLE_SCHISM,
	H1S2_WS_PLASMARIFLE_ZEALOT,
	H1S2_WS_ROCKETLAUNCHER_DEFAULT,
	H1S2_WS_ROCKETLAUNCHER_HUNTERSBLOOD,
	H1S2_WS_ROCKETLAUNCHER_CORROSION,
	H1S2_WS_ROCKETLAUNCHER_DESERT,
	H1S2_WS_SNIPERRIFLE_DEFAULT,
	H1S2_WS_SNIPERRIFLE_GOLDEN,
	H1S2_WS_SNIPERRIFLE_WOODLAND,
	H1S2_WS_SNIPERRIFLE_DESERT,
	H1S2_WS_SNIPERRIFLE_GREATJOURNEY,
	H1S2_WS_SNIPERRIFLE_AVALANCHE,
	H1S2_WS_SHOTGUN_DEFAULT,
	H1S2_WS_SHOTGUN_GOLDEN,
	H1S2_WS_SHOTGUN_WOODLAND,
	H1S2_WS_SHOTGUN_DESERT,
	H1S2_WS_SHOTGUN_GREATJOURNEY,
	H1S2_WS_SHOTGUN_HUNTERSBLOOD,
	H1S2_WS_NEEDLER_DEFAULT,
	H1S2_WS_NEEDLER_ULTRA,
	H1S2_WS_NEEDLER_BRUTAL,
	H1S2_WS_NEEDLER_SCHISM,
	H1S2_WS_NEEDLER_ZEALOT,
	H1S2_WS_FLAMETHROWER_DEFAULT,
	H1S2_WS_FLAMETHROWER_DEARJOHN,
	H1S2_WS_FLAMETHROWER_WHITEHOT,
	H1S2_WS_FLAMETHROWER_HOTPEPPER,
	H1S2_WS_FUELRODGUN_DEFAULT,
	H1S2_WS_FUELRODGUN_ULTRA,
	H1S2_WS_FUELRODGUN_BRUTAL,
	H1S2_WS_FUELRODGUN_HERETIC,
	H1S2_WS_FUELRODGUN_ZEALOT,

	H1S2_VS_WARTHOG_DEFAULT,
	H1S2_VS_WARTHOG_HOTROD,
	H1S2_VS_WARTHOG_PARKRANGER,
	H1S2_VS_WARTHOG_RALLYHOG,
	H1S2_VS_ROCKETWARTHOG_DEFAULT,
	H1S2_VS_ROCKETWARTHOG_SUPERSTAR,
	H1S2_VS_ROCKETWARTHOG_SHARK,
	H1S2_VS_ROCKETWARTHOG_CLEVERGIRL,
	H1S2_VS_GHOST_DEFAULT,
	H1S2_VS_GHOST_BRUTAL,
	H1S2_VS_GHOST_SCHISM,
	H1S2_VS_GHOST_ZEALOT,
	H1S2_VS_GHOST_ULTRA,
	H1S2_VS_SCORPION_DEFAULT,
	H1S2_VS_SCORPION_BENGAL,
	H1S2_VS_SCORPION_GRIMREAPER,
	H1S2_VS_SCORPION_ARCTIC,
	H1S2_VS_SCORPION_THEPACKAGE,
	H1S2_VS_BANSHEE_DEFAULT,
	H1S2_VS_BANSHEE_BRUTAL,
	H1S2_VS_BANSHEE_SCHISM,
	H1S2_VS_BANSHEE_ZEALOT,
	H1S2_VS_BANSHEE_ULTRA,

	H1S2_VISOR_DEFAULT,
	H1S2_VISOR_BRONZE,
	H1S2_VISOR_SILVER,
	H1S2_VISOR_PLATINUM,
	H1S2_VISOR_OBSIDIAN,
	H1S2_VISOR_TRIPPY,
	H1S2_VISOR_RAINBOW,
	H1S2_VISOR_PURPLE_PASTEL,
	H1S2_VISOR_BLUE_PASTEL,
	H1S2_VISOR_GREEN_PASTEL,
	H1S2_VISOR_YELLOW_PASTEL,
	H1S2_VISOR_ORANGE_PASTEL,
	H1S2_VISOR_RED_PASTEL,
	H1S2_VISOR_DARK_PURPLE,
	H1S2_VISOR_DARK_BLUE,
	H1S2_VISOR_DARK_GREEN,
	H1S2_VISOR_DARK_YELLOW,
	H1S2_VISOR_DARK_ORANGE,
	H1S2_VISOR_DARK_RED,
	H1S2_VISOR_PURPLE,
	H1S2_VISOR_BLUE,
	H1S2_VISOR_GREEN,
	H1S2_VISOR_YELLOW,
	H1S2_VISOR_ORANGE,
	H1S2_VISOR_RED,
	H1S2_VISOR_PEARL_PURPLE,
	H1S2_VISOR_PEARL_BLUE,
	H1S2_VISOR_PEARL_GREEN,
	H1S2_VISOR_PEARL_YELLOW,
	H1S2_VISOR_PEARL_ORANGE,
	H1S2_VISOR_PEARL_RED,

	REFLECTION_BRUTAL,
	REFLECTION_SCHISM,
	REFLECTION_ULTRA,
	REFLECTION_ZEALOT,

	H1S2_WS_PISTOL_DEFAULT_MULTIPURPOSE,
	H1S2_WS_PISTOL_GOLDEN_MULTIPURPOSE,
	H1S2_WS_PISTOL_WOODLAND_MULTIPURPOSE,
	H1S2_WS_PISTOL_DESERT_MULTIPURPOSE,
	H1S2_WS_PISTOL_GREATJOURNEY_MULTIPURPOSE,
	H1S2_WS_PISTOL_BLACKCHERRY_MULTIPURPOSE,
	H1S2_WS_PISTOL_HAZARDPAY_MULTIPURPOSE,
	H1S2_WS_PISTOL_TOYSOLDIER_MULTIPURPOSE,

	H1S2_VS_SCORPION_BENGAL_MULTIPURPOSE,
	H1S2_VS_SCORPION_GRIMREAPER_MULTIPURPOSE,
	H1S2_VS_SCORPION_ARCTIC_MULTIPURPOSE,
	H1S2_VS_SCORPION_THEPACKAGE_MULTIPURPOSE,

	H1S2_WS_FUELRODGUN_FP_DEFAULT,
	H1S2_WS_FUELRODGUN_FP_ULTRA,
	H1S2_WS_FUELRODGUN_FP_BRUTAL,
	H1S2_WS_FUELRODGUN_FP_HERETIC,
	H1S2_WS_FUELRODGUN_FP_ZEALOT,

	H1S2_VS_WARTHOG_TIRES_HOTROD,
	H1S2_VS_WARTHOG_TIRES_PARKRANGER,
	H1S2_VS_WARTHOG_TIRES_RALLYHOG,
	H1S2_VS_ROCKETWARTHOG_TIRES_SUPERSTAR,
	H1S2_VS_ROCKETWARTHOG_TIRES_SHARK,
	H1S2_VS_ROCKETWARTHOG_TIRES_CLEVERGIRL,

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
	H2A_Color_20,
	H2A_Color_21,
	H2A_Color_22,
	H2A_Color_23,
	H2A_Color_24,
	H2A_Color_25,
	H2A_Color_26,
	H2A_Color_27,
	H2A_Color_28,
	H2A_Color_29,

	H2A_Spartan_Arms_VAR1,
	H2A_Spartan_Arms_VAR2,
	H2A_Spartan_Arms_VAR3,

	H2A_Spartan_Chest_VAR1,
	H2A_Spartan_Chest_VAR2,
	H2A_Spartan_Chest_VAR3,

	H2A_Spartan_Helmet_VAR1,
	H2A_Spartan_Helmet_VAR2,
	H2A_Spartan_Helmet_VAR3,

	H2A_Spartan_LeftShoulder_VAR1,
	H2A_Spartan_LeftShoulder_VAR2,
	H2A_Spartan_LeftShoulder_VAR3,

	H2A_Spartan_Legs_VAR1,
	H2A_Spartan_Legs_VAR2,
	H2A_Spartan_Legs_VAR3,

	H2A_Spartan_RightShoulder_VAR1,
	H2A_Spartan_RightShoulder_VAR2,
	H2A_Spartan_RightShoulder_VAR3,

	H2A_Elite_Arms_VAR1,
	H2A_Elite_Arms_VAR2,
	H2A_Elite_Arms_VAR3,

	H2A_Elite_Chest_VAR1,
	H2A_Elite_Chest_VAR2,
	H2A_Elite_Chest_VAR3,

	H2A_Elite_Helmet_VAR1,
	H2A_Elite_Helmet_VAR2,
	H2A_Elite_Helmet_VAR3,

	H2A_Elite_Legs_VAR1,
	H2A_Elite_Legs_VAR2,
	H2A_Elite_Legs_VAR3,

	H2A_VisorColor_Default,
	H2A_VisorColor_Visor2,
	H2A_VisorColor_Visor3,
	H2A_VisorColor_Visor4,
	H2A_VisorColor_Visor5,
	H2A_VisorColor_Visor6,
	H2A_VisorColor_Visor7,
	H2A_VisorColor_Visor8,
	H2A_VisorColor_Visor9,
	H2A_VisorColor_Wetwork,
	H2A_VisorColor_Operator,
	H2A_VisorColor_Pioneer,
	H2A_VisorColor_Pathfinder,
	H2A_VisorColor_Engineer,
	H2A_VisorColor_Stalker,
	H2A_VisorColor_Rogue,
	H2A_VisorColor_Tracker,

	Voice_Female,
	Voice_Male,

	H3_CHEST_BUNGIE,
	H3_CHEST_CQB,
	H3_CHEST_EOD,
	H3_CHEST_EVA,
	H3_CHEST_HAYABUSA,
	H3_CHEST_KATANA,
	H3_CHEST_MARK_VI,
	H3_CHEST_RECON,
	H3_CHEST_SCOUT,
	H3_CHEST_SECURITY,

	H3_HELMET_CQB,
	H3_HELMET_EOD,
	H3_HELMET_EVA,
	H3_HELMET_HAYABUSA,
	H3_HELMET_MARK_V,
	H3_HELMET_MARK_VI,
	H3_HELMET_RECON,
	H3_HELMET_ROGUE,
	H3_HELMET_SECURITY,
	H3_HELMET_ODST,
	H3_HELMET_SCOUT,

	H3_LEFTSHOULDER_CQB,
	H3_LEFTSHOULDER_EOD,
	H3_LEFTSHOULDER_EVA,
	H3_LEFTSHOULDER_HAYABUSA,
	H3_LEFTSHOULDER_MARK_VI,
	H3_LEFTSHOULDER_RECON,
	H3_LEFTSHOULDER_SCOUT,
	H3_LEFTSHOULDER_SECURITY,

	H3_RIGHTSHOULDER_CQB,
	H3_RIGHTSHOULDER_EOD,
	H3_RIGHTSHOULDER_EVA,
	H3_RIGHTSHOULDER_HAYABUSA,
	H3_RIGHTSHOULDER_MARK_VI,
	H3_RIGHTSHOULDER_RECON,
	H3_RIGHTSHOULDER_SCOUT,
	H3_RIGHTSHOULDER_SECURITY,

	H3_chest_ASCETIC,
	H3_helmet_ASCETIC,
	H3_leftShoulder_ASCETIC,
	H3_rightShoulder_ASCETIC,

	H3_chest_ASSAULT,
	H3_helmet_ASSAULT,
	H3_leftShoulder_ASSAULT,
	H3_rightShoulder_ASSAULT,

	H3_helmet_COMBAT,
	H3_leftShoulder_COMBAT,
	H3_rightShoulder_COMBAT,

	H3_chest_COMMANDO,
	H3_helmet_COMMANDO,
	H3_leftShoulder_COMMANDO,
	H3_rightShoulder_COMMANDO,

	H3_chest_FLIGHT,
	H3_helmet_FLIGHT,
	H3_leftShoulder_FLIGHT,
	H3_rightShoulder_FLIGHT,

	H3_COLOR0_STEEL,
	H3_COLOR1_SILVER,
	H3_COLOR2_WHITE,
	H3_COLOR3_RED,
	H3_COLOR4_MAUVE,
	H3_COLOR5_SALMON,
	H3_COLOR6_ORANGE,
	H3_COLOR7_CORAL,
	H3_COLOR8_PEACH,
	H3_COLOR9_GOLD,
	H3_COLOR10_YELLOW,
	H3_COLOR11_PALE,
	H3_COLOR12_SAGE,
	H3_COLOR13_GREEN,
	H3_COLOR14_OLIVE,
	H3_COLOR15_TEAL,
	H3_COLOR16_AQUA,
	H3_COLOR17_CYAN,
	H3_COLOR18_BLUE,
	H3_COLOR19_COBALT,
	H3_COLOR20_SAPHIRE,
	H3_COLOR21_VIOLET,
	H3_COLOR22_ORCHID,
	H3_COLOR23_LAVENDER,
	H3_COLOR24_CRIMSON,
	H3_COLOR25_RUBINE,
	H3_COLOR26_PINK,
	H3_COLOR27_BROWN,
	H3_COLOR28_TAN,
	H3_COLOR29_KHAKI,

	H3S3_WS_SNIPERRIFLE_DEFAULT,
	H3S3_WS_SNIPERRIFLE_GOLDPLATE,
	H3S3_WS_SNIPERRIFLE_GLACIERCAMO,
	H3S3_WS_SNIPERRIFLE_GREENCAMO,
	H3S3_WS_SNIPERRIFLE_DESERTTAN,
	H3S3_WS_MAGNUM_DEFAULT,
	H3S3_WS_MAGNUM_GOLDPLATE,
	H3S3_WS_MAGNUM_DINOBITE,
	H3S3_WS_MAGNUM_ORANGE,
	H3S3_WS_MAGNUM_WORNOUTUNBLUE,
	H3S3_WS_ASSAULTRIFLE_DEFAULT,
	H3S3_WS_ASSAULTRIFLE_GOLDPLATE,
	H3S3_WS_ASSAULTRIFLE_WASTELANDRUST,
	H3S3_WS_ASSAULTRIFLE_GREENCAMO,
	H3S3_WS_ASSAULTRIFLE_SUPERSQUIRT,
	H3S4_WS_SHOTGUN_DEFAULT,
	H3S4_WS_SHOTGUN_GOLDPLATE,
	H3S4_WS_SHOTGUN_GREENCAMO,
	H3S4_WS_SHOTGUN_SAFETYORANGE,
	H3S4_WS_BATTLERIFLE_DEFAULT,
	H3S4_WS_BATTLERIFLE_FERNSTENCIL,
	H3S4_WS_BATTLERIFLE_MEANSTREETSOFNEW,
	H3S4_WS_BATTLERIFLE_CAMOCOOL,
	H3S4_WS_BATTLERIFLE_WORNOUTREDHAZARD,
	H3S4_WS_ROCKETLAUNCHER_DEFAULT,
	H3S4_WS_ROCKETLAUNCHER_SAFETYORANGE,
	H3S4_WS_ROCKETLAUNCHER_WASTERLANDRUST,
	H3S4_WS_SMG_DEFAULT,
	H3S4_WS_SMG_DIGITALCAMOWARM,
	H3S4_WS_SMG_TIGERSTRIPES,
	H3S4_WS_SMG_ROCKNROLL,
	H3S4_WS_PLASMAPISTOL_DEFAULT,
	H3S4_WS_PLASMAPISTOL_COVENANTYELLOW,
	H3S4_WS_PLASMARIFLE_DEFAULT,
	H3S4_WS_PLASMARIFLE_DEFECTORGREEN,
	H3S4_WS_NEEDLER_DEFAULT,
	H3S4_WS_NEEDLER_COVENANTYELLOW,
	H3S4_WS_FLAMETHROWER_DEFAULT,
	H3S4_WS_FLAMETHROWER_LAWNMOWERYELLOWANDGREEN,
	H3S4_WS_FLAMETHROWER_REDHOTPEPPER,
	H3S4_WS_FUELRODGUN_DEFAULT,
	H3S4_WS_FUELRODGUN_BANISHEDRED,

	H3_VISOR_DEFAULT,
	H3_VISOR_BRONZE,
	H3_VISOR_SILVER,
	H3_VISOR_PLATINUM,
	H3_VISOR_OBSIDIAN,
	H3_VISOR_TRIPPY,
	H3_VISOR_RAINBOW,
	H3_VISOR_PURPLE_PASTEL,
	H3_VISOR_BLUE_PASTEL,
	H3_VISOR_GREEN_PASTEL,
	H3_VISOR_YELLOW_PASTEL,
	H3_VISOR_ORANGE_PASTEL,
	H3_VISOR_RED_PASTEL,
	H3_VISOR_DARK_PURPLE,
	H3_VISOR_DARK_BLUE,
	H3_VISOR_DARK_GREEN,
	H3_VISOR_DARK_YELLOW,
	H3_VISOR_DARK_ORANGE,
	H3_VISOR_DARK_RED,
	H3_VISOR_PURPLE,
	H3_VISOR_BLUE,
	H3_VISOR_GREEN,
	H3_VISOR_YELLOW,
	H3_VISOR_ORANGE,
	H3_VISOR_RED,
	H3_VISOR_PEARL_PURPLE,
	H3_VISOR_PEARL_BLUE,
	H3_VISOR_PEARL_GREEN,
	H3_VISOR_PEARL_YELLOW,
	H3_VISOR_PEARL_ORANGE,
	H3_VISOR_PEARL_RED,

	ODST_NONE,
	ODST_ROOKIE,
	ODST_BUCK,
	ODST_BUCK_BUGSPLATTERED,
	ODST_DARE,
	ODST_DUTCH,
	ODST_JOHNSON,
	ODST_MICKEY,
	ODST_ROMEO,
	ODST_ROMEO_INJURED,
	ODST_NONE_WITH_HELMET,
	ODST_ROOKIE_WITH_HELMET,
	ODST_BUCK_WITH_HELMET,
	ODST_BUCK_BUGSPLATTERED_WITH_HELMET,
	ODST_DARE_WITH_HELMET,
	ODST_DUTCH_WITH_HELMET,
	ODST_JOHNSON_WITH_HELMET,
	ODST_MICKEY_WITH_HELMET,
	ODST_ROMEO_WITH_HELMET,
	ODST_ROMEO_INJURED_WITH_HELMET,

	ODST_COLOR_BLACK,
	ODST_COLOR_GRAY,
	ODST_COLOR_SNOW,
	ODST_COLOR_MAROON,
	ODST_COLOR_BRICK,
	ODST_COLOR_ROSE,
	ODST_COLOR_BROWN,
	ODST_COLOR_WOODLAND,
	ODST_COLOR_COCOA,
	ODST_COLOR_TAN,
	ODST_COLOR_KHAKI,
	ODST_COLOR_DESERT,
	ODST_COLOR_CORAL,
	ODST_COLOR_GOLD,
	ODST_COLOR_SAND,
	ODST_COLOR_SAGE,
	ODST_COLOR_OLIVE,
	ODST_COLOR_DRAB,
	ODST_COLOR_FOREST,
	ODST_COLOR_GREEN,
	ODST_COLOR_SEA_FOAM,
	ODST_COLOR_TEAL,
	ODST_COLOR_AQUA,
	ODST_COLOR_CYAN,
	ODST_COLOR_BLUE,
	ODST_COLOR_COBALT,
	ODST_COLOR_ICE,
	ODST_COLOR_VIOLET,
	ODST_COLOR_LAVENDER,
	ODST_COLOR_PINK,

	H4_Helmet_Spartan_IV,
	H4_Helmet_Warrior,
	H4_Helmet_Scout,
	H4_Helmet_Soldier,
	H4_Helmet_Recon,
	H4_Helmet_Breather,
	H4_Helmet_EOD,
	H4_Helmet_Scientist,
	H4_Helmet_Demo,
	H4_Helmet_Orbital,
	H4_Helmet_Air_Assault,
	H4_Helmet_Cyclops,
	H4_Helmet_ECM,
	H4_Helmet_Gungnir1,
	H4_Helmet_Mongoose,
	H4_Helmet_Optimus,
	H4_Helmet_Triclops,
	H4_Helmet_Unicorn,
	H4_Helmet_Budokan,
	H4_Helmet_Utility,
	H4_Helmet_Pilot,
	H4_Helmet_Stealth,
	H4_Helmet_Commando,
	H4_Helmet_Ninja,
	H4_Helmet_Iron,
	H4_Helmet_Ranger,
	H4_Helmet_Boxhead,
	H4_Helmet_EVA,
	H4_Helmet_Engineer,
	H4_Helmet_Stalker,
	H4_Helmet_Rogue,
	H4_Helmet_Tracker,
	H4_Helmet_Mjolnir,
	H4_Helmet_Gungnir2,
	H4_Helmet_Helmet01,
	H4_Helmet_Helmet02,
	H4_Helmet_Helmet03,
	H4_Helmet_Helmet04,
	H4_Helmet_Air_Assault_Slither,
	H4_Helmet_Breather_Forest,
	H4_Helmet_Budokan_Circuit,
	H4_Helmet_Cyclops_Traffic,
	H4_Helmet_Demo_Kabuki,
	H4_Helmet_ECM_Calligraphy,
	H4_Helmet_Engineer_Tribal,
	H4_Helmet_EOD_Berserker,
	H4_Helmet_Gungnir1_Target,
	H4_Helmet_Mongoose_Terrain,
	H4_Helmet_Ninja_Chevron,
	H4_Helmet_Optimus_Fly,
	H4_Helmet_Orbital_Ancient,
	H4_Helmet_Ranger_DigitalCammo,
	H4_Helmet_Recon_Lizard,
	H4_Helmet_Scientist_Frog,
	H4_Helmet_Scout_Propeller,
	H4_Helmet_Soldier_Chevron,
	H4_Helmet_Warrior_Bubbles,
	H4_Helmet_Stalker_Octopus,
	H4_Helmet_Tracker_Drive,
	H4_Helmet_Triclops_Arachnid,
	H4_Helmet_Commando_Claw,
	H4_Helmet_EVA_Yield,
	H4_Helmet_Gungnir2_Sand,
	H4_Helmet_Iron_Dragonfly,
	H4_Helmet_Stealth_Raptor,
	H4_Helmet_Utility_Strike,
	H4_Helmet_Boxhead_Pathfinder,
	H4_Helmet_Pilot_Curves,
	H4_Helmet_Rogue_Glyph,
	H4_Helmet_Spartan_IV_Prime,
	H4_Helmet_DE_Air_Assault_A,
	H4_Helmet_DE_Budokan_A,
	H4_Helmet_DE_Demo_A,
	H4_Helmet_DE_ECM_B,
	H4_Helmet_DE_Orbital_C,
	H4_Helmet_DE_Stealth_A,
	H4_Helmet_DE_Triclops_B,
	H4_Helmet_DE_Utility_A,
	H4_Helmet_Ruin,
	H4_Helmet_Toxic,
	H4_Helmet_Refractive,
	H4_Helmet_DE_MarkV,
	H4_Helmet_DE_ODST,
	H4_Helmet_DE_Forerunner,
	H4_Helmet_DE_NFL,
	H4_Helmet_DE_NFL_Alt,

	H4_Chest_Spartan_IV,
	H4_Chest_Warrior,
	H4_Chest_Scout,
	H4_Chest_Soldier,
	H4_Chest_Recon,
	H4_Chest_Breather,
	H4_Chest_EOD,
	H4_Chest_Scientist,
	H4_Chest_Demo,
	H4_Chest_Orbital,
	H4_Chest_Air_Assault,
	H4_Chest_Cyclops,
	H4_Chest_ECM,
	H4_Chest_Gungnir1,
	H4_Chest_Mongoose,
	H4_Chest_Optimus,
	H4_Chest_Triclops,
	H4_Chest_Unicorn,
	H4_Chest_Budokan,
	H4_Chest_Utility,
	H4_Chest_Pilot,
	H4_Chest_Stealth,
	H4_Chest_Commando,
	H4_Chest_Ninja,
	H4_Chest_Iron,
	H4_Chest_Ranger,
	H4_Chest_Boxhead,
	H4_Chest_EVA,
	H4_Chest_Engineer,
	H4_Chest_Stalker,
	H4_Chest_Mjolnir,
	H4_Chest_Rogue,
	H4_Chest_Tracker,
	H4_Chest_Gungnir2,
	H4_Chest_Air_Assault_Slither,
	H4_Chest_Breather_Forest,
	H4_Chest_Budokan_Circuit,
	H4_Chest_Cyclops_Traffic,
	H4_Chest_Demo_Kabuki,
	H4_Chest_ECM_Calligraphy,
	H4_Chest_Engineer_Tribal,
	H4_Chest_EOD_Berserker,
	H4_Chest_Gungnir1_Target,
	H4_Chest_Mongoose_Terrain,
	H4_Chest_Ninja_Chevron,
	H4_Chest_Optimus_Fly,
	H4_Chest_Orbital_Ancient,
	H4_Chest_Ranger_DigitalCammo,
	H4_Chest_Recon_Lizard,
	H4_Chest_Scientist_Frog,
	H4_Chest_Scout_Propeller,
	H4_Chest_Soldier_Chevron,
	H4_Chest_Warrior_Bubbles,
	H4_Chest_Stalker_Octopus,
	H4_Chest_Tracker_Drive,
	H4_Chest_Triclops_Arachnid,
	H4_Chest_Boxhead_Pathfinder,
	H4_Chest_Commando_Claw,
	H4_Chest_EVA_Yield,
	H4_Chest_Gungnir2_Sand,
	H4_Chest_Iron_Dragonfly,
	H4_Chest_Stealth_Raptor,
	H4_Chest_Utility_Strike,
	H4_Chest_Pilot_Curves,
	H4_Chest_Rogue_Glyph,
	H4_Chest_Spartan_IV_Prime,
	H4_Chest_DE_Air_Assault_A,
	H4_Chest_DE_Budokan_A,
	H4_Chest_DE_Demo_A,
	H4_Chest_DE_ECM_B,
	H4_Chest_DE_Orbital_C,
	H4_Chest_DE_Stealth_A,
	H4_Chest_DE_Triclops_B,
	H4_Chest_DE_Utility_A,
	H4_Chest_Ruin,
	H4_Chest_Toxic,
	H4_Chest_Refractive,
	H4_Chest_DE_MarkV,
	H4_Chest_DE_ODST,
	H4_Chest_DE_Forerunner,
	H4_Chest_DE_NFL,

	H4_LeftShoulder_Spartan_IV,
	H4_LeftShoulder_Warrior,
	H4_LeftShoulder_Scout,
	H4_LeftShoulder_Soldier,
	H4_LeftShoulder_Recon,
	H4_LeftShoulder_Breather,
	H4_LeftShoulder_EOD,
	H4_LeftShoulder_Scientist,
	H4_LeftShoulder_Demo,
	H4_LeftShoulder_Orbital,
	H4_LeftShoulder_Air_Assault,
	H4_LeftShoulder_Cyclops,
	H4_LeftShoulder_ECM,
	H4_LeftShoulder_Gungnir1,
	H4_LeftShoulder_Mongoose,
	H4_LeftShoulder_Optimus,
	H4_LeftShoulder_Triclops,
	H4_LeftShoulder_Unicorn,
	H4_LeftShoulder_Budokan,
	H4_LeftShoulder_Utility,
	H4_LeftShoulder_Pilot,
	H4_LeftShoulder_Stealth,
	H4_LeftShoulder_Commando,
	H4_LeftShoulder_Ninja,
	H4_LeftShoulder_Iron,
	H4_LeftShoulder_Ranger,
	H4_LeftShoulder_Boxhead,
	H4_LeftShoulder_EVA,
	H4_LeftShoulder_Engineer,
	H4_LeftShoulder_Stalker,
	H4_LeftShoulder_Mjolnir,
	H4_LeftShoulder_Rogue,
	H4_LeftShoulder_Tracker,
	H4_LeftShoulder_Gungnir2,
	H4_LeftShoulder_Air_Assault_Slither,
	H4_LeftShoulder_Breather_Forest,
	H4_LeftShoulder_Budokan_Circuit,
	H4_LeftShoulder_Cyclops_Traffic,
	H4_LeftShoulder_Demo_Kabuki,
	H4_LeftShoulder_ECM_Calligraphy,
	H4_LeftShoulder_Engineer_Tribal,
	H4_LeftShoulder_EOD_Berserker,
	H4_LeftShoulder_Gungnir1_Target,
	H4_LeftShoulder_Mongoose_Terrain,
	H4_LeftShoulder_Ninja_Chevron,
	H4_LeftShoulder_Optimus_Fly,
	H4_LeftShoulder_Orbital_Ancient,
	H4_LeftShoulder_Ranger_DigitalCammo,
	H4_LeftShoulder_Recon_Lizard,
	H4_LeftShoulder_Scientist_Frog,
	H4_LeftShoulder_Scout_Propeller,
	H4_LeftShoulder_Soldier_Chevron,
	H4_LeftShoulder_Warrior_Bubbles,
	H4_LeftShoulder_Stalker_Octopus,
	H4_LeftShoulder_Tracker_Drive,
	H4_LeftShoulder_Triclops_Arachnid,
	H4_LeftShoulder_Boxhead_Pathfinder,
	H4_LeftShoulder_Commando_Claw,
	H4_LeftShoulder_EVA_Yield,
	H4_LeftShoulder_Gungnir2_Sand,
	H4_LeftShoulder_Iron_Dragonfly,
	H4_LeftShoulder_Stealth_Raptor,
	H4_LeftShoulder_Utility_Strike,
	H4_LeftShoulder_Pilot_Curves,
	H4_LeftShoulder_Rogue_Glyph,
	H4_LeftShoulder_Spartan_IV_Prime,
	H4_LeftShoulder_DE_Air_Assault_A,
	H4_LeftShoulder_DE_Budokan_A,
	H4_LeftShoulder_DE_Demo_A,
	H4_LeftShoulder_DE_ECM_B,
	H4_LeftShoulder_DE_Orbital_C,
	H4_LeftShoulder_DE_Stealth_A,
	H4_LeftShoulder_DE_Triclops_B,
	H4_LeftShoulder_DE_Utility_A,
	H4_LeftShoulder_Ruin,
	H4_LeftShoulder_Toxic,
	H4_LeftShoulder_Refractive,
	H4_LeftShoulder_DE_MarkV,
	H4_LeftShoulder_DE_ODST,
	H4_LeftShoulder_DE_Forerunner,
	H4_LeftShoulder_DE_NFL,

	H4_RightShoulder_Spartan_IV,
	H4_RightShoulder_Warrior,
	H4_RightShoulder_Scout,
	H4_RightShoulder_Soldier,
	H4_RightShoulder_Recon,
	H4_RightShoulder_Breather,
	H4_RightShoulder_EOD,
	H4_RightShoulder_Scientist,
	H4_RightShoulder_Demo,
	H4_RightShoulder_Orbital,
	H4_RightShoulder_Air_Assault,
	H4_RightShoulder_Cyclops,
	H4_RightShoulder_ECM,
	H4_RightShoulder_Gungnir1,
	H4_RightShoulder_Mongoose,
	H4_RightShoulder_Optimus,
	H4_RightShoulder_Triclops,
	H4_RightShoulder_Unicorn,
	H4_RightShoulder_Budokan,
	H4_RightShoulder_Utility,
	H4_RightShoulder_Pilot,
	H4_RightShoulder_Stealth,
	H4_RightShoulder_Commando,
	H4_RightShoulder_Ninja,
	H4_RightShoulder_Iron,
	H4_RightShoulder_Ranger,
	H4_RightShoulder_Boxhead,
	H4_RightShoulder_EVA,
	H4_RightShoulder_Engineer,
	H4_RightShoulder_Stalker,
	H4_RightShoulder_Mjolnir,
	H4_RightShoulder_Rogue,
	H4_RightShoulder_Tracker,
	H4_RightShoulder_Gungnir2,
	H4_RightShoulder_Air_Assault_Slither,
	H4_RightShoulder_Breather_Forest,
	H4_RightShoulder_Budokan_Circuit,
	H4_RightShoulder_Cyclops_Traffic,
	H4_RightShoulder_Demo_Kabuki,
	H4_RightShoulder_ECM_Calligraphy,
	H4_RightShoulder_Engineer_Tribal,
	H4_RightShoulder_EOD_Berserker,
	H4_RightShoulder_Gungnir1_Target,
	H4_RightShoulder_Mongoose_Terrain,
	H4_RightShoulder_Ninja_Chevron,
	H4_RightShoulder_Optimus_Fly,
	H4_RightShoulder_Orbital_Ancient,
	H4_RightShoulder_Ranger_DigitalCammo,
	H4_RightShoulder_Recon_Lizard,
	H4_RightShoulder_Scientist_Frog,
	H4_RightShoulder_Scout_Propeller,
	H4_RightShoulder_Soldier_Chevron,
	H4_RightShoulder_Warrior_Bubbles,
	H4_RightShoulder_Stalker_Octopus,
	H4_RightShoulder_Tracker_Drive,
	H4_RightShoulder_Triclops_Arachnid,
	H4_RightShoulder_Boxhead_Pathfinder,
	H4_RightShoulder_Commando_Claw,
	H4_RightShoulder_EVA_Yield,
	H4_RightShoulder_Gungnir2_Sand,
	H4_RightShoulder_Iron_Dragonfly,
	H4_RightShoulder_Stealth_Raptor,
	H4_RightShoulder_Utility_Strike,
	H4_RightShoulder_Pilot_Curves,
	H4_RightShoulder_Rogue_Glyph,
	H4_RightShoulder_Spartan_IV_Prime,
	H4_RightShoulder_DE_Air_Assault_A,
	H4_RightShoulder_DE_Budokan_A,
	H4_RightShoulder_DE_Demo_A,
	H4_RightShoulder_DE_ECM_B,
	H4_RightShoulder_DE_Orbital_C,
	H4_RightShoulder_DE_Stealth_A,
	H4_RightShoulder_DE_Triclops_B,
	H4_RightShoulder_DE_Utility_A,
	H4_RightShoulder_Ruin,
	H4_RightShoulder_Toxic,
	H4_RightShoulder_Refractive,
	H4_RightShoulder_DE_MarkV,
	H4_RightShoulder_DE_ODST,
	H4_RightShoulder_DE_Forerunner,
	H4_RightShoulder_DE_NFL,

	H4_Arms_Warrior,
	H4_Arms_Scout,
	H4_Arms_Orbital,
	H4_Arms_Unicorn,
	H4_Arms_Budokan,
	H4_Arms_Pilot,
	H4_Arms_Stealth,
	H4_Arms_Ninja,
	H4_Arms_Mjolnir,
	H4_Arms_Warrior_Prime,
	H4_Arms_Budokan_Target,
	H4_Arms_Ninja_Chevron,
	H4_Arms_Orbital_Ancient,
	H4_Arms_Pilot_Forest,
	H4_Arms_Scout_Arachnid,
	H4_Arms_Stealth_Raptor,
	H4_Arms_Budokan_Circuit,
	H4_Arms_DE_Budokan_A,
	H4_Arms_DE_Orbital_C,
	H4_Arms_DE_Stealth_A,
	H4_Arms_Toxic,
	H4_Arms_Refractive,
	H4_Arms_DE_MarkV,
	H4_Arms_DE_ODST,
	H4_Arms_DE_Forerunner,
	H4_Arms_DE_NFL,

	H4_Legs_Spartan_IV,
	H4_Legs_Warrior,
	H4_Legs_Scout,
	H4_Legs_ECM,
	H4_Legs_Unicorn,
	H4_Legs_Utility,
	H4_Legs_Stealth,
	H4_Legs_Ninja,
	H4_Legs_Mjolnir,
	H4_Legs_Warrior_Prime,
	H4_Legs_ECM_Arachnid,
	H4_Legs_Ninja_Chevron,
	H4_Legs_Scout_Circuit,
	H4_Legs_Stealth_Raptor,
	H4_Legs_Utility_Target,
	H4_Legs_Warrior_Forest,
	H4_Legs_Spartan_IV_Salamander,
	H4_Legs_DE_ECM_B,
	H4_Legs_DE_Stealth_A,
	H4_Legs_DE_Utility_A,
	H4_Legs_Toxic,
	H4_Legs_Refractive,
	H4_Legs_DE_MarkV,
	H4_Legs_DE_ODST,
	H4_Legs_DE_Forerunner,
	H4_Legs_DE_NFL,

	H4_Male,
	H4_Female,

	H4_VisorColor_Default,
	H4_VisorColor_Visor2,
	H4_VisorColor_Visor3,
	H4_VisorColor_Visor4,
	H4_VisorColor_Visor5,
	H4_VisorColor_Visor6,
	H4_VisorColor_Visor7,
	H4_VisorColor_Visor8,
	H4_VisorColor_Visor9,
	H4_VisorColor_Wetwork,
	H4_VisorColor_Operator,
	H4_VisorColor_Pioneer,
	H4_VisorColor_Pathfinder,
	H4_VisorColor_Engineer,
	H4_VisorColor_Stalker,
	H4_VisorColor_Rogue,
	H4_VisorColor_Tracker,

	H4_Color0_Steel,
	H4_Color1_Silver,
	H4_Color2_White,
	H4_Color3_Brown,
	H4_Color4_Tan,
	H4_Color5_Khaki,
	H4_Color6_Sage,
	H4_Color7_Olive,
	H4_Color8_Drab,
	H4_Color9_Forest,
	H4_Color10_Green,
	H4_Color11_SeaFoam,
	H4_Color12_Teal,
	H4_Color13_Aqua,
	H4_Color14_Cyan,
	H4_Color15_Blue,
	H4_Color16_Cobalt,
	H4_Color17_Ice,
	H4_Color18_Violet,
	H4_Color19_Orchid,
	H4_Color20_Lavender,
	H4_Color21_Maroon,
	H4_Color22_Brick,
	H4_Color23_Rose,
	H4_Color24_Rust,
	H4_Color25_Coral,
	H4_Color26_Peach,
	H4_Color27_Gold,
	H4_Color28_Yellow,

	k_customization_item_count,
	k_customization_item_none = -1
};

enum class e_customization_item_v5 : long long
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
	HR_Helmet_Mariner_Base,
	HR_Helmet_Mariner_DEFIANT,
	HR_Helmet_Mariner_MISTERCHIEF,
	HR_Helmet_Mariner_OPTREX,
	HR_Helmet_GRD_Base,
	HR_Helmet_GRD_OPTREX,
	HR_Helmet_GRD_CBRN,
	HR_Helmet_GRD_OPTREX_CBRN,

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
	HR_Chest_Condemned,

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

	HR_EliteArmorEffect_Default,
	HR_EliteArmorEffect_BirthdayParty,
	HR_EliteArmorEffect_HeartAttack,
	HR_EliteArmorEffect_Pestilence,
	HR_EliteArmorEffect_InclementWeather,
	HR_EliteArmorEffect_Flames,
	HR_EliteArmorEffect_BlueFlames,

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
	HR_Chest_Default_RoboArm,
	HR_Chest_TacticalPatrol_RoboArm,
	HR_Chest_TacticalRecon_RoboArm,
	HR_Chest_CollarGrenadierUA_RoboArm,
	HR_Chest_UACounterAssault_RoboArm,

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

	H1S2_WS_PISTOL_DEFAULT,
	H1S2_WS_PISTOL_GOLDEN,
	H1S2_WS_PISTOL_WOODLAND,
	H1S2_WS_PISTOL_DESERT,
	H1S2_WS_PISTOL_GREATJOURNEY,
	H1S2_WS_PISTOL_BLACKCHERRY,
	H1S2_WS_PISTOL_HAZARDPAY,
	H1S2_WS_PISTOL_TOYSOLDIER,
	H1S2_WS_ASSAULTRIFLE_DEFAULT,
	H1S2_WS_ASSAULTRIFLE_GOLDEN,
	H1S2_WS_ASSAULTRIFLE_WOODLAND,
	H1S2_WS_ASSAULTRIFLE_DESERT,
	H1S2_WS_ASSAULTRIFLE_GREATJOURNEY,
	H1S2_WS_ASSAULTRIFLE_CORROSION,
	H1S2_WS_ASSAULTRIFLE_SQUIRT,
	H1S2_WS_ASSAULTRIFLE_LUCKYSHOT,
	H1S2_WS_PLASMAPISTOL_DEFAULT,
	H1S2_WS_PLASMAPISTOL_ULTRA,
	H1S2_WS_PLASMAPISTOL_BRUTAL,
	H1S2_WS_PLASMAPISTOL_SCHISM,
	H1S2_WS_PLASMAPISTOL_ZEALOT,
	H1S2_WS_PLASMARIFLE_DEFAULT,
	H1S2_WS_PLASMARIFLE_ULTRA,
	H1S2_WS_PLASMARIFLE_BRUTAL,
	H1S2_WS_PLASMARIFLE_SCHISM,
	H1S2_WS_PLASMARIFLE_ZEALOT,
	H1S2_WS_ROCKETLAUNCHER_DEFAULT,
	H1S2_WS_ROCKETLAUNCHER_HUNTERSBLOOD,
	H1S2_WS_ROCKETLAUNCHER_CORROSION,
	H1S2_WS_ROCKETLAUNCHER_DESERT,
	H1S2_WS_SNIPERRIFLE_DEFAULT,
	H1S2_WS_SNIPERRIFLE_GOLDEN,
	H1S2_WS_SNIPERRIFLE_WOODLAND,
	H1S2_WS_SNIPERRIFLE_DESERT,
	H1S2_WS_SNIPERRIFLE_GREATJOURNEY,
	H1S2_WS_SNIPERRIFLE_AVALANCHE,
	H1S2_WS_SHOTGUN_DEFAULT,
	H1S2_WS_SHOTGUN_GOLDEN,
	H1S2_WS_SHOTGUN_WOODLAND,
	H1S2_WS_SHOTGUN_DESERT,
	H1S2_WS_SHOTGUN_GREATJOURNEY,
	H1S2_WS_SHOTGUN_HUNTERSBLOOD,
	H1S2_WS_NEEDLER_DEFAULT,
	H1S2_WS_NEEDLER_ULTRA,
	H1S2_WS_NEEDLER_BRUTAL,
	H1S2_WS_NEEDLER_SCHISM,
	H1S2_WS_NEEDLER_ZEALOT,
	H1S2_WS_FLAMETHROWER_DEFAULT,
	H1S2_WS_FLAMETHROWER_DEARJOHN,
	H1S2_WS_FLAMETHROWER_WHITEHOT,
	H1S2_WS_FLAMETHROWER_HOTPEPPER,
	H1S2_WS_FUELRODGUN_DEFAULT,
	H1S2_WS_FUELRODGUN_ULTRA,
	H1S2_WS_FUELRODGUN_BRUTAL,
	H1S2_WS_FUELRODGUN_HERETIC,
	H1S2_WS_FUELRODGUN_ZEALOT,

	H1S2_VS_WARTHOG_DEFAULT,
	H1S2_VS_WARTHOG_HOTROD,
	H1S2_VS_WARTHOG_PARKRANGER,
	H1S2_VS_WARTHOG_RALLYHOG,
	H1S2_VS_ROCKETWARTHOG_DEFAULT,
	H1S2_VS_ROCKETWARTHOG_SUPERSTAR,
	H1S2_VS_ROCKETWARTHOG_SHARK,
	H1S2_VS_ROCKETWARTHOG_CLEVERGIRL,
	H1S2_VS_GHOST_DEFAULT,
	H1S2_VS_GHOST_BRUTAL,
	H1S2_VS_GHOST_SCHISM,
	H1S2_VS_GHOST_ZEALOT,
	H1S2_VS_GHOST_ULTRA,
	H1S2_VS_SCORPION_DEFAULT,
	H1S2_VS_SCORPION_BENGAL,
	H1S2_VS_SCORPION_GRIMREAPER,
	H1S2_VS_SCORPION_ARCTIC,
	H1S2_VS_SCORPION_THEPACKAGE,
	H1S2_VS_BANSHEE_DEFAULT,
	H1S2_VS_BANSHEE_BRUTAL,
	H1S2_VS_BANSHEE_SCHISM,
	H1S2_VS_BANSHEE_ZEALOT,
	H1S2_VS_BANSHEE_ULTRA,

	H1S2_VISOR_DEFAULT,
	H1S2_VISOR_BRONZE,
	H1S2_VISOR_SILVER,
	H1S2_VISOR_PLATINUM,
	H1S2_VISOR_OBSIDIAN,
	H1S2_VISOR_TRIPPY,
	H1S2_VISOR_RAINBOW,
	H1S2_VISOR_PURPLE_PASTEL,
	H1S2_VISOR_BLUE_PASTEL,
	H1S2_VISOR_GREEN_PASTEL,
	H1S2_VISOR_YELLOW_PASTEL,
	H1S2_VISOR_ORANGE_PASTEL,
	H1S2_VISOR_RED_PASTEL,
	H1S2_VISOR_DARK_PURPLE,
	H1S2_VISOR_DARK_BLUE,
	H1S2_VISOR_DARK_GREEN,
	H1S2_VISOR_DARK_YELLOW,
	H1S2_VISOR_DARK_ORANGE,
	H1S2_VISOR_DARK_RED,
	H1S2_VISOR_PURPLE,
	H1S2_VISOR_BLUE,
	H1S2_VISOR_GREEN,
	H1S2_VISOR_YELLOW,
	H1S2_VISOR_ORANGE,
	H1S2_VISOR_RED,
	H1S2_VISOR_PEARL_PURPLE,
	H1S2_VISOR_PEARL_BLUE,
	H1S2_VISOR_PEARL_GREEN,
	H1S2_VISOR_PEARL_YELLOW,
	H1S2_VISOR_PEARL_ORANGE,
	H1S2_VISOR_PEARL_RED,

	H1S2_WS_PISTOL_DEFAULT_MULTIPURPOSE,
	H1S2_WS_PISTOL_GOLDEN_MULTIPURPOSE,
	H1S2_WS_PISTOL_WOODLAND_MULTIPURPOSE,
	H1S2_WS_PISTOL_DESERT_MULTIPURPOSE,
	H1S2_WS_PISTOL_GREATJOURNEY_MULTIPURPOSE,
	H1S2_WS_PISTOL_BLACKCHERRY_MULTIPURPOSE,
	H1S2_WS_PISTOL_HAZARDPAY_MULTIPURPOSE,
	H1S2_WS_PISTOL_TOYSOLDIER_MULTIPURPOSE,

	H1S2_VS_SCORPION_BENGAL_MULTIPURPOSE,
	H1S2_VS_SCORPION_GRIMREAPER_MULTIPURPOSE,
	H1S2_VS_SCORPION_ARCTIC_MULTIPURPOSE,
	H1S2_VS_SCORPION_THEPACKAGE_MULTIPURPOSE,

	H1S2_WS_FUELRODGUN_FP_DEFAULT,
	H1S2_WS_FUELRODGUN_FP_ULTRA,
	H1S2_WS_FUELRODGUN_FP_BRUTAL,
	H1S2_WS_FUELRODGUN_FP_HERETIC,
	H1S2_WS_FUELRODGUN_FP_ZEALOT,

	H1S2_VS_WARTHOG_TIRES_HOTROD,
	H1S2_VS_WARTHOG_TIRES_PARKRANGER,
	H1S2_VS_WARTHOG_TIRES_RALLYHOG,
	H1S2_VS_ROCKETWARTHOG_TIRES_SUPERSTAR,
	H1S2_VS_ROCKETWARTHOG_TIRES_SHARK,
	H1S2_VS_ROCKETWARTHOG_TIRES_CLEVERGIRL,

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
	H2A_Color_20,
	H2A_Color_21,
	H2A_Color_22,
	H2A_Color_23,
	H2A_Color_24,
	H2A_Color_25,
	H2A_Color_26,
	H2A_Color_27,
	H2A_Color_28,
	H2A_Color_29,

	H2A_Spartan_Arms_VAR1,
	H2A_Spartan_Arms_VAR2,
	H2A_Spartan_Arms_VAR3,

	H2A_Spartan_Chest_VAR1,
	H2A_Spartan_Chest_VAR2,
	H2A_Spartan_Chest_VAR3,

	H2A_Spartan_Helmet_VAR1,
	H2A_Spartan_Helmet_VAR2,
	H2A_Spartan_Helmet_VAR3,

	H2A_Spartan_LeftShoulder_VAR1,
	H2A_Spartan_LeftShoulder_VAR2,
	H2A_Spartan_LeftShoulder_VAR3,

	H2A_Spartan_Legs_VAR1,
	H2A_Spartan_Legs_VAR2,
	H2A_Spartan_Legs_VAR3,

	H2A_Spartan_RightShoulder_VAR1,
	H2A_Spartan_RightShoulder_VAR2,
	H2A_Spartan_RightShoulder_VAR3,

	H2A_Elite_Arms_VAR1,
	H2A_Elite_Arms_VAR2,
	H2A_Elite_Arms_VAR3,

	H2A_Elite_Chest_VAR1,
	H2A_Elite_Chest_VAR2,
	H2A_Elite_Chest_VAR3,

	H2A_Elite_Helmet_VAR1,
	H2A_Elite_Helmet_VAR2,
	H2A_Elite_Helmet_VAR3,

	H2A_Elite_Legs_VAR1,
	H2A_Elite_Legs_VAR2,
	H2A_Elite_Legs_VAR3,

	H2A_VisorColor_Default,
	H2A_VisorColor_Visor2,
	H2A_VisorColor_Visor3,
	H2A_VisorColor_Visor4,
	H2A_VisorColor_Visor5,
	H2A_VisorColor_Visor6,
	H2A_VisorColor_Visor7,
	H2A_VisorColor_Visor8,
	H2A_VisorColor_Visor9,
	H2A_VisorColor_Wetwork,
	H2A_VisorColor_Operator,
	H2A_VisorColor_Pioneer,
	H2A_VisorColor_Pathfinder,
	H2A_VisorColor_Engineer,
	H2A_VisorColor_Stalker,
	H2A_VisorColor_Rogue,
	H2A_VisorColor_Tracker,

	Voice_Female,
	Voice_Male,

	H3_CHEST_BUNGIE,
	H3_CHEST_CQB,
	H3_CHEST_EOD,
	H3_CHEST_EVA,
	H3_CHEST_HAYABUSA,
	H3_CHEST_KATANA,
	H3_CHEST_MARK_VI,
	H3_CHEST_RECON,
	H3_CHEST_SCOUT,
	H3_CHEST_SECURITY,

	H3_HELMET_CQB,
	H3_HELMET_EOD,
	H3_HELMET_EVA,
	H3_HELMET_HAYABUSA,
	H3_HELMET_MARK_V,
	H3_HELMET_MARK_VI,
	H3_HELMET_RECON,
	H3_HELMET_ROGUE,
	H3_HELMET_SECURITY,
	H3_HELMET_ODST,
	H3_HELMET_SCOUT,

	H3_LEFTSHOULDER_CQB,
	H3_LEFTSHOULDER_EOD,
	H3_LEFTSHOULDER_EVA,
	H3_LEFTSHOULDER_HAYABUSA,
	H3_LEFTSHOULDER_MARK_VI,
	H3_LEFTSHOULDER_RECON,
	H3_LEFTSHOULDER_SCOUT,
	H3_LEFTSHOULDER_SECURITY,

	H3_RIGHTSHOULDER_CQB,
	H3_RIGHTSHOULDER_EOD,
	H3_RIGHTSHOULDER_EVA,
	H3_RIGHTSHOULDER_HAYABUSA,
	H3_RIGHTSHOULDER_MARK_VI,
	H3_RIGHTSHOULDER_RECON,
	H3_RIGHTSHOULDER_SCOUT,
	H3_RIGHTSHOULDER_SECURITY,

	H3E_Techsuit_Default,
	H3E_Techsuit_Eldorado,

	H3E_Helmet_AirAssault,
	H3E_Helmet_Base,
	H3E_Helmet_Blaster,
	H3E_Helmet_Chameleon,
	H3E_Helmet_CQB,
	H3E_Helmet_Demo,
	H3E_Helmet_Dynamo,
	H3E_Helmet_Enigma,
	H3E_Helmet_EOD,
	H3E_Helmet_EVA,
	H3E_Helmet_Extractor,
	H3E_Helmet_Ghoul,
	H3E_Helmet_Gungnir,
	H3E_Helmet_Hammerhead,
	H3E_Helmet_HAYABUSA,
	H3E_Helmet_Knight,
	H3E_Helmet_Lancer,
	H3E_Helmet_MARK_V,
	H3E_Helmet_MARK_VI,
	H3E_Helmet_Mongoose,
	H3E_Helmet_Navigator,
	H3E_Helmet_NiHard,
	H3E_Helmet_ODST,
	H3E_Helmet_Oracle,
	H3E_Helmet_Pilot,
	H3E_Helmet_Poncho,
	H3E_Helmet_RECON,
	H3E_Helmet_Rhino,
	H3E_Helmet_ROGUE,
	H3E_Helmet_SCOUT,
	H3E_Helmet_SECURITY,
	H3E_Helmet_Seeker,
	H3E_Helmet_Spectrum,
	H3E_Helmet_Utility,
	H3E_Helmet_Warrior,

	H3E_LeftShoulder_AirAssault,
	H3E_LeftShoulder_Base,
	H3E_LeftShoulder_Blaster,
	H3E_LeftShoulder_Chameleon,
	H3E_LeftShoulder_CQB,
	H3E_LeftShoulder_Demo,
	H3E_LeftShoulder_Dynamo,
	H3E_LeftShoulder_Enigma,
	H3E_LeftShoulder_EOD,
	H3E_LeftShoulder_EVA,
	H3E_LeftShoulder_Extractor,
	H3E_LeftShoulder_Ghoul,
	H3E_LeftShoulder_Gungnir,
	H3E_LeftShoulder_Hammerhead,
	H3E_LeftShoulder_HAYABUSA,
	H3E_LeftShoulder_Knight,
	H3E_LeftShoulder_Lancer,
	H3E_LeftShoulder_Mark_VI,
	H3E_LeftShoulder_Mongoose,
	H3E_LeftShoulder_Navigator,
	H3E_LeftShoulder_NiHard,
	H3E_LeftShoulder_Oracle,
	H3E_LeftShoulder_Pilot,
	H3E_LeftShoulder_Poncho,
	H3E_LeftShoulder_RECON,
	H3E_LeftShoulder_Rhino,
	H3E_LeftShoulder_SCOUT,
	H3E_LeftShoulder_SECURITY,
	H3E_LeftShoulder_Seeker,
	H3E_LeftShoulder_Spectrum,
	H3E_LeftShoulder_Utility,
	H3E_LeftShoulder_Warrior,

	H3E_RightShoulder_AirAssault,
	H3E_RightShoulder_Base,
	H3E_RightShoulder_Blaster,
	H3E_RightShoulder_Chameleon,
	H3E_RightShoulder_CQB,
	H3E_RightShoulder_Demo,
	H3E_RightShoulder_Dynamo,
	H3E_RightShoulder_Enigma,
	H3E_RightShoulder_EOD,
	H3E_RightShoulder_EVA,
	H3E_RightShoulder_Extractor,
	H3E_RightShoulder_Ghoul,
	H3E_RightShoulder_Gungnir,
	H3E_RightShoulder_Hammerhead,
	H3E_RightShoulder_HAYABUSA,
	H3E_RightShoulder_Knight,
	H3E_RightShoulder_Lancer,
	H3E_RightShoulder_Mark_VI,
	H3E_RightShoulder_Mongoose,
	H3E_RightShoulder_Navigator,
	H3E_RightShoulder_NiHard,
	H3E_RightShoulder_Oracle,
	H3E_RightShoulder_Pilot,
	H3E_RightShoulder_Poncho,
	H3E_RightShoulder_RECON,
	H3E_RightShoulder_Rhino,
	H3E_RightShoulder_SCOUT,
	H3E_RightShoulder_SECURITY,
	H3E_RightShoulder_Seeker,
	H3E_RightShoulder_Spectrum,
	H3E_RightShoulder_Utility,
	H3E_RightShoulder_Warrior,

	H3E_Chest_AirAssault,
	H3E_Chest_Base,
	H3E_Chest_Blaster,
	H3E_Chest_BUNGIE,
	H3E_Chest_Chameleon,
	H3E_Chest_CQB,
	H3E_Chest_Demo,
	H3E_Chest_Dynamo,
	H3E_Chest_Enigma,
	H3E_Chest_EOD,
	H3E_Chest_EVA,
	H3E_Chest_Extractor,
	H3E_Chest_Ghoul,
	H3E_Chest_Gungnir,
	H3E_Chest_Hammerhead,
	H3E_Chest_HAYABUSA,
	H3E_Chest_KATANA,
	H3E_Chest_Knight,
	H3E_Chest_Lancer,
	H3E_Chest_Mark_VI,
	H3E_Chest_Mongoose,
	H3E_Chest_Navigator,
	H3E_Chest_NiHard,
	H3E_Chest_Oracle,
	H3E_Chest_Pilot,
	H3E_Chest_Poncho,
	H3E_Chest_RECON,
	H3E_Chest_Rhino,
	H3E_Chest_SCOUT,
	H3E_Chest_SECURITY,
	H3E_Chest_Seeker,
	H3E_Chest_Spectrum,
	H3E_Chest_Utility,
	H3E_Chest_Warrior,

	H3E_Arms_AirAssault,
	H3E_Arms_Base,
	H3E_Arms_Blaster,
	H3E_Arms_Chameleon,
	H3E_Arms_Demo,
	H3E_Arms_Dynamo,
	H3E_Arms_Enigma,
	H3E_Arms_Extractor,
	H3E_Arms_Gungnir,
	H3E_Arms_Hammerhead,
	H3E_Arms_Lancer,
	H3E_Arms_Mark_VI,
	H3E_Arms_NiHard,
	H3E_Arms_Oracle,
	H3E_Arms_Pilot,
	H3E_Arms_Poncho,
	H3E_Arms_Spectrum,
	H3E_Arms_Utility,
	H3E_Arms_Warrior,

	H3E_Legs_AirAssault,
	H3E_Legs_Base,
	H3E_Legs_Blaster,
	H3E_Legs_Chameleon,
	H3E_Legs_Demo,
	H3E_Legs_Dynamo,
	H3E_Legs_Enigma,
	H3E_Legs_Extractor,
	H3E_Legs_Ghoul,
	H3E_Legs_Gungnir,
	H3E_Legs_Hammerhead,
	H3E_Legs_Knight,
	H3E_Legs_Lancer,
	H3E_Legs_Mark_VI,
	H3E_Legs_Mongoose,
	H3E_Legs_Navigator,
	H3E_Legs_NiHard,
	H3E_Legs_Oracle,
	H3E_Legs_Pilot,
	H3E_Legs_Poncho,
	H3E_Legs_Rhino,
	H3E_Legs_Seeker,
	H3E_Legs_Spectrum,
	H3E_Legs_Utility,
	H3E_Legs_Warrior,

	H3_chest_ASCETIC,
	H3_helmet_ASCETIC,
	H3_leftShoulder_ASCETIC,
	H3_rightShoulder_ASCETIC,
	H3_chest_ASSAULT,
	H3_helmet_ASSAULT,
	H3_leftShoulder_ASSAULT,
	H3_rightShoulder_ASSAULT,
	H3_chest_COMBAT,
	H3_helmet_COMBAT,
	H3_leftShoulder_COMBAT,
	H3_rightShoulder_COMBAT,
	H3_chest_COMMANDO,
	H3_helmet_COMMANDO,
	H3_leftShoulder_COMMANDO,
	H3_rightShoulder_COMMANDO,
	H3_chest_FLIGHT,
	H3_helmet_FLIGHT,
	H3_leftShoulder_FLIGHT,
	H3_rightShoulder_FLIGHT,

	H3_COLOR0_STEEL,
	H3_COLOR1_SILVER,
	H3_COLOR2_WHITE,
	H3_COLOR3_RED,
	H3_COLOR4_MAUVE,
	H3_COLOR5_SALMON,
	H3_COLOR6_ORANGE,
	H3_COLOR7_CORAL,
	H3_COLOR8_PEACH,
	H3_COLOR9_GOLD,
	H3_COLOR10_YELLOW,
	H3_COLOR11_PALE,
	H3_COLOR12_SAGE,
	H3_COLOR13_GREEN,
	H3_COLOR14_OLIVE,
	H3_COLOR15_TEAL,
	H3_COLOR16_AQUA,
	H3_COLOR17_CYAN,
	H3_COLOR18_BLUE,
	H3_COLOR19_COBALT,
	H3_COLOR20_SAPHIRE,
	H3_COLOR21_VIOLET,
	H3_COLOR22_ORCHID,
	H3_COLOR23_LAVENDER,
	H3_COLOR24_CRIMSON,
	H3_COLOR25_RUBINE,
	H3_COLOR26_PINK,
	H3_COLOR27_BROWN,
	H3_COLOR28_TAN,
	H3_COLOR29_KHAKI,

	H3S3_WS_SNIPERRIFLE_DEFAULT,
	H3S3_WS_SNIPERRIFLE_GOLDPLATE,
	H3S3_WS_SNIPERRIFLE_GLACIERCAMO,
	H3S3_WS_SNIPERRIFLE_GREENCAMO,
	H3S3_WS_SNIPERRIFLE_DESERTTAN,
	H3S5_WS_SNIPERRIFLE_REDALERT,
	H3S5_WS_SNIPERRIFLE_HAZARDPAY,
	H3S3_WS_MAGNUM_DEFAULT,
	H3S3_WS_MAGNUM_GOLDPLATE,
	H3S3_WS_MAGNUM_DINOBITE,
	H3S3_WS_MAGNUM_ORANGE,
	H3S3_WS_MAGNUM_WORNOUTUNBLUE,
	H3S5_WS_MAGNUM_HAZARDPAY,
	H3S5_WS_MAGNUM_TECHCAMOBRAVO,
	H3S3_WS_ASSAULTRIFLE_DEFAULT,
	H3S3_WS_ASSAULTRIFLE_GOLDPLATE,
	H3S3_WS_ASSAULTRIFLE_WASTELANDRUST,
	H3S3_WS_ASSAULTRIFLE_GREENCAMO,
	H3S3_WS_ASSAULTRIFLE_SUPERSQUIRT,
	H3S5_WS_ASSAULTRIFLE_DESERT,
	H3S5_WS_ASSAULTRIFLE_HAZARDPAY,
	H3S4_WS_SHOTGUN_DEFAULT,
	H3S4_WS_SHOTGUN_GOLDPLATE,
	H3S4_WS_SHOTGUN_GREENCAMO,
	H3S4_WS_SHOTGUN_SAFETYORANGE,
	H3S4_WS_BATTLERIFLE_DEFAULT,
	H3S4_WS_BATTLERIFLE_FERNSTENCIL,
	H3S4_WS_BATTLERIFLE_MEANSTREETSOFNEW,
	H3S4_WS_BATTLERIFLE_CAMOCOOL,
	H3S4_WS_BATTLERIFLE_WORNOUTREDHAZARD,
	H3S5_WS_BATTLERIFLE_COVENANTPURPLE,
	H3S5_WS_BATTLERIFLE_DESERTTAN,
	H3S5_WS_BATTLERIFLE_GOLDEN,
	H3S5_WS_BATTLERIFLE_GREEN117,
	H3S5_WS_BATTLERIFLE_GREYSCALES,
	H3S5_WS_BATTLERIFLE_HAZARDPAY,
	H3S5_WS_BATTLERIFLE_REDFLAMES,
	H3S5_WS_BATTLERIFLE_SAFETYORANGE,
	H3S4_WS_ROCKETLAUNCHER_DEFAULT,
	H3S4_WS_ROCKETLAUNCHER_SAFETYORANGE,
	H3S4_WS_ROCKETLAUNCHER_WASTERLANDRUST,
	H3S5_WS_ROCKETLAUNCHER_HAZARDPAY,
	H3S4_WS_SMG_DEFAULT,
	H3S4_WS_SMG_DIGITALCAMOWARM,
	H3S4_WS_SMG_TIGERSTRIPES,
	H3S4_WS_SMG_HUNTERSBLOOD,
	H3S5_WS_SMG_GOLDEN,
	H3S5_WS_SMG_GRAFFITI,
	H3S5_WS_SMG_GREENSTRIPES,
	H3S4_WS_PLASMAPISTOL_DEFAULT,
	H3S4_WS_PLASMAPISTOL_COVENANTYELLOW,
	H3S5_WS_PLASMAPISTOL_SCHISM,
	H3S4_WS_PLASMARIFLE_DEFAULT,
	H3S4_WS_PLASMARIFLE_DEFECTORGREEN,
	H3S5_WS_PLASMARIFLE_YELLOWSTRIPES,
	H3S4_WS_NEEDLER_DEFAULT,
	H3S4_WS_NEEDLER_COVENANTYELLOW,
	H3S5_WS_NEEDLER_DEFECTORGREEN,
	H3S4_WS_FLAMETHROWER_DEFAULT,
	H3S4_WS_FLAMETHROWER_LAWNMOWERYELLOWANDGREEN,
	H3S4_WS_FLAMETHROWER_REDHOTPEPPER,
	H3S4_WS_FUELRODGUN_DEFAULT,
	H3S4_WS_FUELRODGUN_BANISHEDRED,
	H3S5_WS_FUELRODGUN_DEFECTORGREEN,

	H3S4_VS_WARTHOG_DEFAULT,
	H3S4_VS_WARTHOG_HAZARDPAY,
	H3S4_VS_WARTHOG_PARKRANGER,
	H3S4_VS_WARTHOG_RALLYHOG,
	H3S4_VS_WARTHOG_ARCTIC,
	H3S4_VS_GAUSSWARTHOG_DEFAULT,
	H3S4_VS_GAUSSWARTHOG_CORROSION,
	H3S4_VS_GAUSSWARTHOG_SHARK,
	H3S4_VS_GAUSSWARTHOG_CLEVERGIRL,
	H3S4_VS_GAUSSWARTHOG_ARCTIC,
	H3S4_VS_GHOST_DEFAULT,
	H3S5_VS_GHOST_BRUTAL,
	H3S5_VS_GHOST_SCHISM,
	H3S4_VS_GHOST_ZEALOT,
	H3S4_VS_GHOST_ULTRA,
	H3S4_VS_BANSHEE_DEFAULT,
	H3S4_VS_BANSHEE_BRUTAL,
	H3S4_VS_BANSHEE_SCHISM,
	H3S4_VS_BANSHEE_ZEALOT,
	H3S5_VS_BANSHEE_ULTRA,
	H3S4_VS_SCORPION_DEFAULT,
	H3S4_VS_SCORPION_BENGAL,
	H3S4_VS_SCORPION_GRIMREAPER,
	H3S4_VS_SCORPION_ARCTIC,
	H3S4_VS_SCORPION_HAZARDPAY,
	H3S5_VS_HORNET_DEFAULT,
	H3S5_VS_HORNET_SNOW,
	H3S5_VS_MONGOOSE_DEFAULT,

	H3_VISOR_DEFAULT,
	H3_VISOR_BRONZE,
	H3_VISOR_SILVER,
	H3_VISOR_PLATINUM,
	H3_VISOR_OBSIDIAN,
	H3_VISOR_TRIPPY,
	H3_VISOR_RAINBOW,
	H3_VISOR_PURPLE_PASTEL,
	H3_VISOR_BLUE_PASTEL,
	H3_VISOR_GREEN_PASTEL,
	H3_VISOR_YELLOW_PASTEL,
	H3_VISOR_ORANGE_PASTEL,
	H3_VISOR_RED_PASTEL,
	H3_VISOR_DARK_PURPLE,
	H3_VISOR_DARK_BLUE,
	H3_VISOR_DARK_GREEN,
	H3_VISOR_DARK_YELLOW,
	H3_VISOR_DARK_ORANGE,
	H3_VISOR_DARK_RED,
	H3_VISOR_PURPLE,
	H3_VISOR_BLUE,
	H3_VISOR_GREEN,
	H3_VISOR_YELLOW,
	H3_VISOR_ORANGE,
	H3_VISOR_RED,
	H3_VISOR_PEARL_PURPLE,
	H3_VISOR_PEARL_BLUE,
	H3_VISOR_PEARL_GREEN,
	H3_VISOR_PEARL_YELLOW,
	H3_VISOR_PEARL_ORANGE,
	H3_VISOR_PEARL_RED,

	ODST_NONE,
	ODST_ROOKIE,
	ODST_BUCK,
	ODST_BUCK_BUGSPLATTERED,
	ODST_DARE,
	ODST_DUTCH,
	ODST_JOHNSON,
	ODST_MICKEY,
	ODST_ROMEO,
	ODST_ROMEO_INJURED,
	ODST_NONE_WITH_HELMET,
	ODST_ROOKIE_WITH_HELMET,
	ODST_BUCK_WITH_HELMET,
	ODST_BUCK_BUGSPLATTERED_WITH_HELMET,
	ODST_DARE_WITH_HELMET,
	ODST_DUTCH_WITH_HELMET,
	ODST_JOHNSON_WITH_HELMET,
	ODST_MICKEY_WITH_HELMET,
	ODST_ROMEO_WITH_HELMET,
	ODST_ROMEO_INJURED_WITH_HELMET,

	ODST_COLOR_BLACK,
	ODST_COLOR_GRAY,
	ODST_COLOR_SNOW,
	ODST_COLOR_MAROON,
	ODST_COLOR_BRICK,
	ODST_COLOR_ROSE,
	ODST_COLOR_BROWN,
	ODST_COLOR_WOODLAND,
	ODST_COLOR_COCOA,
	ODST_COLOR_TAN,
	ODST_COLOR_KHAKI,
	ODST_COLOR_DESERT,
	ODST_COLOR_CORAL,
	ODST_COLOR_GOLD,
	ODST_COLOR_SAND,
	ODST_COLOR_SAGE,
	ODST_COLOR_OLIVE,
	ODST_COLOR_DRAB,
	ODST_COLOR_FOREST,
	ODST_COLOR_GREEN,
	ODST_COLOR_SEA_FOAM,
	ODST_COLOR_TEAL,
	ODST_COLOR_AQUA,
	ODST_COLOR_CYAN,
	ODST_COLOR_BLUE,
	ODST_COLOR_COBALT,
	ODST_COLOR_ICE,
	ODST_COLOR_VIOLET,
	ODST_COLOR_LAVENDER,
	ODST_COLOR_PINK,

	H4_Helmet_RECRUIT,
	H4_Helmet_RECRUIT_PRME,
	H4_Helmet_WARRIOR,
	H4_Helmet_WARRIOR_MTRX,
	H4_Helmet_AIR_ASSAULT,
	H4_Helmet_AIR_ASSAULT_VERG,
	H4_Helmet_AIR_ASSAULT_VISN,
	H4_Helmet_SOLDIER,
	H4_Helmet_SOLDIER_ZNTH,
	H4_Helmet_AVIATOR,
	H4_Helmet_AVIATOR_BOND,
	H4_Helmet_DEFENDER,
	H4_Helmet_DEFENDER_CTRL,
	H4_Helmet_DEFENDER_CLMN,
	H4_Helmet_RECON,
	H4_Helmet_RECON_SURG,
	H4_Helmet_EVA,
	H4_Helmet_EVA_BRCH,
	H4_Helmet_WAR_MASTER,
	H4_Helmet_WAR_MASTER_PRML,
	H4_Helmet_SCOUT,
	H4_Helmet_SCOUT_APEX,
	H4_Helmet_SCOUT_TOXC,
	H4_Helmet_ORBITAL,
	H4_Helmet_ORBITAL_AEON,
	H4_Helmet_ORBITAL_SWFT,
	H4_Helmet_INFILTRATOR,
	H4_Helmet_INFILTRATOR_TRAC,
	H4_Helmet_INFILTRATOR_PYTN,
	H4_Helmet_HAZOP,
	H4_Helmet_HAZOP_FRST,
	H4_Helmet_EOD,
	H4_Helmet_EOD_SHDW,
	H4_Helmet_OCEANIC,
	H4_Helmet_OCEANIC_CRCT,
	H4_Helmet_OCEANIC_SLID,
	H4_Helmet_ENFORCER,
	H4_Helmet_ENFORCER_TRBL,
	H4_Helmet_ENFORCER_TRCR,
	H4_Helmet_WETWORK,
	H4_Helmet_WETWORK_SHRD,
	H4_Helmet_OPERATOR,
	H4_Helmet_OPERATOR_SRFC,
	H4_Helmet_PIONEER,
	H4_Helmet_PIONEER_ADPT,
	H4_Helmet_PATHFINDER,
	H4_Helmet_PATHFINDER_CORE,
	H4_Helmet_ENGINEER,
	H4_Helmet_ENGINEER_EDGE,
	H4_Helmet_STALKER,
	H4_Helmet_STALKER_CRSH,
	H4_Helmet_ROGUE,
	H4_Helmet_ROGUE_FCUS,
	H4_Helmet_TRACKER,
	H4_Helmet_TRACKER_ADRT,
	H4_Helmet_VANGUARD,
	H4_Helmet_VANGUARD_CNVG,
	H4_Helmet_CIO,
	H4_Helmet_CIO_WEB,
	H4_Helmet_CIO_RUSH,
	H4_Helmet_CIO_RUIN,
	H4_Helmet_VENATOR,
	H4_Helmet_VENATOR_RPTR,
	H4_Helmet_VENATOR_BYNT,
	H4_Helmet_VENATOR_RFCT,
	H4_Helmet_GUNGNIR,
	H4_Helmet_GUNGNIR_PULS,
	H4_Helmet_COMMANDO,
	H4_Helmet_COMMANDO_FRCT,
	H4_Helmet_RANGER,
	H4_Helmet_RANGER_STRK,
	H4_Helmet_PROTECTOR,
	H4_Helmet_PROTECTOR_DRFT,
	H4_Helmet_MARK_VI,
	H4_Helmet_RAIDER,
	H4_Helmet_RAIDER_DSTT,
	H4_Helmet_DEADEYE,
	H4_Helmet_LOCUS,
	H4_Helmet_SCANNER,
	H4_Helmet_STRIDER,
	H4_Helmet_FOTUS,
	H4_Helmet_OLYMPUS,

	H4_RightShoulder_RECRUIT,
	H4_RightShoulder_RECRUIT_PRME,
	H4_RightShoulder_WARRIOR,
	H4_RightShoulder_WARRIOR_MTRX,
	H4_RightShoulder_AIR_ASSAULT,
	H4_RightShoulder_AIR_ASSAULT_VERG,
	H4_RightShoulder_AIR_ASSAULT_VISN,
	H4_RightShoulder_SOLDIER,
	H4_RightShoulder_SOLDIER_ZNTH,
	H4_RightShoulder_AVIATOR,
	H4_RightShoulder_AVIATOR_BOND,
	H4_RightShoulder_DEFENDER,
	H4_RightShoulder_DEFENDER_CTRL,
	H4_RightShoulder_DEFENDER_CLMN,
	H4_RightShoulder_RECON,
	H4_RightShoulder_RECON_SURG,
	H4_RightShoulder_EVA,
	H4_RightShoulder_EVA_BRCH,
	H4_RightShoulder_WAR_MASTER,
	H4_RightShoulder_WAR_MASTER_PRML,
	H4_RightShoulder_SCOUT,
	H4_RightShoulder_SCOUT_APEX,
	H4_RightShoulder_SCOUT_TOXC,
	H4_RightShoulder_ORBITAL,
	H4_RightShoulder_ORBITAL_AEON,
	H4_RightShoulder_ORBITAL_SWFT,
	H4_RightShoulder_INFILTRATOR,
	H4_RightShoulder_INFILTRATOR_TRAC,
	H4_RightShoulder_INFILTRATOR_PYTN,
	H4_RightShoulder_HAZOP,
	H4_RightShoulder_HAZOP_FRST,
	H4_RightShoulder_EOD,
	H4_RightShoulder_EOD_SHDW,
	H4_RightShoulder_OCEANIC,
	H4_RightShoulder_OCEANIC_CRCT,
	H4_RightShoulder_OCEANIC_SLID,
	H4_RightShoulder_ENFORCER,
	H4_RightShoulder_ENFORCER_TRBL,
	H4_RightShoulder_ENFORCER_TRCR,
	H4_RightShoulder_WETWORK,
	H4_RightShoulder_WETWORK_SHRD,
	H4_RightShoulder_OPERATOR,
	H4_RightShoulder_OPERATOR_SRFC,
	H4_RightShoulder_PIONEER,
	H4_RightShoulder_PIONEER_ADPT,
	H4_RightShoulder_PATHFINDER,
	H4_RightShoulder_PATHFINDER_CORE,
	H4_RightShoulder_ENGINEER,
	H4_RightShoulder_ENGINEER_EDGE,
	H4_RightShoulder_STALKER,
	H4_RightShoulder_STALKER_CRSH,
	H4_RightShoulder_ROGUE,
	H4_RightShoulder_ROGUE_FCUS,
	H4_RightShoulder_TRACKER,
	H4_RightShoulder_TRACKER_ADRT,
	H4_RightShoulder_VANGUARD,
	H4_RightShoulder_VANGUARD_CNVG,
	H4_RightShoulder_CIO,
	H4_RightShoulder_CIO_WEB,
	H4_RightShoulder_CIO_RUSH,
	H4_RightShoulder_CIO_RUIN,
	H4_RightShoulder_VENATOR,
	H4_RightShoulder_VENATOR_RPTR,
	H4_RightShoulder_VENATOR_BYNT,
	H4_RightShoulder_VENATOR_RFCT,
	H4_RightShoulder_GUNGNIR,
	H4_RightShoulder_GUNGNIR_PULS,
	H4_RightShoulder_COMMANDO,
	H4_RightShoulder_COMMANDO_FRCT,
	H4_RightShoulder_RANGER,
	H4_RightShoulder_RANGER_STRK,
	H4_RightShoulder_PROTECTOR,
	H4_RightShoulder_PROTECTOR_DRFT,
	H4_RightShoulder_MARK_VI,
	H4_RightShoulder_RAIDER,
	H4_RightShoulder_RAIDER_DSTT,
	H4_RightShoulder_FOTUS,

	H4_LeftShoulder_RECRUIT,
	H4_LeftShoulder_RECRUIT_PRME,
	H4_LeftShoulder_WARRIOR,
	H4_LeftShoulder_WARRIOR_MTRX,
	H4_LeftShoulder_AIR_ASSAULT,
	H4_LeftShoulder_AIR_ASSAULT_VERG,
	H4_LeftShoulder_AIR_ASSAULT_VISN,
	H4_LeftShoulder_SOLDIER,
	H4_LeftShoulder_SOLDIER_ZNTH,
	H4_LeftShoulder_AVIATOR,
	H4_LeftShoulder_AVIATOR_BOND,
	H4_LeftShoulder_DEFENDER,
	H4_LeftShoulder_DEFENDER_CTRL,
	H4_LeftShoulder_DEFENDER_CLMN,
	H4_LeftShoulder_RECON,
	H4_LeftShoulder_RECON_SURG,
	H4_LeftShoulder_EVA,
	H4_LeftShoulder_EVA_BRCH,
	H4_LeftShoulder_WAR_MASTER,
	H4_LeftShoulder_WAR_MASTER_PRML,
	H4_LeftShoulder_SCOUT,
	H4_LeftShoulder_SCOUT_APEX,
	H4_LeftShoulder_SCOUT_TOXC,
	H4_LeftShoulder_ORBITAL,
	H4_LeftShoulder_ORBITAL_AEON,
	H4_LeftShoulder_ORBITAL_SWFT,
	H4_LeftShoulder_INFILTRATOR,
	H4_LeftShoulder_INFILTRATOR_TRAC,
	H4_LeftShoulder_INFILTRATOR_PYTN,
	H4_LeftShoulder_HAZOP,
	H4_LeftShoulder_HAZOP_FRST,
	H4_LeftShoulder_EOD,
	H4_LeftShoulder_EOD_SHDW,
	H4_LeftShoulder_OCEANIC,
	H4_LeftShoulder_OCEANIC_CRCT,
	H4_LeftShoulder_OCEANIC_SLID,
	H4_LeftShoulder_ENFORCER,
	H4_LeftShoulder_ENFORCER_TRBL,
	H4_LeftShoulder_ENFORCER_TRCR,
	H4_LeftShoulder_WETWORK,
	H4_LeftShoulder_WETWORK_SHRD,
	H4_LeftShoulder_OPERATOR,
	H4_LeftShoulder_OPERATOR_SRFC,
	H4_LeftShoulder_PIONEER,
	H4_LeftShoulder_PIONEER_ADPT,
	H4_LeftShoulder_PATHFINDER,
	H4_LeftShoulder_PATHFINDER_CORE,
	H4_LeftShoulder_ENGINEER,
	H4_LeftShoulder_ENGINEER_EDGE,
	H4_LeftShoulder_STALKER,
	H4_LeftShoulder_STALKER_CRSH,
	H4_LeftShoulder_ROGUE,
	H4_LeftShoulder_ROGUE_FCUS,
	H4_LeftShoulder_TRACKER,
	H4_LeftShoulder_TRACKER_ADRT,
	H4_LeftShoulder_VANGUARD,
	H4_LeftShoulder_VANGUARD_CNVG,
	H4_LeftShoulder_CIO,
	H4_LeftShoulder_CIO_WEB,
	H4_LeftShoulder_CIO_RUSH,
	H4_LeftShoulder_CIO_RUIN,
	H4_LeftShoulder_VENATOR,
	H4_LeftShoulder_VENATOR_RPTR,
	H4_LeftShoulder_VENATOR_BYNT,
	H4_LeftShoulder_VENATOR_RFCT,
	H4_LeftShoulder_GUNGNIR,
	H4_LeftShoulder_GUNGNIR_PULS,
	H4_LeftShoulder_COMMANDO,
	H4_LeftShoulder_COMMANDO_FRCT,
	H4_LeftShoulder_RANGER,
	H4_LeftShoulder_RANGER_STRK,
	H4_LeftShoulder_PROTECTOR,
	H4_LeftShoulder_PROTECTOR_DRFT,
	H4_LeftShoulder_MARK_VI,
	H4_LeftShoulder_RAIDER,
	H4_LeftShoulder_RAIDER_DSTT,
	H4_LeftShoulder_FOTUS,

	H4_Arms_RECRUIT,
	H4_Arms_RECRUIT_PRME,
	H4_Arms_TWINPLATED,
	H4_Arms_TWINPLATED_AEON,
	H4_Arms_TWINPLATED_SWFT,
	H4_Arms_GV09_LOCKING,
	H4_Arms_GV09_LOCKING_FRST,
	H4_Arms_INNERPLATED,
	H4_Arms_INNERPLATED_WEB,
	H4_Arms_INNERPLATED_TOXC,
	H4_Arms_OUTERPLATED,
	H4_Arms_OUTERPLATED_RPTR,
	H4_Arms_OUTERPLATED_BYNT,
	H4_Arms_OUTERPLATED_RFCT,
	H4_Arms_CONTOURED,
	H4_Arms_CONTOURED_SHRD,
	H4_Arms_XV27_SHIFTING,
	H4_Arms_XV27_SHIFTING_PULS,
	H4_Arms_XV27_SHIFTING_CRCT,
	H4_Arms_XV27_SHIFTING_SLID,
	H4_Arms_MARK_VI,
	H4_Arms_FOTUS,

	H4_Legs_RECRUIT,
	H4_Legs_RECRUIT_TIGR,
	H4_Legs_RG63_COUNTER,
	H4_Legs_RG63_COUNTER_PRME,
	H4_Legs_RG63_COUNTER_FRST,
	H4_Legs_LG50_BULK,
	H4_Legs_LG50_BULK_PULS,
	H4_Legs_LG50_BULK_CLMN,
	H4_Legs_OUTERPLATED,
	H4_Legs_OUTERPLATED_CRCT,
	H4_Legs_OUTERPLATED_TOXC,
	H4_Legs_XG89_NARROW,
	H4_Legs_XG89_NARROW_RPTR,
	H4_Legs_XG89_NARROW_BYNT,
	H4_Legs_XG89_NARROW_RFCT,
	H4_Legs_CONTOURED,
	H4_Legs_CONTOURED_SHRD,
	H4_Legs_OVERLOCKING,
	H4_Legs_OVERLOCKING_WEB,
	H4_Legs_MARK_VI,
	H4_Legs_FOTUS,

	H4_Chest_RECRUIT,
	H4_Chest_RECRUIT_PRME,
	H4_Chest_WARRIOR,
	H4_Chest_WARRIOR_MTRX,
	H4_Chest_AIR_ASSAULT,
	H4_Chest_AIR_ASSAULT_VERG,
	H4_Chest_AIR_ASSAULT_VISN,
	H4_Chest_SOLDIER,
	H4_Chest_SOLDIER_ZNTH,
	H4_Chest_AVIATOR,
	H4_Chest_AVIATOR_BOND,
	H4_Chest_DEFENDER,
	H4_Chest_DEFENDER_CTRL,
	H4_Chest_DEFENDER_CLMN,
	H4_Chest_RECON,
	H4_Chest_RECON_SURG,
	H4_Chest_EVA,
	H4_Chest_EVA_BRCH,
	H4_Chest_WAR_MASTER,
	H4_Chest_WAR_MASTER_PRML,
	H4_Chest_SCOUT,
	H4_Chest_SCOUT_APEX,
	H4_Chest_SCOUT_TOXC,
	H4_Chest_ORBITAL,
	H4_Chest_ORBITAL_AEON,
	H4_Chest_ORBITAL_SWFT,
	H4_Chest_INFILTRATOR,
	H4_Chest_INFILTRATOR_TRAC,
	H4_Chest_INFILTRATOR_PYTN,
	H4_Chest_HAZOP,
	H4_Chest_HAZOP_FRST,
	H4_Chest_EOD,
	H4_Chest_EOD_SHDW,
	H4_Chest_OCEANIC,
	H4_Chest_OCEANIC_CRCT,
	H4_Chest_OCEANIC_SLID,
	H4_Chest_ENFORCER,
	H4_Chest_ENFORCER_TRBL,
	H4_Chest_ENFORCER_TRCR,
	H4_Chest_WETWORK,
	H4_Chest_WETWORK_SHRD,
	H4_Chest_OPERATOR,
	H4_Chest_OPERATOR_SRFC,
	H4_Chest_PIONEER,
	H4_Chest_PIONEER_ADPT,
	H4_Chest_PATHFINDER,
	H4_Chest_PATHFINDER_CORE,
	H4_Chest_ENGINEER,
	H4_Chest_ENGINEER_EDGE,
	H4_Chest_STALKER,
	H4_Chest_STALKER_CRSH,
	H4_Chest_ROGUE,
	H4_Chest_ROGUE_FCUS,
	H4_Chest_TRACKER,
	H4_Chest_TRACKER_ADRT,
	H4_Chest_VANGUARD,
	H4_Chest_VANGUARD_CNVG,
	H4_Chest_CIO,
	H4_Chest_CIO_WEB,
	H4_Chest_CIO_RUSH,
	H4_Chest_CIO_RUIN,
	H4_Chest_VENATOR,
	H4_Chest_VENATOR_RPTR,
	H4_Chest_VENATOR_BYNT,
	H4_Chest_VENATOR_RFCT,
	H4_Chest_GUNGNIR,
	H4_Chest_GUNGNIR_PULS,
	H4_Chest_COMMANDO,
	H4_Chest_COMMANDO_FRCT,
	H4_Chest_RANGER,
	H4_Chest_RANGER_STRK,
	H4_Chest_PROTECTOR,
	H4_Chest_PROTECTOR_DRFT,
	H4_Chest_MARK_VI,
	H4_Chest_RAIDER,
	H4_Chest_RAIDER_DSTT,
	H4_Chest_FOTUS,

	H4_Visor_RECRUIT,
	H4_Visor_SOLAR,
	H4_Visor_FROST,
	H4_Visor_MIDNIGHT,
	H4_Visor_CYAN,
	H4_Visor_BLINDSIDE,
	H4_Visor_SUNSPOT,
	H4_Visor_VERDANT,
	H4_Visor_LEGENDARY,
	H4_Visor_WETWORK,
	H4_Visor_OPERATOR,
	H4_Visor_PIONEER,
	H4_Visor_PATHFINDER,
	H4_Visor_ENGINEER,
	H4_Visor_STALKER,
	H4_Visor_ROGUE,
	H4_Visor_TRACKER,

	H4_Male,
	H4_Female,

	H4_Color0_Steel,
	H4_Color1_Silver,
	H4_Color2_White,
	H4_Color3_Brown,
	H4_Color4_Tan,
	H4_Color5_Khaki,
	H4_Color6_Sage,
	H4_Color7_Olive,
	H4_Color8_Drab,
	H4_Color9_Forest,
	H4_Color10_Green,
	H4_Color11_SeaFoam,
	H4_Color12_Teal,
	H4_Color13_Aqua,
	H4_Color14_Cyan,
	H4_Color15_Blue,
	H4_Color16_Cobalt,
	H4_Color17_Ice,
	H4_Color18_Violet,
	H4_Color19_Orchid,
	H4_Color20_Lavender,
	H4_Color21_Maroon,
	H4_Color22_Brick,
	H4_Color23_Rose,
	H4_Color24_Rust,
	H4_Color25_Coral,
	H4_Color26_Peach,
	H4_Color27_Gold,
	H4_Color28_Yellow,

	H4_WS_ASSAULTRIFLE_DEFAULT,
	H4_WS_ASSAULTRIFLE_PREDATOR,
	H4_WS_ASSAULTRIFLE_PRIME,
	H4_WS_ASSAULTRIFLE_TIGER,
	H4_WS_ASSAULTRIFLE_TRAUMA,
	H4_WS_ASSAULTRIFLE_TURBINE,
	H4_WS_BATTLERIFLE_DEFAULT,
	H4_WS_BATTLERIFLE_DUNES,
	H4_WS_BATTLERIFLE_ARCTIC,
	H4_WS_BATTLERIFLE_MAC_BLAST,
	H4_WS_BATTLERIFLE_STEAM,
	H4_WS_BATTLERIFLE_FROGMAN,
	H4_WS_DMR_DEFAULT,
	H4_WS_DMR_NOBLE,
	H4_WS_DMR_BLOOD,
	H4_WS_DMR_MONOCLE,
	H4_WS_DMR_TIGER,
	H4_WS_MAGNUM_DEFAULT,
	H4_WS_MAGNUM_STATIC,
	H4_WS_MAGNUM_BRAQUE,
	H4_WS_MAGNUM_COMBUSTION,
	H4_WS_MAGNUM_SOLAR_FLARE,
	H4_WS_STORMRIFLE_DEFAULT,
	H4_WS_STORMRIFLE_COMPRESSION,
	H4_WS_CARBINE_DEFAULT,
	H4_WS_CARBINE_REIGN,
	H4_WS_CARBINE_LOCOMOTIVE,
	H4_WS_PLASMAPISTOL_DEFAULT,
	H4_WS_PLASMAPISTOL_FRACTURE,
	H4_WS_PLASMAPISTOL_BOILERPLATE,
	H4_WS_SUPRESSOR_DEFAULT,
	H4_WS_SUPRESSOR_SHATTER,
	H4_WS_SUPRESSOR_MECHANICAL,
	H4_WS_LIGHTRIFLE_DEFAULT,
	H4_WS_LIGHTRIFLE_IMPRINT,
	H4_WS_LIGHTRIFLE_INDUSTRIAL,
	H4_WS_BOLTSHOT_DEFAULT,
	H4_WS_BOLTSHOT_PISTON,
	H4_WS_BOLTSHOT_ENGINE,

	k_customization_item_count,
	k_customization_item_none = -1
};

struct s_user_skin
{
	long ObjectID;
	long SkinID; // e_customization_item_v2
};

struct s_loadout_slot
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

struct s_custom_key_mapping
{
	long AbstractButton;
	long VirtualKeyCodes[5];
};

struct s_weapon_display_offset
{
	float Y;
	float Z;
};

enum e_abstract_button : long
{
	_abstract_button_jump_v1,
	_abstract_button_switch_grenade_v1,
	_abstract_button_context_primary_v1,
	_abstract_button_reload_v1,
	_abstract_button_switch_weapon_v1,
	_abstract_button_melee_v1,
	_abstract_button_flashlight_v1,
	_abstract_button_throw_grenade_v1,
	_abstract_button_fire_v1,
	_abstract_button_crouch_v1,
	_abstract_button_zoom_v1,
	_abstract_button_zoom_in_v1,
	_abstract_button_zoom_out_v1,
	_abstract_button_exchange_weapon_v1,
	_abstract_button_trick_v1,
	_abstract_button_brake_v1,
	_abstract_button_ebrake_v1,
	_abstract_button_sprint_v1,
	_abstract_button_banshee_bomb_v1,
	_abstract_button_forward_v1,
	_abstract_button_backward_v1,
	_abstract_button_left_v1,
	_abstract_button_right_v1,
	_abstract_button_lean_left_v1,
	_abstract_button_lean_right_v1,
	_abstract_button_start_v1,
	_abstract_button_back_v1,
	_abstract_button_show_scores_v1,
	_abstract_button_accept_v1,
	_abstract_button_cancel_v1,
	_abstract_button_primary_vehicle_trick_v1,
	_abstract_button_secondary_vehicle_trick_v1,
	_abstract_button_magnify_zoom_v1,
	_abstract_button_equipment_v1,

	_abstract_button_fire_secondary_v2,

	_abstract_button_lift_editor_v3,
	_abstract_button_drop_editor_v3,
	_abstract_button_grab_object_editor_v3,
	_abstract_button_boost_editor_v3,
	_abstract_button_crouch_editor_v3,
	_abstract_button_delete_object_editor_v3,
	_abstract_button_create_object_editor_v3,
	_abstract_button_open_tool_menu_editor_v3,
	_abstract_button_switch_player_mode_editor_v3,
	_abstract_button_scope_zoom_editor_v3,
	_abstract_button_player_lock_for_manipulation_editor_v3,
	_abstract_button_show_hide_pannel_theater_v3,
	_abstract_button_show_hide_interface_theater_v3,
	_abstract_button_toggle_first_third_person_view_theater_v3,
	_abstract_button_camera_focus_theater_v3,
	_abstract_button_fast_forward_theater_v3,
	_abstract_button_fast_rewind_theater_v3,
	_abstract_button_stop_continue_playback_theater_v3,
	_abstract_button_playback_speed_up_theater_v3,
	_abstract_button_enter_free_camera_mode_theater_v3,

	_abstract_button_movement_speed_up_theater_v4,

	_abstract_button_panning_camera_theater_v5,
	_abstract_button_camera_move_up_theater_v5,
	_abstract_button_camera_move_down_theater_v5,
	_abstract_button_dual_wield_v5,
	_abstract_button_zoom_camera_theater_v5,

	_abstract_button_toggle_rotation_axes_editor_v6 = _abstract_button_show_hide_pannel_theater_v3,
	_abstract_button_show_hide_pannel_theater_v6,
	_abstract_button_show_hide_interface_theater_v6,
	_abstract_button_toggle_first_third_person_view_theater_v6,
	_abstract_button_camera_focus_theater_v6,
	_abstract_button_fast_forward_theater_v6,
	_abstract_button_fast_rewind_theater_v6,
	_abstract_button_stop_continue_playback_theater_v6,
	_abstract_button_playback_speed_up_theater_v6,
	_abstract_button_enter_free_camera_mode_theater_v6,
	_abstract_button_movement_speed_up_theater_v6,
	_abstract_button_panning_camera_theater_v6,
	_abstract_button_camera_move_up_theater_v6,
	_abstract_button_camera_move_down_theater_v6,
	_abstract_button_dual_wield_v6,
	_abstract_button_duplicate_object_editor_v6,
	_abstract_button_lock_object_editor_v6,
	_abstract_button_reset_orientation_editor_v6,
	_abstract_button_zoom_camera_theater_v6,
	_abstract_button_reload_secondary_v6,
	_abstract_button_previous_grenade_v6,
	_abstract_button_special_action_v6,

	_abstract_button_loadout_menu_v7 = _abstract_button_lift_editor_v3,
	_abstract_button_lift_editor_v7,
	_abstract_button_drop_editor_v7,
	_abstract_button_grab_object_editor_v7,
	_abstract_button_boost_editor_v7,
	_abstract_button_crouch_editor_v7,
	_abstract_button_delete_object_editor_v7,
	_abstract_button_create_object_editor_v7,
	_abstract_button_open_tool_menu_editor_v7,
	_abstract_button_switch_player_mode_editor_v7,
	_abstract_button_scope_zoom_editor_v7,
	_abstract_button_player_lock_for_manipulation_editor_v7,
	_abstract_button_toggle_rotation_axes_editor_v7,
	_abstract_button_show_hide_pannel_theater_v7,
	_abstract_button_show_hide_interface_theater_v7,
	_abstract_button_toggle_first_third_person_view_theater_v7,
	_abstract_button_camera_focus_theater_v7,
	_abstract_button_fast_forward_theater_v7,
	_abstract_button_fast_rewind_theater_v7,
	_abstract_button_stop_continue_playback_theater_v7,
	_abstract_button_playback_speed_up_theater_v7,
	_abstract_button_enter_free_camera_mode_theater_v7,
	_abstract_button_movement_speed_up_theater_v7,
	_abstract_button_panning_camera_theater_v7,
	_abstract_button_camera_move_up_theater_v7,
	_abstract_button_camera_move_down_theater_v7,
	_abstract_button_dual_wield_v7,
	_abstract_button_duplicate_object_editor_v7,
	_abstract_button_lock_object_editor_v7,
	_abstract_button_reset_orientation_editor_v7,
	_abstract_button_zoom_camera_theater_v7,
	_abstract_button_reload_secondary_v7,
	_abstract_button_previous_grenade_v7,
	_abstract_button_special_action_v7,

	k_number_of_abstract_buttons,

	k_number_of_abstract_buttons_v1 = _abstract_button_equipment_v1 + 1,
	k_number_of_abstract_buttons_v2 = _abstract_button_fire_secondary_v2 + 1,
	k_number_of_abstract_buttons_v3 = _abstract_button_enter_free_camera_mode_theater_v3 + 1,
	k_number_of_abstract_buttons_v4 = _abstract_button_movement_speed_up_theater_v4 + 1,
	k_number_of_abstract_buttons_v5 = _abstract_button_zoom_camera_theater_v5 + 1,
	k_number_of_abstract_buttons_v6 = _abstract_button_special_action_v6 + 1,
	k_number_of_abstract_buttons_v7 = _abstract_button_special_action_v7 + 1,
};

template<size_t abstract_button_count>
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
	bool LockMaxAspectRatio;
	char __padding1[2];
	long PlayerModelPermutation;
	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	float VerticalLookSensitivity;
	float HorizontalLookSensitivity;
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
	bool DualWieldInverted;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding2[2];
	s_loadout_slot LoadoutSlots[5];
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
	s_custom_key_mapping CustomKeyboardMouseMappings[abstract_button_count];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding4[20];
	long Brightness;
};

template<size_t abstract_button_count>
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
	bool LockMaxAspectRatio;
	char __padding0[2];
	long PlayerModelPermutation;

	/* new in this version */ long HelmetIndex;
	/* new in this version */ long LeftShoulderIndex;
	/* new in this version */ long RightShoulderIndex;
	/* new in this version */ long ChestIndex;
	/* new in this version */ long WristIndex;
	/* new in this version */ long UtilityIndex;
	/* new in this version */ long PaintSchemeIndex;
	/* new in this version */ long VisorColorIndex;
	/* new in this version */ long SpartanArmorEffectIndex;
	/* new in this version */ long SpartanBodyIndex;
	/* new in this version */ long EliteArmorIndex;
	/* new in this version */ long EliteArmorEffectIndex;
	/* new in this version */ long VoiceIndex;
	/* new in this version */ long PlayerModelPrimaryColor;
	/* new in this version */ long PlayerModelSecondaryColor;
	/* new in this version */ long PlayerModelTertiaryColor;

	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	float VerticalLookSensitivity;
	float HorizontalLookSensitivity;
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
	bool DualWieldInverted;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding1[2];
	s_loadout_slot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding2[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	s_custom_key_mapping CustomKeyboardMouseMappings[abstract_button_count];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding3[16];
	long Brightness;
};

template<size_t abstract_button_count>
struct s_player_configuration_v4 : s_player_configuration_v2<abstract_button_count>
{
	/* new in this version */ s_weapon_display_offset WeaponDisplayOffsets[5];
};

template<size_t abstract_button_count>
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
	bool LockMaxAspectRatio;
	char __padding0[2];
	long PlayerModelPermutation;

	long HelmetIndex;
	long LeftShoulderIndex;
	long RightShoulderIndex;
	long ChestIndex;
	long WristIndex;
	long UtilityIndex;
	long PaintSchemeIndex;
	long VisorColorIndex;
	long SpartanArmorEffectIndex;
	long SpartanBodyIndex;
	long EliteArmorIndex;
	long EliteArmorEffectIndex;
	long VoiceIndex;
	long PlayerModelPrimaryColor;
	long PlayerModelSecondaryColor;
	long PlayerModelTertiaryColor;

	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	float VerticalLookSensitivity;
	float HorizontalLookSensitivity;
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
	bool DualWieldInverted;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding1[2];
	s_loadout_slot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding2[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	s_custom_key_mapping CustomKeyboardMouseMappings[abstract_button_count];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding3[16];
	long Brightness;
	s_weapon_display_offset WeaponDisplayOffsets[5];
};

template<size_t abstract_button_count, size_t user_skin_count>
struct s_player_configuration_v7
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
	bool LockMaxAspectRatio;
	char __padding0;

	/* new in this version */ bool UsersSkinsEnabled;

	long PlayerModelPermutation;

	long HelmetIndex;
	long LeftShoulderIndex;
	long RightShoulderIndex;
	long ChestIndex;
	long WristIndex;
	long UtilityIndex;

	/* new in this version */ long ArmsIndex;
	/* new in this version */ long LegsIndex;

	long PaintSchemeIndex;
	long VisorColorIndex;
	long SpartanArmorEffectIndex;
	long SpartanBodyIndex;
	long EliteArmorIndex;
	long EliteArmorEffectIndex;

	/* new in this version */ long EliteHelmetIndex;
	/* new in this version */ long EliteLeftShoulderIndex;
	/* new in this version */ long EliteRightShoulderIndex;
	/* new in this version */ long EliteChestIndex;
	/* new in this version */ long MaybeEliteWristIndex;
	/* new in this version */ long MaybeEliteUtilityIndex;
	/* new in this version */ long EliteArmsIndex;
	/* new in this version */ long EliteLegsIndex;

	long VoiceIndex;
	long PlayerModelPrimaryColor;
	long PlayerModelSecondaryColor;
	long PlayerModelTertiaryColor;

	/* new in this version */ s_user_skin UserSkins[user_skin_count];

	wchar_t ServiceTag[4];
	long OnlineMedalFlasher;
	float VerticalLookSensitivity;
	float HorizontalLookSensitivity;
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
	char __unknown0[16];
	bool SwapTriggersAndBumpers;
	bool UseModernAimControl;
	bool UseDoublePressJumpToJetpack;
	bool DualWieldInverted;
	char EnemyPlayerNameColor;
	char GameEngineTimer;
	char __padding1[2];
	s_loadout_slot LoadoutSlots[5];
	char GameSpecific[256];
	float MouseSensitivity;
	bool MouseSmoothing;
	bool MouseAcceleration;
	char __padding2[2];
	float MouseAccelerationMinRate;
	float MouseAccelerationMaxAccel;
	float MouseAccelerationScale;
	float MouseAccelerationExp;
	long KeyboardMouseButtonPreset;
	s_custom_key_mapping CustomKeyboardMouseMappings[abstract_button_count];
	float MasterVolume;
	float MusicVolume;
	float SfxVolume;
	char __padding3[16];
	long Brightness;
	s_weapon_display_offset WeaponDisplayOffsets[5];
};

using t_player_configuration_v1 = s_player_configuration_v1<k_number_of_abstract_buttons_v1>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v1, 0x624);
using t_player_configuration_v2 = s_player_configuration_v2<k_number_of_abstract_buttons_v1>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v2, 0x664);
using t_player_configuration_v3 = s_player_configuration_v2<k_number_of_abstract_buttons_v2>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v3, 0x67C);
using t_player_configuration_v4 = s_player_configuration_v4<k_number_of_abstract_buttons_v3>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v4, 0x884);
using t_player_configuration_v5 = s_player_configuration_v4<k_number_of_abstract_buttons_v4>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v5, 0x89C);
using t_player_configuration_v6 = s_player_configuration_v6<k_number_of_abstract_buttons_v5>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v6, 0x924);
using t_player_configuration_v7 = s_player_configuration_v7<k_number_of_abstract_buttons_v6, 15>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v7, 0xA6C);
using t_player_configuration_v8 = s_player_configuration_v7<k_number_of_abstract_buttons_v6, 32>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v8, 0xAF4);
using t_player_configuration_v9 = s_player_configuration_v7<k_number_of_abstract_buttons_v7, 32>;
CHECK_STRUCTURE_SIZE(t_player_configuration_v9, 0xB0C);

enum e_player_configuration_version
{
	_player_configuration_version_1,
	_player_configuration_version_2,
	_player_configuration_version_3,
	_player_configuration_version_4,
	_player_configuration_version_5,
	_player_configuration_version_6,
	_player_configuration_version_7,
	_player_configuration_version_8,
	_player_configuration_version_9,
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
		t_player_configuration_v7 player_configuration_v7;
		t_player_configuration_v8 player_configuration_v8;
		t_player_configuration_v9 player_configuration_v9;
	};
public:
	e_player_configuration_version const player_configuration_version;
	e_abstract_button const abstract_button_count;
	bool waiting_on_file_save;

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
	bool& LockMaxAspectRatio;
	bool& UsersSkinsEnabled;
	long& PlayerModelPermutation;
	long& HelmetIndex;
	long& LeftShoulderIndex;
	long& RightShoulderIndex;
	long& ChestIndex;
	long& WristIndex;
	long& UtilityIndex;
	long& ArmsIndex;
	long& LegsIndex;
	long& PaintSchemeIndex;
	long& VisorColorIndex;
	long& SpartanArmorEffectIndex;
	long& SpartanBodyIndex;
	long& EliteArmorIndex;
	long& EliteArmorEffectIndex;
	long& EliteHelmetIndex;
	long& EliteLeftShoulderIndex;
	long& EliteRightShoulderIndex;
	long& EliteChestIndex;
	long& MaybeEliteWristIndex;
	long& MaybeEliteUtilityIndex;
	long& EliteArmsIndex;
	long& EliteLegsIndex;
	long& VoiceIndex;
	long& PlayerModelPrimaryColor;
	long& PlayerModelSecondaryColor;
	long& PlayerModelTertiaryColor;
	//s_user_skin(&UserSkins)[user_skin_count];
	wchar_t(&ServiceTag)[4];
	long& OnlineMedalFlasher;
	float& VerticalLookSensitivity;
	float& HorizontalLookSensitivity;
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
	bool& SwapTriggersAndBumpers;
	bool& UseModernAimControl;
	bool& UseDoublePressJumpToJetpack;
	char& EnemyPlayerNameColor;
	char& GameEngineTimer;
	s_loadout_slot(&LoadoutSlots)[5];
	char(&GameSpecific)[256];
	float& MouseSensitivity;
	bool& MouseSmoothing;
	bool& MouseAcceleration;
	float& MouseAccelerationMinRate;
	float& MouseAccelerationMaxAccel;
	float& MouseAccelerationScale;
	float& MouseAccelerationExp;
	long& KeyboardMouseButtonPreset;
	//s_custom_key_mapping(&CustomKeyboardMouseMappings)[abstract_button_count];
	float& MasterVolume;
	float& MusicVolume;
	float& SfxVolume;
	long& Brightness;
	s_weapon_display_offset(&WeaponDisplayOffsets)[5];

private:

#define player_configuration_reference_getter_v1(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_1: return &player_configuration_v1.field_name; \
		case _player_configuration_version_2: return &player_configuration_v2.field_name; \
		case _player_configuration_version_3: return &player_configuration_v3.field_name; \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		case _player_configuration_version_8: return &player_configuration_v8.field_name; \
		case _player_configuration_version_9: return &player_configuration_v9.field_name; \
		} \
		return nullptr; \
	}
#define player_configuration_reference_getter_v2(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_2: return &player_configuration_v2.field_name; \
		case _player_configuration_version_3: return &player_configuration_v3.field_name; \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		case _player_configuration_version_8: return &player_configuration_v8.field_name; \
		case _player_configuration_version_9: return &player_configuration_v9.field_name; \
		} \
		return nullptr; \
	}
#define player_configuration_reference_getter_v3(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_3: return &player_configuration_v3.field_name; \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		case _player_configuration_version_8: return &player_configuration_v8.field_name; \
		case _player_configuration_version_9: return &player_configuration_v9.field_name; \
		} \
		return nullptr; \
	}
#define player_configuration_reference_getter_v4(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_4: return &player_configuration_v4.field_name; \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		case _player_configuration_version_8: return &player_configuration_v8.field_name; \
		case _player_configuration_version_9: return &player_configuration_v9.field_name; \
		} \
		return nullptr; \
	}
#define player_configuration_reference_getter_v5(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_5: return &player_configuration_v5.field_name; \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		case _player_configuration_version_8: return &player_configuration_v8.field_name; \
		case _player_configuration_version_9: return &player_configuration_v9.field_name; \
		} \
		return nullptr; \
	}
#define player_configuration_reference_getter_v6(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_6: return &player_configuration_v6.field_name; \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		case _player_configuration_version_8: return &player_configuration_v8.field_name; \
		case _player_configuration_version_9: return &player_configuration_v9.field_name; \
		} \
		return nullptr; \
	}
#define player_configuration_reference_getter_v7(field_name) \
	decltype(&field_name) Get##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		case _player_configuration_version_8: return &player_configuration_v8.field_name; \
		case _player_configuration_version_9: return &player_configuration_v9.field_name; \
		} \
		return nullptr; \
	}

	player_configuration_reference_getter_v1(SubtitleSetting);
	player_configuration_reference_getter_v1(CrosshairLocation);
	player_configuration_reference_getter_v1(FOVSetting);
	player_configuration_reference_getter_v2(VehicleFOVSetting);
	player_configuration_reference_getter_v1(LookControlsInverted);
	player_configuration_reference_getter_v2(MouseLookControlsInverted);
	player_configuration_reference_getter_v1(VibrationDisabled);
	player_configuration_reference_getter_v1(ImpulseTriggersDisabled);
	player_configuration_reference_getter_v1(AircraftControlsInverted);
	player_configuration_reference_getter_v2(MouseAircraftControlsInverted);
	player_configuration_reference_getter_v1(AutoCenterEnabled);
	player_configuration_reference_getter_v1(CrouchLockEnabled);
	player_configuration_reference_getter_v2(MKCrouchLockEnabled);
	player_configuration_reference_getter_v1(ClenchProtectionEnabled);
	player_configuration_reference_getter_v1(UseFemaleVoice);
	player_configuration_reference_getter_v1(HoldToZoom);
	player_configuration_reference_getter_v1(PlayerModelPrimaryColorIndex);
	player_configuration_reference_getter_v1(PlayerModelSecondaryColorIndex);
	player_configuration_reference_getter_v1(PlayerModelTertiaryColorIndex);
	player_configuration_reference_getter_v1(UseEliteModel);
	player_configuration_reference_getter_v1(LockMaxAspectRatio);
	player_configuration_reference_getter_v7(UsersSkinsEnabled);
	player_configuration_reference_getter_v1(PlayerModelPermutation);
	player_configuration_reference_getter_v2(HelmetIndex);
	player_configuration_reference_getter_v2(LeftShoulderIndex);
	player_configuration_reference_getter_v2(RightShoulderIndex);
	player_configuration_reference_getter_v2(ChestIndex);
	player_configuration_reference_getter_v2(WristIndex);
	player_configuration_reference_getter_v2(UtilityIndex);
	player_configuration_reference_getter_v7(ArmsIndex);
	player_configuration_reference_getter_v7(LegsIndex);
	player_configuration_reference_getter_v2(PaintSchemeIndex);
	player_configuration_reference_getter_v2(VisorColorIndex);
	player_configuration_reference_getter_v2(SpartanArmorEffectIndex);
	player_configuration_reference_getter_v2(SpartanBodyIndex);
	player_configuration_reference_getter_v2(EliteArmorIndex);
	player_configuration_reference_getter_v2(EliteArmorEffectIndex);
	player_configuration_reference_getter_v7(EliteHelmetIndex);
	player_configuration_reference_getter_v7(EliteLeftShoulderIndex);
	player_configuration_reference_getter_v7(EliteRightShoulderIndex);
	player_configuration_reference_getter_v7(EliteChestIndex);
	player_configuration_reference_getter_v7(MaybeEliteWristIndex);
	player_configuration_reference_getter_v7(MaybeEliteUtilityIndex);
	player_configuration_reference_getter_v7(EliteArmsIndex);
	player_configuration_reference_getter_v7(EliteLegsIndex);
	player_configuration_reference_getter_v2(VoiceIndex);
	player_configuration_reference_getter_v2(PlayerModelPrimaryColor);
	player_configuration_reference_getter_v2(PlayerModelSecondaryColor);
	player_configuration_reference_getter_v2(PlayerModelTertiaryColor);
	player_configuration_reference_getter_v1(ServiceTag);
	player_configuration_reference_getter_v1(OnlineMedalFlasher);
	player_configuration_reference_getter_v1(VerticalLookSensitivity);
	player_configuration_reference_getter_v1(HorizontalLookSensitivity);
	player_configuration_reference_getter_v1(LookAcceleration);
	player_configuration_reference_getter_v1(LookAxialDeadZone);
	player_configuration_reference_getter_v1(LookRadialDeadZone);
	player_configuration_reference_getter_v1(ZoomLookSensitivityMultiplier);
	player_configuration_reference_getter_v1(VehicleLookSensitivityMultiplier);
	player_configuration_reference_getter_v1(ButtonPreset);
	player_configuration_reference_getter_v1(StickPreset);
	player_configuration_reference_getter_v1(LeftyToggle);
	player_configuration_reference_getter_v1(FlyingCameraTurnSensitivity);
	player_configuration_reference_getter_v1(FlyingCameraPanning);
	player_configuration_reference_getter_v1(FlyingCameraSpeed);
	player_configuration_reference_getter_v1(FlyingCameraThrust);
	player_configuration_reference_getter_v1(TheaterTurnSensitivity);
	player_configuration_reference_getter_v1(TheaterPanning);
	player_configuration_reference_getter_v1(TheaterSpeed);
	player_configuration_reference_getter_v1(TheaterThrust);
	player_configuration_reference_getter_v1(SwapTriggersAndBumpers);
	player_configuration_reference_getter_v1(UseModernAimControl);
	player_configuration_reference_getter_v1(UseDoublePressJumpToJetpack);
	player_configuration_reference_getter_v1(EnemyPlayerNameColor);
	player_configuration_reference_getter_v1(GameEngineTimer);
	player_configuration_reference_getter_v1(LoadoutSlots);
	player_configuration_reference_getter_v1(GameSpecific);
	player_configuration_reference_getter_v1(MouseSensitivity);
	player_configuration_reference_getter_v1(MouseSmoothing);
	player_configuration_reference_getter_v1(MouseAcceleration);
	player_configuration_reference_getter_v1(MouseAccelerationMinRate);
	player_configuration_reference_getter_v1(MouseAccelerationMaxAccel);
	player_configuration_reference_getter_v1(MouseAccelerationScale);
	player_configuration_reference_getter_v1(MouseAccelerationExp);
	player_configuration_reference_getter_v1(KeyboardMouseButtonPreset);
	player_configuration_reference_getter_v1(MasterVolume);
	player_configuration_reference_getter_v1(MusicVolume);
	player_configuration_reference_getter_v1(SfxVolume);
	player_configuration_reference_getter_v1(Brightness);
	player_configuration_reference_getter_v4(WeaponDisplayOffsets)

#undef player_configuration_reference_getter_v1
#undef player_configuration_reference_getter_v2
#undef player_configuration_reference_getter_v3
#undef player_configuration_reference_getter_v4
#undef player_configuration_reference_getter_v5
#undef player_configuration_reference_getter_v6
#undef player_configuration_reference_getter_v7

	class c_virtual_player_configuration_user_skins_interface
	{
	public:
		c_virtual_player_configuration_user_skins_interface(c_player_configuration& parent) :
			parent(parent)
		{ }

		c_player_configuration& parent;

		s_user_skin& operator[](size_t user_skin_index) const
		{
			switch (parent.player_configuration_version)
			{
			case _player_configuration_version_7: return parent.player_configuration_v7.UserSkins[user_skin_index];
			case _player_configuration_version_8: return parent.player_configuration_v8.UserSkins[user_skin_index];
			case _player_configuration_version_9: return parent.player_configuration_v9.UserSkins[user_skin_index];
			}
			throw;
		}
	};

	class c_virtual_player_configuration_game_keyboard_mouse_mapping_interface
	{
	public:
		c_virtual_player_configuration_game_keyboard_mouse_mapping_interface(c_player_configuration& parent) :
			parent(parent)
		{ }

		c_player_configuration& parent;

		s_custom_key_mapping& operator[](size_t abstract_button_index) const
		{
			switch (parent.player_configuration_version)
			{
			case _player_configuration_version_1: return parent.player_configuration_v1.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_2: return parent.player_configuration_v2.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_3: return parent.player_configuration_v3.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_4: return parent.player_configuration_v4.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_5: return parent.player_configuration_v5.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_6: return parent.player_configuration_v6.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_7: return parent.player_configuration_v7.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_8: return parent.player_configuration_v8.CustomKeyboardMouseMappings[abstract_button_index];
			case _player_configuration_version_9: return parent.player_configuration_v9.CustomKeyboardMouseMappings[abstract_button_index];
			}
			throw;
		}
	};

	e_abstract_button GetAbstractButtonCount()
	{
		switch (player_configuration_version)
		{
		case _player_configuration_version_1:
		case _player_configuration_version_2:
			return k_number_of_abstract_buttons_v1;
		case _player_configuration_version_3:
			return k_number_of_abstract_buttons_v2;
		case _player_configuration_version_4:
			return k_number_of_abstract_buttons_v3;
		case _player_configuration_version_5:
			return k_number_of_abstract_buttons_v4;
		case _player_configuration_version_6:
			return k_number_of_abstract_buttons_v5;
		case _player_configuration_version_7:
		case _player_configuration_version_8:
			return k_number_of_abstract_buttons_v6;
		case _player_configuration_version_9:
			return k_number_of_abstract_buttons_v7;
		}

		return k_number_of_abstract_buttons;
	}

public:
	c_virtual_player_configuration_user_skins_interface UserSkins;
	c_virtual_player_configuration_game_keyboard_mouse_mapping_interface CustomKeyboardMouseMappings;

	c_player_configuration(e_player_configuration_version player_configuration_version) :
		player_configuration_v1(),
		//player_configuration_v2(),
		//player_configuration_v3(),
		//player_configuration_v4(),
		//player_configuration_v5(),
		//player_configuration_v6(),

		player_configuration_version(player_configuration_version),
		abstract_button_count(GetAbstractButtonCount()),
		waiting_on_file_save(false),

		SubtitleSetting(*GetSubtitleSetting()),
		CrosshairLocation(*GetCrosshairLocation()),
		FOVSetting(*GetFOVSetting()),
		VehicleFOVSetting(*GetVehicleFOVSetting()),
		LookControlsInverted(*GetLookControlsInverted()),
		MouseLookControlsInverted(*GetMouseLookControlsInverted()),
		VibrationDisabled(*GetVibrationDisabled()),
		ImpulseTriggersDisabled(*GetImpulseTriggersDisabled()),
		AircraftControlsInverted(*GetAircraftControlsInverted()),
		MouseAircraftControlsInverted(*GetMouseAircraftControlsInverted()),
		AutoCenterEnabled(*GetAutoCenterEnabled()),
		CrouchLockEnabled(*GetCrouchLockEnabled()),
		MKCrouchLockEnabled(*GetMKCrouchLockEnabled()),
		ClenchProtectionEnabled(*GetClenchProtectionEnabled()),
		UseFemaleVoice(*GetUseFemaleVoice()),
		HoldToZoom(*GetHoldToZoom()),
		PlayerModelPrimaryColorIndex(*GetPlayerModelPrimaryColorIndex()),
		PlayerModelSecondaryColorIndex(*GetPlayerModelSecondaryColorIndex()),
		PlayerModelTertiaryColorIndex(*GetPlayerModelTertiaryColorIndex()),
		UseEliteModel(*GetUseEliteModel()),
		LockMaxAspectRatio(*GetLockMaxAspectRatio()),
		UsersSkinsEnabled(*GetUsersSkinsEnabled()),
		PlayerModelPermutation(*GetPlayerModelPermutation()),
		HelmetIndex(*GetHelmetIndex()),
		LeftShoulderIndex(*GetLeftShoulderIndex()),
		RightShoulderIndex(*GetRightShoulderIndex()),
		ChestIndex(*GetChestIndex()),
		WristIndex(*GetWristIndex()),
		UtilityIndex(*GetUtilityIndex()),
		ArmsIndex(*GetArmsIndex()),
		LegsIndex(*GetLegsIndex()),
		PaintSchemeIndex(*GetPaintSchemeIndex()),
		VisorColorIndex(*GetVisorColorIndex()),
		SpartanArmorEffectIndex(*GetSpartanArmorEffectIndex()),
		SpartanBodyIndex(*GetSpartanBodyIndex()),
		EliteArmorIndex(*GetEliteArmorIndex()),
		EliteArmorEffectIndex(*GetEliteArmorEffectIndex()),
		EliteHelmetIndex(*GetEliteHelmetIndex()),
		EliteLeftShoulderIndex(*GetEliteLeftShoulderIndex()),
		EliteRightShoulderIndex(*GetEliteRightShoulderIndex()),
		EliteChestIndex(*GetEliteChestIndex()),
		MaybeEliteWristIndex(*GetMaybeEliteWristIndex()),
		MaybeEliteUtilityIndex(*GetMaybeEliteUtilityIndex()),
		EliteArmsIndex(*GetEliteArmsIndex()),
		EliteLegsIndex(*GetEliteLegsIndex()),
		VoiceIndex(*GetVoiceIndex()),
		PlayerModelPrimaryColor(*GetPlayerModelPrimaryColor()),
		PlayerModelSecondaryColor(*GetPlayerModelSecondaryColor()),
		PlayerModelTertiaryColor(*GetPlayerModelTertiaryColor()),
		UserSkins(*this),
		ServiceTag(*GetServiceTag()),
		OnlineMedalFlasher(*GetOnlineMedalFlasher()),
		VerticalLookSensitivity(*GetVerticalLookSensitivity()),
		HorizontalLookSensitivity(*GetHorizontalLookSensitivity()),
		LookAcceleration(*GetLookAcceleration()),
		LookAxialDeadZone(*GetLookAxialDeadZone()),
		LookRadialDeadZone(*GetLookRadialDeadZone()),
		ZoomLookSensitivityMultiplier(*GetZoomLookSensitivityMultiplier()),
		VehicleLookSensitivityMultiplier(*GetVehicleLookSensitivityMultiplier()),
		ButtonPreset(*GetButtonPreset()),
		StickPreset(*GetStickPreset()),
		LeftyToggle(*GetLeftyToggle()),
		FlyingCameraTurnSensitivity(*GetFlyingCameraTurnSensitivity()),
		FlyingCameraPanning(*GetFlyingCameraPanning()),
		FlyingCameraSpeed(*GetFlyingCameraSpeed()),
		FlyingCameraThrust(*GetFlyingCameraThrust()),
		TheaterTurnSensitivity(*GetTheaterTurnSensitivity()),
		TheaterPanning(*GetTheaterPanning()),
		TheaterSpeed(*GetTheaterSpeed()),
		TheaterThrust(*GetTheaterThrust()),
		SwapTriggersAndBumpers(*GetSwapTriggersAndBumpers()),
		UseModernAimControl(*GetUseModernAimControl()),
		UseDoublePressJumpToJetpack(*GetUseDoublePressJumpToJetpack()),
		EnemyPlayerNameColor(*GetEnemyPlayerNameColor()),
		GameEngineTimer(*GetGameEngineTimer()),
		LoadoutSlots(*GetLoadoutSlots()),
		GameSpecific(*GetGameSpecific()),
		MouseSensitivity(*GetMouseSensitivity()),
		MouseSmoothing(*GetMouseSmoothing()),
		MouseAcceleration(*GetMouseAcceleration()),
		MouseAccelerationMinRate(*GetMouseAccelerationMinRate()),
		MouseAccelerationMaxAccel(*GetMouseAccelerationMaxAccel()),
		MouseAccelerationScale(*GetMouseAccelerationScale()),
		MouseAccelerationExp(*GetMouseAccelerationExp()),
		KeyboardMouseButtonPreset(*GetKeyboardMouseButtonPreset()),
		CustomKeyboardMouseMappings(*this),
		MasterVolume(*GetMasterVolume()),
		MusicVolume(*GetMusicVolume()),
		SfxVolume(*GetSfxVolume()),
		Brightness(*GetBrightness()),
		WeaponDisplayOffsets(*GetWeaponDisplayOffsets())
	{
		memset(&player_configuration_v1, 0, sizeof(player_configuration_v1));
		memset(&player_configuration_v2, 0, sizeof(player_configuration_v2));
		memset(&player_configuration_v3, 0, sizeof(player_configuration_v3));
		memset(&player_configuration_v4, 0, sizeof(player_configuration_v4));
		memset(&player_configuration_v5, 0, sizeof(player_configuration_v5));
		memset(&player_configuration_v6, 0, sizeof(player_configuration_v6));
		memset(&player_configuration_v7, 0, sizeof(player_configuration_v7));
		memset(&player_configuration_v8, 0, sizeof(player_configuration_v8));
		memset(&player_configuration_v9, 0, sizeof(player_configuration_v9));
	}
};

void save_player_configuration_to_file(c_player_configuration& player_configuration);
void load_player_configuration_from_file(c_player_configuration& player_configuration, e_build build, e_engine_type engine_type);
