#include "blamboozlelib-private-pch.h"

c_h5_tag_field_struct::c_h5_tag_field_struct(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
	c_h5_tag_field(halo5_forge_data, field_definition)
{
	tag_struct_definition = reinterpret_cast<const s_h5_tag_struct_definition*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));

}
