#include "blamboozlelib-private-pch.h"

c_h5_tag_field_enum::c_h5_tag_field_enum(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
	c_h5_tag_field(halo5_forge_data, field_definition)
{
	tag_enum_definition = reinterpret_cast<const s_h5_tag_enum_definition*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));

	//const uint32_t* options_strings_address = reinterpret_cast<const uint32_t*>(h5_aa_to_pointer(halo5_forge_data, tag_enum_definition->options_address));
	//for (uint32_t option_index = 0; option_index < tag_enum_definition->option_count; option_index++)
	//{
	//	uint32_t option_string_address = options_strings_address[option_index];
	//	const char* option = h5_aa_to_pointer(halo5_forge_data, option_string_address);
	//	options.push_back(option);
	//	debug_point;
	//}
}
