#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(MarketplaceOfferTypeEnum, 32)
	{
		OPTION("DeadeyeHelmet"),
		OPTION("LocusHelmet"),
		OPTION("GungnirPulse"),
		OPTION("VenatorRaptor"),
		OPTION("CIOWeb"),
		OPTION("HazopForest"),
		OPTION("OceanicCircuit"),
		OPTION("BattleRifleArctic"),
		OPTION("BonebreakerEmblem"),
		OPTION("AssassinEmblem"),
		OPTION("BulletproofEmblem"),
		OPTION("SpartanEmblem"),
		OPTION("MjolnirEmblem"),
		OPTION("LCE1Emblem"),
		OPTION("SpartanIVArmorUnique"),
		OPTION("AssaultRifleUnique"),
		OPTION("Specializations"),
		OPTION("UnicornEmblem"),
		OPTION("UnicornArmor"),
		OPTION("UnicornLightRifle"),
		OPTION("LiveEmblem"),
		OPTION("ScannerHelmet"),
		OPTION("StriderHelmet"),
		OPTION("FalconEmblem"),
		OPTION("Reserved01"),
		OPTION("Reserved02"),
		OPTION("Reserved04"),
		OPTION("Reserved08"),
		OPTION("Reserved10"),
		OPTION("Reserved20"),
		OPTION("Reserved40"),
		OPTION("ReservedDoNotUse80"),
	};

	TAG_BLOCK(purchase_prerequisite_grade_definition_block, 1)
	{
		FIELD( _field_long_integer, "enlistment index" ),
		FIELD( _field_long_integer, "minimum grade" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_prerequisite_commendation_definition_block, 1)
	{
		FIELD( _field_string_id, "commendation id^#This must match one of the commendation names." ),
		FIELD( _field_char_enum, "type", &aggregatorDependentTypeEnumDefinition ),
		FIELD( _field_char_integer, "minimum level#This field is ignored if \'type\' is set to \'aggregator\'." ),
		FIELD( _field_pad, "PAD1", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(PurchasePrerequisitePurchasedAppearanceItemDefinitionBlock, 20)
	{
		FIELD( _field_struct, "item reference", &PurchaseAppearanceDefinitionReferenceStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(PurchasePrerequisitePurchasedLoadoutItemDefinitionBlock, 20)
	{
		FIELD( _field_struct, "item reference", &PurchaseLoadoutDefinitionReferenceStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(PurchasePrerequisitePurchasedOrdnanceItemDefinitionBlock, 20)
	{
		FIELD( _field_struct, "item reference", &PurchaseOrdnanceDefinitionReferenceStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_prerequisites_unlockable_definition_block, 10)
	{
		FIELD( _field_string_id, "unlockable name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_prerequisites_offer_definition_block, 10)
	{
		FIELD( _field_char_enum, "offer type^", &MarketplaceOfferTypeEnum ),
		FIELD( _field_pad, "pad1", 3 ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(PurchasePrerequisitesUnifiedDefinitionBlock)
{
		FIELD( _field_string_id, "prerequisite purchased item error string" ),
		FIELD( _field_string_id, "prerequisite unlockable error string" ),
		FIELD( _field_string_id, "prerequisite offers error string" ),
		FIELD( _field_long_integer, "prerequisite enlistment count" ),
		FIELD( _field_block, "prerequisite grades", &purchase_prerequisite_grade_definition_block_block ),
		FIELD( _field_block, "prerequisite commendations", &purchase_prerequisite_commendation_definition_block_block ),
		FIELD( _field_block, "prerequisite appearance purchased items", &PurchasePrerequisitePurchasedAppearanceItemDefinitionBlock_block ),
		FIELD( _field_block, "prerequisite loadout purchased items", &PurchasePrerequisitePurchasedLoadoutItemDefinitionBlock_block ),
		FIELD( _field_block, "prerequisite ordnance purchased items", &PurchasePrerequisitePurchasedOrdnanceItemDefinitionBlock_block ),
		FIELD( _field_block, "prerequisite unlockables", &purchase_prerequisites_unlockable_definition_block_block ),
		FIELD( _field_block, "prerequisite offers", &purchase_prerequisites_offer_definition_block_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(PurchaseAppearanceDefinitionReferenceStruct)
{
		FIELD( _field_short_block_index, "item reference^" ),
		FIELD( _field_pad, "pad1", 2 ),
		FIELD( _field_terminator )
};

TAG_STRUCT(PurchaseLoadoutDefinitionReferenceStruct)
{
		FIELD( _field_short_block_index, "item reference^" ),
		FIELD( _field_pad, "pad1", 2 ),
		FIELD( _field_terminator )
};

TAG_STRUCT(PurchaseOrdnanceDefinitionReferenceStruct)
{
		FIELD( _field_short_block_index, "item reference^" ),
		FIELD( _field_pad, "pad1", 2 ),
		FIELD( _field_terminator )
};

} // namespace blofeld

