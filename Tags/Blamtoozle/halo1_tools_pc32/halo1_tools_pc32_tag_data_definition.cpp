#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo1_tools_pc32_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo1_tools_pc32_tag_data_definition& value)
{
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.flags);
	byteswap_inplace(value.maximum_element_count);
	byteswap_inplace(value.unknown_procedure0);
}

c_halo1_tools_pc32_tag_data_definition::c_halo1_tools_pc32_tag_data_definition(c_halo1_tools_pc32_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_data_definition(_tag_definition_manager),
	definition_address(_definition_address),
	data_definition(tag_definition_manager.read_structure<s_halo1_tools_pc32_tag_data_definition>(_definition_address)),
	name(tag_definition_manager.va_to_pointer(data_definition.name_address)),
	code_symbol_name(name),
	maximum_element_count_string()
{
	ultoa(data_definition.maximum_element_count, maximum_element_count_string, 10);
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo1_tools_pc32_tag_data_definition::~c_halo1_tools_pc32_tag_data_definition()
{

}

const char* c_halo1_tools_pc32_tag_data_definition::get_name()
{
	return name;
}

const char* c_halo1_tools_pc32_tag_data_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

unsigned long c_halo1_tools_pc32_tag_data_definition::get_flags()
{
	return data_definition.flags;
}

unsigned long c_halo1_tools_pc32_tag_data_definition::get_alignment_bits()
{
	return 0;
}

unsigned long c_halo1_tools_pc32_tag_data_definition::get_maximum_element_count()
{
	return data_definition.maximum_element_count;
}

const char* c_halo1_tools_pc32_tag_data_definition::get_maximum_element_count_string()
{
	return maximum_element_count_string;
}
