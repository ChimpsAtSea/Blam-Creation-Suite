#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(rasterizer_cache_file_globals, RASTERIZER_CACHE_FILE_GLOBALS_TAG)
{
	FIELD( _field_long_integer, "texture header count" ),
	FIELD( _field_long_integer, "maximum vertex shader gprs" ),
	FIELD( _field_long_integer, "maximum pixel shader gprs" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

