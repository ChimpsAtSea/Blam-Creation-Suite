#pragma once

class c_blam_file_parser
{
public:
	c_blam_file_parser(char* blam_file_data);

	template<typename T>
	T* get_first_chunk_by_type()
	{
		s_blamfile_header* pResult = get_first_chunk_by_type(T::kChunkType);
		return static_cast<T*>(pResult);
	}

	s_blamfile_header* get_first_chunk_by_type(blamfile_chunk_type chunk_type);

	inline bool get_is_little_endian() const { return is_little_endian; }

private:

	s_blamfile_header* get_first_chunk_by_type_impl(blamfile_chunk_type chunk_type);
	bool is_little_endian;
	std::vector<s_blamfile_header*> chunks;
};

