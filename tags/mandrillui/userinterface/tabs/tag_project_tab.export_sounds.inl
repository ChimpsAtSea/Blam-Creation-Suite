#ifndef BCS_BUILD_HIGH_LEVEL_HALO3

static void export_sounds(const wchar_t* export_directory, c_tag_project& tag_project, bool export_wav, bool export_xma)
{

}

#else

//#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>

//#include <AudioConversion\audioconversion-platform-pch.h>
//#include <AudioConversion\audioconversion-public-pch.h>

static void export_sounds(const wchar_t* export_directory, c_tag_project& tag_project, bool export_wav, bool export_xma)
{
//	h_tag_instance* const* tag_instances;
//	uint32_t tag_instance_count;
//	tag_project.get_tag_instances(tag_instances, tag_instance_count);
//
//	blofeld::halo3::pc64::h_sound_cache_file_gestalt_struct_definition* sound_cache_file_gestalt = nullptr;
//	for (uint32_t tag_instance_index = 0; tag_instance_index < tag_instance_count; tag_instance_index++)
//	{
//		h_tag_instance& tag = *tag_instances[tag_instance_index];
//
//		if (tag.group->tag_group.group_tag == blofeld::halo3::pc64::SOUND_CACHE_FILE_GESTALT_TAG)
//		{
//			sound_cache_file_gestalt = dynamic_cast<blofeld::halo3::pc64::h_sound_cache_file_gestalt_struct_definition*>(&tag);
//			break;
//		}
//	}
//	ASSERT(sound_cache_file_gestalt != nullptr);
//
//	for (uint32_t tag_instance_index = 0; tag_instance_index < tag_instance_count; tag_instance_index++)
//	{
//		h_tag_instance& tag = *tag_instances[tag_instance_index];
//
//
//		if (tag.group->tag_group.group_tag == blofeld::halo3::pc64::CACHE_FILE_SOUND_TAG)
//		{
//			blofeld::halo3::pc64::h_cache_file_sound_struct_definition* cache_file_sound = dynamic_cast<blofeld::halo3::pc64::h_cache_file_sound_struct_definition*>(&tag);
//			ASSERT(cache_file_sound != nullptr);
//
//			h_resource* resource = cache_file_sound->sound_data_resource.value;
//
//			if (resource)
//			{
//				const void* resource_buffer;
//				uint32_t resource_buffer_size;
//				if (BCS_SUCCEEDED(resource->add_reference(resource_buffer, resource_buffer_size)))
//				{
//					using namespace blofeld::halo3::pc64;
//
//					blofeld::halo3::pc64::h_sound_gestalt_codec_block& codec = sound_cache_file_gestalt->codecs_block[cache_file_sound->codec_index];
//					
//					uint32_t const pitch_range_start_index = cache_file_sound->first_pitch_range_index;
//					uint32_t const pitch_range_end_index = pitch_range_start_index + cache_file_sound->pitch_range_count;
//					for (uint32_t pitch_range_index = pitch_range_start_index; pitch_range_index < pitch_range_end_index; pitch_range_index++)
//					{
//						blofeld::halo3::pc64::h_sound_gestalt_pitch_ranges_block& pitch_range = sound_cache_file_gestalt->pitch_ranges_block[pitch_range_index];
//
//						h_string_id pitch_range_name = sound_cache_file_gestalt->import_names_block[pitch_range.name].import_name;
//						uint32_t encoded_first_permutation_and_counts = pitch_range.encoded_first_permutation_and_counts;
//
//						uint32_t permutation_start_index = (encoded_first_permutation_and_counts >> 0) & 0x000FFFFF;
//						uint32_t total_permutation_count = (encoded_first_permutation_and_counts >> 20) & 0x3F;
//						uint32_t required_only_permutation_count = (encoded_first_permutation_and_counts >> 26) & 0x3F;
//
//						debug_point;
//
//						uint32_t const permutation_end_index = permutation_start_index + total_permutation_count;
//						for (uint32_t permutation_index = permutation_start_index; permutation_index < permutation_end_index; permutation_index++)
//						{
//							blofeld::halo3::pc64::h_sound_gestalt_permutations_block& permutation = sound_cache_file_gestalt->permutations_block[permutation_index];
//							h_string_id permutation_name = sound_cache_file_gestalt->import_names_block[permutation.name].import_name;
//
//							debug_point;
//
//							const char* _tag_filepath = tag.get_file_path();
//							const char* _permutation_name = permutation_name.get_string();
//
//							uint32_t const chunk_count = permutation.chunk_count;
//							if (chunk_count == 1)
//							{
//								uint32_t const chunk_start_index = permutation.first_chunk_index;
//								uint32_t const chunk_end_index = chunk_start_index + chunk_count;
//								for (uint32_t chunk_index = chunk_start_index; chunk_index < chunk_end_index; chunk_index++)
//								{
//									blofeld::halo3::pc64::h_sound_permutation_chunk_block& chunk = sound_cache_file_gestalt->chunks_block[chunk_index];
//
//									c_long_designator<6, 0> size_and_flags;
//									size_and_flags.set_raw_designator(chunk.encoded_size_and_flags);
//									uint32_t sample_size = size_and_flags.get_primary_index();
//									uint32_t flags = size_and_flags.get_secondary_index();
//									uint32_t file_offset = chunk.file_offset;
//
//									const char* sample_data_start = static_cast<const char*>(resource_buffer) + file_offset;
//									const char* sample_data_end = sample_data_start + sample_size;
//
//									int32_t number_of_channels = 0;
//									switch (codec.encoding)
//									{
//									case _sound_encoding_enum_mono:
//										number_of_channels = 1;
//										break;
//									case _sound_encoding_enum_stereo:
//										number_of_channels = 2;
//										break;
//									case _sound_encoding_enum_quad:
//										number_of_channels = 4;
//										break;
//									case _sound_encoding_enum__51:
//										number_of_channels = 6;
//										break;
//									case _sound_encoding_enum_codec:
//										number_of_channels = 1;
//										break;
//									}
//
//									int32_t samples_per_second = 0;
//									switch (codec.sample_rate)
//									{
//									case _sound_sample_rate_enum__22khz:
//										samples_per_second = 22050;
//										break;
//									case _sound_sample_rate_enum__44khz:
//										samples_per_second = 44100;
//										break;
//									case _sound_sample_rate_enum__32khz:
//										samples_per_second = 32000;
//										break;
//									case _sound_sample_rate_enum__48khz:
//										samples_per_second = 48000;
//										break;
//									}
//
//									int32_t riff_chunk_id = byteswap('RIFF');
//									int32_t riff_chunk_size = 0;
//									int32_t riff_chunk_data = byteswap('WAVE');
//
//									int32_t format_chunk_id = byteswap('fmt ');
//									int32_t format_chunk_size = sizeof(XMA2WAVEFORMATEX);
//
//									int32_t data_chunk_header = byteswap('data');
//									int32_t data_chunk_size = sample_size;
//									XMA2WAVEFORMATEX xma2_wave_format = {};
//
//									riff_chunk_size += sizeof(riff_chunk_data);
//									riff_chunk_size += sizeof(format_chunk_id);
//									riff_chunk_size += sizeof(format_chunk_size);
//									riff_chunk_size += format_chunk_size;
//									riff_chunk_size += sizeof(data_chunk_header);
//									riff_chunk_size += sizeof(data_chunk_size);
//									riff_chunk_size += data_chunk_size;
//
//									{
//										xma2_wave_format.wfx.wFormatTag = WAVE_FORMAT_XMA2;										//    wFormatTag;        // Audio format type; always WAVE_FORMAT_XMA2														
//										xma2_wave_format.wfx.nChannels = static_cast<WORD>(number_of_channels);					//    nChannels;         // Channel count of the decoded audio
//										xma2_wave_format.wfx.nSamplesPerSec = samples_per_second;								//    nSamplesPerSec;    // Sample rate of the decoded audio
//										xma2_wave_format.wfx.nAvgBytesPerSec = 0;												//    nAvgBytesPerSec;   // Used internally by the XMA encoder
//										xma2_wave_format.wfx.nBlockAlign = 2;													//    nBlockAlign;       // Decoded sample size; channels * wBitsPerSample / 8
//										xma2_wave_format.wfx.wBitsPerSample = 16;												//    wBitsPerSample;    // Bits per decoded mono sample; always 16 for XMA
//										xma2_wave_format.wfx.cbSize = sizeof(xma2_wave_format) - sizeof(WAVEFORMATEX);			//    cbSize;            // Size in bytes of the rest of this structure (34)
//
//										xma2_wave_format.NumStreams = 1;														// Number of audio streams (1 or 2 channels each)
//										xma2_wave_format.ChannelMask = 0;														// Spatial positions of the channels in this file,
//																																// stored as SPEAKER_xxx values (see audiodefs.h)
//										xma2_wave_format.SamplesEncoded = permutation.uncompressed_sample_count;			// Total number of PCM samples the file decodes to
//										xma2_wave_format.BytesPerBlock = 2048;													// XMA block size (but the last one may be shorter)
//										xma2_wave_format.PlayBegin = chunk.xma2_source_buffer_sample_start;				// First valid sample in the decoded audio
//										xma2_wave_format.PlayLength = chunk.xma2_source_buffer_sample_end;				// Length of the valid part of the decoded audio
//										xma2_wave_format.LoopBegin = 0;															// Beginning of the loop region in decoded sample terms
//										xma2_wave_format.LoopLength = 0;														// Length of the loop region in decoded sample terms
//										xma2_wave_format.LoopCount = 0;															// Number of loop repetitions; 255 = infinite
//										xma2_wave_format.EncoderVersion = 4;													// Version of XMA encoder that generated the file
//										xma2_wave_format.BlockCount = static_cast<WORD>(sample_size / 2048);					// XMA blocks in file (and entries in its seek table)
//									}
//									char* xma_file_data;
//									uint32_t xma_file_data_size = 0;
//									{
//#define enqueue_size(size) xma_file_data_size += (size)
//										enqueue_size(sizeof(riff_chunk_id));
//										enqueue_size(sizeof(riff_chunk_size));
//										enqueue_size(sizeof(riff_chunk_data));
//										enqueue_size(sizeof(format_chunk_id));
//										enqueue_size(sizeof(format_chunk_size));
//										enqueue_size(sizeof(xma2_wave_format));
//										enqueue_size(sizeof(data_chunk_header));
//										enqueue_size(sizeof(data_chunk_size));
//										enqueue_size(data_chunk_size);
//#undef enqueue_size
//
//										xma_file_data = new() char[xma_file_data_size];
//										char* xma_file_data_pos = xma_file_data;
//#define enqueue_data(pointer, size) memcpy(xma_file_data_pos, (pointer), (size)); xma_file_data_pos += (size)
//										enqueue_data(&riff_chunk_id, sizeof(riff_chunk_id));
//										enqueue_data(&riff_chunk_size, sizeof(riff_chunk_size));
//										enqueue_data(&riff_chunk_data, sizeof(riff_chunk_data));
//										enqueue_data(&format_chunk_id, sizeof(format_chunk_id));
//										enqueue_data(&format_chunk_size, sizeof(format_chunk_size));
//										enqueue_data(&xma2_wave_format, sizeof(xma2_wave_format));
//										enqueue_data(&data_chunk_header, sizeof(data_chunk_header));
//										enqueue_data(&data_chunk_size, sizeof(data_chunk_size));
//										enqueue_data(sample_data_start, sample_size);
//#undef enqueue_data
//
//									}
//
//									debug_point;
//
//									if (export_wav)
//									{
//										void* wave_file_data;
//										uint64_t wave_file_data_size;
//										BCS_RESULT decode_rs = decode_xma2_to_wav(xma_file_data, xma_file_data_size, wave_file_data, wave_file_data_size);
//										if (BCS_SUCCEEDED(decode_rs))
//										{
//											c_fixed_path wav_output_filepath;
//											wav_output_filepath.format("%Sdata\\%s\\%s.wav", export_directory, _tag_filepath, permutation_name);
//											filesystem_write_file_from_memory(wav_output_filepath, wave_file_data, wave_file_data_size);
//
//											tracked_free(wave_file_data);
//										}
//
//										debug_point;
//									}
//									if (export_xma)
//									{
//										c_fixed_path xma_output_filepath;
//										xma_output_filepath.format("%Sdata\\%s\\%s.xma", export_directory, _tag_filepath, permutation_name);
//
//										filesystem_write_file_from_memory(xma_output_filepath, xma_file_data, xma_file_data_size);
//
//										tracked_free(xma_file_data);
//
//										debug_point;
//									}
//
//
//									debug_point;
//								}
//							}
//							else
//							{
//								debug_point;
//							}
//							debug_point;
//						}
//
//						debug_point;
//					}
//
//					debug_point;
//
//					resource->remove_reference();
//				}
//			}
//			else
//			{
//				debug_point;
//			}
//
//			debug_point;
//		}
//
//	}
}

#endif
