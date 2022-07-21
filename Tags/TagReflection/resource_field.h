#pragma once

template<typename field_type, typename parent_type, uint32_t _field_index>
class h_resource_field
{
public:
	explicit h_resource_field() :
		value()
	{

	}

	~h_resource_field()
	{
		if (value)
		{
			delete value;
		}
	}

	const h_resource* operator=(const h_resource* new_value)
	{
		return value = new_value;
	}

	bool operator==(const h_resource* new_value) const
	{
		return value == new_value;
	}

	template<typename t_result>
	operator t_result() const
	{
		return static_cast<t_result>(value);
	}

public:
	h_resource* value;
};
