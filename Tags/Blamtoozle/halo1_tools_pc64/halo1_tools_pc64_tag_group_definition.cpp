#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo1_tools_pc64_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo1_tools_pc64_tag_group_definition& value)
{
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.flags);
	byteswap_inplace(value.group_tag);
	byteswap_inplace(value.parent_group_tag);
	byteswap_inplace(value.version);
	byteswap_inplace(value.postprocess_procedure);
	byteswap_inplace(value.block_definition_address);
	byteswap_inplace(value.child_group_tags);
	byteswap_inplace(value.num_child_group_tags);
}

c_halo1_tools_pc64_tag_group_definition::c_halo1_tools_pc64_tag_group_definition(c_halo1_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_group_definition(_tag_definition_manager),
	definition_address(_definition_address),
	group_definition(tag_definition_manager.read_structure<s_halo1_tools_pc64_tag_group_definition>(_definition_address)),
	name(tag_definition_manager.va_to_pointer(group_definition.name_address)),
	code_symbol_name(name),
	group_tag_macro_name(name),
	tag_block_definition()
{
	code_symbol_name += "_group";
	group_tag_macro_name += "_TAG";

	for (char& c : group_tag_macro_name) c = toupper(c);

	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo1_tools_pc64_tag_group_definition::~c_halo1_tools_pc64_tag_group_definition()
{

}

void c_halo1_tools_pc64_tag_group_definition::traverse()
{
	tag_block_definition = &tag_definition_manager.eval_block(group_definition.block_definition_address);
	tag_block_definition->associate_tag_group_definition(this);

	if (strcmp(code_symbol_name.c_str(), tag_block_definition->struct_definition->code_symbol_name.c_str()) == 0)
	{
		tag_block_definition->struct_definition->code_symbol_name += "_struct_definition";
	}
}

const char* c_halo1_tools_pc64_tag_group_definition::get_name()
{
	return name;
}

const char* c_halo1_tools_pc64_tag_group_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

const char* c_halo1_tools_pc64_tag_group_definition::get_group_tag_macro_name()
{
	return group_tag_macro_name.c_str();
}

unsigned long c_halo1_tools_pc64_tag_group_definition::get_version()
{
	return group_definition.version;
}

tag c_halo1_tools_pc64_tag_group_definition::get_group_tag()
{
	return group_definition.group_tag;
}

tag c_halo1_tools_pc64_tag_group_definition::get_parent_group_tag()
{
	return group_definition.parent_group_tag;
}

c_blamtoozle_tag_block_definition& c_halo1_tools_pc64_tag_group_definition::get_block_definition()
{
	ASSERT(tag_block_definition != nullptr);
	return *tag_block_definition;
}
