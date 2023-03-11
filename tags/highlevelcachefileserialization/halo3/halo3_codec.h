#pragma once

enum e_halo3_compression_codec : char
{
	_halo3_compression_uncompressed,
	_halo3_compression_xdkcompress
};

extern blofeld::s_tag_persistent_identifier k_halo3_xdkcompress_codec_identifier;

int h3_codec_inflate_lzx_xbox360(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
int h3_codec_inflate(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
