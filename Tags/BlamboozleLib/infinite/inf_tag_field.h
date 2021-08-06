#pragma once

struct s_inf_tag_field
{
	ptr64 name_address;
	e_inf_field_type field_type;
	unsigned long meta;
	ptr64 definition_address;
};

class c_inf_tag_block_definition;
class c_inf_tag_reference_definition;
class c_inf_tag_array_definition;
class c_inf_tag_struct_definition;

class c_inf_tag_field
{
public:
	const char* name;
	const char* definition;
	const e_inf_field_type& field_type;
	const ptr64& name_address;
	const ptr64& definition_address;

	c_inf_tag_block_definition* block_definition;
	c_inf_tag_reference_definition* tag_reference_definition;
	c_inf_tag_struct_definition* struct_definition;
	c_inf_tag_array_definition* array_definition;
	c_inf_string_list_definition* string_list_definition;

	unsigned long long padding;
	unsigned long long skip_length;
	const char* explanation;

	c_inf_tag_field(const char* guerilla_data, const s_inf_tag_field& field_definition);
};
