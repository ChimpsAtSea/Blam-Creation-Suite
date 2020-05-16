#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(variant_globals, VARIANT_GLOBALS_TAG, variant_globals_block_block )

TAG_BLOCK_FROM_STRUCT(variant_globals_block, 1, variant_globals_struct_definition_struct_definition );

TAG_BLOCK(single_variant_block, s_variant_globals_definition::k_variant_globals_per_block_count_maximum)
{
	FIELD( _field_data, "metadata" ),
	FIELD( _field_data, "full_data" ),
	FIELD( _field_long_string, "filename^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(FallbackHopperFileBlock, s_variant_globals_definition::k_hopper_files_maximum_count)
{
	FIELD( _field_data, "file_data" ),
	FIELD( _field_long_string, "filename^" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(variant_globals_struct_definition)
{
	FIELD( _field_block, "map_variants", &single_variant_block_block ),
	FIELD( _field_block, "game_variants", &single_variant_block_block ),
	FIELD( _field_block, "fallback_hoppers", &FallbackHopperFileBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

