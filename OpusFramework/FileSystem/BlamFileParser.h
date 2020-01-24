#pragma once

class BlamFileParser
{
public:
	BlamFileParser(char* pBlamFileData);
	template<typename T>
	T* GetFirstChunkByType()
	{
		s_blamfile_header* pResult = GetFirstChunkByType(T::kChunkType);
		return static_cast<T*>(pResult);
	}

	s_blamfile_header* GetFirstChunkByType(blamfile_chunk_type chunkType);
	inline bool IsLittleEndian() const { return m_isLittleEndian; }
private:

	s_blamfile_header* getFirstChunkByTypeImpl(blamfile_chunk_type chunk_type);
	bool m_isLittleEndian;
	std::vector<s_blamfile_header*> m_chunks;
};

