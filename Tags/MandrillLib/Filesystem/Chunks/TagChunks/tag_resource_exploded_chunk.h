#pragma once

class c_tag_resource_exploded_chunk : public c_typed_single_tag_file_reader_chunk<'tgrc', false>
{
public:
	c_tag_resource_exploded_chunk(c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_resource_exploded_chunk();
};
