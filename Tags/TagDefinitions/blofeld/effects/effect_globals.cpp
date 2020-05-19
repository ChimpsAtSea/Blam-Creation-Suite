#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(effect_globals, EFFECT_GLOBALS_TAG, effect_globals_block_block );

	TAG_BLOCK(effect_component_holdback_block, k_effect_priority_max)
	{
		{ _field_long_enum, "priority type^*", &global_effect_priority_enum },
		{ _field_explanation, "SET ONE OF THE FOLLOWING" },
		{ _field_dword_integer, "absolute count" },
		{ _field_real, "relative percentage:/ 100" },
		{ _field_dword_integer, "How many available at this priority*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_component_holdbacks_block, k_effect_holdback_type_max)
	{
		{ _field_long_enum, "holdback type^*", &effect_holdback_type_enum },
		{ _field_dword_integer, "overall budget*#from code" },
		{ _field_block, "priorities", &effect_component_holdback_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_global_spawn_effects_block, 1)
	{
		{ _field_tag_reference, "biped spawn effect", &global_effect_reference },
		{ _field_tag_reference, "vehicle spawn effect", &global_effect_reference },
		{ _field_tag_reference, "weapon spawn effect", &global_effect_reference },
		{ _field_tag_reference, "first person player spawn effect", &global_effect_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(effect_globals_block, 1, effect_globals_struct_definition_struct_definition );

	TAG_STRUCT(effect_globals_struct_definition)
	{
		{ _field_explanation, "EFFECT HOLDBACKS" },
		{ _field_block, "holdbacks", &effect_component_holdbacks_block_block },
		{ _field_tag_reference, "grunt birthday effect", &global_effect_reference },
		{ _field_explanation, "Spawn Effects" },
		{ _field_block, "multiplayer", &effect_global_spawn_effects_block_block },
		{ _field_block, "survival", &effect_global_spawn_effects_block_block },
		{ _field_block, "campaign", &effect_global_spawn_effects_block_block },
		{ _field_terminator }
	};

	STRINGS(global_effect_priority_enum)
	{
		"low",
		"normal",
		"above normal",
		"high",
		"very high",
		"essential"
	};
	STRING_LIST(global_effect_priority_enum, global_effect_priority_enum_strings, _countof(global_effect_priority_enum_strings));

	STRINGS(effect_holdback_type_enum)
	{
		"type_effect",
		"type_event",
		"type_location",
		"type_lightprobe",
		"type_effect_message",
		"tracer system",
		"tracer location",
		"tracer spawned",
		"tracer stateless",
		"tracer spawned profile row",
		"tracer stateless profile row",
		"type_decal_system",
		"type_decal",
		"type_decal_vertex",
		"type_decal_index",
		"type_light_volume_system",
		"type_light_volume_location",
		"type_light_volume",
		"type_light_volume_profile_row",
		"type_particle_system",
		"type_particle_location",
		"type_particle_emitter",
		"type_cpu_particle",
		"type_gpu_particle_row",
		"type_particle_queue",
		"tracer queue"
	};
	STRING_LIST(effect_holdback_type_enum, effect_holdback_type_enum_strings, _countof(effect_holdback_type_enum_strings));

	TAG_REFERENCE(global_effect_globals_reference, EFFECT_GLOBALS_TAG);

} // namespace blofeld

