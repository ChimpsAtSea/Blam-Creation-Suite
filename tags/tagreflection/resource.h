#pragma once

struct s_resource_chunk_details
{
	const void* buffer;
	uint32_t buffer_size;
};

struct s_resource_details
{
	const void* buffer;
	uint32_t buffer_size;
	s_resource_chunk_details* chunk_details;
	uint32_t num_chunk_details;
	h_prototype* prototype;
};

class h_resource :
	public h_extended_type
{
public:
	BCS_SHARED h_resource(h_type* parent = nullptr);
	BCS_SHARED virtual ~h_resource();

	BCS_SHARED virtual BCS_RESULT add_reference(s_resource_details& resource_details, bool create_prototype) = 0;
	BCS_SHARED virtual BCS_RESULT remove_reference() = 0;
	BCS_SHARED virtual const char* get_debug_type_string() = 0;
};
