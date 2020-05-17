#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(structure_bsp_sound_cluster_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_short_integer, "palette index!" ),
		FIELD( _field_pad, "HRSFKJT", 2 ),
		FIELD( _field_block, "enclosing portal designators", &structure_sound_cluster_portal_designators_block ),
		FIELD( _field_block, "interior cluster indices", &structure_sound_cluster_interior_cluster_indices_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(structure_sound_cluster_portal_designators, MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE)
	{
		FIELD( _field_short_integer, "portal designator*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(structure_sound_cluster_interior_cluster_indices, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_short_integer, "interior cluster index*" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

