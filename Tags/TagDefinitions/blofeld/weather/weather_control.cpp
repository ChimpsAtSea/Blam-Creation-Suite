#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(weather_globals, WEATHER_GLOBALS_TAG, weather_globals_block_block );

	TAG_BLOCK(global_textures_refs_block, BYTE_MAX)
	{
		{ _field_tag_reference, "texture", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(weather_globals_block, 1, weather_globals_struct_definition_struct_definition );

	TAG_STRUCT(weather_globals_struct_definition)
	{
		{ _field_explanation, "global textures", "0: ............... random noise\n" },
		{ _field_block, "global textures", &global_textures_refs_block_block },
		{ _field_tag_reference, "default rain", &global_rain_definition_reference },
		{ _field_explanation, "ripple settings (TO BE REMOVED)", "we are going to use a new method to render and control of ripple effects\n" },
		{ _field_struct, "rain ripple setting", &rain_ripple_setting_block_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(rain_ripple_setting_block)
	{
		{ _field_tag_reference, "rain ripple texture", &global_bitmap_reference },
		{ _field_real, "group period time:seconds" },
		{ _field_real, "texture tile size:world units" },
		{ _field_real, "reflection intensify" },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_weather_globals_reference, WEATHER_GLOBALS_TAG);

} // namespace blofeld

