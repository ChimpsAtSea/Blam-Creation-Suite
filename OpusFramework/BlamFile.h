#pragma once

#pragma pack(push, 1)

enum blamfile_chunk_type : unsigned int
{
	Blamfile = '_blf',
	EndOfFile = '_eof',
	Level = 'levl'
};

struct s_blamfile_header
{
public:
	static constexpr blamfile_chunk_type kChunkType = blamfile_chunk_type::Blamfile;

	blamfile_chunk_type m_chunkType;
	int m_chunkSize;
};

struct s_blamfile_level_chunk : s_blamfile_header
{
public:
	static constexpr blamfile_chunk_type kChunkType = blamfile_chunk_type::Level;
private:
	int __unknown0;
public:
	int m_mapID;
	char __unknown10[0x5];
	wchar_t m_levelName[12][0x20];
	wchar_t m_levelDescription[1];
	// dont know how to parse rest of struct
	char __unknown[0xC981];
};
static_assert(sizeof(s_blamfile_level_chunk) == 0xCC98, "s_blamfile_level_chunk is incorrect size");
#pragma pack(pop)

