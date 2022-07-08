#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_reach_x360_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_reach_x360_tag_block_definition& value)
{
	byteswap_inplace(value.display_name_address);
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.max_count);
	byteswap_inplace(value.max_count_string_address);
	byteswap_inplace(value.structure_definition_address);
}

c_reach_x360_tag_block_definition::c_reach_x360_tag_block_definition(c_reach_x360_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_block_definition(_tag_definition_manager),
	definition_address(_definition_address),
	block_definition(tag_definition_manager.read_structure<s_reach_x360_tag_block_definition>(_definition_address)),
	struct_definition(tag_definition_manager.eval_struct(block_definition.structure_definition_address)),
	display_name(tag_definition_manager.va_to_pointer(block_definition.display_name_address)),
	name(tag_definition_manager.va_to_pointer(block_definition.name_address)),
	code_symbol_name(),
	max_count_string(tag_definition_manager.va_to_pointer(block_definition.max_count_string_address))
{
	make_code_symbol_name();
}

c_reach_x360_tag_block_definition::~c_reach_x360_tag_block_definition()
{

}

const char* c_reach_x360_tag_block_definition::get_display_name()
{
	return display_name;
}

const char* c_reach_x360_tag_block_definition::get_name()
{
	return name;
}

const char* c_reach_x360_tag_block_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

unsigned long c_reach_x360_tag_block_definition::get_max_count()
{
	return block_definition.max_count;
}

const char* c_reach_x360_tag_block_definition::get_max_count_string()
{
	return max_count_string;
}

c_blamtoozle_tag_struct_definition& c_reach_x360_tag_block_definition::get_struct_definition()
{
	return struct_definition;
}

void c_reach_x360_tag_block_definition::associate_tag_group_definition(c_blamtoozle_tag_group_definition* tag_group_definition)
{
	c_blamtoozle_tag_block_definition::associate_tag_group_definition(tag_group_definition);
	make_code_symbol_name();
}

void c_reach_x360_tag_block_definition::make_code_symbol_name()
{
	code_symbol_name = name;

	if (tag_group_definition != nullptr)
	{
		code_symbol_name += "_group_block";
	}
	else
	{
		// #TODO: should this check if the string already ends with _block ?
		code_symbol_name += "_block";
	}

	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}
