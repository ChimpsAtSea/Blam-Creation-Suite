#include "tagreflection-private-pch.h"

h_prototype::h_prototype(h_type* parent) :
	h_type(parent)
{

}

h_prototype::~h_prototype()
{

}

unsigned long h_prototype::get_version() const
{
	return 0;
}
