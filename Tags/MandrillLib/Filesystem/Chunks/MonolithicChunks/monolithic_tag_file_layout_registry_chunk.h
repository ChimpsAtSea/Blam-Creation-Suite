#pragma once

class c_monolithic_tag_file_layout_registry_chunk : public c_typed_chunk<'mreg'>
{
public:
	c_monolithic_tag_file_layout_registry_chunk(void* chunk_data, c_chunk& parent);
};
