#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo2_tools_pc32_tag_definition_manager&>(tag_definition_manager)

c_halo2_tools_pc32_tag_array_definition::c_halo2_tools_pc32_tag_array_definition(c_halo2_tools_pc32_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_array_definition(_tag_definition_manager),
	definition_address(_definition_address),
	field_definition(tag_definition_manager.read_structure<s_halo2_tools_pc32_tag_field>(_definition_address)),
	struct_definition(tag_definition_manager.eval_array_struct(_definition_address + sizeof(s_halo2_tools_pc32_tag_field))),
	//name(tag_definition_manager.va_to_pointer(array_definition.name_address)),
	//element_count_string(tag_definition_manager.va_to_pointer(array_definition.element_count_string)),
	name("todo"),
	element_count_string("todo"),
	code_symbol_name(name)
{
	ASSERT(field_definition.field_type == _halo2_tools_pc32_field_array_start);

	//if (strcmp(code_symbol_name.c_str(), struct_definition.code_symbol_name.c_str()) == 0)
	//{
	//	struct_definition.code_symbol_name += "_struct_definition";
	//}

	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo2_tools_pc32_tag_array_definition::~c_halo2_tools_pc32_tag_array_definition()
{

}

const char* c_halo2_tools_pc32_tag_array_definition::get_name()
{
	return name;
}

const char* c_halo2_tools_pc32_tag_array_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

unsigned long c_halo2_tools_pc32_tag_array_definition::get_element_count()
{
	return field_definition.definition_address;
}

const char* c_halo2_tools_pc32_tag_array_definition::get_element_count_string()
{
	return element_count_string;
}

c_blamtoozle_tag_struct_definition& c_halo2_tools_pc32_tag_array_definition::get_struct_definition()
{
	return struct_definition;
}
