#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo1_tools_pc32_tag_definition_manager&>(tag_definition_manager)

c_halo1_tools_pc32_tag_array_definition::c_halo1_tools_pc32_tag_array_definition(c_halo1_tools_pc32_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_array_definition(_tag_definition_manager),
	definition_address(_definition_address),
	field_definition(tag_definition_manager.read_structure<s_halo1_tools_pc32_tag_field>(_definition_address)),
	struct_definition(tag_definition_manager.eval_array_struct(_definition_address + sizeof(s_halo1_tools_pc32_tag_field))),
	name("unnamed_array"),
	element_count_string("unnamed_array"),
	code_symbol_name(name)
{
	ASSERT(field_definition.field_type == _halo1_tools_pc32_field_array_start);

	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo1_tools_pc32_tag_array_definition::~c_halo1_tools_pc32_tag_array_definition()
{

}

const char* c_halo1_tools_pc32_tag_array_definition::get_name()
{
	return name;
}

const char* c_halo1_tools_pc32_tag_array_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

unsigned long c_halo1_tools_pc32_tag_array_definition::get_element_count()
{
	return field_definition.definition_address;
}

const char* c_halo1_tools_pc32_tag_array_definition::get_element_count_string()
{
	return element_count_string;
}

c_blamtoozle_tag_struct_definition& c_halo1_tools_pc32_tag_array_definition::get_struct_definition()
{
	return struct_definition;
}
