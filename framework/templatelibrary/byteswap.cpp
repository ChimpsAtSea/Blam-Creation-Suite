#include "templatelibrary-private-pch.h"

template<> BCS_SHARED void byteswap_inplace<unsigned char>(unsigned char& value)
{

}

template<> BCS_SHARED void byteswap_inplace<unsigned short>(unsigned short& value)
{
	value = _byteswap_ushort(value);
}

template<> BCS_SHARED void byteswap_inplace<unsigned int>(unsigned int& value)
{
	static_assert(sizeof(value) == sizeof(unsigned long));
	value = _byteswap_ulong(value);
}

template<> BCS_SHARED void byteswap_inplace<unsigned long>(unsigned long& value)
{
	value = _byteswap_ulong(value);
}

template<> BCS_SHARED void byteswap_inplace<uint64_t>(uint64_t& value)
{
	value = _byteswap_uint64(value);
}

template<> BCS_SHARED void byteswap_inplace<char>(char& value)
{

}

template<> BCS_SHARED void byteswap_inplace<short>(short& value)
{
	value = static_cast<short>(_byteswap_ushort(static_cast<unsigned short>(value)));
}

template<> BCS_SHARED void byteswap_inplace<long>(long& value)
{
	value = static_cast<long>(_byteswap_ulong(static_cast<unsigned long>(value)));
}

template<> BCS_SHARED void byteswap_inplace<int>(int& value)
{
	static_assert(sizeof(value) == sizeof(long));
	value = _byteswap_ulong(value);
}

template<> BCS_SHARED void byteswap_inplace<int64_t>(int64_t& value)
{
	value = static_cast<int64_t>(_byteswap_uint64(static_cast<uint64_t>(value)));
}

template<> BCS_SHARED void byteswap_inplace<bool>(bool& value)
{

}
