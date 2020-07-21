#include <blamboozlelib-private-pch.h>

c_h4_tag_interop::c_h4_tag_interop(const char* h4_data, const s_h4_tag_interop_definition* tag_interop_definition) :
	name(h4_va_to_pointer(h4_data, tag_interop_definition->name)),
	tag_interop_definition(tag_interop_definition),
	struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, tag_interop_definition->struct_definition)),
	tag_struct(*c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, tag_interop_definition->struct_definition))
{

}
