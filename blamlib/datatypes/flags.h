#pragma once

#include <blamlib/cseries/cseries.h>

/* ---------- classes */

template <
	typename t_enum,
	typename t_storage,
	const long k_number_of_bits = sizeof(t_storage) * 8>
class c_flags_no_init
{
	static_assert(__is_enum(t_enum));
	static_assert(k_number_of_bits <= sizeof(t_storage) * 8);

protected:
	t_storage m_stored;

public:
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
		auto total_bits = sizeof(t_storage) * k_uint8_bits;

		for (auto current_bit = k_number_of_bits;
			current_bit < total_bits;
			current_bit++)
		{
			if (TEST_BIT(m_stored, current_bit))
				return false;
		}

		return true;
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
};

template <
	typename t_enum,
	typename t_storage = __underlying_type(t_enum),
	const long k_number_of_bits = sizeof(t_storage) * 8>
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

    c_flags(const t_storage &value)
    {
        m_stored = value;
	}

	c_flags operator|(c_flags value) const
	{
		c_flags result;
		result.set_unsafe(this->m_stored | value.m_stored);
		return result;
	}
};
