#include "highlevelcachefileserialization-private-pch.h"

c_eldorado_debug_reader::c_eldorado_debug_reader(c_eldorado_cache_cluster& cache_cluster, c_eldorado_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader),
	string_id_manager(k_string_id_index_bits, k_string_id_namespace_bits, k_string_id_length_bits),
	strings_file_header()
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = string_id_manager.init_from_engine_platform_build(cache_reader.engine_platform_build)))
	{
		throw(rs);
	}

	if (t_memory_mapped_file* string_ids_file = cache_reader.memory_mapped_files[_eldorado_file_type_string_ids])
	{
		s_memory_mapped_file_info& string_ids_file_info = cache_reader.memory_mapped_file_infos[_eldorado_file_type_string_ids];

		if (string_ids_file_info.file_size < sizeof(blofeld::eldorado::s_strings_file_header))
		{
			throw BCS_E_OUT_OF_RANGE;
		}

		blofeld::eldorado::s_strings_file_header* _strings_file_header = reinterpret_cast<blofeld::eldorado::s_strings_file_header*>(string_ids_file_info.file_view_begin);
		// byteswap_inplace(_cache_file_tags_header);
		strings_file_header = *_strings_file_header;

		unsigned int* string_offsets = next_contiguous_pointer(unsigned int, _strings_file_header);

		if (static_cast<void*>(string_offsets + strings_file_header.string_count) >= string_ids_file_info.file_view_end)
		{
			throw BCS_E_OUT_OF_RANGE;
		}

		const char* string_table = reinterpret_cast<const char*>(string_offsets + strings_file_header.string_count);

		for (unsigned int string_index = string_id_manager.get_total_engine_strings(); string_index < strings_file_header.string_count; string_index++)
		{
			unsigned int string_offset = string_offsets[string_index];

			const char* string = nullptr;
			if (string_offset != UINT_MAX)
			{
				if (string_table + string_offset >= string_ids_file_info.file_view_end)
				{
					throw BCS_E_OUT_OF_RANGE;
				}

				string = string_table + string_offset;

				if (string_ids_file_info.file_view_end < string)
				{
					throw BCS_E_OUT_OF_RANGE;
				}
			}

			string_id_manager.commit_string(0, string);
		}
	}
}

c_eldorado_debug_reader::~c_eldorado_debug_reader()
{

}

BCS_RESULT c_eldorado_debug_reader::string_id_to_string(string_id string_identifier, const char*& string)
{
	return string_id_manager.fetch_string(string_identifier, string);
}

BCS_RESULT c_eldorado_debug_reader::string_id_to_string(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, const char*& string)
{
	BCS_RESULT rs = BCS_S_OK;

	uint32_t string_identifier;
	if (BCS_FAILED(rs = string_id_manager.calculate_string_id(string_id_namespace, string_id_index, string_id_length, string_identifier)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = string_id_to_index(string_id_index, string_id_namespace, string_id_length, string_identifier)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT c_eldorado_debug_reader::get_tag_filepath(uint32_t tag_index, const char*& filepath)
{
	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_eldorado_debug_reader::get_group_name(tag group_tag, const char*& group_name)
{
	if (blofeld::t_tag_group_iterator tag_group_iterator = cache_reader.tag_groups)
	{
		do
		{
			blofeld::s_tag_group const& tag_group = **tag_group_iterator;
			if (tag_group.group_tag == group_tag)
			{
				group_name = tag_group.name;
				return BCS_S_OK;
			}
		} while (*++tag_group_iterator);
		return BCS_E_NOT_FOUND;
	}
	return BCS_E_NOT_SUPPORTED;
}

BCS_RESULT c_eldorado_debug_reader::get_group_id(tag group_tag, const char*& group_id)
{
	return BCS_E_DEPRECATED_UNSUPPORTED;
}

BCS_RESULT c_eldorado_debug_reader::string_id_to_index(string_id stringid, uint32_t& string_index)
{
	return BCS_E_NOT_SUPPORTED;
}

BCS_RESULT c_eldorado_debug_reader::string_id_to_index(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, uint32_t& string_index)
{
	return BCS_E_NOT_SUPPORTED;
}
