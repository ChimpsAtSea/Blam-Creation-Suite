#include "blamboozlelib-private-pch.h"

c_h5_tag_field_explaination_definition::c_h5_tag_field_explaination_definition(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
	c_h5_tag_field(halo5_forge_data, field_definition)
{
	explaination = reinterpret_cast<const char*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));

}
