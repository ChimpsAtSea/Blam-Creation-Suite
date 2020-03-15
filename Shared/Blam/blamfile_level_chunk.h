#pragma once

#pragma pack(push, 1)
struct s_blamfile_level_chunk : s_blamfile_header
{
public:
	static constexpr blamfile_chunk_type kChunkType = blamfile_chunk_type::Level;
private:
	int __unknown0;
public:
	int m_mapID;
	s_blamfile_level_chunk_flags m_flags;
	wchar_t m_levelName[12][0x20];
	wchar_t m_levelDescription[12][0x80];
	// dont know how to parse rest of struct
	char m_imageFileName[0x100];
	char m_mapFileName[0x100];
	char __unknown[0xBB84];
};
constexpr size_t s_blamfile_level_chunk_size = sizeof(s_blamfile_level_chunk);
static_assert(s_blamfile_level_chunk_size == 0xCC98, "s_blamfile_level_chunk is incorrect size");
#pragma pack(pop)