#pragma once

struct nicename("Text Value Pair Definition") group('sily') s_text_value_pair_definition_definition
{
	struct nicename("Text Value Pairs") s_text_value_pair_block_definition;

	// comment
	signed int nicename("Parameter") parameter; 
	string_id nicename("Name") name; 
	string_id nicename("Description") description; 
	s_tag_block_definition<s_text_value_pair_block_definition> nicename("Text Value Pairs") text_value_pairs_block; 

	struct nicename("text_value_pair") s_text_value_pair_block_definition
	{
		unsigned char nicename("Flags") flags; 
		signed char nicename("Expected Value Type") expected_value_type; 
		signed short __unknown; 
		signed int nicename("Integer Value") integer_value; 
		string_id nicename("StringID Value") stringid_value; 
		string_id nicename("Name") name; 
		string_id nicename("Description") description; 
	};
};
