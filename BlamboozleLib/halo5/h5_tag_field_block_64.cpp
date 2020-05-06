#include "blamboozlelib-private-pch.h"

c_h5_tag_field_block_64::c_h5_tag_field_block_64(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
	c_h5_tag_field(halo5_forge_data, field_definition)
{
	tag_block_definition_header = reinterpret_cast<const s_h5_tag_block_definition_header*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));
	tag_block_definition = c_blamboozle_h5_forge::get_tag_block_definition(field_definition->definition_address, halo5_forge_data, tag_block_definition_header);
}
