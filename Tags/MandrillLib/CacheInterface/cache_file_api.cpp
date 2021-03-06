#include "mandrilllib-private-pch.h"

BCSAPI BCS_RESULT get_cache_file_reader_engine_and_platform(const char* filepath, s_engine_platform_build* engine_platform_build)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	
	size_t buffer_length = strlen(filepath);
	wchar_t* buffer = new(alloca(sizeof(wchar_t) * (buffer_length + 1))) wchar_t[buffer_length];
	mbstowcs(buffer, filepath, buffer_length + 1);

	return get_cache_file_reader_engine_and_platform(buffer, engine_platform_build);
}

BCSAPI BCS_RESULT get_cache_file_reader_engine_and_platform(const wchar_t* filepath, s_engine_platform_build* engine_platform_build)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_VALIDATE_ARGUMENT(engine_platform_build);

	// #TODO determine the engine platform

	engine_platform_build->engine_type = _engine_type_halo4;
	engine_platform_build->platform_type = _platform_type_xbox_360;
	engine_platform_build->build = _build_not_set;

	return BCS_S_OK;
}

BCSAPI BCS_RESULT open_cache_file_reader(const char* filepath, s_engine_platform_build engine_platform_build, bool read_only, bool memory_mapped_file, c_cache_file_reader** cache_file)
{
	BCS_VALIDATE_ARGUMENT(filepath);

	size_t buffer_length = strlen(filepath);
	wchar_t* buffer = new(alloca(sizeof(wchar_t) * (buffer_length + 1))) wchar_t[buffer_length];
	mbstowcs(buffer, filepath, buffer_length + 1);

	return open_cache_file_reader(buffer, engine_platform_build, read_only, memory_mapped_file, cache_file);
}

BCSAPI BCS_RESULT open_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build, bool read_only, bool memory_mapped_file, c_cache_file_reader** cache_file)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_VALIDATE_ARGUMENT(engine_platform_build);
	BCS_VALIDATE_ARGUMENT(IS_VALID_BOOLEAN(read_only));
	BCS_VALIDATE_ARGUMENT(IS_VALID_BOOLEAN(memory_mapped_file));
	BCS_VALIDATE_ARGUMENT(cache_file);

	// #TODO plugin support

	try
	{
		switch (engine_platform_build.engine_type)
		{
		case _engine_type_halo4:
			if (engine_platform_build.platform_type == _platform_type_xbox_360)
			{
				*cache_file = new c_halo4_cache_file_reader(filepath);
				return BCS_S_OK;
			}
		}
	}
	catch (BCS_RESULT error_result)
	{
		return error_result;
	}
	catch (...)
	{
		return BCS_E_UNEXPECTED;
	}

	return BCS_E_UNSUPPORTED;
}

BCSAPI BCS_RESULT close_cache_file_reader(c_cache_file_reader* cache_reader)
{
	delete cache_reader;

	return BCS_S_OK;
}

BCSAPI BCS_RESULT get_cache_file_reader_build_info(c_cache_file_reader* cache_reader, s_cache_file_build_info* build_info)
{
	BCS_VALIDATE_ARGUMENT(build_info);
	return cache_reader->get_build_info(*build_info);
}

BCSAPI BCS_RESULT get_cache_file_reader_debug_info(c_cache_file_reader* cache_reader, s_cache_file_debug_info* debug_info)
{
	BCS_VALIDATE_ARGUMENT(debug_info);
	return cache_reader->get_debug_info(*debug_info);
}

BCSAPI BCS_RESULT get_cache_file_reader_buffer(c_cache_file_reader* cache_reader, e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info* buffer_info)
{
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(buffer_index < k_num_cache_file_buffers);
	BCS_VALIDATE_ARGUMENT(buffer_info);

	return cache_reader->get_buffer(buffer_index , *buffer_info);
}

BCSAPI BCS_RESULT get_cache_file_reader_buffers(c_cache_file_reader* cache_reader, s_cache_file_buffers_info* buffers_info)
{
	BCS_VALIDATE_ARGUMENT(buffers_info);
	return cache_reader->get_buffers(*buffers_info);
}

BCSAPI BCS_RESULT create_cache_cluster(c_cache_file_reader** cache_readers, uint32_t cache_reader_count, c_cache_cluster** cache_cluster)
{
	BCS_VALIDATE_ARGUMENT(cache_readers);
	BCS_VALIDATE_ARGUMENT(cache_reader_count > 0);
	BCS_VALIDATE_ARGUMENT(cache_cluster);

	try
	{
		if (c_halo4_cache_file_reader* halo4_cache_file = dynamic_cast<c_halo4_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new c_halo4_cache_cluster(reinterpret_cast<c_halo4_cache_file_reader**>(cache_readers), cache_reader_count);

			return BCS_S_OK;
		}
	}
	catch (BCS_RESULT error_result)
	{
		return error_result;
	}
	catch (...)
	{
		return BCS_E_UNEXPECTED;
	}

	return BCS_E_FAIL;
}

BCSAPI BCS_RESULT destroy_cache_cluster(c_cache_cluster* cache_cluster)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);

	delete cache_cluster;

	return BCS_S_OK;
}

BCSAPI BCS_RESULT get_cache_file_debug_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_debug_reader** debug_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(debug_reader);

	BCS_RESULT result = BCS_E_NOT_IMPLEMENTED;
	if (c_halo4_cache_cluster* halo4_cache_cluster = dynamic_cast<c_halo4_cache_cluster*>(cache_cluster))
	{
		result = halo4_cache_cluster->get_debug_reader(
			*static_cast<c_halo4_cache_file_reader*>(cache_reader), 
			*reinterpret_cast<c_halo4_debug_reader**>(debug_reader));
	}
	return result;
}

BCSAPI BCS_RESULT destroy_cache_file_debug_reader(c_debug_reader* debug_reader)
{
	BCS_VALIDATE_ARGUMENT(debug_reader);

	delete debug_reader;

	return BCS_S_OK;
}

BCSAPI BCS_RESULT get_cache_file_tag_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_tag_reader** tag_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(tag_reader);

	return cache_cluster->get_tag_reader(*cache_reader, *tag_reader);
}

BCSAPI BCS_RESULT destroy_cache_file_tag_reader(c_tag_reader* tag_reader)
{
	BCS_VALIDATE_ARGUMENT(tag_reader);

	delete tag_reader;

	return BCS_S_OK;
}

BCSAPI BCS_RESULT create_cache_file_resource_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_resource_reader** resource_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(resource_reader);

	return cache_cluster->get_resource_reader(*cache_reader, *resource_reader);
}

BCSAPI BCS_RESULT destroy_cache_file_resource_reader(c_resource_reader* resource_reader)
{
	BCS_VALIDATE_ARGUMENT(resource_reader);

	delete resource_reader;

	return BCS_S_OK;
}

BCSAPI BCS_RESULT create_cache_file_localization_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_localization_reader** localization_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(localization_reader);

	return cache_cluster->get_localization_reader(*cache_reader, *localization_reader);
}

BCSAPI BCS_RESULT destroy_cache_file_localization_reader(c_localization_reader* localization_reader)
{
	BCS_VALIDATE_ARGUMENT(localization_reader);

	delete localization_reader;

	return BCS_S_OK;
}
