#pragma once

class c_virtual_resource_manager;
class c_virtual_bitmap_resource
{
public:
	friend class c_virtual_resource_manager;
	c_virtual_bitmap_resource() = delete;
	c_virtual_bitmap_resource(const c_virtual_bitmap_resource&) = delete;
	c_virtual_bitmap_resource& operator=(const c_virtual_bitmap_resource&) = delete;

private:
	c_virtual_bitmap_resource(c_virtual_resource_manager& virtual_resource_manager, v_tag_interface_legacy<s_bitmap_definition>& bitmap_tag_interface);
	~c_virtual_bitmap_resource();

	c_virtual_resource_manager& virtual_resource_manager;
	v_tag_interface_legacy<s_bitmap_definition>& bitmap_tag_interface;
};

