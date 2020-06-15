#include "tagreflection-private-pch.h"

c_virtual_tag_interface::c_virtual_tag_interface(c_tag_interface& tag_interface) :
	tag_interface(tag_interface)
{
	tag_interface.associate_virtual_tag_interface(*this);
}

c_virtual_tag_interface::~c_virtual_tag_interface()
{

}
