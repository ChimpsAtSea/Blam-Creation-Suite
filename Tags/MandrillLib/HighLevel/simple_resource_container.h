#pragma once

class c_simple_resource_container :
	public h_resource
{
public:
	c_simple_resource_container();
	~c_simple_resource_container();

	virtual BCS_RESULT add_reference(const void*& buffer, unsigned long& buffer_size) override;
	virtual BCS_RESULT remove_reference() override;
	virtual const char* get_debug_type_string() override;

//private:
	long reference_count;
	std::vector<char> data;
};

