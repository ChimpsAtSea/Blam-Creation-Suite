#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(trigger_references, 10)
{
	FIELD( _field_long_flags, "Trigger flags" ),
	FIELD( _field_short_block_index, "trigger^" ),
	FIELD( _field_pad, "LPQYXEA", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(orders_block, 300)
{
	FIELD( _field_custom ),
	FIELD( _field_string, "name^" ),
	FIELD( _field_short_block_index, "Style" ),
	FIELD( _field_pad, "YATIWNRNR", 2 ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_enum, "Force combat status" ),
	FIELD( _field_pad, "PWY", 2 ),
	FIELD( _field_string, "Entry Script" ),
	FIELD( _field_short_integer, "Script index*!" ),
	FIELD( _field_short_block_index, "Follow squad" ),
	FIELD( _field_real, "follow radius" ),
	FIELD( _field_block, "Primary area set", &area_reference_block ),
	FIELD( _field_block, "Secondary area set", &area_reference_block ),
	FIELD( _field_block, "Secondary set trigger", &secondary_set_trigger_block ),
	FIELD( _field_block, "Special movement", &special_movement_block ),
	FIELD( _field_useless_pad ),
	FIELD( _field_block, "Order endings", &order_ending_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(secondary_set_trigger_block, 1)
{
	FIELD( _field_enum, "combination rule" ),
	FIELD( _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type" ),
	FIELD( _field_block, "triggers", &trigger_references ),
	FIELD( _field_terminator )
};

TAG_BLOCK(order_ending_block, 12)
{
	FIELD( _field_short_block_index, "next order^" ),
	FIELD( _field_enum, "combination rule" ),
	FIELD( _field_real, "delay time" ),
	FIELD( _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type" ),
	FIELD( _field_pad, "YVKPCQIYY", 2 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_block, "triggers", &trigger_references ),
	FIELD( _field_terminator )
};

TAG_BLOCK(triggers_block, 256)
{
	FIELD( _field_custom ),
	FIELD( _field_string, "name^" ),
	FIELD( _field_long_flags, "trigger flags" ),
	FIELD( _field_enum, "combination rule" ),
	FIELD( _field_pad, "XXCMMRUP", 2 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_block, "conditions", &order_completion_condition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(order_completion_condition, 5)
{
	FIELD( _field_enum, "rule type^" ),
	FIELD( _field_short_block_index, "squad" ),
	FIELD( _field_short_block_index, "squad group" ),
	FIELD( _field_short_integer, "a" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_useless_pad ),
	FIELD( _field_real, "x" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_short_block_index, "trigger volume" ),
	FIELD( _field_pad, "VZNEYGLW", 2 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_string, "Exit condition script" ),
	FIELD( _field_short_integer, "script index!" ),
	FIELD( _field_pad, "LEV", 2 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

