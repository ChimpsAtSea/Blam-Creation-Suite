#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define JETWASH_DEFINITION_BLOCK_ID { 0xC47AA872, 0x0A224BC5, 0x9B77C993, 0x79969CAB }
	TAG_BLOCK(
		jetwash_definition_block,
		"jetwash_definition_block",
		k_maximum_jetwash_points_per_object,
		"s_jetwash_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		JETWASH_DEFINITION_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "marker name" },
		{ _field_real, "radius" },
		{ _field_long_integer, "maximum traces", "traces per second" },
		{ _field_real, "maximum emission length", "world units" },
		{ _field_angle_bounds, "trace yaw angle", "degrees" },
		{ _field_angle_bounds, "trace pitch angle", "degrees" },
		{ _field_real, "particle offset", "world units" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

