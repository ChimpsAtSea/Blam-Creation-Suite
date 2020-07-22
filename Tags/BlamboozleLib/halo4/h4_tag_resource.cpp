#include <blamboozlelib-private-pch.h>

c_h4_tag_resource::c_h4_tag_resource(const char* h4_data, const s_h4_tag_resource_definition* tag_resource_definition) :
	name(h4_va_to_pointer(h4_data, tag_resource_definition->name)),
	tag_resource_definition(tag_resource_definition),
	struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, tag_resource_definition->struct_definition)),
	tag_struct(*c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, tag_resource_definition->struct_definition))
{

}
