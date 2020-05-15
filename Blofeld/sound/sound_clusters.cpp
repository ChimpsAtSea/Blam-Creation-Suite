#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(structure_bsp_sound_cluster, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_short_integer, "palette index!" },
	{ _field_pad, "HRSFKJT", 2 },
	{ _field_block, "enclosing portal designators", &structure_sound_cluster_portal_designators_block },
	{ _field_block, "interior cluster indices", &structure_sound_cluster_interior_cluster_indices_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_sound_cluster_portal_designators, MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE)
{
	{ _field_short_integer, "portal designator*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_sound_cluster_interior_cluster_indices, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_short_integer, "interior cluster index*" },
	{ _field_terminator },
};

} // namespace blofeld

