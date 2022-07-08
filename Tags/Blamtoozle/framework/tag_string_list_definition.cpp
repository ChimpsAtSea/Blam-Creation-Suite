#include "blamtoozle-private-pch.h"

c_blamtoozle_string_list_definition::c_blamtoozle_string_list_definition(
	c_blamtoozle_tag_definition_manager& tag_definition_manager) :
	options(),
	tag_definition_manager(tag_definition_manager)
{
}

c_blamtoozle_string_list_definition::~c_blamtoozle_string_list_definition()
{

}

const char* c_blamtoozle_string_list_definition::get_file_path()
{
	return nullptr;
}

long c_blamtoozle_string_list_definition::get_line_number()
{
	return -1;
}
