#pragma once

template<typename T>
class v_tag_interface;

class c_virtual_tag
{
public:
	c_virtual_tag(c_tag_interface& tag_interface, s_tag_reference& tag_reference) :
		tag_interface(tag_interface),
		tag_reference(tag_reference)
	{

	}

	operator c_tag_interface* () const
	{
		// #TODO: cache refactor
		//return tag_interface.get_cache_file().get_tag_interface(tag_reference.index);
		throw;
	}

	operator const c_tag_interface* () const
	{
		// #TODO: cache refactor
		//return tag_interface.get_cache_file().get_tag_interface(tag_reference.index);
		throw;
	}

	template<typename T>
	operator v_tag_interface<T>* () const
	{
		c_tag_interface* target_tag_interface = *this;
		return tag_cast<T>(target_tag_interface);
	}

	template<typename T>
	operator const v_tag_interface<T>* () const
	{
		c_tag_interface* target_tag_interface = *this;
		return tag_cast<T>(target_tag_interface);
	}

private:
	c_tag_interface& tag_interface;
	s_tag_reference& tag_reference;
};
