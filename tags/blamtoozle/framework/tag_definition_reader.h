#pragma once

class c_blamtoozle_tag_definition_reader
{
public:
	c_blamtoozle_tag_definition_reader();
	c_blamtoozle_tag_definition_reader(const c_blamtoozle_tag_definition_reader&) = delete;
	c_blamtoozle_tag_definition_reader(c_blamtoozle_tag_definition_reader&&) = delete;
	virtual ~c_blamtoozle_tag_definition_reader();

	virtual const char* va_to_pointer(ptr64 address) = 0;
	virtual const char* pa_to_pointer(ptr64 address) = 0;

	template<typename t_type>
	const t_type* va_to_pointer2(ptr64 address)
	{
		return reinterpret_cast<const t_type*>(va_to_pointer(address));
	}

	template<typename t_type>
	const t_type* pa_to_pointer2(ptr64 address)
	{
		return reinterpret_cast<const t_type*>(pa_to_pointer(address));
	}
};
