#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(structure_portal_device_mapping, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_block, "device portal associations", &structure_device_portal_association_block },
	{ _field_block, "game portal to portal map", &game_portal_to_portal_mapping_block },
	{ _field_block, "occluding portal to portal map", &occluding_portal_to_portal_mapping_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_device_portal_association, k_maximum_machine_door_portal_associations)
{
	{ _field_struct, "device id" },
	{ _field_short_integer, "first game portal index" },
	{ _field_word_integer, "game portal count" },
	{ _field_terminator },
};

TAG_BLOCK(game_portal_to_portal_mapping, k_maximum_machine_door_portal_associations)
{
	{ _field_short_integer, "portal index" },
	{ _field_terminator },
};

TAG_BLOCK(occluding_portal_to_portal_mapping, k_maximum_occluding_portal_associations)
{
	{ _field_short_integer, "portal index" },
	{ _field_terminator },
};

} // namespace blofeld

