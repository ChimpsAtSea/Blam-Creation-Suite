#pragma once

class c_string_data_chunk;
class c_single_tag_file_reader;
class c_single_tag_file_reader;

struct s_chunk_header_gen3
{
	uint32_t signature;
	uint32_t metadata;
	uint32_t chunk_size;
};

class c_chunk
{
public:
	c_chunk(tag signature, c_chunk* parent);
	virtual ~c_chunk();

	using t_chunk_child_iterator = c_chunk* const*;

	BCS_RESULT add_child(c_chunk& chunk);
	BCS_RESULT remove_child(c_chunk& chunk);
	BCS_RESULT get_children(c_chunk* const*& children, uint32_t& num_children);

	c_chunk* const* get_children_unsafe() const;
	c_chunk* get_child_unsafe(uint32_t index) const;
	c_chunk* get_child_by_signature_unsafe(tag signature, t_chunk_child_iterator* iterator = nullptr) const;
	c_chunk* get_child_by_signature_recursive_unsafe(tag signature, t_chunk_child_iterator* iterator = nullptr) const;

	const char* get_chunk_data_start() const;
	const char* get_chunk_data_end() const;

	virtual BCS_RESULT append_data(const void* data, uint32_t data_size);
	virtual BCS_RESULT set_data(const void* data, uint32_t data_size);
	virtual BCS_RESULT get_data(const void*& data, uint32_t& data_size);

	virtual BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);
	virtual BCS_RESULT read_chunk_header(void* userdata, const void* header_data);
	virtual BCS_RESULT read_child_chunks(void* userdata, bool use_read_only, const char* data = nullptr);
	virtual void write_chunk(c_high_level_tag_file_writer& tag_file_writer);
	virtual void write_chunk_data(c_high_level_tag_file_writer& tag_file_writer);
	virtual void write_child_chunks(c_high_level_tag_file_writer& tag_file_writer);
	virtual bool should_parse_children() const = 0;

	void log(c_tag_file_string_debugger* string_debugger = nullptr) const;
	void log_pad() const;
	virtual void log_signature() const;
	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const;

	template<typename t_chunk>
	t_chunk* get_child_by_type_unsafe() const
	{
		if (children)
		{
			for (c_chunk** children_iter = children; *children_iter; children_iter++)
			{
				if (t_chunk* child = dynamic_cast<t_chunk*>(*children_iter))
				{
					return child;
				}
			}
			for (c_chunk** children_iter = children; *children_iter; children_iter++)
			{
				c_chunk& child = **children_iter;
				if (t_chunk* child_search_result = child.get_child_by_type_unsafe<t_chunk>())
				{
					return child_search_result;
				}
			}
		}
		return nullptr;
	}

	template<typename t_chunk>
	t_chunk* get_child_unsafe(uint32_t index) const
	{
		return dynamic_cast<t_chunk*>(get_child_unsafe(index));
	}

//protected:

	c_chunk* parent;
	c_chunk** children;

	const void* chunk_data;
	uint32_t chunk_size;
	uint32_t metadata;
	tag signature;

	uint32_t is_read_only : 1;
	uint32_t is_big_endian : 1;
	uint32_t is_data_allocated : 1;
	uint32_t is_data_valid : 1;
	uint32_t depth : 16;
	uint32_t num_children;


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

	template<typename t_element, const int32_t k_maximum_count>
	void chunk_byteswap_inplace(t_element(&arr)[k_maximum_count])
	{
		if (is_big_endian)
		{
			byteswap_inplace(arr);
		}
	}

	template<typename t_element, const int32_t k_maximum_count>
	void chunk_byteswap_inplace(s_static_array<t_element, k_maximum_count>& arr)
	{
		if (is_big_endian)
		{
			byteswap_inplace(arr);
		}
	}

	template<typename t_chunk>
	uint32_t get_num_children_by_type_unsafe() const
	{
		uint32_t num_typed_children = 0;
		for (uint32_t child_index = 0; child_index < num_children; child_index++)
		{
			if (dynamic_cast<t_chunk>(children[child_index]))
			{
				num_typed_children++;
			}
		}
		return num_typed_children;
	}

private:
	static c_chunk* const children_list_empty[];
};
static constexpr size_t k_chunk_size = sizeof(c_chunk);
