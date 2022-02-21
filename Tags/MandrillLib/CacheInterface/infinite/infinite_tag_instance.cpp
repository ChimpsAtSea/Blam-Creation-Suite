#include "mandrilllib-private-pch.h"

c_infinite_tag_instance::c_infinite_tag_instance(
	c_cache_cluster& cache_cluster,
	c_infinite_tag_group& tag_group,
	const char* instance_name,
	c_infinite_file_entry_block_map& file_entry_block_map) :
	cache_cluster(cache_cluster),
	tag_group(tag_group),
	instance_name(instance_name),
	file_entry_block_map(file_entry_block_map),
	ucs_reader(),
	mapped_data(),
	header_data(),
	tag_data(),
	resource_data(),
	unknown_data()
{

}

c_infinite_tag_instance::~c_infinite_tag_instance()
{
	// unmap data must be called before destructor
	ASSERT(ucs_reader == nullptr);
}

BCS_RESULT c_infinite_tag_instance::get_global_tag_id(long& out_global_tag_id) const
{
	BCS_RESULT rs = BCS_S_OK;

#if 0
	BCS_RESULT rst1 = ((c_infinite_tag_instance*)this)->map_data();
	const void* data = ucs_reader->root_tag_block_data;
	//if (BCS_FAILED(rs = get_tag_data(data)))
	//{
	//	return rs;
	//}
	out_global_tag_id = *reinterpret_cast<const long*>(static_cast<const char*>(data) + 8);

	BCS_RESULT rst2 = ((c_infinite_tag_instance*)this)->unmap_data();

	unsigned long global_id_a = static_cast<unsigned long>(file_entry_block_map.file_entry.global_tag_id);
	unsigned long global_id_b = static_cast<unsigned long>(file_entry_block_map.file_entry.file_entry_51->global_tag_id);

	//ASSERT(global_id_a == out_global_tag_id);
	ASSERT(global_id_b == out_global_tag_id);
#endif

	out_global_tag_id = file_entry_block_map.file_entry.global_tag_id;

	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::map_data()
{
	BCS_RESULT rs = BCS_S_OK;

	if (mapped_data != nullptr)
	{
		// data has already been mapped
		return BCS_E_FAIL;
	}

	if (BCS_FAILED(rs = file_entry_block_map.map(mapped_data)))
	{
		return rs;
	}

	infinite::c_infinite_generic_module_file_entry& file_entry = file_entry_block_map.file_entry;

	unsigned long header_data_offset = 0;
	unsigned long tag_data_offset = header_data_offset + file_entry.header_data_size;
	unsigned long resource_data_offset = tag_data_offset + file_entry.tag_data_size;
	unsigned long unknown_data_offset = resource_data_offset + file_entry.resource_data_size;

	header_data = static_cast<char*>(mapped_data) + header_data_offset;
	tag_data = static_cast<char*>(mapped_data) + tag_data_offset;
	resource_data = static_cast<char*>(mapped_data) + resource_data_offset;
	unknown_data = static_cast<char*>(mapped_data) + unknown_data_offset;

	// #TODO: test this safety feature
	if (file_entry.header_data_size == 0) header_data = nullptr;
	if (file_entry.tag_data_size == 0) tag_data = nullptr;
	if (file_entry.resource_data_size == 0) resource_data = nullptr;
	if (file_entry.unknown_data_size == 0) unknown_data = nullptr;

	ucs_reader = new() c_infinite_ucs_reader(header_data/*, tag_data, resource_data, unknown_data*/);
	ASSERT(ucs_reader->tag_data == tag_data);

	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::unmap_data()
{
	BCS_RESULT rs = BCS_S_OK;

	if (mapped_data == nullptr)
	{
		// data is not mapped
		return BCS_E_FAIL;
	}

	if (BCS_FAILED(rs = file_entry_block_map.unmap(mapped_data)))
	{
		return rs;
	}

	mapped_data = nullptr;
	header_data = nullptr;
	tag_data = nullptr;
	resource_data = nullptr;
	unknown_data = nullptr;

	delete ucs_reader;
	ucs_reader = nullptr;

	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_ucs_reader(c_infinite_ucs_reader*& out_ucs_reader) const
{
	if (mapped_data == nullptr)
	{
		// data is not mapped
		return BCS_E_DATA_NOT_MAPPED;
	}

	out_ucs_reader = ucs_reader;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_header_data(const void*& out_header_data, unsigned long& header_data_size) const
{
	if (mapped_data == nullptr)
	{
		// data is not mapped
		return BCS_E_DATA_NOT_MAPPED;
	}

	header_data_size = file_entry_block_map.file_entry.header_data_size;
	out_header_data = header_data;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_tag_data(const void*& out_tag_data) const
{
	if (mapped_data == nullptr)
	{
		// data is not mapped
		return BCS_E_DATA_NOT_MAPPED;
	}

	//tag_data_size = file_entry_block_map.file_entry.header_data_size;
	out_tag_data = tag_data;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_resource_data(const void*& out_resource_data, unsigned long& resource_data_size) const
{
	if (mapped_data == nullptr)
	{
		// data is not mapped
		return BCS_E_DATA_NOT_MAPPED;
	}

	resource_data_size = file_entry_block_map.file_entry.resource_data_size;
	out_resource_data = resource_data;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_unknown_data(const void*& out_unknown_data, unsigned long& unknown_data_size) const
{
	if (mapped_data == nullptr)
	{
		// data is not mapped
		return BCS_E_DATA_NOT_MAPPED;
	}

	unknown_data_size = file_entry_block_map.file_entry.unknown_data_size;
	out_unknown_data = unknown_data;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_instance_name(const char*& out_tag_instance_name) const
{
	out_tag_instance_name = instance_name;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_tag_group(c_infinite_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_tag_group(c_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_cache_file_tag_index(unsigned long& out_cache_file_tag_index) const
{
	return BCS_E_UNSUPPORTED;
}
