#pragma once

#include <cseries/cseries.h>

#include <datatypes/enum.h>
#include <datatypes/flags.h>
#include <datatypes/static_array.h>
#include <datatypes/static_hash_table_data.h>
#include <datatypes/static_string.h>

template <const long k_maximum_count>
class c_static_bitarray final
{
	static_assert(k_maximum_count > 0);

private:
	long m_bit_vector[BIT_VECTOR_SIZE_IN_LONGS(k_maximum_count)];

public:
	void clear()
	{
		memset(m_bit_vector, 0, BIT_VECTOR_SIZE_IN_BYTES(k_maximum_count));
	}

	void set(long bit_index, bool m_value)
	{
		assert(VALID_INDEX(bit_index, k_maximum_count));
		BIT_VECTOR_SET_FLAG(m_bit_vector, bit_index, m_value);
	}

	bool test(long bit_index) const
	{
		assert(VALID_INDEX(bit_index, k_maximum_count));
		return BIT_VECTOR_TEST_FLAG(m_bit_vector, bit_index);
	}

	bool operator[](long bit_index) const
	{
		assert(VALID_INDEX(bit_index, k_maximum_count));
		return test(bit_index);
	}
};

template <const long k_maximum_count>
class c_static_wchar_string
{
	static_assert(k_maximum_count > 0);

private:
	wchar_t m_string[k_maximum_count];

public:
	wchar_t *get_string()
	{
		return m_string;
	}

	wchar_t const *get_string_const() const
	{
		return m_string;
	}

	void set(wchar_t const *string)
	{
		// TODO
	}
};

template <const long k_number_of_bits>
class c_big_flags
{

};

template <typename t_storage, const long k_number_of_bits>
class c_big_flags_typed_no_init
{
protected:
	t_storage m_storage[k_number_of_bits >> 5];

public:
	// TODO
};

template <typename t_storage, const long k_number_of_bits>
class c_big_flags_typed :
	public c_big_flags_typed_no_init<t_storage, k_number_of_bits>
{

};
