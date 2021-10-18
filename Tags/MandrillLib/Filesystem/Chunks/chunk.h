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

	tag signature;
	unsigned long metadata;
	unsigned long chunk_size;
	unsigned long depth : 16;
	unsigned long children_fast_allocation : 1;

	char* chunk_data_begin;
	char* const chunk_data_end;

	c_chunk(void* chunk_data, c_chunk* parent);
	virtual ~c_chunk();

	void log(c_single_tag_file_layout_reader& layout_reader) const;
	void log_pad() const;
	void log_signature() const;
	virtual void log_impl(c_single_tag_file_layout_reader& layout_reader) const;

	c_chunk* find_first_chunk(tag type) const;
	c_chunk* get_chunk(unsigned long index) const;

	template<typename t_chunk>
	t_chunk* find_first_chunk() const
	{
		return static_cast<t_chunk*>(find_first_chunk(t_chunk::signature));
	}

	template<typename t_chunk>
	t_chunk* get_chunk(unsigned long index) const
	{
		return static_cast<t_chunk*>(get_chunk(index));
	}

	void parse_children(void* userdata, char* data = nullptr, bool force_fast = false);

protected:
	c_chunk** create_child_chunks_fast(char* data, void* userdata);
	c_chunk** create_child_chunks_slow(char* data, void* userdata);
};
static constexpr size_t k_chunk_size = sizeof(c_chunk);
