#pragma once

class h_enumerable :
	public h_type
{
public:
	h_enumerable(h_type* parent = nullptr);

	virtual h_prototype& operator[](uint32_t index) = 0;
	virtual const h_prototype& operator[](uint32_t index) const = 0;
	virtual h_prototype& get(uint32_t index) = 0;
	virtual const h_prototype& get(uint32_t index) const = 0;
	virtual const h_prototype* data() = 0;
	virtual uint32_t size() const = 0;
	virtual uint32_t data_size() const = 0;

	//protected:
	//	h_enumerable(h_enumerable const&) = default;
};
