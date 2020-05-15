#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(effect_component_holdbacks, k_effect_holdback_type_max)
{
	{ _field_long_enum, "holdback type^*" },
	{ _field_dword_integer, "overall budget*#from code" },
	{ _field_block, "priorities", &effect_component_holdback_block },
	{ _field_terminator },
};

TAG_BLOCK(effect_component_holdback, k_effect_priority_max)
{
	{ _field_long_enum, "priority type^*" },
	{ _field_explanation, "SET ONE OF THE FOLLOWING" },
	{ _field_dword_integer, "absolute count" },
	{ _field_real, "relative percentage:/ 100" },
	{ _field_dword_integer, "How many available at this priority*!" },
	{ _field_terminator },
};

TAG_BLOCK(effect_global_spawn_effects, 1)
{
	{ _field_tag_reference, "biped spawn effect" },
	{ _field_tag_reference, "vehicle spawn effect" },
	{ _field_tag_reference, "weapon spawn effect" },
	{ _field_tag_reference, "first person player spawn effect" },
	{ _field_terminator },
};

TAG_GROUP(effect_globals, EFFECT_GLOBALS_TAG)
{
	{ _field_explanation, "EFFECT HOLDBACKS" },
	{ _field_block, "holdbacks", &effect_component_holdbacks_block },
	{ _field_tag_reference, "grunt birthday effect" },
	{ _field_explanation, "Spawn Effects" },
	{ _field_block, "multiplayer", &effect_global_spawn_effects_block },
	{ _field_block, "survival", &effect_global_spawn_effects_block },
	{ _field_block, "campaign", &effect_global_spawn_effects_block },
	{ _field_terminator },
};

} // namespace blofeld

