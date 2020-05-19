#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(structure_device_portal_association_block, k_maximum_machine_door_portal_associations)
	{
		{ _field_struct, "device id", &scenario_object_id_struct_struct_definition },
		{ _field_short_integer, "first game portal index" },
		{ _field_word_integer, "game portal count" },
		{ _field_terminator }
	};

	TAG_BLOCK(game_portal_to_portal_mapping_block, k_maximum_machine_door_portal_associations)
	{
		{ _field_short_integer, "portal index" },
		{ _field_terminator }
	};

	TAG_BLOCK(occluding_portal_to_portal_mapping_block, k_maximum_occluding_portal_associations)
	{
		{ _field_short_integer, "portal index" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_portal_device_mapping_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		{ _field_block, "device portal associations", &structure_device_portal_association_block_block },
		{ _field_block, "game portal to portal map", &game_portal_to_portal_mapping_block_block },
		{ _field_block, "occluding portal to portal map", &occluding_portal_to_portal_mapping_block_block },
		{ _field_terminator }
	};

} // namespace blofeld

