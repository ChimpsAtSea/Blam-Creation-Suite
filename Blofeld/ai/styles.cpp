#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(style, STYLE_TAG, style_block_block );

TAG_BLOCK_FROM_STRUCT(style_block, 1, style_struct_definition_struct_definition );

TAG_BLOCK(style_palette_block, 50)
{
	FIELD( _field_tag_reference, "reference^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(behavior_names_block, k_maximum_behavior_count)
{
	FIELD( _field_string, "behavior name*^" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(style_struct_definition)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_explanation, "Combat status decay options" ),
	FIELD( _field_enum, "Combat status decay options" ),
	FIELD( _field_pad, "hghq", 2 ),
	FIELD( _field_explanation, "Style Behavior Control" ),
	FIELD( _field_long_flags, "Style control" ),
	FIELD( _field_long_flags, "Behaviors1" ),
	FIELD( _field_long_flags, "Behaviors2" ),
	FIELD( _field_long_flags, "Behaviors3" ),
	FIELD( _field_long_flags, "Behaviors4" ),
	FIELD( _field_long_flags, "Behaviors5" ),
	FIELD( _field_long_flags, "Behaviors6" ),
	FIELD( _field_long_flags, "Behaviors7" ),
	FIELD( _field_long_flags, "Behaviors8" ),
	FIELD( _field_block, "Special movement", &special_movement_block_block ),
	FIELD( _field_block, "Behavior list", &behavior_names_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

