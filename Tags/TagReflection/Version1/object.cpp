#include "tagreflection-private-pch.h"

h_prototype::h_prototype(h_type* parent) :
	h_type(parent)
{

}

h_prototype::~h_prototype()
{

}

bool h_prototype::operator==(h_prototype const& value) const
{
	return this == &value;
}

bool h_prototype::operator!=(h_prototype const& value) const
{
	return this != &value;
}

uint32_t h_prototype::get_version() const
{
	return 0;
}
