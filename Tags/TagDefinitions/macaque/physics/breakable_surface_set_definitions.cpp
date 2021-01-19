#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define BREAKABLE_SURFACE_SET_BLOCK_ID { 0x1CAF3641, 0x92334C3F, 0x9991A6AC, 0xCB69431A }
	TAG_BLOCK(
		breakable_surface_set_block,
		"breakable_surface_set_block",
		k_maximum_breakable_surface_sets,
		"s_breakable_surface_set_definition",
		BREAKABLE_SURFACE_SET_BLOCK_ID)
	{
		{ _field_array, "supported bitfield!", &supported_bitfield_array },
		{ _field_terminator }
	};

	TAG_ARRAY(supported_bitfield, ((((k_maximum_breakable_surfaces_per_breakable_surface_set)+(k_int32_bits-1))>>k_int32_bits_bits)))
	{
		{ _field_long_integer, "bitvector data!" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

