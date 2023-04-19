#include "tagreflection-private-pch.h"

BCS_RESULT h_prototype_serialization_info::get_field_serialization_info_by_blofeld_field(blofeld::s_tag_field const& tag_field, h_field_serialization_info const*& out_field_serialization_info) const
{
	auto field_index = &tag_field - tag_struct_definition.fields;

	// #TODO: Binary search this

	for (unsigned int field_serialization_index = 0; field_serialization_index < num_field_serialization_infos; field_serialization_index++)
	{
		h_field_serialization_info const& field_serialization_info = field_serialization_infos[field_serialization_index];
		// blofeld::s_tag_field const& tag_field = tag_struct_definition.fields[field_serialization_info.blofeld_field_index];

		if (field_serialization_info.blofeld_field_index == field_index)
		{
			out_field_serialization_info = &field_serialization_info;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}
