#pragma once

class c_h1_tag_group_definition;
class c_h1_pseudo_array_definition;
class c_h1_tag_reference_definition;
class c_h1_string_list_definition;

class c_h1_pseudo_field_definition
{
public:
	const char* name;
	e_h1_pseudo_field_type field_type;
	const s_h1_tag_field* field;

	c_h1_tag_block_definition* block_definition;
	c_h1_tag_reference_definition* tag_reference_definition;
	c_h1_pseudo_struct_definition* struct_definition;
	c_h1_pseudo_array_definition* pseudo_array_definition;
	c_h1_string_list_definition* string_list_definition;
	
	unsigned long long padding;
	unsigned long long skip_length;
	const char* explanation;

	c_h1_pseudo_field_definition(const char* guerilla_data, const s_h1_tag_field& field);
	c_h1_pseudo_field_definition(c_h1_tag_group_definition& tag_group_definition);
	
};
