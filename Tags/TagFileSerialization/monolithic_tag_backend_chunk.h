#pragma once

class c_monolithic_tag_backend_chunk : public c_typed_chunk<'tgin', true>
{
public:
	BCS_SHARED c_monolithic_tag_backend_chunk();
	BCS_SHARED ~c_monolithic_tag_backend_chunk();
};
