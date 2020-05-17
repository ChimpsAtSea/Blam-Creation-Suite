#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(trigger_references, 10)
	{
		FIELD( _field_long_flags, "Trigger flags", &trigger_ref_flags ),
		FIELD( _field_short_block_index, "trigger^" ),
		FIELD( _field_pad, "LPQYXEA", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(secondary_set_trigger_block, 1)
	{
		FIELD( _field_enum, "combination rule", &combination_rules_enum ),
		FIELD( _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type", &order_ending_dialogue_enum ),
		FIELD( _field_block, "triggers", &trigger_references_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(order_ending_block, 12)
	{
		FIELD( _field_short_block_index, "next order^" ),
		FIELD( _field_enum, "combination rule", &combination_rules_enum ),
		FIELD( _field_real, "delay time" ),
		FIELD( _field_enum, "dialogue type#when this ending is triggered, launch a dialogue event of the given type", &order_ending_dialogue_enum ),
		FIELD( _field_pad, "YVKPCQIYY", 2 ),
		FIELD( _field_useless_pad ),
		FIELD( _field_block, "triggers", &trigger_references_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(orders_block, 300)
	{
		FIELD( _field_custom ),
		FIELD( _field_string, "name^" ),
		FIELD( _field_short_block_index, "Style" ),
		FIELD( _field_pad, "YATIWNRNR", 2 ),
		FIELD( _field_long_flags, "flags", &order_flags ),
		FIELD( _field_enum, "Force combat status", &force_combat_status_enum ),
		FIELD( _field_pad, "PWY", 2 ),
		FIELD( _field_string, "Entry Script" ),
		FIELD( _field_short_integer, "Script index*!" ),
		FIELD( _field_short_block_index, "Follow squad" ),
		FIELD( _field_real, "follow radius" ),
		FIELD( _field_block, "Primary area set", &area_reference_block_block ),
		FIELD( _field_block, "Secondary area set", &area_reference_block_block ),
		FIELD( _field_block, "Secondary set trigger", &secondary_set_trigger_block_block ),
		FIELD( _field_block, "Special movement", &special_movement_block_block ),
		FIELD( _field_useless_pad ),
		FIELD( _field_block, "Order endings", &order_ending_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(order_completion_condition, 5)
	{
		FIELD( _field_enum, "rule type^", &condition_type_enum ),
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
		FIELD( _field_long_flags, "flags", &completion_condition_flags ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(triggers_block, 256)
	{
		FIELD( _field_custom ),
		FIELD( _field_string, "name^" ),
		FIELD( _field_long_flags, "trigger flags", &trigger_flags ),
		FIELD( _field_enum, "combination rule", &combination_rules_enum ),
		FIELD( _field_pad, "XXCMMRUP", 2 ),
		FIELD( _field_useless_pad ),
		FIELD( _field_block, "conditions", &order_completion_condition_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(condition_type_enum, 21)
	{
		OPTION("A or greater alive"),
		OPTION("A or fewer alive"),
		OPTION("X or greater strength"),
		OPTION("X or less strength"),
		OPTION("If enemy sighted"),
		OPTION("After A ticks"),
		OPTION("If alerted by squad A"),
		OPTION("Script ref TRUE"),
		OPTION("Script ref FALSE"),
		OPTION("If player in trigger volume"),
		OPTION("If ALL players in trigger volume"),
		OPTION("Combat status A or more"),
		OPTION("Combat status A or less"),
		OPTION("Arrived"),
		OPTION("In vehicle"),
		OPTION("Sighted player"),
		OPTION("A or greater fighting"),
		OPTION("A or fewer fighting"),
		OPTION("Player within X world units"),
		OPTION("Player shot more than X seconds ago"),
		OPTION("Game safe to save"),
	};

	TAG_ENUM(completion_condition_flags, 1)
	{
		OPTION("NOT!"),
	};

	TAG_ENUM(combination_rules_enum, 2)
	{
		OPTION("OR"),
		OPTION("AND"),
	};

	TAG_ENUM(trigger_flags, 1)
	{
		OPTION("Latch ON when triggered"),
	};

	TAG_ENUM(trigger_ref_flags, 1)
	{
		OPTION("not"),
	};

	TAG_ENUM(order_ending_dialogue_enum, 16)
	{
		OPTION("none"),
		OPTION("enemy is advancing"),
		OPTION("enemy is charging"),
		OPTION("enemy is falling back"),
		OPTION("advance"),
		OPTION("charge"),
		OPTION("fall_back"),
		OPTION("move on{moveone}"),
		OPTION("follow_player"),
		OPTION("arriving into combat"),
		OPTION("end combat"),
		OPTION("investigate"),
		OPTION("spread out"),
		OPTION("hold position{hold}"),
		OPTION("find cover"),
		OPTION("covering fire"),
	};

	TAG_ENUM(order_flags, 9)
	{
		OPTION("locked"),
		OPTION("always active"),
		OPTION("debug on"),
		OPTION("strict area def"),
		OPTION("follow closest player"),
		OPTION("follow squad"),
		OPTION("suppress active camo"),
		OPTION("suppress combat until engaged"),
		OPTION("inhibit vehicle use"),
	};

	TAG_ENUM(force_combat_status_enum, 4)
	{
		OPTION("NONE"),
		OPTION("Idle"),
		OPTION("Alert"),
		OPTION("Combat"),
	};

} // namespace blofeld

