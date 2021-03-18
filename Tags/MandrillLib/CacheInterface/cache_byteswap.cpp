#include "mandrilllib-private-pch.h"

template<> void byteswap<s_basic_buffer32>(s_basic_buffer32& value)
{
	byteswap(value.elements);
	byteswap(value.size);
}