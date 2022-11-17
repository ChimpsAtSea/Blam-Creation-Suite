#pragma once

class h_field;

// #TODO: Wrap all types such that they are h_field
using h_pointer_to_member = h_type h_extended_type::*;

class h_member_info
{
public:
	const char* name;
	h_pointer_to_member pointer_to_member;
};

class h_serialization_info
{
public:
	blofeld::s_tag_field const& tag_field;
	h_pointer_to_member pointer_to_member;
};
