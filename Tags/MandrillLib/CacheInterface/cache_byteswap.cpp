#include "mandrilllib-private-pch.h"

template<> void byteswap<unsigned short>(unsigned short& value)
{
	value = _byteswap_ushort(value);
}

template<> void byteswap<unsigned long>(unsigned long& value)
{
	value = _byteswap_ulong(value);
}

template<> void byteswap<unsigned long long>(unsigned long long& value)
{
	value = _byteswap_uint64(value);
}

template<> void byteswap<short>(short& value)
{
	value = static_cast<short>(_byteswap_ushort(static_cast<unsigned short>(value)));
}

template<> void byteswap<long>(long& value)
{
	value = static_cast<long>(_byteswap_ulong(static_cast<unsigned long>(value)));
}

template<> void byteswap<long long>(long long& value)
{
	value = static_cast<long long>(_byteswap_uint64(static_cast<unsigned long long>(value)));
}




