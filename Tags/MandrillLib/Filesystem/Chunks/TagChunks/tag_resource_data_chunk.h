#pragma once

class c_tag_resource_data_chunk : public c_typed_chunk<'tgdt', false>
{
public:
	c_tag_resource_data_chunk(c_chunk& parent);
	~c_tag_resource_data_chunk();
};
