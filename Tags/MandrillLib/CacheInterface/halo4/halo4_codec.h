#pragma once

enum e_compression_codec : char
{
	_compression_uncompressed,
	_compression_xdkcompress
};

extern blofeld::s_tag_persistent_identifier k_xdkcompress_codec_identifier;

int codec_inflate_lzx_xbox360(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
int codec_inflate(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size);
