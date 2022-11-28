#pragma once

class h_data :
	public h_extended_type
{
public:
	BCS_SHARED h_data(h_prototype* parent);
	BCS_SHARED ~h_data();

	BCS_SHARED unsigned int get_count();

	void* data_data;

	BCS_SHARED char* begin();
	BCS_SHARED char* end();
	BCS_SHARED char& emplace_back(char value = 0);
	BCS_SHARED char* create_elements(unsigned int num_elements);
	BCS_SHARED void clear();
	BCS_SHARED char& operator[](size_t index);
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_data = h_data;

#else

// #TODO

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_data = h_data;

#endif
