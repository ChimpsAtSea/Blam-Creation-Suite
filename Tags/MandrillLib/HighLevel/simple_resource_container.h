#pragma once

class c_simple_resource_container :
	public h_resource
{
public:
	BCS_SHARED c_simple_resource_container();
	~c_simple_resource_container();

	virtual BCS_RESULT add_reference(const void*& buffer, uint32_t& buffer_size) override;
	virtual BCS_RESULT remove_reference() override;
	virtual const char* get_debug_type_string() override;

//private:
	int32_t reference_count;
	std::vector<char> data;
};

