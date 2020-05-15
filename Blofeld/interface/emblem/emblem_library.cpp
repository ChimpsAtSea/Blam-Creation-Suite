#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(emblem_bitmap_list, s_emblem_library::k_max_bitmap_list_count)
{
	{ _field_string_id, "name^" },
	{ _field_short_integer, "bitmap index#the index of the bitmap in the bitmap group" },
	{ _field_pad, "ASDFJIJJGHJFL", 2 },
	{ _field_real, "gradient size:pixels#the size of the gradient (from white to black) in this bitmap" },
	{ _field_terminator },
};

TAG_BLOCK(emblem_shape_list, s_emblem_library::k_max_shape_list_count)
{
	{ _field_string_id, "name^" },
	{ _field_short_block_index, "bitmap" },
	{ _field_enum, "address mode x" },
	{ _field_enum, "address mode y" },
	{ _field_pad, "FGKKGKHL", 2 },
	{ _field_struct, "transform" },
	{ _field_terminator },
};

TAG_BLOCK(emblem_front_list, s_emblem_library::k_max_front_emblem_count)
{
	{ _field_string_id, "name^" },
	{ _field_explanation, "Layer 0 (foreground)" },
	{ _field_struct, "layer 0" },
	{ _field_explanation, "Layer 1 (midground)" },
	{ _field_struct, "layer 1" },
	{ _field_explanation, "Misc" },
	{ _field_char_enum, "primary layer#layer that is considered \"primary\" and which will use the primary color" },
	{ _field_pad, "pad0", 1 },
	{ _field_pad, "pad1", 2 },
	{ _field_terminator },
};

TAG_BLOCK(emblem_back_list, s_emblem_library::k_max_back_emblem_count)
{
	{ _field_string_id, "name^" },
	{ _field_explanation, "Layer 2 (background)" },
	{ _field_struct, "layer 2" },
	{ _field_terminator },
};

TAG_BLOCK(emblem_runtime_front_list, s_emblem_library::k_max_front_emblem_count)
{
	{ _field_string_id, "name0" },
	{ _field_short_integer, "bitmap0_index" },
	{ _field_enum, "bitmap0_address_x" },
	{ _field_enum, "bitmap0_address_y" },
	{ _field_short_integer, "bitmap1_index" },
	{ _field_enum, "bitmap1_address_x" },
	{ _field_enum, "bitmap1_address_y" },
	{ _field_real_quaternion, "bitmap_transform0" },
	{ _field_real_quaternion, "bitmap_transform1" },
	{ _field_real_quaternion, "bitmap_transform2" },
	{ _field_real_quaternion, "bitmap_transform3" },
	{ _field_real_quaternion, "bitmap_params0" },
	{ _field_real_quaternion, "bitmap_params1" },
	{ _field_string_id, "name1" },
	{ _field_short_integer, "bitmap2_index" },
	{ _field_enum, "bitmap2_address_x" },
	{ _field_enum, "bitmap2_address_y" },
	{ _field_short_integer, "bitmap3_index" },
	{ _field_enum, "bitmap3_address_x" },
	{ _field_enum, "bitmap3_address_y" },
	{ _field_real_quaternion, "bitmap_transform4" },
	{ _field_real_quaternion, "bitmap_transform5" },
	{ _field_real_quaternion, "bitmap_transform6" },
	{ _field_real_quaternion, "bitmap_transform7" },
	{ _field_real_quaternion, "bitmap_params2" },
	{ _field_real_quaternion, "bitmap_params3" },
	{ _field_char_enum, "primary layer" },
	{ _field_pad, "pad0", 1 },
	{ _field_pad, "pad1", 2 },
	{ _field_terminator },
};

TAG_BLOCK(emblem_runtime_back_list, s_emblem_library::k_max_back_emblem_count)
{
	{ _field_string_id, "name" },
	{ _field_short_integer, "bitmap0_index" },
	{ _field_enum, "bitmap0_address_x" },
	{ _field_enum, "bitmap0_address_y" },
	{ _field_short_integer, "bitmap1_index" },
	{ _field_enum, "bitmap1_address_x" },
	{ _field_enum, "bitmap1_address_y" },
	{ _field_real_quaternion, "bitmap_transform0" },
	{ _field_real_quaternion, "bitmap_transform1" },
	{ _field_real_quaternion, "bitmap_transform2" },
	{ _field_real_quaternion, "bitmap_transform3" },
	{ _field_real_quaternion, "bitmap_params0" },
	{ _field_real_quaternion, "bitmap_params1" },
	{ _field_terminator },
};

TAG_GROUP(emblem_library, EMBLEM_LIBRARY_TAG)
{
	{ _field_explanation, "Emblem Library" },
	{ _field_short_integer, "version!" },
	{ _field_pad, "jfejkjjg", 2 },
	{ _field_custom, "Bitmaps" },
	{ _field_explanation, "Bitmaps" },
	{ _field_real, "bitmap resolution:pixels#used to calculate appropriate antialiasing settings" },
	{ _field_real, "antialias sharpen#default 1.0, global control on antialias sharpness" },
	{ _field_tag_reference, "emblem bitmaps" },
	{ _field_tag_reference, "emblem bitmaps hi rez" },
	{ _field_block, "bitmaps", &emblem_bitmap_list_block },
	{ _field_custom },
	{ _field_explanation, "Shapes" },
	{ _field_block, "shapes", &emblem_shape_list_block },
	{ _field_explanation, "Emblems" },
	{ _field_block, "front emblems", &emblem_front_list_block },
	{ _field_block, "back emblems", &emblem_back_list_block },
	{ _field_block, "runtime front!", &emblem_runtime_front_list_block },
	{ _field_block, "runtime back!", &emblem_runtime_back_list_block },
	{ _field_terminator },
};

} // namespace blofeld

