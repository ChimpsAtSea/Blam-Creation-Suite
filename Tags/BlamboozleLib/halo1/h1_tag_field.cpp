#include "blamboozlelib-private-pch.h"

c_h1_tag_field::c_h1_tag_field(const char* guerilla_data, const s_h1_tag_field* field_definition) :
	name(h1_va_to_pointer(guerilla_data, field_definition->name_address)),
	definition(h1_va_to_pointer(guerilla_data, field_definition->definition_address)),
	field_type(field_definition->field_type),
	name_address(field_definition->name_address),
	definition_address(field_definition->definition_address)
{
	ASSERT(field_definition->_padding == 0);
}
