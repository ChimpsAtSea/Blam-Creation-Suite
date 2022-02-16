#pragma once

class c_string_data_chunk;
class c_single_tag_file_reader;
class c_single_tag_file_reader;

class c_chunk
{
public:
	void* const chunk_data;
	c_chunk** children;
	//c_chunk* parent;

	unsigned long is_big_endian : 1;
	unsigned long children_fast_allocation : 1;
	unsigned long depth : 16;
	tag signature;
	unsigned long metadata;
	unsigned long chunk_size;

	char* chunk_data_begin;
	char* const chunk_data_end;

	c_chunk(void* chunk_data, c_chunk* parent, bool is_big_endian);
	virtual ~c_chunk();

	void log(c_single_tag_file_layout_reader* layout_reader = nullptr) const;
	void log_pad() const;
	void log_signature() const;
	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const;

	c_chunk* find_first_chunk(tag type) const;
	c_chunk* get_chunk(unsigned long index) const;

	template<typename t_chunk>
	t_chunk* find_first_chunk() const
	{
		for (c_chunk** children_iter = children; children_iter && *children_iter; children_iter++)
		{
			if (t_chunk* child = dynamic_cast<t_chunk*>(*children_iter))
			{
				return child;
			}
		}
		for (c_chunk** children_iter = children; children_iter && *children_iter; children_iter++)
		{
			c_chunk& child = **children_iter;
			if (t_chunk* child_search_result = child.find_first_chunk<t_chunk>())
			{
				return child_search_result;
			}
		}
		return nullptr;
	}

	template<typename t_chunk>
	t_chunk* get_chunk(unsigned long index) const
	{
		return static_cast<t_chunk*>(get_chunk(index));
	}

	template<typename t_element>
	t_element chunk_byteswap(t_element value)
	{
		return is_big_endian ? byteswap(value) : value;
	}

	template<typename t_element>
	void chunk_byteswap_inplace(t_element& value)
	{
		if (is_big_endian)
		{
			byteswap_inplace(value);
		}
	}

	template<typename t_element, const long k_maximum_count>
	void chunk_byteswap_inplace(t_element(&arr)[k_maximum_count])
	{
		if (is_big_endian)
		{
			byteswap_inplace(arr);
		}
	}

	template<typename t_element, const long k_maximum_count>
	void chunk_byteswap_inplace(s_static_array<t_element, k_maximum_count>& arr)
	{
		if (is_big_endian)
		{
			byteswap_inplace(arr);
		}
	}

	void parse_children(void* userdata, char* data = nullptr, bool force_fast = false);

protected:
	c_chunk** create_child_chunks_fast(char* data, void* userdata);
	c_chunk** create_child_chunks_slow(char* data, void* userdata);
};
static constexpr size_t k_chunk_size = sizeof(c_chunk);
