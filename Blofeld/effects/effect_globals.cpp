#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(effect_globals, EFFECT_GLOBALS_TAG, effect_globals_block_block );

	TAG_BLOCK(effect_component_holdback_block, k_effect_priority_max)
	{
		FIELD( _field_long_enum, "priority type^*", &global_effect_priority_enum ),
		FIELD( _field_explanation, "SET ONE OF THE FOLLOWING" ),
		FIELD( _field_dword_integer, "absolute count" ),
		FIELD( _field_real, "relative percentage:/ 100" ),
		FIELD( _field_dword_integer, "How many available at this priority*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(effect_component_holdbacks_block, k_effect_holdback_type_max)
	{
		FIELD( _field_long_enum, "holdback type^*", &effect_holdback_type_enum ),
		FIELD( _field_dword_integer, "overall budget*#from code" ),
		FIELD( _field_block, "priorities", &effect_component_holdback_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(effect_global_spawn_effects_block, 1)
	{
		FIELD( _field_tag_reference, "biped spawn effect" ),
		FIELD( _field_tag_reference, "vehicle spawn effect" ),
		FIELD( _field_tag_reference, "weapon spawn effect" ),
		FIELD( _field_tag_reference, "first person player spawn effect" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(effect_globals_block, 1, effect_globals_struct_definition_struct_definition );

	TAG_STRUCT(effect_globals_struct_definition)
	{
		FIELD( _field_explanation, "EFFECT HOLDBACKS" ),
		FIELD( _field_block, "holdbacks", &effect_component_holdbacks_block_block ),
		FIELD( _field_tag_reference, "grunt birthday effect" ),
		FIELD( _field_explanation, "Spawn Effects" ),
		FIELD( _field_block, "multiplayer", &effect_global_spawn_effects_block_block ),
		FIELD( _field_block, "survival", &effect_global_spawn_effects_block_block ),
		FIELD( _field_block, "campaign", &effect_global_spawn_effects_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(global_effect_priority_enum, 6)
	{
		OPTION("low"),
		OPTION("normal"),
		OPTION("above normal"),
		OPTION("high"),
		OPTION("very high"),
		OPTION("essential"),
	};

	TAG_ENUM(effect_holdback_type_enum, 26)
	{
		OPTION("type_effect"),
		OPTION("type_event"),
		OPTION("type_location"),
		OPTION("type_lightprobe"),
		OPTION("type_effect_message"),
		OPTION("tracer system"),
		OPTION("tracer location"),
		OPTION("tracer spawned"),
		OPTION("tracer stateless"),
		OPTION("tracer spawned profile row"),
		OPTION("tracer stateless profile row"),
		OPTION("type_decal_system"),
		OPTION("type_decal"),
		OPTION("type_decal_vertex"),
		OPTION("type_decal_index"),
		OPTION("type_light_volume_system"),
		OPTION("type_light_volume_location"),
		OPTION("type_light_volume"),
		OPTION("type_light_volume_profile_row"),
		OPTION("type_particle_system"),
		OPTION("type_particle_location"),
		OPTION("type_particle_emitter"),
		OPTION("type_cpu_particle"),
		OPTION("type_gpu_particle_row"),
		OPTION("type_particle_queue"),
		OPTION("tracer queue"),
	};

} // namespace blofeld

