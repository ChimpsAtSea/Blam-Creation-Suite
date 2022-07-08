#include "blamtoozle-private-pch.h"

c_blamtoozle_tag_field::c_blamtoozle_tag_field(c_blamtoozle_tag_definition_manager& _tag_definition_manager) :
	t_virtual(),
	tag_definition_manager(_tag_definition_manager)
{

}

c_blamtoozle_tag_field::~c_blamtoozle_tag_field()
{

}

c_blamtoozle_tag_field_combined_fixup::c_blamtoozle_tag_field_combined_fixup(
	c_blamtoozle_tag_group_definition& _group_definition,
	unsigned long _count,
	e_blamtoozle_tag_field_combined_fixup_type _fixup_type) :
	t_virtual(),
	group_definition(_group_definition),
	count(_count),
	fixup_type(_fixup_type)
{

}
