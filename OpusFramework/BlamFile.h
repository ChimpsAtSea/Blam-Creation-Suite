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

struct s_blamfile_level_chunk_flags
{
	uint32_t __bit0 : 1;
	uint32_t __bit1 : 1;
	uint32_t m_isVisible : 1;
	uint32_t m_isTheatreEnabled : 1;
	uint32_t m_isMainMenu : 1;
	uint32_t m_isCampaign : 1;
	uint32_t m_isMultiplayer : 1;
	uint32_t m_isDLC : 1;
	uint32_t __bit8 : 1;
	uint32_t __bit9 : 1;
	uint32_t m_isFirefight : 1;
	uint32_t m_isCinematic : 1;
	uint32_t __bit12 : 1;
	uint32_t __bit13 : 1;
	uint32_t __bit14 : 1;
	uint32_t __bit15 : 1;
	uint32_t __bit16 : 1;
	uint32_t __bit17 : 1;
	uint32_t __bit18 : 1;
	uint32_t __bit19 : 1;
	uint32_t __bit20 : 1;
	uint32_t __bit21 : 1;
	uint32_t __bit22 : 1;
	uint32_t __bit23 : 1;
	uint32_t __bit24 : 1;
	uint32_t __bit25 : 1;
	uint32_t __bit26 : 1;
	uint32_t __bit27 : 1;
	uint32_t __bit28 : 1;
	uint32_t __bit29 : 1;
	uint32_t __bit30 : 1;
	uint32_t __bit31 : 1;
};

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
static constexpr size_t s_blamfile_level_chunk_size = sizeof(s_blamfile_level_chunk);
static_assert(s_blamfile_level_chunk_size == 0xCC98, "s_blamfile_level_chunk is incorrect size");
#pragma pack(pop)

