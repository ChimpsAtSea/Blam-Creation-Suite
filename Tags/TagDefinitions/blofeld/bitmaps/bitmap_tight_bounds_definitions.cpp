#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define BITMAP_TIGHT_BOUNDS_BLOCK_DEF_ID { 0x999753DF, 0x8AB54C19, 0xBDEDB3D3, 0x2D83450D }
	TAG_BLOCK(
		bitmap_tight_bounds_block_def_block,
		"bitmap_tight_bounds_block_def",
		(4 * k_maxTightBoundsSets),
		"real_point2d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BITMAP_TIGHT_BOUNDS_BLOCK_DEF_ID)
	{
		{ _field_real_point_2d, "uv" },
		{ _field_terminator }
	};



} // namespace blofeld

