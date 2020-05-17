#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(decorator_placement_flags_definition, 2)
	{
		OPTION("UNUSED!"),
		OPTION("UNUSED2!"),
	};

	TAG_ENUM(decorator_left_brush_type_enum_definition, 19)
	{
		OPTION("fill add"),
		OPTION("airbrush add"),
		OPTION("airbrush color"),
		OPTION("airbrush erase"),
		OPTION("density smooth"),
		OPTION("precision place"),
		OPTION("precision delete"),
		OPTION("scale"),
		OPTION("scale additive"),
		OPTION("scale subtractive"),
		OPTION("rotate random"),
		OPTION("rotate normal"),
		OPTION("rotate local"),
		OPTION("eraser"),
		OPTION("reapply type settings"),
		OPTION("raise to ground (use reapply flags)"),
		OPTION("drop to ground (use reapply flags)"),
		OPTION("comb"),
		OPTION("thin"),
	};

	TAG_ENUM(decorator_right_brush_type_enum_definition, 19)
	{
		OPTION("fill add"),
		OPTION("airbrush add"),
		OPTION("airbrush color"),
		OPTION("airbrush erase"),
		OPTION("density smooth"),
		OPTION("precision place"),
		OPTION("precision delete"),
		OPTION("scale"),
		OPTION("scale additive"),
		OPTION("scale subtractive"),
		OPTION("rotate random"),
		OPTION("rotate normal"),
		OPTION("rotate local"),
		OPTION("eraser"),
		OPTION("reapply type settings"),
		OPTION("raise to ground (use reapply flags)"),
		OPTION("drop to ground (use reapply flags)"),
		OPTION("comb"),
		OPTION("thin"),
	};

	TAG_ENUM(decorator_brush_reapply_flags_definition, 7)
	{
		OPTION("reapply hover"),
		OPTION("reapply orientation"),
		OPTION("reapply scale"),
		OPTION("reapply motion"),
		OPTION("reapply color"),
		OPTION("reapply ground tint"),
		OPTION("reapply all decorators"),
	};

	TAG_ENUM(decorator_brush_render_flags_definition, 4)
	{
		OPTION("render preview"),
		OPTION("render in radius only"),
		OPTION("render selected only"),
		OPTION("dont render lines"),
	};

	TAG_ENUM(decorator_brush_action_flags_definition, 5)
	{
		OPTION("clamp scale"),
		OPTION("enforce minimum distance"),
		OPTION("select all decorator sets"),
		OPTION("use global up"),
		OPTION("constrain to a single channel"),
	};

	TAG_ENUM(decorator_brush_shape_enum_definition, 4)
	{
		OPTION("flattened sphere"),
		OPTION("spherical"),
		OPTION("tall sphere"),
		OPTION("floating sphere"),
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
		FIELD( _field_block, "palette", &decorator_palette_block ),
		FIELD( _field_block, "sets", &decorator_scenario_set_block_block ),
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
		FIELD( _field_block, "placements*", &global_decorator_placement_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(global_decorator_placement_block, MAXIMUM_DECORATOR_PLACEMENTS_PER_SET)
	{
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_byte_integer, "type index" ),
		FIELD( _field_byte_integer, "motion scale" ),
		FIELD( _field_byte_integer, "ground tint" ),
		FIELD( _field_byte_flags, "flags", &decorator_placement_flags_definition ),
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

TAG_STRUCT(decorator_brush_struct)
{
		FIELD( _field_long_enum, "left button brush", &decorator_left_brush_type_enum_definition ),
		FIELD( _field_long_enum, "middle button brush", &decorator_right_brush_type_enum_definition ),
		FIELD( _field_long_enum, "control+left button brush", &decorator_left_brush_type_enum_definition ),
		FIELD( _field_long_enum, "control+middle button brush", &decorator_right_brush_type_enum_definition ),
		FIELD( _field_long_enum, "alt+left button brush", &decorator_left_brush_type_enum_definition ),
		FIELD( _field_long_enum, "alt+middle button brush", &decorator_right_brush_type_enum_definition ),
		FIELD( _field_real, "outer radius!" ),
		FIELD( _field_real, "feather percent!" ),
		FIELD( _field_byte_flags, "reapply flags", &decorator_brush_reapply_flags_definition ),
		FIELD( _field_byte_flags, "render flags", &decorator_brush_render_flags_definition ),
		FIELD( _field_byte_flags, "action flags", &decorator_brush_action_flags_definition ),
		FIELD( _field_char_enum, "brush shape", &decorator_brush_shape_enum_definition ),
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

} // namespace blofeld

