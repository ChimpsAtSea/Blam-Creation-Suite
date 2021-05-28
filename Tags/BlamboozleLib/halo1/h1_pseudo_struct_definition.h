#pragma once

class c_h1_pseudo_field_definition;
class c_h1_pseudo_array_definition;

class c_h1_pseudo_struct_definition
{
public:

	std::string name;
	std::string code_name;
	std::vector<c_h1_pseudo_field_definition*> pseudo_fields;

	c_h1_tag_block_definition& block_definition;
	bool is_array;

	const s_h1_tag_field* fields_begin;
	const s_h1_tag_field* fields_end;

	c_h1_pseudo_array_definition* pseudo_array_definition;

	c_h1_pseudo_struct_definition(
		const char* guerilla_data, 
		const s_h1_tag_field* fields, 
		c_h1_tag_block_definition& block_definition,
		c_h1_pseudo_array_definition* pseudo_array_definition = nullptr);
};