#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(rasterizer_cache_file_globals, RASTERIZER_CACHE_FILE_GLOBALS_TAG, rasterizer_cache_file_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(rasterizer_cache_file_globals_block, 1, rasterizer_cache_file_globals_struct_definition_struct_definition );

TAG_STRUCT(rasterizer_cache_file_globals_struct_definition)
{
		FIELD( _field_long_integer, "texture header count" ),
		FIELD( _field_long_integer, "maximum vertex shader gprs" ),
		FIELD( _field_long_integer, "maximum pixel shader gprs" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

