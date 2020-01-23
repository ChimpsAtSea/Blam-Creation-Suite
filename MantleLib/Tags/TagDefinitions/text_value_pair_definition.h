#pragma once

struct nicename("Text Value Pair Definition") group('sily') s_text_value_pair_definition_definition
{
	struct nicename("Text Value Pairs") s_text_value_pair_block_definition;

	// comment
	int32_t nicename("Parameter") parameter; 
	string_id nicename("Name") name; 
	string_id nicename("Description") description; 
	s_tag_block_definition<s_text_value_pair_block_definition> nicename("Text Value Pairs") text_value_pairs_block; 

	struct nicename("text_value_pair") s_text_value_pair_block_definition
	{
		uint8_t nicename("Flags") flags; 
		int8_t nicename("Expected Value Type") expected_value_type; 
		int16_t __unknown; 
		int32_t nicename("Integer Value") integer_value; 
		string_id nicename("StringID Value") stringid_value; 
		string_id nicename("Name") name; 
		string_id nicename("Description") description; 
	};
};
