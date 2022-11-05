#pragma once

class c_tag_resource_exploded_chunk : public c_typed_chunk<'tgrc', true>
{
public:
	BCS_SHARED c_tag_resource_exploded_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_resource_exploded_chunk();
	BCS_SHARED virtual BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override;
};
