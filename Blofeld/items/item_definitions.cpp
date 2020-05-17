#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_INHERIT_FROM_BLOCK(item, ITEM_TAG, object, OBJECT_TAG, item_block_block );

	TAG_BLOCK(predicted_bitmaps_block, 8)
	{
		FIELD( _field_tag_reference, "bitmap" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(item_block, 1, item_struct_definition_struct_definition );

	TAG_STRUCT(item_struct_definition)
	{
		FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
		FIELD( _field_custom, "$$$ ITEM $$$" ),
		FIELD( _field_long_flags, "flags", &item_definition_flags ),
		FIELD( _field_short_integer, "OLD message index" ),
		FIELD( _field_short_integer, "sort order" ),
		FIELD( _field_real, "OLD multiplayer on-ground scale" ),
		FIELD( _field_real, "OLD campaign on-ground scale" ),
		FIELD( _field_explanation, "NEW hud messages" ),
		FIELD( _field_string_id, "pickup message" ),
		FIELD( _field_string_id, "swap message" ),
		FIELD( _field_string_id, "pickup message (dual)" ),
		FIELD( _field_string_id, "swap message (dual)" ),
		FIELD( _field_string_id, "picked up msg" ),
		FIELD( _field_string_id, "switch-to msg" ),
		FIELD( _field_string_id, "switch-to from ai msg" ),
		FIELD( _field_string_id, "notify empty msg" ),
		FIELD( _field_string_id, "notify overheated message" ),
		FIELD( _field_tag_reference, "collision sound" ),
		FIELD( _field_block, "predicted bitmaps", &predicted_bitmaps_block_block ),
		FIELD( _field_tag_reference, "detonation damage effect" ),
		FIELD( _field_real_bounds, "detonation delay:seconds" ),
		FIELD( _field_tag_reference, "detonating effect" ),
		FIELD( _field_tag_reference, "detonation effect" ),
		FIELD( _field_explanation, "Item scale settings" ),
		FIELD( _field_real, "ground scale" ),
		FIELD( _field_real, "small unit (armed)" ),
		FIELD( _field_real, "small unit (stowed)" ),
		FIELD( _field_real, "medium unit (armed)" ),
		FIELD( _field_real, "medium unit (stowed)" ),
		FIELD( _field_real, "large unit (armed)" ),
		FIELD( _field_real, "large unit (stowed)" ),
		FIELD( _field_real, "huge unit (armed)" ),
		FIELD( _field_real, "huge unit (stowed)" ),
		FIELD( _field_tag_reference, "grounded friction settings#If not present, the default from global.globals is used." ),
		FIELD( _field_tag_reference, "Tossed Override# Used to override the object tossed when item owner is killed.  Is overridden by tossed weapon override." ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(item_definition_flags, 5)
	{
		OPTION("always maintains z up"),
		OPTION("blocks headshots#like jackal shield"),
		OPTION("use ground scale for all unspecified attachments"),
		OPTION("fixup position upon detaching from parent"),
		OPTION("fixup position after attaching to parent"),
	};

} // namespace blofeld

