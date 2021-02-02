#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(rasterizer_cache_file_globals, RASTERIZER_CACHE_FILE_GLOBALS_TAG, rasterizer_cache_file_globals_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(rasterizer_cache_file_globals_block, 1, rasterizer_cache_file_globals_struct_definition_struct_definition );

	V5_TAG_STRUCT(rasterizer_cache_file_globals_struct_definition)
	{
		{ _field_legacy, _field_long_integer, "texture header count" },
		{ _field_legacy, _field_long_integer, "maximum vertex shader gprs" },
		{ _field_legacy, _field_long_integer, "maximum pixel shader gprs" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

