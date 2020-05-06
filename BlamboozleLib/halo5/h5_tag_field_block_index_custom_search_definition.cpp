#include "blamboozlelib-private-pch.h"

c_h5_tag_field_block_index_custom_search_definition::c_h5_tag_field_block_index_custom_search_definition(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
	c_h5_tag_field(halo5_forge_data, field_definition)
{
	tag_block_index_custom_search_definition = reinterpret_cast<const s_h5_tag_block_index_custom_search_definition*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));

}
