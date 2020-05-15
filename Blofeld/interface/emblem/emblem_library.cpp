#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(emblem_bitmap_list, s_emblem_library::k_max_bitmap_list_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_short_integer, "bitmap index#the index of the bitmap in the bitmap group" ),
	FIELD( _field_pad, "ASDFJIJJGHJFL", 2 ),
	FIELD( _field_real, "gradient size:pixels#the size of the gradient (from white to black) in this bitmap" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(emblem_shape_list, s_emblem_library::k_max_shape_list_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_short_block_index, "bitmap" ),
	FIELD( _field_enum, "address mode x" ),
	FIELD( _field_enum, "address mode y" ),
	FIELD( _field_pad, "FGKKGKHL", 2 ),
	FIELD( _field_struct, "transform" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(emblem_front_list, s_emblem_library::k_max_front_emblem_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_explanation, "Layer 0 (foreground)" ),
	FIELD( _field_struct, "layer 0" ),
	FIELD( _field_explanation, "Layer 1 (midground)" ),
	FIELD( _field_struct, "layer 1" ),
	FIELD( _field_explanation, "Misc" ),
	FIELD( _field_char_enum, "primary layer#layer that is considered \"primary\" and which will use the primary color" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_pad, "pad1", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(emblem_back_list, s_emblem_library::k_max_back_emblem_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_explanation, "Layer 2 (background)" ),
	FIELD( _field_struct, "layer 2" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(emblem_runtime_front_list, s_emblem_library::k_max_front_emblem_count)
{
	FIELD( _field_string_id, "name0" ),
	FIELD( _field_short_integer, "bitmap0_index" ),
	FIELD( _field_enum, "bitmap0_address_x" ),
	FIELD( _field_enum, "bitmap0_address_y" ),
	FIELD( _field_short_integer, "bitmap1_index" ),
	FIELD( _field_enum, "bitmap1_address_x" ),
	FIELD( _field_enum, "bitmap1_address_y" ),
	FIELD( _field_real_quaternion, "bitmap_transform0" ),
	FIELD( _field_real_quaternion, "bitmap_transform1" ),
	FIELD( _field_real_quaternion, "bitmap_transform2" ),
	FIELD( _field_real_quaternion, "bitmap_transform3" ),
	FIELD( _field_real_quaternion, "bitmap_params0" ),
	FIELD( _field_real_quaternion, "bitmap_params1" ),
	FIELD( _field_string_id, "name1" ),
	FIELD( _field_short_integer, "bitmap2_index" ),
	FIELD( _field_enum, "bitmap2_address_x" ),
	FIELD( _field_enum, "bitmap2_address_y" ),
	FIELD( _field_short_integer, "bitmap3_index" ),
	FIELD( _field_enum, "bitmap3_address_x" ),
	FIELD( _field_enum, "bitmap3_address_y" ),
	FIELD( _field_real_quaternion, "bitmap_transform4" ),
	FIELD( _field_real_quaternion, "bitmap_transform5" ),
	FIELD( _field_real_quaternion, "bitmap_transform6" ),
	FIELD( _field_real_quaternion, "bitmap_transform7" ),
	FIELD( _field_real_quaternion, "bitmap_params2" ),
	FIELD( _field_real_quaternion, "bitmap_params3" ),
	FIELD( _field_char_enum, "primary layer" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_pad, "pad1", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(emblem_runtime_back_list, s_emblem_library::k_max_back_emblem_count)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_short_integer, "bitmap0_index" ),
	FIELD( _field_enum, "bitmap0_address_x" ),
	FIELD( _field_enum, "bitmap0_address_y" ),
	FIELD( _field_short_integer, "bitmap1_index" ),
	FIELD( _field_enum, "bitmap1_address_x" ),
	FIELD( _field_enum, "bitmap1_address_y" ),
	FIELD( _field_real_quaternion, "bitmap_transform0" ),
	FIELD( _field_real_quaternion, "bitmap_transform1" ),
	FIELD( _field_real_quaternion, "bitmap_transform2" ),
	FIELD( _field_real_quaternion, "bitmap_transform3" ),
	FIELD( _field_real_quaternion, "bitmap_params0" ),
	FIELD( _field_real_quaternion, "bitmap_params1" ),
	FIELD( _field_terminator )
};

TAG_GROUP(emblem_library, EMBLEM_LIBRARY_TAG)
{
	FIELD( _field_explanation, "Emblem Library" ),
	FIELD( _field_short_integer, "version!" ),
	FIELD( _field_pad, "jfejkjjg", 2 ),
	FIELD( _field_custom, "Bitmaps" ),
	FIELD( _field_explanation, "Bitmaps" ),
	FIELD( _field_real, "bitmap resolution:pixels#used to calculate appropriate antialiasing settings" ),
	FIELD( _field_real, "antialias sharpen#default 1.0, global control on antialias sharpness" ),
	FIELD( _field_tag_reference, "emblem bitmaps" ),
	FIELD( _field_tag_reference, "emblem bitmaps hi rez" ),
	FIELD( _field_block, "bitmaps", &emblem_bitmap_list_block ),
	FIELD( _field_custom ),
	FIELD( _field_explanation, "Shapes" ),
	FIELD( _field_block, "shapes", &emblem_shape_list_block ),
	FIELD( _field_explanation, "Emblems" ),
	FIELD( _field_block, "front emblems", &emblem_front_list_block ),
	FIELD( _field_block, "back emblems", &emblem_back_list_block ),
	FIELD( _field_block, "runtime front!", &emblem_runtime_front_list_block ),
	FIELD( _field_block, "runtime back!", &emblem_runtime_back_list_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

