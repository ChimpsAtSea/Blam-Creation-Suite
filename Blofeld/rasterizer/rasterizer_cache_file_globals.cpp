#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(rasterizer_cache_file_globals, RASTERIZER_CACHE_FILE_GLOBALS_TAG)
{
	{ _field_long_integer, "texture header count" },
	{ _field_long_integer, "maximum vertex shader gprs" },
	{ _field_long_integer, "maximum pixel shader gprs" },
	{ _field_terminator },
};

} // namespace blofeld

