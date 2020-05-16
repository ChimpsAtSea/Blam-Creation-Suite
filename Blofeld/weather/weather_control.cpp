#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(weather_globals_struct_definition)
{
	FIELD( _field_explanation, "global textures" ),
	FIELD( _field_block, "global textures", &global_textures_refs_block ),
	FIELD( _field_tag_reference, "default rain" ),
	FIELD( _field_explanation, "ripple settings (TO BE REMOVED)" ),
	FIELD( _field_struct, "rain ripple setting", &rain_ripple_setting_block_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(rain_ripple_setting_block)
{
	FIELD( _field_tag_reference, "rain ripple texture" ),
	FIELD( _field_real, "group period time:seconds" ),
	FIELD( _field_real, "texture tile size:world units" ),
	FIELD( _field_real, "reflection intensify" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_textures_refs_block, BYTE_MAX)
{
	FIELD( _field_tag_reference, "texture" ),
	FIELD( _field_terminator )
};

TAG_GROUP(weather_globals_block, WEATHER_GLOBALS_TAG)
{
	FIELD( _field_explanation, "global textures" ),
	FIELD( _field_block, "global textures", &global_textures_refs_block ),
	FIELD( _field_tag_reference, "default rain" ),
	FIELD( _field_explanation, "ripple settings (TO BE REMOVED)" ),
	FIELD( _field_struct, "rain ripple setting", &rain_ripple_setting_block_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

