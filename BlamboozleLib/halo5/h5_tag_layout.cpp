#include "blamboozlelib-private-pch.h"

c_h5_tag_layout::c_h5_tag_layout(const char* halo5_forge_data, const s_h5_tag_layout_header* layout_header)
{
	name = h5_aa_to_pointer(halo5_forge_data, layout_header->name_address);
	const char* default_tag_path = h5_aa_to_pointer(halo5_forge_data, layout_header->default_tag_path_address);
	const s_h5_tag_block_definition_header* tag_block_definition_header = reinterpret_cast<const s_h5_tag_block_definition_header*>(h5_aa_to_pointer(halo5_forge_data, layout_header->definition_address));

	tag_block_definition = c_blamboozle_h5_forge::get_tag_block_definition(layout_header->definition_address, halo5_forge_data, tag_block_definition_header, layout_header);
}
