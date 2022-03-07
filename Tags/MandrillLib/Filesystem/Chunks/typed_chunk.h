#pragma once

class c_single_tag_file_layout_reader;
class c_single_tag_file_reader;
class c_high_level_tag_file_writer;

template<tag _signature, bool _should_parse_children>
class c_typed_chunk : 
	public c_chunk
{
public:
	static constexpr tag k_signature = _signature;
	static constexpr bool k_should_parse_children = _should_parse_children;

	c_typed_chunk(c_chunk* parent) :
		c_chunk(_signature, parent)
	{

	}

	virtual BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
	{
		return c_chunk::read_chunk(userdata, data, use_read_only, parse_children && k_should_parse_children);
	}
};

template<tag _signature, bool _should_parse_children>
class c_typed_single_tag_file_reader_chunk :
	public c_typed_chunk<_signature, _should_parse_children>
{
public:
	c_single_tag_file_reader& reader;

	c_typed_single_tag_file_reader_chunk(c_chunk& parent, c_single_tag_file_reader& reader) :
		c_typed_chunk<_signature, _should_parse_children>(&parent),
		reader(reader)
	{

	}
};
