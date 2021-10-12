#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define BREAKABLE_SURFACE_SET_BLOCK_ID { 0x1CAF3641, 0x92334C3F, 0x9991A6AC, 0xCB69431A }
	TAG_BLOCK(
		breakable_surface_set_block,
		"breakable_surface_set_block",
		k_maximum_breakable_surface_sets,
		"s_breakable_surface_set_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BREAKABLE_SURFACE_SET_BLOCK_ID)
	{
		{ _field_array, "supported bitfield", FIELD_FLAG_UNKNOWN0, &supported_bitfield_array },
		{ _field_terminator }
	};

	#define SUPPORTED_BITFIELD_ID { 0x5BA3F924, 0xD9104D57, 0x9D743495, 0x3F6636C6 }
	TAG_ARRAY(
		supported_bitfield_array,
		"supported_bitfield",
		((((k_maximum_breakable_surfaces_per_breakable_surface_set)+(k_int32_bits-1))>>k_int32_bits_bits)),
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SUPPORTED_BITFIELD_ID)
	{
		{ _field_long_integer, "bitvector data", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};



} // namespace blofeld

