#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(rasterizer_cache_file_globals_struct_definition)
{
	FIELD( _field_long_integer, "texture header count" ),
	FIELD( _field_long_integer, "maximum vertex shader gprs" ),
	FIELD( _field_long_integer, "maximum pixel shader gprs" ),
	FIELD( _field_terminator )
};

TAG_GROUP(rasterizer_cache_file_globals_block, RASTERIZER_CACHE_FILE_GLOBALS_TAG)
{
	FIELD( _field_long_integer, "texture header count" ),
	FIELD( _field_long_integer, "maximum vertex shader gprs" ),
	FIELD( _field_long_integer, "maximum pixel shader gprs" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

