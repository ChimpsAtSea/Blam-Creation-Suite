#pragma once

class c_tag_resource_exploded_chunk : public c_typed_chunk<'tgrc', true>
{
public:
	c_tag_resource_exploded_chunk(c_chunk& parent);
	~c_tag_resource_exploded_chunk();
	virtual BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override;
};
