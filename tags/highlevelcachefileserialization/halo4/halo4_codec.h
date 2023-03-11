#pragma once

enum e_halo4_compression_codec : char
{
	_halo4_compression_uncompressed,
	_halo4_compression_xdkcompress
};

extern blofeld::s_tag_persistent_identifier k_halo4_xdkcompress_codec_identifier;

int h4_codec_inflate_lzx_xbox360(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
int h4_codec_inflate(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
