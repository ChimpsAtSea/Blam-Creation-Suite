#pragma once

class h_block :
	public h_enumerable
{
public:
	h_block(h_type* parent = nullptr);

	virtual h_prototype& emplace_back() = 0;
	virtual h_prototype& emplace_back(const h_prototype& value) = 0;
	virtual void reserve(unsigned long count) = 0;
	virtual void resize(unsigned long count) = 0;
	virtual void insert_hole(unsigned long index, unsigned long count) = 0;
	virtual void remove(unsigned long index) = 0;
	virtual void clear() = 0;
	virtual const blofeld::s_tag_struct_definition& get_tag_struct_definition() const = 0;

	//protected:
	//	h_block(h_block const&) = default;
};
