#pragma once

class c_h2_pseudo_struct_definition;
class c_h2_tag_block_definition;
struct s_h2_tag_field;

class c_h2_pseudo_array_definition
{
public:
	std::string name;
	std::string code_name;

	c_h2_pseudo_struct_definition* array_pseudo_struct_definition;
	c_h2_pseudo_struct_definition& parent_pseudo_struct_definition;
	unsigned long count;

	c_h2_pseudo_array_definition(
		const char* guerilla_data, 
		const s_h2_tag_field* fields_begin, 
		c_h2_pseudo_struct_definition& parent_pseudo_struct_definition);
};
