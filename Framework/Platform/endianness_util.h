#pragma once

template<class T, std::size_t... N>
constexpr T bswap_impl(T i, std::index_sequence<N...>) { return ((((i >> (N * CHAR_BIT)) & (T)(unsigned char)(-1)) << ((sizeof(T) - 1 - N) * CHAR_BIT)) | ...); };
template<class T, class U = typename std::make_unsigned<T>::type>
constexpr U bswap(T i) { return bswap_impl<U>(i, std::make_index_sequence<sizeof(T)>{}); }
#define bswap_auto_endian(littleEndian, i) (littleEndian ? i : bswap(i))