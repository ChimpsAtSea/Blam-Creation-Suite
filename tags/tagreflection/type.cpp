#include "tagreflection-private-pch.h"

h_type::h_type(h_type* parent) :
	parent(parent)
{

}

h_type::~h_type()
{

}

void h_type::_set_parent(h_type* _parent)
{
	parent = _parent;
}
