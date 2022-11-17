#include "tagreflection-private-pch.h"

h_resource::h_resource(h_type* parent) :
	h_type(parent),
	object(nullptr)
{

}

h_resource::~h_resource()
{

}

h_interop::h_interop() :
	h_type(nullptr)
{

}

h_interop::~h_interop()
{

}
