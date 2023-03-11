#include "highlevelcachefileserialization-private-pch.h"

blofeld::s_tag_persistent_identifier k_halo4_xdkcompress_codec_identifier = { 0x7EDA2AB5, 0x80CF4906, 0x7343A8BD, 0xF0C7B36C };


int h4_codec_inflate_lzx_xbox360(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size)
{
	// xbox 360 sdk
	/*{
		XMEMDECOMPRESSION_CONTEXT context = NULL;
		HRESULT hr;
		if (FAILED(hr = XMemCreateDecompressionContext(XMEMCODEC_DEFAULT, NULL, 0, &context)))
		{
			return -1;
		}

		SIZE_T destination_size = uncompressed_buffer_size;
		hr = XMemDecompress(context, uncompressed_buffer, &destination_size, compressed_buffer, compressed_buffer_size);

		XMemDestroyDecompressionContext(context);

		if (FAILED(hr))
		{
			return -1;
		}

		return static_cast<long>(destination_size);
	}*/


	// #TODO: safety, check uncompressed_buffer_size and ensure not doing nasty things

	size_t remaining_input_bytes = 0;
	unsigned short compressed_input_size = 0;
	unsigned short uncompressed_output_size = 0;
	uint32_t bytes_decoded = 0;

	if (compressed_buffer_size > 5)
	{
		remaining_input_bytes = compressed_buffer_size - 5;
	}

	const unsigned char* compressed_buffer_position = static_cast<const unsigned char*>(compressed_buffer);
	unsigned char* uncompressed_buffer_position = static_cast<unsigned char*>(uncompressed_buffer);

	c_lzx_decoder decoder = { 17 };

	for (; remaining_input_bytes > 0; remaining_input_bytes -= compressed_input_size)
	{
		if (*compressed_buffer_position == 0xFFui8)
		{
			uncompressed_output_size = _byteswap_ushort(*reinterpret_cast<const unsigned short*>(compressed_buffer_position + 1));
			compressed_input_size = _byteswap_ushort(*reinterpret_cast<const unsigned short*>(compressed_buffer_position + 3));

			remaining_input_bytes -= 5;
			compressed_buffer_position += 5;

			if (compressed_input_size < remaining_input_bytes)
			{
				remaining_input_bytes = compressed_input_size;
			}
		}
		else                                        // 16bit header
		{
			uncompressed_output_size = 0x8000ui16;
			compressed_input_size = _byteswap_ushort(*reinterpret_cast<const unsigned short*>(compressed_buffer_position));

			remaining_input_bytes -= 2;
			compressed_buffer_position += 2;
		}

		// #TODO: make sure we're overwriting into invalid memory

		decoder.decompress(compressed_buffer_position, compressed_input_size, uncompressed_buffer_position, uncompressed_output_size);

		compressed_buffer_position += compressed_input_size;
		uncompressed_buffer_position += uncompressed_output_size;
		bytes_decoded += uncompressed_output_size;
	}
	return static_cast<long>(bytes_decoded);
}

int h4_codec_inflate(const void* compressed_buffer, size_t compressed_buffer_size, void* uncompressed_buffer, size_t uncompressed_buffer_size)
{
	z_stream stream{};
	stream.avail_out = static_cast<uInt>(uncompressed_buffer_size);
	stream.next_out = (Bytef*)uncompressed_buffer;
	stream.avail_in = static_cast<uInt>(compressed_buffer_size);
	stream.next_in = (Bytef*)compressed_buffer;
	//int inflateInitResult = inflateInit2(&stream, -15);
	int inflateInitResult = inflateInit(&stream);
	ASSERT(inflateInitResult >= Z_OK);
	int inflateResult = inflate(&stream, Z_SYNC_FLUSH);
	ASSERT(inflateResult >= Z_OK);
	int inflateEndResult = inflateEnd(&stream);
	ASSERT(inflateEndResult >= Z_OK);

	return Z_OK;


	//	z_stream strm = { };
	//	strm.total_in = strm.avail_in = source_size;
	//	strm.total_out = strm.avail_out = destination_size;
	//	strm.next_in = static_cast<const Bytef*>(source);
	//	strm.next_out = static_cast<Bytef*>(destination);
	//
	//	strm.zalloc = Z_NULL;
	//	strm.zfree = Z_NULL;
	//	strm.opaque = Z_NULL;
	//
	//	int err;
	//	if ((err = inflateInit2(&strm, -15)) < 0) //15 window bits, and the +32 tells zlib to to detect if using gzip or zlib
	//	{
	//		goto end;
	//	}
	//	if ((err = inflate(&strm, Z_SYNC_FLUSH)) < 0)
	//	{
	//		goto end;
	//	}
	//end:;
	//	inflateEnd(&strm);
	//	return err;
}

