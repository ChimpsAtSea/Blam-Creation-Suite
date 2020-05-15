#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_textures_refs, BYTE_MAX)
{
	{ _field_tag_reference, "texture" },
	{ _field_terminator },
};

TAG_GROUP(weather_globals, WEATHER_GLOBALS_TAG)
{
	{ _field_explanation, "global textures" },
	{ _field_block, "global textures", &global_textures_refs_block },
	{ _field_tag_reference, "default rain" },
	{ _field_explanation, "ripple settings (TO BE REMOVED)" },
	{ _field_struct, "rain ripple setting" },
	{ _field_terminator },
};

} // namespace blofeld

