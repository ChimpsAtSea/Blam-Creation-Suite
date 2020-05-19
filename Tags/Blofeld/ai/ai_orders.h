#pragma once

namespace blofeld
{

	extern s_tag_struct_definition trigger_references_block_struct;
	extern s_tag_block_definition trigger_references_block;
	extern s_tag_struct_definition secondary_set_trigger_block_block_struct;
	extern s_tag_block_definition secondary_set_trigger_block_block;
	extern s_tag_struct_definition order_ending_block_block_struct;
	extern s_tag_block_definition order_ending_block_block;
	extern s_tag_struct_definition orders_block_block_struct;
	extern s_tag_block_definition orders_block_block;
	extern s_tag_struct_definition order_completion_condition_block_struct;
	extern s_tag_block_definition order_completion_condition_block;
	extern s_tag_struct_definition triggers_block_block_struct;
	extern s_tag_block_definition triggers_block_block;


	extern const char* condition_type_enum_strings[];
	extern s_string_list_definition condition_type_enum;
	extern const char* completion_condition_flags_strings[];
	extern s_string_list_definition completion_condition_flags;
	extern const char* combination_rules_enum_strings[];
	extern s_string_list_definition combination_rules_enum;
	extern const char* trigger_flags_strings[];
	extern s_string_list_definition trigger_flags;
	extern const char* trigger_ref_flags_strings[];
	extern s_string_list_definition trigger_ref_flags;
	extern const char* order_ending_dialogue_enum_strings[];
	extern s_string_list_definition order_ending_dialogue_enum;
	extern const char* order_flags_strings[];
	extern s_string_list_definition order_flags;
	extern const char* force_combat_status_enum_strings[];
	extern s_string_list_definition force_combat_status_enum;

} // namespace blofeld

