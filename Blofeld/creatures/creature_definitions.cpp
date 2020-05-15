#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(creature_scalar_timing, 1)
{
	{ _field_struct, "function_curve" },
	{ _field_terminator },
};

TAG_GROUP(big_battle_creature, BIG_BATTLE_CREATURE_TAG)
{
	{ _field_custom, "CREATURE" },
	{ _field_long_flags, "flags" },
	{ _field_enum, "default team" },
	{ _field_enum, "motion sensor blip size" },
	{ _field_angle, "turning velocity maximum:degrees per second" },
	{ _field_angle, "turning acceleration maximum:degrees per second squared" },
	{ _field_real_fraction, "casual turning modifier:[0,1]" },
	{ _field_real, "autoaim width:world units" },
	{ _field_struct, "physics" },
	{ _field_tag_reference, "impact damage" },
	{ _field_tag_reference, "impact shield damage#if not specified, uses \'impact damage\'" },
	{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block },
	{ _field_explanation, "death and destruction" },
	{ _field_real_bounds, "destroy after death time:seconds#if non-zero, the creature will destroy itself upon death after this much time" },
	{ _field_explanation, "big battle" },
	{ _field_long_flags, "big battle flags" },
	{ _field_tag_reference, "big battle weapon emitter" },
	{ _field_real_point_3d, "big battle weapon offset" },
	{ _field_tag_reference, "big battle weapon emitter 2#if you leave this empty, only the first emitter will fire" },
	{ _field_real_point_3d, "big battle weapon offset 2" },
	{ _field_block, "big battle weapon fire timing", &creature_scalar_timing_block },
	{ _field_tag_reference, "big battle expensive weapon effect#this fires a full effect from location up, oriented along vehicle\'s forward and up axes" },
	{ _field_real_bounds, "expensive weapon fire time:seconds" },
	{ _field_tag_reference, "big battle death effect" },
	{ _field_custom },
	{ _field_tag_reference, "imposter model" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(creature, CREATURE_TAG, object, OBJECT_TAG)
{
	{ _field_struct, "object" },
	{ _field_custom, "$$$ CREATURE $$$" },
	{ _field_long_flags, "flags" },
	{ _field_enum, "default team" },
	{ _field_enum, "motion sensor blip size" },
	{ _field_angle, "turning velocity maximum:degrees per second" },
	{ _field_angle, "turning acceleration maximum:degrees per second squared" },
	{ _field_real_fraction, "casual turning modifier:[0,1]" },
	{ _field_real, "autoaim width:world units" },
	{ _field_struct, "physics" },
	{ _field_tag_reference, "impact damage" },
	{ _field_tag_reference, "impact shield damage#if not specified, uses \'impact damage\'" },
	{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block },
	{ _field_explanation, "death and destruction" },
	{ _field_real_bounds, "destroy after death time:seconds#if non-zero, the creature will destroy itself upon death after this much time" },
	{ _field_explanation, "big battle" },
	{ _field_long_flags, "big battle flags" },
	{ _field_tag_reference, "big battle weapon emitter" },
	{ _field_real_point_3d, "big battle weapon offset" },
	{ _field_tag_reference, "big battle weapon emitter 2#if you leave this empty, only the first emitter will fire" },
	{ _field_real_point_3d, "big battle weapon offset 2" },
	{ _field_block, "big battle weapon fire timing", &creature_scalar_timing_block },
	{ _field_tag_reference, "big battle expensive weapon effect#this fires a full effect from location up, oriented along vehicle\'s forward and up axes" },
	{ _field_real_bounds, "expensive weapon fire time:seconds" },
	{ _field_tag_reference, "big battle death effect" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

