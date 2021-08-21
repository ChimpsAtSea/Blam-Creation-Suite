#include "blamboozlelib-private-pch.h"

c_h2_pseudo_array_definition::c_h2_pseudo_array_definition(
	const char* guerilla_data, 
	const s_h2_tag_field* fields_begin, 
	c_h2_pseudo_struct_definition& parent_pseudo_struct_definition) :
	name(),
	code_name(),
	array_pseudo_struct_definition(nullptr),
	parent_pseudo_struct_definition(parent_pseudo_struct_definition),
	count(fields_begin->definition_address.value())
{
	ASSERT(fields_begin->field_type == _h2_field_type_array_start);
	ASSERT(count > 0);

	name = parent_pseudo_struct_definition.name;
	if (fields_begin->name_address)
	{
		name += " | ";
		name += h2_va_to_pointer_with_external_string(guerilla_data, fields_begin->name_address);
	}
	name += " array";

	code_name = parent_pseudo_struct_definition.code_name;
	if (fields_begin->name_address)
	{
		code_name += "__";
		code_name += h2_convert_to_code_name(h2_va_to_pointer_with_external_string(guerilla_data, fields_begin->name_address));
	}
	code_name += "_array";

	array_pseudo_struct_definition = new c_h2_pseudo_struct_definition(guerilla_data, fields_begin + 1, *this);
	array_pseudo_struct_definition->pseudo_array_definition = this;

	ASSERT(array_pseudo_struct_definition->fields_end->field_type == _h2_field_type_array_end);
}
