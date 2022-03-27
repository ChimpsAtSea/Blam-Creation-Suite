#include "mandrilllib-private-pch.h"

c_simple_resource_container::c_simple_resource_container() :
	reference_count(0),
	data()
{

}

c_simple_resource_container::~c_simple_resource_container()
{
	ASSERT(reference_count == 0);
}

BCS_RESULT c_simple_resource_container::add_reference(const void*& buffer, unsigned long& buffer_size)
{
	reference_count++;
	ASSERT(reference_count >= 0);

	buffer = data.data();
	buffer_size = static_cast<unsigned long>(data.size());

	return BCS_S_OK;
}

BCS_RESULT c_simple_resource_container::remove_reference()
{
	reference_count--;
	ASSERT(reference_count >= 0);
	return BCS_S_OK;
}

const char* c_simple_resource_container::get_debug_type_string()
{
	return "c_simple_resource_container";
}
