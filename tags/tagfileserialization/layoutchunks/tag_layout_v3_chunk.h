#pragma once

class c_tag_layout_v3_chunk : public c_typed_chunk<'tgly', true>
{
public:
	BCS_SHARED c_tag_layout_v3_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_layout_v3_chunk();
};
