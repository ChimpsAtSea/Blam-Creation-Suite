#include "blamtoozle-private-pch.h"

c_blamtoozle_tag_struct_definition::c_blamtoozle_tag_struct_definition(
	c_blamtoozle_tag_definition_manager& _tag_definition_manager) :
	fields(),
	tag_definition_manager(_tag_definition_manager)
{
}

c_blamtoozle_tag_struct_definition::~c_blamtoozle_tag_struct_definition()
{
	clear_fields();
}

void c_blamtoozle_tag_struct_definition::clear_fields()
{
	for (t_blamtoozle_tag_field* field_wrapper : fields)
	{
		delete field_wrapper;
	}
	fields.clear();
}

const char* c_blamtoozle_tag_struct_definition::get_file_path()
{
	return nullptr;
}

long c_blamtoozle_tag_struct_definition::get_line_number()
{
	return -1;
}

void c_blamtoozle_tag_struct_definition::handle_conflict(const c_blamtoozle_tag_struct_definition& conflicting_tag_struct_definition)
{
}
