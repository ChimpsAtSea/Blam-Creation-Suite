#include "blamboozlelib-private-pch.h"

c_h4_tag_block::c_h4_tag_block(const char* h4_data, const s_h4_tag_block_definition* tag_block_definition_header, const s_h4_tag_group* tag_layout_header) :
	display_name(h4_va_to_pointer(h4_data, tag_block_definition_header->display_name_address)),
	name(h4_va_to_pointer(h4_data, tag_block_definition_header->name_address)),
	maximum_element_count(tag_block_definition_header->maximum_element_count),
	maximum_element_count_string(h4_va_to_pointer(h4_data, tag_block_definition_header->maximum_element_count_string_address)),
	struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, tag_block_definition_header->struct_definition)),
	tag_struct(c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition))
{

}
