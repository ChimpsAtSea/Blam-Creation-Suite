#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(multiplayer_object_type, k_multiplayer_object_type_maximum_count)
{
	{ _field_explanation, "WARNING" },
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "object" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_weapon_collection, k_maximum_number_of_multiplayer_weapon_selections)
{
	{ _field_long_block_index, "object type^" },
	{ _field_string_id, "object description" },
	{ _field_string_id, "object header text" },
	{ _field_string_id, "object help text" },
	{ _field_real, "random weight" },
	{ _field_long_integer, "loadout menu sprite frame" },
	{ _field_string_id, "icon string id" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_vehicle_collection, k_maximum_number_of_multiplayer_vehicle_selections)
{
	{ _field_long_block_index, "object type^" },
	{ _field_string_id, "object description" },
	{ _field_string_id, "object header text" },
	{ _field_string_id, "object help text" },
	{ _field_real, "random weight" },
	{ _field_long_integer, "loadout menu sprite frame" },
	{ _field_string_id, "icon string id" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_grenade_collection, k_maximum_number_of_multiplayer_grenade_selections)
{
	{ _field_long_block_index, "object type^" },
	{ _field_string_id, "object description" },
	{ _field_string_id, "object header text" },
	{ _field_string_id, "object help text" },
	{ _field_real, "random weight" },
	{ _field_long_integer, "loadout menu sprite frame" },
	{ _field_string_id, "icon string id" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_equipment_collection, k_maximum_number_of_multiplayer_equipment_selections)
{
	{ _field_long_block_index, "object type^" },
	{ _field_string_id, "object description" },
	{ _field_string_id, "object header text" },
	{ _field_string_id, "object help text" },
	{ _field_real, "random weight" },
	{ _field_long_integer, "loadout menu sprite frame" },
	{ _field_string_id, "icon string id" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_weapon_remap_table, k_maximum_number_of_multiplayer_weapon_sets)
{
	{ _field_string_id, "name^" },
	{ _field_block, "remap table", &multiplayer_weapon_remap_table_entry_block },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_weapon_remap_table_entry, k_maximum_number_of_multiplayer_remap_table_entries)
{
	{ _field_custom_long_block_index, "from object" },
	{ _field_custom_long_block_index, "to object" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_vehicle_remap_table, k_maximum_number_of_multiplayer_weapon_sets)
{
	{ _field_string_id, "name^" },
	{ _field_block, "remap table", &multiplayer_vehicle_remap_table_entry_block },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_vehicle_remap_table_entry, k_maximum_number_of_multiplayer_remap_table_entries)
{
	{ _field_custom_long_block_index, "from object" },
	{ _field_custom_long_block_index, "to object" },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_equipment_remap_table, k_maximum_number_of_multiplayer_weapon_sets)
{
	{ _field_string_id, "name^" },
	{ _field_block, "remap table", &multiplayer_equipment_remap_table_entry_block },
	{ _field_terminator },
};

TAG_BLOCK(multiplayer_equipment_remap_table_entry, k_maximum_number_of_multiplayer_remap_table_entries)
{
	{ _field_custom_long_block_index, "from object" },
	{ _field_custom_long_block_index, "to object" },
	{ _field_terminator },
};

TAG_GROUP(multiplayer_object_type_list, MULTIPLAYER_OBJECT_TYPE_LIST_TAG)
{
	{ _field_explanation, "MEGALO" },
	{ _field_block, "object types", &multiplayer_object_type_block },
	{ _field_block, "weapons", &multiplayer_weapon_collection_block },
	{ _field_block, "vehicles", &multiplayer_vehicle_collection_block },
	{ _field_block, "grenades", &multiplayer_grenade_collection_block },
	{ _field_block, "equipment", &multiplayer_equipment_collection_block },
	{ _field_explanation, "REMAPPING TABLES" },
	{ _field_block, "weapon remapping", &multiplayer_weapon_remap_table_block },
	{ _field_block, "vehicle remapping", &multiplayer_vehicle_remap_table_block },
	{ _field_block, "equipment remapping", &multiplayer_equipment_remap_table_block },
	{ _field_long_integer, "random weapon menu sprite frame" },
	{ _field_long_integer, "random equipment menu sprite frame" },
	{ _field_string_id, "random weapon icon string id" },
	{ _field_string_id, "random equipment icon string id" },
	{ _field_terminator },
};

} // namespace blofeld

