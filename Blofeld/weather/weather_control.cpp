#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(weather_globals, WEATHER_GLOBALS_TAG, weather_globals_block_block );

	TAG_BLOCK(global_textures_refs_block, BYTE_MAX)
	{
		FIELD( _field_tag_reference, "texture" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(weather_globals_block, 1, weather_globals_struct_definition_struct_definition );

	TAG_STRUCT(weather_globals_struct_definition)
	{
		FIELD( _field_explanation, "global textures" ),
		FIELD( _field_block, "global textures", &global_textures_refs_block_block ),
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

} // namespace blofeld

