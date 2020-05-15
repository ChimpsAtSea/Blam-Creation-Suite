#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(style_palette, 50)
{
	FIELD( _field_tag_reference, "reference^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(behavior_names, k_maximum_behavior_count)
{
	FIELD( _field_string, "behavior name*^" ),
	FIELD( _field_terminator )
};

TAG_GROUP(style, STYLE_TAG)
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
	FIELD( _field_block, "Special movement", &special_movement_block ),
	FIELD( _field_block, "Behavior list", &behavior_names_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

