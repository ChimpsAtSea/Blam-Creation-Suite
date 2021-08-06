#include "mandrilllib-private-pch.h"

using namespace infinite;

c_infinite_tag_reader::c_infinite_tag_reader(c_infinite_cache_cluster& cache_cluster, c_infinite_module_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader),
	tag_groups(),
	tag_instances(),
	tag_instances_by_filename(),
	tag_instance_infos()
{
	BCS_RESULT rs;

	if (BCS_FAILED(rs = read_tag_instances()))
	{
		throw(rs);
	}

	if (BCS_FAILED(rs = init_tag_groups()))
	{
		throw(rs);
	}

	if (BCS_FAILED(rs = init_tag_instances()))
	{
		throw(rs);
	}
}

c_infinite_tag_reader::~c_infinite_tag_reader()
{
}

BCS_RESULT decompress_buffer_zlib(
	const void* compressed_buffer,
	unsigned long compressed_buffer_size,
	void* uncompressed_buffer,
	unsigned long uncompressed_buffer_size)
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
	if (inflateResult < Z_OK)
	{
		return BCS_E_FAIL;
	}
	int inflateEndResult = inflateEnd(&stream);
	if (inflateEndResult < Z_OK)
	{
		return BCS_E_FAIL;
	}

	return BCS_S_OK;
}

BCS_RESULT decompress_buffer_oodle(
	const void* compressed_buffer,
	unsigned long compressed_buffer_size,
	void* uncompressed_buffer,
	unsigned long uncompressed_buffer_size)
{
	return BCS_E_FAIL;
}

BCS_RESULT c_infinite_tag_reader::data_offset_fixup(unsigned long offset, unsigned long index, unsigned long& fixed_offset)
{
	BCS_RESULT rs = BCS_S_OK;

	e_cache_file_buffer_index start = _module_file_buffer_data0;
	e_cache_file_buffer_index end = static_cast<e_cache_file_buffer_index>(_module_file_buffer_data0 + index);

	fixed_offset = offset;

	for (underlying(e_cache_file_buffer_index) buffer_index = start; buffer_index < end; buffer_index++)
	{
		s_cache_file_buffer_info data_module_buffer;
		if (BCS_FAILED(rs = cache_reader.get_buffer(static_cast<e_cache_file_buffer_index>(buffer_index), data_module_buffer)))
		{
			return rs;
		}

		fixed_offset -= data_module_buffer.size;
	}

	return rs;
}

BCS_RESULT c_infinite_tag_reader::read_tag_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	s_cache_file_buffer_info root_module_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_module_file_buffer_root, root_module_buffer)))
	{
		return rs;
	}

	const infinite::s_module_file_header* module_file_header = reinterpret_cast<const infinite::s_module_file_header*>(root_module_buffer.begin);
	const infinite::s_module_file_entry* file_entries = reinterpret_cast<const infinite::s_module_file_entry*>(module_file_header + 1);
	const char* string_buffer = reinterpret_cast<const char*>(file_entries + module_file_header->num_files);
	const infinite::s_module_resource_entry* resource_entries = reinterpret_cast<const infinite::s_module_resource_entry*>(string_buffer + module_file_header->string_table_length);
	const infinite::s_module_block_entry* block_entries = reinterpret_cast<const infinite::s_module_block_entry*>(resource_entries + module_file_header->num_resources);
	//const char* module_file_data_section = reinterpret_cast<const char*>(block_entries + module_file_header->num_file_blocks);

	for (long file_entry_index = 0; file_entry_index < module_file_header->num_files; file_entry_index++)
	{
		const infinite::s_module_file_entry& file_entry = file_entries[file_entry_index];
		if (file_entry.group_tag != blofeld::INVALID_TAG)
		{

			s_cache_file_buffer_info data_module_buffer;
			if (BCS_FAILED(rs = cache_reader.get_buffer(static_cast<e_cache_file_buffer_index>(_module_file_buffer_data0 + file_entry.data_file_index), data_module_buffer)))
			{
				return rs;
			}
			const char* module_file_data_section = data_module_buffer.begin;

			const char* name = string_buffer + file_entry.name_offset;
			//c_console::write_line(name);
			//c_console::write_line("0x%X", file_entry.unknown);

			unsigned long x = file_entry.uncompressed_header_data_size + file_entry.uncompressed_tag_data_size + file_entry.uncompressed_resource_data_size + file_entry.unknown_data_size;
			ASSERT(file_entry.flags.test(_module_file_flag_raw_file) || x == file_entry.total_uncompressed_size);

			debug_point;

			char* file_entry_data = new char[file_entry.total_uncompressed_size];
			memset(file_entry_data, 0xAC, file_entry.total_uncompressed_size);
			char* file_entry_block_data[16] = { file_entry_data };

			unsigned long linear_offset = file_entry.data_offset;
			unsigned long relative_offset;
			ASSERT(BCS_SUCCEEDED(data_offset_fixup(linear_offset, file_entry.data_file_index, relative_offset)));

			const char* file_entry_raw_data = module_file_data_section + relative_offset;

			if (file_entry.flags.test(_module_file_flag_has_blocks))
			{
				for (long block_index = 0; block_index < file_entry.block_count; block_index++)
				{
					const infinite::s_module_block_entry& block_entry = block_entries[file_entry.first_block_index + block_index];

					char* block_data = file_entry_data + block_entry.uncompressed_offset;
					const char* block_raw_data = file_entry_raw_data + block_entry.compressed_offset;
					if (block_entry.compressed)
					{
						BCS_RESULT decompress_result = decompress_buffer_oodle(block_raw_data, block_entry.compressed_size, block_data, block_entry.uncompressed_size);
						ASSERT(BCS_SUCCEEDED(decompress_result));
						debug_point;
					}
					else
					{
						ASSERT(block_entry.compressed_size == block_entry.uncompressed_size);
						memcpy(block_data, block_raw_data, block_entry.uncompressed_size);
						debug_point;
					}

					file_entry_block_data[block_index] = block_data;

					debug_point;
				}
			}
			else
			{

				ASSERT(file_entry.flags.test(_module_file_flag_raw_file));

				if (file_entry.flags.test(_module_file_flag_compressed))
				{
					BCS_RESULT decompress_result = decompress_buffer_oodle(file_entry_raw_data, file_entry.total_compressed_size, file_entry_data, file_entry.total_uncompressed_size);
					ASSERT(BCS_SUCCEEDED(decompress_result));
					debug_point;
				}
				else
				{
					memcpy(file_entry_data, file_entry_raw_data, file_entry.total_uncompressed_size);
				}
			}

			const blofeld::s_tag_group* tag_group = blofeld::get_group_tag_by_group_tag(cache_reader.engine_platform_build.engine_type, file_entry.group_tag);
			ASSERT(tag_group != nullptr);

			s_infinite_tag_instance_info& tag_instance_info = tag_instance_infos.emplace_back();

			tag_instance_info.file_entry = &file_entry;
			tag_instance_info.file_name = name;
			tag_instance_info.instance_name = name;
			tag_instance_info.instance_data = file_entry_data;
			for (unsigned long i = 0; i < __min(_countof(tag_instance_info.instance_block_data), _countof(file_entry_block_data)); i++) 
				tag_instance_info.instance_block_data[i] = file_entry_block_data[i];
			tag_instance_info.blofeld_tag_group = tag_group;
			tag_instance_info.tag_group = nullptr;
		}

	}

	debug_point;

	return rs;
}

BCS_RESULT c_infinite_tag_reader::init_tag_groups()
{
	BCS_RESULT rs = BCS_S_OK;

	const blofeld::s_tag_group** blofeld_tag_groups;
	if (BCS_FAILED(rs = cache_cluster.get_blofeld_tag_groups(blofeld_tag_groups)))
	{
		return rs;
	}

	unsigned long tag_group_count = 0; // #TODO: create a function for this
	for (const blofeld::s_tag_group** tag_group_iterator = blofeld_tag_groups; *tag_group_iterator; tag_group_iterator++)
	{
		tag_group_count++;
	}

	bool added_tag_group = false;
	do
	{
		added_tag_group = false;
		for (const blofeld::s_tag_group** tag_group_iterator = blofeld_tag_groups; *tag_group_iterator; tag_group_iterator++)
		{
			const blofeld::s_tag_group& blofeld_tag_group = **tag_group_iterator;

			c_infinite_tag_group* tag_group = nullptr;
			if (BCS_SUCCEEDED(get_tag_group_by_group_tag(blofeld_tag_group.group_tag, tag_group)))
			{
				continue; // skip groups already added
			}

			c_infinite_tag_group* parent_tag_group = nullptr;
			if (blofeld_tag_group.parent_tag_group)
			{
				if (BCS_FAILED(get_tag_group_by_group_tag(blofeld_tag_group.parent_group_tag, parent_tag_group)))
				{
					continue;
				}
			}

			tag_group = new c_infinite_tag_group(cache_cluster, blofeld_tag_group, parent_tag_group);
			tag_groups.push_back(tag_group);
			added_tag_group = true;
		}
	} while (added_tag_group);
	ASSERT(tag_groups.size() >= tag_group_count);

	return rs;
}

BCS_RESULT c_infinite_tag_reader::init_tag_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	for (s_infinite_tag_instance_info& tag_instance_info : tag_instance_infos)
	{
#if !INF_DONT_PROCESS_TAG_DATA
		// skip null tags
		if (tag_instance_info.instance_data == nullptr) // #NOTE: is this the best way to do this?
		{
			continue;
}
#endif

		c_infinite_tag_group* tag_group;
		if (BCS_FAILED(rs = get_tag_group_by_blofeld_tag_group(*tag_instance_info.blofeld_tag_group, tag_group)))
		{
			return rs;
		}

		c_infinite_tag_instance* tag_instance = new c_infinite_tag_instance(
			cache_cluster,
			*tag_group,
			tag_instance_info.instance_name,
			tag_instance_info.instance_data,
			tag_instance_info.instance_block_data,
			tag_instance_info.file_entry
		);

		tag_instances.push_back(tag_instance);
		tag_instances_by_filename[tag_instance_info.file_name] = tag_instance;
	}

	return rs;
}

BCS_RESULT c_infinite_tag_reader::get_tag_group_by_group_tag(tag in_group_tag, c_infinite_tag_group*& out_tag_group) const
{
	for (c_infinite_tag_group* tag_group : tag_groups)
	{
		tag group_tag;
		ASSERT(BCS_SUCCEEDED(tag_group->get_group_tag(group_tag)));
		if (group_tag == in_group_tag)
		{
			out_tag_group = tag_group;
			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_infinite_tag_reader::get_tag_group_by_blofeld_tag_group(const blofeld::s_tag_group& in_blofeld_tag_group, c_infinite_tag_group*& out_tag_group) const
{
	for (c_infinite_tag_group* tag_group : tag_groups)
	{
		const blofeld::s_tag_group* blofeld_tag_group;
		ASSERT(BCS_SUCCEEDED(tag_group->get_blofeld_tag_group(blofeld_tag_group)));

		if (blofeld_tag_group == &in_blofeld_tag_group)
		{
			out_tag_group = tag_group;
			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_infinite_tag_reader::get_instance_info_by_tag_filename(const char* filename, const s_infinite_tag_instance_info*& instance_info)
{
	BCS_VALIDATE_ARGUMENT(filename != nullptr);

	for (s_infinite_tag_instance_info& tag_instance_info : tag_instance_infos)
	{
		if (strcmp(tag_instance_info.instance_name, filename) == 0)
		{
			instance_info = &tag_instance_info;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_infinite_tag_reader::page_offset_to_pointer(long page_offset, const void*& data)
{
	BCS_RESULT rs = BCS_S_OK;

	if (page_offset == 0)
	{
		data = nullptr;
		return rs;
	}

	s_cache_file_buffer_info tag_section_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
	{
		return rs;
	}

	int64_t virtual_address;
	if (BCS_FAILED(rs = cache_reader.page_offset_to_virtual_address(page_offset, virtual_address)))
	{
		return rs;
	}

	int32_t relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(virtual_address, relative_offset)))
	{
		return rs;
	}

	const char* data_pointer = tag_section_buffer.begin + relative_offset;

	data = data_pointer;

	return rs;
}

BCS_RESULT c_infinite_tag_reader::get_tag_groups(c_infinite_tag_group**& out_tag_groups, unsigned long& out_tag_group_count)
{
	out_tag_groups = tag_groups.data();
	out_tag_group_count = static_cast<unsigned long>(tag_groups.size());
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_reader::get_tag_groups(c_tag_group**& out_tag_groups, unsigned long& out_tag_group_count)
{
	out_tag_groups = reinterpret_cast<c_tag_group**>(tag_groups.data());
	out_tag_group_count = static_cast<unsigned long>(tag_groups.size());
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_reader::get_tag_instances(c_infinite_tag_instance**& out_tag_instances, unsigned long& out_tag_instance_count)
{
	out_tag_instances = tag_instances.data();
	out_tag_instance_count = static_cast<unsigned long>(tag_instances.size());
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_reader::get_tag_instances(c_tag_instance**& out_tag_instances, unsigned long& out_tag_instance_count)
{
	out_tag_instances = reinterpret_cast<c_tag_instance**>(tag_instances.data());
	out_tag_instance_count = static_cast<unsigned long>(tag_instances.size());
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_reader::get_tag_instance_by_cache_file_tag_index(unsigned long cache_file_tag_index, c_tag_instance*& out_tag_instance)
{
	for (c_infinite_tag_instance* tag_instance : tag_instances)
	{
		//if(tag_instance->ucs_reader->ucs_header->)
	}
	return BCS_E_UNSUPPORTED;
}

#include <LowLevel/low_level_infinite/lowlevel-infinite-public-pch.h>

BCS_RESULT c_infinite_tag_reader::get_tag_instance_by_global_tag_id(unsigned long global_tag_id, c_tag_instance*& out_tag_instance)
{
	for (c_infinite_tag_instance* tag_instance : tag_instances)
	{
		if (tag_instance->file_entry->asset_checksum32 == global_tag_id)
		{
			out_tag_instance = tag_instance;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_infinite_tag_reader::get_tag_instance_by_global_tag_id_and_group_tag(long global_tag_id, tag group_tag, c_tag_instance*& out_tag_instance)
{
	c_infinite_tag_group* tag_group;
	if (BCS_SUCCEEDED(get_tag_group_by_group_tag(group_tag, tag_group)))
	{
		for (c_infinite_tag_instance* tag_instance : tag_instances)
		{
			// #TODO: store a list of tag_instances associated with the specific group to reduce iterations
			// this is better than nothing
			if (&tag_instance->tag_group == tag_group) 
			{
				if (tag_instance->file_entry->asset_checksum32 == global_tag_id)
				{
					out_tag_instance = tag_instance;
					return BCS_S_OK;
				}
			}
		}
	}
	return BCS_E_NOT_FOUND;
}
