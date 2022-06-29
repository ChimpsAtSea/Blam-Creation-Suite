#pragma once

template<typename h_custom_type, unsigned long _size>
class h_typed_array :
	public std::array<h_custom_type, _size>,
	public h_enumerable
{
public:
	h_typed_array(h_type * parent = nullptr) :
		h_enumerable(parent)
	{
		for (unsigned long index = 0; index < _size; index++)
		{
			// #TODO: is there a better way to do this?
			// _set_parent is kind of nasty to expose
			get(index)._set_parent(this); 
		}
	}

	virtual h_custom_type& operator[](unsigned long index) final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual const h_custom_type& operator[](unsigned long index) const final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual h_custom_type & get(unsigned long index) final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual const h_custom_type& get(unsigned long index) const final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual const h_custom_type * data() final
	{
		return std::array<h_custom_type, _size>::data();
	}

	virtual unsigned long size() const final
	{
		return _size;
	}

	virtual unsigned long data_size() const final
	{
		return _size * sizeof(h_custom_type);
	}

//protected:
//	h_typed_array(h_typed_array const&) = default;
};
