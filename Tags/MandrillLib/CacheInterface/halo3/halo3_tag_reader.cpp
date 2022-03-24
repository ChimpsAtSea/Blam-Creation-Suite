#include "mandrilllib-private-pch.h"

using namespace blofeld;
using namespace blofeld::halo3;

c_halo3_tag_reader::c_halo3_tag_reader(c_halo3_cache_cluster& cache_cluster, c_halo3_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader),
	pc_tags_header(),
	tag_groups(),
	tag_instances(),
	tag_instances_by_index(),
	tag_group_infos(),
	tag_instance_infos(),
	tag_global_instance_infos(),
	//t_tag_interop_infos tag_interop_infos(),
	_interop_type_index_to_halo3_interop_type(nullptr),
	interop_containers(nullptr),
	_shared_file_index_to_cache_file_reader(nullptr),
	_shared_file_count(0),
	high_level_resources(nullptr),
	num_high_level_resources(0)
{
	BCS_RESULT rs;

	if (BCS_FAILED(rs = read_tags_header()))
	{
		throw(rs);
	}
	if (BCS_FAILED(rs = read_tag_groups()))
	{
		throw(rs);
	}
	if (BCS_FAILED(rs = read_tag_instances()))
	{
		throw(rs);
	}
	if (BCS_FAILED(rs = read_tag_global_instances()))
	{
		throw(rs);
	}
	if (BCS_FAILED(rs = read_tag_interops()))
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
	//if (BCS_FAILED(rs = init_tag_global_instances()))
	//{
	//	throw(rs);
	//}
	//if (BCS_FAILED(rs = init_tag_interops()))
	//{
	//	throw(rs);
	//}
}

c_halo3_tag_reader::~c_halo3_tag_reader()
{
	delete _interop_type_index_to_halo3_interop_type;
	delete interop_containers;
	delete _shared_file_index_to_cache_file_reader;
}

BCS_RESULT c_halo3_tag_reader::read_tags_header()
{
	BCS_RESULT rs = BCS_S_OK;

	s_cache_file_buffer_info tag_section_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
	{
		return rs;
	}

	long tags_header_relative_offset;
	if (BCS_FAILED(rs = cache_reader.get_tags_header_relative_offset(tags_header_relative_offset)))
	{
		return rs;
	}

	switch (cache_cluster.engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		xbox360_tags_header = *reinterpret_cast<const ::halo3::xbox360::s_cache_file_tags_header*>(tag_section_buffer.begin + tags_header_relative_offset);
		byteswap_inplace(xbox360_tags_header);
		if (xbox360_tags_header.tags_signature != 'tags')
		{
			return BCS_E_FAIL;
		}
		break;
	case _platform_type_pc_64bit:
		pc_tags_header = *reinterpret_cast<const ::halo3::pc::s_cache_file_tags_header*>(tag_section_buffer.begin + tags_header_relative_offset);
		if (pc_tags_header.tags_signature != 'tags')
		{
			return BCS_E_FAIL;
		}
		break;
	}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::get_tag_groups_section(::halo3::s_section& tag_groups)
{
	switch (cache_cluster.engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		tag_groups = xbox360_tags_header.tag_groups;
		return BCS_S_OK;
	case _platform_type_pc_64bit:
		tag_groups = pc_tags_header.tag_groups;
		break;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_tag_reader::get_tag_instances_section(::halo3::s_section& tag_instances)
{
	switch (cache_cluster.engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		tag_instances = xbox360_tags_header.tag_instances;
		return BCS_S_OK;
	case _platform_type_pc_64bit:
		tag_instances = pc_tags_header.tag_instances;
		break;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_tag_reader::get_global_tag_instances_section(::halo3::s_section& global_tag_instances)
{
	switch (cache_cluster.engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		global_tag_instances = xbox360_tags_header.global_tag_instances;
		return BCS_S_OK;
	case _platform_type_pc_64bit:
		global_tag_instances = pc_tags_header.global_tag_instances;
		break;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_tag_reader::get_tag_interop_table_section(::halo3::s_section& tag_interop_table)
{
	switch (cache_cluster.engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		tag_interop_table = xbox360_tags_header.tag_interop_table;
		return BCS_S_OK;
	case _platform_type_pc_64bit:
		tag_interop_table = pc_tags_header.tag_interop_table;
		break;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_tag_reader::read_tag_groups()
{
	BCS_RESULT rs = BCS_S_OK;

	c_halo3_debug_reader* debug_reader;
	if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_reader, debug_reader)))
	{
		return rs;
	}

	s_cache_file_buffer_info tag_section_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
	{
		return rs;
	}

	::halo3::s_section tag_groups_section;
	if (BCS_FAILED(rs = get_tag_groups_section(tag_groups_section)))
	{
		return rs;
	}

	long tag_groups_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tag_groups_section.address, tag_groups_relative_offset)))
	{
		return rs;
	}

	tag_group_infos.resize(tag_groups_section.count);
	const ::halo3::s_cache_file_tag_group * tag_groups_read_pointer = reinterpret_cast<const ::halo3::s_cache_file_tag_group*>(tag_section_buffer.begin + tag_groups_relative_offset);
	for (unsigned long group_index = 0; group_index < tag_groups_section.count; group_index++)
	{
		s_halo3_tag_group_info& tag_group_info = tag_group_infos[group_index];
		::halo3::s_cache_file_tag_group& tag_group = tag_group_info.group = tag_groups_read_pointer[group_index];
		cache_reader.byteswap_inplace(tag_group);

		tag group_tag = tag_group_info.group.group_tags[0];
		if (group_tag == blofeld::halo3::CACHE_FILE_SOUND_TAG)
		{
			debug_point;
		}

		const blofeld::s_tag_group* blofeld_tag_group = blofeld::get_tag_group_by_group_tag(cache_reader.engine_platform_build.engine_type, group_tag);
		ASSERT(blofeld_tag_group != nullptr);
		tag_group_info.blofeld_tag_group = blofeld_tag_group;
		tag_group_info.tag_group = nullptr; // deferred : init_tag_groups

		if (BCS_FAILED(rs = debug_reader->string_id_to_string(tag_group.name, tag_group_info.group_name)))
		{
			return rs;
		}

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::read_tag_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	c_halo3_debug_reader* debug_reader;
	if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_reader, debug_reader)))
	{
		return rs;
	}

	s_cache_file_buffer_info tag_section_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
	{
		return rs;
	}

	::halo3::s_section tag_instances_section;
	if (BCS_FAILED(rs = get_tag_instances_section(tag_instances_section)))
	{
		return rs;
	}

	long tag_instances_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tag_instances_section.address, tag_instances_relative_offset)))
	{
		return rs;
	}

	tag_instance_infos.resize(tag_instances_section.count);
	const ::halo3::s_cache_file_tag_instance* tag_instances_read_pointer = reinterpret_cast<const ::halo3::s_cache_file_tag_instance*>(tag_section_buffer.begin + tag_instances_relative_offset);
	for (unsigned long tag_index = 0; tag_index < tag_instances_section.count; tag_index++)
	{
		s_halo3_tag_instance_info& tag_instance_info = tag_instance_infos[tag_index];
		::halo3::s_cache_file_tag_instance& tag_instance = tag_instance_info.instance = tag_instances_read_pointer[tag_index];
		cache_reader.byteswap_inplace(tag_instance);

		tag_instance_info.absolute_index = tag_index;
		tag_instance_info.identifier = tag_instance.identifier;
		tag_instance_info.tag_instance = nullptr; // deferred : init_tag_instances
		if (tag_instance.identifier != USHRT_MAX)
		{
			tag_instance_info.group_info = &tag_group_infos[tag_instance.group_index];

			if (tag_instance_info.group_info->group.group_tags[0] == blofeld::halo3::SOUND_TAG)
			{
				ASSERT(BCS_SUCCEEDED(rs = get_tag_group_info_by_group_tag(blofeld::halo3::CACHE_FILE_SOUND_TAG, tag_instance_info.group_info)));
				debug_point;
			}

			if (BCS_FAILED(rs = debug_reader->get_tag_filepath(tag_index, tag_instance_info.instance_name)))
			{
				return rs;
			}

			const void* instance_data;
			if (BCS_FAILED(rs = page_offset_to_pointer(tag_instance_info.instance.address, instance_data)))
			{
				return rs;
			}

			tag_instance_info.instance_data = instance_data;
		}
		else
		{
			tag_instance_info.group_info = nullptr;
			tag_instance_info.instance_data = nullptr;
		}

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::read_tag_global_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	c_halo3_debug_reader* debug_reader;
	if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_reader, debug_reader)))
	{
		return rs;
	}

	s_cache_file_buffer_info tag_section_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
	{
		return rs;
	}

	::halo3::s_section global_tag_instances_section;
	if (BCS_FAILED(rs = get_global_tag_instances_section(global_tag_instances_section)))
	{
		return rs;
	}

	long tag_global_instances_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(global_tag_instances_section.address, tag_global_instances_relative_offset)))
	{
		return rs;
	}

	tag_global_instance_infos.resize(global_tag_instances_section.count);
	const ::halo3::s_cache_file_tag_global_instance* global_tag_instances_read_pointer = reinterpret_cast<const ::halo3::s_cache_file_tag_global_instance*>(tag_section_buffer.begin + tag_global_instances_relative_offset);
	for (unsigned long global_tag_index = 0; global_tag_index < global_tag_instances_section.count; global_tag_index++)
	{
		s_halo3_tag_global_instance_info& global_instance_info = tag_global_instance_infos[global_tag_index];
		::halo3::s_cache_file_tag_global_instance& global_tag_instance = global_instance_info.global_instance = global_tag_instances_read_pointer[global_tag_index];
		cache_reader.byteswap_inplace(global_tag_instance);

		unsigned long tag_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(global_tag_instance.datum_index);

		global_instance_info.instance_info = &tag_instance_infos[tag_index];

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::read_tag_interops()
{
	BCS_RESULT rs = BCS_S_OK;

	c_halo3_debug_reader* debug_reader;
	if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_reader, debug_reader)))
	{
		return rs;
	}

	s_cache_file_buffer_info tag_section_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
	{
		return rs;
	}

	::halo3::s_section tag_interop_table_section;
	if (BCS_FAILED(rs = get_tag_interop_table_section(tag_interop_table_section)))
	{
		return rs;
	}

	long tag_interops_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tag_interop_table_section.address, tag_interops_relative_offset)))
	{
		return rs;
	}

	tag_interop_infos.resize(tag_interop_table_section.count);
	const ::halo3::s_cache_file_tag_interop* tag_interops_read_pointer = reinterpret_cast<const ::halo3::s_cache_file_tag_interop*>(tag_section_buffer.begin + tag_interops_relative_offset);
	for (unsigned long interop_index = 0; interop_index < tag_interop_table_section.count; interop_index++)
	{
		::halo3::s_cache_file_tag_interop& tag_interop = tag_interop_infos[interop_index] = tag_interops_read_pointer[interop_index];
		cache_reader.byteswap_inplace(tag_interop);

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::init_tag_groups()
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

			c_halo3_tag_group* tag_group = nullptr;
			if (BCS_SUCCEEDED(get_tag_group_by_group_tag(blofeld_tag_group.group_tag, tag_group)))
			{
				continue; // skip groups already added
			}

			c_halo3_tag_group* parent_tag_group = nullptr;
			if (blofeld_tag_group.parent_tag_group)
			{
				if (BCS_FAILED(get_tag_group_by_group_tag(blofeld_tag_group.parent_group_tag, parent_tag_group)))
				{
					continue;
				}
			}

			tag_group = new() c_halo3_tag_group(cache_cluster, blofeld_tag_group, parent_tag_group);
			tag_groups.push_back(tag_group);

			s_halo3_tag_group_info* tag_group_info = nullptr;
			if (BCS_SUCCEEDED(get_tag_group_info_by_blofeld_tag_group(blofeld_tag_group, tag_group_info)))
			{
				tag_group_info->tag_group = tag_group;
			}
			else
			{
				debug_point;
			}
			added_tag_group = true;
		}
	} while (added_tag_group);
	ASSERT(tag_groups.size() >= tag_group_count);

	return rs;
}

BCS_RESULT c_halo3_tag_reader::init_tag_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	for (s_halo3_tag_instance_info& tag_instance_info : tag_instance_infos)
	{
		if (tag_instance_info.identifier != USHRT_MAX)
		{
			if (
				cache_cluster.engine_platform_build.platform_type != _platform_type_xbox_360 ||
				tag_instance_info.group_info->group.group_tags[0] == blofeld::halo3::SOUND_TAG ||
				tag_instance_info.group_info->group.group_tags[0] == blofeld::halo3::CACHE_FILE_SOUND_TAG ||
				tag_instance_info.group_info->group.group_tags[0] == blofeld::halo3::SOUND_CACHE_FILE_GESTALT_TAG) // #TODO: only sound tags for now from 360, tag definitions need fixing
			{
				ASSERT(tag_instance_info.group_info != nullptr);
				ASSERT(tag_instance_info.group_info->tag_group != nullptr);

				c_halo3_tag_instance* tag_instance = new() c_halo3_tag_instance(
					cache_cluster,
					*tag_instance_info.group_info->tag_group,
					tag_instance_info.absolute_index,
					tag_instance_info.instance_name,
					tag_instance_info.instance_data
				);

				tag_instances.push_back(tag_instance);
				tag_instances_by_index[tag_instance_info.absolute_index] = tag_instance;
			}
		}
	}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::get_tag_group_by_group_tag(tag in_group_tag, c_halo3_tag_group*& out_tag_group) const
{
	for (c_halo3_tag_group* tag_group : tag_groups)
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

BCS_RESULT c_halo3_tag_reader::get_tag_group_by_blofeld_tag_group(const blofeld::s_tag_group& in_blofeld_tag_group, c_halo3_tag_group*& out_tag_group) const
{
	for (c_halo3_tag_group* tag_group : tag_groups)
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

BCS_RESULT c_halo3_tag_reader::get_tag_group_info_by_group_tag(tag group_tag, s_halo3_tag_group_info*& out_tag_group_info)
{
	for (s_halo3_tag_group_info& tag_group_info : tag_group_infos)
	{
		if (tag_group_info.group.group_tags[0] == group_tag)
		{
			out_tag_group_info = &tag_group_info;
			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_halo3_tag_reader::get_tag_group_info_by_blofeld_tag_group(const blofeld::s_tag_group& blofeld_tag_group, s_halo3_tag_group_info*& out_tag_group_info)
{
	for (s_halo3_tag_group_info& tag_group_info : tag_group_infos)
	{
		if (tag_group_info.blofeld_tag_group == &blofeld_tag_group) // #NOTE: is this the safest way to do this?
		{
			out_tag_group_info = &tag_group_info;
			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_halo3_tag_reader::get_global_instance_info(tag group_tag, const s_halo3_tag_global_instance_info*& out_global_instance_info)
{
	for (s_halo3_tag_global_instance_info& global_instance_info : tag_global_instance_infos)
	{
		if (global_instance_info.global_instance.group_tag == group_tag)
		{
			out_global_instance_info = &global_instance_info;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_halo3_tag_reader::get_instance_info_by_tag_index(unsigned long tag_index, const s_halo3_tag_instance_info*& instance_info)
{
	if (tag_index > tag_instance_infos.size())
	{
		return BCS_E_FAIL;
	}

	instance_info = &tag_instance_infos[tag_index];

	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_reader::get_tag_instance_info_by_tag_index(unsigned long tag_index, c_halo3_tag_instance*& tag_instance)
{
	t_tag_instances_by_index::iterator tag_instance_search = tag_instances_by_index.find(tag_index);
	if (tag_instance_search == tag_instances_by_index.end())
	{
		return BCS_E_FAIL;
	}

	tag_instance = tag_instance_search->second;

	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_reader::page_offset_to_pointer(long page_offset, const void*& data)
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

BCS_RESULT c_halo3_tag_reader::get_tag_groups(c_halo3_tag_group**& out_tag_groups, unsigned long& out_tag_group_count)
{
	out_tag_groups = tag_groups.data();
	out_tag_group_count = static_cast<unsigned long>(tag_groups.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_reader::get_tag_groups(c_tag_group**& out_tag_groups, unsigned long& out_tag_group_count)
{
	out_tag_groups = reinterpret_cast<c_tag_group**>(tag_groups.data());
	out_tag_group_count = static_cast<unsigned long>(tag_groups.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_reader::get_tag_instances(c_halo3_tag_instance**& out_tag_instances, unsigned long& out_tag_instance_count)
{
	out_tag_instances = tag_instances.data();
	out_tag_instance_count = static_cast<unsigned long>(tag_instances.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_reader::get_tag_instances(c_tag_instance**& out_tag_instances, unsigned long& out_tag_instance_count)
{
	out_tag_instances = reinterpret_cast<c_tag_instance**>(tag_instances.data());
	out_tag_instance_count = static_cast<unsigned long>(tag_instances.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_reader::get_tag_instance_by_cache_file_tag_index(unsigned long cache_file_tag_index, c_tag_instance*& out_tag_instance)
{
	BCS_RESULT rs = BCS_S_OK;

	c_halo3_tag_instance** tag_instances;
	unsigned long tag_instances_count;
	if (BCS_FAILED(rs = get_tag_instances(tag_instances, tag_instances_count)))
	{
		return rs;
	}

	for (unsigned long tag_instance_index = 0; tag_instance_index < tag_instances_count; tag_instance_index++)
	{
		c_halo3_tag_instance& tag_instance = *tag_instances[tag_instance_index];
		if (tag_instance.cache_file_tag_index == cache_file_tag_index)
		{
			out_tag_instance = &tag_instance;

			return BCS_S_OK;
		}
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_halo3_tag_reader::init_interop_table()
{
	

	BCS_RESULT rs = BCS_S_OK;

	const s_halo3_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	cache_reader.byteswap_inplace(resource_gestalt);

	const s_cache_file_resource_type_identifier_block* resource_type_identifiers;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.resource_type_identifiers_block.address, *reinterpret_cast<const void**>(&resource_type_identifiers))))
	{
		return rs;
	}

	//_resource_type_index_to_halo3_resource_type = new() e_halo3_resource_type[resource_gestalt.resource_type_identifiers_block.count];
	//for (unsigned long index = 0; index < resource_gestalt.resource_type_identifiers_block.count; index++)
	//{
	//	s_cache_file_resource_type_identifier_block_struct resource_type_identifier = resource_type_identifiers[index];
	//	cache_reader.byteswap_inplace(resource_type_identifier);

	//	const char* name = nullptr;
	//	c_halo3_debug_reader* debug_reader;
	//	if (BCS_SUCCEEDED(cache_cluster.get_debug_reader(this->cache_reader, debug_reader)))
	//	{
	//		debug_reader->string_id_to_string(resource_type_identifier.name, name);
	//	}

	//	e_halo3_resource_type resource_type = k_num_halo3_resource_types;
	//	for (unsigned long resource_type_index = 0; resource_type_index < k_num_halo3_resource_types; resource_type_index++)
	//	{
	//		const s_halo3_tag_resource_info& resource_info = halo3_tag_resource_infos[resource_type_index];

	//		if (
	//			static_cast<unsigned long>(resource_type_identifier.identifier_part_0) == resource_info.definition.persistent_identifier.identifier_part_0 &&
	//			static_cast<unsigned long>(resource_type_identifier.identifier_part_1) == resource_info.definition.persistent_identifier.identifier_part_1 &&
	//			static_cast<unsigned long>(resource_type_identifier.identifier_part_2) == resource_info.definition.persistent_identifier.identifier_part_2 &&
	//			static_cast<unsigned long>(resource_type_identifier.identifier_part_3) == resource_info.definition.persistent_identifier.identifier_part_3
	//			)
	//		{
	//			resource_type = static_cast<e_halo3_resource_type>(resource_type_index);
	//			break;
	//		}
	//	}
	//	ASSERT(resource_type != k_num_halo3_resource_types);

	//	_resource_type_index_to_halo3_resource_type[index] = resource_type;

	//	debug_point;
	//}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::init_interops()
{
	

	BCS_RESULT rs = BCS_S_OK;

	const s_halo3_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	cache_reader.byteswap_inplace(resource_gestalt);

	unsigned long interop_count = static_cast<unsigned long>(tag_interop_infos.size());

	interop_containers = new() c_halo3_interop_container * [interop_count + 1];
	interop_containers[interop_count] = nullptr;
	for (unsigned long interop_index = 0; interop_index < interop_count; interop_index++)
	{
		::halo3::s_cache_file_tag_interop& cache_file_tag_interop_entry = tag_interop_infos[interop_index];

		e_halo3_interop_type interop_type;
		if (BCS_FAILED(rs = interop_type_index_to_halo3_interop_type(cache_file_tag_interop_entry.type_index, interop_type)))
		{
			return rs;
		}

		const s_tag_interop* tag_interop_pointer;
		if (BCS_FAILED(rs = page_offset_to_pointer(cache_file_tag_interop_entry.page_address, *(const void**)&tag_interop_pointer)))
		{
			return rs;
		}
		s_tag_interop tag_interop = *tag_interop_pointer;
		cache_reader.byteswap_inplace(tag_interop);

		const void* interop_data;
		if (BCS_FAILED(rs = page_offset_to_pointer(tag_interop.descriptor, interop_data)))
		{
			return rs;
		}


		//{
		//	const s_cache_file_interop_type_identifier_block_struct* interop_type_identifiers;
		//	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.interop_type_identifiers_block.address, *reinterpret_cast<const void**>(&interop_type_identifiers))))
		//	{
		//		throw(rs);
		//	}

		//	s_cache_file_interop_type_identifier_block_struct interop_type_identifier = interop_type_identifiers[tag_interop.type_index];
		//	cache_reader.byteswap_inplace(interop_type_identifier);

		//	const char* name = "<error>";
		//	c_halo3_debug_reader* debug_reader;
		//	if (BCS_SUCCEEDED(cache_cluster.get_debug_reader(this->cache_reader, debug_reader)))
		//	{
		//		debug_reader->string_id_to_string(interop_type_identifier.name, name);
		//	}
		//	console_write_line(name);
		//}

		switch (interop_type)
		{
		case _halo3_vectorart_vertex_buffer_interop:
			interop_containers[interop_index] = new() c_halo3_vectorart_vertex_buffer_interop(*this, tag_interop.descriptor, interop_data);
			break;
		case _halo3_polyart_index_buffer_interop:
			interop_containers[interop_index] = new() c_halo3_polyart_index_buffer_interop(*this, tag_interop.descriptor, interop_data);
			break;
		case _halo3_polyart_vertex_buffer_interop:
			interop_containers[interop_index] = new() c_halo3_polyart_vertex_buffer_interop(*this, tag_interop.descriptor, interop_data);
			break;
		case _halo3_d3d_vertex_buffer_interop:
		case _halo3_d3d_index_buffer_interop:
		case _halo3_d3d_texture_interop:
		case _halo3_d3d_texture_interleaved_interop:
		case _halo3_d3d_vertex_shader_interop:
		case _halo3_d3d_pixel_shader_interop:
		default:
			interop_containers[interop_index] = nullptr;
			FATAL_ERROR("Unsupported interop type");
			break;
		}

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::interop_type_index_to_halo3_interop_type(long type_index, e_halo3_interop_type& interop_type)
{
	

	BCS_VALIDATE_ARGUMENT(type_index >= 0);

	BCS_RESULT rs = BCS_S_OK;

	const s_halo3_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}


	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	
	cache_reader.byteswap_inplace(resource_gestalt);

	if (static_cast<unsigned long>(type_index) >= resource_gestalt.interop_type_identifiers_block.count)
	{
		return BCS_E_FAIL;
	}

	interop_type = _interop_type_index_to_halo3_interop_type[type_index];

	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_reader::init_resource_table()
{
	BCS_RESULT rs = BCS_S_OK;

	const s_halo3_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	cache_reader.byteswap_inplace(resource_gestalt);

	const s_cache_file_interop_type_identifier_block* interop_type_identifiers;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.interop_type_identifiers_block.address, *reinterpret_cast<const void**>(&interop_type_identifiers))))
	{
		throw(rs);
	}

	_interop_type_index_to_halo3_interop_type = new() e_halo3_interop_type[resource_gestalt.interop_type_identifiers_block.count];
	for (unsigned long index = 0; index < resource_gestalt.interop_type_identifiers_block.count; index++)
	{
		s_cache_file_interop_type_identifier_block interop_type_identifier = interop_type_identifiers[index];
		cache_reader.byteswap_inplace(interop_type_identifier);

		const char* name = nullptr;
		c_halo3_debug_reader* debug_reader;
		if (BCS_SUCCEEDED(cache_cluster.get_debug_reader(this->cache_reader, debug_reader)))
		{
			debug_reader->string_id_to_string(interop_type_identifier.name, name);
		}

		e_halo3_interop_type interop_type = k_num_halo3_interop_types;
		for (unsigned long interop_type_index = 0; interop_type_index < k_num_halo3_interop_types; interop_type_index++)
		{
			const s_halo3_tag_interop_info& interop_info = halo3_tag_interop_infos[interop_type_index];

			if (
				static_cast<unsigned long>(interop_type_identifier.identifier_part_0) == interop_info.persistent_identifier.identifier_part_0 &&
				static_cast<unsigned long>(interop_type_identifier.identifier_part_1) == interop_info.persistent_identifier.identifier_part_1 &&
				static_cast<unsigned long>(interop_type_identifier.identifier_part_2) == interop_info.persistent_identifier.identifier_part_2 &&
				static_cast<unsigned long>(interop_type_identifier.identifier_part_3) == interop_info.persistent_identifier.identifier_part_3
				)
			{
				interop_type = static_cast<e_halo3_interop_type>(interop_type_index);
				break;
			}
		}
		ASSERT(interop_type != k_num_halo3_interop_types);

		_interop_type_index_to_halo3_interop_type[index] = interop_type;

		debug_point;
	}

	return rs;
}

class c_halo3_pageable_streaming_resource :
	public h_resource
{
public:
	s_cache_file_resource_data_block resource;
	s_cache_file_resource_default_location_block default_location;
	s_engine_platform_build engine_platform_build;

	const wchar_t* required_cache_file_path;
	s_cache_file_resource_location_struct required_file_resource_location;
	s_cache_file_resource_streaming_sublocation_table_block pageable_sublocation_table;

	const wchar_t* optional_cache_file_path;
	s_cache_file_resource_location_struct optional_file_resource_location;
	s_cache_file_resource_streaming_sublocation_table_block optional_sublocation_table;

	unsigned long reference_count;
	BCS_RESULT resource_state;
	const char* data_buffer;
	size_t data_buffer_size = 0;

	c_halo3_pageable_streaming_resource(
		s_engine_platform_build _engine_platform_build,
		s_cache_file_resource_default_location_block const& _default_location,
		const wchar_t* _required_cache_file_path,
		s_cache_file_resource_location_struct const& _required_file_resource_location,
		s_cache_file_resource_streaming_sublocation_table_block const& _pageable_sublocation_table,
		const wchar_t* _optional_cache_file_path,
		s_cache_file_resource_location_struct const& _optional_file_resource_location,
		s_cache_file_resource_streaming_sublocation_table_block const& _optional_sublocation_table) :
		default_location(_default_location),
		engine_platform_build(_engine_platform_build),
		required_cache_file_path(),
		required_file_resource_location(_required_file_resource_location),
		pageable_sublocation_table(_pageable_sublocation_table),
		optional_cache_file_path(),
		optional_file_resource_location(_optional_file_resource_location),
		optional_sublocation_table(_optional_sublocation_table),
		reference_count(0),
		resource_state(BCS_S_OK),
		data_buffer(nullptr),
		data_buffer_size(0)
	{
		//BCS_CHAR_TO_WIDECHAR_STACK(_required_cache_file_path, required_cache_file_path_wc);
		//BCS_CHAR_TO_WIDECHAR_STACK(_optional_cache_file_path, optional_cache_file_path_wc);
		//required_cache_file_path = wcsdup(required_cache_file_path_wc);
		//optional_cache_file_path = wcsdup(optional_cache_file_path_wc);
		required_cache_file_path = wcsdup(_required_cache_file_path);
		optional_cache_file_path = wcsdup(_optional_cache_file_path);
	}

	~c_halo3_pageable_streaming_resource()
	{
		untracked_free(required_cache_file_path);
		untracked_free(optional_cache_file_path);
	}

	BCS_RESULT load_data()
	{
		BCS_RESULT rs = BCS_S_OK;

		data_buffer_size = 0;
		char* required_data_position = nullptr;
		char* optional_data_position = nullptr;

		if (default_location.required_location >= 0)
		{
			required_data_position += data_buffer_size;
			data_buffer_size += pageable_sublocation_table.total_memory_size;
		}

		if (default_location.optional_location >= 0)
		{
			optional_data_position += data_buffer_size;
			data_buffer_size += optional_sublocation_table.total_memory_size;
		}

		data_buffer = new() char[data_buffer_size];
		required_data_position += reinterpret_cast<intptr_t>(data_buffer);
		optional_data_position += reinterpret_cast<intptr_t>(data_buffer);

		if (default_location.required_location >= 0)
		{
			ASSERT(required_file_resource_location.codec == -1); // #TODO: support compression codecs

			c_halo3_cache_file_reader* resource_cache_file = new() c_halo3_cache_file_reader(required_cache_file_path, engine_platform_build);

			s_cache_file_buffer_info buffer_info;
			resource_cache_file->get_section_buffer(gen3::_cache_file_section_index_resource, buffer_info);

			const char* page_data_pointer = buffer_info.begin + required_file_resource_location.file_offset;
			size_t raw_page_data_size = required_file_resource_location.file_size;

			const char* read_start = page_data_pointer + default_location.required_location_offset;
			const char* read_end = read_start + pageable_sublocation_table.total_memory_size;

			memcpy(required_data_position, read_start, pageable_sublocation_table.total_memory_size);

			delete resource_cache_file;

			debug_point;
		}

		if (default_location.optional_location >= 0)
		{
			ASSERT(required_file_resource_location.codec == -1); // #TODO: support compression codecs

			c_halo3_cache_file_reader* resource_cache_file = new() c_halo3_cache_file_reader(optional_cache_file_path, engine_platform_build);

			s_cache_file_buffer_info buffer_info;
			resource_cache_file->get_section_buffer(gen3::_cache_file_section_index_resource, buffer_info);

			const char* page_data_pointer = buffer_info.begin + optional_file_resource_location.file_offset;
			size_t raw_page_data_size = optional_file_resource_location.file_size;

			const char* read_start = page_data_pointer + default_location.optional_location_offset;
			const char* read_end = read_start + optional_sublocation_table.total_memory_size;

			memcpy(optional_data_position, read_start, optional_sublocation_table.total_memory_size);

			delete resource_cache_file;

			debug_point;
		}

		return rs;
	}

	void unload_data()
	{
		delete[] data_buffer;
		data_buffer_size = 0;
	}

	virtual BCS_RESULT add_reference(const void*& buffer, unsigned long& buffer_size) override
	{
		if (reference_count == 0)
		{
			resource_state = load_data();
		}

		if (BCS_SUCCEEDED(resource_state))
		{
			reference_count++;
			buffer = data_buffer;
			buffer_size = data_buffer_size;
		}

		return resource_state;
	}

	virtual BCS_RESULT remove_reference() override
	{
		if (BCS_SUCCEEDED(resource_state))
		{
			reference_count--;

			if (reference_count == 0)
			{
				unload_data();
			}
		}

		return resource_state;
	}

	virtual const char* get_debug_type_string() override
	{
		return "c_halo3_pageable_streaming_resource";
	}
};

BCS_RESULT c_halo3_tag_reader::init_resources()
{
	BCS_RESULT rs = BCS_S_OK;

	const s_halo3_tag_global_instance_info* resource_gestalt_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_GESTALT_TAG, resource_gestalt_global_instance_info)))
	{
		return rs;
	}
	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(resource_gestalt_global_instance_info->instance_info->instance_data);
	cache_reader.byteswap_inplace(resource_gestalt);

	const s_halo3_tag_global_instance_info* resource_layout_table_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG, resource_layout_table_global_instance_info)))
	{
		return rs;
	}

	const s_cache_file_resource_data_block* resources;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.resources_block.address, *reinterpret_cast<const void**>(&resources))))
	{
		return rs;
	}

	c_typed_tag_block<s_cache_file_resource_location_struct> file_locations_block;
	c_typed_tag_block<s_cache_file_resource_default_location_block> default_locations_block;
	c_typed_tag_block<s_cache_file_resource_streaming_sublocation_table_block> streaming_sublocation_tables_block;
	if (resource_layout_table_global_instance_info->instance_info->instance_data)
	{
		s_cache_file_resource_layout_table_block_struct resource_layout_table = *static_cast<const s_cache_file_resource_layout_table_block_struct*>(resource_layout_table_global_instance_info->instance_info->instance_data);
		cache_reader.byteswap_inplace(resource_layout_table);

		file_locations_block = resource_layout_table.file_locations_block;
		default_locations_block = resource_layout_table.default_locations_block;
		streaming_sublocation_tables_block = resource_layout_table.streaming_sublocation_tables_block;
	}
	else
	{
		file_locations_block = resource_gestalt.file_locations_block;
		default_locations_block = resource_gestalt.default_locations_block;
		streaming_sublocation_tables_block = resource_gestalt.streaming_sublocation_tables_block;
	}

	const s_cache_file_resource_location_struct* file_locations;
	if (BCS_FAILED(rs = page_offset_to_pointer(file_locations_block.address, *reinterpret_cast<const void**>(&file_locations))))
	{
		return rs;
	}

	const s_cache_file_resource_default_location_block* default_locations;
	if (BCS_FAILED(rs = page_offset_to_pointer(default_locations_block.address, *reinterpret_cast<const void**>(&default_locations))))
	{
		return rs;
	}

	const s_cache_file_resource_streaming_sublocation_table_block* streaming_sublocation_tables;
	if (BCS_FAILED(rs = page_offset_to_pointer(streaming_sublocation_tables_block.address, *reinterpret_cast<const void**>(&streaming_sublocation_tables))))
	{
		return rs;
	}

	const char* naive_resource_control_data;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.naive_resource_control_data.address, *reinterpret_cast<const void**>(&naive_resource_control_data))))
	{
		return rs;
	}

	////const char* current_naive_resource_control_data_position = naive_resource_control_data;

	high_level_resources = new() h_resource * [resource_gestalt.resources_block.count] {};
	num_high_level_resources = resource_gestalt.resources_block.count;
	for (unsigned long resource_index = 0; resource_index < resource_gestalt.resources_block.count; resource_index++)
	{
		s_cache_file_resource_data_block resource = resources[resource_index];
		cache_reader.byteswap_inplace(resource);

		unsigned long tag_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(resource.owner_tag.datum_index);

		if (tag_index < UINT16_MAX && resource.owner_tag.group_tag == blofeld::halo3::SOUND_TAG)
		{
			c_halo3_tag_instance* tag_instance;
			if (BCS_FAILED(rs = get_tag_instance_info_by_tag_index(tag_index, tag_instance)))
			{
				return rs;
			}

			s_cache_file_resource_default_location_block default_location = default_locations[resource.location];
			cache_reader.byteswap_inplace(default_location);

			if (default_location.required_location >= 0)
			{
				s_cache_file_resource_location_struct required_file_resource_location = file_locations[default_location.required_location];
				cache_reader.byteswap_inplace(required_file_resource_location);

				c_halo3_cache_file_reader* required_resource_cache_file;
				if (BCS_FAILED(rs = shared_file_index_to_cache_file_reader(required_file_resource_location.shared_file, required_resource_cache_file)))
				{
					return rs;
				}

				ASSERT(default_location.pageable_sublocation_table >= 0);
				s_cache_file_resource_streaming_sublocation_table_block pageable_sublocation_table = streaming_sublocation_tables[default_location.pageable_sublocation_table];
				cache_reader.byteswap_inplace(pageable_sublocation_table);

				if (default_location.optional_location >= 0)
				{
					s_cache_file_resource_location_struct optional_file_resource_location = file_locations[default_location.optional_location];
					cache_reader.byteswap_inplace(optional_file_resource_location);

					c_halo3_cache_file_reader* optional_resource_cache_file;
					if (BCS_FAILED(rs = shared_file_index_to_cache_file_reader(optional_file_resource_location.shared_file, optional_resource_cache_file)))
					{
						return rs;
					}

					ASSERT(default_location.optional_sublocation_table >= 0);
					s_cache_file_resource_streaming_sublocation_table_block optional_sublocation_table = streaming_sublocation_tables[default_location.optional_sublocation_table];
					cache_reader.byteswap_inplace(optional_sublocation_table);

					c_halo3_pageable_streaming_resource* pageable_streaming_resource = new() c_halo3_pageable_streaming_resource(
						cache_cluster.engine_platform_build,
						default_location,
						required_resource_cache_file->filepath.c_str(),
						required_file_resource_location,
						pageable_sublocation_table,
						optional_resource_cache_file->filepath.c_str(),
						optional_file_resource_location,
						optional_sublocation_table);
					high_level_resources[resource_index] = pageable_streaming_resource;

					debug_point;
				}
				else
				{

				}
			}

			debug_point;

		}

	}

	debug_point;

	return rs;
}

BCS_RESULT c_halo3_tag_reader::init_shared_files_table()
{
	
	BCS_RESULT rs = BCS_S_OK;

	const s_halo3_tag_global_instance_info* resource_gestalt_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_GESTALT_TAG, resource_gestalt_global_instance_info)))
	{
		return rs;
	}

	const s_halo3_tag_global_instance_info* resource_layout_table_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG, resource_layout_table_global_instance_info)))
	{
		return rs;
	}

	c_typed_tag_block<s_cache_file_shared_file_block> shared_files_block;
	if (resource_layout_table_global_instance_info->instance_info->instance_data)
	{
		s_cache_file_resource_layout_table_block_struct resource_layout_table = *static_cast<const s_cache_file_resource_layout_table_block_struct*>(resource_layout_table_global_instance_info->instance_info->instance_data);
		cache_reader.byteswap_inplace(resource_layout_table);

		shared_files_block = resource_layout_table.shared_files_block;
	}
	else if (resource_gestalt_global_instance_info->instance_info->instance_data)
	{
		s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(resource_gestalt_global_instance_info->instance_info->instance_data);
		cache_reader.byteswap_inplace(resource_gestalt);

		shared_files_block = resource_gestalt.shared_files_block;
	}

	const s_cache_file_shared_file_block* shared_files;
	if (BCS_FAILED(rs = page_offset_to_pointer(shared_files_block.address, *reinterpret_cast<const void**>(&shared_files))))
	{
		return rs;
	}

	_shared_file_index_to_cache_file_reader = new() c_halo3_cache_file_reader * [shared_files_block.count];
	_shared_file_count = shared_files_block.count;

	for (unsigned long shared_file_index = 0; shared_file_index < shared_files_block.count; shared_file_index++)
	{
		s_cache_file_shared_file_block shared_file = shared_files[shared_file_index];
		cache_reader.byteswap_inplace(shared_file);

		const char* dvd_relative_path = shared_file.dvd_relative_path.get_string();

		c_halo3_cache_file_reader* cache_file_reader = nullptr;
		cache_cluster.get_cache_reader_by_relative_path(dvd_relative_path, cache_file_reader);
		//if (BCS_FAILED(rs = cache_cluster.get_cache_reader_by_relative_path(dvd_relative_path, cache_file_reader)))
		//{
		//	return rs;
		//}

		_shared_file_index_to_cache_file_reader[shared_file_index] = cache_file_reader;

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo3_tag_reader::shared_file_index_to_cache_file_reader(long shared_file_index, c_halo3_cache_file_reader*& cache_file_reader)
{
	BCS_VALIDATE_ARGUMENT(shared_file_index >= -1);

	if (shared_file_index == -1)
	{
		cache_file_reader = &cache_reader;
	}
	else
	{
		if (static_cast<unsigned long>(shared_file_index) > _shared_file_count)
		{
			return BCS_E_OUT_OF_RANGE;
		}

		cache_file_reader = _shared_file_index_to_cache_file_reader[shared_file_index];
	}

	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_reader::get_interop_container_by_type_and_descriptor(e_halo3_interop_type interop_type, unsigned long descriptor, c_halo3_interop_container*& interop_container)
{

	for (c_halo3_interop_container** interop_container_iter = interop_containers; *interop_container_iter; interop_container_iter++)
	{
		if ((*interop_container_iter)->type == interop_type && (*interop_container_iter)->descriptor == descriptor)
		{
			interop_container = *interop_container_iter;
			return BCS_S_OK;
		}
	}
	return BCS_E_FAIL;
}

BCS_RESULT c_halo3_tag_reader::get_compression_codec_by_index(long codec_index, e_halo3_compression_codec& compression_codec)
{
	BCS_RESULT rs = BCS_S_OK;

	
	const s_halo3_tag_global_instance_info* resource_layout_table_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG, resource_layout_table_global_instance_info)))
	{
		return rs;
	}

	c_typed_tag_block<s_cache_file_codec_identifier_block> codec_identifiers_block;
	if (resource_layout_table_global_instance_info->instance_info->instance_data)
	{
		s_cache_file_resource_layout_table_block_struct resource_layout_table = *static_cast<const s_cache_file_resource_layout_table_block_struct*>(resource_layout_table_global_instance_info->instance_info->instance_data);
		cache_reader.byteswap_inplace(resource_layout_table);

		codec_identifiers_block = resource_layout_table.codec_identifiers_block;
	}
	else
	{
		const s_halo3_tag_global_instance_info* resource_gestalt_global_instance_info;
		if (BCS_FAILED(rs = get_global_instance_info(CACHE_FILE_RESOURCE_GESTALT_TAG, resource_gestalt_global_instance_info)))
		{
			return rs;
		}
		s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(resource_gestalt_global_instance_info->instance_info->instance_data);
		cache_reader.byteswap_inplace(resource_gestalt);

		codec_identifiers_block = resource_gestalt.codec_identifiers_block;
	}

	const s_cache_file_codec_identifier_block* codec_identifiers;
	if (BCS_FAILED(rs = page_offset_to_pointer(codec_identifiers_block.address, *reinterpret_cast<const void**>(&codec_identifiers))))
	{
		return rs;
	}

	if (codec_index >= 0)
	{
		s_cache_file_codec_identifier_block codec_identifier = codec_identifiers[codec_index];
		cache_reader.byteswap_inplace(codec_identifier);

		blofeld::s_tag_persistent_identifier identifier =
		{
			static_cast<unsigned long>(codec_identifier.identifier_part_0),
			static_cast<unsigned long>(codec_identifier.identifier_part_1),
			static_cast<unsigned long>(codec_identifier.identifier_part_2),
			static_cast<unsigned long>(codec_identifier.identifier_part_3)
		};

		if (memcmp(&identifier, &k_xdkcompress_codec_identifier, sizeof(identifier)) == 0)
		{
			compression_codec = _halo3_compression_xdkcompress;
		}
		else
		{
			return BCS_E_UNSUPPORTED; // unsupported codec
		}
	}

	return rs;
}
