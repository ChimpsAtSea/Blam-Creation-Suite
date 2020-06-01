#pragma once

template<typename t_value>
class c_virtual_tag_block
{
public:
	c_virtual_tag_block(c_cache_file& cache_file, c_tag_interface& tag_interface, c_typed_tag_block<t_value>& tag_block) :
		address(tag_block.address),
		count(tag_block.count),
		definition_address(tag_block.definition_address),
		begin_pointer(nullptr),
		end_pointer(nullptr),
		cache_file(cache_file),
		tag_interface(tag_interface),
		tag_block(tag_block)
	{
		init();
	}

	t_value* begin() { return begin_pointer; }
	t_value* end() { return end_pointer; }

	decltype(s_tag_block::address)& address;
	decltype(s_tag_block::count)& count;
	decltype(s_tag_block::definition_address)& definition_address;


	t_value& operator[](size_t index) const { return begin_pointer[index]; }

private:

	void init()
	{
		if (tag_interface.get_data() != nullptr)
		{
			begin_pointer = cache_file.get_tag_block_data(tag_block);
			end_pointer = begin_pointer + tag_block.count;
		}
	}

	t_value* begin_pointer;
	t_value* end_pointer;

	c_cache_file& cache_file;
	c_tag_interface& tag_interface;
	c_typed_tag_block<t_value>& tag_block;
};

