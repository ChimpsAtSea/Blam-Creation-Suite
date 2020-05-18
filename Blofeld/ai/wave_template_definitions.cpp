#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(wave_template, WAVE_TEMPLATE_TAG)
	{
		{ _field_block, "squad specifications", &wave_squad_specification_struct_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(wave_squad_specification_struct, k_max_squad_specifications_per_wave, wave_squad_specification_struct_struct_struct_definition );

	TAG_STRUCT(wave_squad_specification_struct_struct)
	{
		{ _field_tag_reference, "squad template^", &squad_template_reference$2 },
		{ _field_struct, "spawn conditions", &ai_spawn_conditions_struct_struct_definition },
		{ _field_short_integer, "weight#The relative weight given to this squad spawning" },
		{ _field_explanation, "MIN/MAX SPAWN COUNTS" },
		{ _field_char_integer, "min spawn#Spawn AT LEAST this number of squads. Value of 0 means \"no minimum\"" },
		{ _field_char_integer, "max spawn#Spawn NO MORE THAN this number of squads. Value of 0 means \"no maximum\"" },
		{ _field_long_enum, "placement filter#Filter where this squad specification can spawn by matching this value with the values in squad definitions in the scenario", &wave_placement_filter_enum },
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

} // namespace blofeld

