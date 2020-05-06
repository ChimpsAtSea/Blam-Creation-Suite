#include "blamboozlelib-private-pch.h"

c_h5_tag_field_data_64::c_h5_tag_field_data_64(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
	c_h5_tag_field(halo5_forge_data, field_definition)
{
	tag_data_definition = reinterpret_cast<const s_h5_tag_data_definition*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));

	definition_name = h5_aa_to_pointer(halo5_forge_data, tag_data_definition->definition_name_address);
	maximum_size = h5_aa_to_pointer(halo5_forge_data, tag_data_definition->maximum_size_string_address);

}
