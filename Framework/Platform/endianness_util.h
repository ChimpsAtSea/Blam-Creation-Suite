#pragma once

template<class T, std::size_t... N>
constexpr T bswap_impl(T i, std::index_sequence<N...>) { return ((((i >> (N * CHAR_BIT)) & (T)(unsigned char)(-1)) << ((sizeof(T) - 1 - N) * CHAR_BIT)) | ...); };
template<class T, class U = typename std::make_unsigned<T>::type>
constexpr U bswap(T i) { return bswap_impl<U>(i, std::make_index_sequence<sizeof(T)>{}); }
#define bswap_auto_endian(little_endian, i) (little_endian ? i : bswap(i))

template<typename T>
struct bigendian_type
{
public:
	operator T() const
	{
		T const& raw_value = *reinterpret_cast<const T*>(this);
		if constexpr (sizeof(T) == 1)
		{
			unsigned char unsigned8 = *reinterpret_cast<const unsigned char*>(this);
			return *reinterpret_cast<T*>(&unsigned8);
		}

		if constexpr (sizeof(T) == 2)
		{
			unsigned short unsigned16 = _byteswap_ushort(*reinterpret_cast<const unsigned short*>(this));
			return *reinterpret_cast<T*>(&unsigned16);
		}

		if constexpr (sizeof(T) == 4)
		{
			unsigned long unsigned32 = _byteswap_ulong(*reinterpret_cast<const unsigned long*>(this));
			return *reinterpret_cast<T*>(&unsigned32);
		}

		if constexpr (sizeof(T) == 8)
		{
			unsigned __int64 unsigned64 = _byteswap_uint64(*reinterpret_cast<const unsigned char*>(this));
			return *reinterpret_cast<T*>(&unsigned64);
		}

		throw;
	}
	T value;
};

using buint8_t = bigendian_type<uint8_t>;
using buint16_t = bigendian_type<uint16_t>;
using buint32_t = bigendian_type<uint32_t>;
using buint64_t = bigendian_type<uint64_t>;
using bint8_t = bigendian_type<int8_t>;
using bint16_t = bigendian_type<int16_t>;
using bint32_t = bigendian_type<int32_t>;
using bint64_t = bigendian_type<int64_t>;

using buchar = bigendian_type<unsigned char>;
using bushort = bigendian_type<unsigned short>;
using bulong = bigendian_type<unsigned long>;
using bulonglong = bigendian_type<unsigned long long>;
using bchar = bigendian_type<char>;
using bshort = bigendian_type<short>;
using blong = bigendian_type<long>;
using blonglong = bigendian_type<long long>;

template<typename T>
using bptr32 = bigendian_type<unsigned long>;

template<typename T>
using bptr64 = bigendian_type<unsigned long long>;
