#pragma once

template<typename T>
class c_virtual_tag_block
{
public:
	c_virtual_tag_block(c_cache_file& cache_file, s_tag_block_definition<T>& tag_block) :
		begin_pointer(nullptr),
		end_pointer(nullptr),
		cache_file(cache_file),
		tag_block(tag_block)
	{
		init();
	}

	T* begin() { return begin_pointer; }
	T* end() { return end_pointer; }

private:

	void init()
	{
		begin_pointer = cache_file.GetTagBlockData(tag_block);
		end_pointer = begin_pointer + tag_block.count;
	}

	T* begin_pointer;
	T* end_pointer;

	c_cache_file& cache_file;
	s_tag_block_definition<T>& tag_block;

};

