#pragma once

template<typename t_value>
class c_virtual_tag_block
{
public:
	c_virtual_tag_block(c_cache_file& cache_file, s_tag_block_definition<t_value>& tag_block) :
		address(tag_block.address),
		count(tag_block.count),
		definition_address(tag_block.definition_address),
		begin_pointer(nullptr),
		end_pointer(nullptr),
		cache_file(cache_file),
		tag_block(tag_block)
	{
		init();
	}

	t_value* begin() { return begin_pointer; }
	t_value* end() { return end_pointer; }

	decltype(s_tag_block_definition<>::address)& address;
	decltype(s_tag_block_definition<>::count)& count;
	decltype(s_tag_block_definition<>::definition_address)& definition_address;


	t_value& operator[](size_t index) const { return begin_pointer[index]; }

private:

	void init()
	{
		begin_pointer = cache_file.GetTagBlockData(tag_block);
		end_pointer = begin_pointer + tag_block.count;
	}

	t_value* begin_pointer;
	t_value* end_pointer;

	c_cache_file& cache_file;
	s_tag_block_definition<t_value>& tag_block;
};

