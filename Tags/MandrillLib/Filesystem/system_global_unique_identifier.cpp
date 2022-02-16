#include "mandrilllib-private-pch.h"


template<> void byteswap_inplace(s_system_global_unique_identifier& value)
{
	byteswap_inplace(value.data);
}