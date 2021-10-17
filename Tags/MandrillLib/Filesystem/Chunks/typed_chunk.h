#pragma once

class c_single_tag_file_layout_reader;
class c_single_tag_file_reader;

template<tag _signature>
class c_typed_chunk : 
	public c_chunk
{
public:
	static constexpr unsigned long signature = _signature;

	c_typed_chunk(void* chunk_data, c_chunk* parent) :
		c_chunk(chunk_data, parent)
	{

	}
};

template<tag _signature>
class c_typed_single_tag_file_reader_chunk :
	public c_typed_chunk<_signature>
{
public:
	c_single_tag_file_reader& reader;

	c_typed_single_tag_file_reader_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader) :
		c_typed_chunk<_signature>(chunk_data, &parent),
		reader(reader)
	{

	}
};
