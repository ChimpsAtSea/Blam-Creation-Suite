#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(purchase_prerequisite_grade_definition_block, 1)
	{
		{ _field_long_integer, "enlistment index" },
		{ _field_long_integer, "minimum grade" },
		{ _field_terminator }
	};

	TAG_BLOCK(purchase_prerequisite_commendation_definition_block, 1)
	{
		{ _field_string_id, "commendation id^#This must match one of the commendation names." },
		{ _field_char_enum, "type", &aggregatorDependentTypeEnumDefinition },
		{ _field_char_integer, "minimum level#This field is ignored if \'type\' is set to \'aggregator\'." },
		{ _field_pad, "PAD1", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(PurchasePrerequisitePurchasedAppearanceItemDefinitionBlock, 20)
	{
		{ _field_struct, "item reference", &PurchaseAppearanceDefinitionReferenceStruct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(PurchasePrerequisitePurchasedLoadoutItemDefinitionBlock, 20)
	{
		{ _field_struct, "item reference", &PurchaseLoadoutDefinitionReferenceStruct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(PurchasePrerequisitePurchasedOrdnanceItemDefinitionBlock, 20)
	{
		{ _field_struct, "item reference", &PurchaseOrdnanceDefinitionReferenceStruct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(purchase_prerequisites_unlockable_definition_block, 10)
	{
		{ _field_string_id, "unlockable name^" },
		{ _field_terminator }
	};

	TAG_BLOCK(purchase_prerequisites_offer_definition_block, 10)
	{
		{ _field_char_enum, "offer type^", &MarketplaceOfferTypeEnum },
		{ _field_pad, "pad1", 3 },
		{ _field_terminator }
	};

	TAG_STRUCT(PurchasePrerequisitesUnifiedDefinitionBlock)
	{
		{ _field_string_id, "prerequisite purchased item error string" },
		{ _field_string_id, "prerequisite unlockable error string" },
		{ _field_string_id, "prerequisite offers error string" },
		{ _field_long_integer, "prerequisite enlistment count" },
		{ _field_block, "prerequisite grades", &purchase_prerequisite_grade_definition_block_block },
		{ _field_block, "prerequisite commendations", &purchase_prerequisite_commendation_definition_block_block },
		{ _field_block, "prerequisite appearance purchased items", &PurchasePrerequisitePurchasedAppearanceItemDefinitionBlock_block },
		{ _field_block, "prerequisite loadout purchased items", &PurchasePrerequisitePurchasedLoadoutItemDefinitionBlock_block },
		{ _field_block, "prerequisite ordnance purchased items", &PurchasePrerequisitePurchasedOrdnanceItemDefinitionBlock_block },
		{ _field_block, "prerequisite unlockables", &purchase_prerequisites_unlockable_definition_block_block },
		{ _field_block, "prerequisite offers", &purchase_prerequisites_offer_definition_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(PurchaseAppearanceDefinitionReferenceStruct)
	{
		{ _field_short_block_index, "item reference^" },
		{ _field_pad, "pad1", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(PurchaseLoadoutDefinitionReferenceStruct)
	{
		{ _field_short_block_index, "item reference^" },
		{ _field_pad, "pad1", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(PurchaseOrdnanceDefinitionReferenceStruct)
	{
		{ _field_short_block_index, "item reference^" },
		{ _field_pad, "pad1", 2 },
		{ _field_terminator }
	};

	STRINGS(MarketplaceOfferTypeEnum)
	{
		"DeadeyeHelmet",
		"LocusHelmet",
		"GungnirPulse",
		"VenatorRaptor",
		"CIOWeb",
		"HazopForest",
		"OceanicCircuit",
		"BattleRifleArctic",
		"BonebreakerEmblem",
		"AssassinEmblem",
		"BulletproofEmblem",
		"SpartanEmblem",
		"MjolnirEmblem",
		"LCE1Emblem",
		"SpartanIVArmorUnique",
		"AssaultRifleUnique",
		"Specializations",
		"UnicornEmblem",
		"UnicornArmor",
		"UnicornLightRifle",
		"LiveEmblem",
		"ScannerHelmet",
		"StriderHelmet",
		"FalconEmblem",
		"Reserved01",
		"Reserved02",
		"Reserved04",
		"Reserved08",
		"Reserved10",
		"Reserved20",
		"Reserved40",
		"ReservedDoNotUse80"
	};
	STRING_LIST(MarketplaceOfferTypeEnum, MarketplaceOfferTypeEnum_strings, _countof(MarketplaceOfferTypeEnum_strings));

} // namespace blofeld

