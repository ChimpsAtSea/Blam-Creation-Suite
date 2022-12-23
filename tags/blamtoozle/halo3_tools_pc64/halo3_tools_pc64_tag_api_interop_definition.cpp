#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo3_tools_pc64_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo3_tools_pc64_tag_api_interop_definition& value)
{
	byteswap_inplace(value.persistent_identifier);
	byteswap_inplace(value.structure_definition_address);
	byteswap_inplace(value.vtable_address);
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.unknown);
}

c_halo3_tools_pc64_tag_api_interop_definition::c_halo3_tools_pc64_tag_api_interop_definition(c_halo3_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr64 _definition_address) :
	c_blamtoozle_tag_api_interop_definition(_tag_definition_manager),
	definition_address(_definition_address),
	interop_definition(tag_definition_manager.read_structure<s_halo3_tools_pc64_tag_api_interop_definition>(_definition_address)),
	struct_definition(tag_definition_manager.eval_struct(interop_definition.structure_definition_address)),
	name(tag_definition_manager.va_to_pointer(interop_definition.name_address)),
	code_symbol_name(name)
{
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo3_tools_pc64_tag_api_interop_definition::~c_halo3_tools_pc64_tag_api_interop_definition()
{

}

const char* c_halo3_tools_pc64_tag_api_interop_definition::get_name()
{
	return name;
}

const char* c_halo3_tools_pc64_tag_api_interop_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

const blofeld::s_tag_persistent_identifier& c_halo3_tools_pc64_tag_api_interop_definition::get_persistent_identifier()
{
	return interop_definition.persistent_identifier;
}

c_blamtoozle_tag_struct_definition& c_halo3_tools_pc64_tag_api_interop_definition::get_struct_definition()
{
	return struct_definition;
}
