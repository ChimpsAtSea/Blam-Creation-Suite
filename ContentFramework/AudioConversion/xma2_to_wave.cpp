#include "audioconversion-private-pch.h"

BCS_RESULT find_riff_chunk(
	long search_chunk_type, 
	const void* riff_data, 
	unsigned long long riff_data_size,
	void*& out_chunk_data, 
	long& out_chunk_data_size)
{
	BCS_RESULT rs = BCS_E_NOT_FOUND;

	unsigned char* current_read_position = static_cast<unsigned char*>(const_cast<void*>(riff_data));
	unsigned char* end_read_position = current_read_position + riff_data_size;

	while (current_read_position < end_read_position)
	{
#define remaining_bytes (end_read_position - current_read_position)

		long chunk_type;
		if (remaining_bytes < sizeof(chunk_type)) // not enough data to read the chunk id
		{
			return BCS_E_FAIL;
		}
		chunk_type = byteswap(*reinterpret_cast<decltype(chunk_type)*>(current_read_position));
		current_read_position += sizeof(chunk_type);

		long chunk_size;
		if (remaining_bytes < sizeof(chunk_size)) // not enough data to read the chunk size
		{
			return BCS_E_FAIL;
		}
		chunk_size = *reinterpret_cast<decltype(chunk_size)*>(current_read_position);
		current_read_position += sizeof(chunk_size);

		if (chunk_type == search_chunk_type)
		{
			out_chunk_data = current_read_position;
			out_chunk_data_size = chunk_size;
			rs = BCS_S_OK;
			goto end;
		}

		switch (chunk_type)
		{
		case 'RIFF':
		{
			long format;
			if (remaining_bytes < sizeof(format)) // not enough data to read the chunk size
			{
				return BCS_E_FAIL;
			}
			format = byteswap(*reinterpret_cast<decltype(format)*>(current_read_position));
			current_read_position += sizeof(format);
			chunk_size -= sizeof(format);

			if (BCS_SUCCEEDED(rs = find_riff_chunk(search_chunk_type, current_read_position, chunk_size, out_chunk_data, out_chunk_data_size)))
			{
				return rs;
			}
		}
		default:
		{
			current_read_position += chunk_size;
		}
		break;
		}

#undef remaining_bytes
	}
end:;
	return rs;
}

BCS_RESULT decode_xma2_to_wav(
	const void* xma_file_data,
	unsigned long long xma_file_data_size,
	void*& wav_file_data,
	unsigned long long& wav_file_data_size)
{
	BCS_RESULT rs = BCS_S_OK;

	void* riff_chunk_data;
	long riff_chunk_size;
	long riff_format;
	void* format_chunk_data;
	long format_chunk_size;
	WAVEFORMATEX* wave_format;
	void* samples_chunk_data;
	long samples_chunk_size;

	if (BCS_FAILED(rs = find_riff_chunk('RIFF', xma_file_data, xma_file_data_size, riff_chunk_data, riff_chunk_size)))
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	if (riff_chunk_size < sizeof(riff_format))
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	riff_format = byteswap(*static_cast<decltype(riff_format)*>(riff_chunk_data));
	if (riff_format != 'WAVE')
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	if (BCS_FAILED(rs = find_riff_chunk('fmt ', xma_file_data, xma_file_data_size, format_chunk_data, format_chunk_size)))
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	if (format_chunk_size < sizeof(*wave_format))
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}
	wave_format = static_cast<decltype(wave_format)>(format_chunk_data);
	if (format_chunk_size < (sizeof(*wave_format) + wave_format->cbSize))
	{
		rs = BCS_E_FATAL;
		goto cleanup;
	}

	if (BCS_FAILED(rs = find_riff_chunk('data', xma_file_data, xma_file_data_size, samples_chunk_data, samples_chunk_size)))
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	if (BCS_FAILED(rs = sound_transcode_to_wav(
		wave_format,
		samples_chunk_data,
		samples_chunk_size,
		wav_file_data,
		wav_file_data_size)))
	{
		return rs;
	}

cleanup:;

	return rs;
}

BCS_RESULT sound_transcode_to_wav(
	WAVEFORMATEX* source_wave_format,
	const void* samples_chunk_data,
	long samples_chunk_size,
	void*& out_wav_file_data,
	unsigned long long& out_wav_file_data_size)
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned char* resampled_sample_data[AV_NUM_DATA_POINTERS] = {};
	long total_resampled_sample_count = 0;

	WAVEFORMATEX target_wave_format = *source_wave_format;
	target_wave_format.wFormatTag = WAVE_FORMAT_PCM;
	target_wave_format.nSamplesPerSec = 48000;

	if (BCS_FAILED(rs = sound_transcode(
		source_wave_format,
		&target_wave_format,
		samples_chunk_data,
		samples_chunk_size,
		resampled_sample_data,
		&total_resampled_sample_count)))
	{
		goto cleanup;
	}

	{
		long bytes_per_sample = target_wave_format.wBitsPerSample / 8;

		long riff_chunk_id = byteswap('RIFF');
		long riff_chunk_size = 0;
		long riff_chunk_data = byteswap('WAVE');

		long format_chunk_id = byteswap('fmt ');
		long format_chunk_size = sizeof(WAVEFORMATEX);

		long data_chunk_header = byteswap('data');
		long data_chunk_size = total_resampled_sample_count * bytes_per_sample * target_wave_format.nChannels;

		riff_chunk_size += sizeof(riff_chunk_data);
		riff_chunk_size += sizeof(format_chunk_id);
		riff_chunk_size += sizeof(format_chunk_size);
		riff_chunk_size += format_chunk_size;
		riff_chunk_size += sizeof(data_chunk_header);
		riff_chunk_size += sizeof(data_chunk_size);
		riff_chunk_size += data_chunk_size;

		out_wav_file_data_size = 0;
#define enqueue_size(size) out_wav_file_data_size += (size)
		enqueue_size(sizeof(riff_chunk_id));
		enqueue_size(sizeof(riff_chunk_size));
		enqueue_size(sizeof(riff_chunk_data));
		enqueue_size(sizeof(format_chunk_id));
		enqueue_size(sizeof(format_chunk_size));
		enqueue_size(sizeof(target_wave_format));
		enqueue_size(sizeof(data_chunk_header));
		enqueue_size(sizeof(data_chunk_size));
		enqueue_size(data_chunk_size);
#undef enqueue_size

		char* wav_file_data = new() char[out_wav_file_data_size];
		out_wav_file_data = wav_file_data;
#define enqueue_data(pointer, size) memcpy(wav_file_data, (pointer), (size)); wav_file_data += (size)
		enqueue_data(&riff_chunk_id, sizeof(riff_chunk_id));
		enqueue_data(&riff_chunk_size, sizeof(riff_chunk_size));
		enqueue_data(&riff_chunk_data, sizeof(riff_chunk_data));
		enqueue_data(&format_chunk_id, sizeof(format_chunk_id));
		enqueue_data(&format_chunk_size, sizeof(format_chunk_size));
		enqueue_data(&target_wave_format, sizeof(target_wave_format));
		enqueue_data(&data_chunk_header, sizeof(data_chunk_header));
		enqueue_data(&data_chunk_size, sizeof(data_chunk_size));
		enqueue_data(resampled_sample_data[0], data_chunk_size);
#undef enqueue_data

		debug_point;


		debug_point;
	}


cleanup:;
	av_freep(&resampled_sample_data[0]);

	return rs;
}

BCS_RESULT sound_transcode(
	WAVEFORMATEX* source_wave_format,
	WAVEFORMATEX* target_wave_format,
	const void* samples_chunk_data,
	long samples_chunk_size,
	unsigned char** resampled_sample_data,
	long* total_resampled_sample_count)
{
	BCS_RESULT rs = BCS_S_OK;

	AVCodec* encoder_codec = nullptr;
	AVCodec* decoder_codec = nullptr;
	AVCodecParserContext* parser_context = nullptr;
	AVCodecContext* decoder_context = nullptr;
	AVCodecContext* encoder_context = nullptr;
	long open_result;


	encoder_codec = avcodec_find_encoder(AV_CODEC_ID_PCM_S16LE);
	if (encoder_codec == nullptr)
	{
		return BCS_E_FATAL;
	}

	encoder_context = avcodec_alloc_context3(encoder_codec);
	if (encoder_context == nullptr)
	{
		rs = BCS_E_FATAL;
		goto cleanup;
	}

	encoder_context->channels = target_wave_format->nChannels;
	encoder_context->sample_rate = target_wave_format->nSamplesPerSec;
	encoder_context->block_align = target_wave_format->nBlockAlign;
	encoder_context->bits_per_raw_sample = target_wave_format->wBitsPerSample;
	switch (target_wave_format->wBitsPerSample)
	{
	case 8:
		encoder_context->sample_fmt = AV_SAMPLE_FMT_U8;
		break;
	case 16:
		encoder_context->sample_fmt = AV_SAMPLE_FMT_S16;
		break;
	case 32:
		encoder_context->sample_fmt = AV_SAMPLE_FMT_S32;
		break;
	default:
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	decoder_codec = nullptr;
	switch (source_wave_format->wFormatTag)
	{
	case 0x165:
		decoder_codec = avcodec_find_decoder(AV_CODEC_ID_XMA1);
		return BCS_E_NOT_IMPLEMENTED;
		break;
	case 0x166:
		decoder_codec = avcodec_find_decoder(AV_CODEC_ID_XMA2);
		break;
	default:
		return BCS_E_NOT_SUPPORTED;
	}
	if (decoder_codec == nullptr)
	{
		return BCS_E_FATAL;
	}

	parser_context = av_parser_init(decoder_codec->id);
	if (parser_context == nullptr)
	{
		return BCS_E_FATAL;
	}

	decoder_context = avcodec_alloc_context3(decoder_codec);
	if (decoder_context == nullptr)
	{
		return BCS_E_FATAL;
	}

	decoder_context->channels = source_wave_format->nChannels;
	decoder_context->sample_rate = source_wave_format->nSamplesPerSec;
	decoder_context->block_align = source_wave_format->nBlockAlign;
	decoder_context->bits_per_raw_sample = source_wave_format->wBitsPerSample;
	decoder_context->extradata_size = source_wave_format->cbSize;
	decoder_context->sample_fmt = encoder_context->sample_fmt;

	{
		const void* wave_format_extra_data = next_contiguous_pointer(source_wave_format);
		void* dst_extra_data_copy = av_malloc(decoder_context->extradata_size);
		memcpy(dst_extra_data_copy, wave_format_extra_data, decoder_context->extradata_size);
		decoder_context->extradata = static_cast<unsigned char*>(dst_extra_data_copy);
	}

	open_result = avcodec_open2(decoder_context, decoder_codec, NULL);
	if (open_result < 0)
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	if (BCS_FAILED(rs = sound_transcode_packets(
		parser_context,
		decoder_context,
		encoder_context,
		samples_chunk_data,
		samples_chunk_size,
		resampled_sample_data,
		total_resampled_sample_count)))
	{
		goto cleanup;
	}

	debug_point;

cleanup:;
	avcodec_free_context(&encoder_context);
	avcodec_free_context(&decoder_context);
	av_parser_close(parser_context);

	return rs;
}

BCS_RESULT sound_transcode_packets(
	AVCodecParserContext* parser_context,
	AVCodecContext* decoder_context,
	AVCodecContext* encoder_context,
	const void* samples_chunk_data,
	long samples_chunk_size,
	unsigned char** resampled_sample_data,
	long* total_resampled_sample_count)
{
	BCS_VALIDATE_ARGUMENT(parser_context != nullptr);
	BCS_VALIDATE_ARGUMENT(decoder_context != nullptr);
	BCS_VALIDATE_ARGUMENT(encoder_context != nullptr);
	BCS_VALIDATE_ARGUMENT(samples_chunk_data != nullptr);
	BCS_VALIDATE_ARGUMENT(samples_chunk_size > 0);
	BCS_VALIDATE_ARGUMENT(resampled_sample_data != nullptr);
	BCS_VALIDATE_ARGUMENT(total_resampled_sample_count != nullptr);

	BCS_RESULT rs = BCS_S_OK;

	AVPacket* encoded_packet;
	AVFrame* decoded_frame;

	unsigned char* decoded_sample_data[AV_NUM_DATA_POINTERS];
	long total_decoded_sample_count = 0;

	const unsigned char* data_read_position = static_cast<const unsigned char*>(samples_chunk_data);

	AVSampleFormat in_sample_format = decoder_context->sample_fmt;
	long in_sample_rate = decoder_context->sample_rate;

	AVSampleFormat out_sample_format = encoder_context->sample_fmt;
	long out_sample_rate = encoder_context->sample_rate;

	encoded_packet = av_packet_alloc();
	if (encoded_packet == nullptr)
	{
		rs = BCS_E_FATAL;
		goto cleanup;
	}
	decoded_frame = av_frame_alloc();
	if (decoded_frame == nullptr)
	{
		rs = BCS_E_FATAL;
		goto cleanup;
	}

	for (long bytes_read = 0, bytes_remaining = samples_chunk_size, bytes_consumed; bytes_read < samples_chunk_size; bytes_read += bytes_consumed, bytes_remaining -= bytes_consumed)
	{
		bytes_consumed = av_parser_parse2(
			parser_context,
			decoder_context,
			&encoded_packet->data,
			&encoded_packet->size,
			data_read_position,
			bytes_remaining,
			AV_NOPTS_VALUE,
			AV_NOPTS_VALUE, 0);
		if (bytes_consumed < 0)
		{
			rs = BCS_E_FAIL;
			goto cleanup;
		}
		data_read_position += bytes_consumed;

		if (encoded_packet->size)
		{
			long decode_packet_result = avcodec_send_packet(decoder_context, encoded_packet);
			if (decode_packet_result < 0)
			{
				rs = BCS_E_FAIL;
				goto cleanup;
			}

			while (decode_packet_result >= 0)
			{
				decode_packet_result = avcodec_receive_frame(decoder_context, decoded_frame);
				if (decode_packet_result == AVERROR(EAGAIN) || decode_packet_result == AVERROR_EOF)
				{
					rs = BCS_S_OK;
					goto finish;
				}
				else if (decode_packet_result < 0)
				{
					rs = BCS_E_FAIL;
					goto cleanup;
				}

				long decoded_sample_count = decoded_frame->nb_samples;
				if (decoded_sample_count > 0)
				{
					unsigned char* new_decoded_sample_data[AV_NUM_DATA_POINTERS] = {};
					long decoded_samples_allocate_result = av_samples_alloc(
						new_decoded_sample_data,
						nullptr,
						decoded_frame->channels,
						total_decoded_sample_count + decoded_sample_count,
						decoder_context->sample_fmt,
						0);
					if (decoded_samples_allocate_result < 0)
					{
						rs = BCS_E_FAIL;
						goto cleanup;
					}

					long decoded_samples_copy_result = 0;
					long decoded_samples_buffer_offset = 0;
					if (total_decoded_sample_count > 0)
					{
						decoded_samples_copy_result = av_samples_copy(
							new_decoded_sample_data,
							decoded_sample_data,
							0,
							0,
							total_decoded_sample_count,
							decoded_frame->channels,
							decoder_context->sample_fmt);
						if (decoded_samples_copy_result < 0)
						{
							rs = BCS_E_FAIL;
							goto cleanup;
						}

						av_freep(&decoded_sample_data[0]);
					}

					long decoded_samples_copy_result2 = av_samples_copy(
						new_decoded_sample_data,
						decoded_frame->data,
						total_decoded_sample_count,
						0,
						decoded_frame->nb_samples,
						decoded_frame->channels,
						decoder_context->sample_fmt);
					if (decoded_samples_copy_result2 < 0)
					{
						rs = BCS_E_FAIL;
						goto cleanup;
					}

					memcpy(decoded_sample_data, new_decoded_sample_data, sizeof(decoded_sample_data));
					total_decoded_sample_count += decoded_sample_count;
				}

				for (long sample_index = 0, num_samples = decoded_frame->nb_samples; sample_index < num_samples; sample_index++)
				{
					for (long channel_index = 0, num_channels = decoded_frame->channels; channel_index < num_channels; channel_index++)
					{
						unsigned char* channel_data = decoded_frame->data[channel_index];

						// AV_SAMPLE_FMT_FLTP

						// memcpy(dst, channel_data, data_size);
						debug_point;
					}
				}
			}
		}
		debug_point;
	}
finish:;

	if (BCS_FAILED(rs = sound_software_resample(
		const_cast<const unsigned char**>(decoded_sample_data),
		resampled_sample_data,
		total_decoded_sample_count,
		total_resampled_sample_count,
		decoder_context->channels,
		encoder_context->channels,
		in_sample_rate,
		out_sample_rate,
		in_sample_format,
		out_sample_format)))
	{
		goto cleanup;
	}

cleanup:;
	av_frame_free(&decoded_frame);
	av_packet_free(&encoded_packet);

	return rs;
}

static BCS_RESULT sound_channel_count_to_channel_layout(long channel_count, long long& channel_layout)
{
	channel_layout = AV_CH_LAYOUT_MONO;
	switch (channel_count)
	{
	case 1:
		channel_layout = AV_CH_LAYOUT_MONO;
		return BCS_S_OK;
	case 2:
		channel_layout = AV_CH_LAYOUT_STEREO;
		return BCS_S_OK;
	case 4:
		channel_layout = AV_CH_LAYOUT_QUAD;
		return BCS_S_OK;
	case 6:
		channel_layout = AV_CH_LAYOUT_5POINT1;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT sound_software_resample(
	const unsigned char** in_sample_data,
	unsigned char** out_sample_data,
	long in_sample_count,
	long* out_sample_count,
	long in_channel_count,
	long out_channel_count,
	long in_sample_rate,
	long out_sample_rate,
	AVSampleFormat in_sample_format,
	AVSampleFormat out_sample_format)
{
	BCS_VALIDATE_ARGUMENT(in_sample_data);
	BCS_VALIDATE_ARGUMENT(in_sample_count > 0);
	BCS_VALIDATE_ARGUMENT(out_sample_count != nullptr);
	BCS_VALIDATE_ARGUMENT(in_channel_count > 0);
	BCS_VALIDATE_ARGUMENT(out_sample_data != nullptr);
	BCS_VALIDATE_ARGUMENT(out_channel_count > 0);

	BCS_RESULT rs = BCS_S_OK;

	SwrContext* software_resample_context = nullptr;
	long long in_channel_layout;
	long long out_channel_layout;

	long software_resample_init_result;
	long converted_sample_data_allocate_result;
	long software_resample_convert_result;

	if (BCS_FAILED(rs = sound_channel_count_to_channel_layout(in_channel_count, in_channel_layout)))
	{
		goto cleanup;
	}

	if (BCS_FAILED(rs = sound_channel_count_to_channel_layout(out_channel_count, out_channel_layout)))
	{
		goto cleanup;
	}

	software_resample_context = swr_alloc_set_opts(
		nullptr,
		in_channel_layout,
		out_sample_format,
		out_sample_rate,
		out_channel_layout,
		in_sample_format,
		in_sample_rate,
		0,
		nullptr);
	if (software_resample_context == nullptr)
	{
		return BCS_E_FAIL;
	}

	software_resample_init_result = swr_init(software_resample_context);
	if (software_resample_init_result < 0)
	{
		return BCS_E_FAIL;
	}

	*out_sample_count = swr_get_out_samples(software_resample_context, in_sample_count);
	if (*out_sample_count < 0)
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	converted_sample_data_allocate_result = av_samples_alloc(out_sample_data, nullptr, out_channel_count, *out_sample_count, out_sample_format, 0);
	if (converted_sample_data_allocate_result < 0)
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}

	software_resample_convert_result = swr_convert(
		software_resample_context,
		out_sample_data,
		*out_sample_count,
		in_sample_data,
		in_sample_count);
	if (software_resample_convert_result < 0)
	{
		rs = BCS_E_FAIL;
		goto cleanup;
	}
	*out_sample_count = software_resample_convert_result;

cleanup:;
	swr_close(software_resample_context);
	swr_free(&software_resample_context);

	return rs;
}