#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(emblem_library, EMBLEM_LIBRARY_TAG, emblem_library_block_block );

	V5_TAG_BLOCK(emblem_bitmap_list, s_emblem_library::k_max_bitmap_list_count)
	{
		{ _field_string_id, "name^" },
		{ _field_short_integer, "bitmap index#the index of the bitmap in the bitmap group" },
		{ _field_pad, "ASDFJIJJGHJFL", 2 },
		{ _field_real, "gradient size:pixels#the size of the gradient (from white to black) in this bitmap" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(emblem_shape_list, s_emblem_library::k_max_shape_list_count)
	{
		{ _field_string_id, "name^" },
		{ _field_short_block_index, "bitmap" },
		{ _field_enum, "address mode x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "address mode y", &render_method_bitmap_address_mode_enum },
		{ _field_pad, "FGKKGKHL", 2 },
		{ _field_struct, "transform", &emblem_transform_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(emblem_front_list, s_emblem_library::k_max_front_emblem_count)
	{
		{ _field_string_id, "name^" },
		{ _field_explanation, "Layer 0 (foreground)", "Composed of two shapes\n" },
		{ _field_struct, "layer 0", &emblem_layer_struct_definition },
		{ _field_explanation, "Layer 1 (midground)", "This layer is behind the foreground, and in front of the background\n" },
		{ _field_struct, "layer 1", &emblem_layer_struct_definition },
		{ _field_explanation, "Misc", "Extra configuration\n" },
		{ _field_char_enum, "primary layer#layer that is considered \"primary\" and which will use the primary color", &front_emblem_primary_layer },
		{ _field_pad, "pad0", 1 },
		{ _field_pad, "pad1", 2 },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(emblem_back_list, s_emblem_library::k_max_back_emblem_count)
	{
		{ _field_string_id, "name^" },
		{ _field_explanation, "Layer 2 (background)", "\n" },
		{ _field_struct, "layer 2", &emblem_layer_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(emblem_runtime_front_list, s_emblem_library::k_max_front_emblem_count)
	{
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "name0" },

		{ _field_short_integer, "bitmap0_index" },
		{ _field_enum, "bitmap0_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap0_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_short_integer, "bitmap1_index" },
		{ _field_enum, "bitmap1_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap1_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_real_quaternion, "bitmap_transform0" },
		{ _field_real_quaternion, "bitmap_transform1" },
		{ _field_real_quaternion, "bitmap_transform2" },
		{ _field_real_quaternion, "bitmap_transform3" },
		{ _field_real_quaternion, "bitmap_params0" },
		{ _field_real_quaternion, "bitmap_params1" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "name1" },

		{ _field_short_integer, "bitmap2_index" },
		{ _field_enum, "bitmap2_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap2_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_short_integer, "bitmap3_index" },
		{ _field_enum, "bitmap3_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap3_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_real_quaternion, "bitmap_transform4" },
		{ _field_real_quaternion, "bitmap_transform5" },
		{ _field_real_quaternion, "bitmap_transform6" },
		{ _field_real_quaternion, "bitmap_transform7" },
		{ _field_real_quaternion, "bitmap_params2" },
		{ _field_real_quaternion, "bitmap_params3" },
		{ _field_char_enum, "primary layer", &front_emblem_primary_layer },
		{ _field_pad, "pad0", 1 },
		{ _field_pad, "pad1", 2 },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(emblem_runtime_back_list, s_emblem_library::k_max_back_emblem_count)
	{
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "name" },

		{ _field_short_integer, "bitmap0_index" },
		{ _field_enum, "bitmap0_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap0_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_short_integer, "bitmap1_index" },
		{ _field_enum, "bitmap1_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap1_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_real_quaternion, "bitmap_transform0" },
		{ _field_real_quaternion, "bitmap_transform1" },
		{ _field_real_quaternion, "bitmap_transform2" },
		{ _field_real_quaternion, "bitmap_transform3" },
		{ _field_real_quaternion, "bitmap_params0" },
		{ _field_real_quaternion, "bitmap_params1" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(emblem_library_block, 1, emblem_library_struct_definition_struct_definition );

	V5_TAG_STRUCT(emblem_library_struct_definition)
	{
		{ _field_explanation, "Emblem Library", "This library contains the definitions of all the player emblems\nAll the compositions and transformations that build an emblem are defined in this tag.\nEach emblem is composed of a number of shapes.\nAnd each shape is defined by transformations on an emblem bitmap.\n" },
		{ _field_short_integer, "version!" },
		{ _field_pad, "jfejkjjg", 2 },
		{ _field_custom, "Bitmaps" },
		{ _field_explanation, "Bitmaps", "\n" },
		{ _field_real, "bitmap resolution:pixels#used to calculate appropriate antialiasing settings" },
		{ _field_real, "antialias sharpen#default 1.0, global control on antialias sharpness" },
		{ _field_tag_reference, "emblem bitmaps", &global_bitmap_reference },
		{ _field_tag_reference, "emblem bitmaps hi rez", &global_bitmap_reference },
		{ _field_block, "bitmaps", &emblem_bitmap_list_block },
		{ _field_custom },
		{ _field_explanation, "Shapes", "\n" },
		{ _field_block, "shapes", &emblem_shape_list_block },
		{ _field_explanation, "Emblems", "\n" },
		{ _field_block, "front emblems", &emblem_front_list_block },
		{ _field_block, "back emblems", &emblem_back_list_block },
		{ _field_block, "runtime front!", &emblem_runtime_front_list_block },
		{ _field_block, "runtime back!", &emblem_runtime_back_list_block },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(emblem_transform)
	{
		{ _field_real_point_2d, "scale" },
		{ _field_real_point_2d, "shear" },
		{ _field_real, "rotation" },
		{ _field_real_point_2d, "offset" },
		{ _field_real, "expand contract#amount to expand (positive) or contract (negative) the shape outline" },
		{ _field_real, "blur#amount to blur the shape outline" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(emblem_layer)
	{
		{ _field_explanation, "Shape 0", "Multiplier allows you to control how these shapes are combined.\nFor example, mult0= 1.0 and mult1= -1.0 causes shape 1 to be subtracted from shape 0.\n" },
		{ _field_short_block_index, "shape 0" },
		{ _field_pad, "fkkfkll", 2 },
		{ _field_real, "multiplier 0" },
		{ _field_struct, "transform 0", &emblem_transform_struct_definition },
		{ _field_explanation, "Shape 1", "\n" },
		{ _field_short_block_index, "shape 1" },
		{ _field_pad, "fkkfkllf", 2 },
		{ _field_real, "multiplier 1" },
		{ _field_struct, "transform 1", &emblem_transform_struct_definition },
		{ _field_terminator }
	};

	STRINGS(front_emblem_primary_layer)
	{
		"Layer 0 (foreground)",
		"Layer 1 (midground)"
	};
	STRING_LIST(front_emblem_primary_layer, front_emblem_primary_layer_strings, _countof(front_emblem_primary_layer_strings));

	TAG_REFERENCE(global_emblem_library_parameters_reference, EMBLEM_LIBRARY_TAG);

} // namespace blofeld

