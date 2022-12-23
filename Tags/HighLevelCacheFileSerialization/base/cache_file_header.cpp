#include "highlevelcachefileserialization-private-pch.h"

template<> void byteswap_inplace<s_cache_file_header>(s_cache_file_header& header)
{
	byteswap_inplace(header.header_signature);
	byteswap_inplace(header.file_version);
	byteswap_inplace(header.file_length);
	byteswap_inplace(header.file_compressed_length);
}
