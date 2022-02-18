#include "templatelibrary-private-pch.h"

template<> BCS_DEBUG_API void byteswap_inplace<unsigned char>(unsigned char& value)
{

}

template<> BCS_DEBUG_API void byteswap_inplace<unsigned short>(unsigned short& value)
{
	value = _byteswap_ushort(value);
}

template<> BCS_DEBUG_API void byteswap_inplace<unsigned int>(unsigned int& value)
{
	static_assert(sizeof(value) == sizeof(unsigned long));
	value = _byteswap_ulong(value);
}

template<> BCS_DEBUG_API void byteswap_inplace<unsigned long>(unsigned long& value)
{
	value = _byteswap_ulong(value);
}

template<> BCS_DEBUG_API void byteswap_inplace<unsigned long long>(unsigned long long& value)
{
	value = _byteswap_uint64(value);
}

template<> BCS_DEBUG_API void byteswap_inplace<char>(char& value)
{

}

template<> BCS_DEBUG_API void byteswap_inplace<short>(short& value)
{
	value = static_cast<short>(_byteswap_ushort(static_cast<unsigned short>(value)));
}

template<> BCS_DEBUG_API void byteswap_inplace<long>(long& value)
{
	value = static_cast<long>(_byteswap_ulong(static_cast<unsigned long>(value)));
}

template<> BCS_DEBUG_API void byteswap_inplace<int>(int& value)
{
	static_assert(sizeof(value) == sizeof(long));
	value = _byteswap_ulong(value);
}

template<> BCS_DEBUG_API void byteswap_inplace<long long>(long long& value)
{
	value = static_cast<long long>(_byteswap_uint64(static_cast<unsigned long long>(value)));
}

template<> BCS_DEBUG_API void byteswap_inplace<bool>(bool& value)
{

}
