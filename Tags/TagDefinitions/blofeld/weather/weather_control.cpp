#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		weather_globals_group,
		WEATHER_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		weather_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		weather_globals_block,
		"weather_globals_block",
		1,
		weather_globals_struct_definition);

	#define GLOBAL_TEXTURES_REFS_BLOCK_ID { 0x6CFA3906, 0x9F764CAE, 0x8034C2F5, 0xA11803EA }
	TAG_BLOCK(
		global_textures_refs_block,
		"global_textures_refs_block",
		BYTE_MAX,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_TEXTURES_REFS_BLOCK_ID)
	{
		{ _field_tag_reference, "texture", &global_bitmap_reference },
		{ _field_terminator }
	};

	#define WEATHER_GLOBALS_STRUCT_DEFINITION_ID { 0x8C9B19BF, 0x971F413F, 0x8B57DFEF, 0xFC8E152E }
	TAG_STRUCT(
		weather_globals_struct_definition,
		"weather_globals_struct_definition",
		"s_weather_globals",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WEATHER_GLOBALS_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION_EX("global textures", nullptr, FIELD_FLAG_NONE, "0: ............... random noise\n"),
		{ _field_block, "global textures", &global_textures_refs_block },
		{ _field_tag_reference, "default rain", &global_rain_definition_reference },
		FIELD_EXPLANATION_EX("ripple settings (TO BE REMOVED)", nullptr, FIELD_FLAG_NONE, "we are going to use a new method to render and control of ripple effects\n"),
		{ _field_struct, "rain ripple setting", &rain_ripple_setting_block },
		{ _field_terminator }
	};

	#define RAIN_RIPPLE_SETTING_BLOCK_ID { 0x514BC6BA, 0x360C4B17, 0x8CA56212, 0x9E0BB16A }
	TAG_STRUCT(
		rain_ripple_setting_block,
		"rain_ripple_setting_block",
		"s_rain_ripple_setting",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RAIN_RIPPLE_SETTING_BLOCK_ID)
	{
		{ _field_tag_reference, "rain ripple texture", &global_bitmap_reference },
		{ _field_real, "group period time", nullptr, "seconds" },
		{ _field_real, "texture tile size", nullptr, "world units" },
		{ _field_real, "reflection intensify" },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_weather_globals_reference, WEATHER_GLOBALS_TAG);



} // namespace blofeld

