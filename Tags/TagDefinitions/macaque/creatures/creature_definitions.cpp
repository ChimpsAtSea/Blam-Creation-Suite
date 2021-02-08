#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define BIG_BATTLE_CREATURE_STRUCT_DEFINITION_ID { 0x0C9CAA3F, 0xE6544B0A, 0x970A3001, 0xC88B7C27 }
	TAG_BLOCK(
		big_battle_creature_block,
		"big_battle_creature_block",
		1,
		"s_big_battle_creature_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BIG_BATTLE_CREATURE_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("CREATURE", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_flags, "flags", &creature_definition_flags },
		{ _field_enum, "default team", &unit_default_teams },
		{ _field_enum, "motion sensor blip size", &global_chud_blip_type_definition },
		{ _field_angle, "turning velocity maximum", nullptr, "degrees per second" },
		{ _field_angle, "turning acceleration maximum", nullptr, "degrees per second squared" },
		{ _field_real_fraction, "casual turning modifier", nullptr, nullptr, "[0,1]" },
		{ _field_real, "autoaim width", nullptr, "world units" },
		{ _field_struct, "physics", &character_physics_struct },
		{ _field_tag_reference, "impact damage", &global_damage_reference },
		{ _field_tag_reference, "impact shield damage", "if not specified, uses 'impact damage'", &global_damage_reference },
		{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block },
		FIELD_EXPLANATION("death and destruction", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_bounds, "destroy after death time", "if non-zero, the creature will destroy itself upon death after this much time", "seconds" },
		FIELD_EXPLANATION("big battle", nullptr, FIELD_FLAG_NONE, "The following fields only affect creatures configured as boids for big battle"),
		{ _field_long_flags, "big battle flags", &creature_big_battle_definition_flags },
		{ _field_tag_reference, "big battle weapon emitter", &global_cheap_particle_emitter_reference },
		{ _field_real_point_3d, "big battle weapon offset" },
		{ _field_tag_reference, "big battle weapon emitter 2", "if you leave this empty, only the first emitter will fire", &global_cheap_particle_emitter_reference },
		{ _field_real_point_3d, "big battle weapon offset 2" },
		{ _field_block, "big battle weapon fire timing", &creature_scalar_timing_block },
		{ _field_tag_reference, "big battle expensive weapon effect", "this fires a full effect from location up, oriented along vehicle's forward and up axes", &global_effect_reference },
		{ _field_real_bounds, "expensive weapon fire time", nullptr, "seconds" },
		{ _field_tag_reference, "big battle death effect", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_tag_reference, "imposter model", &imposter_model_reference },
		{ _field_terminator }
	};

	TAG_GROUP(
		big_battle_creature_group,
		BIG_BATTLE_CREATURE_TAG,
		nullptr,
		INVALID_TAG,
		big_battle_creature_block );

	TAG_GROUP(
		creature_group,
		CREATURE_TAG,
		&object_group,
		OBJECT_TAG,
		creature_block );

	TAG_BLOCK_FROM_STRUCT(
		creature_block,
		"creature_block",
		1,
		creature_struct_definition);

	#define CREATURE_SCALAR_TIMING_BLOCK_ID { 0x3BF7E066, 0xD7B244F4, 0xA9A392E5, 0x0BC191CF }
	TAG_BLOCK(
		creature_scalar_timing_block,
		"creature_scalar_timing_block",
		1,
		"c_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CREATURE_SCALAR_TIMING_BLOCK_ID)
	{
		{ _field_struct, "function_curve", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define CREATURE_STRUCT_DEFINITION_ID { 0x83C805FE, 0xCAD24C6A, 0x8781D5EE, 0x18B84ED8 }
	TAG_STRUCT(
		creature_struct_definition,
		"creature_struct_definition",
		"s_creature_definition_internal",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CREATURE_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		FIELD_CUSTOM("$$$ CREATURE $$$", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_flags, "flags", &creature_definition_flags },
		{ _field_enum, "default team", &unit_default_teams },
		{ _field_enum, "motion sensor blip size", &global_chud_blip_type_definition },
		{ _field_angle, "turning velocity maximum", nullptr, "degrees per second" },
		{ _field_angle, "turning acceleration maximum", nullptr, "degrees per second squared" },
		{ _field_real_fraction, "casual turning modifier", nullptr, nullptr, "[0,1]" },
		{ _field_real, "autoaim width", nullptr, "world units" },
		{ _field_struct, "physics", &character_physics_struct },
		{ _field_tag_reference, "impact damage", &global_damage_reference },
		{ _field_tag_reference, "impact shield damage", "if not specified, uses 'impact damage'", &global_damage_reference },
		{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block },
		FIELD_EXPLANATION("death and destruction", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_bounds, "destroy after death time", "if non-zero, the creature will destroy itself upon death after this much time", "seconds" },
		FIELD_EXPLANATION("big battle", nullptr, FIELD_FLAG_NONE, "The following fields only affect creatures configured as boids for big battle"),
		{ _field_long_flags, "big battle flags", &creature_big_battle_definition_flags },
		{ _field_tag_reference, "big battle weapon emitter", &global_cheap_particle_emitter_reference },
		{ _field_real_point_3d, "big battle weapon offset" },
		{ _field_tag_reference, "big battle weapon emitter 2", "if you leave this empty, only the first emitter will fire", &global_cheap_particle_emitter_reference },
		{ _field_real_point_3d, "big battle weapon offset 2" },
		{ _field_block, "big battle weapon fire timing", &creature_scalar_timing_block },
		{ _field_tag_reference, "big battle expensive weapon effect", "this fires a full effect from location up, oriented along vehicle's forward and up axes", &global_effect_reference },
		{ _field_real_bounds, "expensive weapon fire time", nullptr, "seconds" },
		{ _field_tag_reference, "big battle death effect", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	STRINGS(creature_big_battle_definition_flags)
	{
		"boid aims at big battle target#setting this forces boid to aim at target instead of firing straight ahead",
		"boids fly with no pitch#flying boids will always stay level when changing altitude",
		"boids fly non-directionally#flying boids will move like helicopters"
	};
	STRING_LIST(creature_big_battle_definition_flags, creature_big_battle_definition_flags_strings, _countof(creature_big_battle_definition_flags_strings));

	STRINGS(creature_definition_flags)
	{
		"unused",
		"immune to falling damage",
		"rotate while airborne",
		"zapped by shields",
		"attach upon impact",
		"not on motion sensor",
		"force ground movement"
	};
	STRING_LIST(creature_definition_flags, creature_definition_flags_strings, _countof(creature_definition_flags_strings));

	STRINGS(unit_default_teams)
	{
		"default",
		"player",
		"human",
		"covenant",
		"brute",
		"mule",
		"spare",
		"covenant_player",
		"forerunner"
	};
	STRING_LIST(unit_default_teams, unit_default_teams_strings, _countof(unit_default_teams_strings));

} // namespace macaque

} // namespace blofeld

