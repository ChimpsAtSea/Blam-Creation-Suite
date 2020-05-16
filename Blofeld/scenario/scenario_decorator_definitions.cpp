#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(decorator_brush_struct)
{
	FIELD( _field_long_enum, "left button brush" ),
	FIELD( _field_long_enum, "middle button brush" ),
	FIELD( _field_long_enum, "control+left button brush" ),
	FIELD( _field_long_enum, "control+middle button brush" ),
	FIELD( _field_long_enum, "alt+left button brush" ),
	FIELD( _field_long_enum, "alt+middle button brush" ),
	FIELD( _field_real, "outer radius!" ),
	FIELD( _field_real, "feather percent!" ),
	FIELD( _field_byte_flags, "reapply flags" ),
	FIELD( _field_byte_flags, "render flags" ),
	FIELD( _field_byte_flags, "action flags" ),
	FIELD( _field_char_enum, "brush shape" ),
	FIELD( _field_long_block_index, "current palette" ),
	FIELD( _field_long_block_index, "current set" ),
	FIELD( _field_long_integer, "current type" ),
	FIELD( _field_real, "paint rate:[0 - 1]" ),
	FIELD( _field_real_rgb_color, "paint color" ),
	FIELD( _field_real, "move distance#drop height for drop to ground" ),
	FIELD( _field_real, "angle snap interval#rotate brushes will snap to intervals of this" ),
	FIELD( _field_real, "Editor cull distance#decorators will not draw beyond this distance from the camera" ),
	FIELD( _field_explanation, "KEYS" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_decorator_block, 1)
{
	FIELD( _field_struct, "brush", &decorator_brush_struct_struct_definition ),
	FIELD( _field_long_integer, "decorator count*" ),
	FIELD( _field_long_integer, "current bsp count*" ),
	FIELD( _field_real_vector_3d, "global offset!" ),
	FIELD( _field_real_vector_3d, "global x!" ),
	FIELD( _field_real_vector_3d, "global y!" ),
	FIELD( _field_real_vector_3d, "global z!" ),
	FIELD( _field_block, "palette", &decorator_palette ),
	FIELD( _field_block, "sets", &decorator_scenario_set_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(decorator_palette, MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_short_block_index, "decorator set 0" ),
	FIELD( _field_word_integer, "decorator weight 0" ),
	FIELD( _field_short_block_index, "decorator set 1" ),
	FIELD( _field_word_integer, "decorator weight 1" ),
	FIELD( _field_short_block_index, "decorator set 2" ),
	FIELD( _field_word_integer, "decorator weight 2" ),
	FIELD( _field_short_block_index, "decorator set 3" ),
	FIELD( _field_word_integer, "decorator weight 3" ),
	FIELD( _field_short_block_index, "decorator set 4" ),
	FIELD( _field_word_integer, "decorator weight 4" ),
	FIELD( _field_short_block_index, "decorator set 5" ),
	FIELD( _field_word_integer, "decorator weight 5" ),
	FIELD( _field_short_block_index, "decorator set 6" ),
	FIELD( _field_word_integer, "decorator weight 6" ),
	FIELD( _field_short_block_index, "decorator set 7" ),
	FIELD( _field_word_integer, "decorator weight 7" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(decorator_scenario_set_block, MAXIMUM_DECORATOR_SETS_PER_SCENARIO)
{
	FIELD( _field_tag_reference, "decorator set^" ),
	FIELD( _field_block, "placements*", &global_decorator_placement_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_decorator_placement_block, MAXIMUM_DECORATOR_PLACEMENTS_PER_SET)
{
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_byte_integer, "type index" ),
	FIELD( _field_byte_integer, "motion scale" ),
	FIELD( _field_byte_integer, "ground tint" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_real_quaternion, "rotation" ),
	FIELD( _field_real, "scale" ),
	FIELD( _field_real_point_3d, "tint color" ),
	FIELD( _field_real_point_3d, "original point" ),
	FIELD( _field_real_point_3d, "original normal" ),
	FIELD( _field_long_integer, "bsp index!" ),
	FIELD( _field_short_integer, "cluster index!" ),
	FIELD( _field_short_integer, "cluster decorator set index!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

