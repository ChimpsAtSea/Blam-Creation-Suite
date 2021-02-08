#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SCENARIO_DECORATOR_BLOCK_ID { 0xDCA3DA7E, 0xDA4B412B, 0xBED1DC74, 0xF6507BAC }
	TAG_BLOCK(
		scenario_decorator_block,
		"scenario_decorator_block",
		1,
		"s_scenario_new_decorator_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_DECORATOR_BLOCK_ID)
	{
		{ _field_struct, "brush", &decorator_brush_struct },
		{ _field_long_integer, "decorator count", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "current bsp count", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "global offset", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_vector_3d, "global x", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_vector_3d, "global y", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_vector_3d, "global z", FIELD_FLAG_UNKNOWN0 },
		{ _field_block, "palette", &decorator_palette_block },
		{ _field_block, "sets", &decorator_scenario_set_block },
		{ _field_terminator }
	};

	#define DECORATOR_PALETTE_ID { 0xD416B945, 0x6A6045D6, 0xA46B060A, 0x6D084231 }
	TAG_BLOCK(
		decorator_palette_block,
		"decorator_palette",
		MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO,
		"s_decorator_palette",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DECORATOR_PALETTE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "decorator set 0", &decorator_scenario_set_block },
		{ _field_word_integer, "decorator weight 0" },
		{ _field_short_block_index, "decorator set 1", &decorator_scenario_set_block },
		{ _field_word_integer, "decorator weight 1" },
		{ _field_short_block_index, "decorator set 2", &decorator_scenario_set_block },
		{ _field_word_integer, "decorator weight 2" },
		{ _field_short_block_index, "decorator set 3", &decorator_scenario_set_block },
		{ _field_word_integer, "decorator weight 3" },
		{ _field_short_block_index, "decorator set 4", &decorator_scenario_set_block },
		{ _field_word_integer, "decorator weight 4" },
		{ _field_short_block_index, "decorator set 5", &decorator_scenario_set_block },
		{ _field_word_integer, "decorator weight 5" },
		{ _field_short_block_index, "decorator set 6", &decorator_scenario_set_block },
		{ _field_word_integer, "decorator weight 6" },
		{ _field_short_block_index, "decorator set 7", &decorator_scenario_set_block },
		{ _field_word_integer, "decorator weight 7" },
		{ _field_terminator }
	};

	#define DECORATOR_SCENARIO_SET_BLOCK_ID { 0x40576308, 0x4FC747DD, 0xAED99352, 0xBE229502 }
	TAG_BLOCK(
		decorator_scenario_set_block,
		"decorator_scenario_set_block",
		MAXIMUM_DECORATOR_SETS_PER_SCENARIO,
		"s_decorator_scenario_set_placements",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DECORATOR_SCENARIO_SET_BLOCK_ID)
	{
		{ _field_tag_reference, "decorator set", FIELD_FLAG_INDEX, &global_decorator_set_reference },
		{ _field_block, "placements", FIELD_FLAG_READ_ONLY, &global_decorator_placement_block },
		{ _field_terminator }
	};

	#define GLOBAL_DECORATOR_PLACEMENT_BLOCK_ID { 0x04F0AFBF, 0x257649DF, 0x916C1650, 0xEC5FBF80 }
	TAG_BLOCK(
		global_decorator_placement_block,
		"global_decorator_placement_block",
		MAXIMUM_DECORATOR_PLACEMENTS_PER_SET,
		"s_decorator_placement",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_DECORATOR_PLACEMENT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_byte_integer, "type index" },
		{ _field_byte_integer, "motion scale" },
		{ _field_byte_integer, "ground tint" },
		{ _field_byte_flags, "flags", &decorator_placement_flags_definition },
		{ _field_real_quaternion, "rotation" },
		{ _field_real, "scale" },
		{ _field_real_point_3d, "tint color" },
		{ _field_real_point_3d, "original point" },
		{ _field_real_point_3d, "original normal" },
		{ _field_long_integer, "bsp index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "cluster index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "cluster decorator set index", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define DECORATOR_BRUSH_STRUCT_ID { 0xC3DB84FA, 0xC247443B, 0x9093336D, 0xF7E811A2 }
	TAG_STRUCT(
		decorator_brush_struct,
		"decorator_brush_struct",
		"s_decorator_brush_options",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DECORATOR_BRUSH_STRUCT_ID)
	{
		{ _field_long_enum, "left button brush", &decorator_left_brush_type_enum_definition, _field_id_enum },
		{ _field_long_enum, "middle button brush", &decorator_right_brush_type_enum_definition, _field_id_enum },
		{ _field_long_enum, "control+left button brush", &decorator_left_brush_type_enum_definition, _field_id_enum },
		{ _field_long_enum, "control+middle button brush", &decorator_right_brush_type_enum_definition, _field_id_enum },
		{ _field_long_enum, "alt+left button brush", &decorator_left_brush_type_enum_definition, _field_id_enum },
		{ _field_long_enum, "alt+middle button brush", &decorator_right_brush_type_enum_definition, _field_id_enum },
		{ _field_real, "outer radius", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "feather percent", FIELD_FLAG_UNKNOWN0 },
		{ _field_byte_flags, "reapply flags", &decorator_brush_reapply_flags_definition },
		{ _field_byte_flags, "render flags", &decorator_brush_render_flags_definition },
		{ _field_byte_flags, "action flags", &decorator_brush_action_flags_definition },
		{ _field_char_enum, "brush shape", &decorator_brush_shape_enum_definition },
		{ _field_long_block_index, "current palette", &decorator_palette_block },
		{ _field_long_block_index, "current set", &decorator_scenario_set_block },
		{ _field_long_integer, "current type", _field_id_decorator_brush_unknown },
		{ _field_real, "paint rate" },
		{ _field_real_rgb_color, "paint color" },
		{ _field_real, "move distance", "drop height for drop to ground" },
		{ _field_real, "angle snap interval", "rotate brushes will snap to intervals of this" },
		{ _field_real, "Editor cull distance", "decorators will not draw beyond this distance from the camera" },
		FIELD_EXPLANATION("KEYS", nullptr, FIELD_FLAG_NONE, "[] \t brush size\n-= \t brush feathering\n0-9 \t brush opacity\nSHIFT+0-9\t select palette\nSHIFT\t while painting will reverse the operation\n"),
		{ _field_terminator }
	};

	STRINGS(decorator_placement_flags_definition)
	{
		"UNUSED!",
		"UNUSED2!"
	};
	STRING_LIST(decorator_placement_flags_definition, decorator_placement_flags_definition_strings, _countof(decorator_placement_flags_definition_strings));

	STRINGS(decorator_left_brush_type_enum_definition)
	{
		"fill add",
		"airbrush add",
		"airbrush color",
		"airbrush erase",
		"density smooth",
		"precision place",
		"precision delete",
		"scale",
		"scale additive",
		"scale subtractive",
		"rotate random",
		"rotate normal",
		"rotate local",
		"eraser",
		"reapply type settings",
		"raise to ground (use reapply flags)",
		"drop to ground (use reapply flags)",
		"comb",
		"thin"
	};
	STRING_LIST(decorator_left_brush_type_enum_definition, decorator_left_brush_type_enum_definition_strings, _countof(decorator_left_brush_type_enum_definition_strings));

	STRINGS(decorator_right_brush_type_enum_definition)
	{
		"fill add",
		"airbrush add",
		"airbrush color",
		"airbrush erase",
		"density smooth",
		"precision place",
		"precision delete",
		"scale",
		"scale additive",
		"scale subtractive",
		"rotate random",
		"rotate normal",
		"rotate local",
		"eraser",
		"reapply type settings",
		"raise to ground (use reapply flags)",
		"drop to ground (use reapply flags)",
		"comb",
		"thin"
	};
	STRING_LIST(decorator_right_brush_type_enum_definition, decorator_right_brush_type_enum_definition_strings, _countof(decorator_right_brush_type_enum_definition_strings));

	STRINGS(decorator_brush_reapply_flags_definition)
	{
		"reapply hover",
		"reapply orientation",
		"reapply scale",
		"reapply motion",
		"reapply color",
		"reapply ground tint",
		"reapply all decorators"
	};
	STRING_LIST(decorator_brush_reapply_flags_definition, decorator_brush_reapply_flags_definition_strings, _countof(decorator_brush_reapply_flags_definition_strings));

	STRINGS(decorator_brush_render_flags_definition)
	{
		"render preview",
		"render in radius only",
		"render selected only",
		"dont render lines"
	};
	STRING_LIST(decorator_brush_render_flags_definition, decorator_brush_render_flags_definition_strings, _countof(decorator_brush_render_flags_definition_strings));

	STRINGS(decorator_brush_action_flags_definition)
	{
		"clamp scale",
		"enforce minimum distance",
		"select all decorator sets",
		"use global up",
		"constrain to a single channel"
	};
	STRING_LIST(decorator_brush_action_flags_definition, decorator_brush_action_flags_definition_strings, _countof(decorator_brush_action_flags_definition_strings));

	STRINGS(decorator_brush_shape_enum_definition)
	{
		"flattened sphere",
		"spherical",
		"tall sphere",
		"floating sphere"
	};
	STRING_LIST(decorator_brush_shape_enum_definition, decorator_brush_shape_enum_definition_strings, _countof(decorator_brush_shape_enum_definition_strings));

} // namespace macaque

} // namespace blofeld

