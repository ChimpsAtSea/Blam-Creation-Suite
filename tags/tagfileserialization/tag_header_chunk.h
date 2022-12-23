#pragma once

class c_tag_header_chunk : public c_typed_chunk<'tag!', true>
{
public:
	BCS_SHARED c_tag_header_chunk();
};

