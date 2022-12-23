#pragma once

class c_exploded_dependencies_chunk : public c_typed_chunk<'expl', false>
{
public:
	BCS_SHARED c_exploded_dependencies_chunk(c_chunk& parent);
};
