#pragma once

class c_monolithic_tag_file_layout_registry_chunk : public c_typed_chunk<'mreg', false>
{
public:
	c_monolithic_tag_file_layout_registry_chunk(c_chunk& parent);
};
