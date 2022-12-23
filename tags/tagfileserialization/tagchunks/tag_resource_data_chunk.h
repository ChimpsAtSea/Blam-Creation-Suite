#pragma once

class c_tag_resource_data_chunk : public c_typed_chunk<'tgdt', false>
{
public:
	BCS_SHARED c_tag_resource_data_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_resource_data_chunk();
};
