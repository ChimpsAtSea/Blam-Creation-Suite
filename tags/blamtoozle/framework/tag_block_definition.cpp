#include "blamtoozle-private-pch.h"

c_blamtoozle_tag_block_definition::c_blamtoozle_tag_block_definition(
	c_blamtoozle_tag_definition_manager& _tag_definition_manager) :
	tag_definition_manager(_tag_definition_manager),
	tag_group_definition()
{

}

c_blamtoozle_tag_block_definition::~c_blamtoozle_tag_block_definition()
{

}

void c_blamtoozle_tag_block_definition::associate_tag_group_definition(c_blamtoozle_tag_group_definition* _tag_group_definition)
{
	tag_group_definition = _tag_group_definition;
}

c_blamtoozle_tag_group_definition* c_blamtoozle_tag_block_definition::get_tag_group_definition()
{
	return tag_group_definition;
}
