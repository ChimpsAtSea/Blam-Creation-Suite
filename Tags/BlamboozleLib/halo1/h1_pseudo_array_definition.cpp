#include "blamboozlelib-private-pch.h"

c_h1_pseudo_array_definition::c_h1_pseudo_array_definition(const char* guerilla_data, const s_h1_tag_field* fields_begin, c_h1_tag_block_definition& block_definition) :
	name(),
	code_name(),
	pseudo_struct_definition(nullptr),
	block_definition(block_definition),
	count(fields_begin->definition_address)
{
	ASSERT(fields_begin->field_type == _h1_field_type_array_start);
	ASSERT(count > 0);

	name = block_definition.name;
	if (fields_begin->name_address)
	{
		name += " | ";
		name += va_to_pointer(guerilla_data, fields_begin->name_address);
	}
	name += " array";

	code_name = block_definition.code_name;
	if (fields_begin->name_address)
	{
		code_name += "__";
		code_name += h1_convert_to_code_name(va_to_pointer(guerilla_data, fields_begin->name_address));
	}
	code_name += "_array";

	pseudo_struct_definition = new c_h1_pseudo_struct_definition(guerilla_data, fields_begin + 1, block_definition, this);
	pseudo_struct_definition->pseudo_array_definition = this;

	ASSERT(pseudo_struct_definition->fields_end->field_type == _h1_field_type_array_end);
}
