#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(single_variant, s_variant_globals_definition::k_variant_globals_per_block_count_maximum)
{
	{ _field_data, "metadata" },
	{ _field_data, "full_data" },
	{ _field_long_string, "filename^" },
	{ _field_terminator },
};

TAG_BLOCK(FallbackHopperFileBlock, s_variant_globals_definition::k_hopper_files_maximum_count)
{
	{ _field_data, "file_data" },
	{ _field_long_string, "filename^" },
	{ _field_terminator },
};

TAG_GROUP(variant_globals, VARIANT_GLOBALS_TAG)
{
	{ _field_block, "map_variants", &single_variant_block },
	{ _field_block, "game_variants", &single_variant_block },
	{ _field_block, "fallback_hoppers", &FallbackHopperFileBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

