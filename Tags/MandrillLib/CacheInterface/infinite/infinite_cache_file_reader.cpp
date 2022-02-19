#include "mandrilllib-private-pch.h"

c_infinite_module_file_reader::c_infinite_module_file_reader(const wchar_t* filepath, s_engine_platform_build _engine_platform_build) :
	filepath(filepath),
	engine_platform_build(_engine_platform_build),
	files(),
	file_infos(),
	cache_cluster(nullptr),
	module_file_header(nullptr)
{
	BCS_RESULT rs;


	for (unsigned long file_index = 0; file_index < k_max_module_files; file_index++)
	{
		c_fixed_wide_path module_file_path;
		if (file_index == 0)
		{
			module_file_path = filepath;
		}
		else
		{
			module_file_path.format(L"%s_hd%i", filepath, file_index);
		}

		if(BCS_FAILED(filesystem_filepath_exists(module_file_path)))
		{
			ASSERT(file_index > 0);
			break;
		}

		if (BCS_FAILED(rs = create_memory_mapped_file(module_file_path, true, files[file_index])))
		{
			throw(rs);
		}

		if (BCS_FAILED(rs = get_memory_mapped_file_info(files[file_index], file_infos[file_index])))
		{
			throw(rs);
		}
	}

	infinite::s_module_file_header_base* module_file_header_base = reinterpret_cast<infinite::s_module_file_header_base*>(file_infos[0].file_view_begin);

	module_file_header = static_cast<infinite::s_module_file_header*>(module_file_header_base);

	debug_point;
}

c_infinite_module_file_reader::~c_infinite_module_file_reader()
{
	for (unsigned long file_index = 0; file_index < k_max_module_files; file_index++)
	{
		ASSERT_NO_THROW(BCS_SUCCEEDED(destroy_memory_mapped_file(files[file_index])));
	}
}

BCS_RESULT c_infinite_module_file_reader::get_module_file_entry_structure_size(unsigned long& structure_size) const
{
	if (engine_platform_build.build >= _build_infinite_HIFLTA_202700_21_09_06_0001)
	{
		structure_size = sizeof(infinite::s_module_file_entry_51);
		return BCS_S_OK;
	}
	else if (engine_platform_build.build >= _build_infinite_FLT002INT_199229_21_07_20_0001)
	{
		structure_size = sizeof(infinite::s_module_file_entry_48);
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_infinite_module_file_reader::get_string_buffer_fixup_offset_hack(unsigned long& string_buffer_fixup_offset_hack) const
{
	if (engine_platform_build.build >= _build_infinite_HIFLTA_202700_21_09_06_0001)
	{
		string_buffer_fixup_offset_hack = 8;
		return BCS_S_OK;
	}
	else if (engine_platform_build.build >= _build_infinite_FLT002INT_199229_21_07_20_0001)
	{
		string_buffer_fixup_offset_hack = 0;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_infinite_module_file_reader::get_build_info(s_cache_file_build_info& build_info) const
{
	build_info.file_version = module_file_header->file_version;
	//build_info.file_length = module_file_header->file_length;
	//build_info.file_compressed_length = cache_file_header->file_compressed_length;
	//build_info.source_file = cache_file_header->source_file;
	//build_info.build_version = module_file_header->build_version;
	//build_info.scenario_type = cache_file_header->scenario_type;
	//build_info.scenario_load_type = cache_file_header->scenario_load_type;
	//build_info.tracked_build = cache_file_header->tracked_build;
	//build_info.header_flags = cache_file_header->header_flags;
	//build_info.shared_file_type_flags = cache_file_header->shared_file_type_flags;
	//build_info.timestamp = cache_file_header->timestamp;
	//build_info.name = module_file_header->scenario_name;
	//build_info.relative_path = cache_file_header->relative_path;
	//build_info.expected_base_address = cache_file_header->expected_base_address;
	//build_info.xdk_version = cache_file_header->xdk_version;
	//build_info.hash = cache_file_header->hash;
	//build_info.rsa = cache_file_header->rsa;

	return BCS_S_OK;
}

BCS_RESULT c_infinite_module_file_reader::get_debug_info(s_cache_file_debug_info& debug_info) const
{

	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_infinite_module_file_reader::get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const
{
	// #TODO: remove this by adding a function that determines if the cache file supports these features

	buffer_info.begin = file_infos[0].file_view_begin;
	buffer_info.end = nullptr;
	buffer_info.size = 0xFFFFFFFFul;
	buffer_info.offset = 0;
	buffer_info.offset_mask = 0;

	return BCS_S_OK;
}

//BCS_RESULT c_infinite_module_file_reader::get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const
//{
//	return BCS_E_UNSUPPORTED;
//}

BCS_RESULT c_infinite_module_file_reader::get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const
{
	BCS_RESULT rs = BCS_S_OK;
	switch (buffer_index)
	{
	case _module_file_buffer_root:
	{
		buffer_info.begin = file_infos[0].file_view_begin;
		buffer_info.end = file_infos[0].file_view_end;
		buffer_info.size = static_cast<unsigned long>(file_infos[0].file_size);
		return rs;
	}
	case _module_file_buffer_data0:
	case _module_file_buffer_data1:
	case _module_file_buffer_data2:
	case _module_file_buffer_data3:
	{
		if (buffer_index == _module_file_buffer_data1)
		{
			unsigned long file_info_index = buffer_index - _module_file_buffer_data0;
			buffer_info.begin = file_infos[file_info_index].file_view_begin;
			buffer_info.end = file_infos[file_info_index].file_view_end;
			buffer_info.size = static_cast<unsigned long>(file_infos[file_info_index].file_size);
		}
		else /*if (buffer_index == _module_file_buffer_data0)*/
		{
			// #TODO: This is pretty terrible??? Why is index 2 used now, but the data is inside of file 0
			unsigned long file_info_index = 0; // _module_file_buffer_data0
			buffer_info.begin = file_infos[file_info_index].file_view_begin;
			buffer_info.end = file_infos[file_info_index].file_view_end;
			buffer_info.size = static_cast<unsigned long>(file_infos[file_info_index].file_size);

			unsigned long file_entry_size;
			if (BCS_FAILED(rs = get_module_file_entry_structure_size(file_entry_size)))
			{
				return rs;
			}

			unsigned long string_buffer_fixup_offset_hack;
			if (BCS_FAILED(rs = get_string_buffer_fixup_offset_hack(string_buffer_fixup_offset_hack)))
			{
				return rs;
			}

			const infinite::s_module_file_header* module_file_header = reinterpret_cast<const infinite::s_module_file_header*>(buffer_info.begin);
			const char* file_entries = reinterpret_cast<const char*>(module_file_header + 1);
			const char* string_buffer = reinterpret_cast<const char*>(file_entries + module_file_header->num_files * file_entry_size);
			const infinite::s_module_resource_entry* resource_entries = reinterpret_cast<const infinite::s_module_resource_entry*>(string_buffer + module_file_header->string_table_length);
			const infinite::s_module_block_entry* block_entries = reinterpret_cast<const infinite::s_module_block_entry*>(resource_entries + module_file_header->num_resources);
			const char* module_file_data_section = reinterpret_cast<const char*>(block_entries + module_file_header->num_file_blocks);

			// #TODO: give this a home?
#define ROUND_UP_VALUE(value, alignment) ((((value) + (alignment) - 1) / (alignment)) * (alignment))
			module_file_data_section = reinterpret_cast<const char*>(ROUND_UP_VALUE(reinterpret_cast<intptr_t>(module_file_data_section), 0x1000));
#undef ROUND_UP_VALUE

			buffer_info.begin = module_file_data_section;
			// #NOTE: module_file_header->total_data_size is only populated when there is an extra module file (hd1)
			//buffer_info.end = buffer_info.begin + module_file_header->total_data_size;
			//buffer_info.size = module_file_header->total_data_size;
			buffer_info.size = static_cast<unsigned long>(buffer_info.end - buffer_info.begin);
		}

		return rs;
	}
	case _debug_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_debug, buffer_info);
	case _tag_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_tags, buffer_info);
	case _resources_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_resource, buffer_info);
	case _localization_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_localization, buffer_info);
	default:
		rs = BCS_E_UNSUPPORTED;
	}
	return rs;
}

BCS_RESULT c_infinite_module_file_reader::get_buffers(s_cache_file_buffers_info& buffers_info) const
{
	for (int cache_file_buffer_index = 0; cache_file_buffer_index < k_num_cache_file_buffers; cache_file_buffer_index++)
	{
		get_buffer(static_cast<e_cache_file_buffer_index>(cache_file_buffer_index), buffers_info.buffer_infos[cache_file_buffer_index]);
	}

	return BCS_S_OK;
}

BCS_RESULT c_infinite_module_file_reader::associate_cache_cluster(c_cache_cluster& target_cache_cluster)
{
	if (c_infinite_cache_cluster* infinite_cache_cluster = dynamic_cast<c_infinite_cache_cluster*>(&target_cache_cluster))
	{
		return associate_cache_cluster(*infinite_cache_cluster);
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_infinite_module_file_reader::associate_cache_cluster(c_infinite_cache_cluster& target_cache_cluster)
{
	if (cache_cluster == nullptr)
	{
		cache_cluster = &target_cache_cluster;
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT c_infinite_module_file_reader::virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const
{
	return BCS_E_UNSUPPORTED;
	//BCS_RESULT rs = BCS_S_OK;

	//s_cache_file_buffer_info buffer_info;
	//if (BCS_FAILED(rs = get_buffer(_tag_section_buffer, buffer_info)))
	//{
	//	return rs;
	//}

	//infinite::s_cache_file_tags_header tags_header = *reinterpret_cast<const infinite::s_cache_file_tags_header*>(buffer_info.begin);

	//relative_offset = static_cast<int32_t>(virtual_address - tags_header.tag_instances_address + sizeof(infinite::s_cache_file_tags_header));

	//return rs;
}

BCS_RESULT c_infinite_module_file_reader::page_offset_to_virtual_address(unsigned long page_offset, int64_t& virtual_address) const
{
	virtual_address = page_offset; // -cache_file_header->expected_base_address;

	return BCS_S_OK;
	//return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_infinite_module_file_reader::get_blofeld_tag_groups(const blofeld::s_tag_group**& tag_groups) const
{
	tag_groups = blofeld::tag_groups[engine_platform_build.engine_type];

	return BCS_S_OK;
}
//
//BCS_RESULT c_infinite_module_file_reader::get_cache_file_resource_instance(unsigned long index, const infinite::s_cache_file_resource_instance*& cache_file_resource_instance)
//{
//	BCS_RESULT rs = BCS_S_OK;
//
//	s_cache_file_buffer_info tag_section_buffer_info;
//	if (BCS_FAILED(rs = get_buffer(_tag_section_buffer, tag_section_buffer_info)))
//	{
//		return rs;
//	}
//
//	const infinite::s_cache_file_resource_instance* tag_instances = reinterpret_cast<const infinite::s_cache_file_resource_instance*>(tag_section_buffer_info.begin);
//	cache_file_resource_instance = tag_instances + index;
//
//	return rs;
//}
//
//BCS_RESULT c_infinite_module_file_reader::get_cache_file_resource_instance_data(unsigned long index, const void*& tag_instance_data)
//{
//	BCS_RESULT rs = BCS_S_OK;
//
//	const infinite::s_cache_file_resource_instance* cache_file_resource_instance;
//	if (BCS_FAILED(rs = get_cache_file_resource_instance(index, cache_file_resource_instance)))
//	{
//		return rs;
//	}
//
//	s_cache_file_buffer_info cache_file_buffer_info;
//	if (BCS_FAILED(rs = get_buffer(_cache_file_buffer, cache_file_buffer_info)))
//	{
//		return rs;
//	}
//
//	tag_instance_data = cache_file_buffer_info.begin + cache_file_resource_instance->address;
//
//	return rs;
//}
//
//BCS_RESULT c_infinite_module_file_reader::get_cache_file_resource_instance_name(unsigned long index, const char*& tag_instance_name)
//{
//	BCS_RESULT rs = BCS_S_OK;
//
//	const infinite::s_cache_file_resource_instance* cache_file_resource_instance;
//	if (BCS_FAILED(rs = get_cache_file_resource_instance(index, cache_file_resource_instance)))
//	{
//		return rs;
//	}
//
//	s_cache_file_buffer_info debug_section_buffer_info;
//	if (BCS_FAILED(rs = get_buffer(_debug_section_buffer, debug_section_buffer_info)))
//	{
//		return rs;
//	}
//
//	tag_instance_name = debug_section_buffer_info.begin + cache_file_resource_instance->name_address;
//
//	return rs;
//}


unsigned long c_infinite_module_file_reader::get_field_size(blofeld::e_field field)
{
	using namespace blofeld;

	switch (field)
	{
	case _field_block:
		return sizeof(s_infinite_ucs_block_field);
	case _field_data:
		return sizeof(s_infinite_ucs_data_reference_field);
	case _field_tag_reference:
		return sizeof(s_infinite_ucs_tag_reference_field);
	case _field_pageable:
		return sizeof(s_infinite_ucs_pageable_resource_field);
	}

	return get_blofeld_field_size(engine_platform_build.platform_type, field);
}

unsigned long c_infinite_module_file_reader::get_field_size(const blofeld::s_tag_field& field)
{
	using namespace blofeld;

	switch (field.field_type)
	{
	case _field_pad:							return field.padding;
	case _field_useless_pad:					return 0;
	case _field_skip:							return field.length;
	case _field_struct:
	{
		unsigned long structure_size = this->calculate_struct_size(*field.struct_definition);
		return structure_size;
	}
	case _field_array:
	{
		unsigned long structure_size = this->calculate_struct_size(field.array_definition->struct_definition);
		unsigned long array_element_count = field.array_definition->count(engine_platform_build);
		unsigned long array_size = structure_size * array_element_count;
		return array_size;
	}
	default: return get_field_size(field.field_type);
	}
}

unsigned long c_infinite_module_file_reader::calculate_struct_size(const blofeld::s_tag_struct_definition& struct_definition)
{
	using namespace blofeld;

	unsigned long computed_size = 0;

	for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
	{
		unsigned long field_skip_count;
		if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		unsigned long field_size = 0;
		switch (current_field->field_type)
		{
		case _field_useless_pad:
			//computed_size += current_field->padding;
			break;
		case _field_pad:
			field_size = current_field->padding;
			break;
		case _field_skip:
			field_size = current_field->length;
			break;
		case _field_struct:
			field_size = this->calculate_struct_size(*current_field->struct_definition);
			break;
		case _field_array:
		{
			const s_tag_array_definition& array_definition = *current_field->array_definition;
			REFERENCE_ASSERT(array_definition);
			const s_tag_struct_definition& struct_definition = array_definition.struct_definition;
			REFERENCE_ASSERT(struct_definition);
			unsigned long struct_size = this->calculate_struct_size(struct_definition);
			unsigned long array_data_size = struct_size * array_definition.count(engine_platform_build);
			field_size = array_data_size;
			break;
		}
		default:
			field_size = this->get_field_size(current_field->field_type);
			break;
		}

		computed_size += field_size;
	}

	//ASSERT((computed_size % (1u << struct_definition.alignment_bits)) == 0);

	return computed_size;
}

BCS_RESULT c_infinite_module_file_reader::data_offset_fixup(unsigned long long data_offset, unsigned long index, unsigned long long& fixed_offset)
{
	BCS_RESULT rs = BCS_S_OK;

	e_cache_file_buffer_index start = _module_file_buffer_data0;
	e_cache_file_buffer_index end = static_cast<e_cache_file_buffer_index>(_module_file_buffer_data0 + index);

	fixed_offset = data_offset;

	for (underlying(e_cache_file_buffer_index) buffer_index = start; buffer_index < end; buffer_index++)
	{
		s_cache_file_buffer_info data_module_buffer;
		if (BCS_FAILED(rs = get_buffer(static_cast<e_cache_file_buffer_index>(buffer_index), data_module_buffer)))
		{
			return rs;
		}

		fixed_offset -= data_module_buffer.size;
	}

	return rs;
}


