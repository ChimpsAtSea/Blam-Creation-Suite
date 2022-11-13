#pragma once

class h_block :
	public h_enumerable
{
public:
	h_block(h_type* parent = nullptr);

	virtual h_prototype& emplace_back() = 0;
	virtual h_prototype& emplace_back(const h_prototype& value) = 0;
	virtual void reserve(uint32_t count) = 0;
	virtual void resize(uint32_t count) = 0;
	virtual void insert_hole(uint32_t index, uint32_t count) = 0;
	virtual void remove(uint32_t index) = 0;
	virtual void clear() = 0;
	virtual blofeld::s_tag_struct_definition const& get_tag_struct_definition() const = 0;

	//protected:
	//	h_block(h_block const&) = default;
};
