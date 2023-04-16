#pragma once

class h_resource :
	public h_extended_type
{
public:
	BCS_SHARED h_resource(h_type* parent = nullptr);
	BCS_SHARED virtual ~h_resource();

	BCS_SHARED virtual BCS_RESULT add_reference(const void*& buffer, uint32_t& buffer_size) = 0;
	BCS_SHARED virtual BCS_RESULT remove_reference() = 0;
	BCS_SHARED virtual const char* get_debug_type_string() = 0;
};
