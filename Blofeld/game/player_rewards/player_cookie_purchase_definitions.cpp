#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(CookiePurchaseFamilyAppearanceDefinitionBlock, k_max_cookie_purchase_families)
{
	FIELD( _field_string_id, "display title^#If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints)." ),
	FIELD( _field_string_id, "display_description" ),
	FIELD( _field_tag_reference, "display bitmap" ),
	FIELD( _field_long_integer, "sprite index" ),
	FIELD( _field_block, "purchasable items", &CookiePurchaseAppearanceDefinitionReferenceBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseAppearanceDefinitionReferenceBlock, k_max_cookie_purchase_family_items)
{
	FIELD( _field_struct, "purchasable item reference" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseFamilyLoadoutDefinitionBlock, k_max_cookie_purchase_families)
{
	FIELD( _field_string_id, "display title^#If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints)." ),
	FIELD( _field_string_id, "display_description" ),
	FIELD( _field_tag_reference, "display bitmap" ),
	FIELD( _field_long_integer, "sprite index" ),
	FIELD( _field_block, "purchasable items", &CookiePurchaseLoadoutDefinitionReferenceBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseLoadoutDefinitionReferenceBlock, k_max_cookie_purchase_family_items)
{
	FIELD( _field_struct, "purchasable item reference" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseFamilyOrdnanceDefinitionBlock, k_max_cookie_purchase_families)
{
	FIELD( _field_string_id, "display title^#If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints)." ),
	FIELD( _field_string_id, "display_description" ),
	FIELD( _field_tag_reference, "display bitmap" ),
	FIELD( _field_long_integer, "sprite index" ),
	FIELD( _field_block, "purchasable items", &CookiePurchaseOrdnanceDefinitionReferenceBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseOrdnanceDefinitionReferenceBlock, k_max_cookie_purchase_family_items)
{
	FIELD( _field_struct, "purchasable item reference" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseAppearanceDefinitionBlock, k_max_cookie_purchase_total_appearance_items)
{
	FIELD( _field_string_id, "purchase id" ),
	FIELD( _field_string_id, "display name^" ),
	FIELD( _field_string_id, "display description" ),
	FIELD( _field_string_id, "Exit Experience Aggregate Group Name" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad1", 3 ),
	FIELD( _field_tag_reference, "display bitmap" ),
	FIELD( _field_long_integer, "sprite index" ),
	FIELD( _field_tag_reference, "detail display bitmap" ),
	FIELD( _field_long_integer, "cookie cost" ),
	FIELD( _field_custom, "Prerequisites for visibility" ),
	FIELD( _field_struct, "visible prerequisites" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Prerequisites for purchasability" ),
	FIELD( _field_struct, "purchasable prerequisites" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "purchase player appearance" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseExternalUnlockableBlockAppearanceDefinition, (sizeof(dword)*k_byte_bits))
{
	FIELD( _field_block, "purchasable items", &CookiePurchaseAppearanceDefinitionReferenceBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseLoadoutDefinitionBlock, k_max_cookie_purchase_total_loadout_items)
{
	FIELD( _field_string_id, "purchase id" ),
	FIELD( _field_string_id, "display name^" ),
	FIELD( _field_string_id, "display description" ),
	FIELD( _field_string_id, "Exit Experience Aggregate Group Name" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad1", 3 ),
	FIELD( _field_tag_reference, "display bitmap" ),
	FIELD( _field_long_integer, "sprite index" ),
	FIELD( _field_tag_reference, "detail display bitmap" ),
	FIELD( _field_long_integer, "cookie cost" ),
	FIELD( _field_custom, "Prerequisites for visibility" ),
	FIELD( _field_struct, "visible prerequisites" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Prerequisites for purchasability" ),
	FIELD( _field_struct, "purchasable prerequisites" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "icon string id" ),
	FIELD( _field_struct, "purchase player loadout" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseExternalUnlockableBlockLoadoutDefinition, (sizeof(dword)*k_byte_bits))
{
	FIELD( _field_block, "purchasable items", &CookiePurchaseLoadoutDefinitionReferenceBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseOrdnanceDefinitionBlock, k_max_cookie_purchase_total_ordnance_items)
{
	FIELD( _field_string_id, "purchase id" ),
	FIELD( _field_string_id, "display name^" ),
	FIELD( _field_string_id, "display description" ),
	FIELD( _field_string_id, "Exit Experience Aggregate Group Name" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad1", 3 ),
	FIELD( _field_tag_reference, "display bitmap" ),
	FIELD( _field_long_integer, "sprite index" ),
	FIELD( _field_tag_reference, "detail display bitmap" ),
	FIELD( _field_long_integer, "cookie cost" ),
	FIELD( _field_custom, "Prerequisites for visibility" ),
	FIELD( _field_struct, "visible prerequisites" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Prerequisites for purchasability" ),
	FIELD( _field_struct, "purchasable prerequisites" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "purchase player ordnance" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CookiePurchaseExternalUnlockableBlockOrdnanceDefinition, (sizeof(dword)*k_byte_bits))
{
	FIELD( _field_block, "purchasable items", &CookiePurchaseOrdnanceDefinitionReferenceBlock_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(cookie_purchase_globals, COOKIE_PURCHASE_GLOBALS_TAG)
{
	FIELD( _field_custom, "Purchase Families" ),
	FIELD( _field_block, "Helmet purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Left shoulder purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Right shoulder purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Chest purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Legs purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Arms purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "App 1 loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block ),
	FIELD( _field_block, "App 2 loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block ),
	FIELD( _field_block, "Primary weapon loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block ),
	FIELD( _field_block, "Secondary weapon loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block ),
	FIELD( _field_block, "Grenade purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block ),
	FIELD( _field_block, "Equipment purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block ),
	FIELD( _field_block, "Slot purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block ),
	FIELD( _field_block, "Visor tint purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Elite armor purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Primary emblem purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Secondary emblem purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "Ordnance slot purchasable families", &CookiePurchaseFamilyOrdnanceDefinitionBlock_block ),
	FIELD( _field_block, "Ordnance purchasable families", &CookiePurchaseFamilyOrdnanceDefinitionBlock_block ),
	FIELD( _field_block, "Portrait pose purchasable families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Appearance Items" ),
	FIELD( _field_block, "purchasable appearance items", &CookiePurchaseAppearanceDefinitionBlock_block ),
	FIELD( _field_block, "DLC appearance unlockables", &CookiePurchaseExternalUnlockableBlockAppearanceDefinition_block ),
	FIELD( _field_block, "Waypoint appearance unlockables", &CookiePurchaseExternalUnlockableBlockAppearanceDefinition_block ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Loadout Items" ),
	FIELD( _field_block, "purchasable loadout items", &CookiePurchaseLoadoutDefinitionBlock_block ),
	FIELD( _field_block, "DLC loadout unlockables", &CookiePurchaseExternalUnlockableBlockLoadoutDefinition_block ),
	FIELD( _field_block, "Waypoint loadout unlockables", &CookiePurchaseExternalUnlockableBlockLoadoutDefinition_block ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Ordnance Items" ),
	FIELD( _field_block, "purchasable ordnance items", &CookiePurchaseOrdnanceDefinitionBlock_block ),
	FIELD( _field_block, "DLC ordnance unlockables", &CookiePurchaseExternalUnlockableBlockOrdnanceDefinition_block ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

