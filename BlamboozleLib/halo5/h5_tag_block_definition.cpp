#include "blamboozlelib-private-pch.h"

c_h5_tag_block_definition::c_h5_tag_block_definition(const char* halo5_forge_data, const s_h5_tag_block_definition* tag_block_definition_header, const s_h5_tag_layout_header* tag_layout_header)
{
	display_name = h5_aa_to_pointer(halo5_forge_data, tag_block_definition_header->display_name_address);
	name = h5_aa_to_pointer(halo5_forge_data, tag_block_definition_header->name_address);

	const char* maximum_element_count_string = h5_aa_to_pointer(halo5_forge_data, tag_block_definition_header->maximum_element_count_string_address);

	const s_h5_tag_field_set_header* field_sets = reinterpret_cast<const s_h5_tag_field_set_header*>(h5_aa_to_pointer(halo5_forge_data, tag_block_definition_header->field_set_address));

	const char* display_name = field_sets->display_name;
	const char* name = field_sets->name;

	//const uintptr_t* structure_name_address_table = reinterpret_cast<const uintptr_t*>(h5_aa_to_pointer(halo5_forge_data, tag_block_definition_header->structure_name_address_table_address));
	//const char* display_name = h5_aa_to_pointer(halo5_forge_data, structure_name_address_table[0]);
	//const char* name = h5_aa_to_pointer(halo5_forge_data, structure_name_address_table[1]);


	uint32_t set_index = 0;
	//for (uint32_t set_index = 0; set_index < definition_header->field_set_count; set_index++)
	{
		const s_h5_tag_field_set_header* field_set = field_sets + set_index;
		c_h5_tag_field_set* tag_field_set = new c_h5_tag_field_set(halo5_forge_data, field_sets + set_index);
		tag_field_sets.emplace_back(tag_field_set);
	}
}
