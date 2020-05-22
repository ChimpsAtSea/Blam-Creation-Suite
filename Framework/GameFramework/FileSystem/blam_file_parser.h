#pragma once

class c_blam_file_parser
{
public:
	c_blam_file_parser(char* pBlamFileData);
	template<typename T>
	T* get_first_chunk_by_type()
	{
		s_blamfile_header* pResult = get_first_chunk_by_type(T::kChunkType);
		return static_cast<T*>(pResult);
	}

	s_blamfile_header* get_first_chunk_by_type(blamfile_chunk_type chunkType);
	inline bool is_little_endian() const { return m_isLittleEndian; }
private:

	s_blamfile_header* getFirstChunkByTypeImpl(blamfile_chunk_type chunk_type);
	bool m_isLittleEndian;
	std::vector<s_blamfile_header*> m_chunks;
};

