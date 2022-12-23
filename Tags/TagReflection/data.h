#pragma once

class h_data :
	public h_extended_type
{
public:
	BCS_SHARED h_data(h_prototype* parent);
	BCS_SHARED ~h_data();

	BCS_SHARED unsigned int get_count();


	BCS_SHARED char* begin();
	BCS_SHARED char* end();
	BCS_SHARED char& emplace_back(char value = 0);
	BCS_SHARED char* create_elements(unsigned int num_elements);
	BCS_SHARED char* append_elements(char const* copy_from, unsigned int num_elements);
	BCS_SHARED char* append_elements(char const* copy_start, char const* copy_end);
	BCS_SHARED void clear();
	BCS_SHARED char& operator[](size_t index);
	BCS_SHARED unsigned int size() const;
	BCS_SHARED bool empty() const;
	BCS_SHARED void const* data() const;
	BCS_SHARED void* data();

protected:
	void* data_data;
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_data = h_data;

#else

// #TODO

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_data = h_data;

#endif
