#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(blamlib::s_cache_file_header& value)
{
	byteswap_inplace(value.header_signature);
	byteswap_inplace(value.file_version);
	byteswap_inplace(value.file_length);
	byteswap_inplace(value.file_compressed_length);
}

BCS_RESULT get_cache_file_reader_engine_and_platform(const char* filepath, s_engine_platform_build* engine_platform_build)
{
	BCS_VALIDATE_ARGUMENT(filepath);

	size_t buffer_length = strlen(filepath);
	wchar_t* buffer = new(alloca(sizeof(wchar_t) * (buffer_length + 1))) wchar_t[buffer_length];
	mbstowcs(buffer, filepath, buffer_length + 1);

	return get_cache_file_reader_engine_and_platform(buffer, engine_platform_build);
}

BCS_RESULT get_cache_file_reader_engine_and_platform(const wchar_t* filepath, s_engine_platform_build* engine_platform_build)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_VALIDATE_ARGUMENT(engine_platform_build);

	FILE* file_handle = _wfopen(filepath, L"rb");
	if (file_handle == nullptr)
	{
		return BCS_E_FAIL;
	}

	_fseeki64(file_handle, 0, SEEK_SET);

	blamlib::s_cache_file_header header;
	if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
	{
		return BCS_E_FAIL;
	}
	_fseeki64(file_handle, 0, SEEK_SET);

	if (header.header_signature == _byteswap_ulong('mohd'))
	{
		// #TODO: support Halo 5 Forge

		// #TODO: Detect version based off executable?

		*engine_platform_build = { _engine_type_haloinfinite, _platform_type_pc_64bit, _build_infinite_FLT002INT_199229_21_07_20_0001 };

		switch (header.file_version)
		{
		case 48: engine_platform_build->build = _build_infinite_FLT002INT_199229_21_07_20_0001; break;
		case 51:
			engine_platform_build->build = _build_infinite_HIFLTA_202700_21_09_06_0001;
			engine_platform_build->build = _build_infinite_HIREL_209048_21_12_09_1546; // #TODO: detect version of 51
			break;
		default: throw(BCS_E_UNSUPPORTED);
		}

		return BCS_S_OK;
	}

	bool is_big_endian = false;
	if (header.header_signature == _byteswap_ulong('head'))
	{
		is_big_endian = true;
		byteswap_inplace(header);
	}

	//if (header.header_signature == 'head')
	{
		if (header.file_version == 11)
		{
			ASSERT(header.header_signature == k_cache_header_signature);

			if (is_big_endian)
			{
				*engine_platform_build = { _engine_type_halo3, _platform_type_xbox_360, _build_not_set };
			}
			return BCS_S_OK;
		}
		else if (header.file_version == 5)
		{
			ASSERT(header.header_signature == k_cache_header_signature);

			halo1::pc::s_cache_file_header header;
			if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
			{
				return BCS_E_FAIL;
			}

			if (header.build_version.is_empty())
			{
				// #TODO: check for 32bit stubbs
				*engine_platform_build = { _engine_type_stubbs, _platform_type_pc_64bit, _build_stubbs };
			}
			else
			{
				// #TODO: validate xbox build
				*engine_platform_build = { _engine_type_halo1, _platform_type_xbox, _build_halo1_xbox };
			}

			return BCS_S_OK;
		}
		else if (header.file_version == 6)
		{
			if (header.header_signature == k_cache_header_signature)
			{
				halo1::pc::s_cache_file_header header;
				if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				if (strcmp(header.build_version.get_buffer(), "01.05.22.0268") == 0)
				{
					*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_beta_01_05_22_0268 };
					return BCS_S_OK;
				}
			}
			else
			{
				halo1::pc::s_cache_file_header header;
				if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
				{
					return BCS_E_FAIL;
				}
				// #TODO: validate demo build
				*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_demo };
				return BCS_S_OK;
			}
		}
		else if (header.file_version == 7)
		{
			halo1::demo::s_cache_file_header header;
			if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
			{
				return BCS_E_FAIL;
			}
			// #TODO: validate retail build
			*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_pc_retail };
			return BCS_S_OK;
		}
		else if (header.file_version == 609)
		{
			halo1::pc::s_cache_file_header header;
			if (!fread(&header, 1, sizeof(header), file_handle)) // #TODO: pipe BCS result
			{
				return BCS_E_FAIL;
			}
			if (strcmp(header.build_version.get_buffer(), "01.00.00.0609") == 0)
			{
				*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_custom_edition };
				return BCS_S_OK;
			}
		}
		else
		{
			// #TODO:
			*engine_platform_build = { _engine_type_halo1, _platform_type_pc_32bit, _build_halo1_custom_edition };
			return BCS_S_OK;
		}

		// #TODO determine the engine platform

		engine_platform_build->engine_type = _engine_type_halo4;
		engine_platform_build->platform_type = _platform_type_xbox_360;
		engine_platform_build->build = _build_not_set;

		return BCS_S_OK;
	}
	return BCS_E_FAIL;
}

BCS_RESULT open_cache_file_reader(const char* filepath, s_engine_platform_build engine_platform_build, bool read_only, bool memory_mapped_file, c_cache_file_reader** cache_file)
{
	BCS_VALIDATE_ARGUMENT(filepath);

	size_t buffer_length = strlen(filepath);
	wchar_t* buffer = new(alloca(sizeof(wchar_t) * (buffer_length + 1))) wchar_t[buffer_length];
	mbstowcs(buffer, filepath, buffer_length + 1);

	return open_cache_file_reader(buffer, engine_platform_build, read_only, memory_mapped_file, cache_file);
}

BCS_RESULT open_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build, bool read_only, bool memory_mapped_file, c_cache_file_reader** cache_file)
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
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_1) || defined(BCS_BUILD_HIGH_LEVEL_STUBBS)
		case _engine_type_stubbs:
		case _engine_type_halo1:
		{
			switch (engine_platform_build.platform_type)
			{
			case _platform_type_xbox:
			case _platform_type_pc_32bit:
			case _platform_type_pc_64bit:
				*cache_file = new() c_halo1_cache_file_reader(filepath, engine_platform_build);
				return BCS_S_OK;
			}
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_3)
		case _engine_type_halo3:
		{
			*cache_file = new() c_halo3_cache_file_reader(filepath, engine_platform_build);
			return BCS_S_OK;
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_4)
		case _engine_type_halo4:
		{
			//if (engine_platform_build.platform_type == _platform_type_xbox_360)
			//{
			//	*cache_file = new() c_halo4_cache_file_reader(filepath, engine_platform_build);
			//	return BCS_S_OK;
			//}
		}
		break;
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_INFINITE)
		case _engine_type_haloinfinite:
		{
			if (engine_platform_build.platform_type == _platform_type_pc_64bit)
			{
				*cache_file = new() c_infinite_module_file_reader(filepath, engine_platform_build);
				return BCS_S_OK;
			}
			break;
		}
#endif
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

BCS_RESULT close_cache_file_reader(c_cache_file_reader* cache_reader)
{
	delete cache_reader;

	return BCS_S_OK;
}

BCS_RESULT get_cache_file_reader_build_info(c_cache_file_reader* cache_reader, s_cache_file_build_info* build_info)
{
	BCS_VALIDATE_ARGUMENT(build_info);
	return cache_reader->get_build_info(*build_info);
}

BCS_RESULT get_cache_file_reader_debug_info(c_cache_file_reader* cache_reader, s_cache_file_debug_info* debug_info)
{
	BCS_VALIDATE_ARGUMENT(debug_info);
	return cache_reader->get_debug_info(*debug_info);
}

BCS_RESULT get_cache_file_reader_buffer(c_cache_file_reader* cache_reader, e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info* buffer_info)
{
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(buffer_index < k_num_cache_file_buffers);
	BCS_VALIDATE_ARGUMENT(buffer_info);

	return cache_reader->get_buffer(buffer_index, *buffer_info);
}

BCS_RESULT get_cache_file_reader_buffers(c_cache_file_reader* cache_reader, s_cache_file_buffers_info* buffers_info)
{
	BCS_VALIDATE_ARGUMENT(buffers_info);
	return cache_reader->get_buffers(*buffers_info);
}

BCS_RESULT create_cache_cluster(c_cache_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build, c_cache_cluster** cache_cluster)
{
	BCS_VALIDATE_ARGUMENT(cache_readers);
	BCS_VALIDATE_ARGUMENT(cache_reader_count > 0);
	BCS_VALIDATE_ARGUMENT(cache_cluster);

	try
	{
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_1)
		if (c_halo1_cache_file_reader* halo1_cache_file = dynamic_cast<c_halo1_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_halo1_cache_cluster(reinterpret_cast<c_halo1_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_3)
		if (c_halo3_cache_file_reader* halo3_cache_file = dynamic_cast<c_halo3_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_halo3_cache_cluster(reinterpret_cast<c_halo3_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_4)
		/*if (c_halo4_cache_file_reader* halo4_cache_file = dynamic_cast<c_halo4_cache_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_halo4_cache_cluster(reinterpret_cast<c_halo4_cache_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}*/
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_INFINITE)
		if (c_infinite_module_file_reader* infinite_module_file = dynamic_cast<c_infinite_module_file_reader*>(*cache_readers))
		{
			*cache_cluster = new() c_infinite_cache_cluster(reinterpret_cast<c_infinite_module_file_reader**>(cache_readers), cache_reader_count, engine_platform_build);

			return BCS_S_OK;
		}
#endif
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

BCS_RESULT destroy_cache_cluster(c_cache_cluster* cache_cluster)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);

	delete cache_cluster;

	return BCS_S_OK;
}

BCS_RESULT get_cache_file_debug_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_debug_reader** debug_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(debug_reader);

	BCS_RESULT result = BCS_E_NOT_IMPLEMENTED;
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_3)
	if (c_halo3_cache_cluster* halo3_cache_cluster = dynamic_cast<c_halo3_cache_cluster*>(cache_cluster))
	{
		result = halo3_cache_cluster->get_debug_reader(
			*static_cast<c_halo3_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_halo3_debug_reader**>(debug_reader));
	}
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO_4)
	/*if (c_halo4_cache_cluster* halo4_cache_cluster = dynamic_cast<c_halo4_cache_cluster*>(cache_cluster))
	{
		result = halo4_cache_cluster->get_debug_reader(
			*static_cast<c_halo4_cache_file_reader*>(cache_reader),
			*reinterpret_cast<c_halo4_debug_reader**>(debug_reader));
	}*/
#endif
	return result;
}

BCS_RESULT destroy_cache_file_debug_reader(c_debug_reader* debug_reader)
{
	BCS_VALIDATE_ARGUMENT(debug_reader);

	delete debug_reader;

	return BCS_S_OK;
}

BCS_RESULT get_cache_file_tag_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_tag_reader** tag_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(tag_reader);

	return cache_cluster->get_tag_reader(*cache_reader, *tag_reader);
}

BCS_RESULT destroy_cache_file_tag_reader(c_tag_reader* tag_reader)
{
	BCS_VALIDATE_ARGUMENT(tag_reader);

	delete tag_reader;

	return BCS_S_OK;
}

BCS_RESULT create_cache_file_resource_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_resource_reader** resource_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(resource_reader);

	return cache_cluster->get_resource_reader(*cache_reader, *resource_reader);
}

BCS_RESULT destroy_cache_file_resource_reader(c_resource_reader* resource_reader)
{
	BCS_VALIDATE_ARGUMENT(resource_reader);

	delete resource_reader;

	return BCS_S_OK;
}

BCS_RESULT create_cache_file_localization_reader(c_cache_cluster* cache_cluster, c_cache_file_reader* cache_reader, c_localization_reader** localization_reader)
{
	BCS_VALIDATE_ARGUMENT(cache_cluster);
	BCS_VALIDATE_ARGUMENT(cache_reader);
	BCS_VALIDATE_ARGUMENT(localization_reader);

	return cache_cluster->get_localization_reader(*cache_reader, *localization_reader);
}

BCS_RESULT destroy_cache_file_localization_reader(c_localization_reader* localization_reader)
{
	BCS_VALIDATE_ARGUMENT(localization_reader);

	delete localization_reader;

	return BCS_S_OK;
}
