#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_textures_refs, BYTE_MAX)
{
	FIELD( _field_tag_reference, "texture" ),
	FIELD( _field_terminator )
};

TAG_GROUP(weather_globals, WEATHER_GLOBALS_TAG)
{
	FIELD( _field_explanation, "global textures" ),
	FIELD( _field_block, "global textures", &global_textures_refs_block ),
	FIELD( _field_tag_reference, "default rain" ),
	FIELD( _field_explanation, "ripple settings (TO BE REMOVED)" ),
	FIELD( _field_struct, "rain ripple setting" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

