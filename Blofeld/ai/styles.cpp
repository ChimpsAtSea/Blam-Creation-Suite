#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(style_palette, 50)
{
	{ _field_tag_reference, "reference^" },
	{ _field_terminator },
};

TAG_BLOCK(behavior_names, k_maximum_behavior_count)
{
	{ _field_string, "behavior name*^" },
	{ _field_terminator },
};

TAG_GROUP(style, STYLE_TAG)
{
	{ _field_string, "name^" },
	{ _field_explanation, "Combat status decay options" },
	{ _field_enum, "Combat status decay options" },
	{ _field_pad, "hghq", 2 },
	{ _field_explanation, "Style Behavior Control" },
	{ _field_long_flags, "Style control" },
	{ _field_long_flags, "Behaviors1" },
	{ _field_long_flags, "Behaviors2" },
	{ _field_long_flags, "Behaviors3" },
	{ _field_long_flags, "Behaviors4" },
	{ _field_long_flags, "Behaviors5" },
	{ _field_long_flags, "Behaviors6" },
	{ _field_long_flags, "Behaviors7" },
	{ _field_long_flags, "Behaviors8" },
	{ _field_block, "Special movement", &special_movement_block },
	{ _field_block, "Behavior list", &behavior_names_block },
	{ _field_terminator },
};

} // namespace blofeld

