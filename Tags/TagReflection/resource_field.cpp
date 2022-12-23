#include "tagreflection-private-pch.h"

h_resource_field::h_resource_field(h_prototype& parent) :
	h_field(parent),
	prototype(nullptr),
	resource(nullptr)
{

}

//h_resource_field::h_resource_field(h_resource* _resource) :
//	resource(nullptr)
//{
//	set_resource(_resource);
//}
//
//h_resource_field::h_resource_field(h_resource_field const& _resource_field) :
//	resource(nullptr)
//{
//	set_resource(_resource_field.resource);
//}

h_resource_field::~h_resource_field()
{
	clear();
}

h_resource* h_resource_field::get_resource() const
{
	return resource;
}

void h_resource_field::set_resource(h_resource* _resource)
{
	resource = _resource;
}

void h_resource_field::clear()
{
	resource = nullptr;
}

h_resource_field& h_resource_field::operator=(h_resource_field const& resource_field)
{
	set_resource(resource_field.resource);
	return *this;
}

h_resource_field& h_resource_field::operator=(h_resource* const& _resource)
{
	set_resource(_resource);
	return *this;
}

bool h_resource_field::operator==(h_resource_field const& resource_field) const
{
	return resource == resource_field.resource;
}

bool h_resource_field::operator==(h_resource* const& _resource) const
{
	return resource == _resource;
}

bool h_resource_field::operator!=(h_resource_field const& resource_field) const
{
	return resource != resource_field.resource;
}

bool h_resource_field::operator!=(h_resource* const& _resource) const
{
	return resource != _resource;
}

void const* h_resource_field::get_data() const
{
	return &resource;
}

void* h_resource_field::get_data()
{
	return &resource;
}
