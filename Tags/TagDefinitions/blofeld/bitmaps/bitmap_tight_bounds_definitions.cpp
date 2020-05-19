#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(bitmap_tight_bounds_block_def, (4 * k_maxTightBoundsSets))
	{
		{ _field_real_point_2d, "uv" },
		{ _field_terminator }
	};

} // namespace blofeld

