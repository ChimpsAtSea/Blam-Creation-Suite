#include "blamboozlelib-private-pch.h"

c_h4_tag_block::c_h4_tag_block(const char* h4_data, const s_h4_tag_block_definition* tag_block_definition_header, const s_h4_tag_group* tag_layout_header)
{
	display_name = h4_va_to_pointer(h4_data, tag_block_definition_header->display_name_address);
	name = h4_va_to_pointer(h4_data, tag_block_definition_header->name_address);

	const char* maximum_element_count_string = h4_va_to_pointer(h4_data, tag_block_definition_header->maximum_element_count_string_address);

	uint32_t struct_definition_address = tag_block_definition_header->struct_definition;
	const s_h4_tag_struct_definition* struct_definition = reinterpret_cast<const s_h4_tag_struct_definition*>(h4_va_to_pointer(h4_data, tag_block_definition_header->struct_definition));
	ASSERT(struct_definition != nullptr);
	const char* field_set_display_name = h4_va_to_pointer(h4_data, struct_definition->display_name);
	const char* field_set_name = h4_va_to_pointer(h4_data, struct_definition->name);
	tag_struct = c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition);
}
