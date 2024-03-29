#pragma once

class h_type;

struct h_field_serialization_info
{
	unsigned int blofeld_field_index;
	h_pointer_to_member pointer_to_member;
};

class h_prototype_serialization_info
{
public:
	blofeld::s_tag_struct_definition const& tag_struct_definition;
	h_field_serialization_info const* field_serialization_infos;
	unsigned int num_field_serialization_infos;

	BCS_SHARED BCS_RESULT get_field_serialization_info_by_blofeld_field(blofeld::s_tag_field const& tag_field, h_field_serialization_info const*& field_serialization_info) const;
};
