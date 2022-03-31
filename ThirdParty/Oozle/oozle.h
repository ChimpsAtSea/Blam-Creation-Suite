#pragma once

typedef unsigned char byte;

int Kraken_Decompress(const byte* src, size_t src_len, byte* dst, size_t dst_len);
