#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo2_tools_pc32_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo2_tools_pc32_tag_data_definition& value)
{
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.flags);
	byteswap_inplace(value.alignment_bit);
	byteswap_inplace(value.maximum_element_count);
	byteswap_inplace(value.maximum_element_count_string_address);
	byteswap_inplace(value.unknown_procedure0);
	byteswap_inplace(value.unknown_procedure1);
	byteswap_inplace(value.unknown_procedure2);
	byteswap_inplace(value.unknown_procedure3);
	byteswap_inplace(value.unknown_procedure4);
	byteswap_inplace(value.unknown_procedure5);
}

c_halo2_tools_pc32_tag_data_definition::c_halo2_tools_pc32_tag_data_definition(c_halo2_tools_pc32_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_data_definition(_tag_definition_manager),
	definition_address(_definition_address),
	data_definition(tag_definition_manager.read_structure<s_halo2_tools_pc32_tag_data_definition>(_definition_address)),
	name(tag_definition_manager.va_to_pointer(data_definition.name_address)),
	code_symbol_name(name),
	maximum_element_count_string(tag_definition_manager.va_to_pointer(data_definition.maximum_element_count_string_address))
{
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo2_tools_pc32_tag_data_definition::~c_halo2_tools_pc32_tag_data_definition()
{

}

const char* c_halo2_tools_pc32_tag_data_definition::get_name()
{
	return name;
}

const char* c_halo2_tools_pc32_tag_data_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

unsigned long c_halo2_tools_pc32_tag_data_definition::get_flags()
{
	return data_definition.flags;
}

unsigned long c_halo2_tools_pc32_tag_data_definition::get_alignment_bits()
{
	return data_definition.alignment_bit;
}

unsigned long c_halo2_tools_pc32_tag_data_definition::get_maximum_element_count()
{
	return data_definition.maximum_element_count;
}

const char* c_halo2_tools_pc32_tag_data_definition::get_maximum_element_count_string()
{
	return maximum_element_count_string;
}
