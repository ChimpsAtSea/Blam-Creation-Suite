#include "blamboozlelib-private-pch.h"

c_h4_tag_group::c_h4_tag_group(const char* h4_data, const s_h4_tag_group* layout_header) :
	name(h4_va_to_pointer(h4_data, layout_header->name_address.value())),
	flags(layout_header->flags),
	group_tag(layout_header->group_tag),
	parent_group_tag(layout_header->parent_group_tag),
	version(layout_header->version),
	initialized(layout_header->initialized),
	block_definition(h4_va_to_pointer<s_h4_tag_block_definition>(h4_data, layout_header->definition_address)),
	tag_block(*c_h4_blamboozle::get_tag_block_definition(h4_data, block_definition, layout_header))
{
	REFERENCE_ASSERT(tag_block);
}
