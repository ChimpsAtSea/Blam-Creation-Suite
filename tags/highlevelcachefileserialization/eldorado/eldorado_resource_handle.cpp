#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO

using namespace blofeld::eldorado::pc32;

c_eldorado_resource_handle::c_eldorado_resource_handle(
	c_eldorado_cache_file_reader& cache_file_reader,
	c_tag_instance& tag_instance,
	char const* resource_data_position) :
	resource_location(*new h_cache_file_resource_location_struct(this)),
	resource_data(*new h_cache_file_resource_data_block(this)),
	resource_binary_filepath(),
	absolute_file_offset(UINT_MAX),
	decompressed_buffer(nullptr),
	reference_count(0),
	memory_mapped_file(),
	memory_mapped_file_info()
{
	transplant_prototype(tag_instance, resource_data_position, resource_location);
	transplant_prototype(tag_instance, resource_data_position, resource_data);

	//h_prototype_field<short, h_cache_file_resource_location_struct, 0> header_salt_at_runtime;
	//h_prototype_flags<e_cache_file_tag_resource_location_flags, unsigned int, k_cache_file_tag_resource_location_flags_count, h_cache_file_resource_location_struct, 1> flags;
	//h_prototype_field<char, h_cache_file_resource_location_struct, 2> codec;
	//h_prototype_field<short, h_cache_file_resource_location_struct, 3> shared_file;
	//h_prototype_field<short, h_cache_file_resource_location_struct, 4> shared_file_location_index;
	//h_prototype_field<int32_t, h_cache_file_resource_location_struct, 5> file_size;
	//h_prototype_field<int32_t, h_cache_file_resource_location_struct, 6> size;
	//h_resource_checksum_struct checksum;
	//h_prototype_field<short, h_cache_file_resource_location_struct, 8> resource_reference_count;
	//h_prototype_field<short, h_cache_file_resource_location_struct, 9> streaming_sublocation_table;
	//h_prototype_field<int32_t, h_cache_file_resource_location_struct, 10> value;
	//h_prototype_field<int32_t, h_cache_file_resource_location_struct, 11> value$2;
	//h_prototype_field<int32_t, h_cache_file_resource_location_struct, 12> value$3;

	
	short header_salt_at_runtime = resource_location.header_salt_at_runtime;
	auto& flags = resource_location.flags;
	char codec = resource_location.codec;
	short shared_file = resource_location.shared_file;
	short shared_file_location_index = resource_location.shared_file_location_index;
	int32_t file_size = resource_location.file_size;
	int32_t size = resource_location.size;
	short resource_reference_count = resource_location.resource_reference_count;
	short streaming_sublocation_table = resource_location.streaming_sublocation_table;
	int32_t value = resource_location.value;
	int32_t value$2 = resource_location.value$2;
	int32_t value$3 = resource_location.value$3;

	if (shared_file >= 0)
	{
		e_eldorado_file_index eldorado_file_index = _eldorado_file_type_resources;
		if (flags.test(_cache_file_tag_resource_location_flags_resources))
		{
			eldorado_file_index = _eldorado_file_type_resources;
		}
		else if (flags.test(_cache_file_tag_resource_location_flags_textures))
		{
			eldorado_file_index = _eldorado_file_type_textures_resources;
		}
		else if (flags.test(_cache_file_tag_resource_location_flags_textures_b))
		{
			eldorado_file_index = _eldorado_file_type_textures_b_resources;
		}
		else if (flags.test(_cache_file_tag_resource_location_flags_audio))
		{
			eldorado_file_index = _eldorado_file_type_audio_resources;
		}
		else if (flags.test(_cache_file_tag_resource_location_flags_video))
		{
			eldorado_file_index = _eldorado_file_type_video_resources;
		}

		debug_point;
		 
		if (eldorado_file_index == _eldorado_file_type_textures_resources && shared_file == 1)
		{
			debug_point;
		}

		cache_file_reader.get_resource_absolute_file_offset(eldorado_file_index, shared_file, absolute_file_offset);

		debug_point;

		const char* eldorado_relative_file_path = cache_file_reader.eldorado_relative_file_paths[eldorado_file_index];
		c_fixed_wide_path eldorado_file_path;
		eldorado_file_path.format(L"%s\\%S", cache_file_reader.directory, eldorado_relative_file_path);

		resource_binary_filepath = _wcsdup(eldorado_file_path);

		debug_point;
	}

	debug_point;
}

c_eldorado_resource_handle::~c_eldorado_resource_handle()
{
	delete& resource_location;
	delete& resource_data;
	ASSERT(reference_count == 0);
	untracked_free(resource_binary_filepath);
}

BCS_RESULT c_eldorado_resource_handle::add_reference(const void*& buffer, uint32_t& buffer_size)
{

	short header_salt_at_runtime = resource_location.header_salt_at_runtime;
	auto& flags = resource_location.flags;
	short shared_file = resource_location.shared_file;
	short shared_file_location_index = resource_location.shared_file_location_index;
	int32_t file_size = resource_location.file_size;
	int32_t size = resource_location.size;
	short resource_reference_count = resource_location.resource_reference_count;
	short streaming_sublocation_table = resource_location.streaming_sublocation_table;
	int32_t value = resource_location.value;
	int32_t value$2 = resource_location.value$2;
	int32_t value$3 = resource_location.value$3;










	BCS_RESULT rs = BCS_S_OK;

	int32_t reference_index = reference_count;

	if (reference_index == 0)
	{
		if (BCS_FAILED(rs = create_memory_mapped_file(resource_binary_filepath, true, memory_mapped_file)))
		{
			return rs;
		}

		if (BCS_FAILED(rs = get_memory_mapped_file_info(memory_mapped_file, memory_mapped_file_info)))
		{
			destroy_memory_mapped_file(memory_mapped_file);
			return rs;
		}
	}
	reference_count++;
	ASSERT(reference_count > 0);

	const char* resource_data_start = memory_mapped_file_info.file_view_begin + absolute_file_offset;
	const char* resource_data_end = resource_data_start + resource_location.file_size;

	char codec = resource_location.codec;
	switch (codec)
	{
	case -1:
	{
		buffer = resource_data_start;
		buffer_size = static_cast<unsigned long>(resource_data_end - resource_data_start);
	}
	break;
	case 0:
	{
		int file_size = resource_location.file_size;
		int size = resource_location.size;

		decompressed_buffer = tracked_malloc(size);

		const char* resource_data_position = resource_data_start;
		char* decompressed_buffer_position = static_cast<char*>(decompressed_buffer);

		while (resource_data_position < resource_data_end)
		{
			unsigned int decompressed_chunk_size = reinterpret_cast<const unsigned int*>(resource_data_position)[0];
			unsigned int compressed_chunk_size = reinterpret_cast<const unsigned int*>(resource_data_position)[1];
			resource_data_position += 8;

			// Decompress the data
			int decompressed_size = LZ4_decompress_safe(resource_data_position, decompressed_buffer_position, compressed_chunk_size, decompressed_chunk_size);
			ASSERT(decompressed_size == decompressed_chunk_size);

			// Check if the decompression was successful
			if (decompressed_size < 0)
			{
				// Handle error
				tracked_free(decompressed_buffer);
				decompressed_buffer = nullptr;
				return BCS_E_FAIL;
			}

			resource_data_position += compressed_chunk_size;
			decompressed_buffer_position += decompressed_size;
		}

		buffer = decompressed_buffer;
		buffer_size = size;
	}
	break;
	}

	return rs;
}

BCS_RESULT c_eldorado_resource_handle::remove_reference()
{
	BCS_RESULT rs = BCS_S_OK;
	int32_t reference_index = --reference_count;
	ASSERT(reference_count >= 0);

	if (reference_index == 0)
	{
		if (BCS_FAILED(rs = destroy_memory_mapped_file(memory_mapped_file)))
		{
			return rs;
		}

		if (decompressed_buffer != nullptr)
		{
			tracked_free(decompressed_buffer);
			decompressed_buffer = nullptr;
		}
	}

	return rs;
}

const char* c_eldorado_resource_handle::get_debug_type_string()
{
	return "c_eldorado_resource_handle";
}

#endif // BCS_BUILD_HIGH_LEVEL_ELDORADO
