#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define STRUCTURE_BSP_SOUND_CLUSTER_BLOCK_ID { 0x1B60A32F, 0x573342BF, 0x861F64D3, 0xADC5FA35 }
	TAG_BLOCK(
		structure_bsp_sound_cluster_block,
		"structure_bsp_sound_cluster_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_structure_sound_cluster",
		STRUCTURE_BSP_SOUND_CLUSTER_BLOCK_ID)
	{
		{ _field_short_integer, "palette index" },
		FIELD_PAD("HRSFKJT", nullptr, 2),
		{ _field_block, "enclosing portal designators", &structure_sound_cluster_portal_designators_block },
		{ _field_block, "interior cluster indices", &structure_sound_cluster_interior_cluster_indices_block },
		{ _field_terminator }
	};

	#define STRUCTURE_SOUND_CLUSTER_PORTAL_DESIGNATORS_ID { 0x01EC24E9, 0xFD0D4390, 0xB834EDB2, 0x81935210 }
	TAG_BLOCK(
		structure_sound_cluster_portal_designators_block,
		"structure_sound_cluster_portal_designators",
		MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE,
		"short",
		STRUCTURE_SOUND_CLUSTER_PORTAL_DESIGNATORS_ID)
	{
		{ _field_short_integer, "portal designator" },
		{ _field_terminator }
	};

	#define STRUCTURE_SOUND_CLUSTER_INTERIOR_CLUSTER_INDICES_ID { 0xC93822AC, 0x9F9E404B, 0x9440C3DA, 0x462F28E7 }
	TAG_BLOCK(
		structure_sound_cluster_interior_cluster_indices_block,
		"structure_sound_cluster_interior_cluster_indices",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"short",
		STRUCTURE_SOUND_CLUSTER_INTERIOR_CLUSTER_INDICES_ID)
	{
		{ _field_short_integer, "interior cluster index" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

