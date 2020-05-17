#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(big_battle_creature, BIG_BATTLE_CREATURE_TAG)
	{
		FIELD( _field_custom, "CREATURE" ),
		FIELD( _field_long_flags, "flags", &creature_definition_flags ),
		FIELD( _field_enum, "default team", &unit_default_teams ),
		FIELD( _field_enum, "motion sensor blip size", &global_chud_blip_type_definition ),
		FIELD( _field_angle, "turning velocity maximum:degrees per second" ),
		FIELD( _field_angle, "turning acceleration maximum:degrees per second squared" ),
		FIELD( _field_real_fraction, "casual turning modifier:[0,1]" ),
		FIELD( _field_real, "autoaim width:world units" ),
		FIELD( _field_struct, "physics", &character_physics_struct_struct_definition ),
		FIELD( _field_tag_reference, "impact damage" ),
		FIELD( _field_tag_reference, "impact shield damage#if not specified, uses \'impact damage\'" ),
		FIELD( _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block_block ),
		FIELD( _field_explanation, "death and destruction" ),
		FIELD( _field_real_bounds, "destroy after death time:seconds#if non-zero, the creature will destroy itself upon death after this much time" ),
		FIELD( _field_explanation, "big battle" ),
		FIELD( _field_long_flags, "big battle flags", &creature_big_battle_definition_flags ),
		FIELD( _field_tag_reference, "big battle weapon emitter" ),
		FIELD( _field_real_point_3d, "big battle weapon offset" ),
		FIELD( _field_tag_reference, "big battle weapon emitter 2#if you leave this empty, only the first emitter will fire" ),
		FIELD( _field_real_point_3d, "big battle weapon offset 2" ),
		FIELD( _field_block, "big battle weapon fire timing", &creature_scalar_timing_block_block ),
		FIELD( _field_tag_reference, "big battle expensive weapon effect#this fires a full effect from location up, oriented along vehicle\'s forward and up axes" ),
		FIELD( _field_real_bounds, "expensive weapon fire time:seconds" ),
		FIELD( _field_tag_reference, "big battle death effect" ),
		FIELD( _field_custom ),
		FIELD( _field_tag_reference, "imposter model" ),
		FIELD( _field_terminator )
	};

	TAG_GROUP_INHERIT_FROM_BLOCK(creature, CREATURE_TAG, object, OBJECT_TAG, creature_block_block );

	TAG_BLOCK(creature_scalar_timing_block, 1)
	{
		FIELD( _field_struct, "function_curve", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(creature_block, 1, creature_struct_definition_struct_definition );

	TAG_STRUCT(creature_struct_definition)
	{
		FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
		FIELD( _field_custom, "$$$ CREATURE $$$" ),
		FIELD( _field_long_flags, "flags", &creature_definition_flags ),
		FIELD( _field_enum, "default team", &unit_default_teams ),
		FIELD( _field_enum, "motion sensor blip size", &global_chud_blip_type_definition ),
		FIELD( _field_angle, "turning velocity maximum:degrees per second" ),
		FIELD( _field_angle, "turning acceleration maximum:degrees per second squared" ),
		FIELD( _field_real_fraction, "casual turning modifier:[0,1]" ),
		FIELD( _field_real, "autoaim width:world units" ),
		FIELD( _field_struct, "physics", &character_physics_struct_struct_definition ),
		FIELD( _field_tag_reference, "impact damage" ),
		FIELD( _field_tag_reference, "impact shield damage#if not specified, uses \'impact damage\'" ),
		FIELD( _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block_block ),
		FIELD( _field_explanation, "death and destruction" ),
		FIELD( _field_real_bounds, "destroy after death time:seconds#if non-zero, the creature will destroy itself upon death after this much time" ),
		FIELD( _field_explanation, "big battle" ),
		FIELD( _field_long_flags, "big battle flags", &creature_big_battle_definition_flags ),
		FIELD( _field_tag_reference, "big battle weapon emitter" ),
		FIELD( _field_real_point_3d, "big battle weapon offset" ),
		FIELD( _field_tag_reference, "big battle weapon emitter 2#if you leave this empty, only the first emitter will fire" ),
		FIELD( _field_real_point_3d, "big battle weapon offset 2" ),
		FIELD( _field_block, "big battle weapon fire timing", &creature_scalar_timing_block_block ),
		FIELD( _field_tag_reference, "big battle expensive weapon effect#this fires a full effect from location up, oriented along vehicle\'s forward and up axes" ),
		FIELD( _field_real_bounds, "expensive weapon fire time:seconds" ),
		FIELD( _field_tag_reference, "big battle death effect" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(creature_big_battle_definition_flags, 3)
	{
		OPTION("boid aims at big battle target#setting this forces boid to aim at target instead of firing straight ahead"),
		OPTION("boids fly with no pitch#flying boids will always stay level when changing altitude"),
		OPTION("boids fly non-directionally#flying boids will move like helicopters"),
	};

	TAG_ENUM(creature_definition_flags, 7)
	{
		OPTION("unused"),
		OPTION("immune to falling damage"),
		OPTION("rotate while airborne"),
		OPTION("zapped by shields"),
		OPTION("attach upon impact"),
		OPTION("not on motion sensor"),
		OPTION("force ground movement"),
	};

	TAG_ENUM(unit_default_teams, 9)
	{
		OPTION("default"),
		OPTION("player"),
		OPTION("human"),
		OPTION("covenant"),
		OPTION("brute"),
		OPTION("mule"),
		OPTION("spare"),
		OPTION("covenant_player"),
		OPTION("forerunner"),
	};

} // namespace blofeld

