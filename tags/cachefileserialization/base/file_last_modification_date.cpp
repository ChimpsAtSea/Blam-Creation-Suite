#include "cachefileserialization-private-pch.h"

template<> BCS_SHARED void byteswap_inplace(s_file_last_modification_date& value)
{
	byteswap_inplace(value.filetime_low);
	byteswap_inplace(value.filetime_high);
}
