#pragma once

class h_enumerable :
	public h_extended_type
{
public:
	h_enumerable(h_type* parent, unsigned char global_vftable_index, unsigned short local_vftable_index);

	virtual h_prototype& operator[](unsigned int index) = 0;
	virtual const h_prototype& operator[](unsigned int index) const = 0;
	virtual h_prototype& get(unsigned int index) = 0;
	virtual const h_prototype& get(unsigned int index) const = 0;
	virtual unsigned int size() const = 0;
	virtual unsigned int data_size() const = 0;
};
