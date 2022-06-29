#pragma once

class h_enumerable :
	public h_type
{
public:
	h_enumerable(h_type* parent = nullptr);

	virtual h_object& operator[](unsigned long index) = 0;
	virtual const h_object& operator[](unsigned long index) const = 0;
	virtual h_object& get(unsigned long index) = 0;
	virtual const h_object& get(unsigned long index) const = 0;
	virtual const h_object* data() = 0;
	virtual unsigned long size() const = 0;
	virtual unsigned long data_size() const = 0;

	//protected:
	//	h_enumerable(h_enumerable const&) = default;
};
