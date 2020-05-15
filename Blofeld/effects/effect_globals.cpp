#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(effect_component_holdbacks, k_effect_holdback_type_max)
{
	FIELD( _field_long_enum, "holdback type^*" ),
	FIELD( _field_dword_integer, "overall budget*#from code" ),
	FIELD( _field_block, "priorities", &effect_component_holdback_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(effect_component_holdback, k_effect_priority_max)
{
	FIELD( _field_long_enum, "priority type^*" ),
	FIELD( _field_explanation, "SET ONE OF THE FOLLOWING" ),
	FIELD( _field_dword_integer, "absolute count" ),
	FIELD( _field_real, "relative percentage:/ 100" ),
	FIELD( _field_dword_integer, "How many available at this priority*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(effect_global_spawn_effects, 1)
{
	FIELD( _field_tag_reference, "biped spawn effect" ),
	FIELD( _field_tag_reference, "vehicle spawn effect" ),
	FIELD( _field_tag_reference, "weapon spawn effect" ),
	FIELD( _field_tag_reference, "first person player spawn effect" ),
	FIELD( _field_terminator )
};

TAG_GROUP(effect_globals, EFFECT_GLOBALS_TAG)
{
	FIELD( _field_explanation, "EFFECT HOLDBACKS" ),
	FIELD( _field_block, "holdbacks", &effect_component_holdbacks_block ),
	FIELD( _field_tag_reference, "grunt birthday effect" ),
	FIELD( _field_explanation, "Spawn Effects" ),
	FIELD( _field_block, "multiplayer", &effect_global_spawn_effects_block ),
	FIELD( _field_block, "survival", &effect_global_spawn_effects_block ),
	FIELD( _field_block, "campaign", &effect_global_spawn_effects_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

