#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(breakable_surface_set_block, k_maximum_breakable_surface_sets)
	{
		{ _field_legacy, _field_array, "supported bitfield!", &supported_bitfield_array },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_ARRAY(supported_bitfield, ((((k_maximum_breakable_surfaces_per_breakable_surface_set)+(k_int32_bits-1))>>k_int32_bits_bits)))
	{
		{ _field_legacy, _field_long_integer, "bitvector data!" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

