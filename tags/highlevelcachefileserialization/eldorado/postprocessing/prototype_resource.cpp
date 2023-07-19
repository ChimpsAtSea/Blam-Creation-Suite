#include "highlevelcachefileserialization-private-pch.h"

h_prototype_resource::h_prototype_resource(h_prototype* _prototype) :
	h_resource(),
	prototype(_prototype)
{

}

h_prototype_resource::~h_prototype_resource()
{

}

BCS_RESULT h_prototype_resource::add_reference(s_resource_details& resource_details, bool create_prototype)
{
	resource_details = {};
	resource_details.prototype = prototype;
	return BCS_S_OK;
}

BCS_RESULT h_prototype_resource::remove_reference()
{
	return BCS_S_OK;
}

const char* h_prototype_resource::get_debug_type_string()
{
	return "h_prototype_resource";
}
