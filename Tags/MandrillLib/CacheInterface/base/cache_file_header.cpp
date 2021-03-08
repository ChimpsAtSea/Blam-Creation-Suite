#include "mandrilllib-private-pch.h"

template<> void byteswap<s_cache_file_header>(s_cache_file_header& header)
{
	byteswap(header.header_signature);
	byteswap(header.file_version);
	byteswap(header.file_length);
	byteswap(header.file_compressed_length);
}
