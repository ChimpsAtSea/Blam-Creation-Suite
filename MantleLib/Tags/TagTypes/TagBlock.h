#pragma once

template<typename value_type = void>
class s_tag_block_definition
{
public:
	using t_value = value_type;


	uint32_t count;
	uint32_t address;
	uint32_t definition_address;

#ifdef __INTELLISENSE__
	t_value* begin();
	t_value* end();
	t_value& operator[](size_t index) const;
#endif
};
