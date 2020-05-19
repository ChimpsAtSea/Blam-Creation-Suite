#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(multiplayer_object_type_list, MULTIPLAYER_OBJECT_TYPE_LIST_TAG, multiplayer_object_type_list_block_block );

	TAG_BLOCK(multiplayer_object_type_block, k_multiplayer_object_type_maximum_count)
	{
		{ _field_explanation, "WARNING" },
		{ _field_string_id, "name^" },
		{ _field_tag_reference, "object", &object_reference$6 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(multiplayer_weapon_collection_block, k_maximum_number_of_multiplayer_weapon_selections, multiplayer_object_collection_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(multiplayer_vehicle_collection_block, k_maximum_number_of_multiplayer_vehicle_selections, multiplayer_object_collection_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(multiplayer_grenade_collection_block, k_maximum_number_of_multiplayer_grenade_selections, multiplayer_object_collection_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(multiplayer_equipment_collection_block, k_maximum_number_of_multiplayer_equipment_selections, multiplayer_object_collection_struct_struct_definition );

	TAG_BLOCK(multiplayer_weapon_remap_table_entry_block, k_maximum_number_of_multiplayer_remap_table_entries)
	{
		{ _field_custom_long_block_index, "from object" },
		{ _field_custom_long_block_index, "to object" },
		{ _field_terminator }
	};

	TAG_BLOCK(multiplayer_weapon_remap_table_block, k_maximum_number_of_multiplayer_weapon_sets)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "remap table", &multiplayer_weapon_remap_table_entry_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(multiplayer_vehicle_remap_table_entry_block, k_maximum_number_of_multiplayer_remap_table_entries)
	{
		{ _field_custom_long_block_index, "from object" },
		{ _field_custom_long_block_index, "to object" },
		{ _field_terminator }
	};

	TAG_BLOCK(multiplayer_vehicle_remap_table_block, k_maximum_number_of_multiplayer_weapon_sets)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "remap table", &multiplayer_vehicle_remap_table_entry_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(multiplayer_equipment_remap_table_entry_block, k_maximum_number_of_multiplayer_remap_table_entries)
	{
		{ _field_custom_long_block_index, "from object" },
		{ _field_custom_long_block_index, "to object" },
		{ _field_terminator }
	};

	TAG_BLOCK(multiplayer_equipment_remap_table_block, k_maximum_number_of_multiplayer_weapon_sets)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "remap table", &multiplayer_equipment_remap_table_entry_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(multiplayer_object_type_list_block, 1, multiplayer_object_type_list_struct_definition_struct_definition );

	TAG_STRUCT(multiplayer_object_type_list_struct_definition)
	{
		{ _field_explanation, "MEGALO" },
		{ _field_block, "object types", &multiplayer_object_type_block_block },
		{ _field_block, "weapons", &multiplayer_weapon_collection_block_block },
		{ _field_block, "vehicles", &multiplayer_vehicle_collection_block_block },
		{ _field_block, "grenades", &multiplayer_grenade_collection_block_block },
		{ _field_block, "equipment", &multiplayer_equipment_collection_block_block },
		{ _field_explanation, "REMAPPING TABLES" },
		{ _field_block, "weapon remapping", &multiplayer_weapon_remap_table_block_block },
		{ _field_block, "vehicle remapping", &multiplayer_vehicle_remap_table_block_block },
		{ _field_block, "equipment remapping", &multiplayer_equipment_remap_table_block_block },
		{ _field_long_integer, "random weapon menu sprite frame" },
		{ _field_long_integer, "random equipment menu sprite frame" },
		{ _field_string_id, "random weapon icon string id" },
		{ _field_string_id, "random equipment icon string id" },
		{ _field_terminator }
	};

	TAG_STRUCT(multiplayer_object_collection_struct)
	{
		{ _field_long_block_index, "object type^" },
		{ _field_string_id, "object description" },
		{ _field_string_id, "object header text" },
		{ _field_string_id, "object help text" },
		{ _field_real, "random weight" },
		{ _field_long_integer, "loadout menu sprite frame" },
		{ _field_string_id, "icon string id" },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_multiplayer_object_type_list_reference, MULTIPLAYER_OBJECT_TYPE_LIST_TAG);

} // namespace blofeld

