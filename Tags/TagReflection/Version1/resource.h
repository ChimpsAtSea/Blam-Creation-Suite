#pragma once

class h_resource :
	public h_type
{
public:
	h_resource(h_type* parent = nullptr);
	virtual ~h_resource();

	h_prototype* object;

	virtual BCS_RESULT add_reference(const void*& buffer, uint32_t& buffer_size) = 0;
	virtual BCS_RESULT remove_reference() = 0;
	virtual const char* get_debug_type_string() = 0;
};

class h_interop :
	public h_type
{
public:
	h_interop();
	virtual ~h_interop();

};
