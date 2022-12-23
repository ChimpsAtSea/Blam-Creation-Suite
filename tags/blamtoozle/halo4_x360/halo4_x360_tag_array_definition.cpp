#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo4_x360_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo4_x360_tag_array_definition& value)
{
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.element_count);
	byteswap_inplace(value.element_count_string);
	byteswap_inplace(value.structure_definition_address);
}

c_halo4_x360_tag_array_definition::c_halo4_x360_tag_array_definition(c_halo4_x360_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_array_definition(_tag_definition_manager),
	definition_address(_definition_address),
	array_definition(tag_definition_manager.read_structure<s_halo4_x360_tag_array_definition>(_definition_address)),
	struct_definition(tag_definition_manager.eval_struct(array_definition.structure_definition_address)),
	name(tag_definition_manager.va_to_pointer(array_definition.name_address)),
	element_count_string(tag_definition_manager.va_to_pointer(array_definition.element_count_string)),
	code_symbol_name(name)
{
	if (strcmp(code_symbol_name.c_str(), struct_definition.code_symbol_name.c_str()) == 0)
	{
		struct_definition.code_symbol_name += "_struct_definition";
	}

	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo4_x360_tag_array_definition::~c_halo4_x360_tag_array_definition()
{

}

const char* c_halo4_x360_tag_array_definition::get_name()
{
	return name;
}

const char* c_halo4_x360_tag_array_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

uint32_t c_halo4_x360_tag_array_definition::get_element_count()
{
	return array_definition.element_count;
}

const char* c_halo4_x360_tag_array_definition::get_element_count_string()
{
	return element_count_string;
}

c_blamtoozle_tag_struct_definition& c_halo4_x360_tag_array_definition::get_struct_definition()
{
	return struct_definition;
}
