#pragma once

class h_type;

class h_serialization_info
{
public:
	blofeld::s_tag_field const& tag_field;
	h_pointer_to_member pointer_to_member;
};
