#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(player_model_customization_area_enum, 8)
	{
		OPTION("spartan helmet"),
		OPTION("spartan chest"),
		OPTION("elite armor"),
		OPTION("unused_1"),
		OPTION("unused_2"),
		OPTION("unused_3"),
		OPTION("unused_4"),
		OPTION("unused_5"),
	};

	TAG_ENUM(player_non_model_customization_area_enum, 2)
	{
		OPTION("spartan armour effect"),
		OPTION("elite armour effect"),
	};

	TAG_ENUM(player_item_category_enum, 4)
	{
		OPTION("weapon"),
		OPTION("grenade"),
		OPTION("equipment"),
		OPTION("vehicle"),
	};

	TAG_ENUM(cookie_purchase_flags, 5)
	{
		OPTION("auto buy#this item is automatically given to the player when they meet the conditions"),
		OPTION("default#this item will appear as \'worn\' when the player isn\'t wearing any item (for \'default\' items)"),
		OPTION("doesn\'t count toward percent complete#this item will NOT count toward an overall completion value"),
		OPTION("doesn\'t count toward new items#this item is never \'new\'"),
		OPTION("lsp_authoritative#cannot be purchased locally, only LSP can set"),
	};

	TAG_GROUP_FROM_BLOCK(cookie_purchase_globals, COOKIE_PURCHASE_GLOBALS_TAG, cookie_purchase_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(cookie_purchase_globals_block, 1, cookie_purchase_globals_struct_definition_struct_definition );

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
		FIELD( _field_struct, "purchasable item reference", &PurchaseAppearanceDefinitionReferenceStruct_struct_definition ),
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
		FIELD( _field_struct, "purchasable item reference", &PurchaseLoadoutDefinitionReferenceStruct_struct_definition ),
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
		FIELD( _field_struct, "purchasable item reference", &PurchaseOrdnanceDefinitionReferenceStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(CookiePurchaseAppearanceDefinitionBlock, k_max_cookie_purchase_total_appearance_items)
	{
		FIELD( _field_string_id, "purchase id" ),
		FIELD( _field_string_id, "display name^" ),
		FIELD( _field_string_id, "display description" ),
		FIELD( _field_string_id, "Exit Experience Aggregate Group Name" ),
		FIELD( _field_byte_flags, "flags", &cookie_purchase_flags ),
		FIELD( _field_pad, "pad1", 3 ),
		FIELD( _field_tag_reference, "display bitmap" ),
		FIELD( _field_long_integer, "sprite index" ),
		FIELD( _field_tag_reference, "detail display bitmap" ),
		FIELD( _field_long_integer, "cookie cost" ),
		FIELD( _field_custom, "Prerequisites for visibility" ),
		FIELD( _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "Prerequisites for purchasability" ),
		FIELD( _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "purchase player appearance", &PurchasePlayerAppearanceStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_player_appearance_effect_model_permutation_block, 1)
	{
		FIELD( _field_char_enum, "model_region#See player customization globals, linked from globals.globals.", &player_model_customization_area_enum ),
		FIELD( _field_pad, "pad1", 3 ),
		FIELD( _field_string_id, "model_customization_selection_name^#This must match one of the selections in the model customization globals (within the selected region)." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_player_appearance_effect_non_model_permutation_block, 2)
	{
		FIELD( _field_char_enum, "non_model_region#See player customization globals, linked from globals.globals.", &player_non_model_customization_area_enum ),
		FIELD( _field_pad, "pad1", 3 ),
		FIELD( _field_string_id, "non_model_customization_selection_name^#This must match one of the selections in the model customization globals (within the selected region)." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_player_appearance_effect_visor_tint_block, 1)
	{
		FIELD( _field_string_id, "visor color name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_player_appearance_effect_emblem_index_block, k_maxEmblemIndicesPerItem)
	{
		FIELD( _field_char_integer, "emblem index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(PurchasePlayerAppearancePoseBlock, 1)
	{
		FIELD( _field_string_id, "pose name^" ),
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
		FIELD( _field_byte_flags, "flags", &cookie_purchase_flags ),
		FIELD( _field_pad, "pad1", 3 ),
		FIELD( _field_tag_reference, "display bitmap" ),
		FIELD( _field_long_integer, "sprite index" ),
		FIELD( _field_tag_reference, "detail display bitmap" ),
		FIELD( _field_long_integer, "cookie cost" ),
		FIELD( _field_custom, "Prerequisites for visibility" ),
		FIELD( _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "Prerequisites for purchasability" ),
		FIELD( _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "icon string id" ),
		FIELD( _field_struct, "purchase player loadout", &PurchasePlayerLoadoutStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_player_item_block, 1)
	{
		FIELD( _field_char_enum, "item_category#From the global multiplayer object list.", &player_item_category_enum ),
		FIELD( _field_pad, "pad1", 3 ),
		FIELD( _field_string_id, "object_name^#This must match one of the global objects." ),
		FIELD( _field_byte_integer, "object variant index#e.g. used for weapon skins" ),
		FIELD( _field_pad, "ppib", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_player_app_block, 1)
	{
		FIELD( _field_string_id, "object_name^#This must match an item in the custom app globals." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_player_loadout_slot_block, 1)
	{
		FIELD( _field_byte_integer, "slot_count^#Total slots you\'re allowed." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(purchase_player_app_mod_slot_block, 1)
	{
		FIELD( _field_byte_integer, "app_count^#Total apps you\'re allowed (from 0 to 2)." ),
		FIELD( _field_byte_integer, "mod_count^#Total mods you\'re allowed (from 0 to 1)." ),
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
		FIELD( _field_byte_flags, "flags", &cookie_purchase_flags ),
		FIELD( _field_pad, "pad1", 3 ),
		FIELD( _field_tag_reference, "display bitmap" ),
		FIELD( _field_long_integer, "sprite index" ),
		FIELD( _field_tag_reference, "detail display bitmap" ),
		FIELD( _field_long_integer, "cookie cost" ),
		FIELD( _field_custom, "Prerequisites for visibility" ),
		FIELD( _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "Prerequisites for purchasability" ),
		FIELD( _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "purchase player ordnance", &PurchasePlayerOrdnanceStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(PurchasePlayerOrdnanceItemBlock, 1)
	{
		FIELD( _field_string_id, "ordnance_name^#This must match one of the global ordnance objects." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(PurchasePlayerOrdnanceSlotBlock, 1)
	{
		FIELD( _field_byte_integer, "slot_count^#Total slots you\'re allowed." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(CookiePurchaseExternalUnlockableBlockOrdnanceDefinition, (sizeof(dword)*k_byte_bits))
	{
		FIELD( _field_block, "purchasable items", &CookiePurchaseOrdnanceDefinitionReferenceBlock_block ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(cookie_purchase_globals_struct_definition)
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

TAG_STRUCT(PurchasePlayerAppearanceStruct)
{
		FIELD( _field_block, "permutations", &purchase_player_appearance_effect_model_permutation_block_block ),
		FIELD( _field_block, "armor effects permutations", &purchase_player_appearance_effect_non_model_permutation_block_block ),
		FIELD( _field_block, "visor tints", &purchase_player_appearance_effect_visor_tint_block_block ),
		FIELD( _field_block, "emblem indices", &purchase_player_appearance_effect_emblem_index_block_block ),
		FIELD( _field_block, "portrait poses", &PurchasePlayerAppearancePoseBlock_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(PurchasePlayerLoadoutStruct)
{
		FIELD( _field_block, "items", &purchase_player_item_block_block ),
		FIELD( _field_block, "apps", &purchase_player_app_block_block ),
		FIELD( _field_block, "loadout slots", &purchase_player_loadout_slot_block_block ),
		FIELD( _field_block, "app and mod slots", &purchase_player_app_mod_slot_block_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(PurchasePlayerOrdnanceStruct)
{
		FIELD( _field_block, "ordnance items", &PurchasePlayerOrdnanceItemBlock_block ),
		FIELD( _field_block, "ordnance slots", &PurchasePlayerOrdnanceSlotBlock_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

