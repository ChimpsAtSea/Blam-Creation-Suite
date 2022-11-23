#include "tagreflection-private-pch.h"

h_resource::h_resource(h_type* parent) :
	h_extended_type(parent, UINT8_MAX, UINT16_MAX),
	prototype(nullptr)
{

}

h_resource::~h_resource()
{
	if (prototype)
	{
		delete prototype;
	}
}
