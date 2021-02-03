#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define WAVE_TEMPLATE_STRUCT_DEFINITION_ID { 0xB82E4294, 0x71E441F2, 0x9CE4C7D4, 0x916B76B7 }
	TAG_BLOCK(
		wave_template_block,
		"wave_template_block",
		1,
		"s_ai_wave_template_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WAVE_TEMPLATE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "squad specifications", &wave_squad_specification_struct_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		wave_template_group,
		WAVE_TEMPLATE_TAG,
		nullptr,
		INVALID_TAG,
		wave_template_block );

	TAG_BLOCK_FROM_STRUCT(
		wave_squad_specification_struct_block,
		"wave_squad_specification_struct",
		k_max_squad_specifications_per_wave,
		wave_squad_specification_struct_struct);

	#define WAVE_SQUAD_SPECIFICATION_STRUCT_STRUCT_ID { 0x55990120, 0x27804544, 0x9145EB6F, 0xBFA6A0A3 }
	TAG_STRUCT(
		wave_squad_specification_struct_struct,
		"wave_squad_specification_struct_struct",
		"s_ai_wave_squad_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WAVE_SQUAD_SPECIFICATION_STRUCT_STRUCT_ID)
	{
		{ _field_tag_reference, "squad template", &squad_template_reference$2 },
		{ _field_struct, "spawn conditions", &ai_spawn_conditions_struct },
		{ _field_short_integer, "weight", "The relative weight given to this squad spawning" },
		{ _field_explanation, "MIN/MAX SPAWN COUNTS", "When spawning a number of squads from this wave template, try and spawn at least the minimum number, and at most the maximum number. Once these min/max bounds have been met, probabilistic distribution will continue." },
		{ _field_char_integer, "min spawn", "Spawn AT LEAST this number of squads. Value of 0 means \"no minimum\"" },
		{ _field_char_integer, "max spawn", "Spawn NO MORE THAN this number of squads. Value of 0 means \"no maximum\"" },
		{ _field_long_enum, "placement filter", &wave_placement_filter_enum },
		{ _field_terminator }
	};

	STRINGS(wave_placement_filter_enum)
	{
		"None",
		"Heavy Infantry",
		"Boss Infantry",
		"Light Vehicle",
		"Heavy Vehicle",
		"Flying Infantry",
		"Flying Vehicle",
		"Bonus"
	};
	STRING_LIST(wave_placement_filter_enum, wave_placement_filter_enum_strings, _countof(wave_placement_filter_enum_strings));

} // namespace macaque

} // namespace blofeld

