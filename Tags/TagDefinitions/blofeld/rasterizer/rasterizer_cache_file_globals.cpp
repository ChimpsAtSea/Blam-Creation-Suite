#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		rasterizer_cache_file_globals_group,
		RASTERIZER_CACHE_FILE_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		rasterizer_cache_file_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		rasterizer_cache_file_globals_block,
		"rasterizer_cache_file_globals_block",
		1,
		rasterizer_cache_file_globals_struct_definition);

	#define RASTERIZER_CACHE_FILE_GLOBALS_STRUCT_DEFINITION_ID { 0x3FAFA78E, 0x905B48F5, 0x82089983, 0x561E7C3B }
	TAG_STRUCT_V6(
		rasterizer_cache_file_globals_struct_definition,
		"rasterizer_cache_file_globals_struct_definition",
		"s_rasterizer_cache_file_globals",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RASTERIZER_CACHE_FILE_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "texture header count" },
		{ _field_long_integer, "maximum vertex shader gprs" },
		{ _field_long_integer, "maximum pixel shader gprs" },
		{ _field_terminator }
	};



} // namespace blofeld

