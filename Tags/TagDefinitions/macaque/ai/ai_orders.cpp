#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define TRIGGER_REFERENCES_ID { 0xE6CF862C, 0xBF56407F, 0x9FB84441, 0x14EE598E }
	TAG_BLOCK(
		trigger_references_block,
		"trigger_references",
		10,
		"order_trigger_reference",
		TRIGGER_REFERENCES_ID)
	{
		{ _field_long_flags, "Trigger flags", &trigger_ref_flags },
		{ _field_short_block_index, "trigger^" },
		{ _field_pad, "LPQYXEA", 2 },
		{ _field_terminator }
	};

	#define ORDERS_BLOCK_ID { 0xAA153229, 0x3F434BB1, 0xA442B744, 0xB378C50A }
	TAG_BLOCK(
		orders_block,
		"orders_block",
		300,
		"orders_definition",
		ORDERS_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, _custom_field_filter),
		{ _field_string, "name^" },
		{ _field_short_block_index, "Style" },
		{ _field_pad, "YATIWNRNR", 2 },
		{ _field_long_flags, "flags", &order_flags },
		{ _field_enum, "Force combat status", &force_combat_status_enum },
		{ _field_pad, "PWY", 2 },
		{ _field_string, "Entry Script", nullptr, 'hsbl' },
		{ _field_short_integer, "Script index*!" },
		{ _field_short_block_index, "Follow squad" },
		{ _field_real, "follow radius" },
		{ _field_block, "Primary area set", &area_reference_block },
		{ _field_block, "Secondary area set", &area_reference_block },
		{ _field_block, "Secondary set trigger", &secondary_set_trigger_block },
		{ _field_block, "Special movement", &special_movement_block },
		{ _field_useless_pad },
		{ _field_block, "Order endings", &order_ending_block },
		{ _field_terminator }
	};

	#define SECONDARY_SET_TRIGGER_BLOCK_ID { 0xFE527898, 0x39E047EE, 0x8093F855, 0x07FC3092 }
	TAG_BLOCK(
		secondary_set_trigger_block,
		"secondary_set_trigger_block",
		1,
		"secondary_set_triggers",
		SECONDARY_SET_TRIGGER_BLOCK_ID)
	{
		{ _field_enum, "combination rule", &combination_rules_enum },
		{ _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type", &order_ending_dialogue_enum },
		{ _field_block, "triggers", &trigger_references_block },
		{ _field_terminator }
	};

	#define ORDER_ENDING_BLOCK_ID { 0xFB397E2B, 0xE8894CCB, 0x95BBC537, 0x06463876 }
	TAG_BLOCK(
		order_ending_block,
		"order_ending_block",
		12,
		"order_ending_definition",
		ORDER_ENDING_BLOCK_ID)
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

	#define TRIGGERS_BLOCK_ID { 0xBDCE0188, 0x8F4F4836, 0xB6CB517B, 0x781A6B59 }
	TAG_BLOCK(
		triggers_block,
		"triggers_block",
		256,
		"trigger_definition",
		TRIGGERS_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, _custom_field_filter),
		{ _field_string, "name^" },
		{ _field_long_flags, "trigger flags", &trigger_flags },
		{ _field_enum, "combination rule", &combination_rules_enum },
		{ _field_pad, "XXCMMRUP", 2 },
		{ _field_useless_pad },
		{ _field_block, "conditions", &order_completion_condition_block },
		{ _field_terminator }
	};

	#define ORDER_COMPLETION_CONDITION_ID { 0xF28511DE, 0xF3EF4ED6, 0xAA67399F, 0x165711C7 }
	TAG_BLOCK(
		order_completion_condition_block,
		"order_completion_condition",
		5,
		"s_trigger_condition",
		ORDER_COMPLETION_CONDITION_ID)
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
		{ _field_string, "Exit condition script", nullptr, 'hsbl' },
		{ _field_short_integer, "script index!" },
		{ _field_pad, "LEV", 2 },
		{ _field_useless_pad },
		{ _field_long_flags, "flags", &completion_condition_flags },
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

} // namespace macaque

} // namespace blofeld

