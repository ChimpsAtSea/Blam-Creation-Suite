#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(wave_squad_specification_struct, k_max_squad_specifications_per_wave)
{
	{ _field_tag_reference, "squad template^" },
	{ _field_struct, "spawn conditions" },
	{ _field_short_integer, "weight#The relative weight given to this squad spawning" },
	{ _field_explanation, "MIN/MAX SPAWN COUNTS" },
	{ _field_char_integer, "min spawn#Spawn AT LEAST this number of squads. Value of 0 means \"no minimum\"" },
	{ _field_char_integer, "max spawn#Spawn NO MORE THAN this number of squads. Value of 0 means \"no maximum\"" },
	{ _field_long_enum, "placement filter#Filter where this squad specification can spawn by matching this value with the values in squad definitions in the scenario" },
	{ _field_terminator },
};

TAG_GROUP(wave_template, WAVE_TEMPLATE_TAG)
{
	{ _field_block, "squad specifications", &wave_squad_specification_struct_block },
	{ _field_terminator },
};

} // namespace blofeld

