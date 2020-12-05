#include "tagreflection-private-pch.h"

c_high_level_tag::c_high_level_tag(const blofeld::s_tag_group& tag_group, const char* tag_name, uint32_t type_size) :
	c_high_level_type(tag_group.block_definition.struct_definition, type_size),
	tag_name(tag_name ? tag_name : ""),
	tag_group(tag_group)
{

}

c_high_level_tag::~c_high_level_tag()
{

}

c_high_level_type::c_high_level_type(const blofeld::s_tag_struct_definition& struct_definition, uint32_t type_size) :
	struct_definition(struct_definition),
	type_size(type_size)
{

}

c_high_level_type::~c_high_level_type()
{

}
