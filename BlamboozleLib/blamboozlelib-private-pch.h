#pragma once

#include <Shared/shared-public-pch.h>
#include <SymbolsLib/symbolslib-public-pch.h>
#include <OpusFramework/opusframework-public-pch.h>

#include "blamboozlelib-public-pch.h"

// #TODO: Common
struct tag_group
{
	union
	{
		uint32_t value;
		char name[4];
	};
};

template<typename T>
struct bigendian_integer
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
private:
	T value;
};

using buint8_t = bigendian_integer<uint8_t>;
using buint16_t = bigendian_integer<uint16_t>;
using buint32_t = bigendian_integer<uint32_t>;
using buint64_t = bigendian_integer<uint64_t>;
using bint8_t = bigendian_integer<int8_t>;
using bint16_t = bigendian_integer<int16_t>;
using bint32_t = bigendian_integer<int32_t>;
using bint64_t = bigendian_integer<int64_t>;
using btag_group = bigendian_integer<tag_group>;
template<typename T>
using bpointer32 = bigendian_integer<uint32_t>;

#include "halo5/halo5_forge.h"
#include "halo4/halo4.h"


