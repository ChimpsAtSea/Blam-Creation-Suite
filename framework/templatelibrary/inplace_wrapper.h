#pragma once

template<typename t_type, bool auto_dispose = true>
class alignas(t_type) t_inplace_wrapper
{
public:
	t_inplace_wrapper() = default;
	t_inplace_wrapper(const t_inplace_wrapper&) = delete;
	t_inplace_wrapper(t_inplace_wrapper&&) = delete;
	t_inplace_wrapper& operator=(const t_inplace_wrapper&) = delete;
	t_inplace_wrapper& operator=(t_inplace_wrapper&&) = delete;
	~t_inplace_wrapper()
	{
		if constexpr (auto_dispose)
		{
			dispose();
		}
	}

	void dispose()
	{
		if constexpr (!__is_trivially_destructible(t_type))
		{
			reinterpret_cast<t_type*>(underlying_data)->~t_type();
		}
	}

	t_type& ref()
	{
		return *reinterpret_cast<t_type*>(underlying_data);
	}

	t_type const& ref() const
	{
		return *reinterpret_cast<t_type*>(underlying_data);
	}

	t_type* ptr()
	{
		return reinterpret_cast<t_type*>(underlying_data);
	}

	t_type const* ptr() const
	{
		return reinterpret_cast<t_type*>(underlying_data);
	}

	operator t_type& ()
	{
		return *reinterpret_cast<t_type*>(underlying_data);
	}

	operator t_type const& () const
	{
		return *reinterpret_cast<t_type*>(underlying_data);
	}

protected:
	char underlying_data[sizeof(t_type)];
};
