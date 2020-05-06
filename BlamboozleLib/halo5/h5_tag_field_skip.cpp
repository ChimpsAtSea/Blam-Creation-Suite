#include "blamboozlelib-private-pch.h"

c_h5_tag_field_skip::c_h5_tag_field_skip(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
	c_h5_tag_field(halo5_forge_data, field_definition),
	lenght(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(field_definition->definition_address)))
{

}
