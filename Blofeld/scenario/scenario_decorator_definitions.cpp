#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_decorator, 1)
{
	{ _field_struct, "brush" },
	{ _field_long_integer, "decorator count*" },
	{ _field_long_integer, "current bsp count*" },
	{ _field_real_vector_3d, "global offset!" },
	{ _field_real_vector_3d, "global x!" },
	{ _field_real_vector_3d, "global y!" },
	{ _field_real_vector_3d, "global z!" },
	{ _field_block, "palette", &decorator_palette_block },
	{ _field_block, "sets", &decorator_scenario_set_block },
	{ _field_terminator },
};

TAG_BLOCK(decorator_palette, MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO)
{
	{ _field_string_id, "name^" },
	{ _field_short_block_index, "decorator set 0" },
	{ _field_word_integer, "decorator weight 0" },
	{ _field_short_block_index, "decorator set 1" },
	{ _field_word_integer, "decorator weight 1" },
	{ _field_short_block_index, "decorator set 2" },
	{ _field_word_integer, "decorator weight 2" },
	{ _field_short_block_index, "decorator set 3" },
	{ _field_word_integer, "decorator weight 3" },
	{ _field_short_block_index, "decorator set 4" },
	{ _field_word_integer, "decorator weight 4" },
	{ _field_short_block_index, "decorator set 5" },
	{ _field_word_integer, "decorator weight 5" },
	{ _field_short_block_index, "decorator set 6" },
	{ _field_word_integer, "decorator weight 6" },
	{ _field_short_block_index, "decorator set 7" },
	{ _field_word_integer, "decorator weight 7" },
	{ _field_terminator },
};

TAG_BLOCK(decorator_scenario_set, MAXIMUM_DECORATOR_SETS_PER_SCENARIO)
{
	{ _field_tag_reference, "decorator set^" },
	{ _field_block, "placements*", &global_decorator_placement_block },
	{ _field_terminator },
};

TAG_BLOCK(global_decorator_placement, MAXIMUM_DECORATOR_PLACEMENTS_PER_SET)
{
	{ _field_real_point_3d, "position" },
	{ _field_byte_integer, "type index" },
	{ _field_byte_integer, "motion scale" },
	{ _field_byte_integer, "ground tint" },
	{ _field_byte_flags, "flags" },
	{ _field_real_quaternion, "rotation" },
	{ _field_real, "scale" },
	{ _field_real_point_3d, "tint color" },
	{ _field_real_point_3d, "original point" },
	{ _field_real_point_3d, "original normal" },
	{ _field_long_integer, "bsp index!" },
	{ _field_short_integer, "cluster index!" },
	{ _field_short_integer, "cluster decorator set index!" },
	{ _field_terminator },
};

} // namespace blofeld

