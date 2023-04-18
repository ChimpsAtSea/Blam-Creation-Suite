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

BCS_RESULT c_simple_resource_container::add_reference(s_resource_details& resource_details, bool create_prototype)
{
	if (create_prototype)
	{
		return BCS_E_UNSUPPORTED;
	}

	reference_count++;
	ASSERT(reference_count >= 0);

	resource_details = {};
	resource_details.buffer = data.data();
	resource_details.buffer_size = static_cast<unsigned long>(data.size());

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
