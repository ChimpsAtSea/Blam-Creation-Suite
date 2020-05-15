#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(trigger_references, 10)
{
	{ _field_long_flags, "Trigger flags" },
	{ _field_short_block_index, "trigger^" },
	{ _field_pad, "LPQYXEA", 2 },
	{ _field_terminator },
};

TAG_BLOCK(orders, 300)
{
	{ _field_custom },
	{ _field_string, "name^" },
	{ _field_short_block_index, "Style" },
	{ _field_pad, "YATIWNRNR", 2 },
	{ _field_long_flags, "flags" },
	{ _field_enum, "Force combat status" },
	{ _field_pad, "PWY", 2 },
	{ _field_string, "Entry Script" },
	{ _field_short_integer, "Script index*!" },
	{ _field_short_block_index, "Follow squad" },
	{ _field_real, "follow radius" },
	{ _field_block, "Primary area set", &area_reference_block },
	{ _field_block, "Secondary area set", &area_reference_block },
	{ _field_block, "Secondary set trigger", &secondary_set_trigger_block },
	{ _field_block, "Special movement", &special_movement_block },
	{ _field_useless_pad },
	{ _field_block, "Order endings", &order_ending_block },
	{ _field_terminator },
};

TAG_BLOCK(secondary_set_trigger, 1)
{
	{ _field_enum, "combination rule" },
	{ _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type" },
	{ _field_block, "triggers", &trigger_references_block },
	{ _field_terminator },
};

TAG_BLOCK(order_ending, 12)
{
	{ _field_short_block_index, "next order^" },
	{ _field_enum, "combination rule" },
	{ _field_real, "delay time" },
	{ _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type" },
	{ _field_pad, "YVKPCQIYY", 2 },
	{ _field_useless_pad },
	{ _field_block, "triggers", &trigger_references_block },
	{ _field_terminator },
};

TAG_BLOCK(triggers, 256)
{
	{ _field_custom },
	{ _field_string, "name^" },
	{ _field_long_flags, "trigger flags" },
	{ _field_enum, "combination rule" },
	{ _field_pad, "XXCMMRUP", 2 },
	{ _field_useless_pad },
	{ _field_block, "conditions", &order_completion_condition_block },
	{ _field_terminator },
};

TAG_BLOCK(order_completion_condition, 5)
{
	{ _field_enum, "rule type^" },
	{ _field_short_block_index, "squad" },
	{ _field_short_block_index, "squad group" },
	{ _field_short_integer, "a" },
	{ _field_useless_pad },
	{ _field_useless_pad },
	{ _field_real, "x" },
	{ _field_useless_pad },
	{ _field_short_block_index, "trigger volume" },
	{ _field_pad, "VZNEYGLW", 2 },
	{ _field_useless_pad },
	{ _field_string, "Exit condition script" },
	{ _field_short_integer, "script index!" },
	{ _field_pad, "LEV", 2 },
	{ _field_useless_pad },
	{ _field_long_flags, "flags" },
	{ _field_terminator },
};

} // namespace blofeld

