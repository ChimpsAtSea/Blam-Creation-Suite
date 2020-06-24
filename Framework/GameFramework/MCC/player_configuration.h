#pragma once

enum class e_customization_item_v1 : long
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

enum class e_customization_item_v2 : long
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

struct s_customization_item_skin
{
	long object;
	long skin; // e_customization_item_v2
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

struct s_weapon_display_offset
{
	float y;
	float z;
};

enum e_game_action : long
{
	_game_action_v1_jump,
	_game_action_v1_switch_grenade,
	_game_action_v1_context_primary,
	_game_action_v1_reload,
	_game_action_v1_switch_weapon,
	_game_action_v1_melee,
	_game_action_v1_flashlight,
	_game_action_v1_throw_grenade,
	_game_action_v1_fire,
	_game_action_v1_crouch,
	_game_action_v1_zoom,
	_game_action_v1_zoom_in,
	_game_action_v1_zoom_out,
	_game_action_v1_exchange_weapon,
	_game_action_v1_trick,
	_game_action_v1_brake,
	_game_action_v1_ebrake,
	_game_action_v1_sprint,
	_game_action_v1_banshee_bomb,
	_game_action_v1_forward,
	_game_action_v1_backward,
	_game_action_v1_left,
	_game_action_v1_right,
	_game_action_v1_lean_left,
	_game_action_v1_lean_right,
	_game_action_v1_start,
	_game_action_v1_back,
	_game_action_v1_show_scores,
	_game_action_v1_accept,
	_game_action_v1_cancel,
	_game_action_v1_primary_vehicle_trick,
	_game_action_v1_secondary_vehicle_trick,
	_game_action_v1_magnify_zoom,
	_game_action_v1_equipment,

	_game_action_v2_fire_secondary,

	_game_action_v3_lift_editor,
	_game_action_v3_drop_editor,
	_game_action_v3_grab_object_editor,
	_game_action_v3_boost_editor,
	_game_action_v3_crouch_editor,
	_game_action_v3_delete_object_editor,
	_game_action_v3_create_object_editor,
	_game_action_v3_open_tool_menu_editor,
	_game_action_v3_switch_player_mode_editor,
	_game_action_v3_scope_zoom_editor,
	_game_action_v3_player_lock_for_manipulation_editor,
	_game_action_v3_show_hide_pannel_theater,
	_game_action_v3_show_hide_interface_theater,
	_game_action_v3_toggle_first_third_person_view_theater,
	_game_action_v3_camera_focus_theater,
	_game_action_v3_fast_forward_theater,
	_game_action_v3_fast_rewind_theater,
	_game_action_v3_stop_continue_playback_theater,
	_game_action_v3_playback_speed_up_theater,
	_game_action_v3_enter_free_camera_mode_theater,

	_game_action_v4_movement_speed_up_theater,

	_game_action_v5_panning_camera_theater,
	_game_action_v5_camera_move_up_theater,
	_game_action_v5_camera_move_down_theater,
	_game_action_v5_dual_wield,
	_game_action_v5_zoom_camera_theater,

	_game_action_v6_toggle_rotation_axes_editor = _game_action_v3_show_hide_pannel_theater,
	_game_action_v6_show_hide_pannel_theater,
	_game_action_v6_show_hide_interface_theater,
	_game_action_v6_toggle_first_third_person_view_theater,
	_game_action_v6_camera_focus_theater,
	_game_action_v6_fast_forward_theater,
	_game_action_v6_fast_rewind_theater,
	_game_action_v6_stop_continue_playback_theater,
	_game_action_v6_playback_speed_up_theater,
	_game_action_v6_enter_free_camera_mode_theater,
	_game_action_v6_movement_speed_up_theater,
	_game_action_v6_panning_camera_theater,
	_game_action_v6_camera_move_up_theater,
	_game_action_v6_camera_move_down_theater,
	_game_action_v6_dual_wield,
	_game_action_v6_duplicate_object_editor,
	_game_action_v6_lock_object_editor,
	_game_action_v6_reset_orientation_editor,
	_game_action_v6_zoom_camera_theater,
	_game_action_v6_reload_secondary,
	_game_action_v6_previous_grenade,
	_game_action_v6_special_action,

	k_number_of_game_actions,

	k_number_of_game_actions_v1 = _game_action_v1_equipment + 1,
	k_number_of_game_actions_v2 = _game_action_v2_fire_secondary + 1,
	k_number_of_game_actions_v3 = _game_action_v3_enter_free_camera_mode_theater + 1,
	k_number_of_game_actions_v4 = _game_action_v4_movement_speed_up_theater + 1,
	k_number_of_game_actions_v5 = _game_action_v5_zoom_camera_theater + 1,
	k_number_of_game_actions_v6 = _game_action_v6_special_action + 1,
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
	bool lock_max_aspect_ratio;
	char __padding1[2];
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
	bool dual_wield_inverted;
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
	long master_volume;
	long music_volume;
	long sfx_volume;
	char __padding4[20];
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
	bool lock_max_aspect_ratio;
	char __padding0[2];
	long player_model_permutation;
	/* new in this version */ long helmet_index;					 // e_customization_item_v1
	/* new in this version */ long left_shoulder_index;				 // e_customization_item_v1
	/* new in this version */ long right_shoulder_index;			 // e_customization_item_v1
	/* new in this version */ long chest_index;						 // e_customization_item_v1
	/* new in this version */ long wrist_index;						 // e_customization_item_v1
	/* new in this version */ long utility_index;					 // e_customization_item_v1
	/* new in this version */ long knee_guards_index;				 // e_customization_item_v1
	/* new in this version */ long visor_color_index;				 // e_customization_item_v1
	/* new in this version */ long spartan_armor_effect_index;		 // e_customization_item_v1
	/* new in this version */ long spartan_body_index;				 // e_customization_item_v1
	/* new in this version */ long elite_armor_index;				 // e_customization_item_v1
	/* new in this version */ long elite_armor_effect_index;		 // e_customization_item_v1
	/* new in this version */ long voice_index;						 // e_customization_item_v1
	/* new in this version */ long player_model_primary_color;		 // e_customization_item_v1
	/* new in this version */ long player_model_secondary_color;	 // e_customization_item_v1
	/* new in this version */ long player_model_tertiary_color;		 // e_customization_item_v1
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
	bool dual_wield_inverted;
	char enemy_player_name_color;
	char game_engine_timer;
	char __padding1[2];
	s_loadout_slot loadout_slots[5];
	char game_specific[256];
	float mouse_sensitivity;
	bool mouse_smoothing;
	bool mouse_acceleration;
	char __padding2[2];
	float mouse_acceleration_min_rate;
	float mouse_acceleration_max_accel;
	float mouse_acceleration_scale;
	float mouse_acceleration_exp;
	long keyboard_mouse_button_preset;
	s_game_keyboard_mouse_mapping game_keyboard_mouse_mappings[game_actions_count];
	long master_volume;
	long music_volume;
	long sfx_volume;
	char __padding3[16];
	long brightness;
};

template<size_t game_actions_count>
struct s_player_configuration_v4 : s_player_configuration_v2<game_actions_count>
{
	/* new in this version */ s_weapon_display_offset weapon_display_offsets[5];
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
	bool lock_max_aspect_ratio;
	char __padding0[2];
	long player_model_permutation;

	long helmet_index;												 // e_customization_item_v1
	long left_shoulder_index;										 // e_customization_item_v1
	long right_shoulder_index;										 // e_customization_item_v1
	long chest_index;												 // e_customization_item_v1
	long wrist_index;												 // e_customization_item_v1
	long utility_index;												 // e_customization_item_v1
	long knee_guards_index;											 // e_customization_item_v1
	long visor_color_index;											 // e_customization_item_v1
	long spartan_armor_effect_index;								 // e_customization_item_v1
	long spartan_body_index;										 // e_customization_item_v1
	long elite_armor_index;											 // e_customization_item_v1
	long elite_armor_effect_index;									 // e_customization_item_v1
	long voice_index;												 // e_customization_item_v1
	long player_model_primary_color;								 // e_customization_item_v1
	long player_model_secondary_color;								 // e_customization_item_v1
	long player_model_tertiary_color;								 // e_customization_item_v1

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
	bool dual_wield_inverted;
	char enemy_player_name_color;
	char game_engine_timer;
	char __padding1[2];
	s_loadout_slot loadout_slots[5];
	char game_specific[256];
	float mouse_sensitivity;
	bool mouse_smoothing;
	bool mouse_acceleration;
	char __padding2[2];
	float mouse_acceleration_min_rate;
	float mouse_acceleration_max_accel;
	float mouse_acceleration_scale;
	float mouse_acceleration_exp;
	long keyboard_mouse_button_preset;
	s_game_keyboard_mouse_mapping game_keyboard_mouse_mappings[game_actions_count];
	long master_volume;
	long music_volume;
	long sfx_volume;
	char __padding3[16];
	long brightness;
	s_weapon_display_offset weapon_display_offsets[5];
};

template<size_t game_actions_count>
struct s_player_configuration_v7
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
	bool lock_max_aspect_ratio;
	char __padding0;
	/* new in this version */ bool users_skins_enabled;
	long player_model_permutation;

	long helmet_index;												 // e_customization_item_v2
	long left_shoulder_index;										 // e_customization_item_v2
	long right_shoulder_index;										 // e_customization_item_v2
	long chest_index;												 // e_customization_item_v2
	long wrist_index;												 // e_customization_item_v2
	long utility_index;												 // e_customization_item_v2
	long arms_index;												 // e_customization_item_v2
	/* new in this version */ long legs_index;						 // e_customization_item_v2
	long knee_guards_index;											 // e_customization_item_v2
	long visor_color_index;											 // e_customization_item_v2
	long spartan_armor_effect_index;								 // e_customization_item_v2
	long spartan_body_index;										 // e_customization_item_v2
	long elite_armor_index;											 // e_customization_item_v2
	long elite_armor_effect_index;									 // e_customization_item_v2
	/* new in this version */ long elite_helmet_index;				 // e_customization_item_v2
	/* new in this version */ long elite_left_shoulder_index;		 // e_customization_item_v2
	/* new in this version */ long elite_right_shoulder_index;		 // e_customization_item_v2
	/* new in this version */ long elite_chest_index;				 // e_customization_item_v2
	/* new in this version */ long elite_wrist_index_maybe;			 // e_customization_item_v2
	/* new in this version */ long elite_utility_index_maybe;		 // e_customization_item_v2
	/* new in this version */ long elite_arms_index_maybe;			 // e_customization_item_v2
	/* new in this version */ long elite_legs_index_maybe;			 // e_customization_item_v2
	long voice_index;												 // e_customization_item_v2
	long player_model_primary_color;								 // e_customization_item_v2
	long player_model_secondary_color;								 // e_customization_item_v2
	long player_model_tertiary_color;								 // e_customization_item_v2
	/* new in this version */ s_customization_item_skin customization_item_skins[15];

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
	char __unknown0[16];
	bool swap_triggers_and_bumpers;
	bool use_modern_aim_control;
	bool use_double_press_jump_to_jetpack;
	bool dual_wield_inverted;
	char enemy_player_name_color;
	char game_engine_timer;
	char __padding1[2];
	s_loadout_slot loadout_slots[5];
	char game_specific[256];
	float mouse_sensitivity;
	bool mouse_smoothing;
	bool mouse_acceleration;
	char __padding2[2];
	float mouse_acceleration_min_rate;
	float mouse_acceleration_max_accel;
	float mouse_acceleration_scale;
	float mouse_acceleration_exp;
	long keyboard_mouse_button_preset;
	s_game_keyboard_mouse_mapping game_keyboard_mouse_mappings[game_actions_count];
	long master_volume;
	long music_volume;
	long sfx_volume;
	char __padding3[16];
	long brightness;
	s_weapon_display_offset weapon_display_offsets[5];
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

using t_player_configuration_v7 = s_player_configuration_v7<k_number_of_game_actions_v6>;
constexpr size_t k_player_configuration_v7_size = sizeof(t_player_configuration_v7);

CHECK_STRUCTURE_SIZE(t_player_configuration_v7, 0xA6C);

enum e_player_configuration_version
{
	_player_configuration_version_1,
	_player_configuration_version_2,
	_player_configuration_version_3,
	_player_configuration_version_4,
	_player_configuration_version_5,
	_player_configuration_version_6,
	_player_configuration_version_7,
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
	bool& lock_max_aspect_ratio;
	bool& users_skins_enabled;

	long& player_model_permutation;

	long& helmet_index;
	long& left_shoulder_index;
	long& right_shoulder_index;
	long& chest_index;
	long& wrist_index;
	long& utility_index;
	long& knee_guards_index;
	long& visor_color_index;
	long& spartan_armor_effect_index;
	long& spartan_body_index;
	long& elite_armor_index;
	long& elite_armor_effect_index;
	long& elite_helmet_index;
	long& elite_left_shoulder_index;
	long& elite_right_shoulder_index;
	long& elite_chest_index;
	long& voice_index;
	long& player_model_primary_color;
	long& player_model_secondary_color;
	long& player_model_tertiary_color;
	s_customization_item_skin (&customization_item_skins)[15];

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
	long& master_volume;
	long& music_volume;
	long& sfx_volume;

	long& brightness;
	s_weapon_display_offset(&weapon_display_offsets)[5];

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
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
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
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
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
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
		} \
		return nullptr; \
	}
#define reference_getter_v7(field_name) \
	decltype(&field_name) get_##field_name() \
	{ \
		switch (player_configuration_version) \
		{ \
		case _player_configuration_version_7: return &player_configuration_v7.field_name; \
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
	reference_getter(lock_max_aspect_ratio);
	reference_getter_v7(users_skins_enabled);
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
	reference_getter_v7(elite_helmet_index);
	reference_getter_v7(elite_left_shoulder_index);
	reference_getter_v7(elite_right_shoulder_index);
	reference_getter_v7(elite_chest_index);
	reference_getter_v2(voice_index);
	reference_getter_v2(player_model_primary_color);
	reference_getter_v2(player_model_secondary_color);
	reference_getter_v2(player_model_tertiary_color);
	reference_getter_v7(customization_item_skins);
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
			case _player_configuration_version_1: return parent.player_configuration_v1.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_2: return parent.player_configuration_v2.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_3: return parent.player_configuration_v3.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_4: return parent.player_configuration_v4.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_5: return parent.player_configuration_v5.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_6: return parent.player_configuration_v6.game_keyboard_mouse_mappings[game_action_index];
			case _player_configuration_version_7: return parent.player_configuration_v7.game_keyboard_mouse_mappings[game_action_index];
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
		customization_item_skins(*get_customization_item_skins()),
		use_elite_model(*get_use_elite_model()),
		lock_max_aspect_ratio(*get_lock_max_aspect_ratio()),
		users_skins_enabled(*get_users_skins_enabled()),
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
		elite_helmet_index(*get_elite_helmet_index()),
		elite_left_shoulder_index(*get_elite_left_shoulder_index()),
		elite_right_shoulder_index(*get_elite_right_shoulder_index()),
		elite_chest_index(*get_elite_chest_index()),
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
		memset(&player_configuration_v7, 0, sizeof(player_configuration_v7));
	}
};
