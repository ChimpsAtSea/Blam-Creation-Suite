#pragma once

class c_tag_dependency_chunk : public c_typed_chunk<'tree', true>
{
public:
	BCS_SHARED c_tag_dependency_chunk(c_chunk& parent);
};
