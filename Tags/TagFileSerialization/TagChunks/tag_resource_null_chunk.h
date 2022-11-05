#pragma once

class c_tag_resource_null_chunk : public c_typed_chunk<'tg\0c', false>
{
public:
	BCS_SHARED c_tag_resource_null_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_resource_null_chunk();
	BCS_SHARED virtual BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override;
	BCS_SHARED virtual void log_signature() const override;
};
