#pragma once

template<typename T>
class v_tag_interface;

class c_virtual_tag_interface
{
public:
	c_virtual_tag_interface(c_cache_file& cache_file, c_tag_interface& tag_interface, TagReference& tag_reference) :
		cache_file(cache_file),
		tag_interface(tag_interface),
		tag_reference(tag_reference)
	{

	}

	operator c_tag_interface* () const
	{
		return cache_file.get_tag_interface(tag_reference.index);
	}

	operator const c_tag_interface* () const
	{
		return cache_file.get_tag_interface(tag_reference.index);
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
	c_cache_file& cache_file;
	c_tag_interface& tag_interface;
	TagReference& tag_reference;
};
