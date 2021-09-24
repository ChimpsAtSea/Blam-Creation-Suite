#pragma once

template<typename T>
class c_auto_delete
{
public:
	c_auto_delete(T pointer) : pointer(pointer) {}
	~c_auto_delete() { delete pointer; }
protected:
	T pointer;
};

#define AUTO_DELETE(pointer) c_auto_delete __auto_delete_##__LINE__(shader_binary_data)
