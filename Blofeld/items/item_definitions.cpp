#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(predicted_bitmaps, 8)
{
	{ _field_tag_reference, "bitmap" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(item, ITEM_TAG, object, OBJECT_TAG)
{
	{ _field_struct, "object" },
	{ _field_custom, "$$$ ITEM $$$" },
	{ _field_long_flags, "flags" },
	{ _field_short_integer, "OLD message index" },
	{ _field_short_integer, "sort order" },
	{ _field_real, "OLD multiplayer on-ground scale" },
	{ _field_real, "OLD campaign on-ground scale" },
	{ _field_explanation, "NEW hud messages" },
	{ _field_string_id, "pickup message" },
	{ _field_string_id, "swap message" },
	{ _field_string_id, "pickup message (dual)" },
	{ _field_string_id, "swap message (dual)" },
	{ _field_string_id, "picked up msg" },
	{ _field_string_id, "switch-to msg" },
	{ _field_string_id, "switch-to from ai msg" },
	{ _field_string_id, "notify empty msg" },
	{ _field_string_id, "notify overheated message" },
	{ _field_tag_reference, "collision sound" },
	{ _field_block, "predicted bitmaps", &predicted_bitmaps_block },
	{ _field_tag_reference, "detonation damage effect" },
	{ _field_real_bounds, "detonation delay:seconds" },
	{ _field_tag_reference, "detonating effect" },
	{ _field_tag_reference, "detonation effect" },
	{ _field_explanation, "Item scale settings" },
	{ _field_real, "ground scale" },
	{ _field_real, "small unit (armed)" },
	{ _field_real, "small unit (stowed)" },
	{ _field_real, "medium unit (armed)" },
	{ _field_real, "medium unit (stowed)" },
	{ _field_real, "large unit (armed)" },
	{ _field_real, "large unit (stowed)" },
	{ _field_real, "huge unit (armed)" },
	{ _field_real, "huge unit (stowed)" },
	{ _field_tag_reference, "grounded friction settings#If not present, the default from global.globals is used." },
	{ _field_tag_reference, "Tossed Override# Used to override the object tossed when item owner is killed.  Is overridden by tossed weapon override." },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

