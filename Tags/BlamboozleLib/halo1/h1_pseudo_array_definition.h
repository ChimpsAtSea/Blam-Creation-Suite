#pragma once

class c_h1_pseudo_struct_definition;
class c_h1_tag_block_definition;
struct s_h1_tag_field;

class c_h1_pseudo_array_definition
{
public:
	std::string name;
	std::string code_name;

	c_h1_pseudo_struct_definition* pseudo_struct_definition;
	c_h1_tag_block_definition& block_definition;
	unsigned long count;

	c_h1_pseudo_array_definition(const char* guerilla_data, const s_h1_tag_field* fields_begin, c_h1_tag_block_definition& block_definition);
};

