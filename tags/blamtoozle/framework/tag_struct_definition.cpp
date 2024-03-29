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

int32_t c_blamtoozle_tag_struct_definition::get_line_number()
{
	return -1;
}

bool c_blamtoozle_tag_struct_definition::is_legacy_struct()
{
	return false;
}

bool c_blamtoozle_tag_struct_definition::is_latest_structure_version()
{
	return true;
}

c_blamtoozle_tag_struct_definition* c_blamtoozle_tag_struct_definition::get_previous_struct_definition()
{
	return nullptr;
}

c_blamtoozle_tag_struct_definition* c_blamtoozle_tag_struct_definition::get_next_struct_definition()
{
	return nullptr;
}

c_blamtoozle_tag_struct_definition& c_blamtoozle_tag_struct_definition::get_latest_struct_definition()
{
	return *this;
}

uint32_t c_blamtoozle_tag_struct_definition::get_structure_version()
{
	return 0;
}
