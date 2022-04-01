#include "mandrilllib-private-pch.h"

using namespace infinite;

c_infinite_tag_reader::c_infinite_tag_reader(c_infinite_cache_cluster& cache_cluster, c_infinite_module_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader),
	tag_groups(),
	tag_instances(),
	tag_instances_by_filepath(),
	file_entry_block_maps(),
	num_file_entry_block_maps(),
	tag_instance_infos(),
	num_tag_instance_infos()
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
	

	for (unsigned long file_entry_block_index = 0; file_entry_block_index < num_file_entry_block_maps; file_entry_block_index++)
	{
		c_infinite_file_entry_block_map* file_entry_block_map = file_entry_block_maps[file_entry_block_index];
		delete file_entry_block_map;
	}
	delete[] file_entry_block_maps;
	delete[] tag_instance_infos;
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

BCS_RESULT c_infinite_tag_reader::offset_to_data(unsigned long long offset, const char*& data)
{
	BCS_RESULT rs = BCS_S_OK;

	for (underlying(e_cache_file_buffer_index) buffer_index = _module_file_buffer_data0; buffer_index < _module_file_buffer_data3; buffer_index++)
	{
		s_cache_file_buffer_info data_module_buffer;
		if (BCS_FAILED(rs = cache_reader.get_buffer(static_cast<e_cache_file_buffer_index>(buffer_index), data_module_buffer)))
		{
			return rs;
		}

		if (offset > data_module_buffer.size)
		{
			offset -= data_module_buffer.size;
		}
		else
		{
			data = data_module_buffer.begin + offset;
			return rs;
		}
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

	unsigned long file_entry_size;
	if (BCS_FAILED(rs = this->cache_reader.get_module_file_entry_structure_size(file_entry_size)))
	{
		return rs;
	}

	unsigned long string_buffer_fixup_offset_hack;
	if (BCS_FAILED(rs = cache_reader.get_string_buffer_fixup_offset_hack(string_buffer_fixup_offset_hack)))
	{
		return rs;
	}

	const infinite::s_module_file_header* module_file_header = reinterpret_cast<const infinite::s_module_file_header*>(root_module_buffer.begin);
	const char* file_entries = reinterpret_cast<const char*>(module_file_header + 1);
	const char* string_buffer = reinterpret_cast<const char*>(file_entries + module_file_header->num_files * file_entry_size) + string_buffer_fixup_offset_hack;
	const infinite::s_module_resource_entry* resource_entries = reinterpret_cast<const infinite::s_module_resource_entry*>(string_buffer + module_file_header->string_table_length);
	const infinite::s_module_block_entry* block_entries = reinterpret_cast<const infinite::s_module_block_entry*>(resource_entries + module_file_header->num_resources);


	file_entry_block_maps = new() c_infinite_file_entry_block_map*[module_file_header->num_files];
	for (long file_entry_index = 0; file_entry_index < module_file_header->num_files; file_entry_index++)
	{
		const char* file_entry_pointer = file_entries + file_entry_size * file_entry_index;
		c_infinite_file_entry_block_map* file_entry_block_map = new() c_infinite_file_entry_block_map(
			file_entry_index,
			cache_reader,
			string_buffer,
			block_entries,
			file_entry_pointer,
			cache_reader.engine_platform_build
		);

		file_entry_block_maps[file_entry_index] = file_entry_block_map;

		if (file_entry_block_map->file_entry.group_tag != blofeld::INVALID_TAG)
		{
			num_tag_instance_infos++;
		}
	}

	tag_instance_infos = new() s_infinite_tag_instance_info[num_tag_instance_infos]{};
	for (long file_entry_index = 0, tag_instance_index = 0; file_entry_index < module_file_header->num_files; file_entry_index++)
	{
		c_infinite_file_entry_block_map& file_entry_block_map = *file_entry_block_maps[file_entry_index];
		infinite::c_infinite_generic_module_file_entry& file_entry = file_entry_block_map.file_entry;
		if (file_entry_block_map.file_entry.group_tag != blofeld::INVALID_TAG) // tag file
		{
			ASSERT(file_entry.parent_file_index == -1);
			s_infinite_tag_instance_info& tag_instance_info = tag_instance_infos[tag_instance_index];

			const blofeld::s_tag_group* tag_group = blofeld::get_tag_group_by_group_tag(cache_reader.engine_platform_build.engine_type, file_entry.group_tag);
			ASSERT(tag_group != nullptr);

			tag_instance_info.file_entry_block_map = &file_entry_block_map;
			tag_instance_info.filepath = file_entry_block_map.filepath;
			tag_instance_info.blofeld_tag_group = tag_group;

			file_entry_block_map.tag_index = tag_instance_index;

			void* data;
			BCS_RESULT rst1 = file_entry_block_map.map(data);
			BCS_RESULT rst2 = file_entry_block_map.unmap(data);

			tag_instance_index++;
		}
	}

	for (long file_entry_index = 0, tag_instance_index = 0; file_entry_index < module_file_header->num_files; file_entry_index++)
	{
		c_infinite_file_entry_block_map& file_entry_block_map = *file_entry_block_maps[file_entry_index];
		infinite::c_infinite_generic_module_file_entry& file_entry = file_entry_block_map.file_entry;

		if (file_entry_block_map.file_entry.group_tag == blofeld::INVALID_TAG && file_entry.parent_file_index != -1) // resource file
		{
			c_infinite_file_entry_block_map& parent_file_entry_block_map = *file_entry_block_maps[file_entry.parent_file_index];
			s_infinite_tag_instance_info& tag_instance_info = tag_instance_infos[parent_file_entry_block_map.tag_index];

			parent_file_entry_block_map.resource_file_entry_block_maps.push_back(&file_entry_block_map);
		}
	}
	

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

			tag_group = new() c_infinite_tag_group(cache_cluster, blofeld_tag_group, parent_tag_group);
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

	for(unsigned long tag_instance_index =0; tag_instance_index < num_tag_instance_infos; tag_instance_index++)
	{
		s_infinite_tag_instance_info& tag_instance_info = tag_instance_infos[tag_instance_index];
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

		c_infinite_tag_instance* tag_instance = new() c_infinite_tag_instance(
			cache_cluster,
			*tag_group,
			tag_instance_info.filepath,
			*tag_instance_info.file_entry_block_map
		);

		tag_instances.push_back(tag_instance);
		tag_instances_by_filepath[tag_instance_info.filepath] = tag_instance;
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

BCS_RESULT c_infinite_tag_reader::get_instance_info_by_tag_filepath(const char* filepath, const s_infinite_tag_instance_info*& instance_info)
{
	BCS_VALIDATE_ARGUMENT(filepath != nullptr);

	for (unsigned long tag_instance_index = 0; tag_instance_index < num_tag_instance_infos; tag_instance_index++)
	{
		s_infinite_tag_instance_info& tag_instance_info = tag_instance_infos[tag_instance_index];
		if (strcmp(tag_instance_info.filepath, filepath) == 0)
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

	long long virtual_address;
	if (BCS_FAILED(rs = cache_reader.page_offset_to_virtual_address(page_offset, virtual_address)))
	{
		return rs;
	}

	long relative_offset;
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
	BCS_RESULT rs = BCS_S_OK;
	for (c_infinite_tag_instance* tag_instance : tag_instances)
	{
		long _global_tag_id;
		if (BCS_FAILED(rs = tag_instance->get_global_tag_id(_global_tag_id)))
		{
			return rs;
		}
		if (_global_tag_id == global_tag_id)
		{
			out_tag_instance = tag_instance;
			return rs;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_infinite_tag_reader::get_tag_instance_by_global_tag_id_and_group_tag(long global_tag_id, tag group_tag, c_tag_instance*& out_tag_instance)
{
	BCS_RESULT rs = BCS_S_OK;
	c_infinite_tag_group* tag_group;
	if (BCS_SUCCEEDED(get_tag_group_by_group_tag(group_tag, tag_group)))
	{
		for (c_infinite_tag_instance* tag_instance : tag_instances)
		{
			// #TODO: store a list of tag_instances associated with the specific group to reduce iterations
			// this is better than nothing
			if (&tag_instance->tag_group == tag_group) 
			{
				if (strcmp(tag_instance->instance_name, "objects\\characters\\marine\\attachments\\helmet_goggles\\helmet_goggles.render_model") == 0)
				{
					
				}
				long _global_tag_id;
				if (BCS_FAILED(rs = tag_instance->get_global_tag_id(_global_tag_id)))
				{
					return rs;
				}
				if (_global_tag_id == global_tag_id)
				{
					out_tag_instance = tag_instance;
					return rs;
				}
			}
		}
	}
	return BCS_E_NOT_FOUND;
}
