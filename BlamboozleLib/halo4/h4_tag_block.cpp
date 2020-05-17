#include "blamboozlelib-private-pch.h"

c_h4_tag_block::c_h4_tag_block(const char* h4_data, const s_h4_tag_block_definition* tag_block_definition_header, const s_h4_tag_group* tag_layout_header) :
	display_name(h4_va_to_pointer(h4_data, tag_block_definition_header->display_name)),
	name(h4_va_to_pointer(h4_data, tag_block_definition_header->name)),
	maximum_element_count(tag_block_definition_header->maximum_element_count),
	maximum_element_count_string(h4_va_to_pointer(h4_data, tag_block_definition_header->maximum_element_count_string)),
	struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, tag_block_definition_header->struct_definition)),
	tag_struct(*c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition)),
	is_block(true),
	is_array(false)
{
	REFERENCE_ASSERT(tag_struct);
}

c_h4_tag_block::c_h4_tag_block(const char* h4_data, const s_h4_tag_array_definition* tag_array_definition_header) :
	display_name(h4_va_to_pointer(h4_data, tag_array_definition_header->name)),
	name(h4_va_to_pointer(h4_data, tag_array_definition_header->name)),
	maximum_element_count(tag_array_definition_header->element_count),
	maximum_element_count_string(h4_va_to_pointer(h4_data, tag_array_definition_header->element_count_string)),
	struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, tag_array_definition_header->struct_definition)),
	tag_struct(*c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition)),
	is_block(false),
	is_array(true)
{

}