#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo4_x360_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo4_x360_tag_resource_definition& value)
{
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.unknown8);
	byteswap_inplace(value.structure_definition_address);
	byteswap_inplace(value.tag_resource_vtable);
	byteswap_inplace(value.unknown20);
	byteswap_inplace(value.file_path);
	byteswap_inplace(value.line_number);
	byteswap_inplace(value.unknown30);
}

c_halo4_x360_tag_resource_definition::c_halo4_x360_tag_resource_definition(c_halo4_x360_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_resource_definition(_tag_definition_manager),
	definition_address(_definition_address),
	resource_definition(tag_definition_manager.read_structure<s_halo4_x360_tag_resource_definition>(_definition_address)),
	struct_definition(tag_definition_manager.eval_struct(resource_definition.structure_definition_address)),
	name(tag_definition_manager.va_to_pointer(resource_definition.name_address)),
	code_symbol_name(name)
{
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo4_x360_tag_resource_definition::~c_halo4_x360_tag_resource_definition()
{

}

const char* c_halo4_x360_tag_resource_definition::get_name()
{
	return name;
}

const char* c_halo4_x360_tag_resource_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

c_blamtoozle_tag_struct_definition& c_halo4_x360_tag_resource_definition::get_struct_definition()
{
	return struct_definition;
}
