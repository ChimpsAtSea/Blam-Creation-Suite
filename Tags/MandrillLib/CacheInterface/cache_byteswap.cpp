#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace<s_basic_buffer32>(s_basic_buffer32& value)
{
	byteswap_inplace(value.elements);
	byteswap_inplace(value.size);
}