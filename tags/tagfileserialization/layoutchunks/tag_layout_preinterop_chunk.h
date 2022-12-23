#pragma once

class c_tag_layout_preinterop_chunk : public c_typed_chunk<'tgly', true>
{
public:
	BCS_SHARED c_tag_layout_preinterop_chunk(c_chunk& parent);
};
