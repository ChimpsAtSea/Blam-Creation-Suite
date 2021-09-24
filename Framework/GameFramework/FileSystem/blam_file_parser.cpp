#include "gameframework-private-pch.h"

c_blam_file_parser::c_blam_file_parser(char* blam_file_data)
	:is_little_endian(false)
{
	char* current_map_info_data_position = blam_file_data;
	bool end_of_file_found = false;
	do
	{
		s_blamfile_header* chunk = reinterpret_cast<s_blamfile_header*>(current_map_info_data_position);

		switch (chunk->chunk_type)
		{
		case '_blf': is_little_endian = true;
		case bswap('_blf'):
			break;
			//case 'levl': is_little_endian = true;
			//case bswap('levl'):
			//{
			//	s_blamfile_level_chunk* plevel_chunk = static_cast<s_blamfile_level_chunk*>(chunk);
			//	int map_id = bswap_auto_endian(is_little_endian, plevel_chunk->map_id);
			//	console_write_line("MapInfoManager> ");
			//	break;
			//}
		case '_eof': is_little_endian = true;
		case bswap('_eof'):
			end_of_file_found = true;
			break;
		}
		int chunk_size = bswap_auto_endian(is_little_endian, chunk->chunk_size);
		current_map_info_data_position += chunk_size;

		chunks.emplace_back(chunk);

	} while (!end_of_file_found);

	console_write_line("BlamFileParser> Parsed %i chunks", static_cast<int>(chunks.size()));
}

s_blamfile_header* c_blam_file_parser::get_first_chunk_by_type_impl(blamfile_chunk_type chunk_type)
{
	for (s_blamfile_header*& pCurrentChunk : chunks)
	{
		if (pCurrentChunk->chunk_type == chunk_type)
		{
			return pCurrentChunk;
		}
	}

	return nullptr;
}

s_blamfile_header* c_blam_file_parser::get_first_chunk_by_type(blamfile_chunk_type chunk_type)
{
	s_blamfile_header* pResult = get_first_chunk_by_type_impl(chunk_type);
	if (pResult == nullptr)
	{
		pResult = get_first_chunk_by_type_impl(static_cast<blamfile_chunk_type>(bswap(chunk_type)));
	}
	return pResult;
}