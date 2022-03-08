#pragma once

class c_tag_resource_exploded_chunk : public c_typed_chunk<'tgrc', false>
{
public:
	c_tag_resource_exploded_chunk(c_chunk& parent);
	~c_tag_resource_exploded_chunk();
};
