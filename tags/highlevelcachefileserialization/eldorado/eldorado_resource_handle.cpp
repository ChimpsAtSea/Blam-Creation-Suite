#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO

using namespace blofeld::eldorado::pc32;

c_eldorado_resource_handle::c_eldorado_resource_handle(
	c_transplant_context& context,
	c_eldorado_cache_file_reader& _cache_file_reader,
	c_eldorado_tag_instance& _tag_instance,
	char const* _resource_data_position,
	blofeld::s_tag_resource_definition const& _resource_definition) :
	resource_location(*new h_cache_file_resource_location_struct(this)),
	resource_data(*new h_cache_file_resource_data_block(this)),
	resource_binary_filepath(),
	absolute_file_offset(UINT_MAX),
	decompressed_buffer(nullptr),
	reference_count(0),
	chunk_details(),
	memory_mapped_file(),
	memory_mapped_file_info(),
	prototype(nullptr),
	resource_definition(_resource_definition)
{
	transplant_prototype(context, _resource_data_position, resource_location);
	transplant_prototype(context, _resource_data_position, resource_data);

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

		_cache_file_reader.get_resource_absolute_file_offset(eldorado_file_index, shared_file, absolute_file_offset);

		debug_point;

		const char* eldorado_relative_file_path = _cache_file_reader.eldorado_relative_file_paths[eldorado_file_index];
		c_fixed_wide_path eldorado_file_path;
		eldorado_file_path.format(L"%s\\%S", _cache_file_reader.directory, eldorado_relative_file_path);

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

BCS_RESULT c_eldorado_resource_handle::add_reference(s_resource_details& resource_details, bool create_prototype)
{
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
		resource_details = {};
		resource_details.buffer = resource_data_start;
		resource_details.buffer_size = static_cast<unsigned long>(resource_data_end - resource_data_start);
		resource_details.chunk_details = nullptr;
		resource_details.num_chunk_details = 0;
		throw; // #TODO: How to handle chunks?
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

			s_resource_chunk_details& chunk = chunk_details.emplace_back();
			chunk.buffer = decompressed_buffer_position;
			chunk.buffer_size = decompressed_chunk_size;

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

		resource_details = {};
		resource_details.buffer = decompressed_buffer;
		resource_details.buffer_size = size;
		resource_details.chunk_details = chunk_details.data();
		resource_details.num_chunk_details = chunk_details.size();

		debug_point;
	}
	break;
	}

	if (create_prototype && prototype == nullptr)
	{
		this->resource_data;

		if (BCS_FAILED(rs = high_level_registry_create_high_level_object({ _engine_type_eldorado, _platform_type_pc_32bit }, resource_definition.struct_definition, prototype)))
		{
			return rs;
		}

		c_big_flags;
		resource_data.root_fixup;

		void const* control_data_start;
		void const* control_data_end;
		void const* control_data_root;
		if (BCS_FAILED(get_transplant_data(control_data_start, &control_data_end, &control_data_root)))
		{
			return rs;
		}

		char const* control_data_position = static_cast<char const*>(control_data_root);
		if (BCS_FAILED(rs = rs = transplant_prototype(*this, control_data_position, *prototype)))
		{
			return rs;
		}

		resource_details.prototype = prototype;

		debug_point;
	}

	return rs;
}

BCS_RESULT c_eldorado_resource_handle::get_transplant_data(void const*& data_start, void const** data_end, void const** data_root)
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned int root_fixup_type = static_cast<unsigned int>(resource_data.root_fixup) >> 28;
	unsigned int root_fixup_offset = static_cast<unsigned int>(resource_data.root_fixup) & 0x0FFFFFFF;

	const char* const control_data_start = resource_data.control_data.begin();
	const char* const control_data_end = resource_data.control_data.end();
	const char* const control_data_root = control_data_start + root_fixup_offset;

	data_start = control_data_start;

	if (data_end != nullptr)
	{
		*data_end = control_data_end;
	}

	if (data_root != nullptr)
	{
		*data_root = control_data_root;
	}

	return BCS_S_OK;
}

BCS_RESULT c_eldorado_resource_handle::resolve_address(dword const* address_pointer, void const*& address_data_start)
{
	BCS_RESULT rs = BCS_S_OK;

	const char* const control_data_start = resource_data.control_data.begin();
	const char* const control_data_end = resource_data.control_data.end();

	if (static_cast<void const*>(address_pointer + 1) > static_cast<void const*>(control_data_end))
	{
		return BCS_E_OUT_OF_RANGE;
	}

	if (static_cast<void const*>(address_pointer) < static_cast<void const*>(control_data_start))
	{
		return BCS_E_OUT_OF_RANGE;
	}

	intptr_t tag_block_address_offset = reinterpret_cast<intptr_t>(address_pointer) - reinterpret_cast<intptr_t>(control_data_start);
	if (tag_block_address_offset < 0)
	{
		return BCS_E_OUT_OF_RANGE;
	}

	for (auto& control_fixup : resource_data.control_fixups_block)
	{
		if (static_cast<int32_t>(control_fixup->encoded_fixup_location) == tag_block_address_offset)
		{
			dword address_storage = control_fixup->encoded_fixup_value;

			debug_point;

			dword address_segment = address_storage >> 28u;
			ASSERT(address_segment == 2 || address_segment == 4);
			dword offset = address_storage & 0xfffffff;


			void const* data_start = nullptr;
			void const* data_end = nullptr;
			if (address_segment == 2) // control data
			{
				if (BCS_FAILED(rs = get_transplant_data(data_start, &data_end, nullptr)))
				{
					return rs;
				}
				debug_point;
			}
			else if (address_segment == 4) // resource data
			{
				data_start = decompressed_buffer;
				data_end = static_cast<char const*>(decompressed_buffer) + resource_location.size;
				debug_point;
			}

			address_data_start = static_cast<char const*>(data_start) + offset;

			if (address_data_start >= data_end)
			{
				debug_point;
			}

			debug_point;

			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
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

		if (prototype != nullptr)
		{
			delete prototype;
			prototype = nullptr;
		}
	}

	return rs;
}

const char* c_eldorado_resource_handle::get_debug_type_string()
{
	return "c_eldorado_resource_handle";
}

#endif // BCS_BUILD_HIGH_LEVEL_ELDORADO
