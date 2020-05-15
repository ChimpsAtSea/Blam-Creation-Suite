#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(muffin_permutation_name, SHORT_MAX)
{
	{ _field_string_id, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(muffin_marker, SHORT_MAX)
{
	{ _field_string_id, "name^" },
	{ _field_word_integer, "muffinage chance:percent [0 - 100]#how often muffins will appear on this marker" },
	{ _field_word_block_flags, "allowed muffin types" },
	{ _field_terminator },
};

TAG_BLOCK(global_muffin_type, 16)
{
	{ _field_short_block_index, "mesh^" },
	{ _field_word_flags, "flags" },
	{ _field_real_bounds, "spawn delay:seconds#how long to wait before spawning these muffins" },
	{ _field_explanation, "SCALE" },
	{ _field_real_bounds, "random scale:[0-1]" },
	{ _field_struct, "initial growth" },
	{ _field_real, "growth time:seconds" },
	{ _field_struct, "periodic noise" },
	{ _field_explanation, "JIGGLE" },
	{ _field_real, "jiggle:[0.0 - 1.0]#how much the muffin jiggles (0 = perfectly rigid, 1 = full jiggle, subject to parameters below)" },
	{ _field_real, "jiggle spring length:world units#spring length affects how the spring reacts to the model moving (this should be approximately how far the muffin sticks out from the model)" },
	{ _field_real, "jiggle spring strength:[0.01 - 1.0]#spring strength affects how fast the muffins jiggle (higher numbers jiggle faster)" },
	{ _field_real, "jiggle velocity damp:[0.5 - 0.95]#velocity damp affects how long the muffins jiggle (the higher numbers jiggle exponentially longer, 1.0 will never stop jiggling)" },
	{ _field_real, "jiggle max velocity:world units per frame#this just clamps how fast the muffin can jiggle, to keep it from exploding" },
	{ _field_explanation, "DEATH" },
	{ _field_real_bounds, "lifetime:seconds#how long before the muffins die" },
	{ _field_real, "immortality chance:[0.0 - 1.0]#the chance that any give muffin of this type will live forever" },
	{ _field_tag_reference, "death effect" },
	{ _field_terminator },
};

TAG_GROUP(muffin, MUFFIN_TAG)
{
	{ _field_custom, "link to render model" },
	{ _field_tag_reference, "render model*" },
	{ _field_block, "render model permutation names!", &muffin_permutation_name_block },
	{ _field_long_integer, "render model permutation name valid count!" },
	{ _field_block, "muffin markers{default markers}#defines where muffins appear, how often, and which types", &muffin_marker_block },
	{ _field_block, "muffin types", &global_muffin_type_block },
	{ _field_terminator },
};

} // namespace blofeld

