#include "blamboozlelib-private-pch.h"

c_h5_tag_field::c_h5_tag_field(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition)
{
	name = h5_aa_to_pointer(halo5_forge_data, field_definition->name_address);
	definition = h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address);
}

c_h5_tag_field::~c_h5_tag_field()
{

}
