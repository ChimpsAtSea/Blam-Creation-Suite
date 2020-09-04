#pragma once

struct s_blamfile_header
{
public:
	static constexpr blamfile_chunk_type kChunkType = blamfile_chunk_type::Blamfile;

	blamfile_chunk_type chunk_type;
	int chunk_size;
};
