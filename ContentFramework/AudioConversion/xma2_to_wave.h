#pragma once

BCS_DEBUG_API BCS_RESULT find_riff_chunk(
	int32_t search_chunk_type,
	const void* riff_data,
	uint64_t riff_data_size,
	void*& out_chunk_data,
	int32_t& out_chunk_data_size);

BCS_DEBUG_API extern BCS_RESULT decode_xma2_to_wav(
	const void* xma_file_data,
	uint64_t xma_file_data_size,
	void*& wav_file_data,
	uint64_t& wav_file_data_size);

#ifdef __XAUDIO2_INCLUDED__

BCS_DEBUG_API extern BCS_RESULT sound_transcode_to_wav(
	WAVEFORMATEX* wave_format,
	const void* samples_chunk_data,
	int32_t samples_chunk_size,
	void*& wav_file_data,
	uint64_t& wav_file_data_size);

BCS_DEBUG_API extern BCS_RESULT sound_transcode(
	WAVEFORMATEX* source_wave_format,
	WAVEFORMATEX* target_wave_format,
	const void* samples_chunk_data,
	int32_t samples_chunk_size,
	unsigned char** resampled_sample_data,
	int32_t* total_resampled_sample_count);

#endif

#ifdef AVCODEC_AVCODEC_H

BCS_DEBUG_API extern BCS_RESULT sound_transcode_packets(
	AVCodecParserContext* parser_context,
	AVCodecContext* decoder_context,
	AVCodecContext* encoder_context,
	const void* samples_chunk_data,
	int32_t samples_chunk_size,
	unsigned char** resampled_sample_data,
	int32_t* total_resampled_sample_count);

BCS_DEBUG_API extern BCS_RESULT sound_software_resample(
	const unsigned char** in_sample_data,
	unsigned char** out_sample_data,
	int32_t in_sample_count,
	int32_t* out_sample_count,
	int32_t in_channel_count,
	int32_t out_channel_count,
	int32_t in_sample_rate,
	int32_t out_sample_rate,
	AVSampleFormat in_sample_format,
	AVSampleFormat out_sample_format);

#endif
