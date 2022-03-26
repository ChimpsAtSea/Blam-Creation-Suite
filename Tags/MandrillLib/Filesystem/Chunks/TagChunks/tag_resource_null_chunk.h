#pragma once

class c_tag_resource_null_chunk : public c_typed_chunk<'tg\0c', false>
{
public:
	c_tag_resource_null_chunk(c_chunk& parent);
	~c_tag_resource_null_chunk();
	virtual BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override;
	virtual void log_signature() const override;
};
