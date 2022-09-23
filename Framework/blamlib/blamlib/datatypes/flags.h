#pragma once

#include <blamlib/cseries/cseries.h>

/* ---------- classes */

template <
	typename t_enum,
	typename t_storage,
	const int k_number_of_bits = sizeof(t_storage) * 8>
class c_flags_no_init
{
	static_assert(__is_enum(t_enum));
	static_assert(k_number_of_bits <= sizeof(t_storage) * 8);

protected:
	t_storage m_stored;

public:
	static t_storage make_N_bit_mask_size_type(int num_bits)
	{
		return ~t_storage() >> (k_number_of_bits - num_bits);
	}

	static t_storage make_mask_with_all_valid_bits_on_size_type()
	{
		return make_N_bit_mask_size_type(k_number_of_bits);
	}

	bool is_clear() const
	{
		t_storage mask = make_mask_with_all_valid_bits_on_size_type();
		return (m_stored & mask) == 0;
	}

	c_flags_no_init operator~() const
	{
		t_storage mask = make_mask_with_all_valid_bits_on_size_type();
		c_flags_no_init result;
		result.set_unsafe((~m_stored) & mask);
		return result;
	}

	void clear()
	{
		m_stored = 0;
	}

	bool test(t_enum bit) const
	{
		return (m_stored & FLAG(static_cast<t_storage>(bit))) != 0;
	}

	void set(t_enum bit, bool value)
	{
		t_storage flag = FLAG(static_cast<t_storage>(bit));

		if (value)
			m_stored |= flag;
		else
			m_stored &= ~flag;
	}

	bool valid() const
	{
		t_storage mask = ~make_mask_with_all_valid_bits_on_size_type();
		return (m_stored & mask) == 0;
	}

	t_storage get_unsafe() const
	{
		return m_stored;
	}

	void set_unsafe(t_storage value)
	{
		m_stored = value;
	}

	c_flags_no_init operator|(c_flags_no_init value) const
	{
		c_flags_no_init result;
		result.set_unsafe(this->m_stored | value.m_stored);
		return result;
	}

	bool operator==(c_flags_no_init const& value) const
	{
		return m_stored == value.m_stored;
	}
};

template <
	typename t_enum,
	typename t_storage = __underlying_type(t_enum),
	const int k_number_of_bits = sizeof(t_storage) * 8>
class c_flags :
	public c_flags_no_init<t_enum, t_storage, k_number_of_bits>
{
	using t_base = c_flags_no_init<t_enum, t_storage, k_number_of_bits>;
	using t_this = c_flags<t_enum, t_storage, k_number_of_bits>;

protected:
	using t_base::m_stored;

public:
	c_flags()
	{
		m_stored = static_cast<t_storage>(0);
	}

	c_flags(const t_storage& value)
	{
		m_stored = value;
	}

	c_flags(const t_enum& value)
	{
		m_stored = static_cast<t_storage>(0);
		this->set(value, true);
	}

	c_flags operator|(c_flags value) const
	{
		c_flags result;
		result.set_unsafe(this->m_stored | value.m_stored);
		return result;
	}
};
