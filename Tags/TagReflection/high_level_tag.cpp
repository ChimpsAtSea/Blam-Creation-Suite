#include "tagreflection-private-pch.h"

c_high_level_tag::c_high_level_tag(
	blofeld::s_tag_struct_definition& struct_definition,
	const char* tag_name, 
	const blofeld::s_tag_group& tag_group) :
	c_high_level_type(struct_definition),
	tag_name(tag_name ? tag_name : ""),
	tag_group(tag_group)
{

}

c_high_level_type::c_high_level_type(blofeld::s_tag_struct_definition& struct_definition) :
	struct_definition(struct_definition)
{

}
