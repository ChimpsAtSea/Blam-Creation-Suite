#pragma once

template <typename t_type, typename t_error>
class c_result final
{
private:
	t_type m_value;
	t_error const *m_error;

public:
	c_result(t_type const &value) :
		m_value(value),
		m_error(nullptr)
	{
	}

	c_result(t_error const &error) :
		m_error(&error)
	{
	}

	bool has_error() const
	{
		return m_error != nullptr;
	}

	t_error const &get_error() const
	{
		return *m_error;
	}

	t_type get_value() const
	{
		return m_value;
	}
};
