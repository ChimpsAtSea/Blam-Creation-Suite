#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define ACTIVE_CAMO_GLOBALS_BLOCK_ID { 0x4034FF5E, 0x39D84C2D, 0x916CA4FB, 0x0C7983BC }
	TAG_BLOCK(
		active_camo_globals_block,
		"active_camo_globals_block",
		1,
		"s_active_camo_globals",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ACTIVE_CAMO_GLOBALS_BLOCK_ID)
	{
		{ _field_real, "biped speed reference", "for bipeds, the speed at which you are on the far right of the 'speed to max camo' graph", "wu/s" },
		{ _field_real, "vehicle speed reference", "for vehicles, the speed at which you are on the far right of the 'speed to max camo' graph", "wu/s" },
		{ _field_real_fraction, "camo value for game name", "minimum active camo percentage at which a player's game name will start becoming visible" },
		{ _field_struct, "camo value to distortion", &scalar_function_named_struct },
		{ _field_struct, "camo value to transparency", "maps active-camo percentage to alpha for THIRD PERSON rendering", &scalar_function_named_struct },
		{ _field_struct, "camo value to fp transparency", "maps active-camo percentage to alpha for FIRST PERSON rendering", &scalar_function_named_struct },

		{ _version_mode_greater, _engine_type_haloreach, 6 },
		{ _field_struct, "camo distortion texture strength", &scalar_function_named_struct },
		{ _field_real_vector_2d, "camo distortion scale" },
		{ _field_real_vector_2d, "camo distortion translate speed" },
		{ _field_tag_reference, "camo distortion texture", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_real, "camo depth bias max distance", "This is used to deal with ugly rendering artifacts when camo is not fully on" },
		{ _field_struct, "camo depth bias function", "This is used to deal with ugly rendering artifacts when camo is not fully on", &scalar_function_named_struct },

		{ _field_block, "camo levels", &active_camo_level_definition_block },
		{ _field_terminator }
	};

	#define ACTIVE_CAMO_LEVEL_DEFINITION_BLOCK_ID { 0xE283DEAA, 0xD17B46FF, 0x8002F669, 0xF186E377 }
	TAG_BLOCK(
		active_camo_level_definition_block,
		"active_camo_level_definition_block",
		k_number_of_active_camo_levels,
		"s_active_camo_level_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ACTIVE_CAMO_LEVEL_DEFINITION_BLOCK_ID)
	{
		{ _field_real, "grenade throw penalty", "reduces camo value by this much when throwing a grenade", "0..1" },
		{ _field_real, "melee penalty", "reduces camo by this much when meleeing", "0..1" },
		{ _field_real, "minimum dinged value", "when taking damage or doing other actions that reduce camo, we will never drop below this value" },
		{ _field_real, "interpolation time", "time it takes to interpolate from 0.0 to 1.0", "s" },
		{ _field_struct, "speed to maximum camo", &scalar_function_named_struct },
		{ _field_terminator }
	};

	STRINGS(active_camo_enum_definition)
	{
		"poor",
		"good",
		"excellent",
		"invisible",
		"ai"
	};
	STRING_LIST(active_camo_enum_definition, active_camo_enum_definition_strings, _countof(active_camo_enum_definition_strings));



} // namespace blofeld

