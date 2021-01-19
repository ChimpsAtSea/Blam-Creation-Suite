#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(trigger_references, 10)
	{
		{ _field_long_flags, "Trigger flags", &trigger_ref_flags },
		{ _field_short_block_index, "trigger^" },
		{ _field_pad, "LPQYXEA", 2 },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(secondary_set_trigger_block, 1)
	{
		{ _field_enum, "combination rule", &combination_rules_enum },
		{ _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type", &order_ending_dialogue_enum },
		{ _field_block, "triggers", &trigger_references_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(order_ending_block, 12)
	{
		{ _field_short_block_index, "next order^" },
		{ _field_enum, "combination rule", &combination_rules_enum },
		{ _field_real, "delay time" },
		{ _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type", &order_ending_dialogue_enum },
		{ _field_pad, "YVKPCQIYY", 2 },
		{ _field_useless_pad },
		{ _field_block, "triggers", &trigger_references_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(orders_block, 300)
	{
		{ _field_custom },
		{ _field_string, "name^" },
		{ _field_short_block_index, "Style" },
		{ _field_pad, "YATIWNRNR", 2 },
		{ _field_long_flags, "flags", &order_flags },
		{ _field_enum, "Force combat status", &force_combat_status_enum },
		{ _field_pad, "PWY", 2 },
		{ _field_string, "Entry Script" },
		{ _field_short_integer, "Script index*!" },
		{ _field_short_block_index, "Follow squad" },
		{ _field_real, "follow radius" },
		{ _field_block, "Primary area set", &area_reference_block_block },
		{ _field_block, "Secondary area set", &area_reference_block_block },
		{ _field_block, "Secondary set trigger", &secondary_set_trigger_block_block },
		{ _field_block, "Special movement", &special_movement_block_block },
		{ _field_useless_pad },
		{ _field_block, "Order endings", &order_ending_block_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(order_completion_condition, 5)
	{
		{ _field_enum, "rule type^", &condition_type_enum },
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
		{ _field_long_flags, "flags", &completion_condition_flags },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(triggers_block, 256)
	{
		{ _field_custom },
		{ _field_string, "name^" },
		{ _field_long_flags, "trigger flags", &trigger_flags },
		{ _field_enum, "combination rule", &combination_rules_enum },
		{ _field_pad, "XXCMMRUP", 2 },
		{ _field_useless_pad },
		{ _field_block, "conditions", &order_completion_condition_block },
		{ _field_terminator }
	};

	STRINGS(condition_type_enum)
	{
		"A or greater alive",
		"A or fewer alive",
		"X or greater strength",
		"X or less strength",
		"If enemy sighted",
		"After A ticks",
		"If alerted by squad A",
		"Script ref TRUE",
		"Script ref FALSE",
		"If player in trigger volume",
		"If ALL players in trigger volume",
		"Combat status A or more",
		"Combat status A or less",
		"Arrived",
		"In vehicle",
		"Sighted player",
		"A or greater fighting",
		"A or fewer fighting",
		"Player within X world units",
		"Player shot more than X seconds ago",
		"Game safe to save"
	};
	STRING_LIST(condition_type_enum, condition_type_enum_strings, _countof(condition_type_enum_strings));

	STRINGS(completion_condition_flags)
	{
		"NOT!"
	};
	STRING_LIST(completion_condition_flags, completion_condition_flags_strings, _countof(completion_condition_flags_strings));

	STRINGS(combination_rules_enum)
	{
		"OR",
		"AND"
	};
	STRING_LIST(combination_rules_enum, combination_rules_enum_strings, _countof(combination_rules_enum_strings));

	STRINGS(trigger_flags)
	{
		"Latch ON when triggered"
	};
	STRING_LIST(trigger_flags, trigger_flags_strings, _countof(trigger_flags_strings));

	STRINGS(trigger_ref_flags)
	{
		"not"
	};
	STRING_LIST(trigger_ref_flags, trigger_ref_flags_strings, _countof(trigger_ref_flags_strings));

	STRINGS(order_ending_dialogue_enum)
	{
		"none",
		"enemy is advancing",
		"enemy is charging",
		"enemy is falling back",
		"advance",
		"charge",
		"fall_back",
		"move on{moveone}",
		"follow_player",
		"arriving into combat",
		"end combat",
		"investigate",
		"spread out",
		"hold position{hold}",
		"find cover",
		"covering fire"
	};
	STRING_LIST(order_ending_dialogue_enum, order_ending_dialogue_enum_strings, _countof(order_ending_dialogue_enum_strings));

	STRINGS(order_flags)
	{
		"locked",
		"always active",
		"debug on",
		"strict area def",
		"follow closest player",
		"follow squad",
		"suppress active camo",
		"suppress combat until engaged",
		"inhibit vehicle use"
	};
	STRING_LIST(order_flags, order_flags_strings, _countof(order_flags_strings));

	STRINGS(force_combat_status_enum)
	{
		"NONE",
		"Idle",
		"Alert",
		"Combat"
	};
	STRING_LIST(force_combat_status_enum, force_combat_status_enum_strings, _countof(force_combat_status_enum_strings));

} // namespace blofeld

